/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * This is an example of how to use the EEPROM functions,
 * using the uDEV Sigfox Embedded Development Kit.
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "flash_eeprom.h"
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

uint8_t count;
bool pressed = false;

/*************************************************************************************************/
/*    INTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnUSER_Setup( void )
{
   fnCONSOLE_USB_Init( );

   // This line allows the board to be turned off and resume counting
   // from where it last counted
   count = fnEEPROM_Get_Value( 0 );
}

void fnUSER_Loop( void )
{
   if ( fnGPIO_BUTTON_Get_Level()==false )
   {
      pressed = true;
   }
   if ( fnGPIO_BUTTON_Get_Level()==true && pressed==true )
   {
      pressed = false;
      
      // This section simply prints via Debug the current value at address 0
      // and increments said value.
      fnDEBUG_Int8_Value("EEPROM: ", fnEEPROM_Get_Value( 0 ), "; \r\n");
      fnEEPROM_Set_Value( 0, ++count );
      fnEEPROM_Commit( );
      
   }
}

/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/