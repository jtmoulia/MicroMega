// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define REDPIN 3
#define GREENPIN 5
#define BLUEPIN 6

#define FADESPEED 1     // make this higher to slow down

void setup() {
  Serial.begin(9600);
  // randomSeed(analogRead(0));
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}


float createDelta(float accuracy = 1000000, float amplitude = 0.1) {
  return (random(-accuracy, accuracy) / accuracy) * amplitude;
}

float clamp(float val, float minimum, float maximum) {
  if (val < minimum) {
    return minimum;
  } else if (val > maximum) {
    return maximum;
  }
  return val;
}

float createDelta2() {
  return random(-10, 10);
}

float c_r = 128, c_g = 128, c_b = 128;
float r = c_r, g = c_g, b = c_b;
float v_r = 0, v_g = 0, v_b = 0;
float a_r = 0, a_g = 0, a_b = 0;
float f_r = 0, f_g = 0, f_b = 0;

float mass = 5;
float spring_k = 0.01;
float f_max = 2;
float v_max = 1;

void loop() {
  f_r = clamp(f_r + createDelta(), -f_max, f_max);
  f_g = clamp(f_g + createDelta(), -f_max, f_max);
  f_b = clamp(f_b + createDelta(), -f_max, f_max);

  float a_r = ((c_r - r) * spring_k + f_r) / mass;
  float a_g = ((c_g - g) * spring_k + f_g) / mass;
  float a_b = ((c_b - b) * spring_k + f_b) / mass;

  v_r = clamp(v_r + a_r, -v_max, v_max);
  v_g = clamp(v_g + a_b, -v_max, v_max);
  v_b = clamp(v_b + a_g, -v_max, v_max);

  r = clamp(r + v_r, 0, 255);
  g = clamp(g + v_g, 0, 255);
  b = clamp(b + v_b, 0, 255);

  analogWrite(REDPIN, r);
  analogWrite(GREENPIN, g);
  analogWrite(BLUEPIN, b);
  delay(FADESPEED);
}
