/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_MSG_DATA */
/*                                                                                                                           */
/*   AUTHOR(S):                                                                                                              */
/*      U. Homann                                                                                                              */
/*      M. Eikermann                                                                                                              */
/*                                                                                                                           */
/*                                                                                                                           */
/*   RTICANMM Date: 13-Mar-2014 10:38:34                                                                                     */
/*   RTICANMM Version: 3.0.735671.4434490741                                                                                     */
/*                                                                                                                           */
/*  (c) Copyright 2015, dSPACE GmbH. All rights reserved.                                                                    */
/*      Brand names or product names are trademarks or registered trademarks of their respective companies or organizations. */
/*                                                                                                                           */
/* ***************************************************************************************************************************/

/* Global variables used for signal decoding */                               
static ULong64 ulong64Temp  = 0;                                              
static Long64  long64Temp   = 0;                                              
static Int32   signedTemp   = 0;                                              
static UInt32  unsignedTemp = 0;                                              
static Float32 floatTemp    = 0.0;                                            
static double  doubleTemp   = 0.0;                                            


void RTICANMM_MAIN_CAN_copy_AngleSensor(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_ISO11992_EBS21(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
/* Message for custom code manipulations */         
static RTICANMMMsgStruct custCodeMsg;               
                                                    
static void custCodeMsg2Data(RTICANMMMsgStruct *msg, MainSetupMsgData *data) {         
  int i = 0;                                        
  data->CANMsg.Format  = (CanMM_Msg_Format) msg->idformat;
  data->CANMsg.Id      = msg->identifier;           
  data->CANMsg.Dlc     = msg->len;                  
  for (i=0; i<8; i++) {                             
      data->pData[i] = msg->RAW_DATA[i];            
  }                                                 
  data->DelayTime   = msg->DelayTime;               
  data->CycleTime   = msg->CycleTime;               
  data->Status      = msg->status;                  
  data->TXCounter   = msg->TX_counter;              
  data->RXCounter   = msg->RX_counter;              
}                                                   
                                                    
                                                    
/* CustomCode requires all data (TX path) */        
static void data2CustCodeMsg(MainSetupMsgData *data, RTICANMMMsgStruct *msg) {        
  int i = 0;                                        
  msg->idformat    = (int)data->CANMsg.Format;      
  msg->identifier  = data->CANMsg.Id;               
  msg->DelayTime   = data->DelayTime;               
  msg->CycleTime   = data->CycleTime;               
  msg->status      = data->Status;                  
  msg->TX_counter  = data->TXCounter;               
  msg->RX_counter  = data->RXCounter;               
                                                    
  msg->deltatime   = data->DeltaTime;               
  msg->time        = data->CANMsg.TimeStamp;        
                                                    
  msg->len         = data->CANMsg.Dlc;              
  for (i=0; i<8; i++) {                             
      msg->RAW_DATA[i] = data->pData[i];            
  }                                                 
}                                                   
                                                    
/*----------------------------------------------------------------------------------------------*/
/* ----- AngleSensor  -----*/  
void RTICANMM_MAIN_CAN_copy_AngleSensor(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[1] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_RXLEN[1] = data->CANMsg.Dlc;                                  
                                                                
/* PacketType */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0x7;                             
CANMMCAN_RX_Msg_1_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* MessageCounter */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 3;                        
unsignedTemp = unsignedTemp & 0x1F;                             
CANMMCAN_RX_Msg_1_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* Angle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_RX_Msg_1_Sgn_3 = (double)0.0078125 * (double)unsignedTemp + (double)(-200);                    

/* Temperature */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_1_Sgn_4 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-40);                    

/* AlarmWarningBits */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_1_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((uint8_T*) ssGetOutputPortSignal(S, 0))[0] = CANMMCAN_RX_Msg_1_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 1))[0] = CANMMCAN_RX_Msg_1_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 2))[0] = CANMMCAN_RX_Msg_1_Sgn_3;
((int16_T*) ssGetOutputPortSignal(S, 3))[0] = CANMMCAN_RX_Msg_1_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 4))[0] = CANMMCAN_RX_Msg_1_Sgn_5;
}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- ISO11992_EBS21  -----*/  
void RTICANMM_MAIN_CAN_copy_ISO11992_EBS21(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_RXLEN[0] = data->CANMsg.Dlc;                                  
                                                                
/* VehicleABSActive */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_RX_Msg_2_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* VehicleRetarderCtrlActive */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 2;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_RX_Msg_2_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* VehicleServiceBrakeActive */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 4;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_RX_Msg_2_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* AutomTowedVehBreakActive */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 6;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_RX_Msg_2_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* VDCActive */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_RX_Msg_2_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SupplyLineBrakingRequest */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp >> 2;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_RX_Msg_2_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* Wheel_BasedVehicleSpeed */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_RX_Msg_2_Sgn_7 = (double)0.00390625 * (double)unsignedTemp + (double)(0);                    

/* ActualRetarderPercTorque */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_2_Sgn_8 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-125);                    

/* WheelSpeedDiffMainAxle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (5)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_RX_Msg_2_Sgn_9 = (double)0.00390625 * (double)unsignedTemp + (double)(-125);                    

((uint8_T*) ssGetOutputPortSignal(S, 5))[0] = CANMMCAN_RX_Msg_2_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 6))[0] = CANMMCAN_RX_Msg_2_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 7))[0] = CANMMCAN_RX_Msg_2_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 8))[0] = CANMMCAN_RX_Msg_2_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 9))[0] = CANMMCAN_RX_Msg_2_Sgn_5;
((uint8_T*) ssGetOutputPortSignal(S, 10))[0] = CANMMCAN_RX_Msg_2_Sgn_6;
((real_T*) ssGetOutputPortSignal(S, 11))[0] = CANMMCAN_RX_Msg_2_Sgn_7;
((int16_T*) ssGetOutputPortSignal(S, 12))[0] = CANMMCAN_RX_Msg_2_Sgn_8;
((real_T*) ssGetOutputPortSignal(S, 13))[0] = CANMMCAN_RX_Msg_2_Sgn_9;
}      
}


