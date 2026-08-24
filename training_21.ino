// C++ code
//
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop()
{
  digitalWrite(8,1);
  digitalWrite(13,0);
  delay(1000);
  
  tone(13,300,300);
  digitalWrite(8,0);
  digitalWrite(13,1);
  delay(1000);

}