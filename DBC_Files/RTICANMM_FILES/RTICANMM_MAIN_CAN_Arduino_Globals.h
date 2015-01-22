/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_Globals */
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
#define S_FUNCTION_NAME                           RTICANMM_MAIN_CAN_Arduino
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include <math.h>
                                                       
#if !defined(MATLAB_MEX_FILE) || defined(CANMM_HOST_DEBUG)                                                            
# include "dsRTICANMMGlobals.h"
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */                                                                  
                                                       
                                                       
#define NUM_TX_INPUT                              8
#define NUM_TX_MSG                                1
#define NUM_RX_OUTPUT                             112
#define NUM_RX_MSG                                1
#define NUM_RX                                    112
#define NUM_TX                                    8
#define TX_PORT_DATA_TYPES                        "RTICANMM_MAIN_CAN_Arduino_TX_PORT.h"
#define RX_PORT_DATA_TYPES                        "RTICANMM_MAIN_CAN_Arduino_RX_PORT.h"
#define TX_WRITE_PORT_DATA                        "RTICANMM_MAIN_CAN_Arduino_TX_INPUT.h"
#define RX_WRITE_PORT_DATA                        "RTICANMM_MAIN_CAN_Arduino_RX_OUTPUT.h"
                                                       
                                                       
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
};                                                     
typedef struct MainSetupMsgData MainSetupMsgData;      
                                                       
enum CanMM_MsgTypes {                      
   RTICANMM_MESSAGE_TYPE_STD,              
   RTICANMM_MESSAGE_TYPE_EXT,              
   RTICANMM_MESSAGE_TYPE_J1939             
};                                         
typedef enum CanMM_MsgTypes CanMM_MsgTypes;
                                           
#undef CAN_J1939
#undef WITHOUT_LOOPBACKSTATUS

     /* Include CRC and CustomCode here */
#define CAN_BASEUPDATE_FILE                       "RTICANMM_MAIN_CAN_Arduino_BASEUPDATE.h"
#undef BASEUPDATE_ACTIVE                          
#define CAN_DEFS_FILE                             "RTICANMM_MAIN_CAN_Arduino_DEFS.h"
#define CAN_MSG_DATA_FILE                         "RTICANMM_MAIN_CAN_Arduino_MSG_DATA.h"
#define CAN_ID_TABLE_FILE                         "RTICANMM_MAIN_CAN_Arduino_ID_TABLE.h"
#define CAN_GLOBAL_ENABLE_TX                      CANMMCAN_Arduino_TXGE
#define CAN_GLOBAL_ENABLE                         CANMMCAN_Arduino_GE
#define CAN_VAR_ENABLE                            CANMM_CTL_SETUP_Controller3_ID
#define CAN_VAR_TRAFFIC                           CANMMCAN_Arduino_TRAFFIC
#define CANMM_RESET2DEFAULTS                      CANMMCAN_Arduino_RE
#define CAN_SENDBYKICKOUT                         CANMMCAN_Arduino_BYKICK
#define CAN_ENABLE                                CANMMCAN_Arduino_TXEN
#define CAN_WOULDBESENT                           CANMMCAN_Arduino_WBS
#define CAN_ENABLE_TIMEOUT                        CANMMCAN_Arduino_TXTOUT
#define CAN_CYCLIC                                CANMMCAN_Arduino_TXC
#define CAN_RX_DATA                               CANMMCAN_Arduino_RX
#define CAN_TX_DATA                               CANMMCAN_Arduino_TX
#define CAN_NUM_LOST                              CANMMCAN_Arduino_NL
#define CAN_NUM_LOST_RESET                        CANMMCAN_Arduino_NLR
#define rticanmmsaturation(value, maximum, minimum)((value >= maximum)? maximum : ((value <= minimum)? minimum : value))
#define rticanmmmaxsat(value, maximum, minimum)   ((value >= maximum)? maximum : value)
#define CAN_SIGNAL_HEADERFILE                     "RTICANMM_MAIN_CAN_Arduino_SIGNAL_DEFAULTS.h"
#define CAN_MESSAGE_HEADERFILE                    "RTICANMM_MAIN_CAN_Arduino_MESSAGE_DEFAULTS.h"
#define ENABLE_PORT                               0
#undef ONLYCAPTURE                                
#define TX_LOOPBACK                               1
#define TX_CYCLETIME                              CANMMCAN_Arduino_TXCT
#define TX_DELAYTIME                              CANMMCAN_Arduino_TXDT
#define TX_KICKOUT                                CANMMCAN_Arduino_TXKOUT
#define TX_KICKOUT_INTERN                         CANMMCAN_Arduino_TXKIN
#define TX_KICKOUT_INTERN_EXTERN                  CANMMCAN_Arduino_TXKIEX
#define TX_KICKOUT_CHECK_INTERN_EXTERN            CANMMCAN_Arduino_TXKIEXC
#define RX_STATUS                                 CANMMCAN_Arduino_RXsta
#define TX_STATUS                                 CANMMCAN_Arduino_TXsta
#define TX_MESSAGES_EXIST                         1
#define CAPTURE_KNOWN_MSGS
#define CAPTUREFCN                                CANMMCAN_Arduino_CAPF
#define CAPTURE_INDEX_MAX                         8
#define CAPTURE_STATUS                            CANMMCAN_Arduino_CAPS
#define USE_CAPTURE                               
#define CAPTUREMASK_EXT                           0
#define CAPTUREFILTER_EXT                         0
#define CAPTUREMASK_STD                           0
#define CAPTUREFILTER_STD                         0
#define CANMM_Q_NUM                               16

#if (RTICANMM_FEEDTHROUGH_CHECK)        
static const void * GetInputPortSignal(SimStruct *S, int port_num);
static int CheckDirectFeedThroughInputPort(SimStruct *S, int port_num);
#else                                                              
#define GetInputPortSignal ssGetInputPortSignal                    
#endif //RTICANMM_FEEDTHROUGH_CHECK                                
#endif /* NOT MATLAB_MEX_FILE || CANMM_HOST_DEBUG */               
                                                                   
