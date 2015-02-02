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
 *  IMU_accelerometer - 1
 *     IMU_accelerometer.x - 1
 *     IMU_accelerometer.y - 2
 *     IMU_accelerometer.z - 3
 */

/*********
 *  IMU_angels_corrected - 2
 *     IMU_angels_corrected.x - 1
 *     IMU_angels_corrected.y - 2
 *     IMU_angels_corrected.z - 3
 */

/*********
 *  IMU_gyroskop - 3
 *     IMU_gyroskop.x - 1
 *     IMU_gyroskop.y - 2
 *     IMU_gyroskop.z - 3
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

/* Globale Enable TX */
volatile boolean_T CANMMCAN_Arduino_TXGEIN;
#define CANMMCAN_Arduino_TXGE CANMMCAN_Arduino_TXGEIN
                               
                               
/* ECU ENABLE */               
volatile boolean_T CANMMCAN_Arduino_TXEEIE[1] = {1};     
volatile boolean_T CANMMCAN_Arduino_TXEEIEOLD[1] = {1};     
volatile boolean_T CANMMCAN_Arduino_TXECUEN_Vector__XXX = 1;   
                            
                            

/* Message would be sent */
volatile uint8_T CANMMCAN_Arduino_WBS[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Arduino_BYKICK[NUM_TX_MSG];

/* Message enable */
volatile boolean_T CANMMCAN_Arduino_TXENIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Arduino_TXEIN[NUM_TX_MSG];
#define CANMMCAN_Arduino_TXEN(X) (CANMMCAN_Arduino_TXENIE[X])
#define USE_LOCAL_ENABLE

/* Cyclic triggering */
volatile boolean_T CANMMCAN_Arduino_TXCIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Arduino_TXCIN[NUM_TX_MSG];
#define CANMMCAN_Arduino_TXC(X) (CANMMCAN_Arduino_TXCIE[X])

/* Message kickout */
volatile boolean_T CANMMCAN_Arduino_TXKIEX[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Arduino_TXKIN[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Arduino_TXKIEXC[NUM_TX_MSG];
#define CANMMCAN_Arduino_TXKOUT(X) (CANMMCAN_Arduino_TXKIEX[X])
#undef MESSAGETIMEOUT


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
uint32_T CANMMCAN_Arduino_MIDTX[NUM_TX_MSG];
volatile real_T CANMMCAN_Arduino_TXCT[NUM_TX_MSG];
volatile real_T CANMMCAN_Arduino_TXDT[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Arduino_TXcraw[NUM_TX_MSG];
volatile boolean_T CANMMCAN_Arduino_TXsta[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Arduino_TXRBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Arduino_TXRXBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Arduino_TXusrm[NUM_TX_MSG];
volatile uint8_T CANMMCAN_Arduino_TXLEN[NUM_TX_MSG];


/* Define RX/TX structure */

Int16 CANMMCAN_Arduino_RX_Msg_1_Sgn_1;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_1;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_1_constant;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_1_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_1_error;
Int16 CANMMCAN_Arduino_RX_Msg_1_Sgn_2;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_2;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_2_constant;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_2_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_2_error;
Int16 CANMMCAN_Arduino_RX_Msg_1_Sgn_3;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_3;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_3_constant;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_3_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_1_Sgn_3_error;
Int16 CANMMCAN_Arduino_RX_Msg_2_Sgn_1;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_1;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_1_constant;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_1_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_1_error;
Int16 CANMMCAN_Arduino_RX_Msg_2_Sgn_2;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_2;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_2_constant;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_2_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_2_error;
Int16 CANMMCAN_Arduino_RX_Msg_2_Sgn_3;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_3;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_3_constant;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_3_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_2_Sgn_3_error;
Int16 CANMMCAN_Arduino_RX_Msg_3_Sgn_1;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_1;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_1_constant;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_1_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_1_error;
Int16 CANMMCAN_Arduino_RX_Msg_3_Sgn_2;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_2;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_2_constant;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_2_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_2_error;
Int16 CANMMCAN_Arduino_RX_Msg_3_Sgn_3;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_3;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_3_constant;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_3_DynValue;
Int16 CANMMCAN_Arduino_TX_Msg_3_Sgn_3_error;






volatile uint8_T CANMMCAN_Arduino_TXs[9];
volatile uint8_T CANMMCAN_Arduino_TXm[9];
volatile uint8_T CANMMCAN_Arduino_TXGWs[9];
volatile uint32_T CANMMCAN_Arduino_TXcdo[9];
