#define CIK "PUTYOURCIKHERE"                         // <-- FILL IN YOUR DEVICE CIK HERE (https://portals.exosite.com -> Add Device)!
byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x25, 0xF1 }; // <-- IF DEPLOYING INTO THE WILD, FILL IN A VALID MAC HERE!
byte ip[] = { 192, 168, 0, 77 };                     // <-- FILL IN YOUR DEVICE IP ADDRESS HERE!
byte gateway[] = { 192, 168, 0, 1 };                 // <-- FILL IN YOUR NETWORK GATEWAY IP ADDRESS HERE!	
byte subnet[] = { 255, 255, 255, 0 };                // <-- FILL IN YOUR NETWORK SUBNET MASK HERE!

byte server[] = { 173, 255, 209, 28 }; // m2.exosite.com
Client client(server, 80); // Port 80 is default for HTTP
static char enetInitDone = 0;

void sendToExosite(int res, int value) {
  String myDataString = ""; //allocate for actual data sent
  
  if (!enetInitDone) {
    Ethernet.begin(mac, ip);
    delay(500);
    enetInitDone = 1;
  }
  
  if (client.connect()) {
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
      // Read from the nic or the IC buffer overflows with no warning and goes out to lunch
      while (client.available()) {
        char c = client.read();
      }
      client.stop();
    }
  }
}

int readFromExosite(String res ,String* pResult) {
  int ret = 0;
  char rxdata[150];
  int stringPos = 0;
  boolean DataRecieved = false;
  boolean RxLoop = true;
  char c;
  unsigned long timeout_time = 0;
  unsigned long time_now = 0;
  unsigned long timeout = 3000; // 3 seconds
  
  if (!enetInitDone) {
    Ethernet.begin(mac, ip);
    delay(500);
    enetInitDone = 1;
  }
  
  if (client.connect()) {
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
      // Read from the nic or the IC buffer overflows with no warning and goes out to lunch
      timeout_time = millis()+ timeout;

      while ((timeout_time > time_now) && RxLoop) {
        if (client.available()) {
          if (!DataRecieved)
            DataRecieved = true;
          
          c = client.read();
          rxdata[stringPos] = c;
          stringPos += 1;
        } else {
          rxdata[stringPos] = 0;
          if (DataRecieved) {
            DataRecieved = false;
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
