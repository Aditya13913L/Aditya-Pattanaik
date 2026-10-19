#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

const int buttonPin = 2;
const int buzzerPin = 8;
const int LED_PIN = 13;

int visitors = 0;
int buttonState = HIGH;
int lastReading = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

const int notes[] = {300, 400, 500};
const unsigned long noteDurations[] = {250, 350, 250};
const int totalNotes = 3;
int noteIndex = 0;
bool melodyPlaying = false;
unsigned long noteStartTime = 0;

void updateDisplay() {
  lcd_1.setCursor(0, 0);
  lcd_1.print("DIGITAL DOORBELL");
  lcd_1.setCursor(0, 1);
  lcd_1.print("VISITORS:       ");
  lcd_1.setCursor(10, 1);
  lcd_1.print(visitors);
}

void startDoorbell() {
  melodyPlaying = true;
  noteIndex = 0;
  digitalWrite(LED_PIN, HIGH);
  tone(buzzerPin, notes[noteIndex]);
  noteStartTime = millis();
}

void updateDoorbell() {
  if (!melodyPlaying) return;

  if (millis() - noteStartTime >= noteDurations[noteIndex]) {
    noteIndex++;
    if (noteIndex >= totalNotes) {
      noTone(buzzerPin);
      digitalWrite(LED_PIN, LOW);
      melodyPlaying = false;
    } else {
      tone(buzzerPin, notes[noteIndex]);
      noteStartTime = millis();
    }
  }
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  noTone(buzzerPin);

  Serial.begin(9600);
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
  updateDisplay();

  Serial.println("Digital Doorbell System Ready!");
  Serial.println("Visitor Count: 0");
}

void loop() {
  updateDoorbell();

  int reading = digitalRead(buttonPin);
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime >= debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        visitors++;
        Serial.print("Doorbell Pressed! Visitor Count: ");
        Serial.println(visitors);
        updateDisplay();

        if (!melodyPlaying) startDoorbell();
      }
    }
  }
  lastReading = reading;
}
