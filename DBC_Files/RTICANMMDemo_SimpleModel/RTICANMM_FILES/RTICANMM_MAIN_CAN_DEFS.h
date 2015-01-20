/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_DEFS */
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
 *  modesignals - 1
 *     modesignals.Modes - 1
 *     modesignals.test_1 - 2
 *     modesignals.test_2 - 3
 *     modesignals.test_3 - 4
 *     modesignals.test_4 - 5
 *     modesignals.modemanager - 6
 *     modesignals.isactivemode2_1 - 7
 *     modesignals.isactivemode15_1 - 8
 *     modesignals.isactivemode15_2 - 9
 *     modesignals.isactivemode2_2 - 10
 *     modesignals.test_5 - 11
 */

/*********
 *  standard - 2
 *     standard.SignalWithError - 1
 *     standard.Bit_4 - 2
 *     standard.Bit_3 - 3
 *     standard.Bit_2 - 4
 *     standard.Bit_1 - 5
 *     standard.Signed - 6
 *     standard.Temperature - 7
 *     standard.SignalFactor - 8
 *     standard.SignalOffset - 9
 *     standard.CRC - 10
 */

/*********
 *  RTFreeID1 - 3
 *     RTFreeID1.RAW_Byte_1 - 1
 *     RTFreeID1.RAW_Byte_2 - 2
 *     RTFreeID1.RAW_Byte_3 - 3
 *     RTFreeID1.RAW_Byte_4 - 4
 *     RTFreeID1.RAW_Byte_5 - 5
 *     RTFreeID1.RAW_Byte_6 - 6
 *     RTFreeID1.RAW_Byte_7 - 7
 *     RTFreeID1.RAW_Byte_8 - 8
 */

/*********
 *  RTFreeID2 - 4
 *     RTFreeID2.RAW_Byte_1 - 1
 *     RTFreeID2.RAW_Byte_2 - 2
 *     RTFreeID2.RAW_Byte_3 - 3
 *     RTFreeID2.RAW_Byte_4 - 4
 *     RTFreeID2.RAW_Byte_5 - 5
 *     RTFreeID2.RAW_Byte_6 - 6
 *     RTFreeID2.RAW_Byte_7 - 7
 *     RTFreeID2.RAW_Byte_8 - 8
 */

/*********
 *  RTFreeID3 - 5
 *     RTFreeID3.RAW_Byte_1 - 1
 *     RTFreeID3.RAW_Byte_2 - 2
 *     RTFreeID3.RAW_Byte_3 - 3
 *     RTFreeID3.RAW_Byte_4 - 4
 *     RTFreeID3.RAW_Byte_5 - 5
 *     RTFreeID3.RAW_Byte_6 - 6
 *     RTFreeID3.RAW_Byte_7 - 7
 *     RTFreeID3.RAW_Byte_8 - 8
 */

/*********
 *  RTTMessage1 - 6
 *     RTTMessage1.RAW_Byte_1 - 1
 *     RTTMessage1.RAW_Byte_2 - 2
 *     RTTMessage1.RAW_Byte_3 - 3
 *     RTTMessage1.RAW_Byte_4 - 4
 *     RTTMessage1.RAW_Byte_5 - 5
 *     RTTMessage1.RAW_Byte_6 - 6
 *     RTTMessage1.RAW_Byte_7 - 7
 *     RTTMessage1.RAW_Byte_8 - 8
 */

/*********
 *  RTTMessage2 - 7
 *     RTTMessage2.RAW_Byte_1 - 1
 *     RTTMessage2.RAW_Byte_2 - 2
 *     RTTMessage2.RAW_Byte_3 - 3
 *     RTTMessage2.RAW_Byte_4 - 4
 *     RTTMessage2.RAW_Byte_5 - 5
 *     RTTMessage2.RAW_Byte_6 - 6
 *     RTTMessage2.RAW_Byte_7 - 7
 *     RTTMessage2.RAW_Byte_8 - 8
 */

/*********
 *  RTTMessage3 - 8
 *     RTTMessage3.RAW_Byte_1 - 1
 *     RTTMessage3.RAW_Byte_2 - 2
 *     RTTMessage3.RAW_Byte_3 - 3
 *     RTTMessage3.RAW_Byte_4 - 4
 *     RTTMessage3.RAW_Byte_5 - 5
 *     RTTMessage3.RAW_Byte_6 - 6
 *     RTTMessage3.RAW_Byte_7 - 7
 *     RTTMessage3.RAW_Byte_8 - 8
 */
