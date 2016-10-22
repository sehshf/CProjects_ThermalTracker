/*
 * i2c_smbus.c
 *
 *  Created on: 22/10/2016
 *      Author: ses
 */

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "i2c_smbus.h"


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
*      ACCESSI2CBUS()
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
int32_T AccessI2CBus(const char *fName, int32_T addr)
{
	int32_T fd;

	if ((fd = open(fName, O_RDWR)) < 0)
	{
        sprintf(stderr, "Failed to open the I2C bus.");
        exit(1);
    }

    if (ioctl(fd, I2C_SLAVE, addr) < 0)
    {
        sprintf(stderr, "Failed to communicate with the I2C slave device.\n");
        exit(1);
    }

	return fd;

} // END: AccessI2CBus()

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      SMBUSWRITE8()
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
void SMBusWrite8(int32_T file, uint8_T reg, uint8_T val)
{
	static uint8_T buf[2] = {0, 0};

	buf[0] = reg;
	buf[1] = val;

	if (write(file, buf, 2) != 2)
	{
		sprintf(stderr, "Failed to write to the I2C bus.\n");
	}

} // END: SMBusWrite8()

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      SMBUSREAD8()
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
void SMBusRead8(int32_T file)
{
	uint8_T *buf;

	if (read(file, buf, 1) != 1)
	{
		sprintf(stderr, "Failed to read from the I2C bus.\n");
	}

} // END: SMBusRead8()


/*
 * **************************************************
 * LOCAL FUNCTIONS									*
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
//static type LocalFunction(type x)
//{
//    return y;
//} // END: LocalFunction()

// EOF: i2c_smbus.c

