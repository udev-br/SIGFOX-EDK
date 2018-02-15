#ifndef _SI1133_H
#define _SI1133_H


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/


#include <stdint.h>
#include <stdbool.h>


/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/


#define SI1133_I2C_BUS_ADDRESS   (0xAA>>1)

#define SI1133_CONFIG_I2C_BUS_TIMEOUT ( 1000 )
//#define SI1133_CONFIG_BUS_ADDRESS     ( 0xAA )


/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


typedef enum {

	SI1133_STATUS_OK,
	SI1133_STATUS_WARNING,
	SI1133_STATUS_CRITICAL,
	SI1133_STATUS_ERROR,

} en_si1133_status_t;


typedef enum {

	SI1133_STATE_IDLE,
	SI1133_STATE_ACQUIRING,

} en_si1133_state_t;


typedef union {

	uint8_t u8_value;

	struct {

		uint8_t b_i2c_transfer_nack   :1;
		uint8_t b_i2c_transfer_failed :1;
		uint8_t b_invalid_device_id   :1;
		uint8_t b_timeout             :1;
		uint8_t reserved              :4;

	} st_bitfield;

} un_si1133_error_t;


typedef struct {

/* Control */
	en_si1133_status_t en_status;
	en_si1133_state_t  en_state;
	un_si1133_error_t  un_last_error;

/* Data */
	float f_lux;
	float f_uvi;

} st_si1133_data_t;


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// This function initializes the component.
bool fnSI1133_Init ( void );

// This function will start and finish a measurement on the so-called
// "blocking mode", which will halt the rest of the application until the
// measurement is complete
bool fnSI1133_Measure_Start_Blocking_Mode ( void );

// This function operates on a "callback mode", and the application
// isn't halted during the measurement. After the measurement is complete,
// the Measure_Done_Callback function will be called automatically.
bool fnSI1133_Measure_Start_Callback_Mode ( void );
void fnSI1133_Measure_Done_Callback ( void );

// This function returns the struct with the entire raw data
const st_si1133_data_t * fnSI1133_Get_Data_Pointer ( void );

// This function returns the ambient light, in Lux
float fnSI1133_Get_Lux ( void );
// This function returns the ambient ultraviolet reading, in UV index
float fnSI1133_Get_Uvi ( void );


#endif   /* _SI1133_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/

