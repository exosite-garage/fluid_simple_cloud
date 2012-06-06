========================================
About fluid_simple_cloud
========================================
This project is a simple example of using a Fluid board to send and receive
data to/from the cloud by using Exosite's Cloud Data Platform.  This example 
sends an analog value to the cloud and reads a control flag "onoff" to set a 
digital output. 

Fluid is an Arduino-inspired development kit and reference 
design that combines an Arduino Uno, Ethernet Shield and low-cost wireless 
sensor interfaces into a single PCB. 

License is BSD, Copyright 2012, Exosite LLC (see LICENSE file)

Tested with Arduino 1.01

========================================
Quick Start
========================================
1) Download the Arduino toolchain and development environment

 * http://www.arduino.cc/en/Main/software

2) Open the "fluid_simple_cloud.ino" file from the Arduino software

3) Edit the "PUTYOURCIKHERE" value in cloud.cpp to match your CIK value

  * HINT: Obtain a CIK by signing up for a free account at https://portals.exosite.com. After activating your account, login and navigate to https://portals.exosite.com/manage/devices and click the +Add Device link

4) Edit the MAC address values in cloud.cpp if you have a valid MAC address, or you can just use the default value for testing purposes

5) In Portals (https://portals.exosite.com), add three Data Sources to match the data resources (aliases) the code is using

  * HINT: Go to https://portals.exosite.com/manage/data and click +Add Data Source

  * HINT: Ensure the "Resource:" values are set to "1" and "onoff" respectively to match the code

  * HINT: Add an "On/Off Switch" widget to your dashboard to control data source "onoff"

6) In the Arduino software, compile and verify there are no errors

7) Go to Tools->Serial Port and select the serial port your Fluid is connected to

8) Go to File->Upload to I/O Board to upload the program

9) When "Done Uploading" is displayed, go to https://portals.exosite.com to see your data in the cloud!

  * HINT: Your Fluid board must be connected to the Internet via the RJ-45 ethernet jack

For more information on this project and other examples, check out our Exosite Garage github page at http://exosite-garage.github.com

========================================
Release Info
========================================

**Release 2012-06-05**
 - changed file extension to .ino for Arduino 1.01 
 - supported new Ethernet library of Arduino 1.01
 - obtained IP from DHCP
 - used DNS to get server IP
 - changed sendToExosite API prototype

**Release 2012-01-13**
 - increased array size for read routine
 - fixed array overwrite in read routine
 - removed un-initialized serial port messages

**Release 2011-10-21**
 - initial version
