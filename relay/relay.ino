#define RELAY1 14
#define RELAY2 15
#define RELAY3 16
#define RELAY4 17

#define DELAY 3000

void setup() {
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(RELAY1, LOW);
  delay(DELAY);
  digitalWrite(RELAY1, HIGH);
  delay(DELAY);

  /* digitalWrite(RELAY2, LOW); */
  /* delay(DELAY); */
  /* digitalWrite(RELAY2, HIGH); */
  /* delay(DELAY); */

  /* digitalWrite(RELAY3, LOW); */
  /* delay(DELAY); */
  /* digitalWrite(RELAY3, HIGH); */
  /* delay(DELAY); */

  /* digitalWrite(RELAY4, LOW); */
  /* delay(DELAY); */
  /* digitalWrite(RELAY4, HIGH); */
  /* delay(DELAY); */

  Serial.println("Iterating...");
}
