/********************************************************************************************************/                 
/*   FILE:                                                                                              */                 
/*     rticanmm_setup.c                                                                                 */                 
/*                                                                                                      */                 
/*   DESCRIPTION:                                                                                       */                 
/*     S-Function providing CAN initialization as well as transmit and receive functionality.           */                 
/*                                                                                                      */                 
/*   AUTHOR(S):                                                                                         */                 
/*     F. Mierke, U. Homann, M. Eikermann                                                               */                 
/*                                                                                                      */                 
/*   RTICANMM Date: 13-Mar-2014 10:38:34                                                                                  */                 
/*   RTICANMM Version: 3.0.735671.4434490741                                                                               */                 
/*                                                                                                      */                 
/*  (c) Copyright 2015, dSPACE GmbH. All rights reserved.                                                 */                 
/*      Brand names or product names are trademarks or registered trademarks of their respective companies or organizations. */
/*                                                                                                      */                 
/* $RCSFile: rticanmm_setup.c $ $Revision: 2.232 $ $Date: 2014/01/14 11:23:48MEZ $                  */                    
/* $ProjectName: e:/ARC/Products/ImplSW/RTISW/RTICANMM/Components/Blocks/BusSetup/project.pj $          */                 
/* ******************************************************************************************************/                 
                                                                                                                           
#define S_FUNCTION_LEVEL       2                                                                                           
#define S_FUNCTION_NAME        RTICANMM_SETUP_TutVar_C2                                                                                          
                                                                                                                           
                                                                                                                           
                                                                                                                   
/****************************/                                                                                     
/*        Includes          */                                                                                     
/****************************/                                                                                     
                                                                                                                   
#include "RTICANMM_SETUP_TutVar_C2.h"                                                                                                    
                                                                                                                   
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                          
                                                                                                                   
#if defined(RTICANMM_HAVE_DSTS_H)                                                                                  
#  include <dsts.h>                                                                                                
# endif /* RTICANMM_HAVE_DSTS_H */                                                                                 
                                                                                                                   
                                                                                                                   
#endif /* RTICANMM_HAVE_VALID_PLATFORM */                                                                          
                                                                                                                           
#include <simstruc.h>                                                                                                      
#include <tmwtypes.h>                                                                                                      
                                                                                                                           
#define NUM_CSTATES     0                            /* Number of Continuous States */                                     
#define NUM_DSTATES     0                            /* Number of Discrete States */                                       
                                                                                                                           
#define NUM_IWORK       0                            /* Number of I WORKS */                                               
#define NUM_PWORK       0                            /* Number of P WORKS */                                               
#define NUM_RWORK       0                            /* Number of R WORKS */                                               
                                                                                                                           
#define NUM_STIMES      1                            /* Number of Sample Times */                                          
#define NUM_MODES       0                            /* Number of Modes */                                                 
#define NUM_NSZCS       0                            /* Number of None Sampled ZCs */                                      
#define SET_OPTS        0                            /* Options */                                                         
                                                                                                                           
                                                                                                                           
                                                                                                                           
                                                                                                                           
                                                                                                                           
/****************************/                                                                                     
/*         Globals          */                                                                                     
/****************************/                                                                                     
                                                                                                                   
#define NUM_PARAM       0                                /* Number of Parameter */                                 
#define NUM_IN          2                               /* Number of Input Ports */                               
#define NUM_OUT         0                               /* Number of Output Ports */                              
                                                                                                                   
/* defines for rx service */                                                                                       
#define PZS_TJA_COMM_CH         6                                                                                 
                                                                                                                   
                                                                                                                   
#define USE_DS4302     1                                                                                               
                                                                                                                   
                                                                                                                           
#define CAN_BOARDNUMBER                                     1                                                     
#define CAN_BTR0                                            0x40                                                     
#define CAN_BTR1                                            0x1C                                                     
#define CAN_BOARD_BASE                                  DS4302_1_BASE                                             
#define CAN_BOARD_IDX                                   PHS_INDEX_GET(CAN_BOARD_BASE)                          
#define CAN_BUSCFG                                          0x0                                                     
                                                                                                                   
#define CAN_TERMINATION                                     DS4302_CAN_TERMINATION_ON                                              
#define CAN_INT_CONFIG  DS4302_CAN_INT_DISABLE                                                                     
                                                                                                                   
#define CAN_TYPE_MB15                                       DS4302_CAN_STD                                              
                                                                                                                   
#define CAN_TRANSCEIVER                                    DS4302_CAN_ISO11898_TRANSCEIVER                           
                                                                                                                   
#define CanMM_channel_array                               DS4302_B1_P0                                                       
                                                                                                                   
#if defined(USE_DS2211)                                                                                            
# define CAN_BTR0_36                                        0x40                                                 
# define CAN_BTR1_36                                        0x1C                                                 
#endif                                                                                                             
#define MONITORING_SLEEPTIME                                1.000                                                         
                                                                                                                       
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                              
#if !defined(CANMM_HOST_DEBUG)                                                                                    
    static ds4302_canService* StatusService; /* Number of successfully sent TX messages */                 
#endif                                                                                                             
                                                                                                                   
static Float32 oldsampletime = 0;                                                                                  
static Float32 newsampletime = 0;                                                                                  
static Float64 CANMM_CTL_SETUP_TutVar_C2_baudrate      = 500.0;                                                                                 
static Float64 CANMM_CTL_SETUP_TutVar_C2_baudrate_in   = 500.0; /* Temporary for input port value */                                            
static Float64 CANMM_CTL_SETUP_TutVar_C2_baudrate_old  = 500.0;                                                                                 
#endif /* RTICANMM_HAVE_VALID_PLATFORM */                                                                           
                                                                                                                            
#define CAN_CHANNELNO                                       2                                                              
                                                                                                                            
#define INDEF_VARIATION ((uint8_T*) ssGetInputPortSignal(S, 0))[0]   /* Variation */                                                      
#define INDEF_RESET ((boolean_T*) ssGetInputPortSignal(S, 1))[0]   /* Reset */                                                      
                                                                                                                            
                                                                                                                   
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                                   
                                                                                                                   
static Int32     IndexRd = -1;           // Handle for DS4302 memory/TJA1041 read                                  
static Int32     IndexWr = -1;           // Handle for DS4302 memory/TJA1041 write                                 
static UInt32    LastState = 0;          // Last state read from the TJA1041                                       
static UInt32    LastWrittenData = 0;    // Last data written to the TJA1041 configuration register                
static boolean_T TransceiverState = 0;   // Last Transceiver State                                                 
                                                                                                                   
