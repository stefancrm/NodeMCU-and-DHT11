#include <Arduino.h>
#include "DHTesp.h"
#include "LittleFS.h"

DHTesp dht;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
  Serial.println( "NodeMCU DHT11 Weather station");
  dht.setup(2, DHTesp::DHT11); // data pin 2
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }
  File file = LittleFS.open("/test.txt", "r");
  if(!file){
    Serial.println("Failed to open file for reading");
    return;
  }
  
  Serial.println("File Content:");
  while(file.available()){
    Serial.write(file.read());
  }
  file.close();
}

void dht_serial() {
  delay(2000);

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  Serial.print(humidity, 1);
  Serial.print(" ");
  Serial.println("%");
  Serial.print(temperature, 1);
  Serial.print(" ");
  Serial.println("C");
}

  // put your main code here, to run repeatedly:
void loop(){
  dht_serial();
}

