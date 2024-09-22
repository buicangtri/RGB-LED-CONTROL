#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height, in pixels
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// OLED reset pin (set to -1 if sharing Arduino reset pin)
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Define analog pins for the potentiometers (A0-A3 on Nano)
const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;
const int potPin4 = A3;

// Define PWM-capable digital pins for the LEDs (D3, D5, D6, D9 on Nano)
const int redLedPin = 9;
const int greenLedPin = 5;
const int blueLedPin = 6;
const int whiteLedPin = 3;

void setup() {
  // Initialize LED pins as OUTPUT
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(whiteLedPin, OUTPUT);

  // Initialize the serial monitor for debugging
  Serial.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
}

void loop() {
  // Read potentiometer values (0-1023)
  int potValue1 = analogRead(potPin1);
  int potValue2 = analogRead(potPin2);
  int potValue3 = analogRead(potPin3);
  int potValue4 = analogRead(potPin4);

  // Convert potentiometer values to percentages (0-100)
  int redBrightnessPercent = map(potValue1, 0, 1023, 0, 100);
  int greenBrightnessPercent = map(potValue2, 0, 1023, 0, 100);
  int blueBrightnessPercent = map(potValue3, 0, 1023, 0, 100);
  int whiteBrightnessPercent = map(potValue4, 0, 1023, 0, 100);

  // Convert percentages to PWM values (0-255)
  int redPWM = map(redBrightnessPercent, 0, 100, 0, 255);
  int greenPWM = map(greenBrightnessPercent, 0, 100, 0, 255);
  int bluePWM = map(blueBrightnessPercent, 0, 100, 0, 255);
  int whitePWM = map(whiteBrightnessPercent, 0, 100, 0, 255);

  // Apply the PWM values to control the LED brightness
  analogWrite(redLedPin, redPWM);
  analogWrite(greenLedPin, greenPWM);
  analogWrite(blueLedPin, bluePWM);
  analogWrite(whiteLedPin, whitePWM);

  // Clear the display
  display.clearDisplay();

  // Set text size and color for OLED display
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Display the percentage of each LED color
  display.setCursor(0, 0);
  display.print("Red: ");
  display.print(redBrightnessPercent);
  display.println("%");

  display.setCursor(0, 16);
  display.print("Green: ");
  display.print(greenBrightnessPercent);
  display.println("%");

  display.setCursor(0, 32);
  display.print("Blue: ");
  display.print(blueBrightnessPercent);
  display.println("%");

  display.setCursor(0, 48);
  display.print("White: ");
  display.print(whiteBrightnessPercent);
  display.println("%");

  // Update the OLED display with new content
  display.display();

  // Optional: Short delay to avoid overwhelming the serial monitor and OLED
  delay(100);
}
