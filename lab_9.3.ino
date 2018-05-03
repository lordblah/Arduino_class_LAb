/*
Arduino with PIR motion senser
*/

int led = 13; //The pin that the LED is attached tp
int sensor = 2; //The pin that the sensor is ateched to
int state = LOW; //by default, no motion detected
int val = 0; //variable to store the sensor status

void setup() 
{
pinMode(led, OUTPUT);
pinMode(snesor, INPUT);
Serial.begin(9600);
}

void loop()
{
	val = digitalRead(sensor);
	if(val == HIGH)
	{
		digitalWrite(led, HIGH);
		delay(100);
		
		if(state ==LOW)
		{
			Serial.println("Motion detected");
			state = HIGH; 
		}
	}
	else
	{
		digitalWrite(led, LOW);
		delay(200);
		
		if(state == HIGH){
			Serial.println("Motion stopped!");
			state = LOW;
		}
	}
}
