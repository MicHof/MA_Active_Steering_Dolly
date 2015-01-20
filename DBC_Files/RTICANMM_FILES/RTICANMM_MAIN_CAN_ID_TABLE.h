/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_ID_TABLE */
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




/* ISO11992_EBS21 */
((UInt32*) IDPTR_MEM_R)[0] = (UInt32) RTICANMM_MAIN_CAN_copy_ISO11992_EBS21;
CANMMCAN_MIDTXSW[0] = 0;
CANMMCAN_RXCNT[0] = 0;
CANMMCAN_MIDRX[0] = 0xC0320C8;
CANMMCAN_MIDTXS[0] = 0xC0320C8;
CANMMCAN_RXMT[0] = RTICANMM_MESSAGE_TYPE_EXT;
CANMMCAN_MIDFRX[0] = 1;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[0] = 1;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[0] = 1;  /* 0: standard, 1:extended */ 



/* AngleSensor */
((UInt32*) IDPTR_MEM_R)[1] = (UInt32) RTICANMM_MAIN_CAN_copy_AngleSensor;
CANMMCAN_MIDTXSW[1] = 0;
CANMMCAN_RXCNT[1] = 0;
CANMMCAN_MIDRX[1] = 0x18FFA238;
CANMMCAN_MIDTXS[1] = 0x18FFA238;
CANMMCAN_RXMT[1] = RTICANMM_MESSAGE_TYPE_EXT;
CANMMCAN_MIDFRX[1] = 1;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[1] = 1;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[1] = 1;  /* 0: standard, 1:extended */ 
 
 


