/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * This example uses the Thermocouple input (THERM) in the
 * uDEV Sigfox Embedded Development Kit to measure
 * temperature, using a thermocouple.
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "mcp9600.h"

#include "console_usb.h"
#include "debug.h"

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
   
   // These variables store the way we want to configure
   // our thermocouple.
   st_mcp9600_config_t st_mcp9600_config;
   st_mcp9600_config.en_adc_res_bits        = MCP9600_ADC_MEASUREMENT_RESOLUTION_16_BITS;
   st_mcp9600_config.en_cold_junction_res   = MCP9600_COLD_JUNCTION_RESOLUTION_0_25;
   st_mcp9600_config.en_filter_coefficients = MCP9600_FILTER_3;
   st_mcp9600_config.en_thermocouple_type   = MCP9600_TYPE_K;
   
   fnMCP9600_Init( );
   fnMCP9600_Config( &st_mcp9600_config );
}   

void fnUSER_Loop ( void )
{
   // Code within this context will be executed continuously.
   
   // This loop below is operating in Callback Mode
   if( !measured )
   {
      measured = true;
      fnMCP9600_Measure_Start_Callback_Mode( );
   }      
   
   // The context below (initially commented) would operate in
   // Blocking Mode.

//    fnMCP9600_Measure_Start_Blocking_Mode( );
//    if ( fnMCP9600_Get_Data_Pointer()->un_last_error.u8_value == 0 )
//    {
//       fnDEBUG_Const_String( "Status OK block \r\n" );
//       fnDEBUG_Uint16_Value( "Temp: ", fnMCP9600_Get_Temperature() * 1000, " C; \r\n");
//    }
//    else if ( fnMCP9600_Get_Data_Pointer()->un_last_error.u8_value != 0 )
//    {
//       fnDEBUG_Const_String( "===ERRO=== \r\n" );
//    }
}

void fnMCP9600_Measure_Done_Callback ( void )
{
   // When the measurement started in Measure_Start_Callback_Mode is finished,
   // this function is called automatically.
   if ( fnMCP9600_Get_Data_Pointer()->un_last_error.u8_value == 0 )
   {
      fnDEBUG_Const_String( "Status OK \r\n" );
      fnDEBUG_Int32_Value( "Temp: ", (fnMCP9600_Get_Temperature()), " C; \r\n");
   }
   else if ( fnMCP9600_Get_Data_Pointer()->un_last_error.u8_value != 0 )
   {
      fnDEBUG_Const_String( "===ERRO=== \r\n" );
   }
   measured = false;
}
/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/