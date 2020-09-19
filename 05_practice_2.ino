#define PIN_LED 13

unsigned int count, toggle, LED = 7; 


void setup() {

  pinMode(PIN_LED, OUTPUT);
  pinMode(LED, OUTPUT);
  

  Serial.begin(115200); // Initialize serial port

  while (!Serial) {

    ; // wait for serial port to connect.

  }

  Serial.println("Hello World!");

  count = toggle = 0;

  digitalWrite(PIN_LED, toggle); // turn off LED.

}


void loop() {
 
  Serial.println(++count);

  toggle = toggle_state(toggle); //toggle LED value.

  digitalWrite(PIN_LED, toggle); // update LED status.

  delay(1000);// wait for 1,000 milliseconds

  digitalWrite(LED, HIGH);
  delay(1000);
  for (int i = 0; i <5; i++){
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
    digitalWrite(LED, HIGH);
    
  }
  
  while(1) {}
}


int toggle_state(int toggle) {
  
  if (toggle == LOW){
    digitalWrite(PIN_LED, HIGH);
    
  }
  else{
    digitalWrite(PIN_LED, LOW) ;
    
  }
    delay(1000);
      

}
