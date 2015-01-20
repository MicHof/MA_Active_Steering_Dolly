/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_2_J1939DEFS */
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

                                                                                                         
                                                                                                         
#include <dsRTICANMMGlobals.h>                                                                           
#include <DsJ1939Ch.h>                                                                                   
#include <DsJ1939Node.h>                                                                                 
#include <J1939Tp.h>                                                                                     
                                                                                                         
                                                                                                         
/* J1939 channel: */                                                                                     
static DsTJ1939Ch J1939Channel = NULL;                                                                   
static DsSJ1939_Msg J1939Msg;                                                                            
static DsSJ1939_Frame J1939Frame;                                                                        
static UInt8 J1939MsgData[J1939_MSG_DATA_LENGTH];                                                        
                                                                                                         
#define J1939_BROADCAST_ADDRESS         255                                                              
#define J1939_BROADCAST_INDEX           1                                                               
#define J1939_NODE_COUNT                2                                                               
#define J1939_ILLEGAL_NODE_ADDRESS      254                                                              
#define J1939_ILLEGAL_NODE_INDEX        2                                                               
#define J1939_NODE_MAP_SIZE             3                                                               
                                                                                                         
                                                                                                         
/* J1939 node information: */                                                                        
static DsTJ1939Node J1939Nodes[J1939_NODE_COUNT];                                                    
UInt8 RTICANMM_MAIN_CAN_2_J1939NodeIndex[J1939_NODE_COUNT-1];                                                         
UInt8 RTICANMM_MAIN_CAN_2_J1939NodeSimulationMode[J1939_NODE_COUNT-1];                                                
UInt8 RTICANMM_MAIN_CAN_2_J1939NodeAddress[J1939_NODE_COUNT+1]= { 253, 
                              J1939_BROADCAST_ADDRESS, 
                              J1939_ILLEGAL_NODE_ADDRESS };                                               
UInt8 RTICANMM_MAIN_CAN_2_J1939NodeStatus[J1939_NODE_COUNT-1]= { 3 };                                                
UInt8 RTICANMM_MAIN_CAN_2_J1939InitNodeAddress[J1939_NODE_COUNT-1] = { 253 };                                          
static UInt8 J1939NodeMap[3] = { J1939_ILLEGAL_NODE_INDEX, 
                          0, 
                          J1939_BROADCAST_INDEX };                                                              
static ULong64 J1939ECUNAME[J1939_NODE_COUNT-1];                                                     
static DsSJ1939Node_Name J1939ECUNAMEParts[J1939_NODE_COUNT-1];                                      
static char * NodeDesc[J1939_NODE_COUNT-1] = { "Vector__XXX" };                                                 
static DsEJ1939Node_Type NodeType[J1939_NODE_COUNT-1] = { DSJ1939_NODE_TYPE_NONRELEVANT };                                      
static UInt8 J1939NmEnabled[J1939_NODE_COUNT-1] = { 0 };                                            
                                                                                                         
                                                                                                         
/* Initialize pointer for trace access: */                                                               
UInt8* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_ArbitraryAddressCapable;                                          
UInt8* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_IndustryGroup;                                                    
UInt8* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_VehicleSystemInstance;                                            
UInt8* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_VehicleSystem;                                                    
UInt8* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_Reserved;                                                         
UInt8* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_Function;                                                         
UInt8* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_FunctionInstance;                                                 
UInt8* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_ECUInstance;                                                      
UInt16* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_ManufacturerCode;                                                
UInt32* RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_IdentityNumber;                                                  
                                                                                                         
                                                                                                         
/* J1939 Callback for changed node address: */                                                           
static void                                                                                              
J1939NmCb(ULong64 Name, UInt8 Address, const void* Arg) {                                                
#if RTICANMM_LOGLEVEL > 3                                                                                
    msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_NMCB_INFO, RTICANMM_J1939_NMCB_INFO_TXT,              
        "CAN_2",                                                                                            
        __FUNCTION__,                                                                                    
        (UInt32)(Name >> 32),                                                                            
        (UInt32)Name,                                                                                    
        Address);                                                                                        
