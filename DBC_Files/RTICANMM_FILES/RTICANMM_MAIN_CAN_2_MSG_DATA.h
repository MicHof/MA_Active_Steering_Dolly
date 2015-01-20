/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_2_MSG_DATA */
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


void RTICANMM_MAIN_CAN_2_copy_AnalogInputVoltagesMessage1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_AnalogInputVoltagesMessage2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_CurrentMeasurementOutputs1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_CurrentMeasurementOutputs2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_DigitalInput(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage3(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage4(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage5(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_EtsSystemMessage(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_OilSupplyAssignmentMessage(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_OilSupplyRequestMessage(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_PowersupplyVoltageMessage1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_PowersupplyVoltageMessage2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_ResistanceMeasurementOutputs(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_SpeedMessage(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_StatusHighOutputPins(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_2_copy_StatusLowOutputPins(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
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
/* ----- AnalogInputVoltagesMessage1  -----*/  
void RTICANMM_MAIN_CAN_2_copy_AnalogInputVoltagesMessage1(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[8] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[8] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[8] = 0;                                             
CANMMCAN_2_RXSA[8] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[8] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[8] = data->CANMsg.Dlc;                                  
                                                                
/* IAV_AIN1_FrontAngle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_1_Sgn_1 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* IAV_AIN2_FrontAngleRed */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_1_Sgn_2 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* IAV_AIN3_RearAngle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_1_Sgn_3 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* IAV_AIN4_RearAngleRed */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_1_Sgn_4 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

((real_T*) ssGetOutputPortSignal(S, 0))[0] = CANMMCAN_2_RX_Msg_1_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 1))[0] = CANMMCAN_2_RX_Msg_1_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 2))[0] = CANMMCAN_2_RX_Msg_1_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 3))[0] = CANMMCAN_2_RX_Msg_1_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* IAV_AIN1_FrontAngle */
CANMMCAN_2_TX_Msg_1_Sgn_1 = CANMMCAN_2_TX_Msg_1_Sgn_1_constant;

/* IAV_AIN2_FrontAngleRed */
CANMMCAN_2_TX_Msg_1_Sgn_2 = CANMMCAN_2_TX_Msg_1_Sgn_2_constant;

/* IAV_AIN3_RearAngle */
CANMMCAN_2_TX_Msg_1_Sgn_3 = CANMMCAN_2_TX_Msg_1_Sgn_3_constant;

/* IAV_AIN4_RearAngleRed */
CANMMCAN_2_TX_Msg_1_Sgn_4 = CANMMCAN_2_TX_Msg_1_Sgn_4_constant;
/* IAV_AIN1_FrontAngle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_1_Sgn_1 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_1_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* IAV_AIN2_FrontAngleRed */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_1_Sgn_2 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_1_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* IAV_AIN3_RearAngle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_1_Sgn_3 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_1_Sgn_3 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* IAV_AIN4_RearAngleRed */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_1_Sgn_4 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_1_Sgn_4 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[8], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[8];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[8];  
CANMMCAN_2_TXsta[8] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- AnalogInputVoltagesMessage2  -----*/  
void RTICANMM_MAIN_CAN_2_copy_AnalogInputVoltagesMessage2(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[9] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[9] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[9] = 0;                                             
CANMMCAN_2_RXSA[9] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[9] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[9] = data->CANMsg.Dlc;                                  
                                                                
/* IAV_AIN5_PressureSensorX */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_2_Sgn_1 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* IAV_AIN6_PressureSensorY */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_2_Sgn_2 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* IAV_AIN7_RearAngle2 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_2_Sgn_3 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* IAV_AIN8_RearAngle2Red */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_2_Sgn_4 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

((real_T*) ssGetOutputPortSignal(S, 4))[0] = CANMMCAN_2_RX_Msg_2_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 5))[0] = CANMMCAN_2_RX_Msg_2_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 6))[0] = CANMMCAN_2_RX_Msg_2_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 7))[0] = CANMMCAN_2_RX_Msg_2_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* IAV_AIN5_PressureSensorX */
CANMMCAN_2_TX_Msg_2_Sgn_1 = CANMMCAN_2_TX_Msg_2_Sgn_1_constant;

/* IAV_AIN6_PressureSensorY */
CANMMCAN_2_TX_Msg_2_Sgn_2 = CANMMCAN_2_TX_Msg_2_Sgn_2_constant;

/* IAV_AIN7_RearAngle2 */
CANMMCAN_2_TX_Msg_2_Sgn_3 = CANMMCAN_2_TX_Msg_2_Sgn_3_constant;

/* IAV_AIN8_RearAngle2Red */
CANMMCAN_2_TX_Msg_2_Sgn_4 = CANMMCAN_2_TX_Msg_2_Sgn_4_constant;
/* IAV_AIN5_PressureSensorX */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_2_Sgn_1 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_2_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* IAV_AIN6_PressureSensorY */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_2_Sgn_2 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_2_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* IAV_AIN7_RearAngle2 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_2_Sgn_3 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_2_Sgn_3 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* IAV_AIN8_RearAngle2Red */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_2_Sgn_4 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_2_Sgn_4 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[9], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[9];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[9];  
CANMMCAN_2_TXsta[9] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CurrentMeasurementOutputs1  -----*/  
void RTICANMM_MAIN_CAN_2_copy_CurrentMeasurementOutputs1(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[0] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[0] = 0;                                             
CANMMCAN_2_RXSA[0] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[0] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[0] = data->CANMsg.Dlc;                                  
                                                                
/* CMO_Output1 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_3_Sgn_1 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

/* CMO_Output2 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_3_Sgn_2 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

/* CMO_Output3 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_3_Sgn_3 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

/* CMO_Output4 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_3_Sgn_4 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

((real_T*) ssGetOutputPortSignal(S, 8))[0] = CANMMCAN_2_RX_Msg_3_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 9))[0] = CANMMCAN_2_RX_Msg_3_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 10))[0] = CANMMCAN_2_RX_Msg_3_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 11))[0] = CANMMCAN_2_RX_Msg_3_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* CMO_Output1 */
CANMMCAN_2_TX_Msg_3_Sgn_1 = CANMMCAN_2_TX_Msg_3_Sgn_1_constant;

/* CMO_Output2 */
CANMMCAN_2_TX_Msg_3_Sgn_2 = CANMMCAN_2_TX_Msg_3_Sgn_2_constant;

/* CMO_Output3 */
CANMMCAN_2_TX_Msg_3_Sgn_3 = CANMMCAN_2_TX_Msg_3_Sgn_3_constant;

/* CMO_Output4 */
CANMMCAN_2_TX_Msg_3_Sgn_4 = CANMMCAN_2_TX_Msg_3_Sgn_4_constant;
/* CMO_Output1 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_3_Sgn_1 - (0)) / ((double)0.001)) + (CANMMCAN_2_TX_Msg_3_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* CMO_Output2 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_3_Sgn_2 - (0)) / ((double)0.001)) + (CANMMCAN_2_TX_Msg_3_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* CMO_Output3 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_3_Sgn_3 - (0)) / ((double)0.001)) + (CANMMCAN_2_TX_Msg_3_Sgn_3 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* CMO_Output4 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_3_Sgn_4 - (0)) / ((double)0.001)) + (CANMMCAN_2_TX_Msg_3_Sgn_4 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[0], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[0];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[0];  
CANMMCAN_2_TXsta[0] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CurrentMeasurementOutputs2  -----*/  
void RTICANMM_MAIN_CAN_2_copy_CurrentMeasurementOutputs2(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[1] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[1] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[1] = 0;                                             
CANMMCAN_2_RXSA[1] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[1] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[1] = data->CANMsg.Dlc;                                  
                                                                
/* CMO_Output5 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_4_Sgn_1 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

/* CMO_Output6 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_4_Sgn_2 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

/* CMO_Output7 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_4_Sgn_3 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

/* CMO_Output8 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_4_Sgn_4 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

((real_T*) ssGetOutputPortSignal(S, 12))[0] = CANMMCAN_2_RX_Msg_4_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 13))[0] = CANMMCAN_2_RX_Msg_4_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 14))[0] = CANMMCAN_2_RX_Msg_4_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 15))[0] = CANMMCAN_2_RX_Msg_4_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* CMO_Output5 */
CANMMCAN_2_TX_Msg_4_Sgn_1 = CANMMCAN_2_TX_Msg_4_Sgn_1_constant;

/* CMO_Output6 */
CANMMCAN_2_TX_Msg_4_Sgn_2 = CANMMCAN_2_TX_Msg_4_Sgn_2_constant;

/* CMO_Output7 */
CANMMCAN_2_TX_Msg_4_Sgn_3 = CANMMCAN_2_TX_Msg_4_Sgn_3_constant;

/* CMO_Output8 */
CANMMCAN_2_TX_Msg_4_Sgn_4 = CANMMCAN_2_TX_Msg_4_Sgn_4_constant;
/* CMO_Output5 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_4_Sgn_1 - (0)) / ((double)0.001)) + (CANMMCAN_2_TX_Msg_4_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* CMO_Output6 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_4_Sgn_2 - (0)) / ((double)0.001)) + (CANMMCAN_2_TX_Msg_4_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* CMO_Output7 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_4_Sgn_3 - (0)) / ((double)0.001)) + (CANMMCAN_2_TX_Msg_4_Sgn_3 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* CMO_Output8 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_4_Sgn_4 - (0)) / ((double)0.001)) + (CANMMCAN_2_TX_Msg_4_Sgn_4 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[1], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[1];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[1];  
CANMMCAN_2_TXsta[1] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- DigitalInput  -----*/  
void RTICANMM_MAIN_CAN_2_copy_DigitalInput(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[10] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[10] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[10] = 0;                                             
CANMMCAN_2_RXSA[10] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[10] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[10] = data->CANMsg.Dlc;                                  
                                                                
/* DIV_DIN1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 2;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 4;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 6;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN5 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN6 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp >> 2;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN7 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp >> 4;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN8 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp >> 6;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN9 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN10 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp >> 2;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_10 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* DIV_DIN11 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp >> 4;                        
unsignedTemp = unsignedTemp & 0x3;                             
CANMMCAN_2_RX_Msg_5_Sgn_11 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((uint8_T*) ssGetOutputPortSignal(S, 16))[0] = CANMMCAN_2_RX_Msg_5_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 17))[0] = CANMMCAN_2_RX_Msg_5_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 18))[0] = CANMMCAN_2_RX_Msg_5_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 19))[0] = CANMMCAN_2_RX_Msg_5_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 20))[0] = CANMMCAN_2_RX_Msg_5_Sgn_5;
((uint8_T*) ssGetOutputPortSignal(S, 21))[0] = CANMMCAN_2_RX_Msg_5_Sgn_6;
((uint8_T*) ssGetOutputPortSignal(S, 22))[0] = CANMMCAN_2_RX_Msg_5_Sgn_7;
((uint8_T*) ssGetOutputPortSignal(S, 23))[0] = CANMMCAN_2_RX_Msg_5_Sgn_8;
((uint8_T*) ssGetOutputPortSignal(S, 24))[0] = CANMMCAN_2_RX_Msg_5_Sgn_9;
((uint8_T*) ssGetOutputPortSignal(S, 25))[0] = CANMMCAN_2_RX_Msg_5_Sgn_10;
((uint8_T*) ssGetOutputPortSignal(S, 26))[0] = CANMMCAN_2_RX_Msg_5_Sgn_11;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* DIV_DIN1 */
CANMMCAN_2_TX_Msg_5_Sgn_1 = CANMMCAN_2_TX_Msg_5_Sgn_1_constant;

/* DIV_DIN2 */
CANMMCAN_2_TX_Msg_5_Sgn_2 = CANMMCAN_2_TX_Msg_5_Sgn_2_constant;

/* DIV_DIN3 */
CANMMCAN_2_TX_Msg_5_Sgn_3 = CANMMCAN_2_TX_Msg_5_Sgn_3_constant;

/* DIV_DIN4 */
CANMMCAN_2_TX_Msg_5_Sgn_4 = CANMMCAN_2_TX_Msg_5_Sgn_4_constant;

/* DIV_DIN5 */
CANMMCAN_2_TX_Msg_5_Sgn_5 = CANMMCAN_2_TX_Msg_5_Sgn_5_constant;

/* DIV_DIN6 */
CANMMCAN_2_TX_Msg_5_Sgn_6 = CANMMCAN_2_TX_Msg_5_Sgn_6_constant;

/* DIV_DIN7 */
CANMMCAN_2_TX_Msg_5_Sgn_7 = CANMMCAN_2_TX_Msg_5_Sgn_7_constant;

/* DIV_DIN8 */
CANMMCAN_2_TX_Msg_5_Sgn_8 = CANMMCAN_2_TX_Msg_5_Sgn_8_constant;

/* DIV_DIN9 */
CANMMCAN_2_TX_Msg_5_Sgn_9 = CANMMCAN_2_TX_Msg_5_Sgn_9_constant;

/* DIV_DIN10 */
CANMMCAN_2_TX_Msg_5_Sgn_10 = CANMMCAN_2_TX_Msg_5_Sgn_10_constant;

/* DIV_DIN11 */
CANMMCAN_2_TX_Msg_5_Sgn_11 = CANMMCAN_2_TX_Msg_5_Sgn_11_constant;
/* DIV_DIN1 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x3 << 0))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN2 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 2;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x3 << 2))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN3 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 4;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x3 << 4))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN4 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 6;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x3 << 6))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN5 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x3 << 0))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN6 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_6 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 2;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x3 << 2))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN7 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_7 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 4;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x3 << 4))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN8 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_8 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 6;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0x3 << 6))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN9 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_9 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0x3 << 0))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN10 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_10 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 2;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0x3 << 2))) | INT8_TO_LE(unsignedTemp);               

/* DIV_DIN11 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_5_Sgn_11 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 4;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0x3 << 4))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[10], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[10];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[10];  
CANMMCAN_2_TXsta[10] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- EtsDataMessage1  -----*/  
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage1(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[11] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[11] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[11] = 0;                                             
CANMMCAN_2_RXSA[11] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[11] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[11] = data->CANMsg.Dlc;                                  
                                                                
/* ETSD1_InSpeed1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_6_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSD1_InSpeed2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_6_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSD1_TargetAngle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_6_Sgn_3 = (double)0.00390625 * (double)unsignedTemp + (double)(-125);                    

/* ETSD1_FrontAngle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_6_Sgn_4 = (double)0.00390625 * (double)unsignedTemp + (double)(-125);                    

/* ETSD1_RearAngle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_6_Sgn_5 = (double)0.00390625 * (double)unsignedTemp + (double)(-125);                    

((uint8_T*) ssGetOutputPortSignal(S, 27))[0] = CANMMCAN_2_RX_Msg_6_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 28))[0] = CANMMCAN_2_RX_Msg_6_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 29))[0] = CANMMCAN_2_RX_Msg_6_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 30))[0] = CANMMCAN_2_RX_Msg_6_Sgn_4;
((real_T*) ssGetOutputPortSignal(S, 31))[0] = CANMMCAN_2_RX_Msg_6_Sgn_5;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* ETSD1_InSpeed1 */
CANMMCAN_2_TX_Msg_6_Sgn_1 = CANMMCAN_2_TX_Msg_6_Sgn_1_constant;

/* ETSD1_InSpeed2 */
CANMMCAN_2_TX_Msg_6_Sgn_2 = CANMMCAN_2_TX_Msg_6_Sgn_2_constant;

/* ETSD1_TargetAngle */
CANMMCAN_2_TX_Msg_6_Sgn_3 = CANMMCAN_2_TX_Msg_6_Sgn_3_constant;

/* ETSD1_FrontAngle */
CANMMCAN_2_TX_Msg_6_Sgn_4 = CANMMCAN_2_TX_Msg_6_Sgn_4_constant;

/* ETSD1_RearAngle */
CANMMCAN_2_TX_Msg_6_Sgn_5 = CANMMCAN_2_TX_Msg_6_Sgn_5_constant;
/* ETSD1_InSpeed1 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_6_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSD1_InSpeed2 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_6_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSD1_TargetAngle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_6_Sgn_3 - (-125)) / ((double)0.00390625)) + (CANMMCAN_2_TX_Msg_6_Sgn_3 > -125) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* ETSD1_FrontAngle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_6_Sgn_4 - (-125)) / ((double)0.00390625)) + (CANMMCAN_2_TX_Msg_6_Sgn_4 > -125) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* ETSD1_RearAngle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_6_Sgn_5 - (-125)) / ((double)0.00390625)) + (CANMMCAN_2_TX_Msg_6_Sgn_5 > -125) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[11], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[11];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[11];  
CANMMCAN_2_TXsta[11] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- EtsDataMessage2  -----*/  
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage2(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[13] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[13] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[13] = 0;                                             
CANMMCAN_2_RXSA[13] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[13] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[13] = data->CANMsg.Dlc;                                  
                                                                
/* ETSD2_Target2Angle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_7_Sgn_1 = (double)0.00390625 * (double)unsignedTemp + (double)(-125);                    

/* ETSD2_Rear2Angle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_7_Sgn_2 = (double)0.00390625 * (double)unsignedTemp + (double)(-125);                    

/* ETSD2_PxPressure */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_7_Sgn_3 = (double)0.02 * (double)unsignedTemp + (double)(0);                    

/* ETSD2_PyPressure */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_7_Sgn_4 = (double)0.02 * (double)unsignedTemp + (double)(0);                    

((real_T*) ssGetOutputPortSignal(S, 32))[0] = CANMMCAN_2_RX_Msg_7_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 33))[0] = CANMMCAN_2_RX_Msg_7_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 34))[0] = CANMMCAN_2_RX_Msg_7_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 35))[0] = CANMMCAN_2_RX_Msg_7_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* ETSD2_Target2Angle */
CANMMCAN_2_TX_Msg_7_Sgn_1 = CANMMCAN_2_TX_Msg_7_Sgn_1_constant;

