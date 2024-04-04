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

#include "nrf.h"

#include "Arduino.h"
#include "Time_counter.h"
#include "delay.h"

#ifdef __cplusplus
                                                                extern "C" {
#endif

      static volatile uint32_t overflows = 0;

      uint32_t millis( void )
      {
          return timer_counter_get_millis();
      }

      uint32_t micros( void )
      {
          return timer_counter_get_micros();
      }

      void delay( uint32_t ms )
      {
          if ( ms == 0 )
          {
              return ;
          }

          uint32_t start = millis() ;

          do
          {
              yield() ;
          } while ( millis() - start < ms ) ;
      }


#ifdef __cplusplus
  }
#endif
