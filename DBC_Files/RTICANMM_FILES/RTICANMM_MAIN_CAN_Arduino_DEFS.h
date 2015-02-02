/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_DEFS */
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


/*********
 *  New_Message_1 - 1
 *     New_Message_1.New_Signal_3 - 1
 */
volatile uint8_T CANMMCAN_Arduino_RTVE;
volatile boolean_T CANMMCAN_Arduino_TRAFFIC;
volatile int32_T CANMMCAN_Arduino_MAXMSGPERSTEP;

volatile uint8_T CANMMCAN_Arduino_TVAR8;

volatile uint8_T CANMMCAN_Arduino_TVAR8_2;

volatile uint32_T CANMMCAN_Arduino_TVAR32;

volatile uint8_T CANMMCAN_Arduino_TVAR8A[8];

volatile double CANMMCAN_Arduino_TVARD;
volatile double CANMMCAN_Arduino_TVARD2;

/* Globale Enable */
volatile boolean_T CANMMCAN_Arduino_GEIN;
#define CANMMCAN_Arduino_GE CANMMCAN_Arduino_GEIN

/* Reset */
#define CANMMCAN_Arduino_RE 1


/* Feedthrough debug variable*/
volatile uint8_T CANMMCAN_Arduino_FTD;


#define ID_Table_RX(X) (int)(CANMMCAN_Arduino_MIDRX[X])
#define ID_Table_TX(X) (int)(CANMMCAN_Arduino_MIDTX[X])
uint8_T CANMMCAN_Arduino_MIDTXSW[NUM_RX_MSG];
uint32_T CANMMCAN_Arduino_MIDTXIN[NUM_RX_MSG];
uint32_T CANMMCAN_Arduino_MIDTXS[NUM_RX_MSG];
uint32_T CANMMCAN_Arduino_MIDRX[NUM_RX_MSG];
uint8_T CANMMCAN_Arduino_MIDFRX[NUM_RX_MSG];
uint8_T CANMMCAN_Arduino_MIDFTXIN[NUM_RX_MSG];
uint8_T CANMMCAN_Arduino_MIDFTXS[NUM_RX_MSG];
uint8_T CANMMCAN_Arduino_MIDFTX[NUM_RX_MSG];
uint8_T CANMMCAN_Arduino_RXMT[NUM_RX_MSG];
 

volatile real_T CANMMCAN_Arduino_RXt[NUM_RX_MSG];
volatile real_T CANMMCAN_Arduino_RXdt[NUM_RX_MSG];
volatile boolean_T CANMMCAN_Arduino_RXsta[NUM_RX_MSG];
volatile uint8_T CANMMCAN_Arduino_RXerr[NUM_RX_MSG];
volatile real_T CANMMCAN_Arduino_RXCTMIN[NUM_RX_MSG];
volatile real_T CANMMCAN_Arduino_RXCTMAX[NUM_RX_MSG];
volatile uint8_T CANMMCAN_Arduino_RXLEN[NUM_RX_MSG];
volatile uint32_T CANMMCAN_Arduino_RXCNT[NUM_RX_MSG];


/* Define RX/TX structure */

volatile real_T CANMMCAN_Arduino_RXCT1;
Int16 CANMMCAN_Arduino_RX_Msg_1_Sgn_1;






