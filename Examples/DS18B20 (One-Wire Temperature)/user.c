/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * Example for the One-Wire Temperature sensor (DS18B20)
 * component, present in the uDEV Sigfox Embedded Development Kit.
 * 
 * This component uses the Analog Input connectors to operate.
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "ds18b20.h"
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

void fnUSER_Setup ( void )
{
   // Code within this context will execute ONCE.
   fnCONSOLE_USB_Init( );
   
   // This function initializes ONE DS18B20 probe.
   fnDS18B20_Init( 1 );
}   

void fnUSER_Loop ( void )
{
   // Code within this context will be executed continuously.
   
   // The method below utilises the callback mode for the sensor
   if( !measured )
   {
      fnDS18B20_Measure_Start_Callback_Mode( );
      measured = true;
   }      
   
   // The commented method below utilises the so-called "blocking mode"
   // for obtaining data from the sensor. Read the header for more info.
   
//    fnDS18B20_Measure_Start_Blocking_Mode( );
//    if ( fnDS18B20_Get_Data_Pointer()->un_last_error.u8_value == 0 )
//    {
//       fnDEBUG_Const_String( "Status OK block \r\n" );
//       fnDEBUG_Uint16_Value( "Temp: ", fnDS18B20_Get_Temperature() * 1000, " C; \r\n");
//    }
//    else if ( fnDS18B20_Get_Data_Pointer()->un_last_error.u8_value != 0 )
//    {
//       fnDEBUG_Const_String( "===ERRO=== \r\n" );
//   
}

void fnDS18B20_Measure_Done_Callback ( void )
{
   if ( fnDS18B20_Get_Data_Pointer()->un_last_error.u8_value == 0 )
   {
      fnDEBUG_Const_String( "Status OK \r\n" );
      fnDEBUG_Uint16_Value( "Temp: ", fnDS18B20_Get_Temperature( 0 ) * 1000, " C; \r\n");
      // Since the Debug can't print a float, we print the int *1000 to have a result
      // in a format we don't lose information. (e.g. displayed as "24565 C", it means "24.565 C")
      // The channel specified is 0 because we have only one probe, and their addressing starts at 0.
   }
   else if ( fnDS18B20_Get_Data_Pointer()->un_last_error.u8_value != 0 )
   {
      fnDEBUG_Const_String( "===ERROR=== \r\n" );
   }
   measured = false;
}
/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/