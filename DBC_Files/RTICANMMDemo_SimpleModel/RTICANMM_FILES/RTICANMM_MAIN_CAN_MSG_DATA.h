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


void RTICANMM_MAIN_CAN_copy_modesignals(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_standard(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_RTFreeID1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_RTFreeID2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_RTFreeID3(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_RTTMessage1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_RTTMessage2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_RTTMessage3(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
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
/* ----- modesignals  -----*/  
void RTICANMM_MAIN_CAN_copy_modesignals(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[7] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_RXLEN[7] = data->CANMsg.Dlc;                                  
                                                                
/* Modes */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_1_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* test_1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_1_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* test_2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0x3F;                             
CANMMCAN_RX_Msg_1_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* test_3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp >> 6;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_RX_Msg_1_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* test_4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp >> 7;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_RX_Msg_1_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* modemanager */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_1_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

if ((CANMMCAN_RX_Msg_1_Sgn_6 == 2)) {
/* isactivemode2_1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_1_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* isactivemode2_2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_1_Sgn_10 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}
if ((CANMMCAN_RX_Msg_1_Sgn_6 == 15)) {
/* isactivemode15_1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_RX_Msg_1_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* isactivemode15_2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp >> 1;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_RX_Msg_1_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}
/* test_5 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_1_Sgn_11 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* Modes */
CANMMCAN_TX_Msg_1_Sgn_1 = CANMMCAN_TX_Msg_1_Sgn_1_constant;

/* test_1 */
CANMMCAN_TX_Msg_1_Sgn_2 = CANMMCAN_TX_Msg_1_Sgn_2_constant;

/* test_2 */
CANMMCAN_TX_Msg_1_Sgn_3 = CANMMCAN_TX_Msg_1_Sgn_3_constant;

/* test_3 */
CANMMCAN_TX_Msg_1_Sgn_4 = CANMMCAN_TX_Msg_1_Sgn_4_constant;

/* test_4 */
CANMMCAN_TX_Msg_1_Sgn_5 = CANMMCAN_TX_Msg_1_Sgn_5_constant;

/* modemanager */
CANMMCAN_TX_Msg_1_Sgn_6 = CANMMCAN_TX_Msg_1_Sgn_6_constant;
if ((CANMMCAN_TX_Msg_1_Sgn_6 == 2)) {

/* isactivemode2_1 */
CANMMCAN_TX_Msg_1_Sgn_7 = CANMMCAN_TX_Msg_1_Sgn_7_constant;

/* isactivemode2_2 */
CANMMCAN_TX_Msg_1_Sgn_10 = CANMMCAN_TX_Msg_1_Sgn_10_constant;
}
if ((CANMMCAN_TX_Msg_1_Sgn_6 == 15)) {

/* isactivemode15_1 */
CANMMCAN_TX_Msg_1_Sgn_8 = CANMMCAN_TX_Msg_1_Sgn_8_constant;

/* isactivemode15_2 */
CANMMCAN_TX_Msg_1_Sgn_9 = CANMMCAN_TX_Msg_1_Sgn_9_constant;
}

/* test_5 */
CANMMCAN_TX_Msg_1_Sgn_11 = CANMMCAN_TX_Msg_1_Sgn_11_constant;
/* Modes */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* test_1 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* test_2 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3F)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0x3F << 0))) | INT8_TO_LE(unsignedTemp);               

/* test_3 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 6;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0x1 << 6))) | INT8_TO_LE(unsignedTemp);               

/* test_4 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 7;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0x1 << 7))) | INT8_TO_LE(unsignedTemp);               

/* modemanager */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_6 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

if ((CANMMCAN_TX_Msg_1_Sgn_6 == 2)) {
/* isactivemode2_1 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_7 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* isactivemode2_2 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_10 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[5]) = (*((UInt8*)&data->pData[5]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

}
if ((CANMMCAN_TX_Msg_1_Sgn_6 == 15)) {
/* isactivemode15_1 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_8 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0x1 << 0))) | INT8_TO_LE(unsignedTemp);               

/* isactivemode15_2 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_9 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 1;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0x1 << 1))) | INT8_TO_LE(unsignedTemp);               

}
/* test_5 */ 
unsignedTemp = (CANMMCAN_TX_Msg_1_Sgn_11 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_TXLEN[7], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_MIDRX[7];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_MIDFTX[7];  
CANMMCAN_TXsta[7] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- standard  -----*/  
void RTICANMM_MAIN_CAN_copy_standard(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[6] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_RXLEN[6] = data->CANMsg.Dlc;                                  
                                                                
/* SignalWithError */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xF;                             
CANMMCAN_RX_Msg_2_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(2);                    

/* Bit_4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp >> 4;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_RX_Msg_2_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* Bit_3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp >> 5;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_RX_Msg_2_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* Bit_2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp >> 6;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_RX_Msg_2_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* Bit_1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp >> 7;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_RX_Msg_2_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* Signed */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
if (unsignedTemp & 0x80) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_RX_Msg_2_Sgn_6 = (double)0.5 * (double)signedTemp + (double)(0);                    

/* Temperature */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_2_Sgn_7 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-50);                    

/* SignalFactor */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_2_Sgn_8 = (double)0.1 * (double)unsignedTemp + (double)(0);                    

/* SignalOffset */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp >> 4;                        
unsignedTemp = unsignedTemp & 0xF;                             
CANMMCAN_RX_Msg_2_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(200);                    

/* CRC */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_2_Sgn_10 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* SignalWithError */
CANMMCAN_TX_Msg_2_Sgn_1 = CANMMCAN_TX_Msg_2_Sgn_1_constant;

/* Bit_4 */
CANMMCAN_TX_Msg_2_Sgn_2 = CANMMCAN_TX_Msg_2_Sgn_2_constant;

/* Bit_3 */
CANMMCAN_TX_Msg_2_Sgn_3 = CANMMCAN_TX_Msg_2_Sgn_3_constant;

/* Bit_2 */
CANMMCAN_TX_Msg_2_Sgn_4 = CANMMCAN_TX_Msg_2_Sgn_4_constant;

/* Bit_1 */
CANMMCAN_TX_Msg_2_Sgn_5 = CANMMCAN_TX_Msg_2_Sgn_5_constant;

/* Signed */
CANMMCAN_TX_Msg_2_Sgn_6 = CANMMCAN_TX_Msg_2_Sgn_6_constant;

/* Temperature */
CANMMCAN_TX_Msg_2_Sgn_7 = CANMMCAN_TX_Msg_2_Sgn_7_constant;

/* SignalFactor */
CANMMCAN_TX_Msg_2_Sgn_8 = CANMMCAN_TX_Msg_2_Sgn_8_constant;

/* SignalOffset */
CANMMCAN_TX_Msg_2_Sgn_9 = CANMMCAN_TX_Msg_2_Sgn_9_constant;

/* CRC */
CANMMCAN_TX_Msg_2_Sgn_10 = CANMMCAN_TX_Msg_2_Sgn_10_constant;
/* SignalWithError */ 
unsignedTemp = ((CANMMCAN_TX_Msg_2_Sgn_1 - (2)) + (CANMMCAN_TX_Msg_2_Sgn_1 > 2) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xF << 0))) | INT8_TO_LE(unsignedTemp);               

/* Bit_4 */ 
unsignedTemp = (CANMMCAN_TX_Msg_2_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 4;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 4))) | INT8_TO_LE(unsignedTemp);               

