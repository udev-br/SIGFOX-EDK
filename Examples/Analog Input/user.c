/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * Example for the Analog Input component present
 * in the uDEV Sigfox Embedded Development Kit.
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "input_analogic.h"
#include "debug.h"
#include "gpio.h"
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

bool pressed = false;
uint16_t raw=0;
uint16_t volts=0;

/*************************************************************************************************/
/*    INTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnUSER_Setup( void )
{
   fnCONSOLE_USB_Init( );
   fnINPUT_ANALOGIC_Init( );
}

void fnUSER_Loop( void )
{
   // In this example we use the user button to measure and print
   // the voltage measured both on the battery pins and the
   // analog input.
   // Every time the button is pressed, data is sent via the debugging
   // usb port.
   
   if(!fnGPIO_BUTTON_Get_Level())
   {
      fnGPIO_LED_Set_Level( true );
      pressed = true;
   }
   if(fnGPIO_BUTTON_Get_Level() && pressed)
   {
      fnGPIO_LED_Set_Level( false );
      pressed = false;
      
      fnINPUT_ANALOGIC_Read_Value( INPUT_ANALOGIC_DEFINITION_VBAT , &raw, &volts );
      fnDEBUG_Uint16_Value( "Battery voltage: ", volts, "; \r\n" );
      fnDEBUG_Uint16_Value( "Battery raw data: ", raw, "; \r\n" );
      
      fnINPUT_ANALOGIC_Read_Value( INPUT_ANALOGIC_DEFINITION_4_20_MA , &raw, &volts );
      fnDEBUG_Uint16_Value( "Analog input voltage: ", volts, "; \r\n" );
      fnDEBUG_Uint16_Value( "Analog input raw data: ", raw, "; \r\n \r\n" );
    }
}
/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/