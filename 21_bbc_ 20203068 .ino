#include<Servo.h>

#define PIN_LED 9
#define PIN_SERVO 10
#define PIN_IR A0

#define _DIST_TARGET 255

#define _DUTY_NEU 1500
#define _DUTY_RIGHT 2000
#define _DUTY_LEFT 1000

#define INTERVAL 20
#define _INTERVAL_SERVO 20

Servo myservo;
float dist_raw;
unsigned long last_sampling_time;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);

  myservo.attach(PIN_SERVO); 
  myservo.writeMicroseconds(_DUTY_NEU);

  Serial.begin(57600);

  last_sampling_time = 0;

 }
   float ir_distance(void){ 
    float val; 
    float volt = float(analogRead(PIN_IR));
    val = ((6762.0/(volt - 9.0)) - 4.0) * 10.0; 
    return val; 
   }

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() < last_sampling_time + INTERVAL) return;

   float dist_raw = ir_distance();

   if (dist_raw < 255){
    myservo.writeMicroseconds(_DUTY_RIGHT);
   }
   else{
    myservo.writeMicroseconds(_DUTY_LEFT);
   }
   last_sampling_time += INTERVAL;
}
