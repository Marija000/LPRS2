#include <Wire.h>
#include <dht.h>
#define DHT11PIN 2
#define sensorPower 7
#define groundePin A0
#define wet 500
#define dry 750

const int rain_d=4;
dht DHT;
const int grounde_a=0;


byte buffer[4];

int readSensor(){
  digitalWrite(sensorPower,HIGH);
  delay(10);
  int val=analogRead(groundePin);
  digitalWrite(sensorPower,LOW);
  return val;
}


void setup() {
  // put your setup code here, to run once:
  pinMode(rain_d,INPUT);
  Wire.begin(2);
  pinMode(sensorPower,OUTPUT);
  digitalWrite(sensorPower,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
 
  buffer[0]=digitalRead(rain_d);
  buffer[1]=DHT.humidity;
  buffer[2]=DHT.temperature;

  if(readSensor()<wet){
     buffer[3]=0x0;
  }else if(readSensor()>wet && readSensor()<dry){
    buffer[3]=0x1;
  }else{
    buffer[3]=0x2;
  }
  
  Wire.beginTransmission(8);
  Wire.write(buffer,4);
  Wire.endTransmission();


  //KISA
  if(digitalRead(rain_d)==LOW){
    Serial.println("There's water on sensor");
  }else{
    Serial.println("There's not water on sensor");
  }
  delay(1000);

  //TEMPERATURA I VLAZNOST

  int chk=DHT.read11(DHT11PIN);
  Serial.print("Air humidity: ");
  Serial.println(DHT.humidity);
  delay(1000);

  Serial.print("Temperature: ");
  Serial.println(DHT.temperature);
  delay(1000);

  //VLAZNOST ZEMLJISTA

  Serial.print("Ground humidity, analog read: ");
  Serial.println(readSensor());
  delay(1000);

  if(readSensor()<wet){
    Serial.println("Ground is wet");
  }else if(readSensor()>wet && readSensor()<dry){
    Serial.println("Ground is in the mid humidity condition");
  }else{
    Serial.println("Ground is dry");
  }
  

 delay(8000);
 Serial.println("");
 

}
