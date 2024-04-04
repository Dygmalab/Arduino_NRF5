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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif


extern void init(void);

extern void reset_mcu();

void waitForEvent(void);

// Test if in interrupt mode
static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}

/*
 * \brief Reads the on-chip temperature sensor, returning the temperature in degrees C
 * with a resolution of 0.25 degrees.
*/
float readCPUTemperature( void );

#ifdef __cplusplus
}
#endif
