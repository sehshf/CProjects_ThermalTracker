/*
 * servo_test.c
 *
 *  Created on: 20/10/2016
 *      Author: ses
 */

/*
 * **************************************************
 * SYSTEM INCLUDE FILES								*
 * **************************************************
 */
#include <stdio.h>

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "portable.h"
#include "servo_motor.h"

int main(void)
{
	uint8_T *motor;
	int8_T  *degree;

	InitServos();

	while(1)
    {

		printf("Enter motor\n");
		scanf("%d", &motor);

		printf("Enter degree:\n");
		scanf("%d", &degree);

		DriveServoAbs((uint8_T)motor, (int8_T)degree);
    }

    return PASSED;
} // END: main()

// EOF: servo_test.c
