/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * Example using occurrence of Events
 * in the uDEV Sigfox Embedded Development Kit, using
 * the Attaching Method.
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

   // The following functions attach the event in question with
   // the already-defined corresponding function
   fnEVENT_Attach_Callback( EVENT_SYSTEM_INIT, fnInit_Callback );
   fnEVENT_Attach_Callback( EVENT_INPUT_BUTTON_PRESS, fnButton_Press_Callback );
   fnEVENT_Attach_Callback( EVENT_INPUT_BUTTON_RELEASE, fnButton_Release_Callback );
   fnEVENT_Attach_Callback( EVENT_INPUT_BUTTON_PRESS_HOLD, fnButton_Press_Hold_Callback );
   fnEVENT_Attach_Callback( EVENT_INPUT_BUTTON_RELEASE_HOLD, fnButton_Release_Hold_Callback );
   fnEVENT_Attach_Callback( EVENT_SYSTEM_RTC, fnRTC_Callback );

   fnDEBUG_Const_String( "\r\nEnd of User Setup\r\n" );
}

void fnUSER_Loop ( void )
{
   
}      


// Now we must implement what happens in the functions called
// when the events occur.

void fnInit_Callback ( void )
{
   fnDEBUG_Const_String( "Event: System Initialization\r\n" );
}

void fnButton_Press_Callback ( void )
{
   fnDEBUG_Const_String( "Event: Button Press\r\n" );
}

void fnButton_Release_Callback ( void )
{
   fnDEBUG_Const_String( "Event: Button Release\r\n" );
   fnGPIO_LED_Toggle();
}

void fnButton_Press_Hold_Callback ( void )
{
   fnDEBUG_Const_String( "Event: Button Press Hold\r\n" );
}

void fnButton_Release_Hold_Callback ( void )
{
   fnDEBUG_Const_String( "Event: Button Release Hold\r\n" );
}

void fnRTC_Callback ( void )
{
   fnDEBUG_Const_String( "Event: RTC tick\r\n" );
}
/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/