# Arduino nRF24L01 Struct Transmitter

Send multiple values between two Arduino boards using an nRF24L01 radio and a C/C++ `struct`.

This example includes both a transmitter and receiver, so it can be tested as a complete standalone project.

## What this project demonstrates

- nRF24L01 wireless communication
- Sending multiple values in one payload
- C/C++ structures
- Matching data structures on transmitter and receiver
- RF24 transmit and receive modes

## Hardware

Two Arduino Uno/Nano/Pro Mini boards and two nRF24L01 modules.

## nRF24L01 wiring

The sketches use:

```cpp
RF24 radio(5, 6); // CE, CSN
```

| nRF24L01 | Arduino Uno / Pro Mini |
|---|---|
| VCC | 3.3 V |
| GND | GND |
| CE | D5 |
| CSN | D6 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |
| IRQ | Not used |

**Do not power a standard nRF24L01 module from 5 V.**

## Library

Install the **RF24** library.

## Payload

```cpp
struct DataPackage {
  int batteryLevel;
  int occupancy;
};
```

The total nRF24L01 payload must remain within its payload limit.

## Run

1. Upload `receiver/receiver.ino` to one Arduino.
2. Upload `transmitter/transmitter.ino` to the other.
3. Open both Serial Monitors at 115200 baud.
4. The transmitter sends example values once per second.

## Reuse ideas

Replace the example values with:

- Temperature and humidity
- Occupancy and battery level
- Light and motion data
- Equipment status
- Multiple environmental sensor readings

## License

MIT License.
