// C++ code
int SW = 8;
int LED = 13;
int D1 =100;
int D2 =3000;
void blink(int D)
{
  digitalWrite(LED, HIGH);
  delay(D); // Wait for 1000 millisecond(s)
  digitalWrite(LED, LOW);
  delay(D); // Wait for 1000 millisecond(s) 
}
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
}

void loop()
{
  int D = D2;
  
  if(digitalRead(SW)== 0)
    D = D1;
  
  blink(D);
}