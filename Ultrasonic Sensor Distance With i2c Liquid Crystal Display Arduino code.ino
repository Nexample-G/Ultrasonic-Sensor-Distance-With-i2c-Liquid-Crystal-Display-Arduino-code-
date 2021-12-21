#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
  const int trig = 9;
  const int echo = 10;
  long DRN;
  int DsCm, DsIn;
void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.init();
  lcd.backlight();
}
void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  DRN = pulseIn(echo, HIGH);
  DsIn = DRN*0.0133/2;
  DsCm= DRN*0.034/2;

  lcd.setCursor(0,0);
  lcd.print("DISTANCE: ");
  lcd.print(DsIn);
  lcd.print(",");
  lcd.print(DsCm);
  lcd.setCursor(0,1);
  lcd.print("INCH CENTIMETER");
}