static UInt32    tempState_stuffbit_err = 0;                                                                       
static UInt32    tempState_form_err     = 0;                                                                       
static UInt32    tempState_ack_err      = 0;                                                                       
static UInt32    tempState_bit0_err     = 0;                                                                       
static UInt32    tempState_bit1_err     = 0;                                                                       
static UInt32    tempState_crc_err      = 0;                                                                       
static UInt32    tempState_rx_lost      = 0;                                                                       
static UInt32    tempState_rx_ok        = 0;                                                                       
static UInt32    tempState_tx_ok        = 0;                                                                       
static boolean_T resetStateVars         = 0;                                                                       
                                                                                                                   
#if defined(RTICANMM_HAVE_DSCAN_BUS)                                                                                       
static DsTCanBus    CanMM_vBus;                                                                                    
# endif                                                                                                            
static DsTCanBoard  CanMM_board;                                                                                   
                                                                                                                   
#if defined(RTICANMM_HAVE_DSCAN_CHANNEL)																			  
static DsTCanCh     CanMM_channel;                                                                                 
#else                                                                                                              
static ds4302_canChannel* CanMM_channel;                                                                                          
#endif /* RTICANMM_HAVE_DSCAN_CHANNEL */                                                                           
                                                                                                                   
volatile UInt8 DECLSPEC CANMM_CTL_SETUP_TutVar_C2_ID;                                                                                     
volatile UInt8 DECLSPEC CANMM_CTL_SETUP_TutVar_C2_TX_STATUS        = 1;                                                                   
volatile UInt8 DECLSPEC CANMM_CTL_SETUP_TutVar_C2_Variation        = 1;                                                                   
volatile UInt8 DECLSPEC CANMM_CTL_SETUP_TutVar_C2_VariationSwitch  = 0;                                                                   
                                                                                                                   
                                                                                                                   
#if defined(RTICANMM_DSDAQ_SERVICEID)                                                                              
/* Data Capturing Bus Navigator with HostService */                                                                
#if !defined(CANMM_HOST_DEBUG)                                                                                     
extern UInt32 RTICANMM_MonitorData[4];  /* Provided by TLC code generation */                                                       
#else                                                                                                              
UInt32 RTICANMM_MonitorData[4];  /* For CANMM_HOST_DEBUG no TLC code generation is executed therefore declare variable here! */     
#endif                                                                                                             
volatile UInt8   CANMMMonitor_TutVar_C2     = 0;                                                                                       
volatile UInt8   CANMMMonitor_TutVar_C2_old = 0;                                                                                       
volatile dsfloat MonitoringTimeStamp_TutVar_C2     = 0.0;                                                                                     
                                                                                                                   
#if defined(RTICANMM_HAVE_DSTS_H)                                                                                  
static ts_timestamp_type ts;                                                                                       
static real_T HWTimeOffset=0.0;                                                                                    
#endif                                                                                                             
                                                                                                                   
/* Client to self for bus monitoring */                                                                            
static CanMM_Msg canmm_msg;                                                                                        
static CANMM_CTL_CLIENT_TYPE(CANMM_CTL_SETUP_TutVar_C2) ctlsetup_client;                                                                  
#endif /* RTICANMM_DSDAQ_SERVICEID */                                                                              
                                                                                                                   
#if !defined(RTICANMM_HAVE_DSCAN_CHANNEL)                                                                          
void CANMM_CTL_SETUP_TutVar_C2_baudrate_set(Float64 baudrate) {                                                                           
  static int printInfo = 1;                                                                                        
  int res = 0;                                                                                                     
                                                                                                                   
  res = ds4302_can_channel_set(CanMM_channel, DS4302_CAN_CHANNEL_SET_BAUDRATE, (int)baudrate*1000);                                
  if ((res == DS4302_CAN_BAUDRATE_L_ERROR || res == DS4302_CAN_BAUDRATE_H_ERROR) && printInfo) {                                   
     msg_info_printf(MSG_SM_CANNEDY, RTICANMM_CANSFCN_BAUDRATE_RANGE_INFO,                                         
                     RTICANMM_CANSFCN_BAUDRATE_RANGE_INFO_TXT, "TutVar_C2",                                               
                     (int)baudrate, (int)(DS4302_CAN_MIN_BAUDRATE/1000), (int)(DS4302_CAN_MAX_BAUDRATE/1000));                     
     printInfo = 0;                                                                                                
  }                                                                                                                
  if (res == 0) {                                                                                                  
     /* Update baudrate iff changed successfully */                                                                
     CANMM_CTL_SETUP_TutVar_C2_baudrate = baudrate;                                                                                       
     printInfo = 1;                                                                                                
  }                                                                                                                
}                                                                                                                  
                                                                                                                   
                                                                                                                   
# endif /* RTICANMM_HAVE_DSCAN_CHANNEL */                                                                                   
#endif /* RTICANMM_HAVE_VALID_PLATFORM */                                                                                   
                                                                                                                   
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                          
                                                                                                                   
void DECLSPEC CANMM_CTL_SETUP_TutVar_C2_client_init(CANMM_CTL_SETUP_TutVar_C2_CtlClient* client) {                                                               
  DsTError          Error         = DSCAN_NO_ERROR;                                                                
                                                                                                                   
  /* initialize message structures */                                                                              
  if (!client->initialized) {                                                                                      
                                                                                                                   
    /* RX */                                                                                                       
    if ((Error = DsCanMsg_createRxMonitor(&(client->rx_msg), CanMM_channel)) != DSCAN_NO_ERROR)                    
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    if ((Error = DsCanMsg_setFilter(client->rx_msg, 0x1, 0x0, DSCAN_MSG_FORMAT_BOTH, DSCAN_MSG_RTR_BOTH)) != DSCAN_NO_ERROR)
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    if ((Error = DsCanMsg_setQueueSize(client->rx_msg, 100)) != DSCAN_NO_ERROR)                                    
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    if((Error = DsCanMsg_apply(client->rx_msg)) != DSCAN_NO_ERROR)                                                 
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    /* TX */                                                                                                       
    if ((Error = DsCanMsg_createTxQueue(&client->tx_msg, CanMM_channel)) != DSCAN_NO_ERROR)                        
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    if ((Error = DsCanMsg_setQueueSize(client->tx_msg, CANMM_CTL_SETUP_TutVar_C2_tx_queue_size)) != DSCAN_NO_ERROR)                       
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    if ((Error = DsCanMsg_setTxRetryCount(client->tx_msg, DSCAN_MSG_RETRY_MODE_ACTIVE, 3)) != DSCAN_NO_ERROR)     
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    if ((Error = DsCanMsg_apply(client->tx_msg)) != DSCAN_NO_ERROR)                                                
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    if ((Error = DsCanMsg_start(client->tx_msg)) != DSCAN_NO_ERROR)                                                
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
    client->update      = 1;                                                                                       
    client->initialized = 1;                                                                                       
    client->disabled    = 0;                                                                                       
  }                                                                                                                
}                                                                                                                  
                                                                                                                   
                                                                                                                   
#if !defined(RTICANMM_HAVE_DSRT)                                                                                   
extern dsfloat RTICANMM_DataFetchTime[16];                                                                         
extern dsfloat *currentTime;                                                                                       
static DsTError RTICANMM_CanBoard_update(DsTCanBoard CanMM_board, int CanMM_Board_idx)                             
{                                                                                                                  
   DsTError Error = DSCAN_NO_ERROR;                                                                                
#if !defined(RTICANMM_HW_BACKGROUND_ACCESS)                                                                        
   if (RTICANMM_DataFetchTime[CanMM_Board_idx] != *currentTime)                                                    
   {                                                                                                               
      RTICANMM_DataFetchTime[CanMM_Board_idx] = *currentTime;                                                      
      Error = DsCanBoard_update(CanMM_board);                                                                      
   }                                                                                                               
#endif                                                                                                             
   return Error;                                                                                                   
}                                                                                                                  
#elif defined(RTICANMM_HAVE_DSRT)                                                                                  
#define RTICANMM_CanBoard_update(board, idx) DsCanBoard_update(board)                                              
#endif                                                                                                             
                                                                                                                   
                                                                                                                   
/* RX function of controller                                                                                       
 * Receives all messages (incl loopback) from all                                                                  
 * queues.                                                                                                         
 * Always call this function until no new messages are                                                             
 * available.                                                                                                      
 */                                                                                                                