volatile uint8_T CANMMCAN_TXAIDX1;
volatile uint8_T CANMMCAN_TXAIDX2;
volatile uint8_T CANMMCAN_TXAIDX3;
volatile uint8_T CANMMCAN_TXAIDX4;
volatile uint8_T CANMMCAN_TXAIDX5;
volatile uint8_T CANMMCAN_TXAIDX6;
volatile uint8_T CANMMCAN_RTTNM;
RTICANMMMsgStruct CANMMCAN_RTTTX[3];
RTICANMMMsgStruct CANMMCAN_RTTRX[3];
#if defined(RTI_SE_RTT_ENABLE)
#endif
volatile uint8_T CANMMCAN_RTVE;
volatile boolean_T CANMMCAN_TRAFFIC;
volatile int32_T CANMMCAN_MAXMSGPERSTEP;

volatile uint8_T CANMMCAN_TVAR8;

volatile uint8_T CANMMCAN_TVAR8_2;

volatile uint32_T CANMMCAN_TVAR32;

volatile uint8_T CANMMCAN_TVAR8A[8];

volatile double CANMMCAN_TVARD;
volatile double CANMMCAN_TVARD2;

/* Globale Enable */
volatile boolean_T CANMMCAN_GEIN;
#define CANMMCAN_GE CANMMCAN_GEIN

/* Reset */
#define CANMMCAN_RE 1


/* Feedthrough debug variable*/
volatile uint8_T CANMMCAN_FTD;

/* Globale Enable TX */
volatile boolean_T CANMMCAN_TXGEIN;
#define CANMMCAN_TXGE CANMMCAN_TXGEIN
                               
                               
/* ECU ENABLE */               
volatile boolean_T CANMMCAN_TXEEIE[2] = {1, 1};     
volatile boolean_T CANMMCAN_TXEEIEOLD[2] = {1, 1};     
volatile boolean_T CANMMCAN_TXECUEN_ECU = 1;   
volatile boolean_T CANMMCAN_TXECUEN_Simulator = 1;   
                            
                            

/* Message would be sent */
volatile uint8_T CANMMCAN_WBS[NUM_TX_MSG];
volatile boolean_T CANMMCAN_BYKICK[NUM_TX_MSG];

/* Message enable */
volatile boolean_T CANMMCAN_TXENIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXEIN[NUM_TX_MSG];
#define CANMMCAN_TXEN(X) (CANMMCAN_TXENIE[X])
#define USE_LOCAL_ENABLE

/* Cyclic triggering */
volatile boolean_T CANMMCAN_TXCIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXCIN[NUM_TX_MSG];
#define CANMMCAN_TXC(X) (CANMMCAN_TXCIE[X])

