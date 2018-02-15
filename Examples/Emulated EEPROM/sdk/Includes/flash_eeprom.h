#ifndef _FLASH_EEPROM_H
#define _FLASH_EEPROM_H


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include <stdint.h>
#include <stdbool.h>

/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/


/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// Get_Value returns whatever is stored in the u8_address, within the EEPROM
uint8_t fnEEPROM_Get_Value ( uint8_t u8_address );

// Set_Value readies a u8_value to be stored within the EEPROM, at the
// u8_address position. This function DOES NOT write to the memory, just readies
// the data to be written.
void fnEEPROM_Set_Value ( uint8_t u8_address, uint8_t u8_value );

// This function returns an entire array of values, if such exists, starting
// at the address specified.
const uint8_t * fnEEPROM_Get_Value_Array ( uint8_t u8_address );

// Use this function to set an array of values starting at the address specified,
// and with the size specified.
void fnEEPROM_Set_Value_Array ( uint8_t u8_address, uint8_t * pu8_value, uint8_t u8_size );

// Commit effectively writes the data to the memory specified in Set_Value or Set_Value_Array.
void fnEEPROM_Commit ( void );


#endif  /* _FLASH_EEPROM_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