Int32 DECLSPEC CANMM_CTL_SETUP_TutVar_C2_rx(CANMM_CTL_SETUP_TutVar_C2_CtlClient* client, CanMM_Msg* msg) {                                                       
    DsSCanMsg_Item msg_item;                                                                                       
    int i;                                                                                                         
                                                                                                                   
    if (client->disabled) {                                                                                        
      return 0;                                                                                                    
    }                                                                                                              
                                                                                                                   
    if (client->update) {                                                                                          
      RTICANMM_CanBoard_update(CanMM_board, CAN_BOARD_IDX);                                                        
      client->update = 0;                                                                                          
    }                                                                                                              
                                                                                                                   
    if(DsCanMsg_readRxItem(client->rx_msg, &msg_item) == DSCAN_NO_ERROR) {                                         
                                                                                                                   
      if(msg_item.Status == DSCAN_MSG_NO_DATA) {                                                                   
        client->update = 1;                                                                                        
        return 0;                                                                                                  
      }                                                                                                            
                                                                                                                   
      msg->TimeStamp = msg_item.TimeStamp;                                                                         
      msg->Id        = msg_item.Id;                                                                                
      msg->Dlc       = msg_item.Dlc;                                                                               
                                                                                                                   
      if(msg_item.Format == DSCAN_MSG_FORMAT_EXT)                                                                  
        msg->Format    = CANMM_MSG_FORMAT_EXT;                                                                     
      else                                                                                                         
        msg->Format    = CANMM_MSG_FORMAT_STD;                                                                     
                                                                                                                   
      /* Need to copy all data since msg->Data might not be initialized */                                         
      msg->Data[0]   = msg_item.Data[0];                                                                           
      msg->Data[1]   = msg_item.Data[1];                                                                           
      msg->Data[2]   = msg_item.Data[2];                                                                           
      msg->Data[3]   = msg_item.Data[3];                                                                           
      msg->Data[4]   = msg_item.Data[4];                                                                           
      msg->Data[5]   = msg_item.Data[5];                                                                           
      msg->Data[6]   = msg_item.Data[6];                                                                           
      msg->Data[7]   = msg_item.Data[7];                                                                           
                                                                                                                   
      if(msg_item.Dir == DSCAN_MSG_DIR_RECEIVE)                                                                    
        msg->Loopback = 0;                                                                                         
      else                                                                                                         
        msg->Loopback = 1;                                                                                         
                                                                                                                   
      msg->Flags = 0;                                                                                              
      if(msg_item.Status == DSCAN_MSG_LOST) {                                                                      
        msg->Flags = msg->Flags | RTICANMM_FLAG_MSGLOST;                                                           
      }                                                                                                            
    }                                                                                                              
    else {                                                                                                         
      return 0;                                                                                                    
    }                                                                                                              
                                                                                                                   
    return 1;                                                                                                      
}                                                                                                                  
                                                                                                                   
                                                                                                                   
/* TX function of controller                                                                                       
 */                                                                                                                
Int32 DECLSPEC CANMM_CTL_SETUP_TutVar_C2_tx(CANMM_CTL_SETUP_TutVar_C2_CtlClient* client, CanMM_Msg* msg) {                                                       
  int      k     = 0;                                                                                              
  DsTError Error = DSCAN_NO_ERROR;                                                                                 
  DsSCanMsg_Item msg_item;                                                                                         
                                                                                                                   
  msg_item.Id  = msg->Id;                                                                                          
  msg_item.Dlc = msg->Dlc;                                                                                         
  msg_item.Rtr = DSCAN_MSG_RTR_DISABLED;                                                                           
  msg_item.IsEnabled = DSCAN_MSG_STATE_ACTIVE;                                                                     
  msg_item.TimeStamp = 0.0;  /* Send immediately */                                                                
                                                                                                                   
  for (k=0; k<msg->Dlc; k++)                                                                                       
    msg_item.Data[k] = msg->Data[k];                                                                               
                                                                                                                   
  if(msg->Format == CANMM_MSG_FORMAT_EXT)                                                                          
    msg_item.Format = DSCAN_MSG_FORMAT_EXT;                                                                        
  else                                                                                                             
    msg_item.Format = DSCAN_MSG_FORMAT_STD;                                                                        
                                                                                                                   
  if((Error = DsCanMsg_transmitItem(client->tx_msg, &msg_item)) != DSCAN_NO_ERROR) {                               
    CANMM_DEBUG_ERROR(Error);                                                                                      
    return 1;                                                                                                      
  }                                                                                                                
  else {                                                                                                           
    return 0;                                                                                                      
  }                                                                                                                
}                                                                                                                  
                                                                                                                   
/**                                                                                                                
 * Start receiving messages                                                                                        
 * This message is used to indicate a client will start receiving messages.                                        
 * If CANMM_CTL_SETUP_TutVar_C2_rx_stop has been issued before, the receive buffer (mcr) is cleared                                       
 * for the calling client. Messages received in the inactive period thus will                                      
 * not be received.                                                                                                
 */                                                                                                                
void DECLSPEC CANMM_CTL_SETUP_TutVar_C2_rx_start(CANMM_CTL_SETUP_TutVar_C2_CtlClient* client) {                                                                  
  DsTError          Error         = DSCAN_NO_ERROR;                                                                
  if ((Error = DsCanMsg_start(client->rx_msg)) != DSCAN_NO_ERROR)                                                  
    CANMM_DEBUG_ERROR(Error);                                                                                      
  client->disabled = 0;                                                                                            
}                                                                                                                  
                                                                                                                   
