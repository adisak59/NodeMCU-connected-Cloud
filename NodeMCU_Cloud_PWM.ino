#include <Servo.h>
#define LED_PIN D1            // LED at D1
#define SERVO_PIN D2            // Servo at D2
#define ANALOG_PIN A0
Servo myservo;
int analogValue = 0;        // Variable for store analog value


void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);       // set serial port at 115200 bps


  myservo.attach(SERVO_PIN);
} // Setup

void loop()
{
  analogValue = analogRead(ANALOG_PIN);   // Read analog input at pin An 0.
  analogWrite(LED_PIN, analogValue);

  analogValue = map(analogValue,0,1023,110,151);
  myservo.write(analogValue);
  
  Serial.print("analogValue = ");       // Send string to serial port.
  Serial.println(analogValue);            // Send analog value to serial port.
  delay(300);                            // Delay 0.3 second.
}// Loop


