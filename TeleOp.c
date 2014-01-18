#include "config.h"
#include "JoystickDriver.c"

task main() {
    //This code was written by Ryan Pope.
    //Sean is the bonaestest programmer.
    waitForStart();

    /*
    | ------------------------------------------------------------------------------
    | Controller buttons
    | ------------------------------------------------------------------------------
    */
    int x = 1; int a = 2; int b = 3; int y = 4;     /* Buttons                    */
    int leftBumper = 5; int rightBumper = 6;        /* bumpers                    */
    int leftTrigger = 7; int rightTrigger = 8;      /* triggers                   */

    while (true)
    {
        servoChangeRate[armservo] = 2;              /* Slows the servo            */
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
        motor[arm]              = joystick.joy2_y1 * 100 / 128;

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
        | --------------------------------------------------------------------------
        | Arm servo control code (Likely to change)
        | --------------------------------------------------------------------------
        */
        if (joy2Btn(a) == 1) {
            servo[armservo] -= 20;
        } else if (joy2Btn(y) == 1) {
            servo[armservo] += 20;
        }

        /*
        | --------------------------------------------------------------------------
        | Pickup roller control code
        | --------------------------------------------------------------------------
        */
        if (joy2Btn(lt) == 1) {
            motor[flap1] = 100;
            motor[flap2] = 100;
        } else if (joy2Btn(rt) == 1) {
            motor[flap1] = -100;
            motor[flap2] = -100;
        } else {
            motor[flap1] = 0;
            motor[flap2] = 0;
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
