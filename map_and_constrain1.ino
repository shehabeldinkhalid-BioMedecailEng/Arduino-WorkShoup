int Pizo = 11;
int Signal = A0;

int sig;
int Freq;
float G_1;

void setup() {
  Serial.begin(9600); // لمتابعة القيم
  pinMode(Pizo,OUTPUT);
  pinMode(Signal,INPUT);
  Serial.println("Input your Grade");
  while(Serial.available()== 0){}
  G_1 = Serial.parseInt();
  G_1 = map(G_1*100,0,400,0,500);
  Serial.print("Your New Grade Is:");
  Serial.println(G_1/100);
}

void loop() {
  // قراءة الأنالوج
  sig = analogRead(Signal);

  // تحويل القيمة لتردد بين 100Hz و 2000Hz (مش 0, علشان البازر يشتغل كويس)
  Freq = map(sig, 350, 1023, 0, 2000);
  Freq = constrain(Freq,0,2000);
  // تشغيل البازر
  tone(Pizo, Freq,1000);

  // طباعة Debug
  Serial.print("Signal: ");
  Serial.print(sig);
  Serial.print(" | Freq: ");
  Serial.println(Freq);

  delay(500); // زمن تحديث مناسب
  noTone(Pizo);
  delay(500);
}