/* ETSD2_Rear2Angle */
CANMMCAN_2_TX_Msg_7_Sgn_2 = CANMMCAN_2_TX_Msg_7_Sgn_2_constant;

/* ETSD2_PxPressure */
CANMMCAN_2_TX_Msg_7_Sgn_3 = CANMMCAN_2_TX_Msg_7_Sgn_3_constant;

/* ETSD2_PyPressure */
CANMMCAN_2_TX_Msg_7_Sgn_4 = CANMMCAN_2_TX_Msg_7_Sgn_4_constant;
/* ETSD2_Target2Angle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_7_Sgn_1 - (-125)) / ((double)0.00390625)) + (CANMMCAN_2_TX_Msg_7_Sgn_1 > -125) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* ETSD2_Rear2Angle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_7_Sgn_2 - (-125)) / ((double)0.00390625)) + (CANMMCAN_2_TX_Msg_7_Sgn_2 > -125) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* ETSD2_PxPressure */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_7_Sgn_3 - (0)) / ((double)0.02)) + (CANMMCAN_2_TX_Msg_7_Sgn_3 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* ETSD2_PyPressure */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_7_Sgn_4 - (0)) / ((double)0.02)) + (CANMMCAN_2_TX_Msg_7_Sgn_4 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[13], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[13];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[13];  
CANMMCAN_2_TXsta[13] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- EtsDataMessage3  -----*/  
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage3(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[14] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[14] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[14] = 0;                                             
CANMMCAN_2_RXSA[14] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[14] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[14] = data->CANMsg.Dlc;                                  
                                                                
/* ETSD3_AmbientTemp */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_8_Sgn_1 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-40);                    

/* ETSD3_OilTemp */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_8_Sgn_2 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-40);                    

