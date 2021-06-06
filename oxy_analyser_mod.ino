// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
int sig = A0, led1= 16, led2 =15;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);  
int oxy = 0;

void setup() {
  // set up the LCD's number of columns and rows:
 
    pinMode(sig,INPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
  // Print a message to the LCD.
  Serial.begin(9600);
 
  Serial.print("Start");
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
}

void loop() {
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
  lcd.print(("DTR O2 Analyser"));
  analogReference(INTERNAL);
  int sensorValue = analogRead(sig);
    //float oxygen = (sensorValue) * 1.8;
  if ( sensorValue < 70)
  {
    lcd.setCursor(0,1);
  Serial.print(sensorValue);
  lcd.print(sensorValue);
  oxy = map(sensorValue,0,66,0,99);
  Serial.print(" ");
  lcd.setCursor(7, 1);
  Serial.println(oxy);
 Serial.print(" ");
  if (oxy < 100)
  { 
  lcd.print(oxy);
  lcd.print(("%"));
  }
  }

  delay(2000);
  if (( oxy> 0) && (oxy < 87))
  {
    digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);    
  }
if (oxy >= 85)
 {
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
 }
 //lcd.clear();
}