/**                                                                                                                
 * Stop receiving messages                                                                                         
 * Indicates that the calling client intends to not further call the                                               
 * CANMM_CTL_SETUP_TutVar_C2_rx function. To continue reception of messages CANMM_CTL_SETUP_TutVar_C2_rx_start                                                   
 * has to be called.                                                                                               
 */                                                                                                                
void DECLSPEC CANMM_CTL_SETUP_TutVar_C2_rx_stop(CANMM_CTL_SETUP_TutVar_C2_CtlClient* client) {                                                                   
  DsTError          Error         = DSCAN_NO_ERROR;                                                                
  if ((Error = DsCanMsg_stop(client->rx_msg)) != DSCAN_NO_ERROR)                                                   
    CANMM_DEBUG_ERROR(Error);                                                                                      
  client->disabled = 1;                                                                                            
}                                                                                                                  
                                                                                                                   
                                                                                                                   
Float64 DECLSPEC CANMM_CTL_SETUP_TutVar_C2_baudrate_get() {                                                                               
  return CANMM_CTL_SETUP_TutVar_C2_baudrate;                                                                                              
}                                                                                                                  
                                                                                                                   
                                                                                                                   
/**                                                                                                                
* Return the no of message waiting for transmit                                                                    
*/                                                                                                                 
UInt32 DECLSPEC CANMM_CTL_SETUP_TutVar_C2_tx_queue_level(CANMM_CTL_SETUP_TutVar_C2_CtlClient* client) {                                                          
  UInt32   tx_count = 0;                                                                                           
  DsTError Error;                                                                                                  
                                                                                                                   
  if ((Error = DsCanMsg_getTxQueueCount(client->tx_msg, &tx_count)) != DSCAN_NO_ERROR) {                           
    CANMM_DEBUG_ERROR(Error);                                                                                      
    /* In case of error, pretend a full queue */                                                                   
    tx_count = CANMM_CTL_SETUP_TutVar_C2_tx_queue_size;                                                                                   
  }                                                                                                                
  return tx_count;                                                                                                 
}                                                                                                                  
                                                                                                                   
#endif /* RTICANMM_HAVE_VALID_PLATFORM */                                                                                   
                                                                                                                   
                                                                                                                   
#if defined(TJA)                                                                                               
                                                                                                               
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                      
static void ds4302_port2_gst_sst_init( SimStruct *S, UInt32 base,  UInt32 boardno, UInt32 channel, UInt32 conf )
{                                                                                                              
                                                                                                               
                                                                                                               
    ds4302_can_channel_set(CanMM_channel, DEF4302_CHANNEL_SET_P2CONF, conf );                                  
                                                                                                               
    /* Data RAM read access, a block of 32 bit data is read from the slaves adress range */                    
    /* PARAMETERS:                                                                       */                    
    /* IndexRd  : function index (DS4302_CAN_AUTO_INDEX: assign new index)               */                    
    /* ADDR      : source address in data RAM                                            */                    
    /* LEN       : length of data block to be read                                       */                    
    ds4302_can_mem_read_register( (UInt32)CAN_BOARD_BASE,                                                      
    PZS_TJA_COMM_CH,                                                                                           
    &IndexRd,                                                                                                  
    DS4302_CAN_BASIS_ADDR + DS4302_PORT2_READ + ((CAN_CHANNELNO-1) * DS4302_CHAN_OFFSET),                      
    DS4302_PORT2_DATALEN );                                                                                    
                                                                                                               
    ds4302_can_mem_write_register( CAN_BOARD_BASE,                                                             
    PZS_TJA_COMM_CH,                                                                                           
    &IndexWr,                                                                                                  
    DS4302_CAN_BASIS_ADDR + DS4302_PORT2_WRITE + ((CAN_CHANNELNO-1) * DS4302_CHAN_OFFSET),                     
    DS4302_PORT2_DATALEN );                                                                                    
                                                                                                               
}                                                                                                              
                                                                                                               
static Int32 ds4302_port2_read( SimStruct *S, UInt32* data )                                                   
{                                                                                                              
    Int32 error = 0;                                                                                           
    UInt32 buffer;                                                                                             
                                                                                                               
      /* QUEUE    : communication channel within the range 0 ... 6                     */                      
      /* IndexRd : table index already allocated by the previously performed function  */                      
      /* buffer   : Destination address of the data                                    */                      
    error = ds4302_can_mem_read (CAN_BOARD_BASE, PZS_TJA_COMM_CH, IndexRd, &buffer );                          
                                                                                                               
    buffer &= 0x000000FF; /* select the lower 8 bits */                                                        
    *data = buffer;                                                                                            
                                                                                                               
      /* Do the request for the next sample step                                       */                      
      /* IndexRd : table index already allocated by the previously performed function  */                      
    ds4302_can_mem_read_request( CAN_BOARD_BASE, PZS_TJA_COMM_CH, IndexRd );                                   
                                                                                                               
    return error;                                                                                              
}                                                                                                              
#endif   /* RTICANMM_HAVE_VALID_PLATFORM */                                                                    
#endif /* TJA */                                                                                               
                                                                                                               
                                                                                                                   
                                                                                                                           
static void mdlInitializeSizes(SimStruct *S)                                                                               
{                                                                                                                          
                                                                                                                           
/****************************/                                                                                     
/*   Initialize Sizes       */                                                                                     
/****************************/                                                                                     
                                                                                                                   
  int i;                                                                                                           
                                                                                                                   
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                          
  static int sizes_once = 0;                                                                                       
  DsTError          Error         = DSCAN_NO_ERROR;                                                                
  UInt32 maxFrequency;                                                                                             
  UInt32 currentFrequency;                                                                                         
  UInt32 processorType;                                                                                            
#endif                                                                                                             
                                                                                                                   
  ssSetNumSFcnParams(S, NUM_PARAM);                                                                                
                                                                                                                   
  if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)){                                                           
      return;                                                                                                      
  }                                                                                                                
  ssSetNumContStates(S, NUM_CSTATES);                                                                              
  ssSetNumDiscStates(S, NUM_DSTATES);                                                                              
                                                                                                                   
  if (!ssSetNumOutputPorts(S, NUM_OUT)) {                                                                          
      return;                                                                                                      
  }                                                                                                                
                                                                                                                   
  if (!ssSetNumInputPorts(S, NUM_IN)) {                                                                            
      return;                                                                                                      
  }                                                                                                                
                                                                                                                   
  for (i=0;i<NUM_IN;i++) {                                                                                         
      ssSetInputPortRequiredContiguous(S, i, true);                                                                
      ssSetInputPortDirectFeedThrough(S, i, 1);                                                                    
      ssSetInputPortWidth(S, i, 1);                                                                                
  }                                                                                                                
  for (i=0;i<NUM_OUT;i++) {                                                                                        
      ssSetOutputPortWidth(S, i, 1);                                                                               
  }                                                                                                                
                                                                                                                   
  ssSetInputPortDataType(S, 0, SS_UINT8);    /* Variation */                                                               
  ssSetInputPortDataType(S, 1, SS_BOOLEAN);    /* Reset */                                                               
                                                                                                                   
  ssSetNumRWork(S, NUM_RWORK);                                                                                     
  ssSetNumIWork(S, NUM_IWORK);                                                                                     
  ssSetNumPWork(S, NUM_PWORK);                                                                                     
  ssSetNumSampleTimes(S, NUM_STIMES);                                                                              
  ssSetNumModes(S, NUM_MODES);                                                                                     
  ssSetNumNonsampledZCs(S, NUM_NSZCS);                                                                             
  ssSetOptions(S, SET_OPTS | SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME);                                             
                                                                                                                   
