#include <dht.h>
#define dht_apin A0 
dht DHT;

int sensorValue;
void setup(){


  sensorValue = analogRead(1);      

  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
 digitalWrite(A4, HIGH); 
   digitalWrite(A5, LOW); 
}
void loop(){
    DHT.read11(dht_apin);
Serial.print("AirQua=");
Serial.print(sensorValue, DEC);             
Serial.println(" PPM");


    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
     digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
    delay(500);

    {
 if(DHT.temperature>27)
 {
 Serial.println("temp high");
 digitalWrite(11, HIGH); 
 }
  else
  {
   Serial.println("temp low");
 digitalWrite(11, LOW);
  }
}{
 if(DHT.humidity<18)
 {
 Serial.println("hum low ");
  digitalWrite(12, HIGH); 
 }
  else
  {
   Serial.println("hum high");
    digitalWrite(12, LOW);
  }
}
}




                                  
