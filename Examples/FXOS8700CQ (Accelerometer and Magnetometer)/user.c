/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * Accelerometer and Magnetometer sensor example,
 * using the uDEV Sigfox Embedded Development Kit.
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "fxos8700cq.h"
#include "debug.h"
#include "console_usb.h"

/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/

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
   // Code within this context will execute ONCE.
   fnFXOS8700CQ_Init( FXOS8700CQ_OPERATION_MODE_HYBRID );
   fnCONSOLE_USB_Init( );
}

void fnUSER_Loop( void )
{
   // Code within this context will be executed continuously.

   if ( !measured )
   {
      measured = true;
      fnFXOS8700CQ_Enable( );
   }
}

void fnFXOS8700CQ_CALLBACK_Measure_Done ( void )
{
   // This CALLBACK is called everytime the Enable function ends
   
   fnDEBUG_Int16_Value( "AccX:    ", fnFXOS8700CQ_Get_Data_Pointer()->st_accel_raw_data.i16_raw_x , "; " );
   fnDEBUG_Int16_Value( "AccY:    ", fnFXOS8700CQ_Get_Data_Pointer()->st_accel_raw_data.i16_raw_y , "; " );
   fnDEBUG_Int16_Value( "AccZ:    ", fnFXOS8700CQ_Get_Data_Pointer()->st_accel_raw_data.i16_raw_z , "; \r\n" );
 
   fnDEBUG_Int16_Value( "AccX_mg: ", fnFXOS8700CQ_Get_Accel_Data()->i16_converted_x , "; " );
   fnDEBUG_Int16_Value( "AccY_mg: ", fnFXOS8700CQ_Get_Accel_Data()->i16_converted_y , "; " );
   fnDEBUG_Int16_Value( "AccZ_mg: ", fnFXOS8700CQ_Get_Accel_Data()->i16_converted_z , "; \r\n" );
 
   fnDEBUG_Int16_Value( "MagX:    ", fnFXOS8700CQ_Get_Data_Pointer()->st_mag_raw_data.i16_raw_x , "; " );
   fnDEBUG_Int16_Value( "MagY:    ", fnFXOS8700CQ_Get_Data_Pointer()->st_mag_raw_data.i16_raw_y , "; " );
   fnDEBUG_Int16_Value( "MagZ:    ", fnFXOS8700CQ_Get_Data_Pointer()->st_mag_raw_data.i16_raw_z , "; \r\n" );
      
   fnDEBUG_Int16_Value( "MagX_uT: ", fnFXOS8700CQ_Get_Mag_Data()->i16_converted_x , "; " );
   fnDEBUG_Int16_Value( "MagY_uT: ", fnFXOS8700CQ_Get_Mag_Data()->i16_converted_y , "; " );
   fnDEBUG_Int16_Value( "MagZ_uT: ", fnFXOS8700CQ_Get_Mag_Data()->i16_converted_z , "; \r\n \r\n" );
   
   fnFXOS8700CQ_Disable( );
   measured = false;
}
/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/