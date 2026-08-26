#include <SPI.h>

const int SS_PIN = 10;

void setup() {
  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);

  SPI.begin();

  SPI.beginTransaction(
    SPISettings(1000000, MSBFIRST, SPI_MODE0)
  );

  Serial.begin(9600);
}

void loop() {

  // Read potentiometer
  byte potValue = analogRead(A0) / 4;  // 0–255

  // Select Slave
  digitalWrite(SS_PIN, LOW);

  // Send potentiometer value to Slave
  SPI.transfer(potValue);

  // Deselect Slave
  digitalWrite(SS_PIN, HIGH);

  Serial.print("Sent: ");
  Serial.println(potValue);

  delay(100);
}