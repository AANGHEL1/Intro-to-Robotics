#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void helloWorld(int time)
{
	displayBigTextLine(1, "Hello World!");
	sleep(time*1000);
	eraseDisplay();
	sleep(time*1000);
}

task main()
{

	int i;
	int time = 5;
	for (i=0;i<5;i++)
	{

		helloWorld(time);
		time = time/2;
	}

	// 1 second is the minimum interval for a blink

}
