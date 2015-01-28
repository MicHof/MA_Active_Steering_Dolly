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




/* New_Message_1 */
((UInt32*) IDPTR_MEM_R)[0] = (UInt32) RTICANMM_MAIN_CAN_Arduino_copy_New_Message_1;
CANMMCAN_Arduino_MIDTXSW[0] = 0;
CANMMCAN_Arduino_RXCNT[0] = 0;
CANMMCAN_Arduino_MIDRX[0] = 0x3;
CANMMCAN_Arduino_MIDTXS[0] = 0x3;
CANMMCAN_Arduino_RXMT[0] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_Arduino_MIDFRX[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Arduino_MIDFTXS[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_Arduino_MIDFTX[0] = 0;  /* 0: standard, 1:extended */ 
 
 


