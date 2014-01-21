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

/*
| ----------------------------------------------------------------------------------
| Motor and sensor setup. motorK does not exist at the moment and likely will not.
| Only one servo is being used.
| You cannot include this file with the standard #include
| Instead, just copy and paste the code.
| ----------------------------------------------------------------------------------
*/
