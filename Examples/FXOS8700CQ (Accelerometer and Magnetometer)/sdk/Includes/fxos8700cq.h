#ifndef _FXOS8700CQ_H
#define _FXOS8700CQ_H

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/


#include <stdint.h>
#include <stdbool.h>


/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/


#define FXOS8700CQ_I2C_BUS_ADDRESS     0x1E  // with pins SA0=0, SA1=0

#define FXOS8700CQ_DEVICE_ID           0xC7


/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


typedef enum {

   FXOS8700CQ_STATUS_OK,
   FXOS8700CQ_STATUS_WARNING,
   FXOS8700CQ_STATUS_CRITICAL,
   FXOS8700CQ_STATUS_ERROR,

} en_fxos8700cq_status_t;


typedef enum {

   FXOS8700CQ_STATE_IDLE,
   FXOS8700CQ_STATE_ACCEL_ONLY,
   FXOS8700CQ_STATE_MAG_ONLY,
   FXOS8700CQ_STATE_HYBRID,

} en_fxos8700cq_state_t;


typedef union {

   uint8_t u8_value;

   struct {

		uint8_t b_i2c_transfer_nack   :1;
		uint8_t b_i2c_transfer_failed :1;
		uint8_t b_invalid_device_id   :1;
		uint8_t b_timeout             :1;
		uint8_t reserved              :4;

   } st_bitfield;

} un_fxos8700cq_error_t;


typedef struct {

   int16_t i16_raw_x;
   int16_t i16_raw_y;
   int16_t i16_raw_z;

} st_fxos8700cq_raw_data_t;

typedef struct {
   
   int16_t i16_converted_x;
   int16_t i16_converted_y;
   int16_t i16_converted_z;
   
} st_fxos8700cq_converted_data_t;

typedef enum {

   FXOS8700CQ_OPERATION_MODE_MAG_ONLY,
   FXOS8700CQ_OPERATION_MODE_ACCEL_ONLY,
   FXOS8700CQ_OPERATION_MODE_HYBRID,

} en_fxos8700cq_operation_mode_t;


typedef struct {

   /* Control */
   en_fxos8700cq_status_t en_status;
   en_fxos8700cq_state_t  en_state;
   un_fxos8700cq_error_t  un_last_error;
   en_fxos8700cq_operation_mode_t en_operation_mode;

   /* Data */
   st_fxos8700cq_raw_data_t st_accel_raw_data;
   st_fxos8700cq_raw_data_t st_mag_raw_data;

} st_fxos8700cq_data_t;


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// This function initializes the 6-axis sensor.
bool fnFXOS8700CQ_Init ( en_fxos8700cq_operation_mode_t en_mode );

// This function puts the sensor in "ready to read" mode, and realizes a measurement.
void fnFXOS8700CQ_Enable ( void );

// Disable puts the component in low-power mode, returning it to standby.
void fnFXOS8700CQ_Disable ( void );

// After a successful Enable, the following functions return either:
// A struct with the raw data containing all the data acquired by the sensor
const st_fxos8700cq_data_t * fnFXOS8700CQ_Get_Data_Pointer ( void );

// A struct with the converted accelerometer data, in mg (mili g-force)
const st_fxos8700cq_converted_data_t * fnFXOS8700CQ_Get_Accel_Data ( void );

// Or a struct with the converted magnetometer data, in uT (microTesla)
const st_fxos8700cq_converted_data_t * fnFXOS8700CQ_Get_Mag_Data ( void );


// The callback function is called automatically at the successful end of the Enable function.
void fnFXOS8700CQ_CALLBACK_Measure_Done ( void );



#if defined(__cplusplus)
}
#endif /* __cplusplus */


#endif   /* _FXOS8700CQ_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
