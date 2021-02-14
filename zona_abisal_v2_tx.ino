#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  

SoftwareSerial BT(10,11);     // Seteo pines Tx (10) y Rx (11)

/****************************************************************************/
const int numReadings = 10;
int readIndex = 0;              // the index of the current reading

//SENSOR1
int readings1[numReadings];    // the readings from the analog input
int total1 = 0;                  // the running total
int average1 = 0;    // the average
int sensor1 = A0;

//SENSOR2
int readings2[numReadings];      // the readings from the analog input
int total2 = 0;                  // the running total
int average2 = 0;
int sensor2 = A1;

// SENSOR3
int readings3[numReadings];      // the readings from the analog input
int total3 = 0;                  // the running total
int average3 = 0;
int sensor3 = A2;

//SENSOR4
int readings4[numReadings];      // the readings from the analog input
int total4 = 0;                  // the running total
int average4 = 0;
int sensor4 = A3;

void setup() {
  Serial.begin(9600);   // Inicializamos  el puerto serie de la compu
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings1[thisReading] = 0;
    readings2[thisReading] = 0;
    readings3[thisReading] = 0;
    readings4[thisReading] = 0;
  }
}

void loop() {

  //SENSOR 1
  total1 = total1 - readings1[readIndex];
  readings1[readIndex] = analogRead(sensor1);
  total1 = total1 + readings1[readIndex];
  readIndex = readIndex + 1;

  //SENSOR2
  total2 = total2 - readings2[readIndex];
  readings2[readIndex] = analogRead(sensor2);
  total2 = total2 + readings2[readIndex];
  readIndex = readIndex + 1;

  //SENSOR3
  total3 = total3 - readings3[readIndex];
  readings3[readIndex] = analogRead(sensor3);
  total3 = total3 + readings3[readIndex];
  readIndex = readIndex + 1;

  //SENSOR4
  total4 = total4 - readings4[readIndex];
  readings4[readIndex] = analogRead(sensor4);
  total4 = total4 + readings4[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  average1 = total1 / numReadings;
  average2 = total2 / numReadings;
  average3 = total3 / numReadings;
  average4 = total4 / numReadings;

  BT.print(average1);
  BT.print(" ");
  BT.print(average2);
  BT.print(" ");
  BT.print(average3);
  BT.print(" ");
  BT.println(average4);

  Serial.print(average1);
  Serial.print(" ");
  Serial.print(average2);
  Serial.print(" ");
  Serial.print(average3);
  Serial.print(" ");
  Serial.println(average4);

}
