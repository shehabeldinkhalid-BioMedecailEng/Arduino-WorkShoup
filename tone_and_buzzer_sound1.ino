int bezo = 9;
int buttons[] = {2, 3, 4, 5, 6, 7}; 
int tones[] = {262, 294, 330, 349, 392, 440};
void setup() {
  pinMode(bezo, OUTPUT);
  for (int i = 0; i < 6; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 6; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      tone(bezo, tones[i], 300);
    }
  }
}
