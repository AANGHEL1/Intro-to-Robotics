#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int prevRightMotorEncoder = 0;
int rightMotorEncoder = 0;
float wheelAngleChanged = 0;
float currentHeading = 0;
float x = 0;
float y = 0;

int degrees = 1800/176.0 * 360;

task forwardTask()
{
	while(1)
	{
		//setMotorSync(leftMotor,rightMotor,0,20);
		//setMotorTarget(leftMotor,degrees,20);
		//setMotorTarget(rightMotor,degrees,20);
		setMotorSyncEncoder(rightMotor,leftMotor,100,1800,20);
		sleep(20);

	}
}

task PositionTrack()
{
	while(1)
	{
		prevRightMotorEncoder = rightMotorEncoder;
		rightMotorEncoder = getMotorEncoder(motorC);
		wheelAngleChanged = (rightMotorEncoder - prevRightMotorEncoder)*0.01745;
		currentHeading = (-1 * getGyroHeading(S2))* 0.01745;
		x = x+ 28* wheelAngleChanged* cos(currentHeading);
		y = y+ 28* wheelAngleChanged* sin(currentHeading);
		sleep(50);
	}
}

task display()
{
	while(1)
	{
		displayTextLine(1,"Coordinates:");
		displayTextLine(2,"(%.2f, %.2f, %.2f)", x, y, currentHeading);
		writeDebugStreamLine("Coordinates: (%f, %f, %f)", x, y, currentHeading);
		sleep(10);
	}
}



task main()
{
	startTask(PositionTrack);
	resetMotorEncoder(rightMotor);
	resetMotorEncoder(leftMotor);

	startTask(forwardTask);
	//setMotorSyncEncoder(rightMotor,leftMotor,100,1800,20);
	setMotorSync(leftMotor,rightMotor,-100,20);

	while(1)
	{

		startTask(display);

		sleep(50);
	}

}