#endif                                                                                                   
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 Transmit function called by mdlOutputs: */                                                  
static void                                                                                          
J1939Transmit(int MsgIdx) {                                                                          
  UInt8 SnIdx  = J1939_ILLEGAL_NODE_INDEX;                                                           
  UInt8 DnIdx  = J1939_ILLEGAL_NODE_INDEX;                                                           
  UInt8 isPDU1 = 0;                                                                                  
                                                                                                     
  J1939Msg.Pgn  = CANMMCAN_2_MIDRX[ID_Table_TX(MsgIdx)];                                                           
  isPDU1        = J1939_IS_PDU1(J1939Msg.Pgn << 8);                                                  
                                                                                                     
#if RTICANMM_LOGLEVEL > 3                                                                            
  msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,          
                      __FUNCTION__, "CAN_2 - MsgIdx", MsgIdx);                                          
  msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,          
                      __FUNCTION__, "CAN_2 - Pgn", J1939Msg.Pgn);                                       
#endif                                                                                               
                                                                                                     
  J1939Msg.Priority    = CANMMCAN_2_TXPRIO[ID_Table_TX(MsgIdx)];                                                    
  J1939Msg.Dlc         = MsgData.CANMsg.Dlc;                                                         
  J1939Msg.pData       = MsgData.pData;                                                              
  J1939Msg.Mode        = DSJ1939_MSG_MODE_NORMAL;                                                    
                                                                                                     
  /* J1939 address based transmission */                                                             
  J1939Msg.SrcNode     = NULL;                                                                       
  J1939Msg.DestNode    = NULL;                                                                       
  J1939Msg.SrcAddress  = CANMMCAN_2_TXSA[ID_Table_TX(MsgIdx)];                                                    
  J1939Msg.DestAddress = CANMMCAN_2_TXDA[ID_Table_TX(MsgIdx)];                                                    
                                                                                                     
  if (CANMMCAN_2_TXSNIDX[ID_Table_TX(MsgIdx)] < J1939_NODE_MAP_SIZE) {                                               
    SnIdx = J1939NodeMap[CANMMCAN_2_TXSNIDX[ID_Table_TX(MsgIdx)]];                                                   
  }                                                                                                  
  if (isPDU1 && CANMMCAN_2_TXDNIDX[ID_Table_TX(MsgIdx)] < J1939_NODE_MAP_SIZE) {                                     
    DnIdx = J1939NodeMap[CANMMCAN_2_TXDNIDX[ID_Table_TX(MsgIdx)]];                                                   
  }                                                                                                  
                                                                                                     
  /* J1939 node index based transmission if configured on 'J1939 TX ID' page */                             
  /* or enabled network management for src/dest node */                                              
  if (SRC_Addressing_Switch(MsgIdx) == 1) {                                                          
    if (J1939_BROADCAST_INDEX == SnIdx || J1939_ILLEGAL_NODE_INDEX == SnIdx) {                       
      return;                                                                                        
    }                                                                                                
                                                                                                     
    J1939Msg.SrcNode  = J1939Nodes[SnIdx];                                                           
    J1939Msg.SrcAddress  = RTICANMM_MAIN_CAN_2_J1939NodeAddress[SnIdx];                                               
  }                                                                                                  
                                                                                                     
  if (DEST_Addressing_Switch(MsgIdx) == 1) {                                                         
    if (isPDU1 && J1939_ILLEGAL_NODE_INDEX == DnIdx) {                                               
      return;                                                                                        
    }                                                                                                
                                                                                                     
    J1939Msg.DestNode = NULL;                                                                        
    J1939Msg.DestAddress = J1939_BROADCAST_ADDRESS;                                                  
    if (isPDU1) {                                                                                    
      J1939Msg.DestNode = J1939Nodes[DnIdx];                                                         
      J1939Msg.DestAddress = RTICANMM_MAIN_CAN_2_J1939NodeAddress[DnIdx];                                             
    }                                                                                                
  }                                                                                                  
                                                                                                     
  J1939Tp_Transmit (J1939Channel, &J1939Msg);                                                        
                                                                                                     
