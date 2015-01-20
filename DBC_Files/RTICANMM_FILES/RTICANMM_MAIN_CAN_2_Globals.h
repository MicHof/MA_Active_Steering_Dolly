/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_2_Globals */
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

#undef DEBUG              
#define IDMANIPULATION
#define WITHOUT_DELAY
#undef NO_TX         
#define KICKOUT_ACTIVE               
#define NOCANID  0xEFFFFFFF
#define S_FUNCTION_NAME                           RTICANMM_MAIN_CAN_2
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include <math.h>
                                                       
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                            
# include "dsRTICANMMGlobals.h"
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */                                                                  
                                                       
                                                       
#define NUM_TX_INPUT                              0
#define NUM_TX_MSG                                19
#define NUM_RX_OUTPUT                             97
#define NUM_RX_MSG                                19
#define NUM_RX                                    97
#define NUM_TX                                    97
#define TX_PORT_DATA_TYPES                        "RTICANMM_MAIN_CAN_2_TX_PORT.h"
#define RX_PORT_DATA_TYPES                        "RTICANMM_MAIN_CAN_2_RX_PORT.h"
#define TX_WRITE_PORT_DATA                        "RTICANMM_MAIN_CAN_2_TX_INPUT.h"
#define RX_WRITE_PORT_DATA                        "RTICANMM_MAIN_CAN_2_RX_OUTPUT.h"
                                                       
                                                       
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                            
struct MainSetupMsgData {                              
  CanMM_Msg CANMsg;                                    
  UInt8 PaddingData[4];                                
  UInt8* pData;         /* Pointer to DLC data bytes */
  double DeltaTime;                                    
  double DelayTime;                                    
  double CycleTime;                                    
  UInt8  Status;                                       
  UInt32 TXCounter;                                    
  UInt32 RXCounter;                                    
  DsTJ1939Node SrcNode;                            
  DsTJ1939Node DestNode;                           
  UInt8 SrcAddress;                                
  UInt8 DestAddress;                               
};                                                     
typedef struct MainSetupMsgData MainSetupMsgData;      
                                                       
enum CanMM_MsgTypes {                      
   RTICANMM_MESSAGE_TYPE_STD,              
   RTICANMM_MESSAGE_TYPE_EXT,              
   RTICANMM_MESSAGE_TYPE_J1939             
};                                         
typedef enum CanMM_MsgTypes CanMM_MsgTypes;
                                           
#define CAN_J1939                      
#define J1939_MSG_DATA_LENGTH       8 
#define J1939_PF_MASK             0xff 
#define J1939_PDU1_MAX            0xef 
#define J1939_PDU1_MASK      0x1ff0000 
#define J1939_PDU2_MASK      0x1ffff00 
#define J1939_PGN_SHIFT             16 
#define J1939_PRIO_SHIFT            26 
#define J1939_PS_SHIFT               8 
#define J1939_PRIO_MASK     0x1C000000 
#define J1939_SA_MASK        0x00000ff 
#define J1939_DA_MASK        0x000ff00 
                                       
#define J1939_DPPF(Id)        (UInt32)((Id >> J1939_PGN_SHIFT) & J1939_PF_MASK)                       
#define J1939_PRIO(Id)        (UInt8) ((Id & (long)J1939_PRIO_MASK) >> J1939_PRIO_SHIFT)              
#define J1939_PS(Id)          (UInt8) ((Id & (long)J1939_DA_MASK)   >> J1939_PS_SHIFT)                
#define J1939_SRC(Id)         (UInt8)  (Id & (long)J1939_SA_MASK)                                     
#define J1939_IS_PDU1(Id)     (((Id >> J1939_PGN_SHIFT) & (J1939_PF_MASK & 0xff))  <= J1939_PDU1_MAX) 
#define J1939_IS_PDU2(Id)     (((Id >> J1939_PGN_SHIFT) & (J1939_PF_MASK & 0xff))  >  J1939_PDU1_MAX) 
#define J1939_PGN(Id)         (J1939_IS_PDU2(Id) ? (Id & J1939_PDU2_MASK) : (Id & J1939_PDU1_MASK))   
                                      
