#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int distance = 0;
int pos_y = 0;
int theta = 0;
int count = 0;

void getPos_Y()
{
	distance = 176 * (getMotorEncoder(leftMotor)/360);
	if (count%2 == 0)
		distance = -distance;
	writeDebugStreamLine("Distance is %d", distance);
	pos_y += distance;
	//if (distance>=900)
		//resetMotorEncoder(leftMotor);
	writeDebugStreamLine("The position is: (0, %d, %d)", pos_y,theta);
	displayTextLine(1, "The position is: (0, %d, %d)", pos_y,theta);
}

void getTheta()
{
	theta = getGyroDegrees(S2);
	if (theta>=357)
	{
		theta = 0;
		resetGyro(S2);
	}
	writeDebugStreamLine("The position is: (0, %d, %d)", pos_y,theta);
	displayTextLine(1, "The position is: (0, %d, %d)", pos_y,theta);
}

void robotWalk()
{
	//Walk
		resetMotorEncoder(leftMotor);
		count++;
		setMotorSync(leftMotor,rightMotor,0,50);
		sleep(4050);
		getPos_Y();
		eraseDisplay();
		//Turn
		setMotorSync(leftMotor,rightMotor,100,20);
		getTheta();
		sleep(1850);
		eraseDisplay();
		//Walk
		resetMotorEncoder(leftMotor);
		count++;
		setMotorSync(leftMotor,rightMotor,0,50);
		sleep(4050);
		getPos_Y();
		eraseDisplay();
		//Turn
		setMotorSync(leftMotor,rightMotor,100,20);
		getTheta();
		sleep(1850);
		eraseDisplay();
}

task main()
{
	clearDebugStream();
	displayTextLine(6,"Start of the Program");
	sleep(500);

	for (int i=0;i<5;i++)
	{
		robotWalk();
	}

	displayTextLine(6,"End of the Program");
	sleep(500);

}
