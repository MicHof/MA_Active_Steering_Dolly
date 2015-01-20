/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_TX_INPUT */
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


/* RTICANMMFreeRawMessage_1 */
CANMMCAN_Arduino_MIDRX[0] = CANMMCAN_Arduino_MIDTXS[0]; 
/* RTICANMMFreeRawMessage_1.ID Format */ 
CANMMCAN_Arduino_MIDFTX[0] = CANMMCAN_Arduino_MIDFTXS[0]; 
CANMMCAN_Arduino_MIDFRX[0] = CANMMCAN_Arduino_MIDFTXS[0]; 
/* Simulator */ 

/* RTICANMMFreeRawMessage_1 */
CANMMCAN_Arduino_TXENIE[0] =  CANMMCAN_Arduino_TXEIN[0] && (CANMMCAN_Arduino_TXEEIE[0]) && CANMMCAN_Arduino_RTVE;
