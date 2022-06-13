#include <Wire.h>
#define READ_LENGTH 4
#define wet 500
#define dry 750

byte buf[4];

int n=0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void receiveEvent(int bytes) {

 for( int i = 0; i<n; i++)
  {
   buf[i] = Wire.read();
  }

  if(buf[0]==LOW){
    Serial.println("There's water on sensor");
  }else{
    Serial.println("There's not water on sensor");
  }

  Serial.print("Air humidity: ");
  Serial.println(buf[1]);
  

  Serial.print("Temperature: ");
  Serial.println(buf[2]);
  

if(buf[3]==0){
    Serial.println("Ground is wet");
  }else if(buf[3]==1){
    Serial.println("Ground is in the mid humidity condition");
  }else{
    Serial.println("Ground is dry");
  }
  Serial.println("");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  n=Wire.requestFrom(2,4);
  
  for( int i = 0; i<n; i++)
  {
   buf[i] = Wire.read();
  }
 delay(4000);
  
}
