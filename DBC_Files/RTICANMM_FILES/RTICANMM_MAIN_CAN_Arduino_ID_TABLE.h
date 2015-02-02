/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_ID_TABLE */
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




/* IMU_accelerometer */
((UInt32*) IDPTR_MEM_R)[0] = (UInt32) RTICANMM_MAIN_CAN_Arduino_copy_IMU_accelerometer;
CANMMCAN_Arduino_MIDTXSW[0] = 0;
CANMMCAN_Arduino_RXCNT[0] = 0;
CANMMCAN_Arduino_MIDRX[0] = 0x1;
CANMMCAN_Arduino_MIDTXS[0] = 0x1;
CANMMCAN_Arduino_RXMT[0] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Arduino_MIDFRX[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Arduino_MIDFTXS[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Arduino_MIDFTX[0] = 0;  /* 0: standard, 1:extended */ 



/* IMU_gyroskop */
((UInt32*) IDPTR_MEM_R)[1] = (UInt32) RTICANMM_MAIN_CAN_Arduino_copy_IMU_gyroskop;
CANMMCAN_Arduino_MIDTXSW[1] = 0;
CANMMCAN_Arduino_RXCNT[1] = 0;
CANMMCAN_Arduino_MIDRX[1] = 0x2;
CANMMCAN_Arduino_MIDTXS[1] = 0x2;
CANMMCAN_Arduino_RXMT[1] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Arduino_MIDFRX[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Arduino_MIDFTXS[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Arduino_MIDFTX[1] = 0;  /* 0: standard, 1:extended */ 



/* IMU_angels_corrected */
((UInt32*) IDPTR_MEM_R)[2] = (UInt32) RTICANMM_MAIN_CAN_Arduino_copy_IMU_angels_corrected;
CANMMCAN_Arduino_MIDTXSW[2] = 0;
CANMMCAN_Arduino_RXCNT[2] = 0;
CANMMCAN_Arduino_MIDRX[2] = 0x3;
CANMMCAN_Arduino_MIDTXS[2] = 0x3;
CANMMCAN_Arduino_RXMT[2] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Arduino_MIDFRX[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Arduino_MIDFTXS[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Arduino_MIDFTX[2] = 0;  /* 0: standard, 1:extended */ 
 
 


/* IMU_accelerometer */
CANMMCAN_Arduino_MIDTX[0] = 0; 
((UInt32*) IDPTR_MEM_T)[0] = (UInt32) RTICANMM_MAIN_CAN_Arduino_copy_IMU_accelerometer;



/* IMU_gyroskop */
CANMMCAN_Arduino_MIDTX[1] = 1; 
((UInt32*) IDPTR_MEM_T)[1] = (UInt32) RTICANMM_MAIN_CAN_Arduino_copy_IMU_gyroskop;



/* IMU_angels_corrected */
CANMMCAN_Arduino_MIDTX[2] = 2; 
((UInt32*) IDPTR_MEM_T)[2] = (UInt32) RTICANMM_MAIN_CAN_Arduino_copy_IMU_angels_corrected;



