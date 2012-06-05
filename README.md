========================================
About fluid_simple_cloud
========================================
This project is an simple example of using a Fluid board to send and receive
data to/from the cloud by using Exosite's Cloud Data Platform.  This example 
sends an analog value to the cloud and reads a control flag "onoff" to set a 
digital output. Fluid is an Arduino-inspired development kit and reference 
design that combines an Ardunio Uno, Ethernet Sheild and low-cost wireless 
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

  * HINT: Obtain a CIK from https://portals.exosite.com by clicking +Add Device

4) Edit the mac address values in cloud.cpp if you have valid set of mac addres, or you can just use the default value for testing.

5) In Portals (https://portals.exosite.com), add three DataSources to match the data resources (aliases) the code is using.

  * HINT: Goto https://portals.exosite.com/manage/data and click +Add Data Source

  * HINT: Ensure the "Resource:" values are set to "1" and "onoff" respectively to match the code

  * HINT: Add an "on off switch" Widget to your dashboard to control data source "onff"

6) In the Arduino software, compile and verify there are no errors

7) Go to Tools->Serial Port and select the serial port your Fluid is connected to

8) Go to File->Upload to I/O Board to upload the program

9) When "Done uploading" is displayed, go to https://portals.exosite.com to see your data in the cloud!

  * HINT: Your Fluid board must be connected to the Internet via the RJ-45 ethernet jack

For more information on this project and other examples, checkout our Exosite Garage github page at http://exosite-garage.github.com

========================================
Release Info
========================================

**Release 2012-06-05**
 - change file extension to .ino for Arduino 1.01 
 - support new Ethernet library  of Arduino 1.01
 - obtain IP from DHCP.
 - use DNS to get server IP.
 - change sendToExosite API prototype.
 - 

**Release 2012-01-13**
 - increased array size for read routine
 - fixed array overwrite in read routine
 - removed un-initialized serial port messages

**Release 2011-10-21**
 - initial version
