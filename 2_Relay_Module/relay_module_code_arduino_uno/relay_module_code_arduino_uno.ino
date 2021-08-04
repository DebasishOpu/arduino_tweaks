/*

1. Connect the output pin of sensor with A0 pin of Arduino Uno
2. Provide 5V power supply. 

*/


const int current_sensor_1 = A0;


void setup() {
  Serial.begin(9600); 
  pinMode(current_sensor_1, INPUT); 

}

void loop() {

  current_read(current_sensor_1);
  Serial.println("______________________________________________");

}


void current_read(int sensor_pin) {
  double current_reading = 0.00;
  float result = 0.0;
  float meanResult = 0.0;
  double VRMS = 0;


  int readValue = 0;
  int maxValue = 0;
  int minValue = 1024;

  for (int i = 0; i < 1; i++) { //taking single time for elimininting initial beep
    uint32_t start_time = millis();
    //sample for 1 Sec
    while ((millis() - start_time) < 1000) {
      readValue = analogRead(sensor_pin);
      if (readValue > maxValue) {
        maxValue = readValue;
      }
      if (readValue < minValue) {
        minValue = readValue;
      }
    }

    result = ((maxValue - minValue) * 5.0) / 1024.0; //Peak to Peak

    meanResult += result;

  }

  result = meanResult / 1;


  VRMS = (result / 2.0) * 0.707;
  current_reading = ((VRMS * 1000) / 66) - 2.84   ; //Ratiometric value for 30A Model

  if (current_reading <= 0) {
    current_reading = 0;
  }


  Serial.print("current_reading: ");
  Serial.print(current_reading);
  Serial.println(" A");


}