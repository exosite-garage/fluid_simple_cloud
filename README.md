========================================
About fluid_simple_cloud
========================================
This project is an simple example of using a Fluid board to send and receive
data to/from the cloud by using Exosite's Cloud Data Platform.  This example 
sends an analog value to the cloud and reads a control flag "onoff" to set a 
digital output. Fluid is an Arduino-inspired development kit and reference 
design that combines an Ardunio Uno, Ethernet Sheild and low-cost wireless 
sensor interfaces into a single PCB. 

License is BSD, Copyright 2011, Exosite LLC (see LICENSE file)

Tested with Arduino 0022

========================================
Quick Start
========================================
1) Download the Arduino toolchain and development environment<br>
* http://www.arduino.cc/en/Main/software<br>

2) Open the "fluid_simple_cloud.pde" file from the Arduino software<br>

3) Edit the "PUTYOURCIKHERE" value in arduino_http_post.h to match your CIK value<br>
* HINT: Obtain a CIK from https://portals.exosite.com by clicking +Add Device<br>

4) Edit the network values in arduino_http_post.h to match your network setup<br>
* e.g. ip, gateway, subnet<br>

5) In Portals (https://portals.exosite.com), add three DataSources to match the 
data resources (aliases) the code is using.<br>
* HINT: Goto https://portals.exosite.com/manage/data and click +Add Data Source<br>
* HINT: Ensure the "Resource:" values are set to "1", "2" and "onoff" respectively 
to match the code<br>
* HINT: Add an "on off switch" Widget to your dashboard to control data source "onff"<br>

6) In the Arduino software, compile and verify there are no errors<br>

7) Go to Tools->Serial Port and select the serial port your Fluid is connected to<br>

8) Go to File->Upload to I/O Board to upload the program<br>

9) After "Done uploading" is displayed, go to https://portals.exosite.com to see
your data in the cloud!<br>
* HINT: Your Fluid must be connected to the Internet via the RJ-45 ethernet jack<br>

For more information on this project and other examples, checkout our Exosite
Garage github page at http://exosite-garage.github.com<br>

========================================
Release Info
========================================
----------------------------------------
Release 2012-01-13<br>
----------------------------------------
--) increased array size for read routine<br>
--) fixed array overwrite in read routine<br>
--) removed un-initialized serial port messages<br>

----------------------------------------
Release 2011-10-21<br>
----------------------------------------
--) initial version<br>
