/*===============================================================================================================================================================================================
// Nom du fichier : Projet
// Auteur : Argan Piquet, Kenneth Aboue
// Date : 16 mars 2018
// Version : V2
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Description :
//==============================================================================================================================================================================================*/
void angle(short color)
{
	int anglecol = 0;

	if (color == 0)
	{
		setSoundVolume(10);
	  playTone(600, 30); while(bSoundActive) {}
		anglecol = 0*45;
		displayBigTextLine(4, "none");
		setMotorTarget(motorA,anglecol,45);
		waitUntilMotorStop(motorA);
		sleep(100);

	}

	if (color ==1 )
	{
		setSoundVolume(10);
	  playTone(700, 30); while(bSoundActive) {}
		anglecol = 1*45;
		displayBigTextLine(4, "black");
		setMotorTarget(motorA,anglecol,45);
		waitUntilMotorStop(motorA);
		sleep(100);
	}

	if (color == 2)
	{
		setSoundVolume(10);
	  playTone(800, 30); while(bSoundActive) {}
		anglecol = 2*45;
		displayBigTextLine(4, "blue");
		setMotorTarget(motorA,anglecol,45);
		waitUntilMotorStop(motorA);
		sleep(100);
	}

	if (color == 3)
	{
		setSoundVolume(10);
	  playTone(900, 30); while(bSoundActive) {}
		anglecol = 3*45;
		displayBigTextLine(4, "green");
		setMotorTarget(motorA,anglecol,45);
		waitUntilMotorStop(motorA);
		sleep(100);
	}

	if (color == 4)
	{
		setSoundVolume(10);
	  playTone(500, 30); while(bSoundActive) {}
		anglecol = 4*45;
		displayBigTextLine(4, "yellow");
		setMotorTarget(motorA,anglecol,45);
		waitUntilMotorStop(motorA);
		sleep(100);
	}

	if (color == 5)
	{
		setSoundVolume(10);
	  playTone(100, 30); while(bSoundActive) {}
		anglecol = 5*45;
		displayBigTextLine(4, "red");
		setMotorTarget(motorA,anglecol,45);
		waitUntilMotorStop(motorA);
		sleep(100);
	}

	if (color == 6)
	{
		setSoundVolume(10);
	  playTone(200, 30); while(bSoundActive) {}
		anglecol = 6*45;
		displayBigTextLine(4, "white");
		setMotorTarget(motorA,anglecol,45);
		waitUntilMotorStop(motorA);
		sleep(100);
	}

	if (color == 7)
	{
		setSoundVolume(10);
	  playTone(300, 30); while(bSoundActive) {}
		anglecol = 7*45;
		displayBigTextLine(4, "brown");
		setMotorTarget(motorA,anglecol,45);
		waitUntilMotorStop(motorA);
		sleep(100);
	}

	stopMotor(motorA);
}

task main()
{
	int marche=1;
	short currentColor;

	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Color; // Déclaration du capteur de couleur en sortie S2
	resetMotorEncoder(motorA);

	while (marche==1)
	{
		setMotorTarget(motorA,0,45);
		waitUntilMotorStop(motorA);

		if (SensorValue[S1] == 1)
		{
			currentColor = getColorName(S2);
			angle(currentColor);
		}

		sleep(100);
		setMotorTarget(motorA,0,45);
		waitUntilMotorStop(motorA);
			if (getButtonPress(buttonEnter) == 1) // Structure conditionnelle qui arrête l'algorithme
		{
			setSoundVolume(10);
			playTone(348, 30); while(bSoundActive) {} // Lors de l'arrêt, une musique est jouée
			playTone(261, 30); while(bSoundActive) {}
			drawEllipse(120, 120, 20, 20);
			displayCenteredBigTextLine(7, "Au revoir"); // Logo
			sleep(2000);
			marche=2;
		}
	}
}
