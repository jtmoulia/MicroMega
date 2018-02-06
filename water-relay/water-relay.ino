const int relayOutPin = A0;
const int waterInPin = A4;
const int loopDelay = 3000;
const int waterSensorCutoff = 600;

void setup() {
  pinMode(relayOutPin, OUTPUT);
  pinMode(waterInPin, INPUT);
  digitalWrite(relayOutPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int waterValue = analogRead(waterInPin);
  Serial.print("Water Sensor = ");
  Serial.print(waterValue * 100 / 1024);
  Serial.print("% ");
  Serial.print(waterValue);
  Serial.println();

  if (waterValue < waterSensorCutoff) {
    digitalWrite(relayOutPin, LOW);
  } else {
    digitalWrite(relayOutPin, HIGH);
  }

  delay(loopDelay);
}
