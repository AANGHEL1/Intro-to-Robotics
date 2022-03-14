#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

string state = "idle";

void turnPoint(int time)
{
	setMotorSync(leftMotor,rightMotor,100,20);
	sleep(time);
}


task main()
{
	clearTimer(T1);
	clearDebugStream();
		while(1)
		{
			if (state == "idle")
			{
				turnPoint(3600);
				state = "turn";
			}
			if (state == "turn")
			{

				displayTextLine(1, "Time taken to turn is %d", getTimerValue(T1));
				break;
			}
		}


}
