#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int i = 1;
	for (i=1;i<=8;i++)
	{
		displayTextLine(i,"%d squared is %d", i, i*i);
	}
	sleep(10000);
	eraseDisplay();

}
