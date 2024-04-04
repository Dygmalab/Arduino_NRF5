/*
Copyright (c) 2015 Arduino LLC.  All right reserved.
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

#define ARDUINO_MAIN
#include "Adafruit_TinyUSB_API.h"
#include "Arduino.h"
#include "KeyboardioHID.h"
#include "Ble_composite_dev.h"

// \brief Main entry point of Arduino application
int main(void)
{
    init();

    TinyUSBDevice.attach();
#ifdef USE_TINYUSB
    TinyUSB_Device_Init(0);
#endif
    if(!Serial) Serial.begin(115200);
    RawHID.begin();

    setup();

    while (1)
    {
        loop();
        yield(); // yield to run other task

        // Serial events
        //if (serialEvent && serialEventRun) serialEventRun();
    }

    NVIC_SystemReset();  // Soft reset MCU.

    return 0;
}

extern "C"
{

    // nanolib printf() retarget
    // Logger 0: Serial (CDC), 1 Serial1 (UART), 2 Segger RTT
    int _write(int fd, const void *buf, size_t count)
    {
        //        (void)fd;
        //
        //        size_t ret = 0;
        //
        // #if CFG_LOGGER == 2 || CFG_SYSVIEW
        //        SEGGER_RTT_Write(0, buf, count);
        //        ret = count;
        //
        // #elif CFG_LOGGER == 1
        //        if (Serial1)
        //        {
        //            ret = Serial1.write((const uint8_t *)buf, count);
        //        }
        //
        // #else
        //        if (Serial)
        //        {
        //            ret = Serial.write((const uint8_t *)buf, count);
        //        }
        // #endif
        //
        //        return (int)ret;
        return count;
    }
}