/* Message kickout */
volatile boolean_T CANMMCAN_TXKIEX[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXKIN[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXKIEXC[NUM_TX_MSG];
#define CANMMCAN_TXKOUT(X) (CANMMCAN_TXKIEX[X])
#undef MESSAGETIMEOUT


#define ID_Table_RX(X) (int)(CANMMCAN_MIDRX[X])
#define ID_Table_TX(X) (int)(CANMMCAN_MIDTX[X])
uint8_T CANMMCAN_MIDTXSW[NUM_RX_MSG];
uint32_T CANMMCAN_MIDTXIN[NUM_RX_MSG];
uint32_T CANMMCAN_MIDTXS[NUM_RX_MSG];
uint32_T CANMMCAN_MIDRX[NUM_RX_MSG];
uint8_T CANMMCAN_MIDFRX[NUM_RX_MSG];
uint8_T CANMMCAN_MIDFTXIN[NUM_RX_MSG];
uint8_T CANMMCAN_MIDFTXS[NUM_RX_MSG];
uint8_T CANMMCAN_MIDFTX[NUM_RX_MSG];
uint8_T CANMMCAN_RXMT[NUM_RX_MSG];
 

volatile real_T CANMMCAN_RXt[NUM_RX_MSG];
volatile real_T CANMMCAN_RXdt[NUM_RX_MSG];
volatile boolean_T CANMMCAN_RXsta[NUM_RX_MSG];
volatile uint8_T CANMMCAN_RXerr[NUM_RX_MSG];
volatile real_T CANMMCAN_RXCTMIN[NUM_RX_MSG];
volatile real_T CANMMCAN_RXCTMAX[NUM_RX_MSG];
volatile uint8_T CANMMCAN_RXLEN[NUM_RX_MSG];
volatile uint32_T CANMMCAN_RXCNT[NUM_RX_MSG];
uint32_T CANMMCAN_MIDTX[NUM_TX_MSG];
volatile real_T CANMMCAN_TXCT[NUM_TX_MSG];
volatile real_T CANMMCAN_TXDT[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXcraw[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXsta[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXRBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXRXBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXusrm[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXLEN[NUM_TX_MSG];


/* Define RX/TX structure */

UInt8 CANMMCAN_RX_Msg_1_Sgn_1;
UInt8 CANMMCAN_TX_Msg_1_Sgn_1;
UInt8 CANMMCAN_TX_Msg_1_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_1_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_2;
UInt8 CANMMCAN_TX_Msg_1_Sgn_2;
UInt8 CANMMCAN_TX_Msg_1_Sgn_2_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_2_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_3;
UInt8 CANMMCAN_TX_Msg_1_Sgn_3;
UInt8 CANMMCAN_TX_Msg_1_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_4;
UInt8 CANMMCAN_TX_Msg_1_Sgn_4;
UInt8 CANMMCAN_TX_Msg_1_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_4_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_5;
UInt8 CANMMCAN_TX_Msg_1_Sgn_5;
UInt8 CANMMCAN_TX_Msg_1_Sgn_5_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_5_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_5_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_6;
UInt8 CANMMCAN_TX_Msg_1_Sgn_6;
UInt8 CANMMCAN_TX_Msg_1_Sgn_6_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_6_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_6_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_7;
UInt8 CANMMCAN_TX_Msg_1_Sgn_7;
UInt8 CANMMCAN_TX_Msg_1_Sgn_7_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_7_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_7_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_8;
UInt8 CANMMCAN_TX_Msg_1_Sgn_8;
UInt8 CANMMCAN_TX_Msg_1_Sgn_8_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_8_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_8_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_9;
UInt8 CANMMCAN_TX_Msg_1_Sgn_9;
UInt8 CANMMCAN_TX_Msg_1_Sgn_9_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_9_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_9_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_10;
UInt8 CANMMCAN_TX_Msg_1_Sgn_10;
UInt8 CANMMCAN_TX_Msg_1_Sgn_10_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_10_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_10_error;
UInt8 CANMMCAN_RX_Msg_1_Sgn_11;
UInt8 CANMMCAN_TX_Msg_1_Sgn_11;
UInt8 CANMMCAN_TX_Msg_1_Sgn_11_constant;
UInt8 CANMMCAN_TX_Msg_1_Sgn_11_DynValue;
UInt8 CANMMCAN_TX_Msg_1_Sgn_11_error;
UInt8 CANMMCAN_RX_Msg_2_Sgn_1;
UInt8 CANMMCAN_TX_Msg_2_Sgn_1;
UInt8 CANMMCAN_TX_Msg_2_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_2_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_2_Sgn_1_error;
UInt8 CANMMCAN_RX_Msg_2_Sgn_2;
UInt8 CANMMCAN_TX_Msg_2_Sgn_2;
UInt8 CANMMCAN_TX_Msg_2_Sgn_2_constant;
UInt8 CANMMCAN_TX_Msg_2_Sgn_2_DynValue;
UInt8 CANMMCAN_TX_Msg_2_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_2_Sgn_3;
UInt8 CANMMCAN_TX_Msg_2_Sgn_3;
UInt8 CANMMCAN_TX_Msg_2_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_2_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_2_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_2_Sgn_4;
UInt8 CANMMCAN_TX_Msg_2_Sgn_4;
UInt8 CANMMCAN_TX_Msg_2_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_2_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_2_Sgn_4_error;
UInt8 CANMMCAN_RX_Msg_2_Sgn_5;
UInt8 CANMMCAN_TX_Msg_2_Sgn_5;
UInt8 CANMMCAN_TX_Msg_2_Sgn_5_constant;
UInt8 CANMMCAN_TX_Msg_2_Sgn_5_DynValue;
UInt8 CANMMCAN_TX_Msg_2_Sgn_5_error;
double CANMMCAN_RX_Msg_2_Sgn_6;
double CANMMCAN_TX_Msg_2_Sgn_6;
double CANMMCAN_TX_Msg_2_Sgn_6_constant;
double CANMMCAN_TX_Msg_2_Sgn_6_DynValue;
double CANMMCAN_TX_Msg_2_Sgn_6_error;
Int16 CANMMCAN_RX_Msg_2_Sgn_7;
Int16 CANMMCAN_TX_Msg_2_Sgn_7;
Int16 CANMMCAN_TX_Msg_2_Sgn_7_constant;
Int16 CANMMCAN_TX_Msg_2_Sgn_7_DynValue;
Int16 CANMMCAN_TX_Msg_2_Sgn_7_error;
double CANMMCAN_RX_Msg_2_Sgn_8;
double CANMMCAN_TX_Msg_2_Sgn_8;
double CANMMCAN_TX_Msg_2_Sgn_8_constant;
double CANMMCAN_TX_Msg_2_Sgn_8_DynValue;
double CANMMCAN_TX_Msg_2_Sgn_8_error;
UInt8 CANMMCAN_RX_Msg_2_Sgn_9;
UInt8 CANMMCAN_TX_Msg_2_Sgn_9;
UInt8 CANMMCAN_TX_Msg_2_Sgn_9_constant;
UInt8 CANMMCAN_TX_Msg_2_Sgn_9_DynValue;
UInt8 CANMMCAN_TX_Msg_2_Sgn_9_error;
UInt8 CANMMCAN_RX_Msg_2_Sgn_10;
UInt8 CANMMCAN_TX_Msg_2_Sgn_10;
UInt8 CANMMCAN_TX_Msg_2_Sgn_10_constant;
UInt8 CANMMCAN_TX_Msg_2_Sgn_10_DynValue;
UInt8 CANMMCAN_TX_Msg_2_Sgn_10_error;
UInt8 CANMMCAN_RX_Msg_3_Sgn_1;
UInt8 CANMMCAN_TX_Msg_3_Sgn_1;
UInt8 CANMMCAN_TX_Msg_3_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_3_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_3_Sgn_1_error;
UInt8 CANMMCAN_RX_Msg_3_Sgn_2;
UInt8 CANMMCAN_TX_Msg_3_Sgn_2;
UInt8 CANMMCAN_TX_Msg_3_Sgn_2_constant;
UInt8 CANMMCAN_TX_Msg_3_Sgn_2_DynValue;
UInt8 CANMMCAN_TX_Msg_3_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_3_Sgn_3;
UInt8 CANMMCAN_TX_Msg_3_Sgn_3;
UInt8 CANMMCAN_TX_Msg_3_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_3_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_3_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_3_Sgn_4;
UInt8 CANMMCAN_TX_Msg_3_Sgn_4;
UInt8 CANMMCAN_TX_Msg_3_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_3_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_3_Sgn_4_error;
UInt8 CANMMCAN_RX_Msg_3_Sgn_5;
UInt8 CANMMCAN_TX_Msg_3_Sgn_5;
UInt8 CANMMCAN_TX_Msg_3_Sgn_5_constant;
UInt8 CANMMCAN_TX_Msg_3_Sgn_5_DynValue;
UInt8 CANMMCAN_TX_Msg_3_Sgn_5_error;
UInt8 CANMMCAN_RX_Msg_3_Sgn_6;
UInt8 CANMMCAN_TX_Msg_3_Sgn_6;
UInt8 CANMMCAN_TX_Msg_3_Sgn_6_constant;
UInt8 CANMMCAN_TX_Msg_3_Sgn_6_DynValue;
UInt8 CANMMCAN_TX_Msg_3_Sgn_6_error;
UInt8 CANMMCAN_RX_Msg_3_Sgn_7;
UInt8 CANMMCAN_TX_Msg_3_Sgn_7;
UInt8 CANMMCAN_TX_Msg_3_Sgn_7_constant;
UInt8 CANMMCAN_TX_Msg_3_Sgn_7_DynValue;
UInt8 CANMMCAN_TX_Msg_3_Sgn_7_error;
UInt8 CANMMCAN_RX_Msg_3_Sgn_8;
UInt8 CANMMCAN_TX_Msg_3_Sgn_8;
UInt8 CANMMCAN_TX_Msg_3_Sgn_8_constant;
UInt8 CANMMCAN_TX_Msg_3_Sgn_8_DynValue;
UInt8 CANMMCAN_TX_Msg_3_Sgn_8_error;
UInt8 CANMMCAN_RX_Msg_4_Sgn_1;
UInt8 CANMMCAN_TX_Msg_4_Sgn_1;
UInt8 CANMMCAN_TX_Msg_4_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_4_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_4_Sgn_1_error;
UInt8 CANMMCAN_RX_Msg_4_Sgn_2;
UInt8 CANMMCAN_TX_Msg_4_Sgn_2;
UInt8 CANMMCAN_TX_Msg_4_Sgn_2_constant;
UInt8 CANMMCAN_TX_Msg_4_Sgn_2_DynValue;
UInt8 CANMMCAN_TX_Msg_4_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_4_Sgn_3;
UInt8 CANMMCAN_TX_Msg_4_Sgn_3;
UInt8 CANMMCAN_TX_Msg_4_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_4_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_4_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_4_Sgn_4;
UInt8 CANMMCAN_TX_Msg_4_Sgn_4;
UInt8 CANMMCAN_TX_Msg_4_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_4_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_4_Sgn_4_error;
UInt8 CANMMCAN_RX_Msg_4_Sgn_5;
UInt8 CANMMCAN_TX_Msg_4_Sgn_5;
UInt8 CANMMCAN_TX_Msg_4_Sgn_5_constant;
UInt8 CANMMCAN_TX_Msg_4_Sgn_5_DynValue;
UInt8 CANMMCAN_TX_Msg_4_Sgn_5_error;
UInt8 CANMMCAN_RX_Msg_4_Sgn_6;
UInt8 CANMMCAN_TX_Msg_4_Sgn_6;
UInt8 CANMMCAN_TX_Msg_4_Sgn_6_constant;
UInt8 CANMMCAN_TX_Msg_4_Sgn_6_DynValue;
UInt8 CANMMCAN_TX_Msg_4_Sgn_6_error;
UInt8 CANMMCAN_RX_Msg_4_Sgn_7;
UInt8 CANMMCAN_TX_Msg_4_Sgn_7;
UInt8 CANMMCAN_TX_Msg_4_Sgn_7_constant;
UInt8 CANMMCAN_TX_Msg_4_Sgn_7_DynValue;
UInt8 CANMMCAN_TX_Msg_4_Sgn_7_error;
UInt8 CANMMCAN_RX_Msg_4_Sgn_8;
UInt8 CANMMCAN_TX_Msg_4_Sgn_8;
UInt8 CANMMCAN_TX_Msg_4_Sgn_8_constant;
UInt8 CANMMCAN_TX_Msg_4_Sgn_8_DynValue;
UInt8 CANMMCAN_TX_Msg_4_Sgn_8_error;
UInt8 CANMMCAN_RX_Msg_5_Sgn_1;
UInt8 CANMMCAN_TX_Msg_5_Sgn_1;
UInt8 CANMMCAN_TX_Msg_5_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_5_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_5_Sgn_1_error;
UInt8 CANMMCAN_RX_Msg_5_Sgn_2;
UInt8 CANMMCAN_TX_Msg_5_Sgn_2;
UInt8 CANMMCAN_TX_Msg_5_Sgn_2_constant;
UInt8 CANMMCAN_TX_Msg_5_Sgn_2_DynValue;
UInt8 CANMMCAN_TX_Msg_5_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_5_Sgn_3;
UInt8 CANMMCAN_TX_Msg_5_Sgn_3;
UInt8 CANMMCAN_TX_Msg_5_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_5_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_5_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_5_Sgn_4;
UInt8 CANMMCAN_TX_Msg_5_Sgn_4;
UInt8 CANMMCAN_TX_Msg_5_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_5_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_5_Sgn_4_error;
UInt8 CANMMCAN_RX_Msg_5_Sgn_5;
UInt8 CANMMCAN_TX_Msg_5_Sgn_5;
UInt8 CANMMCAN_TX_Msg_5_Sgn_5_constant;
UInt8 CANMMCAN_TX_Msg_5_Sgn_5_DynValue;
UInt8 CANMMCAN_TX_Msg_5_Sgn_5_error;
UInt8 CANMMCAN_RX_Msg_5_Sgn_6;
UInt8 CANMMCAN_TX_Msg_5_Sgn_6;
UInt8 CANMMCAN_TX_Msg_5_Sgn_6_constant;
UInt8 CANMMCAN_TX_Msg_5_Sgn_6_DynValue;
UInt8 CANMMCAN_TX_Msg_5_Sgn_6_error;
UInt8 CANMMCAN_RX_Msg_5_Sgn_7;
UInt8 CANMMCAN_TX_Msg_5_Sgn_7;
UInt8 CANMMCAN_TX_Msg_5_Sgn_7_constant;
UInt8 CANMMCAN_TX_Msg_5_Sgn_7_DynValue;
UInt8 CANMMCAN_TX_Msg_5_Sgn_7_error;
UInt8 CANMMCAN_RX_Msg_5_Sgn_8;
UInt8 CANMMCAN_TX_Msg_5_Sgn_8;
UInt8 CANMMCAN_TX_Msg_5_Sgn_8_constant;
UInt8 CANMMCAN_TX_Msg_5_Sgn_8_DynValue;
UInt8 CANMMCAN_TX_Msg_5_Sgn_8_error;
UInt8 CANMMCAN_RX_Msg_6_Sgn_1;
UInt8 CANMMCAN_TX_Msg_6_Sgn_1;
UInt8 CANMMCAN_TX_Msg_6_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_6_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_6_Sgn_1_error;
UInt8 CANMMCAN_RX_Msg_6_Sgn_2;
UInt8 CANMMCAN_TX_Msg_6_Sgn_2;
UInt8 CANMMCAN_TX_Msg_6_Sgn_2_constant;
UInt8 CANMMCAN_TX_Msg_6_Sgn_2_DynValue;
UInt8 CANMMCAN_TX_Msg_6_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_6_Sgn_3;
UInt8 CANMMCAN_TX_Msg_6_Sgn_3;
UInt8 CANMMCAN_TX_Msg_6_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_6_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_6_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_6_Sgn_4;
UInt8 CANMMCAN_TX_Msg_6_Sgn_4;
UInt8 CANMMCAN_TX_Msg_6_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_6_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_6_Sgn_4_error;
UInt8 CANMMCAN_RX_Msg_6_Sgn_5;
UInt8 CANMMCAN_TX_Msg_6_Sgn_5;
UInt8 CANMMCAN_TX_Msg_6_Sgn_5_constant;
UInt8 CANMMCAN_TX_Msg_6_Sgn_5_DynValue;
UInt8 CANMMCAN_TX_Msg_6_Sgn_5_error;
UInt8 CANMMCAN_RX_Msg_6_Sgn_6;
UInt8 CANMMCAN_TX_Msg_6_Sgn_6;
UInt8 CANMMCAN_TX_Msg_6_Sgn_6_constant;
UInt8 CANMMCAN_TX_Msg_6_Sgn_6_DynValue;
UInt8 CANMMCAN_TX_Msg_6_Sgn_6_error;
UInt8 CANMMCAN_RX_Msg_6_Sgn_7;
UInt8 CANMMCAN_TX_Msg_6_Sgn_7;
UInt8 CANMMCAN_TX_Msg_6_Sgn_7_constant;
UInt8 CANMMCAN_TX_Msg_6_Sgn_7_DynValue;
UInt8 CANMMCAN_TX_Msg_6_Sgn_7_error;
UInt8 CANMMCAN_RX_Msg_6_Sgn_8;
UInt8 CANMMCAN_TX_Msg_6_Sgn_8;
UInt8 CANMMCAN_TX_Msg_6_Sgn_8_constant;
UInt8 CANMMCAN_TX_Msg_6_Sgn_8_DynValue;
UInt8 CANMMCAN_TX_Msg_6_Sgn_8_error;
UInt8 CANMMCAN_RX_Msg_7_Sgn_1;
UInt8 CANMMCAN_TX_Msg_7_Sgn_1;
UInt8 CANMMCAN_TX_Msg_7_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_7_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_7_Sgn_1_error;
UInt8 CANMMCAN_RX_Msg_7_Sgn_2;
UInt8 CANMMCAN_TX_Msg_7_Sgn_2;
UInt8 CANMMCAN_TX_Msg_7_Sgn_2_constant;
UInt8 CANMMCAN_TX_Msg_7_Sgn_2_DynValue;
UInt8 CANMMCAN_TX_Msg_7_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_7_Sgn_3;
UInt8 CANMMCAN_TX_Msg_7_Sgn_3;
UInt8 CANMMCAN_TX_Msg_7_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_7_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_7_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_7_Sgn_4;
UInt8 CANMMCAN_TX_Msg_7_Sgn_4;
UInt8 CANMMCAN_TX_Msg_7_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_7_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_7_Sgn_4_error;
UInt8 CANMMCAN_RX_Msg_7_Sgn_5;
UInt8 CANMMCAN_TX_Msg_7_Sgn_5;
UInt8 CANMMCAN_TX_Msg_7_Sgn_5_constant;
UInt8 CANMMCAN_TX_Msg_7_Sgn_5_DynValue;
UInt8 CANMMCAN_TX_Msg_7_Sgn_5_error;
UInt8 CANMMCAN_RX_Msg_7_Sgn_6;
UInt8 CANMMCAN_TX_Msg_7_Sgn_6;
UInt8 CANMMCAN_TX_Msg_7_Sgn_6_constant;
UInt8 CANMMCAN_TX_Msg_7_Sgn_6_DynValue;
UInt8 CANMMCAN_TX_Msg_7_Sgn_6_error;
UInt8 CANMMCAN_RX_Msg_7_Sgn_7;
UInt8 CANMMCAN_TX_Msg_7_Sgn_7;
UInt8 CANMMCAN_TX_Msg_7_Sgn_7_constant;
UInt8 CANMMCAN_TX_Msg_7_Sgn_7_DynValue;
UInt8 CANMMCAN_TX_Msg_7_Sgn_7_error;
UInt8 CANMMCAN_RX_Msg_7_Sgn_8;
UInt8 CANMMCAN_TX_Msg_7_Sgn_8;
UInt8 CANMMCAN_TX_Msg_7_Sgn_8_constant;
UInt8 CANMMCAN_TX_Msg_7_Sgn_8_DynValue;
UInt8 CANMMCAN_TX_Msg_7_Sgn_8_error;
UInt8 CANMMCAN_RX_Msg_8_Sgn_1;
UInt8 CANMMCAN_TX_Msg_8_Sgn_1;
UInt8 CANMMCAN_TX_Msg_8_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_8_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_8_Sgn_1_error;
UInt8 CANMMCAN_RX_Msg_8_Sgn_2;
UInt8 CANMMCAN_TX_Msg_8_Sgn_2;
UInt8 CANMMCAN_TX_Msg_8_Sgn_2_constant;
UInt8 CANMMCAN_TX_Msg_8_Sgn_2_DynValue;
UInt8 CANMMCAN_TX_Msg_8_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_8_Sgn_3;
UInt8 CANMMCAN_TX_Msg_8_Sgn_3;
UInt8 CANMMCAN_TX_Msg_8_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_8_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_8_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_8_Sgn_4;
UInt8 CANMMCAN_TX_Msg_8_Sgn_4;
UInt8 CANMMCAN_TX_Msg_8_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_8_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_8_Sgn_4_error;
UInt8 CANMMCAN_RX_Msg_8_Sgn_5;
UInt8 CANMMCAN_TX_Msg_8_Sgn_5;
UInt8 CANMMCAN_TX_Msg_8_Sgn_5_constant;
UInt8 CANMMCAN_TX_Msg_8_Sgn_5_DynValue;
UInt8 CANMMCAN_TX_Msg_8_Sgn_5_error;
UInt8 CANMMCAN_RX_Msg_8_Sgn_6;
UInt8 CANMMCAN_TX_Msg_8_Sgn_6;
UInt8 CANMMCAN_TX_Msg_8_Sgn_6_constant;
UInt8 CANMMCAN_TX_Msg_8_Sgn_6_DynValue;
UInt8 CANMMCAN_TX_Msg_8_Sgn_6_error;
UInt8 CANMMCAN_RX_Msg_8_Sgn_7;
UInt8 CANMMCAN_TX_Msg_8_Sgn_7;
UInt8 CANMMCAN_TX_Msg_8_Sgn_7_constant;
UInt8 CANMMCAN_TX_Msg_8_Sgn_7_DynValue;
UInt8 CANMMCAN_TX_Msg_8_Sgn_7_error;
UInt8 CANMMCAN_RX_Msg_8_Sgn_8;
UInt8 CANMMCAN_TX_Msg_8_Sgn_8;
UInt8 CANMMCAN_TX_Msg_8_Sgn_8_constant;
UInt8 CANMMCAN_TX_Msg_8_Sgn_8_DynValue;
UInt8 CANMMCAN_TX_Msg_8_Sgn_8_error;






volatile uint8_T CANMMCAN_TXs[69];
volatile uint8_T CANMMCAN_TXm[69];
volatile uint8_T CANMMCAN_TXGWs[69];
volatile uint32_T CANMMCAN_TXcdo[69];