/* ETSD3_SecMicroVersion */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_8_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSD3_NmiNumber */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_8_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((int16_T*) ssGetOutputPortSignal(S, 36))[0] = CANMMCAN_2_RX_Msg_8_Sgn_1;
((int16_T*) ssGetOutputPortSignal(S, 37))[0] = CANMMCAN_2_RX_Msg_8_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 38))[0] = CANMMCAN_2_RX_Msg_8_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 39))[0] = CANMMCAN_2_RX_Msg_8_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* ETSD3_AmbientTemp */
CANMMCAN_2_TX_Msg_8_Sgn_1 = CANMMCAN_2_TX_Msg_8_Sgn_1_constant;

/* ETSD3_OilTemp */
CANMMCAN_2_TX_Msg_8_Sgn_2 = CANMMCAN_2_TX_Msg_8_Sgn_2_constant;

/* ETSD3_SecMicroVersion */
CANMMCAN_2_TX_Msg_8_Sgn_3 = CANMMCAN_2_TX_Msg_8_Sgn_3_constant;

/* ETSD3_NmiNumber */
CANMMCAN_2_TX_Msg_8_Sgn_4 = CANMMCAN_2_TX_Msg_8_Sgn_4_constant;
/* ETSD3_AmbientTemp */ 
unsignedTemp = ((CANMMCAN_2_TX_Msg_8_Sgn_1 - (-40)) + (CANMMCAN_2_TX_Msg_8_Sgn_1 > -40) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSD3_OilTemp */ 
unsignedTemp = ((CANMMCAN_2_TX_Msg_8_Sgn_2 - (-40)) + (CANMMCAN_2_TX_Msg_8_Sgn_2 > -40) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSD3_SecMicroVersion */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_8_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSD3_NmiNumber */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_8_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[14], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[14];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[14];  
CANMMCAN_2_TXsta[14] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- EtsDataMessage4  -----*/  
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage4(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[15] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[15] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[15] = 0;                                             
CANMMCAN_2_RXSA[15] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[15] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[15] = data->CANMsg.Dlc;                                  
                                                                
/* ETSD4_CanSensorAngle */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_9_Sgn_1 = (double)0.0078125 * (double)unsignedTemp + (double)(-200);                    

/* ETSD4_CanSensorEtsAngle */ 
unsignedTemp = INT16_FROM_BE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_9_Sgn_2 = (double)0.125 * (double)unsignedTemp + (double)(-64);                    

/* ETSD4_CanSensorTemp */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_9_Sgn_3 = (Int16)1 * (Int16)unsignedTemp + (Int16)(-40);                    

/* ETSD4_CanSensorAlarm */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_9_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((real_T*) ssGetOutputPortSignal(S, 40))[0] = CANMMCAN_2_RX_Msg_9_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 41))[0] = CANMMCAN_2_RX_Msg_9_Sgn_2;
((int16_T*) ssGetOutputPortSignal(S, 42))[0] = CANMMCAN_2_RX_Msg_9_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 43))[0] = CANMMCAN_2_RX_Msg_9_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* ETSD4_CanSensorAngle */
CANMMCAN_2_TX_Msg_9_Sgn_1 = CANMMCAN_2_TX_Msg_9_Sgn_1_constant;

