//*****************************************************************************
//
// fluid_simple_cloud.ino - Main application function
//
// Copyright (c) 2012 Exosite LLC.  All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

//  * Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of Exosite LLC nor the names of its contributors may
//    be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
//*****************************************************************************
#include <SPI.h>
#include <Ethernet.h>
#include <Exosite.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Fill in your MAC address and CIK 
byte macData[] = { 0x90, 0xA2, 0xDA, 0x00, 0x11, 0x22}; // <-- Fill in your MAC here! (You can find it on the bottom of Ethernet Shield)

String cikData = "PUTYOURCIKHERE";      // <-- Fill in your CIK here! (https://portals.exosite.com -> Add Device)

// local Macros
#define ONE_WIRE_BUS 6

// global
Exosite exosite(&Ethernet, macData, cikData);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

/*==============================================================================
* setup
*
* Arduino setup function.
*=============================================================================*/
void setup() 
{
  exosite.init();
  pinMode(9, OUTPUT);  //set GPIO 9 to an output
}

/*==============================================================================
* loop
*
* Arduino loop function.
*=============================================================================*/
void loop() 
{
  String retVal;

  //Send an analog input value to Exosite, use the alias (resource name) "1"
  exosite.sendToCloud("1", analogRead(A0));

  //Read temperature from the Dallas sensor and send the data to the Exosite. use the alias "temp"
  sensors.requestTemperatures();
  exosite.sendToCloud("temp", sensors.getTempCByIndex(0));

  //Read the alias (resource name) "onoff" and set our GPIO based on its value
  if (exosite.readFromCloud("onoff", &retVal))
    digitalWrite(9, retVal.toInt());

  delay(3000);
}
