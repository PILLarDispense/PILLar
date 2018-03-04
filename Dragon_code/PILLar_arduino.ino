/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
//int cont0 = 7;
//int cont1 = 8;
int val0;
int val1;
int delaytime;
int curr_pos = 0;

void turn90();
void setup() {
	myservo.attach(9);  // attaches the servo on pin 9 to the servo object
	//pinMode(cont0, INPUT);
	//pinMode(cont1, INPUT);
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
	Serial.begin(9600);
}

void loop() {
	int analog0 = analogRead(A0);
	int analog1 = analogRead(A1);

	if (analog0 > 300){
		val0 = 1;
	}else{
		val0 = 0;
	}
	if (analog1 > 300){
		val1 = 1;
	}else{
		val1 = 0;
	}
	pos = 90*(2*val0 + val1);
	while(pos % 360 != curr_pos % 360)
		turn90();
	
	
}

void turn90(){
	curr_pos = curr_pos + 90;
	myservo.write(75);
	delay(435);
	myservo.write(95);
	delay(1000);
}
