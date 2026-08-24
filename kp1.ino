#include <Keypad.h>
#
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//7Segment
const int pinA = 12;
const int pinB = 13;
const int pinC = 2;
const int pinD = 1;
const int pinE = 0;
const int pinF = 11;
const int pinG = 10;
// Map segments (a to g) for numbers 0-9
// 1 = ON, 0 = OFF (For Common Cathode)
const byte numData[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0  
  {0, 1, 1, 0, 0, 0, 0}, // 1   
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};
char hexadisplay[ROWS][COLS] = {
  {1,2,3},
  {4,5,6},
  {7,8,9},
};
// Function to light up the correct segments
void displayDigit(int digit) {
  digitalWrite(pinA, numData[digit][0]);
  digitalWrite(pinB, numData[digit][1]);
  digitalWrite(pinC, numData[digit][2]);
  digitalWrite(pinD, numData[digit][3]);
  digitalWrite(pinE, numData[digit][4]);
  digitalWrite(pinF, numData[digit][5]);
  digitalWrite(pinG, numData[digit][6]);
}

void setup(){
  Serial.begin(9600);
  // Set all segment pins as OUTPUT
  const int ListPin[7]={pinA,pinB,pinC,pinD,pinE,pinF,pinG};
  for(int p=0;p<7;p++){
    pinMode(ListPin[p], OUTPUT);
  }
}
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    for(int k=0;k<3;k++){
      for(int j=0;j<3;j++){
        if(customKey==hexaKeys[k][j])
        {
          displayDigit(hexadisplay[k][j]);
          delay(100);
        }
      }
    }   
  }
}