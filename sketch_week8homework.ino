int switchPin = 2;
int ledPin = 13;

int buttonState = 0;
int lastButtonState = HIGH;
int ledState = LOW;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(switchPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);
    delay(200);
  }

  lastButtonState = buttonState;
}