#ifndef Arduino_h
#define Arduino_h

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "pgmspace.h"

#include "itoa.h"

typedef bool boolean;
typedef uint8_t byte;
typedef uint16_t word;


#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#include "wiring_constants.h"


    void yield( void ) ;

    /* sketch */
    void setup( void ) ;
    void loop( void ) ;

    void suspendLoop(void);
    void resumeLoop(void);


#ifdef __cplusplus
} // extern "C"
#endif

// The following headers are for C++ only compilation
#ifdef __cplusplus
//Add here all the arduino classes
#endif

#ifdef USE_TINYUSB
// Needed for declaring Serial
#include "Adafruit_USBD_CDC.h"
#endif

#include "delay.h"
#include "common_inc.h"
//#include "utility/debug.h"
//#include "utility/utilities.h"
//#include "utility/AdaCallback.h"


// Include board variant
//#include "variant.h"

#include "wiring.h"
#include "wiring_digital.h"
//#include "wiring_analog.h"
//#include "wiring_shift.h"
//#include "WInterrupts.h"

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif // abs

#ifdef __cplusplus
template<class T, class L>
auto min(const T& a, const L& b) -> decltype((b < a) ? b : a)
{
    return (b < a) ? b : a;
}

template<class T, class L>
auto max(const T& a, const L& b) -> decltype((b < a) ? b : a)
{
    return (a < b) ? b : a;
}
#else
#ifndef min
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
#endif
#ifndef max
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
#endif
#endif

#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() __enable_irq()
#define noInterrupts() __disable_irq()
#define watchdog_update()

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01ul)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

#define bit(b) (1UL << (b))

#ifdef NRF_P1
#define digitalPinToPort(P)        ( (g_ADigitalPinMap[P] < 32) ? NRF_P0 : NRF_P1 )
#else
#define digitalPinToPort(P)        ( NRF_P0 )
#endif

#define digitalPinToBitMask(P)     ( 1UL << ( g_ADigitalPinMap[P] < 32 ? g_ADigitalPinMap[P] : (g_ADigitalPinMap[P]-32) ) )

#define digitalPinToPinName(P)     g_ADigitalPinMap[P]

//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT) )
#define portInputRegister(port)    ( (volatile uint32_t*) &(port->IN) )
#define portModeRegister(port)     ( &(port->DIR) )
#define digitalPinHasPWM(P)        ( g_ADigitalPinMap[P] > 1 )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for nRF52
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// Interrupts
#define digitalPinToInterrupt(P)   ( P )

#endif // Arduino_h
