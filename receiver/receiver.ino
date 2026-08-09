/*
  nRF24L01 Struct Receiver
  ------------------------
  Receives the DataPackage sent by transmitter.ino.

  Author: Mohammad Sadequl Islam
  License: MIT
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(5, 6);  // CE, CSN
const byte address[6] = "00031";

struct DataPackage {
  int batteryLevel;
  int occupancy;
};

DataPackage data;

void setup() {
  Serial.begin(115200);

  if (!radio.begin()) {
    Serial.println("RF24 hardware not responding.");
    while (true) {}
  }

  radio.openReadingPipe(1, address);
  radio.startListening();

  Serial.println("Receiver ready.");
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(data));

    Serial.print("Battery: ");
    Serial.print(data.batteryLevel);
    Serial.print("% | Occupancy: ");
    Serial.println(data.occupancy);
  }
}
