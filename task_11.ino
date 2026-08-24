// C++ code
//
int RED_LED = 2;
int YEL_LED = 1;
int GRE_LED = 0;

void setup()
{
  pinMode(RED_LED,OUTPUT);
  pinMode(YEL_LED,OUTPUT);
  pinMode(GRE_LED,OUTPUT);
}

void loop()
{
  digitalWrite(RED_LED,HIGH);
  digitalWrite(YEL_LED,LOW);
  digitalWrite(GRE_LED,LOW);
  delay(30000); 
  
  digitalWrite(RED_LED,LOW);
  digitalWrite(YEL_LED,HIGH);
  digitalWrite(GRE_LED,LOW);
  delay(6000);
  
  digitalWrite(RED_LED,LOW);
  digitalWrite(YEL_LED,LOW);
  digitalWrite(GRE_LED,HIGH);
  delay(30000);
  
  digitalWrite(RED_LED,LOW);
  digitalWrite(YEL_LED,HIGH);
  digitalWrite(GRE_LED,LOW);
  delay(6000);

}