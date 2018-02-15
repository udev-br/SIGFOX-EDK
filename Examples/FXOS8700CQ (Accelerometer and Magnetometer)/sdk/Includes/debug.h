#ifndef _DEBUG_H
#define _DEBUG_H


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/


/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/


void fnDEBUG_Const_String ( const char * p_char );
void fnDEBUG_String_Size ( char * p_char, uint8_t size );
void fnDEBUG_Uint8_Value ( const char * p_char , const uint8_t u8_data, const char * p_char_after );
void fnDEBUG_Uint16_Value ( const char * p_char , const uint16_t u16_data, const char * p_char_after );
void fnDEBUG_Uint32_Value ( const char * p_char , const uint32_t u32_data, const char * p_char_after );
void fnDEBUG_Int8_Value ( const char * p_char , const int8_t u8_data, const char * p_char_after );
void fnDEBUG_Int16_Value ( const char * p_char , const int16_t u16_data, const char * p_char_after );
void fnDEBUG_Int32_Value ( const char * p_char , const int32_t u32_data, const char * p_char_after );

#endif   /* _DEBUG_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
