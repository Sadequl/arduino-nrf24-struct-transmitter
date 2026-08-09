/*
  nRF24L01 Struct Transmitter
  ---------------------------
  Sends multiple variables in one structured payload.

  Wiring for Arduino Uno / ATmega328P Pro Mini:
    CE   -> D5
    CSN  -> D6
    SCK  -> D13
    MOSI -> D11
    MISO -> D12
    VCC  -> 3.3 V
    GND  -> GND

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

  radio.openWritingPipe(address);
  radio.stopListening();
}

void loop() {
  // Example values. Replace these with real sensor readings.
  data.batteryLevel = 85;
  data.occupancy = 1;

  bool delivered = radio.write(&data, sizeof(data));

  Serial.print("Battery: ");
  Serial.print(data.batteryLevel);
  Serial.print("% | Occupancy: ");
  Serial.print(data.occupancy);
  Serial.print(" | Status: ");
  Serial.println(delivered ? "ACK received" : "No ACK");

  delay(1000);
}
