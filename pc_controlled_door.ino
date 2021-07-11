#include<Servo.h>
Servo door;
int pos =0;
void setup() {
  Serial.begin(9600);
  door.attach(9);
  Serial.println("Enter password");
  // put your setup code here, to run once:

}

void loop() {
  
  if(Serial.available())
  {
    int data = Serial.read();
    Serial.write(data);
    delay(100);
    if(data==8)
    {
      for (pos = 0; pos <= 180; pos += 1) 
      {
        door.write(pos);              // tell servo to go to position in variable 'pos'
        delay(2000);                       // waits 15ms for the servo to reach the position
      }
      for (pos = 180; pos >= 0; pos -= 1) 
      { // goes from 180 degrees to 0 degrees
        door.write(pos);              // tell servo to go to position in variable 'pos'
        delay(2000);                       // waits 15ms for the servo to reach the position
      }
    }
    else
    {
      Serial.println("your password is Wrong try again");
    }
    
  }
  // put your main code here, to run repeatedly:

}
