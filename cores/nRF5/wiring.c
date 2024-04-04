/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"
#include "Time_counter.h"
#include "app_timer.h"
#include "nrf.h"
#include "nrf_drv_clock.h"
#include "nrf_drv_power.h"
#include "nrf_nvic.h"
#include "nrf_sdm.h"


void init(void)
{

/*
Official documentation from Nordic:

Clock
-----
https://infocenter.nordicsemi.com/topic/sdk_nrf5_v17.1.0/hardware_driver_clock.html
https://infocenter.nordicsemi.com/topic/sdk_nrf5_v17.1.0/group__nrf__drv__clock.html

Power
-----
https://infocenter.nordicsemi.com/topic/sdk_nrf5_v17.1.0/group__nrf__drv__power.html
https://infocenter.nordicsemi.com/topic/sdk_nrf5_v17.1.0/group__nrf__power.html
*/

    ret_code_t ret;
    timer_counter_init(250);
    if (!nrf_drv_clock_init_check()) // Check if driver is already initialized.
    {
        /*
            Initializing the nrf_drv_clock module.
            After initialization, the module is in power off state.
        */
        ret = nrf_drv_clock_init();
        APP_ERROR_CHECK(ret);
    }

    if (!nrf_drv_power_init_check()) // Check if driver is already initialized.
    {
        /*
            Power driver has to be enabled before SoftDevice.
        */
        ret = nrf_drv_power_init(NULL);
        APP_ERROR_CHECK(ret);
    }

    nrf_drv_clock_hfclk_request(NULL);
    nrf_drv_clock_lfclk_request(NULL);

    // Wait till the clocks start.
    while (!(nrf_drv_clock_hfclk_is_running() && nrf_drv_clock_lfclk_is_running()))
        ;

    ret = app_timer_init();
    APP_ERROR_CHECK(ret);
}


void waitForEvent(void)
{
#if 0
  // Set bit 7 and bits 4..0 in the mask to one (0x ...00 1001 1111)
  enum { FPU_EXCEPTION_MASK = 0x0000009F };

  /* Clear exceptions and PendingIRQ from the FPU unit */
  __set_FPSCR(__get_FPSCR()  & ~(FPU_EXCEPTION_MASK));
  (void) __get_FPSCR();
  NVIC_ClearPendingIRQ(FPU_IRQn);
#endif

    uint8_t sd_en = 0;
    (void)sd_softdevice_is_enabled(&sd_en);

#ifdef NRF_CRYPTOCELL
    // manually clear CryptoCell else it could prevent low power mode
    NVIC_ClearPendingIRQ(CRYPTOCELL_IRQn);
#endif

    if (sd_en)
    {
        (void)sd_app_evt_wait();
    }
    else
    {
        // SoftDevice is not enabled.
        __WFE();
        __SEV(); // Clear Event Register.
        __WFE();
    }
}


float readCPUTemperature(void)
{
    uint8_t en;
    int32_t temp;
    (void)sd_softdevice_is_enabled(&en);
    if (en)
    {
        sd_temp_get(&temp);
    }
    else
    {
        NRF_TEMP->EVENTS_DATARDY = 0x00; // Only needed in case another function is also looking at this event flag
        NRF_TEMP->TASKS_START = 0x01;

        while (!NRF_TEMP->EVENTS_DATARDY)
            ;
        temp = NRF_TEMP->TEMP; // Per anomaly 29 (unclear whether still applicable), TASKS_STOP will clear the TEMP register.

        NRF_TEMP->TASKS_STOP = 0x01; // Per anomaly 30 (unclear whether still applicable), the temp peripheral needs to be shut down
        NRF_TEMP->EVENTS_DATARDY = 0x00;
    }
    return temp / 4.0F;
}