/* ETSD4_CanSensorEtsAngle */
CANMMCAN_2_TX_Msg_9_Sgn_2 = CANMMCAN_2_TX_Msg_9_Sgn_2_constant;

/* ETSD4_CanSensorTemp */
CANMMCAN_2_TX_Msg_9_Sgn_3 = CANMMCAN_2_TX_Msg_9_Sgn_3_constant;

/* ETSD4_CanSensorAlarm */
CANMMCAN_2_TX_Msg_9_Sgn_4 = CANMMCAN_2_TX_Msg_9_Sgn_4_constant;
/* ETSD4_CanSensorAngle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_9_Sgn_1 - (-200)) / ((double)0.0078125)) + (CANMMCAN_2_TX_Msg_9_Sgn_1 > -200) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* ETSD4_CanSensorEtsAngle */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_9_Sgn_2 - (-64)) / ((double)0.125)) + (CANMMCAN_2_TX_Msg_9_Sgn_2 > -64) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_BE(~(0xFFFF << 0))) | INT16_TO_BE(unsignedTemp);               

/* ETSD4_CanSensorTemp */ 
unsignedTemp = ((CANMMCAN_2_TX_Msg_9_Sgn_3 - (-40)) + (CANMMCAN_2_TX_Msg_9_Sgn_3 > -40) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSD4_CanSensorAlarm */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_9_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[15], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[15];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[15];  
CANMMCAN_2_TXsta[15] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- EtsDataMessage5  -----*/  
void RTICANMM_MAIN_CAN_2_copy_EtsDataMessage5(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[16] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[16] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[16] = 0;                                             
CANMMCAN_2_RXSA[16] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[16] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[16] = data->CANMsg.Dlc;                                  
                                                                
/* ETSD5_Py2Cofa */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_10_Sgn_1 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

/* ETSD5_Py2Pressure */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_10_Sgn_2 = (double)0.02 * (double)unsignedTemp + (double)(0);                    

((uint16_T*) ssGetOutputPortSignal(S, 44))[0] = CANMMCAN_2_RX_Msg_10_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 45))[0] = CANMMCAN_2_RX_Msg_10_Sgn_2;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* ETSD5_Py2Cofa */
CANMMCAN_2_TX_Msg_10_Sgn_1 = CANMMCAN_2_TX_Msg_10_Sgn_1_constant;

/* ETSD5_Py2Pressure */
CANMMCAN_2_TX_Msg_10_Sgn_2 = CANMMCAN_2_TX_Msg_10_Sgn_2_constant;
/* ETSD5_Py2Cofa */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_10_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* ETSD5_Py2Pressure */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_10_Sgn_2 - (0)) / ((double)0.02)) + (CANMMCAN_2_TX_Msg_10_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[16], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[16];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[16];  
CANMMCAN_2_TXsta[16] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- EtsSystemMessage  -----*/  
void RTICANMM_MAIN_CAN_2_copy_EtsSystemMessage(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[12] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[12] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[12] = 0;                                             
CANMMCAN_2_RXSA[12] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[12] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[12] = data->CANMsg.Dlc;                                  
                                                                
/* ETSS_SteeringState */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_2_RX_Msg_11_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_AlarmState */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 1;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_2_RX_Msg_11_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_DiagnosticState */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 2;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_2_RX_Msg_11_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_CentringState */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 3;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_2_RX_Msg_11_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_SteerMode */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp >> 4;                        
unsignedTemp = unsignedTemp & 0xF;                             
CANMMCAN_2_RX_Msg_11_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_AlarmPriority */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_11_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_AlarmReaction */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_11_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_EtsSimpleStatus */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_11_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_SupplyVoltageSimpleState */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xF;                             
CANMMCAN_2_RX_Msg_11_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_SpeedSignalSimpleStatus */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp >> 4;                        
unsignedTemp = unsignedTemp & 0xF;                             
CANMMCAN_2_RX_Msg_11_Sgn_10 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_KL15State */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp >> 1;                        
unsignedTemp = unsignedTemp & 0x1;                             
CANMMCAN_2_RX_Msg_11_Sgn_11 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* ETSS_TableNumber */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_11_Sgn_12 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((boolean_T*) ssGetOutputPortSignal(S, 46))[0] = CANMMCAN_2_RX_Msg_11_Sgn_1;
((boolean_T*) ssGetOutputPortSignal(S, 47))[0] = CANMMCAN_2_RX_Msg_11_Sgn_2;
((boolean_T*) ssGetOutputPortSignal(S, 48))[0] = CANMMCAN_2_RX_Msg_11_Sgn_3;
((boolean_T*) ssGetOutputPortSignal(S, 49))[0] = CANMMCAN_2_RX_Msg_11_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 50))[0] = CANMMCAN_2_RX_Msg_11_Sgn_5;
((uint8_T*) ssGetOutputPortSignal(S, 51))[0] = CANMMCAN_2_RX_Msg_11_Sgn_6;
((uint8_T*) ssGetOutputPortSignal(S, 52))[0] = CANMMCAN_2_RX_Msg_11_Sgn_7;
((uint8_T*) ssGetOutputPortSignal(S, 53))[0] = CANMMCAN_2_RX_Msg_11_Sgn_8;
((uint8_T*) ssGetOutputPortSignal(S, 54))[0] = CANMMCAN_2_RX_Msg_11_Sgn_9;
((uint8_T*) ssGetOutputPortSignal(S, 55))[0] = CANMMCAN_2_RX_Msg_11_Sgn_10;
((boolean_T*) ssGetOutputPortSignal(S, 56))[0] = CANMMCAN_2_RX_Msg_11_Sgn_11;
((uint8_T*) ssGetOutputPortSignal(S, 57))[0] = CANMMCAN_2_RX_Msg_11_Sgn_12;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* ETSS_SteeringState */
CANMMCAN_2_TX_Msg_11_Sgn_1 = CANMMCAN_2_TX_Msg_11_Sgn_1_constant;

/* ETSS_AlarmState */
CANMMCAN_2_TX_Msg_11_Sgn_2 = CANMMCAN_2_TX_Msg_11_Sgn_2_constant;

/* ETSS_DiagnosticState */
CANMMCAN_2_TX_Msg_11_Sgn_3 = CANMMCAN_2_TX_Msg_11_Sgn_3_constant;

/* ETSS_CentringState */
CANMMCAN_2_TX_Msg_11_Sgn_4 = CANMMCAN_2_TX_Msg_11_Sgn_4_constant;

/* ETSS_SteerMode */
CANMMCAN_2_TX_Msg_11_Sgn_5 = CANMMCAN_2_TX_Msg_11_Sgn_5_constant;

/* ETSS_AlarmPriority */
CANMMCAN_2_TX_Msg_11_Sgn_6 = CANMMCAN_2_TX_Msg_11_Sgn_6_constant;

/* ETSS_AlarmReaction */
CANMMCAN_2_TX_Msg_11_Sgn_7 = CANMMCAN_2_TX_Msg_11_Sgn_7_constant;

/* ETSS_EtsSimpleStatus */
CANMMCAN_2_TX_Msg_11_Sgn_8 = CANMMCAN_2_TX_Msg_11_Sgn_8_constant;

/* ETSS_SupplyVoltageSimpleState */
CANMMCAN_2_TX_Msg_11_Sgn_9 = CANMMCAN_2_TX_Msg_11_Sgn_9_constant;

/* ETSS_SpeedSignalSimpleStatus */
CANMMCAN_2_TX_Msg_11_Sgn_10 = CANMMCAN_2_TX_Msg_11_Sgn_10_constant;

/* ETSS_KL15State */
CANMMCAN_2_TX_Msg_11_Sgn_11 = CANMMCAN_2_TX_Msg_11_Sgn_11_constant;

/* ETSS_TableNumber */
CANMMCAN_2_TX_Msg_11_Sgn_12 = CANMMCAN_2_TX_Msg_11_Sgn_12_constant;
/* ETSS_SteeringState */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x1 << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_AlarmState */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 1;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x1 << 1))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_DiagnosticState */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 2;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x1 << 2))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_CentringState */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 3;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0x1 << 3))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_SteerMode */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xF)) << 4;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xF << 4))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_AlarmPriority */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_6 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_AlarmReaction */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_7 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_EtsSimpleStatus */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_8 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_SupplyVoltageSimpleState */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_9 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xF << 0))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_SpeedSignalSimpleStatus */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_10 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xF)) << 4;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xF << 4))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_KL15State */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_11 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 1;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0x1 << 1))) | INT8_TO_LE(unsignedTemp);               

/* ETSS_TableNumber */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_11_Sgn_12 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[12], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[12];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[12];  
CANMMCAN_2_TXsta[12] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- OilSupplyAssignmentMessage  -----*/  
void RTICANMM_MAIN_CAN_2_copy_OilSupplyAssignmentMessage(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[18] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[18] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[18] = 0;                                             
CANMMCAN_2_RXSA[18] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[18] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[18] = data->CANMsg.Dlc;                                  
                                                                
/* OSAM_Press */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_12_Sgn_1 = (double)0.02 * (double)unsignedTemp + (double)(0);                    

/* OSAM_Flow */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_12_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* OSAM_Pump */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_12_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* OSAM_Prio */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_12_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((real_T*) ssGetOutputPortSignal(S, 58))[0] = CANMMCAN_2_RX_Msg_12_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 59))[0] = CANMMCAN_2_RX_Msg_12_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 60))[0] = CANMMCAN_2_RX_Msg_12_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 61))[0] = CANMMCAN_2_RX_Msg_12_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* OSAM_Press */
CANMMCAN_2_TX_Msg_12_Sgn_1 = CANMMCAN_2_TX_Msg_12_Sgn_1_constant;

/* OSAM_Flow */
CANMMCAN_2_TX_Msg_12_Sgn_2 = CANMMCAN_2_TX_Msg_12_Sgn_2_constant;

/* OSAM_Pump */
CANMMCAN_2_TX_Msg_12_Sgn_3 = CANMMCAN_2_TX_Msg_12_Sgn_3_constant;

/* OSAM_Prio */
CANMMCAN_2_TX_Msg_12_Sgn_4 = CANMMCAN_2_TX_Msg_12_Sgn_4_constant;
/* OSAM_Press */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_12_Sgn_1 - (0)) / ((double)0.02)) + (CANMMCAN_2_TX_Msg_12_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* OSAM_Flow */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_12_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* OSAM_Pump */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_12_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* OSAM_Prio */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_12_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[18], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[18];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[18];  
CANMMCAN_2_TXsta[18] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- OilSupplyRequestMessage  -----*/  
void RTICANMM_MAIN_CAN_2_copy_OilSupplyRequestMessage(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[17] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[17] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[17] = 0;                                             
CANMMCAN_2_RXSA[17] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[17] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[17] = data->CANMsg.Dlc;                                  
                                                                
/* OSRM_Press */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_13_Sgn_1 = (double)0.02 * (double)unsignedTemp + (double)(0);                    

/* OSRM_Flow */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_13_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* OSRM_Pump */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_13_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* OSRM_Prio */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_13_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((real_T*) ssGetOutputPortSignal(S, 62))[0] = CANMMCAN_2_RX_Msg_13_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 63))[0] = CANMMCAN_2_RX_Msg_13_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 64))[0] = CANMMCAN_2_RX_Msg_13_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 65))[0] = CANMMCAN_2_RX_Msg_13_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* OSRM_Press */
CANMMCAN_2_TX_Msg_13_Sgn_1 = CANMMCAN_2_TX_Msg_13_Sgn_1_constant;

