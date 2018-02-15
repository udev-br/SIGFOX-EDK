/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * Example using occurrence of Events
 * in the uDEV Sigfox Embedded Development Kit, using
 * the Callback Method.
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "event.h"
#include "gpio.h"
#include "console_usb.h"
#include "debug.h"
#include "delay_loop.h"

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

/*************************************************************************************************/
/*    INTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnUSER_Setup( void )
{
   fnCONSOLE_USB_Init( );
   fnDELAY_LOOP_ms( 500 );
   
   fnDEBUG_Const_String( "\r\nEnd of User Setup\r\n" );
}

void fnUSER_Loop ( void )
{
   
}      


// The following function is called automatically every time
// an event happens, no matter which.

void fnEVENT_Callback ( en_event_t en_event ) {

   // This Switch treats every relevant event,
   // and you can add any that you wish to use.
   // Check the event.h header file for a enum
   // with all available events.

   switch ( en_event ) {

      case EVENT_SYSTEM_INIT: {
         fnDEBUG_Const_String( "EVENT_SYSTEM_INIT\r\n" );
         break;
      }
      case EVENT_SYSTEM_RTC: {
         // fnDEBUG_Const_String( "EVENT_SYSTEM_RTC\r\n");
         break;
      }
      case EVENT_INPUT_BUTTON_RELEASE: {
         fnDEBUG_Const_String("EVENT_INPUT_BUTTON_RELEASE\r\n");
         break;
      }
      case EVENT_INPUT_BUTTON_PRESS: {
         fnDEBUG_Const_String("EVENT_INPUT_BUTTON_PRESS\r\n");
         break;
      }
      case EVENT_INPUT_BUTTON_RELEASE_HOLD: {
         fnDEBUG_Const_String("EVENT_INPUT_BUTTON_RELEASE_HOLD\r\n");
         break;
      }
      case EVENT_INPUT_BUTTON_PRESS_HOLD: {
         fnDEBUG_Const_String("EVENT_INPUT_BUTTON_PRESS_HOLD\r\n");
         break;
      }
   }
}
/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/