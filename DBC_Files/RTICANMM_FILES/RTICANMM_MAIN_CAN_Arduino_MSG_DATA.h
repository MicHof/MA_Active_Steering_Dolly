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


void RTICANMM_MAIN_CAN_Arduino_copy_IMU_accelerometer(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Arduino_copy_IMU_angels_corrected(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_Arduino_copy_IMU_gyroskop(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
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
/* ----- IMU_accelerometer  -----*/  
void RTICANMM_MAIN_CAN_Arduino_copy_IMU_accelerometer(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_Arduino_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_Arduino_RXLEN[0] = data->CANMsg.Dlc;                                  
                                                                
/* x */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_1_Sgn_1 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

/* y */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_1_Sgn_2 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

/* z */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_1_Sgn_3 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

((int16_T*) ssGetOutputPortSignal(S, 0))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_1;
((int16_T*) ssGetOutputPortSignal(S, 1))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_2;
((int16_T*) ssGetOutputPortSignal(S, 2))[0] = CANMMCAN_Arduino_RX_Msg_1_Sgn_3;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* x */
CANMMCAN_Arduino_TX_Msg_1_Sgn_1 = ((int16_T*)GetInputPortSignal(S,0))[0];

/* y */
CANMMCAN_Arduino_TX_Msg_1_Sgn_2 = ((int16_T*)GetInputPortSignal(S,1))[0];

/* z */
CANMMCAN_Arduino_TX_Msg_1_Sgn_3 = ((int16_T*)GetInputPortSignal(S,2))[0];
/* x */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_1 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* y */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_2 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* z */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_1_Sgn_3 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Arduino_TXLEN[0], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_Arduino_MIDRX[0];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Arduino_MIDFTX[0];  
CANMMCAN_Arduino_TXsta[0] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- IMU_angels_corrected  -----*/  
void RTICANMM_MAIN_CAN_Arduino_copy_IMU_angels_corrected(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_Arduino_MIDFRX[2] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_Arduino_RXLEN[2] = data->CANMsg.Dlc;                                  
                                                                
/* x */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_2_Sgn_1 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

/* y */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_2_Sgn_2 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

/* z */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_2_Sgn_3 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

((int16_T*) ssGetOutputPortSignal(S, 3))[0] = CANMMCAN_Arduino_RX_Msg_2_Sgn_1;
((int16_T*) ssGetOutputPortSignal(S, 4))[0] = CANMMCAN_Arduino_RX_Msg_2_Sgn_2;
((int16_T*) ssGetOutputPortSignal(S, 5))[0] = CANMMCAN_Arduino_RX_Msg_2_Sgn_3;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* x */
CANMMCAN_Arduino_TX_Msg_2_Sgn_1 = ((int16_T*)GetInputPortSignal(S,3))[0];

/* y */
CANMMCAN_Arduino_TX_Msg_2_Sgn_2 = ((int16_T*)GetInputPortSignal(S,4))[0];

/* z */
CANMMCAN_Arduino_TX_Msg_2_Sgn_3 = ((int16_T*)GetInputPortSignal(S,5))[0];
/* x */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_2_Sgn_1 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* y */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_2_Sgn_2 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* z */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_2_Sgn_3 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Arduino_TXLEN[2], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_Arduino_MIDRX[2];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Arduino_MIDFTX[2];  
CANMMCAN_Arduino_TXsta[2] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- IMU_gyroskop  -----*/  
void RTICANMM_MAIN_CAN_Arduino_copy_IMU_gyroskop(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_Arduino_MIDFRX[1] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_Arduino_RXLEN[1] = data->CANMsg.Dlc;                                  
                                                                
/* x */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_3_Sgn_1 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

/* y */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_3_Sgn_2 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

/* z */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
if (unsignedTemp & 0x8000) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFF0000;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_Arduino_RX_Msg_3_Sgn_3 = (Int16)1 * (Int16)signedTemp + (Int16)(0);                    

((int16_T*) ssGetOutputPortSignal(S, 6))[0] = CANMMCAN_Arduino_RX_Msg_3_Sgn_1;
((int16_T*) ssGetOutputPortSignal(S, 7))[0] = CANMMCAN_Arduino_RX_Msg_3_Sgn_2;
((int16_T*) ssGetOutputPortSignal(S, 8))[0] = CANMMCAN_Arduino_RX_Msg_3_Sgn_3;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* x */
CANMMCAN_Arduino_TX_Msg_3_Sgn_1 = ((int16_T*)GetInputPortSignal(S,6))[0];

/* y */
CANMMCAN_Arduino_TX_Msg_3_Sgn_2 = ((int16_T*)GetInputPortSignal(S,7))[0];

/* z */
CANMMCAN_Arduino_TX_Msg_3_Sgn_3 = ((int16_T*)GetInputPortSignal(S,8))[0];
/* x */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_3_Sgn_1 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* y */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_3_Sgn_2 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* z */ 
signedTemp = (CANMMCAN_Arduino_TX_Msg_3_Sgn_3 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_Arduino_TXLEN[1], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_Arduino_MIDRX[1];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_Arduino_MIDFTX[1];  
CANMMCAN_Arduino_TXsta[1] = 1;                                       
} /* TX */
}


