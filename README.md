========================================
About fluid_simple_cloud
========================================
This project is a simple example of using a Fluid board to send and receive
data to/from the cloud by using Exosite's Cloud Data Platform.  This example does three things;
sends an analog value to the cloud, reads a control flag "onoff" to set a 
digital output, and sends the temperature sensor data to the cloud. 

Fluid is an Arduino-inspired development kit and reference 
design that combines an Arduino Uno, Ethernet Shield and low-cost wireless 
sensor interfaces into a single PCB. 

License is BSD, Copyright 2012, Exosite LLC (see LICENSE file)

Tested with Arduino 1.0.1

========================================
Quick Start
========================================
1) Download the Arduino toolchain and development environment

 * http://www.arduino.cc/en/Main/software

2) Download the Fluid Simple Cloud example project (this one)
 
 * https://github.com/exosite-garage/fluid_simple_cloud
 * HINT: click the ZIP icon near the top of the page

3) Download the Arduino Exosite Libary
 
 * https://github.com/exosite-garage/arduino_exosite_library
 * HINT: click the ZIP icon near the top of the page
  
4) Download the OneWire Library for Arduino 

 * http://www.pjrc.com/teensy/arduino_libraries/OneWire.zip
 
5) Download the Dallas Temperature Control Libary for Arduino 
  
 * http://download.milesburton.com/Arduino/MaximTemperature/DallasTemperature_372Beta.zip
 
6) Open up the Arduino IDE you just downloaded and click on "File->Preferences", confirm the default folder for the "Sketchbook location". Open your Sketchbook location folder, create a directory named "libraries" if it does not exist. 

7) Copy the Fluid Simple Cloud folder "exosite-garage-fluid_simple_cloud" to anywhere on your system. 

8) Copy the Arduino Exosite Library folder "exosite-garage-arduino_exosite_library" to the libraries folder you just created in the sketchbook location and rename it to "arduino_exosite_library". You should then see "File->Examples->arduino_exosite_library"

9) Copy the OneWire library folder "OneWire" to the directory sketchbook-location\"libraries". You should then see "File->Examples->OneWire"

10) Copy the Dallas Temperature Control library folder "dallas-temperature-control" to the directory sketchbook-location\"libraries" and rename it to "dallas_temperature_control". You should then see "File->Examples->dallas-temperature-control"

11) Run the Arduino IDE. Open the "fluid_simple_cloud.ino" file from the Arduino software.

12) Edit the "PUTYOURCIKHERE" value in fluid_simple_cloud.ino to match your CIK value

  * HINT: Obtain a CIK by signing up for a free account at https://portals.exosite.com. After activating your account, login and navigate to https://portals.exosite.com/manage/devices and click the +Add Device link

13) Edit the MAC address values in fluid_simple_cloud.ino if you have a valid MAC address, or you can just use the default value for testing purposes

14) In Portals (https://portals.exosite.com), add three Data Sources to match the data resources (aliases) the code is using. 

  * HINT: Go to https://portals.exosite.com/manage/data and click +Add Data Source

  * HINT: Ensure the "Alias:" values are set to "1", "temp", and "onoff" respectively to match the code

  * HINT: Add an "On/Off Switch" widget to your dashboard to control data source "onoff"

15) In the Arduino software, compile and verify there are no errors

16) Go to Tools->Serial Port and select the serial port your Fluid is connected to

  * Make sure the correct drivers are installed for your board. Follow http://arduino.cc/en/Guide/HomePage for detailed instructions.

17) Go to Tools->Board and choose "Duemilanove w/ ATmega328"

18) Go to File->Upload to I/O Board to upload the program

19) When "Done Uploading" is displayed, go to https://portals.exosite.com to see your data in the cloud!

  * HINT: Your Fluid board must be connected to the Internet via the RJ-45 ethernet jack

For more information on this project and other examples, check out our Exosite Garage github page at http://exosite-garage.github.com

========================================
Release Info
========================================

**Release 2012-06-08**
 - changed to use Arduino Exosite Library.
 - removed cloud.c and cloud.h (use Exosite Library).
 - updated Readme. 

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