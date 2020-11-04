 // Include the SX1272 and SPI library: 
//#include <Bridge.h>
#include "SX1276.h"
#include <SPI.h>
#include <Console.h>


int e;

void setup()
{
  // Open Console communications and wait for port to open:
 Bridge.begin(115200);
  Console.begin();
  
  // Print a start message
  Console.println("SX1276 module and Arduino: receive packets without ACK");
  
  // Power ON the module
  sx1276.ON();// Set transmission mode and print the result
  e = sx1276.setMode(1);
  Console.println(e, DEC);
  
  // Select frequency channel
  e = sx1276.setChannel(CH_16_868);
  Console.println("Setting Channel: state ");
  Console.println(e, DEC);
  
 
  sx1276.setMaxCurrent(0x1B);
  sx1276.getMaxCurrent();
  // Select output power (Max, High or Low)
  /* H=13dBm M=17dBm  measured at the antenna connector*/
  
  e = sx1276.setPower('M');
 
  
  Console.println("Setting Power: state ");
  Console.println(e);
  
  // Set the node address and print the result
  e = sx1276.setNodeAddress(8);
  Console.println(e, DEC);
  
  // Print a success message
  Console.print("SX1276 successfully configured ");
}

void loop(void)
{
  // Receive message
  String msg = "";
  Console.println("Loop");
  e = sx1276.receivePacketTimeout(10000);
  Console.println(sx1276.packet_received.src);
 //if(!e){
  for ( int a=0; a<sx1276._payloadlength; a++) {
      msg+=String((char)sx1276.packet_received.data[a]);
  }
  //e = sx1276. getRSSIpacket();
  if(msg.length()>0){
  Console.println(msg);
  Console.print(("Receive packet timeout, state "));
  Console.println(e, DEC);
 }
  //delay(3000);
  
}
