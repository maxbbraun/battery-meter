#include <Arduino.h>
#include <Adafruit_INA219.h>
#include <Adafruit_NeoPixel.h>

Adafruit_INA219 ina219;
Adafruit_NeoPixel strip(1, D8, NEO_GRB);

uint32_t start_ms;

void setup() {
  Serial.begin(115200);

  // Watch for button presses.
  pinMode(A0, INPUT_PULLUP);

  // Initialize the LED.
  strip.begin();
  strip.setBrightness(1);

  // Initialize the power monitor.
  ina219.begin();
  ina219.setCalibration_16V_400mA();

  // Initialize the start time.
  start_ms = millis();
}

void loop() {
  // Check if the button is pressed.
  if (digitalRead(A0) == LOW) {
    // Reset the start time.
    start_ms = millis();

    // Print the header.
    Serial.printf("Time (ms), Current (mA)\n");

    // Show a red LED.
    strip.setPixelColor(0, 255, 0, 0);
  } else {
    // Show a green LED.
    strip.setPixelColor(0, 0, 255, 0);
  }
  strip.show();

  // Calculate the relative time.
  uint32_t time = millis() - start_ms;

  // Read the current draw.
  float current_ma = ina219.getCurrent_mA();

  // Print the data.
  Serial.printf("%d, %s\n", time, String(current_ma, 1).c_str());

  // Run at ~10 Hz.
  delay(100);
}
