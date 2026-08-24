// C++ code
//
void Blink(int pin,int Am,int amo){
  int i = 0;
  while(i<=amo)
  {
    digitalWrite(pin,HIGH);
    delay(Am);
    digitalWrite(pin,LOW); 
    i++;
  }
}

void setup()
{
  pinMode(8, OUTPUT);
}

void loop()
{
  Blink(8,1000,1);
  Blink(8,500,3);
  Blink(8,100,5);
}