/* OSRM_Flow */
CANMMCAN_2_TX_Msg_13_Sgn_2 = CANMMCAN_2_TX_Msg_13_Sgn_2_constant;

/* OSRM_Pump */
CANMMCAN_2_TX_Msg_13_Sgn_3 = CANMMCAN_2_TX_Msg_13_Sgn_3_constant;

/* OSRM_Prio */
CANMMCAN_2_TX_Msg_13_Sgn_4 = CANMMCAN_2_TX_Msg_13_Sgn_4_constant;
/* OSRM_Press */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_13_Sgn_1 - (0)) / ((double)0.02)) + (CANMMCAN_2_TX_Msg_13_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* OSRM_Flow */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_13_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* OSRM_Pump */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_13_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* OSRM_Prio */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_13_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[17], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[17];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[17];  
CANMMCAN_2_TXsta[17] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PowersupplyVoltageMessage1  -----*/  
void RTICANMM_MAIN_CAN_2_copy_PowersupplyVoltageMessage1(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[6] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[6] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[6] = 0;                                             
CANMMCAN_2_RXSA[6] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[6] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[6] = data->CANMsg.Dlc;                                  
                                                                
/* PSV_SupV1_KL15 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_14_Sgn_1 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* PSV_SupV2_KL30 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_14_Sgn_2 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* PSV_SupV3_KL1530 */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_14_Sgn_3 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* PSV_SupV4_Internal5V */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_14_Sgn_4 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

((real_T*) ssGetOutputPortSignal(S, 66))[0] = CANMMCAN_2_RX_Msg_14_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 67))[0] = CANMMCAN_2_RX_Msg_14_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 68))[0] = CANMMCAN_2_RX_Msg_14_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 69))[0] = CANMMCAN_2_RX_Msg_14_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* PSV_SupV1_KL15 */
CANMMCAN_2_TX_Msg_14_Sgn_1 = CANMMCAN_2_TX_Msg_14_Sgn_1_constant;

/* PSV_SupV2_KL30 */
CANMMCAN_2_TX_Msg_14_Sgn_2 = CANMMCAN_2_TX_Msg_14_Sgn_2_constant;

/* PSV_SupV3_KL1530 */
CANMMCAN_2_TX_Msg_14_Sgn_3 = CANMMCAN_2_TX_Msg_14_Sgn_3_constant;

/* PSV_SupV4_Internal5V */
CANMMCAN_2_TX_Msg_14_Sgn_4 = CANMMCAN_2_TX_Msg_14_Sgn_4_constant;
/* PSV_SupV1_KL15 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_14_Sgn_1 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_14_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* PSV_SupV2_KL30 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_14_Sgn_2 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_14_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* PSV_SupV3_KL1530 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_14_Sgn_3 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_14_Sgn_3 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* PSV_SupV4_Internal5V */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_14_Sgn_4 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_14_Sgn_4 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[6], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[6];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[6];  
CANMMCAN_2_TXsta[6] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PowersupplyVoltageMessage2  -----*/  
void RTICANMM_MAIN_CAN_2_copy_PowersupplyVoltageMessage2(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[7] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[7] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[7] = 0;                                             
CANMMCAN_2_RXSA[7] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[7] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[7] = data->CANMsg.Dlc;                                  
                                                                
/* PSV_SupV5_Internal6V */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_15_Sgn_1 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* PSV_SupV6_2VRef */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_15_Sgn_2 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* PSV_SupV7_AngleSensor */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_15_Sgn_3 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

/* PSV_SupV8_PressureSensor */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFFFF;                             
CANMMCAN_2_RX_Msg_15_Sgn_4 = (double)0.01 * (double)unsignedTemp + (double)(0);                    

((real_T*) ssGetOutputPortSignal(S, 70))[0] = CANMMCAN_2_RX_Msg_15_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 71))[0] = CANMMCAN_2_RX_Msg_15_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 72))[0] = CANMMCAN_2_RX_Msg_15_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 73))[0] = CANMMCAN_2_RX_Msg_15_Sgn_4;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* PSV_SupV5_Internal6V */
CANMMCAN_2_TX_Msg_15_Sgn_1 = CANMMCAN_2_TX_Msg_15_Sgn_1_constant;

/* PSV_SupV6_2VRef */
CANMMCAN_2_TX_Msg_15_Sgn_2 = CANMMCAN_2_TX_Msg_15_Sgn_2_constant;

/* PSV_SupV7_AngleSensor */
CANMMCAN_2_TX_Msg_15_Sgn_3 = CANMMCAN_2_TX_Msg_15_Sgn_3_constant;

