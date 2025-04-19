#include <Wire.h>
#include <BluetoothSerial.h>
#include <SparkFun_ADS122C04_ADC_Arduino_Library.h>

BluetoothSerial SerialBT;
SFE_ADS122C04 adc;

const int rangePin = 25;                   // Range selection pin
const float amplifierGain = 1000.0;        // Pre-ADC gain
unsigned long lastMillis = 0;
const unsigned long interval = 500;        // Reading interval in ms

void setup() {
  SerialBT.begin("CurrentMeter");         // Visible Bluetooth name
  Wire.begin();

  pinMode(rangePin, INPUT);               // Configure pin as input for range selection

  if (!adc.begin()) {
    Serial.println("Error: ADC not detected.");
    while (1);
  }
  adc.configureADCmode(ADS122C04_RAW_MODE); // Configure ADC(auto mode, internal reference)
}

void loop() {
  if (millis() - lastMillis >= interval) {
    lastMillis = millis();

    bool highRange = digitalRead(rangePin);          // HIGH = 10 mΩ, LOW = 10 Ω
    float amplifiedVoltage = adc.readVoltage();      // Direct ADC reading in volts
    float shuntVoltage = amplifiedVoltage/amplifierGain;

    float current = 0.0;
    String unit;

    if (highRange) {
      current = shuntVoltage / 0.01;                // 10 mΩ → 0.01 Ω
      current *= 1000.0;                           // Convert A to mA
      unit = "mA";
    } else {
      current = shuntVoltage / 10.0;                // 10 Ω
      current *= 1000000.0;                         // Convert A to µA
      unit = "uA";
    }
    String message = String(current, 2) + " " + unit;
    SerialBT.println(message);
  }
}
