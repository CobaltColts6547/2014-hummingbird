#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     c1,             sensorNone)
#pragma config(Sensor, S3,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C2_1,     frontleft,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     backleft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     frontright,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     backright,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     central,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     winch,         tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    armservo,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    rachetservo,          tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)

    /*
    | ------------------------------------------------------------------------------
    | Teleop Code for FTC Team 6547 Cobalt Colts, 2014 Red Hummingbird
    | Final code used at competition
    | Written primarily by head programmer, Ryan Pope
    | Thanks to Sean Doyle, Doc Tassio and Eric Briscoe for their contributions
    | Also thanks to Ben, Ethan, Lex and Jarren for their autonomous
    | Thanks to Tony Ma for driving this robot
    | ® All rights reserved Team 6547
    | ------------------------------------------------------------------------------
    */

#include "JoystickDriver.c"

    /*
    | ------------------------------------------------------------------------------
    | Controller buttons
    | ------------------------------------------------------------------------------
    */
    
    int x = 1; int a = 2; int b = 3; int y = 4;     /* Buttons                    */
    int leftBumper = 5; int rightBumper = 6;        /* bumpers                    */
    int leftTrigger = 7; int rightTrigger = 8;      /* triggers                   */

	task main() {

        waitForStart();
    
        while (true)
        {
            getJoystickSettings(joystick);              /* Updates Joystick settings  */
    
            /*
            | --------------------------------------------------------------------------
            | Joystick control
            | --------------------------------------------------------------------------
            */
            motor[frontleft]        = joystick.joy1_y1 * 100 / 128;
            motor[frontright]       = joystick.joy1_y2 * 100 / 128;
            motor[backleft]         = joystick.joy1_y1 * 100 / 128;
            motor[backright]        = joystick.joy1_y2 * 100 / 128;
	   
            /*
            | --------------------------------------------------------------------------
            | Center wheel control code
            | --------------------------------------------------------------------------
            */

            if (joy1Btn(rightBumper) == 1) {
                motor[central] = -100;
            } else if (joy1Btn(leftBumper) == 1) {
                motor[central] = 100;
            } else {
                motor[central] = 0;
            }

            /*
	        |--------------------------------------------------------------------------
            | Rachet servo control code (Added by Briscoe at last minute)
            | --------------------------------------------------------------------------
            */

            if (joy2Btn(a) == 1) {
                servo[ratchetservo] += 5;
            } else if (joy2Btn(b) == 1) {
                servo[ratchetservo] -= 5;
            } else {
            	servo[ratchetservo] += 0;
          	}
    
            /*
            | --------------------------------------------------------------------------
            | Winch control code
            | --------------------------------------------------------------------------
            */

            if (joy2Btn(leftBumper) == 1) {
                motor[winch]=75;
            } else if (joy2Btn(rightBumper) == 1) {
                motor[winch]=-75;
            } else {
                motor[winch]=0;
            }
        }

}
