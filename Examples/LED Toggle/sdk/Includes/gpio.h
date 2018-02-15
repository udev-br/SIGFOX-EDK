#ifndef _GPIO_H
#define _GPIO_H


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include <stdbool.h>

/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// This function is used to set the LED level directly, to ON (true) or OFF (false).
void fnGPIO_LED_Set_Level ( bool level );
// This function toggles the current state of the LED. If it is on, turns it off, and vice-versa.
void fnGPIO_LED_Toggle ( void );

// The following function returns the current state of the user button.
// If it is pressed, returns False, and if it is not pressed, returns True.
bool fnGPIO_BUTTON_Get_Level ( void );


#endif  /* _GPIO_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
