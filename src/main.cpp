#include <Arduino.h>
#include "DHTesp.h"

DHTesp dht;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);
  Serial.println( "NodeMCU DHT11 Weather station");
  dht.setup(2, DHTesp::DHT11); // data pin 2
}


  // put your main code here, to run repeatedly:
void loop(){
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

