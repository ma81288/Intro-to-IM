const int trigPin = 9;
const int echoPin = 10;
const int blueButton = 2;
const int redButton = 3;
const int speakerPin = 8;

int lastBlueButtonState = HIGH;
int lastRedButtonState = HIGH;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(redButton, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int blueButtonState = digitalRead(blueButton);
  int redButtonState = digitalRead(redButton);

  // Blue button 
  if (blueButtonState == LOW && lastBlueButtonState == HIGH) {
    tone(speakerPin, 150, 100);
  }

  // Red button
  if (redButtonState == LOW && lastRedButtonState == HIGH) {
    tone(speakerPin, 400, 80);
  }

  lastBlueButtonState = blueButtonState;
  lastRedButtonState = redButtonState;


  if (blueButtonState == HIGH && redButtonState == HIGH) {
    
    // ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // echo time
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    
    Serial.println(distance);

    if (distance > 5 && distance < 50) {
      int pitch = map(distance, 5, 50, 1500, 200);
      pitch = constrain(pitch, 200, 1500);
      tone(speakerPin, pitch);
    } else {
      noTone(speakerPin);
    }
  }
}
