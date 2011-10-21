#include <SPI.h>
#include <Ethernet.h>
#include "fluid_simple_cloud.h"

void setup() {
  pinMode(7, OUTPUT);  //set GPIO 7 to an output
}

void loop() {
  String retVal;
  
  //Send an analog input value to Exosite, use the alias (resource name) "1"
  sendToExosite(1,analogRead(A0));

  //Read the alias (resource name) "onoff" and set our GPIO based on its value
  if (readFromExosite("onoff", &retVal)) 
    digitalWrite(7, retVal.toInt());

  delay(3000);
}
