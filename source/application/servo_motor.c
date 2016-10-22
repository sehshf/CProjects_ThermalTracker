/*
 * servo_motor.c
 *
 *  Created on: 22/10/2016
 *      Author: ses
 */

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "servo_motor.h"


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
*      INITSERVOS()
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
pf_T InitServos(void)
{

	SetupPCABoard();

	return PASSED;

} // END: InitServos()


/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      DRIVESERVO()
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
pf_T DriveServoInc(uint8_T motor, boolean_T direction, uint8_T degree)
{
    return PASSED;

} // END: DriveServo()

/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      DRIVESERVO()
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
pf_T DriveServoAbs(uint8_T motor, uint8_T degree)
{
    return PASSED;

} // END: DriveServoAbs()


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


// EOF: servo_motor.c

