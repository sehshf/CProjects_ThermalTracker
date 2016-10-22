/*
 * pca9685.h
 *
 *  Created on: 22/10/2016
 *      Author: ses
 */

#ifndef _PCA9685_H_
#define _PCA9685_H_

/*
 * **************************************************
 * SYSTEM INCLUDE FILES								*
 * **************************************************
 */


/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "i2c_smbus.h"

/*
 * **************************************************
 * DEFINITIONS										*
 * **************************************************
 */
// Device address
#define PCA9685_ADDR	0x40

// PCA9685 registers
#define MODE1				0x00
#define MODE2				0x01

#define LED0_ON_L 			0x06
#define LED0_ON_H 			0x07
#define LED0_OFF_L 			0x08
#define LED0_OFF_H 			0x09
#define LED1_ON_L 			0x0A
#define LED1_ON_H 			0x0B
#define LED1_OFF_L 			0x0C
#define LED1_OFF_H 			0x0C

#define ALL_LED_ON_L		0xFA
#define ALL_LED_ON_H		0xFB
#define ALL_LED_OFF_L		0xFC
#define ALL_LED_OFF_H		0xFD
#define PRE_SCALE			0xFE

// Register bits
#define PCA9685_OUTDRV		0x04
#define PCA9685_ALLCALL 	0x01
#define PCA9685_SLEEP   	0x10

/*
 * **************************************************
 * MACROS											*
 * **************************************************
 */



/*
 * **************************************************
 * TYPE DEFINITIONS									*
 * **************************************************
 */



/*
 * **************************************************
 * External VARIABLES       						*
 * **************************************************
 */




/*
 * **************************************************
 * PROTOTYPES										*
 * **************************************************
 */


#endif // _PCA9685_H_

// EOF: pca9685.h


