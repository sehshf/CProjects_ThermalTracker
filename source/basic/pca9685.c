/*
 * pca9685.c
 *
 *  Created on: 22/10/2016
 *      Author: ses
 */

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "pca9685.h"


/*
 * **************************************************
 * LOCAL DECLARATIONS								*
 * **************************************************
 */



/*
 * **************************************************
 * GLOBAL VARIABLES (extern)						*
 * **************************************************
 */



/*
 * **************************************************
 * FILE SCOPE VARIABLES (static)					*
 * **************************************************
 */



/*
 * **************************************************
 * LOCAL PROTOTYPES									*
 * **************************************************
 */



/*
 * **************************************************
 * PUBLIC FUNCTIONS									*
 * **************************************************
 */

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      PUBLICFUCTION()
*      What this function is doing.
*
*  Inputs:
*      x : Input
*
*  Outputs:
*      y : Return 0 when succeeded.
*
*  Author: Ehsan Shafiei
*  		   Aug 2016
*  -------------------------------------------------------  *
*/
pf_T SetupPCABoard()
{
	int32_T fd;

	fd = AccessI2CBus((const char *)I2C_FILE, PCA9685_ADDR);

	InitOnOffReg(fd);
	InitDeviceMode(fd);

	return PASSED;

} // END: SetupPCABoard()


/*
 * **************************************************
 * LOCAL FUNCTIONS									*
 * **************************************************
 */
/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      INITONOFFREG()
*      What this function is doing.
*
*  Inputs:
*      x : Input
*
*  Outputs:
*      y : Return 0 when succeeded.
*
*  Author: Ehsan Shafiei
*  		   Oct 2016
*  -------------------------------------------------------  *
*/
static void InitOnOffReg(int32_T file)
{
    SMBusWrite8(file, ALL_LED_ON_L , 0x00);
    SMBusWrite8(file, ALL_LED_ON_H , 0x00);
    SMBusWrite8(file, ALL_LED_OFF_L, 0x00);
    SMBusWrite8(file, ALL_LED_OFF_H, 0x00);

} // END: InitOnOffReg()


/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      INITDEVICEMODE()
*      What this function is doing.
*
*  Inputs:
*      x : Input
*
*  Outputs:
*      y : Return 0 when succeeded.
*
*  Author: Ehsan Shafiei
*  		   Oct 2016
*  -------------------------------------------------------  *
*/
static void InitDeviceMode(int32_T file)
{


	SMBusWrite8(file, MODE2 , PCA9685_OUTDRV);		// Default for MODE2
	SMBusWrite8(file, MODE1 , PCA9685_ALLCALL);		// Normal mode
	usleep(500); 									// Wait for oscillator

	SMBusWrite8(file, ALL_LED_ON_L , 0x00);



} // END: InitDeviceMode()


// EOF: pca9685.c




if (read(file, buff, 1) != 1)
{
	printf("Failed to read from device.\n");
}
else
{
	mode1buff = buff[0] & ~SLEEP;	// wake up (reset sleep)
}

buff[0] = MODE1;
buff[1] = mode1buff;
write(file, buff, 2);
printf("Wake up.\n");
usleep(10000);	// wait for oscillator
