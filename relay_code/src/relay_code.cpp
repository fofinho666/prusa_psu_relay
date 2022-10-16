#include <Arduino.h>

#define ON true
#define OFF false

const int RELAY_PIN = 10;
const int LED_PIN = 9;
const int BUTTON_PIN = 8;

bool state = OFF;
bool new_state = state;
bool button_state = LOW;
bool button_read = button_state;

String incoming_string = "";

const unsigned long debounce_delay = 50;
unsigned long last_debounce_time = 0;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  SerialUSB.begin(9600);
}

void loop() {
  // Serial read
  if (SerialUSB.available() > 0) {
    incoming_string = SerialUSB.readStringUntil('\n');

    if (incoming_string.equals("off")) {
      new_state = OFF;
    } else if (incoming_string.equals("on")) {
      new_state = ON;
    }
  }

  // Button read
  button_read = (bool)digitalRead(BUTTON_PIN);

  if ((millis() - last_debounce_time) > debounce_delay) {
    last_debounce_time = millis();

    if (button_read != button_state) {
      button_state = button_read;

      if (button_read == HIGH) {
        new_state = !state;
      }
    }
  }

  // Relay state
  if (new_state != state) {
    state = new_state;

    if (new_state == OFF) {
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
    } else {
      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
    }
  }
}
