#ifndef _RADIO_H
#define _RADIO_H


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


typedef enum {

   RADIO_STATUS_OK,
   RADIO_STATUS_WARNING,
   RADIO_STATUS_CRITICAL,
   RADIO_STATUS_ERROR,

} en_radio_status_t;


typedef enum {

   RADIO_MODE_IDLE,
   RADIO_MODE_SLEEP,
   RADIO_MODE_TX,
   RADIO_MODE_TX_RX,
   RADIO_MODE_TX_RX_GET_DATA,

} en_radio_state_t;


typedef union {

   uint8_t u8_value;

   struct {

      uint8_t b_comm_error          :1;
      uint8_t b_cpu_indicator_error :1;
      uint8_t b_tx_indicator_error  :1;
      uint8_t b_rx_indicator_error  :1;

   } st_bitfield;

} un_radio_error_t;


typedef struct {

/* Control */
   en_radio_status_t en_status;
   en_radio_state_t  en_state;
   un_radio_error_t  un_error;

/* Data */
   uint8_t au8_sigfox_id[8];
   uint8_t au8_sigfox_pac[16];
   uint8_t au8_sigfox_downlink[8];

} st_radio_data_t;


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// This function initializes the SIGFOX Radio.
bool fnRADIO_Init ( void );

// This function sends a message via the Radio, and is described at length at our GitHub page
bool fnRADIO_Send_Message ( uint8_t * pu8_data, uint8_t u8_size, bool b_receive );

// This function returns the struct with the data currently in the Radio
const st_radio_data_t * fnRADIO_Get_Data_Pointer ( void );

// These functions get information on the Radio modem
const uint8_t * fnRADIO_Get_Sigfox_Id ( void );
const uint8_t * fnRADIO_Get_Sigfox_Pac ( void );
const uint8_t * fnRADIO_Get_Sigfox_Downlink_Data ( void );

// This function will be called whenever a message is sent successfully.
void fnRADIO_CALLBACK_Tx_End_Ok ( void );

// This function is called whenever a message sets off a "error in transmission" flag.
// Be warned that the message may still be transmitted even if this flag gets activated,
// it just informs that there was an error in the serial communication.
void fnRADIO_CALLBACK_Tx_End_Error ( void );

// The following two functions will only be called if the flag b_receive is TRUE when
// sending a message. == MAY INCUR ADDITIONAL COSTS, PLEASE CONFIRM YOUR SIGFOX PLAN ==

// This function will be called after the receiver sends back a confirmation
// that the message was received.
void fnRADIO_CALLBACK_Rx_End_Ok ( void );

// This function gets called when the receiver warns that there was an error in transmission, and
// didn't receive a valid message.
void fnRADIO_CALLBACK_Rx_End_Error ( void );


#endif  /* _RADIO_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