#if defined(RTICANMM_HAVE_VALID_PLATFORM)			   															  
  if (!sizes_once) {                                                                                               
    sizes_once = 1;                                                                                                
                                                                                                                   
#if defined(RTICANMM_HAVE_DSCAN_BUS)                                                                                       
  /* Virtual bus for debugging on host */                                                                          
  if ((Error = DsCanBus_create(&CanMM_vBus, 2)) != DSCAN_NO_ERROR)                                                
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
  /* Initialize channel with default parameters */                                                                 
  if (((Error = DsCanCh_create(&CanMM_channel, NULL, NULL)) != DSCAN_NO_ERROR)                                     
        && (Error != DSCAN_ERROR_OBJECT_REUSED))                                                                   
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
  if ((Error = DsCanCh_setDescriptor(CanMM_channel, "TutVar_C2")) != DSCAN_NO_ERROR)                                      
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
  if ((Error = DsCanCh_setBaudRate(CanMM_channel, (int)CANMM_CTL_SETUP_TutVar_C2_baudrate*1000)) != DSCAN_NO_ERROR)                       
      CANMM_DEBUG_ERROR(Error);                                                                                    
                                                                                                                   
  if ((Error = DsCanBus_connectChannel(CanMM_vBus, CanMM_channel)) != DSCAN_NO_ERROR)                              
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
  if ((Error = DsCanCh_setReceiveMode(CanMM_channel, DSCAN_CH_RECEIVE_MODE_NORMAL)) != DSCAN_NO_ERROR)             
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
  if ((Error = DsCanCh_setBusOffRecoveryMode(CanMM_channel, DSCAN_CH_BUSOFF_RECOVERY_ENABLED)) != DSCAN_NO_ERROR)  
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
  if ((Error = DsCanCh_setBusMode(CanMM_channel, DSCAN_CH_MODE_BUSON)) != DSCAN_NO_ERROR)                          
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
  if ((Error = DsCanCh_apply(CanMM_channel)) != DSCAN_NO_ERROR)                                                    
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
# else                                                                                                             
                                                                                                                   
    DsCanBoard_create(&CanMM_board, CAN_BOARD_BASE);                                                               
                                                                                                                   
                                                                                                                   
#if defined(RTICANMM_HAVE_PHS_BUS)                                                                                 
         CanMM_channel = ds4302_can_channel_init(CAN_BOARD_BASE,                                                   
                                         CAN_CHANNELNO-1,                                                  
                                         CANMM_CTL_SETUP_TutVar_C2_baudrate * 1000,                                               
                                         CAN_TYPE_MB15,                                                    
                                         CAN_CHANNELNO-1);                                                 
#endif /* defined(RTICANMM_HAVE_PHS_BUS)*/                                                                         
                                                                                                                   
                                                                                                                   
          ds4302_can_channel_transceiver(CanMM_channel, CAN_TRANSCEIVER, DS4302_CAN_TERMINATION_ON);                                       
                                                                                                               
          if (CAN_TRANSCEIVER == DS4302_CAN_NO_TRANSCEIVER)                                                            
              ds4302_can_channel_set(CanMM_channel, DS4302_CAN_CHANNEL_SET_BUSCFG, CAN_BUSCFG);                                
                                                                                                                   
                                                                                                                   
                                                                                                                   
# endif /* RTICANMM_HAVE_DSCAN_BUS */                                                                                       
  }                                                                                                                
#endif /* RTICANMM_HAVE_VALID_PLATFORM */                                                                                   
}                                                                                                                          
                                                                                                                           
                                                                                                                           
/* Function: mdlInitializeSampleTimes =========================================                                            
 * Abstract:                                                                                                               
 *    This function is used to specify the sample time(s) for your                                                         
 *    S-function. You must register the same number of sample times as                                                     
 *    specified in ssSetNumSampleTimes.                                                                                    
 */                                                                                                                        
static void mdlInitializeSampleTimes(SimStruct *S)                                                                         
{                                                                                                                          
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);                                                                          
    ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);                                                                     
}                                                                                                                          
                                                                                                                           
                                                                                                                           
#define MDL_INITIALIZE_CONDITIONS   /* Change to #undef to remove function */                                              
#if defined(MDL_INITIALIZE_CONDITIONS)                                                                                     
  /* Function: mdlInitializeConditions ========================================                                            
   * Abstract:                                                                                                             
   *    In this function, you should initialize the continuous and discrete                                                
   *    states for your S-function block.  The initial states are placed                                                   
   *    in the state vector, ssGetContStates(S) or ssGetRealDiscStates(S).                                                 
   *    You can also perform any other initialization activities that your                                                 
   *    S-function may require. Note, this routine will be called at the                                                   
   *    start of simulation and if it is present in an enabled subsystem                                                   
   *    configured to reset states, it will be call when the enabled subsystem                                             
   *    restarts execution to reset the states.                                                                            
   */                                                                                                                      
