#ifndef _DS18B20_H
#define _DS18B20_H


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

   DS18B20_STATUS_OK,
   DS18B20_STATUS_WARNING,
   DS18B20_STATUS_CRITICAL,
   DS18B20_STATUS_ERROR,

} en_ds18b20_status_t;


typedef enum {

   EN_DS18B20_STATE_IDLE,
   EN_DS18B20_STATE_ACQUIRING,

} en_ds18b20_state_t;


typedef union {

   uint8_t u8_value;

   struct {

      uint8_t b_no_presence_error   :1;
      uint8_t b_crc_error           :1;
      uint8_t reserved              :6;

   } st_bitfield;

} un_ds18b20_error_t;


typedef enum {

   DS18S20MODEL   = 0x10,
   DS18B20MODEL   = 0x28,
   DS1822MODEL    = 0x22,
   DS1825MODEL    = 0x3B,
   DS28EA00MODEL  = 0x42,

} en_ds18b20_model_t;


typedef struct {

/* Control */
   en_ds18b20_status_t en_status;
   en_ds18b20_state_t  en_state;
   un_ds18b20_error_t  un_last_error;

/* Data */
   en_ds18b20_model_t en_model;
   uint8_t au8_rom_id[8];
   float f_temperature_in_C;

} st_ds18b20_data_t;


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/

// The Init function configures and readies the DS18B20 temperature sensor. Call it before
// using the sensor in whichever application.
// The parameter to be passed is the number of probes currently connected (in parallel), from 1 to 8.
bool fnDS18B20_Init ( uint8_t u8_channel );

// Get_Data_Pointer will return the raw data that is in the temperature registers in the channel specified.
// This function is used to identify probes individually, using their au8_rom_id value present in this function.
// Addresses range from 0 to 7.
const st_ds18b20_data_t * fnDS18B20_Get_Data_Pointer ( uint8_t u8_channel );

// Get_Temperature returns a float already in the proper temperature format, of the probe in the channel specified.
float fnDS18B20_Get_Temperature ( uint8_t u8_channel );

// The Measure_Start_Blocking_Mode will halt the program's execution until the measurement is complete.
bool fnDS18B20_Measure_Start_Blocking_Mode ( void );

// The Measure_Start_Callback function will begin a new temperature measurement.
bool fnDS18B20_Measure_Start_Callback_Mode ( void );

// This Measure_Done_Callback function will be called automatically after the Measure_Start_Callback_Mode function is finished properly.
// When this function is called, the device is ready to have its temperature measurement read by the Get_Temperature function.
void fnDS18B20_Measure_Done_Callback ( void );

// The two functions below only work properly if either the Measure_Start_Blocking_Mode function
// was called and finished properly, or if the Measure_Start_Callback_Mode was used and
// called Measure_Done_Callback automatically.


#endif   /* _DS18B20_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
