#include<Keypad.h>
#include<LiquidCrystal.h>
const int rs=A0,en=A1,d4=2,d5=3,d6=4,d7=5;
int a,b,c,d;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'o','0','=','+'}
};

byte rowPins[ROWS] = {13,12,11,10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9,8,7,6}; //connect to the column pinouts of the keypad
String var =  String('0');  
String var1= String('0');
char opt = '0';
int result = 0;
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  // put your setup code here, to run once:

}

void loop() {
 char key = keypad.getKey();// Read the key
 // Print if key pressed
   if (key)
   {
      lcd.print(key);
      if (key == '+' or key == '-' or key == '*' or key == '/') {
          opt = key;
      }else if(key == 'o')
      {
        lcd.clear();
        opt = '0' ;
        var =  String('0');  
        var1= String('0');
      }
      else if (key == '='){
          if (opt == '+') {
              result = var.toInt() + var1.toInt();
              lcd.clear();
              lcd.print('=');
              lcd.setCursor(1,0);
              lcd.print(result);
          } else if (opt == '-') {
              result = var.toInt() - var1.toInt();
              lcd.clear();
              lcd.print('=');
              lcd.setCursor(1,0);
              lcd.print(result);
          } else if (opt == '*') {
              result = var.toInt() * var1.toInt();
              lcd.clear();
              lcd.print('=');
              lcd.setCursor(1,0);
              lcd.print(result);
          } else if (opt == '/') {
              float result = var.toFloat() / var1.toFloat();
              lcd.clear();
              lcd.print('=');
              lcd.setCursor(1,0);
              lcd.print(result);
          }
      } else {
          if (opt == '0') {
              if (var.equals("0"))
              {
                  var = key;
              }
              else
              {
                  var = var + key;  
              }
          } 
          else
          {
              if (var1.equals("0"))
              {
                  var1 = key;
              }
              else
              {
                  var1 = var1 + key;
              }
          }
      }
   }      
}


  // put your main code here, to run repeatedly:
