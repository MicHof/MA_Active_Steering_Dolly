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
 *  AngleSensor - 1
 *     AngleSensor.PacketType - 1
 *     AngleSensor.MessageCounter - 2
 *     AngleSensor.Angle - 3
 *     AngleSensor.Temperature - 4
 *     AngleSensor.AlarmWarningBits - 5
 */

/*********
 *  ISO11992_EBS21 - 2
 *     ISO11992_EBS21.VehicleABSActive - 1
 *     ISO11992_EBS21.VehicleRetarderCtrlActive - 2
 *     ISO11992_EBS21.VehicleServiceBrakeActive - 3
 *     ISO11992_EBS21.AutomTowedVehBreakActive - 4
 *     ISO11992_EBS21.VDCActive - 5
 *     ISO11992_EBS21.SupplyLineBrakingRequest - 6
 *     ISO11992_EBS21.Wheel_BasedVehicleSpeed - 7
 *     ISO11992_EBS21.ActualRetarderPercTorque - 8
 *     ISO11992_EBS21.WheelSpeedDiffMainAxle - 9
 */
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


/* Define RX/TX structure */

volatile real_T CANMMCAN_RXCT1;
UInt8 CANMMCAN_RX_Msg_1_Sgn_1;
UInt8 CANMMCAN_RX_Msg_1_Sgn_2;
double CANMMCAN_RX_Msg_1_Sgn_3;
Int16 CANMMCAN_RX_Msg_1_Sgn_4;
UInt8 CANMMCAN_RX_Msg_1_Sgn_5;
volatile real_T CANMMCAN_RXCT2;
UInt8 CANMMCAN_RX_Msg_2_Sgn_1;
UInt8 CANMMCAN_RX_Msg_2_Sgn_2;
UInt8 CANMMCAN_RX_Msg_2_Sgn_3;
UInt8 CANMMCAN_RX_Msg_2_Sgn_4;
UInt8 CANMMCAN_RX_Msg_2_Sgn_5;
UInt8 CANMMCAN_RX_Msg_2_Sgn_6;
double CANMMCAN_RX_Msg_2_Sgn_7;
Int16 CANMMCAN_RX_Msg_2_Sgn_8;
double CANMMCAN_RX_Msg_2_Sgn_9;






