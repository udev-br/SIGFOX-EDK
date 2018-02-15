/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * Example using the Temperature and Humidity sensor (SI7021)
 * present in the uDEV Sigfox Embedded Development Kit.
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "si7021.h"
#include "debug.h"
#include "console_usb.h"

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

bool measured = false;

/*************************************************************************************************/
/*    INTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnUSER_Setup( void )
{
   fnSI7021_Init();
   fnCONSOLE_USB_Init();
   
}

void fnUSER_Loop( void )
{
   if ( !measured )
   {
      fnSI7021_Measure_Start_Callback_Mode();
      measured = true;
   }

//    fnSI7021_Measure_Start_Blocking_Mode( );
//    fnDEBUG_Int16_Value( "Tempblock: ", fnSI7021_Get_Temperature(), " C; \r\n" );
//    fnDEBUG_Uint16_Value( "RHblock: ", fnSI7021_Get_RH(), " %; \r\n" );
}

void fnSI7021_Measure_Done_Callback( void )
{
   fnDEBUG_Int32_Value( "Temp: ", fnSI7021_Get_Temperature(), " C; \r\n" );
   fnDEBUG_Uint32_Value( "RH: ", fnSI7021_Get_RH(), " %; \r\n" );
   measured = false;
}
/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/