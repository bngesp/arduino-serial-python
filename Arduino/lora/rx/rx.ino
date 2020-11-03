 // Include the SX1272 and SPI library: 
//#include <Bridge.h>
#include "SX1276.h"
#include <SPI.h>
//#include <Serial.h>


int e;

void setup()
{
  // Open Serial communications and wait for port to open:
 Serial.begin(115200);
  //Serial.begin();
  
  // Print a start message
  Serial.println("SX1276 module and Arduino: receive packets without ACK");
  
  // Power ON the module
  sx1276.ON();// Set transmission mode and print the result
  e = sx1276.setMode(1);
  Serial.println(e, DEC);
  
  // Select frequency channel
  e = sx1276.setChannel(CH_16_868);
  Serial.println("Setting Channel: state ");
  Serial.println(e, DEC);
  
 
  sx1276.setMaxCurrent(0x1B);
  sx1276.getMaxCurrent();
  // Select output power (Max, High or Low)
  /* H=13dBm M=17dBm  measured at the antenna connector*/
  
  e = sx1276.setPower('M');
 
  
  Serial.println("Setting Power: state ");
  Serial.println(e);
  
  // Set the node address and print the result
  e = sx1276.setNodeAddress(8);
  Serial.println(e, DEC);
  
  // Print a success message
  Serial.print("SX1276 successfully configured ");
}

void loop(void)
{
  // Receive message
  String msg = "";
  Serial.println("Loop");
  e = sx1276.receivePacketTimeout(10000);
  Serial.println(sx1276.packet_received.dst);
 //if(!e){
  for ( int a=0; a<sx1276._payloadlength; a++) {
      msg+=String((char)sx1276.packet_received.data[a]);
  }
  //e = sx1276. getRSSIpacket();
  if(msg.length()>0){
  Serial.println(msg);
  Serial.print(("Receive packet timeout, state "));
  Serial.println(e, DEC);
 }
  //delay(3000);
  
}