static void mdlInitializeConditions(SimStruct *S)                                                                          
{                                                                                                                          
                                                                                                                           
/****************************/                                                                                     
/*     Init Conditions      */                                                                                     
/****************************/                                                                                     
                                                                                                                   
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                          
#if !defined(CANMM_HOST_DEBUG)                                                                                           
    static int initialize_once = 0;                                                                                
#endif /* CANMM_HOST_DEBUG  */                                                                                     
#if defined(RTICANMM_DSDAQ_SERVICEID)                                                                                   
    CANMM_CTL_CLIENT_INIT(CANMM_CTL_SETUP_TutVar_C2, &ctlsetup_client);                                                                   
    CANMM_CTL_RX_STOP(CANMM_CTL_SETUP_TutVar_C2, &ctlsetup_client);      /* Start disabled */                                             
#endif                                                                                                             
                                                                                                                   
                                                                                                                   
#if !defined(CANMM_HOST_DEBUG)                                                                                           
    if (!initialize_once) {                                                                                        
        initialize_once = 1;                                                                                       
        StatusService = ds4302_can_service_register(CanMM_channel, 
               DS4302_CAN_SERVICE_BUSSTATUS );                                                                                                               
    }                                                                                                              
    newsampletime = 0;                                                                                             
    oldsampletime = 0;                                                                                             
#endif /* CANMM_HOST_DEBUG */                                                                                      
#endif /* RTICANMM_HAVE_VALID_PLATFORM */                                                                                   
}                                                                                                                          
#endif /* MDL_INITIALIZE_CONDITIONS */                                                                                     
                                                                                                                           
                                                                                                                           
#define MDL_START  /* Change to #undef to remove function */                                                               
#if defined(MDL_START)                                                                                                     
  /* Function: mdlStart =======================================================                                            
   * Abstract:                                                                                                             
   *    This function is called once at start of model execution. If you                                                   
   *    have states that should be initialized once, this is the place                                                     
   *    to do it.                                                                                                          
   */                                                                                                                      
static void mdlStart(SimStruct *S)                                                                                         
{                                                                                                                          
                                                                                                                           
/****************************/                                                                                     
/*           START          */                                                                                     
/****************************/                                                                                     
                                                                                                                   
#if defined(RTICANMM_HAVE_VALID_PLATFORM)																		  
    static int start_once = 0;                                                                                     
    DsTError          Error         = DSCAN_NO_ERROR;                                                              
    boolean_T IN_RESET = INDEF_RESET;                                                                              
                                                                                                                   
#if defined(RTICANMM_HAVE_DSTS_H)                                                                                          
  HWTimeOffset = HWTimeOffset+ts_time_read();                                                                      
#endif                                                                                                             
    if (!start_once) {                                                                                             
        start_once = 1;                                                                                            
                                                                                                                   
#if !defined(CANMM_HOST_DEBUG)                                                                                     
#if defined(TJA)																								  
        /* Initializing the board piggy-back access */                                                         
        ds4302_port2_gst_sst_init( S, CAN_BOARD_BASE, CAN_BOARDNUMBER, CAN_CHANNELNO-1, CONF_OUTPUT_MASK );    
#endif                                                                                                         
#endif /* CANMM_HOST_DEBUG */                                                                                      
                                                                                                                   
    }                                                                                                              
                                                                                                                   
                                                                                                                   
#if defined(TJA)                                                                                               
       /* request the first read of the transceiver state */                                                   
       ds4302_can_mem_read_request(CAN_BOARD_BASE, PZS_TJA_COMM_CH, IndexRd);                                  
#endif                                                                                                         
                                                                                                                   
  if ((Error = DsCanCh_start(CanMM_channel)) != DSCAN_NO_ERROR)                                                    
    CANMM_DEBUG_ERROR(Error);                                                                                      
                                                                                                                   
  TransceiverState = IN_RESET;                                                                                     
                                                                                                                   
#endif  /* RTICANMM_HAVE_VALID_PLATFORM */                                                                                  
}                                                                                                                          
#endif /*  MDL_START */                                                                                                    
                                                                                                                           
                                                                                                                           
/* Function: mdlOutputs =======================================================                                            
 * Abstract:                                                                                                               
 *    In this function, you compute the outputs of your S-function                                                         
 *    block. Generally outputs are placed in the output vector, ssGetY(S).                                                 
 */                                                                                                                        
