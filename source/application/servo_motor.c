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
static int8_T 	servoPos = 0;	// Can vary from -90 to 90


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
void InitServos(void)
{
	SetupPCABoard();
	SetPCAFreq(50);		// 50 Hz
	DriveServoAbs(YAW_MOTOR  , 0);
	DriveServoAbs(PITCH_MOTOR, 0);

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
void DriveServoAbs(uint8_T motor, int8_T degree)
{
	uint16_T pulse;

	pulse = SERVO_PULSE_NEUT + degree * (SERVO_PULSE_MAX - SERVO_PULSE_MIN) / SERVO_POS_MAX / 2;	// pulse [ms]

	servoPos = degree;		// Update position

	SetPCAPWM(motor, pulse);

} // END: DriveServoAbs()

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
void DriveServoInc(uint8_T motor, boolean_T direction, int8_T degree)
{
    servoPos = servoPos + direction * degree;
    servoPos = min(SERVO_POS_MAX, max(-SERVO_POS_MAX, servoPos));
    DriveServoAbs(motor, servoPos);

} // END: DriveServoInc()


/**
*  -------------------------------------------------------  *
*  FUNCTION:
*      GETSERVOPOS()
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
int8_T GetServoPos(void)
{
	return servoPos;

} // END: GetServoPos()


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