#if RTICANMM_LOGLEVEL > 3                                                                            
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,
                                __FUNCTION__, "CAN_2 - Dlc", MsgData.CANMsg.Dlc);                       
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,
                                __FUNCTION__, "CAN_2 - Src Addressing (0 Address / 1 Node Index)", SRC_Addressing_Switch(MsgIdx));  
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,
                                __FUNCTION__, "CAN_2 - Dest Addressing (0 Address / 1 Node Index)", DEST_Addressing_Switch(MsgIdx));  
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,
                                __FUNCTION__, "CAN_2 - SrcAddress", J1939Msg.SrcAddress);               
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,
                                __FUNCTION__, "CAN_2 - DestAddress", J1939Msg.DestAddress);             
#endif                                                                                               
                                                                                                     
}                                                                                                    
                                                                                                     
                                                                                                     
/* J1939 Check for possible transmission: */                                                         
static UInt8                                                                                         
J1939IsTransmissionPossible(int MsgIdx) {                                                            
  if (CANMMCAN_2_TXLEN[MsgIdx] <= 8) {                                                                             
    return 1;                                                                                        
  }                                                                                                  
  {                                                                                                  
    UInt8 SnIdx    = J1939_ILLEGAL_NODE_INDEX;                                                       
    UInt8 DnIdx    = J1939_BROADCAST_INDEX;                                                          
    UInt8 SrcAddr  = J1939_ILLEGAL_NODE_ADDRESS;                                                     
    UInt8 DestAddr = J1939_BROADCAST_ADDRESS;                                                        
    UInt8 isPDU1   = 0;                                                                              
                                                                                                     
    J1939Msg.Pgn    = CANMMCAN_2_MIDRX[ID_Table_TX(MsgIdx)];                                                       
    isPDU1          = J1939_IS_PDU1(J1939Msg.Pgn << 8);                                              
                                                                                                     
    if (CANMMCAN_2_TXSNIDX[ID_Table_TX(MsgIdx)] < J1939_NODE_MAP_SIZE) {                                             
      SnIdx    = J1939NodeMap[CANMMCAN_2_TXSNIDX[ID_Table_TX(MsgIdx)]];                                              
      SrcAddr  = RTICANMM_MAIN_CAN_2_J1939NodeAddress[SnIdx];                                                         
    }                                                                                                
                                                                                                     
    if (isPDU1 && CANMMCAN_2_TXDNIDX[ID_Table_TX(MsgIdx)] < J1939_NODE_MAP_SIZE) {                                   
      DnIdx    = J1939NodeMap[CANMMCAN_2_TXDNIDX[ID_Table_TX(MsgIdx)]];                                              
      DestAddr = RTICANMM_MAIN_CAN_2_J1939NodeAddress[DnIdx];                                                         
    }                                                                                                
                                                                                                     
    if (DSJ1939_NO_ERROR == (J1939Tp_IsStartTransmissionPossible (J1939Channel, SrcAddr, DestAddr))) {
#if RTICANMM_LOGLEVEL > 3                                                                            
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,
                                __FUNCTION__, "CAN_2 - TransmissionPossible", 1);                       
#endif                                                                                               
      return 1;                                                                                      
    }                                                                                                
                                                                                                     
    return 0;                                                                                        
  }                                                                                                  
}                                                                                                    
                                                                                                         
                                                                                                         
/* J1939 Find node index for given node: */                                                              
static UInt8                                                                                             
J1939FindNode(const DsTJ1939Node Node) {                                                                 
   int i = 0;                                                                                            
                                                                                                         
   for (i=1; i<J1939_NODE_MAP_SIZE; i++) {                                                               
     if ((J1939_ILLEGAL_NODE_INDEX != J1939NodeMap[i]) && (J1939Nodes[J1939NodeMap[i]] == Node)) {       
        return i;                                                                                        
     }                                                                                                   
   }                                                                                                     
   /* Return invalid node index */                                                                       
   return 0;                                                                                             
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 Receive function called by J1939 stack after a J1939 message has been received: */              
static void                                                                                              
J1939RxCb(const DsSJ1939_Msg* Msg, const void* Arg) {                                                    
    SimStruct* S = (SimStruct*) Arg;                                                                     
    void **PWork = ssGetPWork(S);                                                                        
    void (*copy_func) (MainSetupMsgData*, int, SimStruct*);                                              
    int pos = 0;                                                                                         
    int idIdx = -1;                                                                                      
    int cIdx  = -1;                                                                                      
    int isPDU2 = 0;                                                                                      
                                                                                                         
    isPDU2 = J1939_IS_PDU2((Msg->Pgn << 8));                                                             
                                                                                                         
    if (DSJ1939_MSG_STATUS_OK == Msg->Status) {                                                          
        for(pos = 0; pos < NUM_RX_MSG; pos++) {                                                          
            if (RTICANMM_MESSAGE_TYPE_J1939 == CANMMCAN_2_RXMT[pos] && CANMMCAN_2_RXPGN[pos] == Msg->Pgn) {                         
                UInt8 SrcAddr  = J1939_ILLEGAL_NODE_ADDRESS;                                             
                if (Msg->SrcNode == NULL) {                                                              
                    SrcAddr = CANMMCAN_2_RXSA[pos];                                                                   
                }                                                                                        
                else {                                                                                   
                    DsTJ1939Node SrcNode = J1939Nodes[J1939NodeMap[CANMMCAN_2_RXSNIDX[pos]]];                            
                    SrcAddr = RTICANMM_MAIN_CAN_2_J1939NodeAddress[J1939NodeMap[J1939FindNode(SrcNode)]];                 
                }                                                                                        
                if (SrcAddr == Msg->SrcAddress) {                                                        
                    UInt8 DestAddr = J1939_BROADCAST_ADDRESS;                                            
                    if (Msg->DestNode == NULL) {                                                         
                        if (Msg->DestAddress != J1939_BROADCAST_ADDRESS) {                               
                            DestAddr = CANMMCAN_2_RXDA[pos];                                                          
                        }                                                                                
                    }                                                                                    
                    else {                                                                               
                        DsTJ1939Node DestNode = J1939Nodes[J1939NodeMap[CANMMCAN_2_RXDNIDX[pos]]];                       
                        DestAddr = RTICANMM_MAIN_CAN_2_J1939NodeAddress[J1939NodeMap[J1939FindNode(DestNode)]];           
                    }                                                                                    
                    /* Only for PDU1 DestNode must match */                                              
                    if (isPDU2 || DestAddr == Msg->DestAddress) {                                        
                        if (1 != ID_Table_RXContainer(pos)) {                                            
                            idIdx = pos;                                                                 
                            break;                                                                       
                          }                                                                              
                      }                                                                                  
                  }                                                                                      
                                                                                                         
                /* Remember index of matching container */                                               
                if ((-1 == cIdx) && (1 == ID_Table_RXContainer(pos))) {                                  
                    cIdx = pos;                                                                          
                  }                                                                                      
              }                                                                                          
          } /* for all RX msgs */                                                                        
                                                                                                         
        /* Nothing found: look for container */                                                          
        if (-1 == idIdx) {                                                                               
          idIdx = cIdx;                                                                                  
        }                                                                                                
                                                                                                         
                                                                                                         
        if (-1 != idIdx) {                                                                               
            MsgData.SrcNode = Msg->SrcNode;                                                              
            MsgData.DestNode = Msg->DestNode;                                                            
            MsgData.SrcAddress = Msg->SrcAddress;                                                        
            MsgData.DestAddress = Msg->DestAddress;                                                      
            MsgData.CANMsg.Flags = 0;                                                                    
#if defined(RTICANMM_HAVE_RTK)                                                                                    
            MsgData.CANMsg.TimeStamp = rtk_dsts_time_to_simtime_convert(Msg->TimeStamp);                 
#else                                                                                                    
            MsgData.CANMsg.TimeStamp = (double) Msg->TimeStamp;                                          
#endif                                                                                                   
            MsgData.CANMsg.Dlc = Msg->Dlc;                                                               
            MsgData.CANMsg.Format = CANMM_MSG_FORMAT_EXT;                                                
                                                                                                         
            if (DSJ1939_DIR_TRANSMIT == Msg->Dir) {                                                      
                MsgData.CANMsg.Loopback = 1;                                                             
            }                                                                                            
                                                                                                         
            /* Set timeinfo and status */                                                                
            CANMMCAN_2_RXt[idIdx] = MsgData.CANMsg.TimeStamp;                                                        
                                                                                                         
            if (MsgData.CANMsg.Loopback) {                                                               
               CANMMCAN_2_RXdt[idIdx] = MsgData.CANMsg.TimeStamp - TX_OLDTIME[idIdx];                                 
               TX_OLDTIME[idIdx] = MsgData.CANMsg.TimeStamp;                                             
               CANMMCAN_2_RXsta[idIdx] = 1;                                                                        
            }                                                                                            
            else {                                                                                       
               CANMMCAN_2_RXdt[idIdx] = MsgData.CANMsg.TimeStamp - RX_OLDTIME[idIdx];                                 
               RX_OLDTIME[idIdx] = MsgData.CANMsg.TimeStamp;                                             
               CANMMCAN_2_RXsta[idIdx] = 1;                                                                            
            }                                                                                            
                                                                                                         
            CANMMCAN_2_RXPRIO[idIdx] = (int)Msg->Priority;                                                              
                                                                                                         
            MsgData.pData = Msg->pData;                                                                  
            copy_func = (void (*)(MainSetupMsgData *, int, SimStruct*)) ((UInt32*) IDPTR_MEM_R)[idIdx];  
            copy_func(&MsgData, RX, S);                                                                  
                                                                                                         
#if RTICANMM_LOGLEVEL > 3                                                                                
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,    
                                __FUNCTION__, "CAN_2 - Id", MsgData.CANMsg.Id);                             
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,    
                                __FUNCTION__, "CAN_2 - SrcAddress", Msg->SrcAddress);                       
            msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_DEBUG_INFO, RTICANMM_J1939_DEBUG_INFO_TXT,    
                                __FUNCTION__, "CAN_2 - DestAddress", Msg->DestAddress);                     
#endif                                                                                                   
        }                                                                                                
    }                                                                                                    
    else {                                                                                               
#if RTICANMM_LOGLEVEL > 3                                                                                
        msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_RXCB_INFO, RTICANMM_J1939_RXCB_INFO_TXT,          
                           "CAN_2", Msg->Status, Msg->Pgn);                                                 
