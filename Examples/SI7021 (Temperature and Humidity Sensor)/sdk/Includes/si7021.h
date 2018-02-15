#ifndef _SI7021_H
#define _SI7021_H


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/


#include <stdint.h>
#include <stdbool.h>


/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/


#define SI7021_I2C_BUS_ADDRESS   0x40


/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


typedef enum {

	SI7021_STATUS_OK,
	SI7021_STATUS_WARNING,
	SI7021_STATUS_CRITICAL,
	SI7021_STATUS_ERROR,

} en_si7021_status_t;


typedef enum {

	SI7021_STATE_IDLE,
	SI7021_STATE_ACQUIRING,

} en_si7021_state_t;


typedef union {

	uint8_t u8_value;

	struct {

		uint8_t b_i2c_transfer_nack   :1;
		uint8_t b_i2c_transfer_failed :1;
		uint8_t b_invalid_device_id   :1;
		uint8_t b_timeout             :1;
		uint8_t reserved              :4;

	} st_bitfield;

} un_si7021_error_t;


typedef enum {

   ID_SAMPLE = 0xFF,
   ID_SI7006 = 0x06,
   ID_SI7013 = 0x0D,
   ID_SI7020 = 0x14,
   ID_SI7021 = 0x15,

} en_si7021_model_t;


typedef struct {

/* Control */
	en_si7021_status_t en_status;
	en_si7021_state_t  en_state;
	un_si7021_error_t  un_last_error;

/* Data */
	en_si7021_model_t en_model;
   uint32_t u32_rh_data;
   int32_t  i32_temperature_data;

} st_si7021_data_t;


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// This function initializes the component.
bool fnSI7021_Init ( void );

// This function will start and finish a measurement on the so-called
// "blocking mode", which will halt the rest of the application until the
// measurement is complete
bool fnSI7021_Measure_Start_Blocking_Mode ( void );

// This function operates on a "callback mode", and the application
// isn't halted during the measurement. After the measurement is complete,
// the Measure_Done_Callback function will be called automatically.
bool fnSI7021_Measure_Start_Callback_Mode ( void );
void fnSI7021_Measure_Done_Callback ( void );

// This function returns the struct with the entire raw data
st_si7021_data_t * fnSI7021_Get_Data_Pointer ( void );

// Use this function to get the Relative Humidity, in a 32-bit unsigned integer.
// Divide by 1000 to get the RH in proper %
uint32_t fnSI7021_Get_RH ( void );

// This function returns the temperature in a 32-bit signed integer
// You have to divide by 1000 to get the proper temperature float variable, in degrees celsius
int32_t  fnSI7021_Get_Temperature ( void );


#endif   /* _SI7021_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
