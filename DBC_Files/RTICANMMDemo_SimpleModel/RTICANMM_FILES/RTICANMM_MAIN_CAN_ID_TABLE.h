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




/* RTFreeID1 */
((UInt32*) IDPTR_MEM_R)[0] = (UInt32) RTICANMM_MAIN_CAN_copy_RTFreeID1;
CANMMCAN_MIDTXSW[0] = 1;
CANMMCAN_RXCNT[0] = 0;
CANMMCAN_MIDRX[0] = 0x0;
CANMMCAN_MIDTXS[0] = 0x0;
CANMMCAN_RXMT[0] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[0] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[0] = 0;  /* 0: standard, 1:extended */ 



/* RTFreeID2 */
((UInt32*) IDPTR_MEM_R)[1] = (UInt32) RTICANMM_MAIN_CAN_copy_RTFreeID2;
CANMMCAN_MIDTXSW[1] = 1;
CANMMCAN_RXCNT[1] = 0;
CANMMCAN_MIDRX[1] = 0x0;
CANMMCAN_MIDTXS[1] = 0x0;
CANMMCAN_RXMT[1] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[1] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[1] = 0;  /* 0: standard, 1:extended */ 



/* RTFreeID3 */
((UInt32*) IDPTR_MEM_R)[2] = (UInt32) RTICANMM_MAIN_CAN_copy_RTFreeID3;
CANMMCAN_MIDTXSW[2] = 1;
CANMMCAN_RXCNT[2] = 0;
CANMMCAN_MIDRX[2] = 0x0;
CANMMCAN_MIDTXS[2] = 0x0;
CANMMCAN_RXMT[2] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[2] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[2] = 0;  /* 0: standard, 1:extended */ 



/* RTTMessage1 */
((UInt32*) IDPTR_MEM_R)[3] = (UInt32) RTICANMM_MAIN_CAN_copy_RTTMessage1;
CANMMCAN_MIDTXSW[3] = 1;
CANMMCAN_RXCNT[3] = 0;
CANMMCAN_MIDRX[3] = 0x0;
CANMMCAN_MIDTXS[3] = 0x0;
CANMMCAN_RXMT[3] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[3] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[3] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[3] = 0;  /* 0: standard, 1:extended */ 



/* RTTMessage2 */
((UInt32*) IDPTR_MEM_R)[4] = (UInt32) RTICANMM_MAIN_CAN_copy_RTTMessage2;
CANMMCAN_MIDTXSW[4] = 1;
CANMMCAN_RXCNT[4] = 0;
CANMMCAN_MIDRX[4] = 0x0;
CANMMCAN_MIDTXS[4] = 0x0;
CANMMCAN_RXMT[4] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[4] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[4] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[4] = 0;  /* 0: standard, 1:extended */ 



/* RTTMessage3 */
((UInt32*) IDPTR_MEM_R)[5] = (UInt32) RTICANMM_MAIN_CAN_copy_RTTMessage3;
CANMMCAN_MIDTXSW[5] = 1;
CANMMCAN_RXCNT[5] = 0;
CANMMCAN_MIDRX[5] = 0x0;
CANMMCAN_MIDTXS[5] = 0x0;
CANMMCAN_RXMT[5] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[5] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[5] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[5] = 0;  /* 0: standard, 1:extended */ 



/* standard */
((UInt32*) IDPTR_MEM_R)[6] = (UInt32) RTICANMM_MAIN_CAN_copy_standard;
CANMMCAN_MIDTXSW[6] = 0;
CANMMCAN_RXCNT[6] = 0;
CANMMCAN_MIDRX[6] = 0x73;
CANMMCAN_MIDTXS[6] = 0x73;
CANMMCAN_RXMT[6] = RTICANMM_MESSAGE_TYPE_STD;
CANMMCAN_MIDFRX[6] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[6] = 0;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[6] = 0;  /* 0: standard, 1:extended */ 



/* modesignals */
((UInt32*) IDPTR_MEM_R)[7] = (UInt32) RTICANMM_MAIN_CAN_copy_modesignals;
CANMMCAN_MIDTXSW[7] = 0;
CANMMCAN_RXCNT[7] = 0;
CANMMCAN_MIDRX[7] = 0x1E114000;
CANMMCAN_MIDTXS[7] = 0x1E114000;
CANMMCAN_RXMT[7] = RTICANMM_MESSAGE_TYPE_EXT;
CANMMCAN_MIDFRX[7] = 1;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTXS[7] = 1;  /* 0: standard, 1:extended */ 
CANMMCAN_MIDFTX[7] = 1;  /* 0: standard, 1:extended */ 
 
 


/* RTFreeID1 */
CANMMCAN_MIDTX[0] = 0; 
((UInt32*) IDPTR_MEM_T)[0] = (UInt32) RTICANMM_MAIN_CAN_copy_RTFreeID1;



/* RTFreeID2 */
CANMMCAN_MIDTX[1] = 1; 
((UInt32*) IDPTR_MEM_T)[1] = (UInt32) RTICANMM_MAIN_CAN_copy_RTFreeID2;



/* RTFreeID3 */
CANMMCAN_MIDTX[2] = 2; 
((UInt32*) IDPTR_MEM_T)[2] = (UInt32) RTICANMM_MAIN_CAN_copy_RTFreeID3;



/* RTTMessage1 */
CANMMCAN_MIDTX[3] = 3; 
((UInt32*) IDPTR_MEM_T)[3] = (UInt32) RTICANMM_MAIN_CAN_copy_RTTMessage1;



/* RTTMessage2 */
CANMMCAN_MIDTX[4] = 4; 
((UInt32*) IDPTR_MEM_T)[4] = (UInt32) RTICANMM_MAIN_CAN_copy_RTTMessage2;



/* RTTMessage3 */
CANMMCAN_MIDTX[5] = 5; 
((UInt32*) IDPTR_MEM_T)[5] = (UInt32) RTICANMM_MAIN_CAN_copy_RTTMessage3;



/* standard */
CANMMCAN_MIDTX[6] = 6; 
((UInt32*) IDPTR_MEM_T)[6] = (UInt32) RTICANMM_MAIN_CAN_copy_standard;



/* modesignals */
CANMMCAN_MIDTX[7] = 7; 
((UInt32*) IDPTR_MEM_T)[7] = (UInt32) RTICANMM_MAIN_CAN_copy_modesignals;