static void mdlOutputs(SimStruct *S, int_T tid)                                                                            
{                                                                                                                          
                                                                                                                           
/****************************/                                                                                     
/*          OUTPUTS         */                                                                                     
/****************************/                                                                                     
                                                                                                                   
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                          
    boolean_T IN_RESET = INDEF_RESET;                                                                              
    static int_T channel_started = 0;                                                                              
#if defined(TJA)                                                                                                     
    UInt32 ds4302_port2_read_data, ds4302_port2_write_data, actualState, actualError;                          
#endif                                                                                                         
                                                                                                                   
                                                                                                                   
    if (!channel_started) {                                                                                        
        ds4302_can_channel_start(CanMM_channel, CAN_INT_CONFIG);                                                       
        channel_started = 1;                                                                                       
    }                                                                                                              
                                                                                                                   
#if defined(TJA)                                                                                               
    /******************************************* SST ********************************/                         
    CANMM_CTL_SETUP_TutVar_C2_TX_STATUS = (INDEF_TJA1041STATUS == TJA1041_NORMAL)                                                     
      || (INDEF_TJA1041AUTOWAKEUP && (INDEF_TJA1041STATUS == TJA1041_GOTOSLEEP))                               
      || (INDEF_TJA1041AUTOWAKEUP && (INDEF_TJA1041STATUS == TJA1041_STANDBY));                                
                                                                                                               
    ds4302_port2_write_data = ((UInt32) INDEF_TJA1041STATUS)  & 0xFF;                                          
                                                                                                               
    /* check the range limits */                                                                               
    if (ds4302_port2_write_data > 3) {                                                                         
        ds4302_port2_write_data = 0x03;                                                                        
    }                                                                                                          
    if (ds4302_port2_write_data < 0) {                                                                         
        ds4302_port2_write_data = 0x00;                                                                        
    }                                                                                                          
                                                                                                               
    /* Calculate the auto-wake-up option */                                                                    
    if (!INDEF_TJA1041AUTOWAKEUP) {                                                                            
        ds4302_port2_write_data = ds4302_port2_write_data | 0x08; /* sets bit 3 */                             
    }                                                                                                          
                                                                                                               
    /* if the new value is equal the last written value, do nothing... */                                      
    if (ds4302_port2_write_data != (UInt32)LastWrittenData) {                                                  
                                                                                                               
        /* save the actual settings */                                                                         
        LastWrittenData = ds4302_port2_write_data;                                                             
                                                                                                               
        /* read all other pins      */                                                                         
        ds4302_port2_read( S, &ds4302_port2_read_data );                                                       
                                                                                                               
        /* calculate the new bitmap */                                                                         
        ds4302_port2_write_data = (ds4302_port2_read_data & 0xF0) | ds4302_port2_write_data;                   
                                                                                                               
        /* write the data to the piggy-back */                                                                 
        ds4302_can_mem_write( CAN_BOARD_BASE, PZS_TJA_COMM_CH, IndexWr, &ds4302_port2_write_data );            
                                                                                                               
        /* add the trigger signal to the bitmap */                                                             
        ds4302_port2_write_data = ds4302_port2_write_data | 0x04;                                              
                                                                                                               
        /* trigger the data-transmission to the transceiver-pins */                                            
        ds4302_can_mem_write( CAN_BOARD_BASE, PZS_TJA_COMM_CH, IndexWr, &ds4302_port2_write_data );            
                                                                                                               
        /* reset the clock pin (PIN 2) in the bitmap */                                                        
        ds4302_port2_write_data = ds4302_port2_write_data & (~0x04);                                           
                                                                                                               
        /* write them to the piggy-back */                                                                     
        ds4302_can_mem_write( CAN_BOARD_BASE, PZS_TJA_COMM_CH, IndexWr, &ds4302_port2_write_data );            
                                                                                                               
    }                                                                                                          
                                                                                                               
    /***************************  GST ******************************************                               
     * read all pins */                                                                                        
    ds4302_port2_read( S, &ds4302_port2_read_data );                                                           
                                                                                                               
    /* the status read pins are lying at PIN 5 and 6 (PIN's starting with 0) */                               
    actualState = (ds4302_port2_read_data & (CONF_BITCODE_GET_EN | CONF_BITCODE_GET_STB)) >> 5;                
                                                                                                               
    /* the error PIN is low activ */                                                                           
    actualError = !((ds4302_port2_read_data & CONF_ERROR_PIN) >> 7);                                           
                                                                                                               
    if (actualError) {                                                                                         
        switch (actualState) {                                                                                 
            case TJA1041_NORMAL: if (LastState == TJA1041_NORMAL) {                                            
                OUTDEF_TJA1041BUSFAILURE = 1; /* bus-error   */                                                
                OUTDEF_TJA1041WAKEUPFLAG = 0;                                                                  
            }                                                                                                  
            else                                                                                               
            {                                                                                                  
                OUTDEF_TJA1041BUSFAILURE = 0;                                                                  
                OUTDEF_TJA1041WAKEUPFLAG = 1; /* wake up     */                                                
            }                                                                                                  
            OUTDEF_TJA1041LOCALFAILURE = 0;                                                                    
            break;                                                                                             
            case TJA1041_STANDBY:                                                                              
            case TJA1041_GOTOSLEEP:                                                                            
                OUTDEF_TJA1041BUSFAILURE   = 0;                                                                
                OUTDEF_TJA1041LOCALFAILURE = 0;                                                                
                OUTDEF_TJA1041WAKEUPFLAG   = 1; /* wake up       */                                            
                break;                                                                                         
            case TJA1041_LISTENONLY:                                                                           
                OUTDEF_TJA1041BUSFAILURE   = 0;                                                                
                OUTDEF_TJA1041LOCALFAILURE = 1; /* local failure */                                            
                OUTDEF_TJA1041WAKEUPFLAG   = 0;                                                                
                break;                                                                                         
        }                                                                                                      
    }                                                                                                          
    else                                                                                                       
    {                                                                                                          
        OUTDEF_TJA1041BUSFAILURE   = 0;                                                                        
        OUTDEF_TJA1041LOCALFAILURE = 0;                                                                        
        OUTDEF_TJA1041WAKEUPFLAG   = 0;                                                                        
    }                                                                                                          
                                                                                                               
    OUTDEF_TJA1041STATUSOUT = (UInt8) actualState;                                                             
                                                                                                               
    /* save the actual state to LastState */                                                                   
    LastState = actualState;                                                                                   
#endif  /* TJA */                                                                                              
                                                                                                                   
#if defined(RTICANMM_HAVE_DSCAN_BUS)                                                                                       
    DsCanBus_update(CanMM_vBus, ssGetT(S));                                                                        
# endif                                                                                                            
                                                                                                                   
    RTICANMM_CanBoard_update(CanMM_board, CAN_BOARD_IDX);                                                          
                                                                                                                   
    if (CANMM_CTL_SETUP_TutVar_C2_VariationSwitch == 0) {                                                                                 
        CANMM_CTL_SETUP_TutVar_C2_ID = INDEF_VARIATION;                                                                                   
    }                                                                                                              
    else {                                                                                                         
        CANMM_CTL_SETUP_TutVar_C2_ID = CANMM_CTL_SETUP_TutVar_C2_Variation;                                                                                      
    }                                                                                                              
                                                                                                                   
#if !defined(CANMM_HOST_DEBUG)                                                                                    
    if (IN_RESET != TransceiverState) {                                                                                     
        ds4302_can_channel_BOff_return(CanMM_channel);                                                                     
        resetStateVars = 1;                                                                                        
        TransceiverState = IN_RESET;                                                                                        
    }                                                                                                              
                                                                                                                   
                                                                                                                   
                                                                                                                   
    newsampletime = ts_time_read();                                                                                
    if ((newsampletime - oldsampletime) > MONITORING_SLEEPTIME){                                                   
        oldsampletime = newsampletime;                                                                             
        ds4302_can_service_request(StatusService);                                                                         
        ds4302_can_service_read(StatusService);                                                                            
        if (StatusService->busstatus == 2)  // CAN Controller is Bus Off                                           
            ds4302_can_channel_BOff_return(CanMM_channel);                                                                 
                                                                                                                   
#if defined(DO_CONTROL_BUS)																						  
        if (resetStateVars){                                                                                       
            tempState_stuffbit_err = StatusService->stuffbit_err;                                                  
            tempState_form_err     = StatusService->form_err;                                                      
            tempState_ack_err      = StatusService->ack_err;                                                       
            tempState_bit0_err     = StatusService->bit0_err;                                                      
            tempState_bit1_err     = StatusService->bit1_err;                                                      
            tempState_crc_err      = StatusService->crc_err;                                                       
            tempState_rx_lost      = StatusService->rx_lost;                                                       
            tempState_rx_ok        = StatusService->rx_ok;                                                         
            tempState_tx_ok        = StatusService->tx_ok;                                                         
            resetStateVars         = 0;                                                                            
        }                                                                                                          
                                                                                                                   
#endif /* DO_CONTROL_BUS */                                                                                        
  }                                                                                                                
# endif /* CANMM_HOST_DEBUG */                                                                                                
#if defined(RTICANMM_DSDAQ_SERVICEID)                                                                                 
if (CANMMMonitor_TutVar_C2 > 0 && !(CANMMMonitor_TutVar_C2_old > 0)) { /* monitoring enabled */                                                          
  CANMM_CTL_RX_START(CANMM_CTL_SETUP_TutVar_C2, &ctlsetup_client);                                                                      
}                                                                                                                
if (!(CANMMMonitor_TutVar_C2 > 0) && CANMMMonitor_TutVar_C2_old > 0) { /* monitoring disabled */                                                         
  CANMM_CTL_RX_STOP(CANMM_CTL_SETUP_TutVar_C2, &ctlsetup_client);                                                                       
}                                                                                                                
CANMMMonitor_TutVar_C2_old = CANMMMonitor_TutVar_C2;                                                                                                     
                                                                                                                 
if (CANMMMonitor_TutVar_C2 > 0) {                                                                                                    
  while (CANMM_CTL_RX(CANMM_CTL_SETUP_TutVar_C2, &ctlsetup_client, &canmm_msg)) {                                                       
    int i = 0;                                                                                                   
                                                                                                                 
    if (canmm_msg.Flags & RTICANMM_FLAG_MSGLOST) {                                                               
      /* Do not monitor lost messages */                                                                         
      continue;                                                                                                  
    }                                                                                                            
                                                                                                                 
    /* Clear monitoring variables from last msg */                                                               
    for (i = 0; i < 4; i++) {                                                                                   
      RTICANMM_MonitorData[i] = 0;                                                                                                 
    }                                                                                                            
                                                                                                                 
    /* TBD optimize for uint8 data */                                                                            
    for (i=0;i<4;i++)                                                                                            
      RTICANMM_MonitorData[2] = (RTICANMM_MonitorData[2] | (canmm_msg.Data[i] << (8*i)));                                                            
                                                                                                                 
    for (i=4;i<8;i++)                                                                                            
      RTICANMM_MonitorData[3] = (RTICANMM_MonitorData[3] | (canmm_msg.Data[i] << (8*(i-4))));                                                        
                                                                                                                 
    RTICANMM_MonitorData[0] = canmm_msg.Id;                                                                                        
                                                                                                                 
    if (canmm_msg.Loopback)                                                                                      
      RTICANMM_MonitorData[1] |= 1;                                                                                                
    else                                                                                                         
      RTICANMM_MonitorData[1] |= 0;                                                                                                
                                                                                                                 
    RTICANMM_MonitorData[1] |= (canmm_msg.Dlc << 1);                                                                               
    RTICANMM_MonitorData[1] |= (2 << 17);                                                                                         
                                                                                                                 
    if(canmm_msg.Format == CANMM_MSG_FORMAT_EXT)                                                                 
      RTICANMM_MonitorData[1] |= (1 << 30);                                                                                        
    else                                                                                                         
      RTICANMM_MonitorData[1] |= (0 << 30);                                                                                        
    MonitoringTimeStamp_TutVar_C2 = canmm_msg.TimeStamp;                                                                                    
#if defined(RTICANMM_HAVE_HOSTSERVICE) | defined(RTICANMM_HAVE_DSDAQ)                                                            
    {                                                                                                            
    ts_timestamp_calculate(canmm_msg.TimeStamp+HWTimeOffset, &ts);                                               
    }                                                                                                            
#endif                                                                                                           
                                                                                                                 
#if defined(RTICANMM_HAVE_HOSTSERVICE)                                                                                   
    /* Call host_service for monitoring */                                                                       
    host_service(RTICANMM_DSDAQ_SERVICEID, &ts);                                                                      
#endif                                                                                                           
                                                                                                                 
#if defined(RTICANMM_HAVE_DSDAQ)                                                                                         
    /* Call DaqService for CalDesk monitoring */                                                                 
    DsDaq_Service(0, 0, RTICANMM_DSDAQ_SERVICEID, (DsDaqSTimestampStruct*) &ts);                                                     
#endif                                                                                                           
                                                                                                                 
#if defined(RTICANMM_HAVE_DSDAQ_WRAPPER)                                                                                 
    CANMM_DsDaqService(RTICANMM_DSDAQ_SERVICEID, canmm_msg.TimeStamp);                                                                     
#endif                                                                                                           
  }                                                                                                              
} /* host service enable */                                                                                      
#endif /* RTICANMM_DSDAQ_SERVICEID */                                                                                 
#endif  /* RTICANMM_HAVE_VALID_PLATFORM */                                                                                             
}                                                                                                                          
                                                                                                                           
                                                                                                                           
#define MDL_UPDATE  /* Change to #undef to remove function */                                                              
#if defined(MDL_UPDATE)                                                                                                    
  /* Function: mdlUpdate ======================================================                                            
   * Abstract:                                                                                                             
   *    This function is called once for every major integration time step.                                                
   *    Discrete states are typically updated here, but this function is useful                                            
   *    for performing any tasks that should only take place once per                                                      
   *    integration step.                                                                                                  
   */                                                                                                                      
