#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)  // SETUP of the robot
#pragma config(Sensor, S3,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C2_1,     frontLeft,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     backLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     frontRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     central,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     winch,         tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
#include "DriverCM.h" // Has the Methods\Driver for this code
// Code BEGINS

int maxDistance = 220; // When H drive is back make 230 XXX
int defaultSpeed = 50;
int slowDownSpeed;
bool hDriveWorking = false;

task main()
{
	//int irpos;
	motor[frontLeft]=defaultSpeed; //Makes it go forward
	motor[frontRight]=defaultSpeed;//Makes it go forward
	motor[backLeft]=defaultSpeed;//Makes it go forward
	motor[backRight]=defaultSpeed;//Makes it go forward
	nMotorEncoder [frontLeft] = 0;//Resets the Encoder
	while(SensorValue[IRSeeker] != 5 && unitsToCentimeters(nMotorEncoder[frontLeft])<maxDistance)//If  Ir seeker is NOT 5 do\ Below 230 CM
	{

		if(SensorValue[IRSeeker] > 0) // Slow down if it sees ir 
		{
			motor[frontLeft]=10;   //Slows it down
			motor[frontRight]=10;
			motor[backLeft]=10;
			motor[backRight]=10;
		}


		wait1Msec(50);	// So we don't spin through the loop infinitely fast.
	}
	nxtDisplayCenteredTextLine(3, "found"); // Displays If the IR is seen
	motor[frontLeft]=0;  //Sets The motors to 0, Which stops them
	motor[frontRight]=0;
	motor[backLeft]=0;
	motor[backRight]=0;
	wait1Msec(2000);  // Waits for 2 sec
	//PUT BUCKETCODE HERE XXX
	//Reads How far gone, then goes the rest of the way (300 CM)
	fourMotorcm(frontLeft,frontRight,backRight,backLeft,50,maxDistance-unitsToCentimeters(nMotorEncoder[frontLeft])); 
	if (hDriveWorking) {
		// H drive is working!
		runMotorWithEncoderByCm(central,-50,70); //Runs h drive to the right for 70 CM // MAKE SURE TO INCLUDE THIS XXXXX
		fourMotorcm(frontLeft,frontRight,backRight,backLeft,-50,85); // Goes backwards for 85 CM // MAKE SURE TO INCLUDE THIS XXXXX		
		} else {
		// H drive isn't working. Turn 90 degrees, drive forward, turn 90 degrees, drive onto ramp.

	}
}
// Code ENDS
