u
int buttonPin = 2;    
int yellowLed = 3;   
int blueLed = 9;        

int buttonState = HIGH;   
int lastButtonState = HIGH;
int systemOn = 0;       

void setup() {
  
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    if (systemOn == 0) {
      systemOn = 1;
    } else {
      systemOn = 0;
    }
    delay(200);  
  }
  lastButtonState = buttonState;
  
 
  int sensorValue = analogRead(A0);
  
  if (systemOn == 1) {
   
    digitalWrite(yellowLed, HIGH);
    int brightness = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(blueLed, brightness);
  } else {
    digitalWrite(yellowLed, LOW);
    analogWrite(blueLed, 0);
  }
  
  delay(50);
}