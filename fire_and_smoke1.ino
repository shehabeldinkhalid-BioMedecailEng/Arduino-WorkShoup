int gasSensor = A0;
int tempSensor = A1;

int redPin = 2;
int greenPin = 3;
int bluePin = 4;
int buzzer = 5;

void setup() { 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void setColor(int r, int g, int b) {
  digitalWrite(redPin, r );
  digitalWrite(greenPin, g );
  digitalWrite(bluePin, b );
}

void loop() {
  int gasValue = analogRead(gasSensor);
  int tempValue = analogRead(tempSensor);

  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;

  bool gasAlert = gasValue > 150;
  bool tempAlert = temperature > 35;

  if (!gasAlert && !tempAlert) {
    setColor(0, 1, 0); // أخضر
    noTone(buzzer);
  }
  else if (gasAlert && !tempAlert) {
    setColor(0, 0, 1); // أزرق
    tone(buzzer, 1000, 200);
  }
  else if (tempAlert && !gasAlert) {
    setColor(1, 0, 0); // أحمر
    tone(buzzer, 2000, 200);
  }
  else { // إنذار مشترك
    setColor(1, 0, 1); // بنفسجي
    tone(buzzer, 2500, 300);
  }

  delay(500);
}