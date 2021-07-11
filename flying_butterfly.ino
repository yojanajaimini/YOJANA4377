#include<LiquidCrystal.h>
const int rs=2,en=3,d4=4,d5=5,d6=6,d7=7;
int up= 1;
int starts =0;

int i=0;
int j=0;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

byte butterfly[8]{
  B000100,
  B010101,
  B001110,
  B010101,
  B001110,
  B000100,
  B001110,
  B010101
  };
  byte obs1[8]{
  B011111,
  B011111,
  B011111,
  B011111,
  B011111,
  B011111,
  B011111,
  B011111,
  
  };
void setup() {

  lcd.createChar(0,butterfly);
  lcd.begin(16,2);
  pinMode(up,INPUT_PULLUP);
  
  pinMode(starts,INPUT_PULLUP);

  // put your setup code here, to run once:

}

void loop() {
  if(digitalRead(starts)==LOW)
  {
    for(j=0;j<=15;j++)
    {
    lcd.setCursor(j,1);
    lcd.write(byte(0));
    delay(200);
    lcd.clear();
    if(digitalRead(up)==LOW)
    {
      lcd.setCursor(j,0);
      lcd.write(byte(0));
      delay(200);
    }
  }
    
       
      
    
  
   
  }

  
  // put your main code here, to run repeatedly:

}
