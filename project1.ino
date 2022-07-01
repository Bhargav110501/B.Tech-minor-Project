#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include<Wire.h>
const char * myWriteAPIKey = "ODEYJAMUAY5NBTGZ";
unsigned long myChannelNumber =  1626307; 
const char* ssid = "bhargav";
const char* password = "bharagav1105";
const int flame = D0;
const int buzz = D1;
double gas;
const int led = D2 ;
const int exhaust =D6;
#define Gas_Pin A0
#define DHTPIN D4 
DHT dht(DHTPIN, DHT11,15);
WiFiClient client;
void setup() {
Serial.begin(9600);
pinMode(flame, INPUT);
pinMode(buzz,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D2,OUTPUT);
dht.begin();
ThingSpeak.begin(client);
WiFi.begin(ssid, password);

pinMode(Gas_Pin,INPUT);
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

Serial.println("");
Serial.println("WiFi connected");
}

void loop() 
{
 float t = dht.readTemperature();
ThingSpeak.writeField(myChannelNumber, 3,t, myWriteAPIKey);
Serial.print("Temp = ");
Serial.println(t);
delay(1000);

float k = analogRead(A0);
Serial.print("gas sensor value:");
Serial.print(k);
Serial.print("\n");
delay(1000);
ThingSpeak.writeField(myChannelNumber, 1,k, myWriteAPIKey );
float p = digitalRead(D0);
if(k>=20){
  digitalWrite(D6,HIGH);
  Serial.print("there is gas leak\n");
  
  
}
 else{
  digitalWrite(D6,LOW);
  Serial.print("there is no gas leak\n");
 }
 Serial.print("flame sensor value:");
 Serial.print(p);
 Serial.print("\n");
 
 ThingSpeak.writeField(myChannelNumber, 2,p, myWriteAPIKey );
if(p==1    )  
    
  {
  digitalWrite(D1,HIGH);
  Serial.print("fire accident\n");
  
  }
else
{
  digitalWrite(D1,LOW);
    
 }

if (t >=30)
{
  digitalWrite(D2,HIGH);
 
  Serial.print("temperature is high");
 
   
 
 }
else
   {
  digitalWrite(D2,LOW);
   Serial.print("temperature is pleasent");
   }
   Serial.print("\n");
   Serial.print("\n");
   
   if ( isnan(t)|| isnan(gas)) {
   Serial.println("Failed to read from DHT sensor!");
   }
}
