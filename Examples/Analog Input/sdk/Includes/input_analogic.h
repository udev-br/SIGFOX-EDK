#ifndef _INPUT_ANALOGIC_H
#define _INPUT_ANALOGIC_H


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include <stdint.h>

/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/


/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


typedef enum {

   INPUT_ANALOGIC_DEFINITION_VBAT,
   INPUT_ANALOGIC_DEFINITION_4_20_MA,

   INPUT_ANALOGIC_DEFINITION_SIZE,

} en_input_analogic_definition_t;


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// Initializes the Analog Input processes.
void fnINPUT_ANALOGIC_Init ( void );

// Realizes a reading of either the analog input in the blue pins,
// or the voltage currently in the battery.
// Without a battery attached, if reading the Battery voltage, should display approximately 2 Volts.
void fnINPUT_ANALOGIC_Read_Value ( en_input_analogic_definition_t en_input, uint16_t * p_adc_raw, uint16_t * p_adc_mv );


#endif  /* _INPUT_ANALOGIC_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
