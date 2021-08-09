/*

1. Connect the input pins of relay module (in this case 4 channel) with 3, 4, 5, and 6 digital pins of Arduino Uno
2. Provide 5V power supply in the Vin of Relay Module. 

*/

const int relay_1_pin = 3;
const int relay_2_pin = 4;
const int relay_3_pin = 5;
const int relay_4_pin = 6;



void setup() {

  pinMode(relay_1_pin, OUTPUT);
  pinMode(relay_2_pin, OUTPUT);
  pinMode(relay_3_pin, OUTPUT);
  pinMode(relay_4_pin, OUTPUT);


}

void loop() {
  
  digitalWrite(relay_1_pin, HIGH);
  digitalWrite(relay_2_pin, HIGH);
  digitalWrite(relay_3_pin, HIGH);
  digitalWrite(relay_4_pin, HIGH);
  delay(1000);

  digitalWrite(relay_1_pin, LOW);
  delay(1000);

  digitalWrite(relay_2_pin, LOW);
  delay(1000);

  digitalWrite(relay_3_pin, LOW);
  delay(1000);

  digitalWrite(relay_4_pin, LOW);
  delay(1000);  

}