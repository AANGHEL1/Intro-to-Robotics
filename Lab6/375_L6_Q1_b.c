#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

string state = "idle";

int K = 1;
int target_angle = 270;
int curr = 0;
int des = 0;

int slewrate = 6;
int maxPower = 40;

task GyroSensorTask()
{
	resetGyro(S2);
	while(1)
	{
		int e = target_angle-getGyroDegrees(S2);
		des = K * e;
		if (des>maxPower)
		{
			des = maxPower;
		}

		if (des<=curr)
		{
			curr -= slewrate;
		}
		else
		{
			curr += slewrate;
		}
		sleep(50);
	}
}

task MotorTask()
{
	while(1)
	{
		while(curr != 0)
		{
			setMotorSync(motorB,motorC,100,curr);
		}
		sleep(20);
	}

}

task main()
{
	clearTimer(T1);
	clearDebugStream();
		while(1)
		{
			if (state == "idle")
			{
				startTask(MotorTask);
				startTask(GyroSensorTask);
				while(1)
				{
					writeDebugStreamLine("the curr is %d", curr);
					sleep(500);
					if(curr == 0)
						break;
				}
				state = "turn";
			}
			if (state == "turn")
			{

				displayTextLine(1, "Time taken to turn is %d", getTimerValue(T1));
				break;
			}
		}


}