/* Bit_3 */ 
unsignedTemp = (CANMMCAN_TX_Msg_2_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 5;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 5))) | INT8_TO_LE(unsignedTemp);               

/* Bit_2 */ 
unsignedTemp = (CANMMCAN_TX_Msg_2_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 6;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 6))) | INT8_TO_LE(unsignedTemp);               

/* Bit_1 */ 
unsignedTemp = (CANMMCAN_TX_Msg_2_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 7;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x1 << 7))) | INT8_TO_LE(unsignedTemp);               

/* Signed */ 
signedTemp = (((CANMMCAN_TX_Msg_2_Sgn_6 - (0)) / ((double)0.5)) + (CANMMCAN_TX_Msg_2_Sgn_6 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(signedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* Temperature */ 
unsignedTemp = ((CANMMCAN_TX_Msg_2_Sgn_7 - (-50)) + (CANMMCAN_TX_Msg_2_Sgn_7 > -50) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SignalFactor */ 
unsignedTemp = (((CANMMCAN_TX_Msg_2_Sgn_8 - (0)) / ((double)0.1)) + (CANMMCAN_TX_Msg_2_Sgn_8 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SignalOffset */ 
unsignedTemp = ((CANMMCAN_TX_Msg_2_Sgn_9 - (200)) + (CANMMCAN_TX_Msg_2_Sgn_9 > 200) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xF)) << 4;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0xF << 4))) | INT8_TO_LE(unsignedTemp);               

/* CRC */ 
unsignedTemp = (CANMMCAN_TX_Msg_2_Sgn_10 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_TXLEN[6], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_MIDRX[6];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_MIDFTX[6];  
CANMMCAN_TXsta[6] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- RTFreeID1  -----*/  
void RTICANMM_MAIN_CAN_copy_RTFreeID1(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_RXLEN[0] = data->CANMsg.Dlc;                                  
                                                                
/* RAW_Byte_1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_3_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_3_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_3_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_3_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_5 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_3_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_6 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_3_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_7 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_3_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_8 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_3_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

CANMMCAN_RXCNT[0] = CANMMCAN_RXCNT[0]+1;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* RAW_Byte_1 */
CANMMCAN_TX_Msg_3_Sgn_1 = CANMMCAN_TX_Msg_3_Sgn_1_constant;

/* RAW_Byte_2 */
CANMMCAN_TX_Msg_3_Sgn_2 = CANMMCAN_TX_Msg_3_Sgn_2_constant;

/* RAW_Byte_3 */
CANMMCAN_TX_Msg_3_Sgn_3 = CANMMCAN_TX_Msg_3_Sgn_3_constant;

/* RAW_Byte_4 */
CANMMCAN_TX_Msg_3_Sgn_4 = CANMMCAN_TX_Msg_3_Sgn_4_constant;

/* RAW_Byte_5 */
CANMMCAN_TX_Msg_3_Sgn_5 = CANMMCAN_TX_Msg_3_Sgn_5_constant;

/* RAW_Byte_6 */
CANMMCAN_TX_Msg_3_Sgn_6 = CANMMCAN_TX_Msg_3_Sgn_6_constant;

/* RAW_Byte_7 */
CANMMCAN_TX_Msg_3_Sgn_7 = CANMMCAN_TX_Msg_3_Sgn_7_constant;

/* RAW_Byte_8 */
CANMMCAN_TX_Msg_3_Sgn_8 = CANMMCAN_TX_Msg_3_Sgn_8_constant;
/* RAW_Byte_1 */ 
unsignedTemp = (CANMMCAN_TX_Msg_3_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_2 */ 
unsignedTemp = (CANMMCAN_TX_Msg_3_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_3 */ 
unsignedTemp = (CANMMCAN_TX_Msg_3_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_4 */ 
unsignedTemp = (CANMMCAN_TX_Msg_3_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_5 */ 
unsignedTemp = (CANMMCAN_TX_Msg_3_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_6 */ 
unsignedTemp = (CANMMCAN_TX_Msg_3_Sgn_6 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[5]) = (*((UInt8*)&data->pData[5]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_7 */ 
unsignedTemp = (CANMMCAN_TX_Msg_3_Sgn_7 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_8 */ 
unsignedTemp = (CANMMCAN_TX_Msg_3_Sgn_8 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_TXLEN[0], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_MIDRX[0];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_MIDFTX[0];  
CANMMCAN_TXsta[0] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- RTFreeID2  -----*/  
void RTICANMM_MAIN_CAN_copy_RTFreeID2(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[1] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_RXLEN[1] = data->CANMsg.Dlc;                                  
                                                                
/* RAW_Byte_1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_4_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_4_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_4_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_4_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_5 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_4_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_6 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_4_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_7 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_4_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_8 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_4_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

CANMMCAN_RXCNT[1] = CANMMCAN_RXCNT[1]+1;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* RAW_Byte_1 */
CANMMCAN_TX_Msg_4_Sgn_1 = CANMMCAN_TX_Msg_4_Sgn_1_constant;

/* RAW_Byte_2 */
CANMMCAN_TX_Msg_4_Sgn_2 = CANMMCAN_TX_Msg_4_Sgn_2_constant;

/* RAW_Byte_3 */
CANMMCAN_TX_Msg_4_Sgn_3 = CANMMCAN_TX_Msg_4_Sgn_3_constant;

/* RAW_Byte_4 */
CANMMCAN_TX_Msg_4_Sgn_4 = CANMMCAN_TX_Msg_4_Sgn_4_constant;

/* RAW_Byte_5 */
CANMMCAN_TX_Msg_4_Sgn_5 = CANMMCAN_TX_Msg_4_Sgn_5_constant;

/* RAW_Byte_6 */
CANMMCAN_TX_Msg_4_Sgn_6 = CANMMCAN_TX_Msg_4_Sgn_6_constant;

/* RAW_Byte_7 */
CANMMCAN_TX_Msg_4_Sgn_7 = CANMMCAN_TX_Msg_4_Sgn_7_constant;

/* RAW_Byte_8 */
CANMMCAN_TX_Msg_4_Sgn_8 = CANMMCAN_TX_Msg_4_Sgn_8_constant;
/* RAW_Byte_1 */ 
unsignedTemp = (CANMMCAN_TX_Msg_4_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_2 */ 
unsignedTemp = (CANMMCAN_TX_Msg_4_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_3 */ 
unsignedTemp = (CANMMCAN_TX_Msg_4_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_4 */ 
unsignedTemp = (CANMMCAN_TX_Msg_4_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_5 */ 
unsignedTemp = (CANMMCAN_TX_Msg_4_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_6 */ 
unsignedTemp = (CANMMCAN_TX_Msg_4_Sgn_6 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[5]) = (*((UInt8*)&data->pData[5]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_7 */ 
unsignedTemp = (CANMMCAN_TX_Msg_4_Sgn_7 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_8 */ 
unsignedTemp = (CANMMCAN_TX_Msg_4_Sgn_8 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_TXLEN[1], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_MIDRX[1];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_MIDFTX[1];  
CANMMCAN_TXsta[1] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- RTFreeID3  -----*/  
void RTICANMM_MAIN_CAN_copy_RTFreeID3(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[2] = (int)data->CANMsg.Format;                            
  
                                                                
    /* Decode message data */                                   
    CANMMCAN_RXLEN[2] = data->CANMsg.Dlc;                                  
                                                                
/* RAW_Byte_1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_5_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_5_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_5_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_5_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_5 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_5_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_6 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_5_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_7 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_5_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* RAW_Byte_8 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_RX_Msg_5_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

CANMMCAN_RXCNT[2] = CANMMCAN_RXCNT[2]+1;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* RAW_Byte_1 */
CANMMCAN_TX_Msg_5_Sgn_1 = CANMMCAN_TX_Msg_5_Sgn_1_constant;

/* RAW_Byte_2 */
CANMMCAN_TX_Msg_5_Sgn_2 = CANMMCAN_TX_Msg_5_Sgn_2_constant;

/* RAW_Byte_3 */
CANMMCAN_TX_Msg_5_Sgn_3 = CANMMCAN_TX_Msg_5_Sgn_3_constant;

/* RAW_Byte_4 */
CANMMCAN_TX_Msg_5_Sgn_4 = CANMMCAN_TX_Msg_5_Sgn_4_constant;

/* RAW_Byte_5 */
CANMMCAN_TX_Msg_5_Sgn_5 = CANMMCAN_TX_Msg_5_Sgn_5_constant;

/* RAW_Byte_6 */
CANMMCAN_TX_Msg_5_Sgn_6 = CANMMCAN_TX_Msg_5_Sgn_6_constant;

/* RAW_Byte_7 */
CANMMCAN_TX_Msg_5_Sgn_7 = CANMMCAN_TX_Msg_5_Sgn_7_constant;

/* RAW_Byte_8 */
CANMMCAN_TX_Msg_5_Sgn_8 = CANMMCAN_TX_Msg_5_Sgn_8_constant;
/* RAW_Byte_1 */ 
unsignedTemp = (CANMMCAN_TX_Msg_5_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_2 */ 
unsignedTemp = (CANMMCAN_TX_Msg_5_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_3 */ 
unsignedTemp = (CANMMCAN_TX_Msg_5_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_4 */ 
unsignedTemp = (CANMMCAN_TX_Msg_5_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_5 */ 
unsignedTemp = (CANMMCAN_TX_Msg_5_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_6 */ 
unsignedTemp = (CANMMCAN_TX_Msg_5_Sgn_6 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[5]) = (*((UInt8*)&data->pData[5]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_7 */ 
unsignedTemp = (CANMMCAN_TX_Msg_5_Sgn_7 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RAW_Byte_8 */ 
unsignedTemp = (CANMMCAN_TX_Msg_5_Sgn_8 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_TXLEN[2], (uint8_T)8, (uint8_T)0);

  data->CANMsg.Id = CANMMCAN_MIDRX[2];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_MIDFTX[2];  
CANMMCAN_TXsta[2] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- RTTMessage1  -----*/  
void RTICANMM_MAIN_CAN_copy_RTTMessage1(MainSetupMsgData* data, int direction, SimStruct *S)
{
if (direction == RX) {                               
  /* Add status and delta from global variables */   
  data->Status = CANMMCAN_RXsta[3];                             
  data->DeltaTime = CANMMCAN_RXdt[3];                          
                                                     
  /* Copy data to RTT interface structure */         
  data2CustCodeMsg(data, &CANMMCAN_RTTRX[0]);               
                                                     
  CANMMCAN_RTTRX[0].RTTRX_counter++;                            
}                                                    
else {  /* TX */                                     
  custCodeMsg2Data(&CANMMCAN_RTTTX[0], data);                   
  CANMMCAN_RTTTX[0].RTTTX_counter++;                            
                                                     
  /* Reset kickout (set by RTT) */                   
  CANMMCAN_RTTRX[0].Kickout = 0;                                
}                                                    
}


/*----------------------------------------------------------------------------------------------*/
/* ----- RTTMessage2  -----*/  
void RTICANMM_MAIN_CAN_copy_RTTMessage2(MainSetupMsgData* data, int direction, SimStruct *S)
{
if (direction == RX) {                               
  /* Add status and delta from global variables */   
  data->Status = CANMMCAN_RXsta[4];                             
  data->DeltaTime = CANMMCAN_RXdt[4];                          
                                                     
  /* Copy data to RTT interface structure */         
  data2CustCodeMsg(data, &CANMMCAN_RTTRX[1]);               
                                                     
  CANMMCAN_RTTRX[1].RTTRX_counter++;                            
}                                                    
else {  /* TX */                                     
  custCodeMsg2Data(&CANMMCAN_RTTTX[1], data);                   
  CANMMCAN_RTTTX[1].RTTTX_counter++;                            
                                                     
  /* Reset kickout (set by RTT) */                   
  CANMMCAN_RTTRX[1].Kickout = 0;                                
}                                                    
}


/*----------------------------------------------------------------------------------------------*/
/* ----- RTTMessage3  -----*/  
void RTICANMM_MAIN_CAN_copy_RTTMessage3(MainSetupMsgData* data, int direction, SimStruct *S)
{
if (direction == RX) {                               
  /* Add status and delta from global variables */   
  data->Status = CANMMCAN_RXsta[5];                             
  data->DeltaTime = CANMMCAN_RXdt[5];                          
                                                     
  /* Copy data to RTT interface structure */         
  data2CustCodeMsg(data, &CANMMCAN_RTTRX[2]);               
                                                     
  CANMMCAN_RTTRX[2].RTTRX_counter++;                            
}                                                    
else {  /* TX */                                     
  custCodeMsg2Data(&CANMMCAN_RTTTX[2], data);                   
  CANMMCAN_RTTTX[2].RTTTX_counter++;                            
                                                     
  /* Reset kickout (set by RTT) */                   
  CANMMCAN_RTTRX[2].Kickout = 0;                                
}                                                    
}


