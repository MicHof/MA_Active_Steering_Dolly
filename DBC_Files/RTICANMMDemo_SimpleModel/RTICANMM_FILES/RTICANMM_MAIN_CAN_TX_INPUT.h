/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_TX_INPUT */
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

CANMMCAN_TXLEN[3] = CANMMCAN_RTTTX[0].len;
CANMMCAN_TXLEN[4] = CANMMCAN_RTTTX[1].len;
CANMMCAN_TXLEN[5] = CANMMCAN_RTTTX[2].len;

/* modesignals */

/* standard */

/* RTFreeID1 */
CANMMCAN_MIDRX[0] = CANMMCAN_MIDTXS[0]; 
/* RTFreeID1.ID Format */ 
CANMMCAN_MIDFTX[0] = CANMMCAN_MIDFTXS[0]; 
CANMMCAN_MIDFRX[0] = CANMMCAN_MIDFTXS[0]; 

/* RTFreeID2 */
CANMMCAN_MIDRX[1] = CANMMCAN_MIDTXS[1]; 
/* RTFreeID2.ID Format */ 
CANMMCAN_MIDFTX[1] = CANMMCAN_MIDFTXS[1]; 
CANMMCAN_MIDFRX[1] = CANMMCAN_MIDFTXS[1]; 

/* RTFreeID3 */
CANMMCAN_MIDRX[2] = CANMMCAN_MIDTXS[2]; 
/* RTFreeID3.ID Format */ 
CANMMCAN_MIDFTX[2] = CANMMCAN_MIDFTXS[2]; 
CANMMCAN_MIDFRX[2] = CANMMCAN_MIDFTXS[2]; 

/* RTTMessage1 */
CANMMCAN_TXCT[3] = CANMMCAN_RTTTX[0].CycleTime;
CANMMCAN_MIDRX[3] = CANMMCAN_RTTTX[0].identifier;
CANMMCAN_MIDFTX[3] = CANMMCAN_RTTTX[0].idformat;
CANMMCAN_MIDFRX[3] = CANMMCAN_RTTTX[0].idformat;

/* RTTMessage2 */
CANMMCAN_TXCT[4] = CANMMCAN_RTTTX[1].CycleTime;
CANMMCAN_MIDRX[4] = CANMMCAN_RTTTX[1].identifier;
CANMMCAN_MIDFTX[4] = CANMMCAN_RTTTX[1].idformat;
CANMMCAN_MIDFRX[4] = CANMMCAN_RTTTX[1].idformat;

/* RTTMessage3 */
CANMMCAN_TXCT[5] = CANMMCAN_RTTTX[2].CycleTime;
CANMMCAN_MIDRX[5] = CANMMCAN_RTTTX[2].identifier;
CANMMCAN_MIDFTX[5] = CANMMCAN_RTTTX[2].idformat;
CANMMCAN_MIDFRX[5] = CANMMCAN_RTTTX[2].idformat;
/* ECU */ 
/* Simulator */ 

/* RTFreeID1 */
CANMMCAN_TXENIE[0] =  CANMMCAN_TXEIN[0] && (CANMMCAN_TXEEIE[1]);

/* RTFreeID2 */
CANMMCAN_TXENIE[1] =  CANMMCAN_TXEIN[1] && (CANMMCAN_TXEEIE[1]);

/* RTFreeID3 */
CANMMCAN_TXENIE[2] =  CANMMCAN_TXEIN[2] && (CANMMCAN_TXEEIE[1]);

/* RTTMessage1 */
CANMMCAN_TXENIE[3] = CANMMCAN_RTTTX[0].Enable;
CANMMCAN_TXCIE[3] = CANMMCAN_RTTTX[0].Cyclic;
CANMMCAN_TXKIEX[3] = CANMMCAN_RTTTX[0].Kickout;
CANMMCAN_RTTTX[0].Kickout = 0;

/* RTTMessage2 */
CANMMCAN_TXENIE[4] = CANMMCAN_RTTTX[1].Enable;
CANMMCAN_TXCIE[4] = CANMMCAN_RTTTX[1].Cyclic;
CANMMCAN_TXKIEX[4] = CANMMCAN_RTTTX[1].Kickout;
CANMMCAN_RTTTX[1].Kickout = 0;

/* RTTMessage3 */
CANMMCAN_TXENIE[5] = CANMMCAN_RTTTX[2].Enable;
CANMMCAN_TXCIE[5] = CANMMCAN_RTTTX[2].Cyclic;
CANMMCAN_TXKIEX[5] = CANMMCAN_RTTTX[2].Kickout;
CANMMCAN_RTTTX[2].Kickout = 0;

/* standard */
CANMMCAN_TXENIE[6] =  CANMMCAN_TXEIN[6] && (CANMMCAN_TXEEIE[0]) && CANMMCAN_RTVE;

/* modesignals */
CANMMCAN_TXENIE[7] =  CANMMCAN_TXEIN[7] && (CANMMCAN_TXEEIE[0]) && CANMMCAN_RTVE;
