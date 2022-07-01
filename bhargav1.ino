#include <SoftwareSerial.h>
#include <dht.h>
dht DHT;
#define FLAME A2
#define Watersprayer 10
#define Exhausterfan 13
#define DHT_11 A1

#define buz 9

void setup()
{
pinMode(FLAME,INPUT);
pinMode(Exhausterfan,OUTPUT);
Serial.begin(9600);
pinMode(buz,OUTPUT);
}
void loop()
{

  int statusSensor=digitalRead(FLAME);
  int sensorValue = analogRead(A0);
Serial.print("gas sensor output=");
Serial.print(sensorValue);
Serial.print("\n");
  delay(100);
  int check= DHT.read11(A1);
Serial.print("Temperature =");
Serial.println(DHT.temperature);
  int temp=DHT.temperature;
  delay(100);
  if(statusSensor>=100){
digitalWrite(10,HIGH);
digitalWrite(Watersprayer, HIGH);
Serial.print("there is a fire accident\n");
   delay(500);
    }
    else
  {
digitalWrite(10,LOW);
digitalWrite(Watersprayer, LOW);
Serial.print("there is no fire accident\n");
    delay(500);

   }
   if(sensorValue>=60){
digitalWrite(8,HIGH);
digitalWrite(Exhausterfan, HIGH);
Serial.print("There is a gas leak\n");
   }
   else{
digitalWrite(8,LOW);
digitalWrite(Exhausterfan, LOW);
    }
   if(temp>=20){

digitalWrite(buz,HIGH);
Serial.print("Temperature is high\n");
   }
   else
    {
digitalWrite(buz,LOW);
Serial.print("pleasent Temperature \n");

    }
Serial.print("\n");
Serial.print("\n");

  delay(3000);

}
