
int REDPIN = 3;
int GREENPIN = 5;
int BLUEPIN = 6;

#define FADESPEED 2
#define TIME_STEP 0.001

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void setColor(int red, int green, int blue) {
  analogWrite(REDPIN, red);
  analogWrite(GREENPIN, green);
  analogWrite(BLUEPIN, blue);
}

int cubic(float p0, float p1, float t) {
  float position = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * p0 + (-2 * pow(t, 3) + 3 * pow(t, 2)) * p1;
  return round(position);
}

int red = random(255);
int green = random(255);
int blue = random(255);
void loop() {
  int nextRed = random(255);
  int nextGreen = random(255);
  int nextBlue = random(255);
  for (float time = 0.0; time < 1.0; time += TIME_STEP) {
    setColor(cubic(red, nextRed, time),
             cubic(green, nextGreen, time),
             cubic(blue, nextBlue, time));
    delay(FADESPEED);
  }
  red = nextRed;
  blue = nextBlue;
  green = nextGreen;
}
