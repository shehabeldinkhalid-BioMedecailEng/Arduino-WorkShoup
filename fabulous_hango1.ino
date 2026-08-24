int Y = A0;
int sw = 2;
int X = A1;

float x_pos = 0;
float y_pos = 0;

void setup() {
  int Arr[9] = {3,4,5,6,7,8,9,10,11};

  for(int i = 3; i <= 11; i++){
    pinMode(i, OUTPUT);
  }

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(sw, INPUT_PULLUP);

  Serial.begin(9600);
} 

int x = 0;
int y = 0;

void loop() {
  Serial.print("Z = ");
  Serial.println(digitalRead(sw));

  Serial.print("X = ");
  x = analogRead(X); 
  Serial.println(x);

  Serial.print("Y = ");
  y = analogRead(Y);
  Serial.println(y);

  x_pos = (x / 1023.0) * 20 - 10;
  y_pos = (y / 1023.0) * 20 - 10;

  Serial.print("X_pos = ");
  Serial.println(x_pos);

  Serial.print("Y_pos = ");
  Serial.println(y_pos);
}