static void mdlUpdate(SimStruct *S, int_T tid)                                                                             
{                                                                                                                          
                                                                                                                           
}                                                                                                                          
#endif /* MDL_UPDATE */                                                                                                    
                                                                                                                           
                                                                                                                           
#define MDL_DERIVATIVES  /* Change to #undef to remove function */                                                         
#if defined(MDL_DERIVATIVES)                                                                                               
  /* Function: mdlDerivatives =================================================                                            
   * Abstract:                                                                                                             
   *    In this function, you compute the S-function block's derivatives.                                                 
   *    The derivatives are placed in the derivative vector, ssGetdX(S).                                                   
   */                                                                                                                      
static void mdlDerivatives(SimStruct *S)                                                                                   
{                                                                                                                          
                                                                                                                           
}                                                                                                                          
#endif /* MDL_DERIVATIVES */                                                                                               
                                                                                                                           
                                                                                                                           
/* Function: mdlTerminate =====================================================                                            
 * Abstract:                                                                                                               
 *    In this function, you should perform any actions that are necessary                                                  
 *    at the termination of a simulation.  For example, if memory was                                                      
 *    allocated in mdlStart, this is the place to free it.                                                                 
 */                                                                                                                        
static void mdlTerminate(SimStruct *S)                                                                                     
{                                                                                                                          
                                                                                                                           
/****************************/                                                                                     
/*         TERMINATE        */                                                                                     
/****************************/                                                                                     
#if defined(RTICANMM_HAVE_VALID_PLATFORM)                                                                           
  DsTError          Error         = DSCAN_NO_ERROR;                                                                
                                                                                                                   
  CANMMMonitor_TutVar_C2_old = 0;                                                                                                      
  CANMM_CTL_RX_STOP(CANMM_CTL_SETUP_TutVar_C2, &ctlsetup_client);                                                                         
  if ((Error = DsCanCh_stop(CanMM_channel)) != DSCAN_NO_ERROR)                                                     
    CANMM_DEBUG_ERROR(Error);                                                                                      
#endif   /* RTICANMM_HAVE_VALID_PLATFORM */                                                                                 
}                                                                                                                          
                                                                                                                           
                                                                                                                           
/*=============================*                                                                                           
 * Required S-function trailer *                                                                                           
 *=============================*/                                                                                          
                                                                                                                           
#if defined(MATLAB_MEX_FILE)    	/* Is this file being compiled as a MEX-file? */                                          
#include <simulink.c>      		/* MEX-file interface mechanism */                                                        
#else                                                                                                                      
#include <cg_sfun.h>       		/* Code generation registration function */                                               
#endif                                                                                                                     
