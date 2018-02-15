/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * Example using the Real-Time Clock, with the uDEV Sigfox Embedded Development Kit.
 * In this example, the event function is called every period of time, defined in
 * the TIMER_TO_FINISH constant below.
 *
 * Use the event method for a function that occurs every time the RTC is called,
 * meaning every one (1) second. After ten (10) seconds, the program will print
 * a message on the Serial terminal, using the USB debugging function.
 *
 * Check our Events Example for more info on how to attach functions to events. 
 *
 * Author : Lucas Badur
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "rtc.h"
#include "event.h"
#include "debug.h"
#include "console_usb.h"

/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/

// Define these constants to set the timer
// to whatever you want.
#define TIMER_HOURS                 (0)
#define TIMER_MINUTES               (0)
#define TIMER_SECONDS               (10)

#define TIMER_TO_FINISH             ((60*60*TIMER_HOURS)+(60*TIMER_MINUTES)+(TIMER_SECONDS))

/*************************************************************************************************/
/*    LOW-POWER OPERATION                                                                        */
/*************************************************************************************************/

// This variable dictates whether the board operates in low-power mode,
// or in normal-power mode.
// The default is TRUE, which corresponds to low-power mode.
// In low-power, the board cannot communicate via USB, so USB serial communication is
// not an option, and using a serial terminal will not work.
// To debug via USB, you must set this variable to FALSE.
bool __b_system_low_power_enabled__ = false;

/*************************************************************************************************/
/*    VARIABLES                                                                                  */
/*************************************************************************************************/

uint32_t u32_timer;

/*************************************************************************************************/
/*    INTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnUSER_Setup()
{
   // Code within this context will execute ONCE.
   // The Real-Time Clock is initialized by default, no need to initialize it.
   fnCONSOLE_USB_Init( );

   // With this function, we specify that every time the event EVENT_SYSTEM_RTC occurs,
   // which is the event that occurs when the system ticks one (1) second in the
   // real-time clock, the function fnEvent_RTC gets called.
   // Thus, we can implement whatever we need within this function, that is to be defined
   // and created by the user.
   fnEVENT_Attach_Callback( EVENT_SYSTEM_RTC, fnEvent_RTC );
   u32_timer = TIMER_TO_FINISH;
}

void fnUSER_Loop()
{
   // Code within this context will be executed continuously.
}


void fnEvent_RTC( void )
{
   u32_timer--;
   if ( u32_timer == 0 )
   {
      //We reset the timer, to begin a new countdown
      u32_timer = TIMER_TO_FINISH;
      fnDEBUG_Const_String( "The timer has finished.\r\n" );
   }      
}

/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/