#endif                                                                                                   
    }                                                                                                    
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 Transmit function called by J1939 stack                                                         
 * Return: DSJ1939_TX_OK, if message could be send                                                       
 *         DSJ1939_TX_FAILED, otherwise                                                                  
 */                                                                                                      
static DsEJ1939_TxState                                                                                  
J1939TxCb(const DsSJ1939_Frame* Frame, const void* Arg) {                                                
    UInt32 i;                                                                                            
                                                                                                         
    MsgData.CANMsg.Id = Frame->Id;                                                                       
    MsgData.CANMsg.Dlc = Frame->Dlc;                                                                     
    MsgData.CANMsg.Format = CANMM_MSG_FORMAT_EXT;                                                        
                                                                                                         
    for (i = 0; i < 8; i++) {                                                                            
        MsgData.CANMsg.Data[i] = Frame->Data[i];                                                         
    }                                                                                                    
                                                                                                         
    CANMM_CTL_TX(CANMM_CONTROLLER_ID, &ctlsetup_client, &MsgData.CANMsg);                                
                                                                                                         
    return DSJ1939_TX_OK;                                                                                
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 ACC callback (used to get possible unused address for next claim): */                           
static UInt8                                                                                             
J1939AccCb(DsTJ1939Node Node, const void* Arg) {                                                         
    UInt8 CurrAddress, NewAddress;                                                                       
    DsEJ1939Node_State State;                                                                            
                                                                                                         
    DsJ1939Node_getState(Node, &State, &CurrAddress);                                                    
    DsJ1939Ch_getUnusedAddress(J1939Channel, &NewAddress);                                               
                                                                                                         
#if RTICANMM_LOGLEVEL > 3                                                                                
    msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_ACCCB_INFO, RTICANMM_J1939_ACCCB_INFO_TXT,            
                    "CAN_2", CurrAddress, NewAddress);                                                      
#endif                                                                                                   
                                                                                                         
    return NewAddress;                                                                                   
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 channel initialization: */                                                                      
static DsTJ1939Ch                                                                                        
J1939InitializeChannel(UInt32 NumFrames, UInt32 NumMsgs, UInt32 MaxDlc) {                                
    DsTJ1939Ch Ch = NULL;                                                                                
                                                                                                         
    J1939Tp_ControlAdditionalFunctionality(J1939TP_ON);                                                  
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_create(&Ch, (void*)&J1939Channel)) {                               
        return Ch;                                                                                       
    }                                                                                                    
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_setDescriptor(Ch, "CAN_2")) {                                         
        DsJ1939Ch_destroy(&Ch);                                                                          
        return Ch;                                                                                       
    }                                                                                                    
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_setMsgBuffer(Ch, NumMsgs, MaxDlc)) {                               
        DsJ1939Ch_destroy(&Ch);                                                                          
        return Ch;                                                                                       
    }                                                                                                    
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_setFrameBuffer(Ch, NumFrames)) {                                   
        DsJ1939Ch_destroy(&Ch);                                                                          
        return Ch;                                                                                       
    }                                                                                                    
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_apply(Ch)) {                                                       
        DsJ1939Ch_destroy(&Ch);                                                                          
        return Ch;                                                                                       
    }                                                                                                    
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_connectRxMonitorCb(Ch, J1939RxCb, NULL)) {                         
        DsJ1939Ch_destroy(&Ch);                                                                          
        return Ch;                                                                                       
    }                                                                                                    
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_connectTxCb(Ch, J1939TxCb, NULL)) {                                
        DsJ1939Ch_destroy(&Ch);                                                                          
        return Ch;                                                                                       
    }                                                                                                    
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_connectNmCb(Ch, J1939NmCb, NULL)) {                                
        DsJ1939Ch_destroy(&Ch);                                                                          
        return Ch;                                                                                       
    }                                                                                                    
                                                                                                         
    if (DSJ1939_NO_ERROR != DsJ1939Ch_connectAccCb(Ch, J1939AccCb, NULL)) {                              
        DsJ1939Ch_destroy(&Ch);                                                                          
        return Ch;                                                                                       
    }                                                                                                    
    return Ch;                                                                                           
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 node initialization: */                                                                         
static void                                                                                              
J1939InitializeNode(UInt8 index,  UInt8 IsEnabled) {                                                     
    DsTError res = DSJ1939_NO_ERROR;                                                                     
                                                                                                         
    /* Skip initialization for node type DSJ1939_NODE_TYPE_NONRELEVANT */                                
    if (NodeType[index] == DSJ1939_NODE_TYPE_NONRELEVANT) {                                              
        return;                                                                                          
    }                                                                                                    
                                                                                                         
    res = DsJ1939Node_convertNameFromStructToLong(&J1939ECUNAMEParts[index], &J1939ECUNAME[index]);      
    if (DSJ1939_NO_ERROR != res) {                                                                       
        goto NodeInitErr;                                                                                
    }                                                                                                    
                                                                                                         
    if (NULL == J1939Nodes[index]) {                                                                     
        if (0 == J1939NmEnabled[index]) {                                                                
            /* Node without J1939 network management */                                                  
            res = DsJ1939Node_createUnique(&J1939Nodes[index], J1939Channel, NodeType[index]);           
            if (DSJ1939_NO_ERROR != res && DSJ1939_INFO_OBJECT_REUSED != res) {                          
                goto NodeInitErr;                                                                        
            }                                                                                            
        }                                                                                                
        else {                                                                                           
            res = DsJ1939Node_create(&J1939Nodes[index], J1939Channel, J1939ECUNAME[index], NodeType[index]);
            if (DSJ1939_NO_ERROR != res && DSJ1939_INFO_OBJECT_REUSED != res) {                          
                goto NodeInitErr;                                                                        
            }                                                                                            
        }                                                                                                
    }                                                                                                    
                                                                                                         
    res = DSJ1939_NO_ERROR;                                                                              
    res = DsJ1939Node_setDescriptor(J1939Nodes[index], NodeDesc[index]);                                 
    if (DSJ1939_NO_ERROR != res) {                                                                       
        goto NodeInitErr;                                                                                
    }                                                                                                    
                                                                                                         
    res = DsJ1939Node_setAddress(J1939Nodes[index], RTICANMM_MAIN_CAN_2_J1939InitNodeAddress[index]);                     
    if (DSJ1939_NO_ERROR != res) {                                                                       
        goto NodeInitErr;                                                                                
    }                                                                                                    
                                                                                                         
                                                                                                         
    if (DSJ1939_NODE_TYPE_SIMULATED == NodeType[index]) {                                                
        if (IsEnabled) {                                                                                 
          res = DsJ1939Node_setSilentMode(J1939Nodes[index], DSJ1939_MODE_DISABLED);                     
          if (DSJ1939_NO_ERROR != res) {                                                                 
              goto NodeInitErr;                                                                          
          }                                                                                              
        }                                                                                                
        else {                                                                                           
          res = DsJ1939Node_setSilentMode(J1939Nodes[index], DSJ1939_MODE_ENABLED);                      
          if (DSJ1939_NO_ERROR != res) {                                                                 
              goto NodeInitErr;                                                                          
          }                                                                                              
        }                                                                                                
                                                                                                         
        res = DsJ1939Node_start(J1939Nodes[index]);                                                      
        if (DSJ1939_NO_ERROR != res) {                                                                   
            goto NodeInitErr;                                                                            
        }                                                                                                
    }                                                                                                    
                                                                                                         
    res = DsJ1939Node_apply(J1939Nodes[index]);                                                          
    if (DSJ1939_NO_ERROR != res) {                                                                       
        goto NodeInitErr;                                                                                
    }                                                                                                    
                                                                                                         
    return;                                                                                              
                                                                                                         
NodeInitErr:                                                                                             
    DsJ1939Node_destroy(&J1939Nodes[index]);                                                             
    J1939Nodes[index] = NULL;                                                                            
                                                                                                         
    if (NULL == J1939Nodes[index]) {                                                                     
        msg_error_printf(MSG_SM_CANNEDY, RTICANMM_J1939_NODEINIT_ERROR, RTICANMM_J1939_NODEINIT_ERROR_TXT, 
                         "CAN_2", NodeDesc[index]);                                                         
    }                                                                                                    
                                                                                                         
    return;                                                                                              
}                                                                                                        
                                                                                                         
                                                                                                         
static UInt8                                                                                             
J1939GetState(DsTJ1939Node Node, UInt8* NodeAddress) {                                                   
    DsTError err = 0;                                                                                    
    DsEJ1939Node_State NodeState;                                                                        
                                                                                                         
    err = DsJ1939Node_getState(Node, &NodeState, NodeAddress);                                           
    if (err != DSJ1939_NO_ERROR) {                                                                       
        msg_info_printf(MSG_SM_CANNEDY, RTICANMM_J1939_NODEREAD_INFO, RTICANMM_J1939_NODEREAD_INFO_TXT,  
                         "CAN_2");                                                                          
        return 0;                                                                                        
    }                                                                                                    
    return NodeState;                                                                                    
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 getter for all node states: */                                                                  
static void                                                                                              
J1939GetAllNodeStates(void) {                                                                            
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 reset of node data: */                                                                          
static void                                                                                              
J1939ResetNodeData(void) {                                                                               
      J1939InitializeNode(0, CANMMCAN_2_TXEEIE[0]);                                                           
      J1939Nodes[J1939_BROADCAST_INDEX] = 0;                                                             
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 node activation/deactivation functions: */                                                      
static DsTError                                                                                          
J1939NodeEnable(int NodeIdx) {                                                                           
    DsTError ret;                                                                                        
                                                                                                         
    if (DSJ1939_NO_ERROR != (ret = DsJ1939Node_setAddress(J1939Nodes[NodeIdx],                           
                              RTICANMM_MAIN_CAN_2_J1939InitNodeAddress[NodeIdx]))) {                                      
        return ret;                                                                                      
    }                                                                                                    
    if (DSJ1939_NO_ERROR != (ret = DsJ1939Node_setSilentMode(J1939Nodes[NodeIdx], DSJ1939_MODE_DISABLED))) {
        return ret;                                                                                      
    }                                                                                                    
    if (DSJ1939_NO_ERROR != (ret = DsJ1939Node_apply(J1939Nodes[NodeIdx]))) {                            
        return ret;                                                                                      
    }                                                                                                    
    return ret;                                                                                          
}                                                                                                        
                                                                                                         
static DsTError                                                                                          
J1939NodeDisable(int NodeIdx) {                                                                          
    DsTError ret;                                                                                        
                                                                                                         
    if (DSJ1939_NO_ERROR != (ret = DsJ1939Node_setSilentMode(J1939Nodes[NodeIdx], DSJ1939_MODE_ENABLED))) {
        return ret;                                                                                      
    }                                                                                                    
    if (DSJ1939_NO_ERROR != (ret = DsJ1939Node_apply(J1939Nodes[NodeIdx]))) {                            
        return ret;                                                                                      
    }                                                                                                    
    return ret;                                                                                          
}                                                                                                        
                                                                                                         
static void                                                                                              
J1939CheckNodeActivation(void) {                                                                         
  DsTError ret;                                                                                          
                                                                                                         
}                                                                                                        
                                                                                                         
                                                                                                         
/* J1939 initialization of all constants: */                                                             
static void                                                                                              
J1939InitConstants(void) {                                                                               
    /* Vector__XXX */                                                                                         
    RTICANMM_MAIN_CAN_2_J1939NodeIndex[0] = 1;                                                                      
    RTICANMM_MAIN_CAN_2_J1939NodeSimulationMode[0] = DSJ1939_NODE_TYPE_NONRELEVANT;                                                             
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_ArbitraryAddressCapable = &J1939ECUNAMEParts[0].ArbitraryAddressCapable;
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_IndustryGroup           = &J1939ECUNAMEParts[0].IndustryGroup;          
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_VehicleSystemInstance   = &J1939ECUNAMEParts[0].VehicleSystemInstance;  
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_VehicleSystem           = &J1939ECUNAMEParts[0].VehicleSystem;          
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_Reserved                = &J1939ECUNAMEParts[0].Reserved;               
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_Function                = &J1939ECUNAMEParts[0].Function;               
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_FunctionInstance        = &J1939ECUNAMEParts[0].FunctionInstance;       
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_ECUInstance             = &J1939ECUNAMEParts[0].ECUInstance;            
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_ManufacturerCode        = &J1939ECUNAMEParts[0].ManufacturerCode;       
    RTICANMM_MAIN_CAN_2_J1939ECUNAMEParts_0_IdentityNumber          = &J1939ECUNAMEParts[0].IdentityNumber;         
    RTICANMM_MAIN_CAN_2_J1939InitNodeAddress[0] = 253;                                                                
    J1939ECUNAMEParts[0].ArbitraryAddressCapable   = 1;                                            
    J1939ECUNAMEParts[0].IndustryGroup             = 0;                                            
    J1939ECUNAMEParts[0].VehicleSystemInstance     = 0;                                            
    J1939ECUNAMEParts[0].VehicleSystem             = 0;                                            
    J1939ECUNAMEParts[0].Reserved                  = 0;                                            
    J1939ECUNAMEParts[0].Function                  = 129;                                            
    J1939ECUNAMEParts[0].FunctionInstance          = 0;                                            
    J1939ECUNAMEParts[0].ECUInstance               = 0;                                            
    J1939ECUNAMEParts[0].ManufacturerCode          = 2040;                                            
    J1939ECUNAMEParts[0].IdentityNumber            = 2090000;                                            
                                                                                                     
}                                                                                                        
                                                                                                         
