#ifndef _MCP9600_H
#define _MCP9600_H


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/


#include <stdint.h>
#include <stdbool.h>


/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/


#define MCP9600_I2C_BUS_ADDRESS   (0x60)


/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


typedef enum {

   MCP9600_STATUS_OK,
   MCP9600_STATUS_WARNING,
   MCP9600_STATUS_CRITICAL,
   MCP9600_STATUS_ERROR,

} en_mcp9600_status_t;


typedef enum {

   EN_MCP9600_STATE_IDLE,
   EN_MCP9600_STATE_ACQUIRING,

} en_mcp9600_state_t;


typedef union {

   uint8_t u8_value;

   struct {

      uint8_t b_no_presence_error   :1;
      uint8_t b_crc_error           :1;
      uint8_t reserved              :6;

   } st_bitfield;

} un_mcp9600_error_t;


typedef union {

   uint8_t u8_value;

   struct {
      
      uint8_t status_alert_1       : 1;
      uint8_t status_alert_2       : 1;
      uint8_t status_alert_3       : 1;
      uint8_t status_alert_4       : 1;
      uint8_t flag_input_range     : 1;
      uint8_t                      : 1;
      uint8_t flag_th_update       : 1;
      uint8_t flag_burst_complete  : 1;

   } st_fields;

} un_mcp9600_status_register_t;


typedef enum {

   MCP9600_RETURN_STATUS_OK,
   MCP9600_RETURN_STATUS_ERROR,

} en_mcp9600_return_status_t;


typedef enum {
   
   MCP9600_TYPE_K = 0b000,
   MCP9600_TYPE_J = 0b001,
   MCP9600_TYPE_T = 0b010,
   MCP9600_TYPE_N = 0b011,
   MCP9600_TYPE_S = 0b100,
   MCP9600_TYPE_E = 0b101,
   MCP9600_TYPE_B = 0b110,
   MCP9600_TYPE_R = 0b111,
   
} en_mcp9600_thermocouple_type_t;


typedef enum {
   
   MCP9600_FILTER_0 = 0b000,
   MCP9600_FILTER_1 = 0b001,
   MCP9600_FILTER_2 = 0b010,
   MCP9600_FILTER_3 = 0b011,
   MCP9600_FILTER_4 = 0b100,
   MCP9600_FILTER_5 = 0b101,
   MCP9600_FILTER_6 = 0b110,
   MCP9600_FILTER_7 = 0b111,

} en_mcp9600_filter_coefficients_t;


typedef enum {

   MCP9600_COLD_JUNCTION_RESOLUTION_0_0625 = 0,
   MCP9600_COLD_JUNCTION_RESOLUTION_0_25   = 1,

} en_mcp9600_cold_junction_resolution_t;


typedef enum {

   MCP9600_ADC_MEASUREMENT_RESOLUTION_18_BITS = 0,
   MCP9600_ADC_MEASUREMENT_RESOLUTION_16_BITS = 1,
   MCP9600_ADC_MEASUREMENT_RESOLUTION_14_BITS = 2,
   MCP9600_ADC_MEASUREMENT_RESOLUTION_12_BITS = 3,

} en_mcp9600_adc_measurement_resolution_bits_t;


typedef enum {

   MCP9600_BURST_SAMPLE_1   = 0,
   MCP9600_BURST_SAMPLE_2   = 1,
   MCP9600_BURST_SAMPLE_4   = 2,
   MCP9600_BURST_SAMPLE_8   = 3,
   MCP9600_BURST_SAMPLE_16  = 4,
   MCP9600_BURST_SAMPLE_32  = 5,
   MCP9600_BURST_SAMPLE_64  = 6,
   MCP9600_BURST_SAMPLE_128 = 7,
   
} en_mcp9600_burst_samples_t;


typedef enum {

   MCP9600_MODE_NORMAL     = 0,
   MCP9600_MODE_SHUTDOWN   = 1,
   MCP9600_MODE_BURST_MODE = 2,
   MCP9600_MODE_RESERVED   = 3,

} en_mcp9600_shutdown_mode_t;


//typedef union {
//
   //uint8_t u8_value;
//
   //struct {
      //
      //uint8_t status_alert_1       : 1;
      //uint8_t status_alert_2       : 1;
      //uint8_t status_alert_3       : 1;
      //uint8_t status_alert_4       : 1;
      //uint8_t flag_input_range     : 1;
      //uint8_t                      : 1;
      //uint8_t flag_th_update       : 1;
      //uint8_t flag_burst_complete  : 1;
//
   //} st_fields;
//
//} un_mcp9600_status_register_t;


typedef union {

   uint8_t u8_value;

   struct {
      
      uint8_t filter_coefficients   : 3;
      uint8_t                       : 1;
      uint8_t thermocouple_type_sel : 3;
      uint8_t                       : 1;

   } st_fields;
   
} un_mcp9600_sensor_config_t;


typedef union {

   uint8_t u8_value;

   struct {
      
      uint8_t shutdown_mode            : 2;
      uint8_t burst_mode               : 3;
      uint8_t adc_resolution           : 2;
      uint8_t cold_junction_resolution : 1;

   } st_fields;

} un_mcp9600_device_config_t;


typedef struct {

   en_mcp9600_adc_measurement_resolution_bits_t en_adc_res_bits;
   en_mcp9600_cold_junction_resolution_t en_cold_junction_res;
   en_mcp9600_filter_coefficients_t en_filter_coefficients;
   en_mcp9600_thermocouple_type_t en_thermocouple_type;

} st_mcp9600_config_t;


typedef struct {

/* Control */
   en_mcp9600_status_t en_status;
   en_mcp9600_state_t  en_state;
   un_mcp9600_error_t  un_last_error;

// remove?
   un_mcp9600_sensor_config_t un_sensor_config;
   un_mcp9600_device_config_t un_device_config;
   un_mcp9600_status_register_t un_status_register;

/* Data */
   bool b_valid_data;
   int32_t i32_thermocouple_temperature;
   int16_t i16_junction_temperature_delta;
   int16_t i16_cold_junction_temperature;
   int32_t i32_raw_adc_data;

} st_mcp9600_data_t;


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/


bool fnMCP9600_Init ( void );
bool fnMCP9600_Config ( st_mcp9600_config_t * pst_mcp9600_config );

const st_mcp9600_data_t * fnMCP9600_Get_Data_Pointer ( void );
int32_t fnMCP9600_Get_Temperature ( void );

bool fnMCP9600_Measure_Start_Blocking_Mode ( void );

bool fnMCP9600_Measure_Start_Callback_Mode ( void );
void fnMCP9600_Measure_Done_Callback ( void );


#endif   /* _MCP9600_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/