/* PSV_SupV8_PressureSensor */
CANMMCAN_2_TX_Msg_15_Sgn_4 = CANMMCAN_2_TX_Msg_15_Sgn_4_constant;
/* PSV_SupV5_Internal6V */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_15_Sgn_1 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_15_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* PSV_SupV6_2VRef */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_15_Sgn_2 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_15_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[2]) = (*((UInt16*)&data->pData[2]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* PSV_SupV7_AngleSensor */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_15_Sgn_3 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_15_Sgn_3 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[4]) = (*((UInt16*)&data->pData[4]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* PSV_SupV8_PressureSensor */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_15_Sgn_4 - (0)) / ((double)0.01)) + (CANMMCAN_2_TX_Msg_15_Sgn_4 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                             
*((UInt16*)&data->pData[6]) = (*((UInt16*)&data->pData[6]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[7], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[7];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[7];  
CANMMCAN_2_TXsta[7] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- ResistanceMeasurementOutputs  -----*/  
void RTICANMM_MAIN_CAN_2_copy_ResistanceMeasurementOutputs(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[3] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[3] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[3] = 0;                                             
CANMMCAN_2_RXSA[3] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[3] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[3] = data->CANMsg.Dlc;                                  
                                                                
/* RMO_Output1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_16_Sgn_1 = (double)0.25 * (double)unsignedTemp + (double)(0);                    

/* RMO_Output2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_16_Sgn_2 = (double)0.25 * (double)unsignedTemp + (double)(0);                    

/* RMO_Output3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_16_Sgn_3 = (double)0.25 * (double)unsignedTemp + (double)(0);                    

/* RMO_Output4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_16_Sgn_4 = (double)0.25 * (double)unsignedTemp + (double)(0);                    

/* RMO_Output5 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_16_Sgn_5 = (double)0.25 * (double)unsignedTemp + (double)(0);                    

/* RMO_Output6 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_16_Sgn_6 = (double)0.25 * (double)unsignedTemp + (double)(0);                    

/* RMO_Output7 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_16_Sgn_7 = (double)0.25 * (double)unsignedTemp + (double)(0);                    

/* RMO_Output8 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_16_Sgn_8 = (double)0.25 * (double)unsignedTemp + (double)(0);                    

((real_T*) ssGetOutputPortSignal(S, 74))[0] = CANMMCAN_2_RX_Msg_16_Sgn_1;
((real_T*) ssGetOutputPortSignal(S, 75))[0] = CANMMCAN_2_RX_Msg_16_Sgn_2;
((real_T*) ssGetOutputPortSignal(S, 76))[0] = CANMMCAN_2_RX_Msg_16_Sgn_3;
((real_T*) ssGetOutputPortSignal(S, 77))[0] = CANMMCAN_2_RX_Msg_16_Sgn_4;
((real_T*) ssGetOutputPortSignal(S, 78))[0] = CANMMCAN_2_RX_Msg_16_Sgn_5;
((real_T*) ssGetOutputPortSignal(S, 79))[0] = CANMMCAN_2_RX_Msg_16_Sgn_6;
((real_T*) ssGetOutputPortSignal(S, 80))[0] = CANMMCAN_2_RX_Msg_16_Sgn_7;
((real_T*) ssGetOutputPortSignal(S, 81))[0] = CANMMCAN_2_RX_Msg_16_Sgn_8;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* RMO_Output1 */
CANMMCAN_2_TX_Msg_16_Sgn_1 = CANMMCAN_2_TX_Msg_16_Sgn_1_constant;

/* RMO_Output2 */
CANMMCAN_2_TX_Msg_16_Sgn_2 = CANMMCAN_2_TX_Msg_16_Sgn_2_constant;

/* RMO_Output3 */
CANMMCAN_2_TX_Msg_16_Sgn_3 = CANMMCAN_2_TX_Msg_16_Sgn_3_constant;

/* RMO_Output4 */
CANMMCAN_2_TX_Msg_16_Sgn_4 = CANMMCAN_2_TX_Msg_16_Sgn_4_constant;

/* RMO_Output5 */
CANMMCAN_2_TX_Msg_16_Sgn_5 = CANMMCAN_2_TX_Msg_16_Sgn_5_constant;

/* RMO_Output6 */
CANMMCAN_2_TX_Msg_16_Sgn_6 = CANMMCAN_2_TX_Msg_16_Sgn_6_constant;

/* RMO_Output7 */
CANMMCAN_2_TX_Msg_16_Sgn_7 = CANMMCAN_2_TX_Msg_16_Sgn_7_constant;

/* RMO_Output8 */
CANMMCAN_2_TX_Msg_16_Sgn_8 = CANMMCAN_2_TX_Msg_16_Sgn_8_constant;
/* RMO_Output1 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_16_Sgn_1 - (0)) / ((double)0.25)) + (CANMMCAN_2_TX_Msg_16_Sgn_1 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RMO_Output2 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_16_Sgn_2 - (0)) / ((double)0.25)) + (CANMMCAN_2_TX_Msg_16_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RMO_Output3 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_16_Sgn_3 - (0)) / ((double)0.25)) + (CANMMCAN_2_TX_Msg_16_Sgn_3 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RMO_Output4 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_16_Sgn_4 - (0)) / ((double)0.25)) + (CANMMCAN_2_TX_Msg_16_Sgn_4 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RMO_Output5 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_16_Sgn_5 - (0)) / ((double)0.25)) + (CANMMCAN_2_TX_Msg_16_Sgn_5 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RMO_Output6 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_16_Sgn_6 - (0)) / ((double)0.25)) + (CANMMCAN_2_TX_Msg_16_Sgn_6 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[5]) = (*((UInt8*)&data->pData[5]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RMO_Output7 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_16_Sgn_7 - (0)) / ((double)0.25)) + (CANMMCAN_2_TX_Msg_16_Sgn_7 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* RMO_Output8 */ 
unsignedTemp = (((CANMMCAN_2_TX_Msg_16_Sgn_8 - (0)) / ((double)0.25)) + (CANMMCAN_2_TX_Msg_16_Sgn_8 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[3], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[3];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[3];  
CANMMCAN_2_TXsta[3] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- SpeedMessage  -----*/  
void RTICANMM_MAIN_CAN_2_copy_SpeedMessage(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[2] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[2] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[2] = 0;                                             
CANMMCAN_2_RXSA[2] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[2] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[2] = data->CANMsg.Dlc;                                  
                                                                
/* SPEED_EtsSpeed */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_17_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SPEED_SecondMicroSpeed */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_17_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SPEED_MidPointHysteresis */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
if (unsignedTemp & 0x80) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_2_RX_Msg_17_Sgn_3 = (Int8)1 * (Int8)signedTemp + (Int8)(0);                    

/* SPEED_SpeedValidIndication */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
if (unsignedTemp & 0x80) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_2_RX_Msg_17_Sgn_4 = (Int8)1 * (Int8)signedTemp + (Int8)(0);                    

/* SPEED_LeadSpeed */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
if (unsignedTemp & 0x80) /* extend sign */      
  unsignedTemp = unsignedTemp | 0xFFFFFF00;                     
signedTemp = *((Int32*)&unsignedTemp);                     
CANMMCAN_2_RX_Msg_17_Sgn_5 = (Int8)1 * (Int8)signedTemp + (Int8)(0);                    

((uint8_T*) ssGetOutputPortSignal(S, 82))[0] = CANMMCAN_2_RX_Msg_17_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 83))[0] = CANMMCAN_2_RX_Msg_17_Sgn_2;
((int8_T*) ssGetOutputPortSignal(S, 84))[0] = CANMMCAN_2_RX_Msg_17_Sgn_3;
((int8_T*) ssGetOutputPortSignal(S, 85))[0] = CANMMCAN_2_RX_Msg_17_Sgn_4;
((int8_T*) ssGetOutputPortSignal(S, 86))[0] = CANMMCAN_2_RX_Msg_17_Sgn_5;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* SPEED_EtsSpeed */
CANMMCAN_2_TX_Msg_17_Sgn_1 = CANMMCAN_2_TX_Msg_17_Sgn_1_constant;

/* SPEED_SecondMicroSpeed */
CANMMCAN_2_TX_Msg_17_Sgn_2 = CANMMCAN_2_TX_Msg_17_Sgn_2_constant;

/* SPEED_MidPointHysteresis */
CANMMCAN_2_TX_Msg_17_Sgn_3 = CANMMCAN_2_TX_Msg_17_Sgn_3_constant;

/* SPEED_SpeedValidIndication */
CANMMCAN_2_TX_Msg_17_Sgn_4 = CANMMCAN_2_TX_Msg_17_Sgn_4_constant;

/* SPEED_LeadSpeed */
CANMMCAN_2_TX_Msg_17_Sgn_5 = CANMMCAN_2_TX_Msg_17_Sgn_5_constant;
/* SPEED_EtsSpeed */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_17_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SPEED_SecondMicroSpeed */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_17_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SPEED_MidPointHysteresis */ 
signedTemp = (CANMMCAN_2_TX_Msg_17_Sgn_3 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SPEED_SpeedValidIndication */ 
signedTemp = (CANMMCAN_2_TX_Msg_17_Sgn_4 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SPEED_LeadSpeed */ 
signedTemp = (CANMMCAN_2_TX_Msg_17_Sgn_5 );                                
unsignedTemp = ((UInt32)(signedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[2], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[2];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[2];  
CANMMCAN_2_TXsta[2] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- StatusHighOutputPins  -----*/  
void RTICANMM_MAIN_CAN_2_copy_StatusHighOutputPins(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[4] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[4] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[4] = 0;                                             
CANMMCAN_2_RXSA[4] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[4] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[4] = data->CANMsg.Dlc;                                  
                                                                
/* SHO_Output1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_18_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SHO_Output2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_18_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SHO_Output3 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_18_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SHO_Output4 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_18_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SHO_Output5 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_18_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SHO_Output6 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_18_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SHO_Output7 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_18_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SHO_Output8 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (7)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_18_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((uint8_T*) ssGetOutputPortSignal(S, 87))[0] = CANMMCAN_2_RX_Msg_18_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 88))[0] = CANMMCAN_2_RX_Msg_18_Sgn_2;
((uint8_T*) ssGetOutputPortSignal(S, 89))[0] = CANMMCAN_2_RX_Msg_18_Sgn_3;
((uint8_T*) ssGetOutputPortSignal(S, 90))[0] = CANMMCAN_2_RX_Msg_18_Sgn_4;
((uint8_T*) ssGetOutputPortSignal(S, 91))[0] = CANMMCAN_2_RX_Msg_18_Sgn_5;
((uint8_T*) ssGetOutputPortSignal(S, 92))[0] = CANMMCAN_2_RX_Msg_18_Sgn_6;
((uint8_T*) ssGetOutputPortSignal(S, 93))[0] = CANMMCAN_2_RX_Msg_18_Sgn_7;
((uint8_T*) ssGetOutputPortSignal(S, 94))[0] = CANMMCAN_2_RX_Msg_18_Sgn_8;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* SHO_Output1 */
CANMMCAN_2_TX_Msg_18_Sgn_1 = CANMMCAN_2_TX_Msg_18_Sgn_1_constant;

/* SHO_Output2 */
CANMMCAN_2_TX_Msg_18_Sgn_2 = CANMMCAN_2_TX_Msg_18_Sgn_2_constant;

/* SHO_Output3 */
CANMMCAN_2_TX_Msg_18_Sgn_3 = CANMMCAN_2_TX_Msg_18_Sgn_3_constant;

/* SHO_Output4 */
CANMMCAN_2_TX_Msg_18_Sgn_4 = CANMMCAN_2_TX_Msg_18_Sgn_4_constant;

/* SHO_Output5 */
CANMMCAN_2_TX_Msg_18_Sgn_5 = CANMMCAN_2_TX_Msg_18_Sgn_5_constant;

/* SHO_Output6 */
CANMMCAN_2_TX_Msg_18_Sgn_6 = CANMMCAN_2_TX_Msg_18_Sgn_6_constant;

/* SHO_Output7 */
CANMMCAN_2_TX_Msg_18_Sgn_7 = CANMMCAN_2_TX_Msg_18_Sgn_7_constant;

/* SHO_Output8 */
CANMMCAN_2_TX_Msg_18_Sgn_8 = CANMMCAN_2_TX_Msg_18_Sgn_8_constant;
/* SHO_Output1 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_18_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SHO_Output2 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_18_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SHO_Output3 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_18_Sgn_3 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SHO_Output4 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_18_Sgn_4 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[3]) = (*((UInt8*)&data->pData[3]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SHO_Output5 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_18_Sgn_5 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[4]) = (*((UInt8*)&data->pData[4]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SHO_Output6 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_18_Sgn_6 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[5]) = (*((UInt8*)&data->pData[5]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SHO_Output7 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_18_Sgn_7 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[6]) = (*((UInt8*)&data->pData[6]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SHO_Output8 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_18_Sgn_8 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[4], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[4];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[4];  
CANMMCAN_2_TXsta[4] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- StatusLowOutputPins  -----*/  
void RTICANMM_MAIN_CAN_2_copy_StatusLowOutputPins(MainSetupMsgData* data, int direction, SimStruct *S)
{
 
if (direction == RX) {                                          
  CANMMCAN_2_MIDFRX[5] = (int)data->CANMsg.Format;                            
  
                                                            
CANMMCAN_2_RXSNIDX[5] = J1939FindNode(data->SrcNode);                      
CANMMCAN_2_RXDNIDX[5] = 0;                                             
CANMMCAN_2_RXSA[5] = data->SrcAddress;                                  
CANMMCAN_2_RXDA[5] = data->DestAddress;                                 
                                                                
    /* Decode message data */                                   
    CANMMCAN_2_RXLEN[5] = data->CANMsg.Dlc;                                  
                                                                
/* SLO_Output1 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_19_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

/* SLO_Output2 */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
unsignedTemp = unsignedTemp & 0xFF;                             
CANMMCAN_2_RX_Msg_19_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

((uint8_T*) ssGetOutputPortSignal(S, 95))[0] = CANMMCAN_2_RX_Msg_19_Sgn_1;
((uint8_T*) ssGetOutputPortSignal(S, 96))[0] = CANMMCAN_2_RX_Msg_19_Sgn_2;
}      
else {  /* TX ========================================================================================== */ 
/* Init encode structure */                                 
*((UInt32*)data->pData) = INT32_TO_BE(0x00000000);              
*((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);          

/* SLO_Output1 */
CANMMCAN_2_TX_Msg_19_Sgn_1 = CANMMCAN_2_TX_Msg_19_Sgn_1_constant;

/* SLO_Output2 */
CANMMCAN_2_TX_Msg_19_Sgn_2 = CANMMCAN_2_TX_Msg_19_Sgn_2_constant;
/* SLO_Output1 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_19_Sgn_1 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[0]) = (*((UInt8*)&data->pData[0]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               

/* SLO_Output2 */ 
unsignedTemp = (CANMMCAN_2_TX_Msg_19_Sgn_2 );                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFF)) << 0;                             
*((UInt8*)&data->pData[1]) = (*((UInt8*)&data->pData[1]) & INT8_TO_LE(~(0xFF << 0))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_2_TXLEN[5], (uint32_T)1785, (uint32_T)0);

  data->CANMsg.Id = CANMMCAN_2_MIDRX[5];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_2_MIDFTX[5];  
CANMMCAN_2_TXsta[5] = 1;                                       
} /* TX */
}


