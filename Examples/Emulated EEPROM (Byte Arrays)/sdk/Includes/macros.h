#ifndef _MACROS_H
#define _MACROS_H


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/


#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>


/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/


#define mN_ELEMENTS(array)  (sizeof(array) / sizeof(array[0]))

#define mBIT_MASK(PIN)  ( 1 << PIN )
#define mBIT_ZERO(PIN)  ( 0x00 )

#define BIT0 (0x0001)
#define BIT1 (0x0002)
#define BIT2 (0x0004)
#define BIT3 (0x0008)
#define BIT4 (0x0010)
#define BIT5 (0x0020)
#define BIT6 (0x0040)
#define BIT7 (0x0080)
#define BIT8 (0x0100)
#define BIT9 (0x0200)
#define BITA (0x0400)
#define BITB (0x0800)
#define BITC (0x1000)
#define BITD (0x2000)
#define BITE (0x4000)
#define BITF (0x8000)


#define mABS(a)            (((a) <  0 ) ? -(a) : (a))
#ifndef abs
#define abs(a)             mABS(a)
#endif

#define mMIN(a, b)         (((a) < (b)) ?  (a) : (b))
#ifndef min
#define min(a, b)          mMIN(a, b)
#endif

#define mMAX(a, b)         (((a) > (b)) ?  (a) : (b))
#ifndef max
#define max(a, b)          mMAX(a, b)
#endif

#define mSET_BIT_8bits(pos)   ((uint8_t)  (1<<( (uint8_t)  (pos) )))
#define mSET_BIT_16bits(pos)  ((uint16_t) (1<<( (uint16_t) (pos) )))
#define mSET_BIT_32bits(pos)  ((uint32_t) (1<<( (uint32_t) (pos) )))

#define mCHECK_IN_RANGE(x, min, max)   ( (x > min) && (x < max) ? 1 : 0 )
#define mCHECK_IN_RANGE_EQUAL(x, min, max)   ( (x >= min) && (x <= max) ? 1 : 0 )

/** Swaps the upper byte with the lower byte in a 16 bit variable */
#define mSWAP_16bits(x)    ((((x)&0xFF)<<8)|(((x)>>8)&0xFF))
                            
/** The upper 8 bits of a 16 bit value */
#define mMSB_16bits(a)     ((a & 0xFF00) >> 8)
/** The lower 8 bits (of a 16 bit value) */
#define mLSB_16bits(a)     ((a & 0xFF))


/* Converts a 2 Byte array into a 16-Bit value */
#define convert_byte_array_to_16_bit(data)               (*(uint16_t *)((void *)data))

/* Converts a 4 Byte array into a 32-Bit value */
#define convert_byte_array_to_32_bit(data)               (*(uint32_t *)((void *)data))

/* Converts a 8 Byte array into a 64-Bit value */
#define convert_byte_array_to_64_bit(data)               (*(uint64_t *)((void *)data))

/* Converts a 16-Bit value into a 2 Byte array */
#define convert_16_bit_to_byte_array(value, data)        ((*(uint16_t *)((void *)data)) = (uint16_t)(value))

/* Converts spec 16-Bit value into a 2 Byte array */
#define convert_spec_16_bit_to_byte_array(value, data)   ((*(uint16_t *)((void *)data)) = (uint16_t)(value))

/* Converts spec 16-Bit value into a 2 Byte array */
#define convert_16_bit_to_byte_address(value, data)      ((*(uint16_t *)((void *)data)) = (uint16_t)(value))

/* Converts a 32-Bit value into a 4 Byte array */
#define convert_32_bit_to_byte_array(value, data)        ((*(uint32_t *)((void *)data)) = (uint32_t)(value))

/* Converts a 64-Bit value into  a 8 Byte array */
/* Here memcpy requires much less footprint */
#define convert_64_bit_to_byte_array(value, data)        ((*(uint64_t *)((void *)data)) = (uint64_t)(value))

/* Converts a 64-Bit value into  a 8 Byte array */
/* Here memcpy requires much less footprint */
#define convert2_64_bit_to_byte_array(value, data)       memcpy((data), (&(value)), sizeof(uint64_t))


/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


/*************************************************************************************************/
/*    EXTERNAL PROTOTYPES                                                                        */
/*************************************************************************************************/


#endif   /* _MACROS_H */


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
