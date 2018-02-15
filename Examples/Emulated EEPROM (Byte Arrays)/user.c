/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/

/*
 * This is an example of how to use the EEPROM array functions,
 * using the uDEV Sigfox Embedded Development Kit.
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "console_usb.h"
#include "debug.h"
#include "flash_eeprom.h"
#include "gpio.h"

/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/

/* Returns a 4 Byte array into a 32-Bit value */
#define convert_byte_array_to_32_bit(data)               (*(uint32_t *)((void *)data))

/* Converts a 32-Bit value into a 4 Byte array, to the "data" buffer */
#define convert_32_bit_to_byte_array(value, data)        ((*(uint32_t *)((void *)data)) = (uint32_t)(value))

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

uint8_t au8_defined_array[] = {0x0A, 0x05, 0x03, 0x00};

uint32_t u32_value = 197898;

bool pressed = false;

/*************************************************************************************************/
/*    INTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnUSER_Setup( void )
{
   // This function will execute once, use it to initialize components and set initial values.
   fnCONSOLE_USB_Init();
}

void fnUSER_Loop( void )
{
   // Anything within the USER_Loop context will execute continuously.
   // Check the header files for functions you can use in each program.
    
   if ( fnGPIO_BUTTON_Get_Level()==true )
   {
      pressed = true;
   }
   if ( fnGPIO_BUTTON_Get_Level()==false && pressed==true )
   {
      // You can switch the two functions as desired, to see each
      // one operating.
      fnWrite_Array_to_EEPROM( );
      //fnWrite_Integer_to_EEPROM( );
      pressed = false;
   }
}

void fnWrite_Array_to_EEPROM( void )
{
   // The functions below can be used directly when you have a defined
   // byte array. See fnWrite_Integer_to_EEPROM for an example of how
   // to write a large integer using the EEPROM array functions.
   fnEEPROM_Set_Value_Array( 0, au8_defined_array, sizeof(au8_defined_array) );
   fnEEPROM_Commit( );
   
   fnDEBUG_Uint32_Value( "Array EEPROM: ", convert_byte_array_to_32_bit( fnEEPROM_Get_Value_Array( 0 ) ), "\r\n" );
}

void fnWrite_Integer_to_EEPROM( void )
{
   uint8_t au8_memory_buffer[8];
 
   // These three functions will write whatever value is in the u32_value
   // variable to the EEPROM memory, starting at the address 0x0,
   // after converting it to a 4-byte array, using a temporary buffer.
   convert_32_bit_to_byte_array( u32_value, au8_memory_buffer );
   fnEEPROM_Set_Value_Array( 0, au8_memory_buffer, sizeof(au8_memory_buffer) );
   fnEEPROM_Commit( );
   
   fnDEBUG_Uint32_Value( "Integer EEPROM: ", convert_byte_array_to_32_bit( fnEEPROM_Get_Value_Array( 0 ) ), "\r\n" );
}

/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/