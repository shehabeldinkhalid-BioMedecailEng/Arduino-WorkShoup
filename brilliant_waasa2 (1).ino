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
Left Arduino — Slave

The LED is connected to the left Arduino.

#include <SPI.h>

volatile byte receivedValue = 0;

const int LED_PIN = 7;

void setup() {
  pinMode(MISO, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Enable SPI Slave mode
  SPCR |= _BV(SPE);

  // Enable SPI interrupt
  SPCR |= _BV(SPIE);

  Serial.begin(9600);
}

ISR(SPI_STC_vect) {
  // Receive data from Master
  receivedValue = SPDR;
}

void loop() {

  // Turn LED on/off based on received value
  if (receivedValue > 127) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  Serial.print("Received: ");
  Serial.println(receivedValue);

  delay(100);
}