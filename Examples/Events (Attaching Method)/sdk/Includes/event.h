#ifndef _EVENT_H
#define _EVENT_H


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


typedef enum {

   EVENT_SYSTEM_NONE,

   EVENT_SYSTEM_INIT,

   EVENT_SYSTEM_RTC,

   EVENT_INPUT_BUTTON_RELEASE,
   EVENT_INPUT_BUTTON_PRESS,
   EVENT_INPUT_BUTTON_RELEASE_HOLD,
   EVENT_INPUT_BUTTON_PRESS_HOLD,

   EVENT_INPUT_EXTERNAL_RELEASE,
   EVENT_INPUT_EXTERNAL_PRESS,
   EVENT_INPUT_EXTERNAL_RELEASE_HOLD,
   EVENT_INPUT_EXTERNAL_PRESS_HOLD,

} en_event_t;


typedef void ( * pfn_event_callback_t ) ( void );


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// Function that treats all events, if the event in question
// hasn't any attached callbacks.
void fnEVENT_Callback ( en_event_t en_event );

// Function for attaching a user-defined and user-implemented function to
// an event. Every time the event in question occurs, said function is called.
bool fnEVENT_Attach_Callback ( en_event_t en_event, pfn_event_callback_t pfn_callback );

// This function detaches all functions associated with the event provided
// as a parameter.
bool fnEVENT_Deattach_Callback ( en_event_t en_event );


#endif  /* _EVENTS_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
