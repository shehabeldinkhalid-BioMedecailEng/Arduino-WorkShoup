/*
int X[18];
void setup()
{
  Serial.begin(9600);
  int i = 0 ;
  for(;;){
    if(i<=17)
    {
      X[i]=random(70,101);
      i++;
    }
    else
    {
      break;
    }
  }
  i = 0 ;
  for(;;){
    if(i<=17)
    {
      Serial.println(X[i]);
      i++;
    }
    else
    {
      break;
    }
  }
  int Max=max(X[0],X[1]);
  for(int i = 2;i<18;i++)
  {
    Max = max(Max,X[i]);
  }
  Serial.print("The Max :");
  Serial.println(Max);
  int Min=min(X[0],X[1]);
  for(int i = 2;i<18;i++)
  {
    Min = min(Min,X[i]);
  }
  Serial.print("The Min :");
  Serial.println(Min);
}

void loop()
{
}*/
// Calipration
int RED = 11;
int Green = 4;
int Blue = 5;
int signal = A5;
int Ton = 2;
int Avarg;
int Max;
int Min;
void Tone()
{
    tone(Ton,Max,100);
    delay(200);
    noTone(Ton);
    delay(100);
    tone(Ton,Min,100);
    delay(200);
    noTone(Ton);
    delay(100);
}
void TurnOffAll()
{
  digitalWrite(RED,LOW);
  digitalWrite(Blue,LOW);
  digitalWrite(Green,LOW);

}
void setup()
{
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
  pinMode(signal,INPUT);
  pinMode(Ton,OUTPUT);
  tone(Ton,300,100);
  delay(1000);
  while(millis()<10000)
  {
    Max = max(Max,analogRead(signal));
    Min = min(Min,analogRead(signal));
    Tone();
  }
  tone(Ton,300,100);
  Avarg = (Max+Min)/2;
  Serial.print("Max:");Serial.println(Max);
  Serial.print("Min:");Serial.println(Min);
  Serial.print("Avarg:");Serial.println(Avarg);
}
void loop()
{
  int color = map(analogRead(signal),Min,Max,0,500);
  if(color <= 200)
  {
   TurnOffAll();
   digitalWrite(RED,HIGH);
  }
  else if(color > 200 && color <= 350)
  {
   TurnOffAll();
   digitalWrite(Green,HIGH);
  }
  else
  {
    TurnOffAll();
    digitalWrite(Blue,HIGH);
  }
}
