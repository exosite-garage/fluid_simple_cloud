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
#include "cloud.h"

void setup() 
{
  pinMode(9, OUTPUT);  //set GPIO 9 to an output
}

void loop() 
{
  String retVal;

  //Send an analog input value to Exosite, use the alias (resource name) "1"
  sendToExosite("1",analogRead(A0));

  //Read the alias (resource name) "onoff" and set our GPIO based on its value
  if (readFromExosite("onoff", &retVal))
    digitalWrite(9, retVal.toInt());

    delay(3000);
}
