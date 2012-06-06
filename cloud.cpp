//*****************************************************************************
//
// cloud.cpp - Exosite cloud API
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
#include <Ethernet.h>
#include "cloud.h"


#define CIK "PUTYOURCIKHERE"        // <-- Fill in your CIK here! (https://portals.exosite.com -> Add Device)

byte mac[] = { "PUTYOURMACHERE"  }; // <-- Fill in your MAC here! (e.g. {0x90, 0xA2, 0xDA, 0x00, 0x22, 0x33}) 


// Global variabele
  char serverName[] = "m2.exosite.com";
  EthernetClient client; // Port 80 is default for HTTP
  static char enetInitDone = 0;
  char rxdata[150];
  String myDataString;
  int ret;
  int stringPos;
  boolean DataRx;
  boolean RxLoop;
  char c;
  unsigned long timeout_time;
  unsigned long time_now;
  unsigned long timeout; 

/*==============================================================================
* sendToExosite
*
* Send data to cloud
*=============================================================================*/
int sendToExosite(String res, int value)
{
  ret = 0;
  stringPos = 0;
  DataRx= false;
  RxLoop = true;
  timeout_time = 0;
  time_now = 0;
  timeout = 3000; // 3 seconds
  myDataString = ""; //allocate for actual data sent
  
  if (!enetInitDone) {
    Ethernet.begin(mac);
    delay(500);
    enetInitDone = 1;
  }
  
  if (client.connect(serverName,80)) {
    if (client.connected()) {
      myDataString += res;
      myDataString += "="; //put into resource
      myDataString += value; //just send the value
      // Send request using Exosite basic HTTP API
      client.println("POST /api:v1/stack/alias HTTP/1.1");
      client.println("Host: m2.exosite.com");
      client.print("X-Exosite-CIK: "); 
      client.println(CIK);
      client.println("Content-Type: application/x-www-form-urlencoded; charset=utf-8");
      client.println("Accept: application/xhtml+xml");
      client.print("Content-Length: ");
      client.println(myDataString.length()); //calculate length
      client.println();
      client.println(myDataString);

      // Read from the nic
      //
      timeout_time = millis()+ timeout;

      while ((timeout_time > time_now) && RxLoop) {
        if (client.available()) {
          if (!DataRx)
            DataRx = true;

          c = client.read();
          rxdata[stringPos] = c;

          stringPos += 1;

        } else {
          rxdata[stringPos] = 0;

          if (DataRx) {
            DataRx= false;
            RxLoop = false;

            ret=1;
          }
        }//else
        time_now = millis();
      }// while ((timeout_time > time_now) && RxLoop) {
      client.stop();
    }
  }
  return ret;
}

/*==============================================================================
* readFromExosite
*
* Read data from cloud
*=============================================================================*/
int readFromExosite(String res ,String* pResult)
{

  ret = 0;
  stringPos = 0;
  DataRx= false;
  RxLoop = true;
  timeout_time = 0;
  time_now = 0;
  timeout = 3000; // 3 seconds
  
  if (!enetInitDone) {
    Ethernet.begin(mac);
    delay(500);
    enetInitDone = 1;
  }
  
  if (client.connect(serverName,80)) {
    if (client.connected()) {
      // Send request using Exosite basic HTTP API
      client.print("GET /api:v1/stack/alias?");
      client.print(res);
      client.println(" HTTP/1.1");
      client.println("Host: m2.exosite.com");
      client.print("X-Exosite-CIK: "); 
      client.println(CIK);
      client.println("Accept: application/x-www-form-urlencoded; charset=utf-8");
      client.println();

      // Read from the nic 
      timeout_time = millis()+ timeout;

      while ((timeout_time > time_now) && RxLoop) {
        if (client.available()) {
          if (!DataRx)
            DataRx = true;
          
          c = client.read();
          rxdata[stringPos] = c;
          
          stringPos += 1;
        } else {
          rxdata[stringPos] = 0;
          if (DataRx) {
            DataRx = false;
            RxLoop = false;
            String rxstrg = String(rxdata);
            int length = 0;
            int rxresultpos = 0;
            int subStringLength = 0;
            if (rxstrg.startsWith("HTTP/1.1 200 OK")) {
              length = rxstrg.length();
              rxresultpos=rxstrg.indexOf('=');
              subStringLength = length - rxresultpos;
              *pResult= String(rxstrg.substring(rxresultpos+1));
            } else {
              rxresultpos=rxstrg.indexOf('\n');
              subStringLength = rxresultpos;
              *pResult= String(rxstrg.substring(0,rxresultpos));
            }  
            ret=1;
          }
        }
        time_now = millis();
      }
      client.stop();
    }
  }
  return ret;
}