#undef WITHOUT_LOOPBACKSTATUS

     /* Include CRC and CustomCode here */
#define CAN_BASEUPDATE_FILE                       "RTICANMM_MAIN_CAN_2_BASEUPDATE.h"
#undef BASEUPDATE_ACTIVE                          
#define CAN_J1939DEFS_FILE                        "RTICANMM_MAIN_CAN_2_J1939DEFS.h"
#define CAN_DEFS_FILE                             "RTICANMM_MAIN_CAN_2_DEFS.h"
#define CAN_MSG_DATA_FILE                         "RTICANMM_MAIN_CAN_2_MSG_DATA.h"
#define CAN_ID_TABLE_FILE                         "RTICANMM_MAIN_CAN_2_ID_TABLE.h"
#define CAN_GLOBAL_ENABLE_TX                      CANMMCAN_2_TXGE
#define CAN_GLOBAL_ENABLE                         CANMMCAN_2_GE
#define CAN_VAR_ENABLE                            CANMM_CTL_SETUP_Controller2_ID
#define CAN_VAR_TRAFFIC                           CANMMCAN_2_TRAFFIC
#define CANMM_RESET2DEFAULTS                      CANMMCAN_2_RE
#define CAN_SENDBYKICKOUT                         CANMMCAN_2_BYKICK
#define CAN_ENABLE                                CANMMCAN_2_TXEN
#define CAN_WOULDBESENT                           CANMMCAN_2_WBS
#define CAN_ENABLE_TIMEOUT                        CANMMCAN_2_TXTOUT
#define CAN_CYCLIC                                CANMMCAN_2_TXC
#define CAN_RX_DATA                               CANMMCAN_2_RX
#define CAN_TX_DATA                               CANMMCAN_2_TX
#define CAN_NUM_LOST                              CANMMCAN_2_NL
#define CAN_NUM_LOST_RESET                        CANMMCAN_2_NLR
#define rticanmmsaturation(value, maximum, minimum)((value >= maximum)? maximum : ((value <= minimum)? minimum : value))
#define rticanmmmaxsat(value, maximum, minimum)   ((value >= maximum)? maximum : value)
#define CAN_SIGNAL_HEADERFILE                     "RTICANMM_MAIN_CAN_2_SIGNAL_DEFAULTS.h"
#define CAN_MESSAGE_HEADERFILE                    "RTICANMM_MAIN_CAN_2_MESSAGE_DEFAULTS.h"
#define ENABLE_PORT                               0
#define MAX_NODE_IDX                              2
#undef ONLYCAPTURE                                
#define TX_LOOPBACK                               1
#define TX_CYCLETIME                              CANMMCAN_2_TXCT
#define TX_DELAYTIME                              CANMMCAN_2_TXDT
#define TX_KICKOUT                                CANMMCAN_2_TXKOUT
#define TX_KICKOUT_INTERN                         CANMMCAN_2_TXKIN
#define TX_KICKOUT_INTERN_EXTERN                  CANMMCAN_2_TXKIEX
#define TX_KICKOUT_CHECK_INTERN_EXTERN            CANMMCAN_2_TXKIEXC
#define RX_STATUS                                 CANMMCAN_2_RXsta
#define TX_STATUS                                 CANMMCAN_2_TXsta
#define TX_MESSAGES_EXIST                         1
#undef USE_CAPTURE                                
#define CANMM_Q_NUM                               1

#if (RTICANMM_FEEDTHROUGH_CHECK)        
static const void * GetInputPortSignal(SimStruct *S, int port_num);
static int CheckDirectFeedThroughInputPort(SimStruct *S, int port_num);
#else                                                              
#define GetInputPortSignal ssGetInputPortSignal                    
#endif //RTICANMM_FEEDTHROUGH_CHECK                                
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */               
                                                                   
