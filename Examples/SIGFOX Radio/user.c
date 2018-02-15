/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/
/* 
 * uDEV Soluções Tecnológicas Ltda
 * Embedded Development Kit (EDK)
 *
 * SIGFOX Radio Example
 *  
 * In this example, the SIGFOX modem will send one message, without
 * receive confirmation, and end the transmission.
 *
 * To send continuously, re-set the boolean variable to false
 * within the fnRADIO_CALLBACK_TX_End_Ok( ) function.
 *
 *
 */ 

/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/

#include "main.h"
#include "radio.h"
#include "debug.h"
#include "console_usb.h"
#include "delay_loop.h"

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

bool sent=false;

/*************************************************************************************************/
/*    INTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnUSER_Setup()
{
   // Code within this context will be run ONCE.
   
   
   fnCONSOLE_USB_Init( );
   // After starting the USB Virtual COM Port, we inserted a delay of 500ms to allow
   // the connection to be established, so we are able to print the SIGFOX data below.
   fnDELAY_LOOP_ms( 500 );
   
   fnRADIO_Init( );
   fnDEBUG_Const_String( "\r\nSigfox ID: " );
   fnDEBUG_String_Size( fnRADIO_Get_Sigfox_Id(), 8 );
   fnDEBUG_Const_String( "; \r\n" );

   fnDEBUG_Const_String( "Sigfox PAC: " );
   fnDEBUG_String_Size(  fnRADIO_Get_Sigfox_Pac(), 16 );
   fnDEBUG_Const_String( "; \r\n" );
   fnDEBUG_Uint8_Value( "SIGFOX Downlink Data: ", fnRADIO_Get_Sigfox_Downlink_Data( ), "; \r\n" );
}

void fnUSER_Loop( )
{
   // Code within this context will be run continuously.
   if ( sent==false )
   {
   	// In this configuration, the SIGFOX sends a message without expecting a confirmation
   	// from the server, only a confirmation that the transmission (TX) was successful.
      fnRADIO_Send_Message( "Test", 4, false );
      sent = true;
   }      
}

// Please check the "radio.h" file in the /SDK/INCLUDES folder for explanations on each function.

void fnRADIO_CALLBACK_Tx_End_Ok( ) {   
   fnDEBUG_Const_String( "TX_End_OK\r\n" );
   sent = false;
}

void fnRADIO_CALLBACK_Tx_End_Error( ) {
   fnDEBUG_Const_String( "TX_End_Error\r\n" );
   sent = false;
}

void fnRADIO_CALLBACK_Rx_End_Ok( ) {
   fnDEBUG_Const_String( "RX_End_Ok\r\n" );
   fnDEBUG_Uint8_Value( "SIGFOX Downlink Data: ", fnRADIO_Get_Sigfox_Downlink_Data( ), "; \r\n" );
   sent = false;
}

void fnRADIO_CALLBACK_Rx_End_Error( ) {
   fnDEBUG_Const_String( "RX_End_error\r\n" );
   sent = false;
}
/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/