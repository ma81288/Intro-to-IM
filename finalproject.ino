
const int motifBtn = 2;
const int paletteBtn = 3;
const int bgBtn = 4;
const int lineBtn = 5;
const int centerBtn = 6;
const int finishBtn = 7;

bool lastMotif = HIGH;
bool lastPalette = HIGH;
bool lastBg = HIGH;
bool lastLine = HIGH;
bool lastCenter = HIGH;
bool lastFinish = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(motifBtn, INPUT_PULLUP);
  pinMode(paletteBtn, INPUT_PULLUP);
  pinMode(bgBtn, INPUT_PULLUP);
  pinMode(lineBtn, INPUT_PULLUP);
  pinMode(centerBtn, INPUT_PULLUP);
  pinMode(finishBtn, INPUT_PULLUP);
}

void loop() {
  bool motifState = digitalRead(motifBtn);
  bool paletteState = digitalRead(paletteBtn);
  bool bgState = digitalRead(bgBtn);
  bool lineState = digitalRead(lineBtn);
  bool centerState = digitalRead(centerBtn);
  bool finishState = digitalRead(finishBtn);

  if (motifState == LOW && lastMotif == HIGH) Serial.println("motif");
  if (paletteState == LOW && lastPalette == HIGH) Serial.println("palette");
  if (bgState == LOW && lastBg == HIGH) Serial.println("background");
  if (lineState == LOW && lastLine == HIGH) Serial.println("line");
  if (centerState == LOW && lastCenter == HIGH) Serial.println("center");
  if (finishState == LOW && lastFinish == HIGH) Serial.println("finish");

  lastMotif = motifState;
  lastPalette = paletteState;
  lastBg = bgState;
  lastLine = lineState;
  lastCenter = centerState;
  lastFinish = finishState;

  delay(50);
}