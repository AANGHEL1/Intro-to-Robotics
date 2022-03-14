#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//



void moveStraight(int time)
{
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);
	sleep(time);
}

task main()
{
	//4000ms is needed to move 1m
	//200ms is needed to move 5cm
	//this time, the robot executes precisely for 15,50,95 and 150 cm
	moveStraight(4000);
}