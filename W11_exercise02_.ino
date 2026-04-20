

int ledPin = 9;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  // Blink LED to show wiring is correct
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    brightness = Serial.parseInt();
    if (Serial.read() == '\n') {
      brightness = constrain(brightness, 0, 255);
      analogWrite(ledPin, brightness);
    }
  }
}