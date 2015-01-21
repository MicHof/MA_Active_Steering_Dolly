// Arduino Due - CAN Sample 1
// Brief CAN example for Arduino Due
// Test the transmission from CAN0 Mailbox 0 to CAN1 Mailbox 0
// By Thibaut Viard/Wilfredo Molina/Collin Kidder 2013

// Required libraries
#include "variant.h"
#include <due_can.h>

#define TEST1_CAN_COMM_MB_IDX    0
#define TEST1_CAN_TRANSFER_ID    0x07
#define TEST1_CAN0_TX_PRIO       15
#define CAN_MSG_DUMMY_DATA       4

// CAN frame max data length
#define MAX_CAN_FRAME_DATA_LEN   8

// Message variable to be send
uint32_t CAN_MSG_1 = 4;

//Leave defined if you use native port, comment if using programming port
//#define Serial SerialUSB

void setup()
{
  CAN_FRAME output;

}
void loop(){

  CAN_FRAME output;
 
  // Initialize CAN0 and CAN1, baudrate is 250kb/s
  Can0.begin(CAN_BPS_500K);
  Can1.begin(CAN_BPS_500K);

  //The default is to allow nothing through if nothing is specified
 
  // Prepare transmit ID, data and data length in CAN0 mailbox 0
  output.id = TEST1_CAN_TRANSFER_ID;
  output.length = MAX_CAN_FRAME_DATA_LEN;
  //Set first four bytes (32 bits) all at once
  output.data.low = CAN_MSG_1;
  //Set last four bytes (32 bits) all at once
  output.data.high = CAN_MSG_DUMMY_DATA;
  //Send out the frame on whichever mailbox is free or queue it for
  //sending when there is an opening.
  CAN.sendFrame(output);

  
  
  // Disable CAN0 Controller
  Can0.disable();

  // Disable CAN1 Controller
  Can1.disable();

delay(200);
}

