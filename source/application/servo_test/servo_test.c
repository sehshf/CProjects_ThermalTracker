/*
 * servo_test.c
 *
 *  Created on: 20/10/2016
 *      Author: ses
 */

//#include <glib.h>
//#include <glib/gprintf.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define ALL_LED_ON_L       0xFA
#define ALL_LED_ON_H       0xFB
#define ALL_LED_OFF_L      0xFC
#define ALL_LED_OFF_H      0xFD

#define MODE1              0x00
#define MODE2              0x01

#define SLEEP              0x10

#define PRE_SCALE 0xFE
#define LED0_ON_L 0x06
#define LED0_ON_H 0x07
#define LED0_OFF_L 0x08
#define LED0_OFF_H 0x09

#define SERVO_DELAY 205


int main(void) {
    int file, i;
    char filename[40], buff[3], mode1buff, oldmode, newmode;
    int addr = 0x40;        // The I2C address of the ADC
    char rBuff[10] = {0};

    unsigned short pulse, onCnt, offCnt;
//    unsigned char onH, onL, offH, offL;

    sprintf(filename,"/dev/i2c-1");
    if ((file = open(filename,O_RDWR)) < 0) {
        printf("Failed to open the bus.");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }

    if (ioctl(file,I2C_SLAVE,addr) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }


    buff[0] = ALL_LED_ON_L;
    buff[1] = 0x00;
    write(file, buff, 2);

    buff[0] = ALL_LED_ON_H;
    buff[1] = 0x00;
    write(file, buff, 2);

    buff[0] = ALL_LED_OFF_L;
    buff[1] = 0x00;
    write(file, buff, 2);

    buff[0] = ALL_LED_OFF_H;
    buff[1] = 0x00;
    write(file, buff, 2);




    buff[0] = MODE2;
    buff[1] = 0x04;
    write(file, buff, 2);

    buff[0] = MODE1;
    buff[1] = 0x01;
    write(file, buff, 2);


    usleep(10000);


//    if (read(file, rBuff, 1) != 1)
//	{
//		printf("Failed to read from device.\n");
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", (int)rBuff[i]);
//	}
//    putchar('G');

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


    if (read(file, buff, 1) != 1)
	{
		printf("Failed to read from device.\n");
	}
	else
	{
		oldmode = buff[0];
		newmode = (oldmode & 0x7F) | SLEEP;    // sleep
	}

    buff[0] = MODE1;
    buff[1] = newmode;
    write(file, buff, 2);  // go to sleep

    //unsigned char reg = 0x10; // Device register to access
    buff[0] = PRE_SCALE;
    buff[1] = 0x79;	// 50 Hz
    if (write(file, buff, 2) != 2) {
        /* ERROR HANDLING: i2c transaction failed */
        printf("Failed to write to the i2c bus.\n");
    }

    buff[0] = MODE1;
    buff[1] = oldmode;
    write(file, buff, 2);
    usleep(10000);

    buff[0] = MODE1;
    buff[1] = oldmode | 0x80;
    write(file, buff, 2);

    sleep (1);

    while(1)
    {
		printf("Enter pulse width:");
		scanf("%u", &pulse);

		onCnt  = SERVO_DELAY;
		offCnt = SERVO_DELAY + pulse * 4096 / 20000;


		buff[0] = LED0_ON_L;
		buff[1] = (unsigned char)(onCnt & 0x00FF);
		write(file, buff, 2);

		buff[0] = LED0_ON_H;
		buff[1] = (unsigned char)(onCnt >> 8);
		write(file, buff, 2);
		printf("On drive.\n");
		usleep(1000);

		buff[0] = LED0_OFF_L;
		buff[1] = (unsigned char)(offCnt & 0x00FF);
		write(file, buff, 2);

		buff[0] = LED0_OFF_H;
		buff[1] = (unsigned char)(offCnt >> 8);
		write(file, buff, 2);
		printf("Off drive.\n");
		usleep(1000);
    }
//
    return 0;

}
