/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * This is a simple application example for the
 * LED present at the uDEV Sigfox EDK board.
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "gpio.h"

/*************************************************************************************************/
/*    LOW-POWER OPERATION                                                                        */
/*************************************************************************************************/

// This variable dictates whether the board operates in low-power mode,
// or in normal-power mode.
// The default is TRUE, which corresponds to low-power mode.
// In low-power, the board cannot communicate via USB, so USB serial communication is
// not an option, and using a serial terminal will not work.
// To debug via USB, you must set this variable to FALSE.
bool __b_system_low_power_enabled__ = true;

/*************************************************************************************************/
/*    VARIABLES                                                                                  */
/*************************************************************************************************/

bool switched=false;
bool pressed;

/*************************************************************************************************/
/*    INTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnUSER_Setup( void )
{
   // This function will execute once, use it to initialize components and set initial values.
   // In the case of the LED Example, this is not necessary, for the button and the LED are
   // always already initialized.
}

void fnUSER_Loop( void )
{
   // Anything within the USER_Loop context will execute continuously.
   // Check the header files for functions you can use in each program.
   
   if ( fnGPIO_BUTTON_Get_Level()==false )
   {
      pressed = true;
   }
   if ( fnGPIO_BUTTON_Get_Level()==true && pressed==true )
   {
      switched = !switched;
      fnGPIO_LED_Set_Level( switched );
      pressed = false;
   }

    // Alternatively, there is a Toggle function available for use
//    if ( fnGPIO_BUTTON_Get_Level()==false )
//    {
//       pressed = true;
//    }
//    if ( fnGPIO_BUTTON_Get_Level()==true && pressed==true )
//    {
//       fnGPIO_LED_Toggle( );
//       pressed = false;
//    }
}

/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/