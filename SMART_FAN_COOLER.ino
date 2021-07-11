#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
const int sensor=A1; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
lcd.begin(16,2);  
  delay(500);
}
void loop() 
{
  if(tempc>=93)
{
  analogWrite(8,255);
}
else if(tempc<93)
{
  analogWrite(8,150);
}
else if(tempc<=0)
{
  analogWrite(8,0);
}

vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit 
lcd.setCursor(0,0);
lcd.print("in DegreeC= ");
lcd.print(tempc);
lcd.setCursor(0,1);
lcd.print("in Fahrenheit=");
lcd.print(tempf);
delay(1000); //Delay of 1 second for ease of viewing in serial monitor
}
