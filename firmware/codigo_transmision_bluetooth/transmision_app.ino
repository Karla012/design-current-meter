#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

unsigned long lastChange = 0;          // Last state change time
const unsigned long changeInterval = 10000; // 10-second interval
const unsigned long sendInterval = 500;     // 500 ms interval

bool currentHIGH = false;    // false = 10 µA, true = 80 mA
unsigned long lastSend = 0;  // Last data transmission time

void setup() {
  SerialBT.begin("CurrentMeter"); // Initialize Bluetooth with device name
}

void loop() {
  // Toggle currentHIGH state every 10 seconds
  if (millis() - lastChange >= changeInterval) {
    lastChange = millis();
    currentHIGH = !currentHIGH;  // Invert the state
  }

  // Send message every 500 ms
  if (millis() - lastSend >= sendInterval) {
    lastSend = millis();
    String message = currentHIGH ? "80.00 mA" : "10.00 µA";
    SerialBT.println(message);  // Transmit via Bluetooth
  }
}

