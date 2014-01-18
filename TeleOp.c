#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          flap1,         tmotorNXT, PIDControl, reversed, encoder)
#pragma config(Motor,  motorB,          flap2,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     frontleft,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     backleft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     frontright,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     backright,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     central,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     winch,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     arm,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    armservo,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
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
