#include<LiquidCrystal.h>
const int rs=2,en=3,d4=4,d5=5,d6=6,d7=7;
int push_button = 8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
byte namastel[8]={
  B000011,
  B000011,
  B000011,
  B000011,
  B000011,
  B000111,
  B001110,
  B001100
   
  };
  byte namaster[8]={
  B011000,
  B011000,
  B011000,
  B011000,
  B011000,
  B011100,
  B001110,
  B000110
   
  };
  byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};
void setup() {
  pinMode(8,INPUT_PULLUP);
  lcd.createChar(0,namastel);
  lcd.createChar(1,namaster);
  lcd.createChar(2,smiley);
  lcd.begin(16,2);
  
  lcd.print("THIS IS NOTICE");
  lcd.setCursor(0,1);
  lcd.write(byte(0));
  lcd.setCursor(1,1);
  lcd.write(byte(1));
  lcd.setCursor(9,1);
  lcd.write(byte(2));
  // put your setup code here, to run once:

}
int j=0;
void loop() {

    if(digitalRead(8)==LOW)
    {
      if(j==0)
      {
        j=1;
        lcd.setCursor(3,1);
      
        lcd.print("YES HOLIDAY");
        delay(200);
      
   
      }
      else if (j==1)
      {
        j=0;
        lcd.setCursor(3,1);
        lcd.print("NO  HOLIDAY");
        delay(200);
      //lcd.clear();
      
        }
   
    
    
  }
    
    
  }
  
   
  
  /*if(digitalRead(8)==LOW)
  {
    if(j==0)
    {
      j=1;
      lcd.setCursor(3,1);
      lcd.print("today is holiday");
      
    }
    else if (j==1)
    {
      j=0;
      lcd.setCursor(3,1);
      lcd.print("today is not holiday");
      
    }
   
    
    
  }*/
  
  
  
  
 
  // put your main code here, to run repeatedly:
