#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


int K = 1;
int target_angle = 0;
int motorspeed = 0;

task GyroSensorTask()
{
	resetGyro(S2);
	while(1)
	{
		int e = target_angle-getGyroDegrees(S2);
		motorspeed = K * e;
		sleep(50);
	}
}

task MotorTask()
{
	while(1)
	{
		while(motorspeed > 2)
		{
			//setMotorSpeed(leftMotor,motorspeed);
			//setMotorSpeed(rightMotor,-motorspeed);
			setMotorSync(motorB,motorC,100,motorspeed);
		}
		if(motorspeed<=2)
		{
			setMotorSync(motorB,motorC,100,0);
			motorspeed = 0;
		}
		sleep(20);
	}

}




task main()
{
	clearDebugStream();
	target_angle = 45;
	startTask(MotorTask);
	startTask(GyroSensorTask);

	while(1)
	{
		writeDebugStreamLine("the motorspeed is %d", motorspeed);
		sleep(1000);
	}


}
