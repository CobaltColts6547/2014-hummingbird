#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          flap1,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          flap2,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     frontLeft,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     backLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     central,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     winch,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     arm,           tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    armservo,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
#include "DriverCM.h" // Has the Methods\Driver for this code
#include "JoystickDriver.c"
// Code BEGINS
int armPower = -20;
int servolevel = 0;
int maxDistance = 180; // When H drive is back make 230 XXX
int bin4 = 150;
int defaultSpeed = 30;
bool hDriveWorking = true;

void spit_old()
{
	servo[armservo] = servolevel+10;
	motor[flap1] = 100;
	motor[flap2] = 100;
	wait1Msec(1000);
	motor[flap1] = 0;
	motor[flap2] = 0;
	servo[armservo] = servolevel;
}

void spit()// drives in and drops the block
{

	// drives into the bins so we are closer for a better chance to drop the block
	motor[central] = -30;//turns the h-drive on
	wait1Msec(3000);//wait
	motor[central] =0;//turns the h-drive off
	servo[armservo] = 300;//lowers the arm to drop the block
	wait1Msec(2000);//wait
	servo[armservo] = servolevel;
	//shakes the arm to get the block in
	//wait1Msec(500); //wait
	//servo[armservo] = servolevel+60;//shakes the arm to get the block in
	//wait1Msec(500);//wait
	//servo[armservo] = servolevel;//shakes the arm to get the block in
	runMotorWithEncoderByCm(central,50,20); //Runs h drive to the right for 10 CM
}
/*
void ArmHold ()
{
if (nMotorEncoder[arm] < 250 && armPower > -80) {
armPower = armPower - 1;	// Lift up stronger.
}
if (nMotorEncoder[arm] > 250 && armPower < -80) {
armPower = armPower + 1;	// Lower the arm.
}

motor[arm] = armPower;
}
*/
task main()
{
	//nMotorEncoder[arm] = 0;
//	motor[winch] = 100;	// Change this to really move the winch XXXX

	//runMotorWithEncoder(arm,-80,250);
	//motor[arm] = -10;
	//int irpos
	nMotorEncoder [frontLeft] = 0;//Resets the Encoder
	motor[frontLeft]=defaultSpeed; //Makes it go forward
	motor[frontRight]=defaultSpeed;//Makes it go forward
	motor[backLeft]=defaultSpeed;//Makes it go forward
	motor[backRight]=defaultSpeed;//Makes it go forward
	while(SensorValue[ir] != 5 && unitsToCentimeters(nMotorEncoder[frontLeft])<bin4)//If  Ir seeker is NOT 5 do\ Below 230 CM
	{
		if(SensorValue[ir] > 0) // Slow down if it sees ir
		{
			motor[frontLeft]=25;   //Slows it down
			motor[frontRight]=25;
			motor[backLeft]=25;
			motor[backRight]=25;
		}

//		nxtDisplayCenteredTextLine(3, "%d", armPower);
		wait1Msec(200);	// So we don't spin through the loop infinitely fast.

	}
runFourMotorsWithEncoderByCmNoReset(frontLeft,frontRight,backRight,backLeft,50,4);
	nxtDisplayCenteredTextLine(3, "found"); // Displays If the IR is seen
	motor[frontLeft]=0;  //Sets The motors to 0, Which stops them
	motor[frontRight]=0;
	motor[backLeft]=0;
	motor[backRight]=0;
	spit();
//	wait1Msec(2000);  // Waits for 2 sec
	//PUT BUCKETCODE HERE XXX
	//Reads How far gone, then goes the rest of the way (300 CM)
	fourMotorcm(frontLeft,frontRight,backRight,backLeft,50,maxDistance-unitsToCentimeters(nMotorEncoder[frontLeft]));
	if (hDriveWorking) {
		// H drive is working!
		runMotorWithEncoderByCm(central,-50,110); //Runs h drive to the right for 70 CM // MAKE SURE TO INCLUDE THIS XXXXX
		fourMotorcm(frontLeft,frontRight,backRight,backLeft,-50,90); // Goes backwards for 85 CM // MAKE SURE TO INCLUDE THIS XXXXX
		} else {
		// H drive isn't working. Turn 90 degrees, drive forward, turn 90 degrees, drive onto ramp.
	}
	motor[winch]=0;

	runMotorWithEncoderByCm(central,20,10);  // scoot back against our ramp wall
	}
// Code ENDS








//Jake gets here late    {  :(   }
