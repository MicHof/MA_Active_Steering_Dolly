/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_MSG_DATA */
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


void RTICANMM_MAIN_CAN_Arduino_copy_RTICANMMFreeRawMessage_1(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
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
/* ----- RTICANMMFreeRawMessage_1  -----*/  
void RTICANMM_MAIN_CAN_Arduino_copy_RTICANMMFreeRawMessage_1(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_Arduino_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_Arduino_RXLEN[0] = data->CANMsg.Dlc;                                  
                                                                
/* RAW_Byte_1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_Arduino_RX_Msg_1_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_Arduino_RX_Msg_1_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_Arduino_RX_Msg_1_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_Arduino_RX_Msg_1_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_5 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_Arduino_RX_Msg_1_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_6 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_Arduino_RX_Msg_1_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_7 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_Arduino_RX_Msg_1_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_8 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_Arduino_RX_Msg_1_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((uint8_T*) ssGetOutputPortSignal(S, 0))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 1))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 2))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 3))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 4))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_5;
((uint8_T*) ssGetOutputPortSignal(S, 5))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_6;
((uint8_T*) ssGetOutputPortSignal(S, 6))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_7;
((uint8_T*) ssGetOutputPortSignal(S, 7))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_8;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* RAW_Byte_1 */
CANMMCAN_Arduino_TX_Msg_1_Sgn_1 = ((uint8_T*)GetInputPortSignal(S,0))[0];

/* RAW_Byte_2 */
CANMMCAN_Arduino_TX_Msg_1_Sgn_2 = ((uint8_T*)GetInputPortSignal(S,1))[0];

/* RAW_Byte_3 */
CANMMCAN_Arduino_TX_Msg_1_Sgn_3 = ((uint8_T*)GetInputPortSignal(S,2))[0];

/* RAW_Byte_4 */
CANMMCAN_Arduino_TX_Msg_1_Sgn_4 = ((uint8_T*)GetInputPortSignal(S,3))[0];

/* RAW_Byte_5 */
CANMMCAN_Arduino_TX_Msg_1_Sgn_5 = ((uint8_T*)GetInputPortSignal(S,4))[0];

/* RAW_Byte_6 */
CANMMCAN_Arduino_TX_Msg_1_Sgn_6 = ((uint8_T*)GetInputPortSignal(S,5))[0];

/* RAW_Byte_7 */
CANMMCAN_Arduino_TX_Msg_1_Sgn_7 = ((uint8_T*)GetInputPortSignal(S,6))[0];

/* RAW_Byte_8 */
CANMMCAN_Arduino_TX_Msg_1_Sgn_8 = ((uint8_T*)GetInputPortSignal(S,7))[0];
/* RAW_Byte_1 */ 
unsignedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_2 */ 
unsignedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_3 */ 
unsignedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_4 */ 
unsignedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_5 */ 
unsignedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_6 */ 
unsignedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_6 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[5]) = (*((UInt8*)&data->pData[5]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_7 */ 
unsignedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_7 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_8 */ 
unsignedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_8 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Arduino_TXLEN[0], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_Arduino_MIDRX[0];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Arduino_MIDFTX[0];  
CANMMCAN_Arduino_TXsta[0] = 1;                                       
} /* TX */
}


