/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_2_DEFS */
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
 *  AnalogInputVoltagesMessage1 - 1
 *     AnalogInputVoltagesMessage1.IAV_AIN1_FrontAngle - 1
 *     AnalogInputVoltagesMessage1.IAV_AIN2_FrontAngleRed - 2
 *     AnalogInputVoltagesMessage1.IAV_AIN3_RearAngle - 3
 *     AnalogInputVoltagesMessage1.IAV_AIN4_RearAngleRed - 4
 */

/*********
 *  AnalogInputVoltagesMessage2 - 2
 *     AnalogInputVoltagesMessage2.IAV_AIN5_PressureSensorX - 1
 *     AnalogInputVoltagesMessage2.IAV_AIN6_PressureSensorY - 2
 *     AnalogInputVoltagesMessage2.IAV_AIN7_RearAngle2 - 3
 *     AnalogInputVoltagesMessage2.IAV_AIN8_RearAngle2Red - 4
 */

/*********
 *  CurrentMeasurementOutputs1 - 3
 *     CurrentMeasurementOutputs1.CMO_Output1 - 1
 *     CurrentMeasurementOutputs1.CMO_Output2 - 2
 *     CurrentMeasurementOutputs1.CMO_Output3 - 3
 *     CurrentMeasurementOutputs1.CMO_Output4 - 4
 */

/*********
 *  CurrentMeasurementOutputs2 - 4
 *     CurrentMeasurementOutputs2.CMO_Output5 - 1
 *     CurrentMeasurementOutputs2.CMO_Output6 - 2
 *     CurrentMeasurementOutputs2.CMO_Output7 - 3
 *     CurrentMeasurementOutputs2.CMO_Output8 - 4
 */

/*********
 *  DigitalInput - 5
 *     DigitalInput.DIV_DIN1 - 1
 *     DigitalInput.DIV_DIN2 - 2
 *     DigitalInput.DIV_DIN3 - 3
 *     DigitalInput.DIV_DIN4 - 4
 *     DigitalInput.DIV_DIN5 - 5
 *     DigitalInput.DIV_DIN6 - 6
 *     DigitalInput.DIV_DIN7 - 7
 *     DigitalInput.DIV_DIN8 - 8
 *     DigitalInput.DIV_DIN9 - 9
 *     DigitalInput.DIV_DIN10 - 10
 *     DigitalInput.DIV_DIN11 - 11
 */

/*********
 *  EtsDataMessage1 - 6
 *     EtsDataMessage1.ETSD1_InSpeed1 - 1
 *     EtsDataMessage1.ETSD1_InSpeed2 - 2
 *     EtsDataMessage1.ETSD1_TargetAngle - 3
 *     EtsDataMessage1.ETSD1_FrontAngle - 4
 *     EtsDataMessage1.ETSD1_RearAngle - 5
 */

/*********
 *  EtsDataMessage2 - 7
 *     EtsDataMessage2.ETSD2_Target2Angle - 1
 *     EtsDataMessage2.ETSD2_Rear2Angle - 2
 *     EtsDataMessage2.ETSD2_PxPressure - 3
 *     EtsDataMessage2.ETSD2_PyPressure - 4
 */

/*********
 *  EtsDataMessage3 - 8
 *     EtsDataMessage3.ETSD3_AmbientTemp - 1
 *     EtsDataMessage3.ETSD3_OilTemp - 2
 *     EtsDataMessage3.ETSD3_SecMicroVersion - 3
 *     EtsDataMessage3.ETSD3_NmiNumber - 4
 */

/*********
 *  EtsDataMessage4 - 9
 *     EtsDataMessage4.ETSD4_CanSensorAngle - 1
 *     EtsDataMessage4.ETSD4_CanSensorEtsAngle - 2
 *     EtsDataMessage4.ETSD4_CanSensorTemp - 3
 *     EtsDataMessage4.ETSD4_CanSensorAlarm - 4
 */

/*********
 *  EtsDataMessage5 - 10
 *     EtsDataMessage5.ETSD5_Py2Cofa - 1
 *     EtsDataMessage5.ETSD5_Py2Pressure - 2
 */

/*********
 *  EtsSystemMessage - 11
 *     EtsSystemMessage.ETSS_SteeringState - 1
 *     EtsSystemMessage.ETSS_AlarmState - 2
 *     EtsSystemMessage.ETSS_DiagnosticState - 3
 *     EtsSystemMessage.ETSS_CentringState - 4
 *     EtsSystemMessage.ETSS_SteerMode - 5
 *     EtsSystemMessage.ETSS_AlarmPriority - 6
 *     EtsSystemMessage.ETSS_AlarmReaction - 7
 *     EtsSystemMessage.ETSS_EtsSimpleStatus - 8
 *     EtsSystemMessage.ETSS_SupplyVoltageSimpleState - 9
 *     EtsSystemMessage.ETSS_SpeedSignalSimpleStatus - 10
 *     EtsSystemMessage.ETSS_KL15State - 11
 *     EtsSystemMessage.ETSS_TableNumber - 12
 */

/*********
 *  OilSupplyAssignmentMessage - 12
 *     OilSupplyAssignmentMessage.OSAM_Press - 1
 *     OilSupplyAssignmentMessage.OSAM_Flow - 2
 *     OilSupplyAssignmentMessage.OSAM_Pump - 3
 *     OilSupplyAssignmentMessage.OSAM_Prio - 4
 */

/*********
 *  OilSupplyRequestMessage - 13
 *     OilSupplyRequestMessage.OSRM_Press - 1
 *     OilSupplyRequestMessage.OSRM_Flow - 2
 *     OilSupplyRequestMessage.OSRM_Pump - 3
 *     OilSupplyRequestMessage.OSRM_Prio - 4
 */

/*********
 *  PowersupplyVoltageMessage1 - 14
 *     PowersupplyVoltageMessage1.PSV_SupV1_KL15 - 1
 *     PowersupplyVoltageMessage1.PSV_SupV2_KL30 - 2
 *     PowersupplyVoltageMessage1.PSV_SupV3_KL1530 - 3
 *     PowersupplyVoltageMessage1.PSV_SupV4_Internal5V - 4
 */

/*********
 *  PowersupplyVoltageMessage2 - 15
 *     PowersupplyVoltageMessage2.PSV_SupV5_Internal6V - 1
 *     PowersupplyVoltageMessage2.PSV_SupV6_2VRef - 2
 *     PowersupplyVoltageMessage2.PSV_SupV7_AngleSensor - 3
 *     PowersupplyVoltageMessage2.PSV_SupV8_PressureSensor - 4
 */

/*********
 *  ResistanceMeasurementOutputs - 16
 *     ResistanceMeasurementOutputs.RMO_Output1 - 1
 *     ResistanceMeasurementOutputs.RMO_Output2 - 2
 *     ResistanceMeasurementOutputs.RMO_Output3 - 3
 *     ResistanceMeasurementOutputs.RMO_Output4 - 4
 *     ResistanceMeasurementOutputs.RMO_Output5 - 5
 *     ResistanceMeasurementOutputs.RMO_Output6 - 6
 *     ResistanceMeasurementOutputs.RMO_Output7 - 7
 *     ResistanceMeasurementOutputs.RMO_Output8 - 8
 */

/*********
 *  SpeedMessage - 17
 *     SpeedMessage.SPEED_EtsSpeed - 1
 *     SpeedMessage.SPEED_SecondMicroSpeed - 2
 *     SpeedMessage.SPEED_MidPointHysteresis - 3
 *     SpeedMessage.SPEED_SpeedValidIndication - 4
 *     SpeedMessage.SPEED_LeadSpeed - 5
 */

/*********
 *  StatusHighOutputPins - 18
 *     StatusHighOutputPins.SHO_Output1 - 1
 *     StatusHighOutputPins.SHO_Output2 - 2
 *     StatusHighOutputPins.SHO_Output3 - 3
 *     StatusHighOutputPins.SHO_Output4 - 4
 *     StatusHighOutputPins.SHO_Output5 - 5
 *     StatusHighOutputPins.SHO_Output6 - 6
 *     StatusHighOutputPins.SHO_Output7 - 7
 *     StatusHighOutputPins.SHO_Output8 - 8
 */

/*********
 *  StatusLowOutputPins - 19
 *     StatusLowOutputPins.SLO_Output1 - 1
 *     StatusLowOutputPins.SLO_Output2 - 2
 */
volatile uint8_T CANMMCAN_2_RTVE;
volatile boolean_T CANMMCAN_2_TRAFFIC;
volatile int32_T CANMMCAN_2_MAXMSGPERSTEP;

volatile uint8_T CANMMCAN_2_TVAR8;

volatile uint8_T CANMMCAN_2_TVAR8_2;

volatile uint32_T CANMMCAN_2_TVAR32;

volatile uint8_T CANMMCAN_2_TVAR8A[8];

volatile double CANMMCAN_2_TVARD;
volatile double CANMMCAN_2_TVARD2;

/* Globale Enable */
volatile boolean_T CANMMCAN_2_GEIN;
#define CANMMCAN_2_GE CANMMCAN_2_GEIN

/* Reset */
#define CANMMCAN_2_RE 1


/* Feedthrough debug variable*/
volatile uint8_T CANMMCAN_2_FTD;

/* Globale Enable TX */
volatile boolean_T CANMMCAN_2_TXGEIN;
#define CANMMCAN_2_TXGE CANMMCAN_2_TXGEIN
                               
                               
/* ECU ENABLE */               
volatile boolean_T CANMMCAN_2_TXEEIE[1] = {1};     
volatile boolean_T CANMMCAN_2_TXEEIEOLD[1] = {1};     
volatile boolean_T CANMMCAN_2_TXECUEN_Vector__XXX = 1;   
                            
                            

/* Message would be sent */
volatile uint8_T CANMMCAN_2_WBS[NUM_TX_MSG];
volatile boolean_T CANMMCAN_2_BYKICK[NUM_TX_MSG];

/* Message enable */
volatile boolean_T CANMMCAN_2_TXENIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_2_TXEIN[NUM_TX_MSG];
#define CANMMCAN_2_TXEN(X) (CANMMCAN_2_TXENIE[X])
#define USE_LOCAL_ENABLE

/* Cyclic triggering */
volatile boolean_T CANMMCAN_2_TXCIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_2_TXCIN[NUM_TX_MSG];
#define CANMMCAN_2_TXC(X) (CANMMCAN_2_TXCIE[X])

/* Message kickout */
volatile boolean_T CANMMCAN_2_TXKIEX[NUM_TX_MSG];
volatile boolean_T CANMMCAN_2_TXKIN[NUM_TX_MSG];
volatile boolean_T CANMMCAN_2_TXKIEXC[NUM_TX_MSG];
#define CANMMCAN_2_TXKOUT(X) (CANMMCAN_2_TXKIEX[X])
#undef MESSAGETIMEOUT


#define ID_Table_RX(X) (int)(CANMMCAN_2_MIDRX[X])
#define ID_Table_TX(X) (int)(CANMMCAN_2_MIDTX[X])
#define ID_Table_RXContainer(X) (int)(CANMMCAN_2_RXCCONT[X])
#define SRC_Addressing_Switch(X) (int)(CANMMCAN_2_TXASW_SRC[CANMMCAN_2_MIDTX[X]])
#define DEST_Addressing_Switch(X) (int)(CANMMCAN_2_TXASW_DEST[CANMMCAN_2_MIDTX[X]])
uint8_T CANMMCAN_2_MIDTXSW[NUM_RX_MSG];
uint32_T CANMMCAN_2_MIDTXIN[NUM_RX_MSG];
uint32_T CANMMCAN_2_MIDTXS[NUM_RX_MSG];
uint32_T CANMMCAN_2_MIDRX[NUM_RX_MSG];
uint8_T CANMMCAN_2_MIDFRX[NUM_RX_MSG];
uint8_T CANMMCAN_2_MIDFTXIN[NUM_RX_MSG];
uint8_T CANMMCAN_2_MIDFTXS[NUM_RX_MSG];
uint8_T CANMMCAN_2_MIDFTX[NUM_RX_MSG];
uint8_T CANMMCAN_2_RXMT[NUM_RX_MSG];
 

uint8_T CANMMCAN_2_MPTXSW[NUM_RX_MSG];
uint8_T CANMMCAN_2_RXPRIO[NUM_RX_MSG];
uint32_T CANMMCAN_2_RXPGN[NUM_RX_MSG];
uint8_T CANMMCAN_2_RXSNIDX[NUM_RX_MSG];
uint8_T CANMMCAN_2_RXDNIDX[NUM_RX_MSG];
uint8_T CANMMCAN_2_RXSA[NUM_RX_MSG];
uint8_T CANMMCAN_2_RXDA[NUM_RX_MSG];
uint8_T CANMMCAN_2_RXCCONT[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXPRIO[NUM_RX_MSG];
uint32_T CANMMCAN_2_TXPGN[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXASW_SRC[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXASW_DEST[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXSNIDX[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXDNIDX[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXSA[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXDA[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXPRIOT[NUM_RX_MSG];
uint32_T CANMMCAN_2_TXPGNT[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXSNIDXT[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXDNIDXT[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXSAT[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXDAT[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXPRIOI[NUM_RX_MSG];
uint32_T CANMMCAN_2_TXPGNI[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXSNIDXI[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXDNIDXI[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXSAI[NUM_RX_MSG];
uint8_T CANMMCAN_2_TXDAI[NUM_RX_MSG];
volatile real_T CANMMCAN_2_RXt[NUM_RX_MSG];
volatile real_T CANMMCAN_2_RXdt[NUM_RX_MSG];
volatile boolean_T CANMMCAN_2_RXsta[NUM_RX_MSG];
volatile uint8_T CANMMCAN_2_RXerr[NUM_RX_MSG];
volatile real_T CANMMCAN_2_RXCTMIN[NUM_RX_MSG];
volatile real_T CANMMCAN_2_RXCTMAX[NUM_RX_MSG];
volatile uint32_T CANMMCAN_2_RXLEN[NUM_RX_MSG];
volatile uint32_T CANMMCAN_2_RXCNT[NUM_RX_MSG];
uint32_T CANMMCAN_2_MIDTX[NUM_TX_MSG];
volatile real_T CANMMCAN_2_TXCT[NUM_TX_MSG];
volatile real_T CANMMCAN_2_TXDT[NUM_TX_MSG];
volatile uint8_T CANMMCAN_2_TXcraw[NUM_TX_MSG];
volatile boolean_T CANMMCAN_2_TXsta[NUM_TX_MSG];
volatile uint8_T CANMMCAN_2_TXRBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_2_TXRXBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_2_TXusrm[NUM_TX_MSG];
volatile uint32_T CANMMCAN_2_TXLEN[NUM_TX_MSG];


/* Define RX/TX structure */

double CANMMCAN_2_RX_Msg_1_Sgn_1;
double CANMMCAN_2_TX_Msg_1_Sgn_1;
double CANMMCAN_2_TX_Msg_1_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_1_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_1_Sgn_1_error;
double CANMMCAN_2_RX_Msg_1_Sgn_2;
double CANMMCAN_2_TX_Msg_1_Sgn_2;
double CANMMCAN_2_TX_Msg_1_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_1_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_1_Sgn_2_error;
double CANMMCAN_2_RX_Msg_1_Sgn_3;
double CANMMCAN_2_TX_Msg_1_Sgn_3;
double CANMMCAN_2_TX_Msg_1_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_1_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_1_Sgn_3_error;
double CANMMCAN_2_RX_Msg_1_Sgn_4;
double CANMMCAN_2_TX_Msg_1_Sgn_4;
double CANMMCAN_2_TX_Msg_1_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_1_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_1_Sgn_4_error;
double CANMMCAN_2_RX_Msg_2_Sgn_1;
double CANMMCAN_2_TX_Msg_2_Sgn_1;
double CANMMCAN_2_TX_Msg_2_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_2_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_2_Sgn_1_error;
double CANMMCAN_2_RX_Msg_2_Sgn_2;
double CANMMCAN_2_TX_Msg_2_Sgn_2;
double CANMMCAN_2_TX_Msg_2_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_2_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_2_Sgn_2_error;
double CANMMCAN_2_RX_Msg_2_Sgn_3;
double CANMMCAN_2_TX_Msg_2_Sgn_3;
double CANMMCAN_2_TX_Msg_2_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_2_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_2_Sgn_3_error;
double CANMMCAN_2_RX_Msg_2_Sgn_4;
double CANMMCAN_2_TX_Msg_2_Sgn_4;
double CANMMCAN_2_TX_Msg_2_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_2_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_2_Sgn_4_error;
double CANMMCAN_2_RX_Msg_3_Sgn_1;
double CANMMCAN_2_TX_Msg_3_Sgn_1;
double CANMMCAN_2_TX_Msg_3_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_3_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_3_Sgn_1_error;
double CANMMCAN_2_RX_Msg_3_Sgn_2;
double CANMMCAN_2_TX_Msg_3_Sgn_2;
double CANMMCAN_2_TX_Msg_3_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_3_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_3_Sgn_2_error;
double CANMMCAN_2_RX_Msg_3_Sgn_3;
double CANMMCAN_2_TX_Msg_3_Sgn_3;
double CANMMCAN_2_TX_Msg_3_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_3_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_3_Sgn_3_error;
double CANMMCAN_2_RX_Msg_3_Sgn_4;
double CANMMCAN_2_TX_Msg_3_Sgn_4;
double CANMMCAN_2_TX_Msg_3_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_3_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_3_Sgn_4_error;
double CANMMCAN_2_RX_Msg_4_Sgn_1;
double CANMMCAN_2_TX_Msg_4_Sgn_1;
double CANMMCAN_2_TX_Msg_4_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_4_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_4_Sgn_1_error;
double CANMMCAN_2_RX_Msg_4_Sgn_2;
double CANMMCAN_2_TX_Msg_4_Sgn_2;
double CANMMCAN_2_TX_Msg_4_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_4_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_4_Sgn_2_error;
double CANMMCAN_2_RX_Msg_4_Sgn_3;
double CANMMCAN_2_TX_Msg_4_Sgn_3;
double CANMMCAN_2_TX_Msg_4_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_4_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_4_Sgn_3_error;
double CANMMCAN_2_RX_Msg_4_Sgn_4;
double CANMMCAN_2_TX_Msg_4_Sgn_4;
double CANMMCAN_2_TX_Msg_4_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_4_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_4_Sgn_4_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_1_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_1_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_1_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_2_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_2_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_2_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_3_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_3_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_3_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_4_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_4_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_4_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_5;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_5;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_5_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_5_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_5_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_6;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_6;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_6_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_6_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_6_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_7;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_7;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_7_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_7_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_7_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_8;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_8;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_8_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_8_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_8_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_9;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_9;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_9_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_9_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_9_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_10;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_10;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_10_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_10_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_10_error;
UInt8 CANMMCAN_2_RX_Msg_5_Sgn_11;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_11;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_11_constant;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_11_DynValue;
UInt8 CANMMCAN_2_TX_Msg_5_Sgn_11_error;
UInt8 CANMMCAN_2_RX_Msg_6_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_6_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_6_Sgn_1_constant;
UInt8 CANMMCAN_2_TX_Msg_6_Sgn_1_DynValue;
UInt8 CANMMCAN_2_TX_Msg_6_Sgn_1_error;
UInt8 CANMMCAN_2_RX_Msg_6_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_6_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_6_Sgn_2_constant;
UInt8 CANMMCAN_2_TX_Msg_6_Sgn_2_DynValue;
UInt8 CANMMCAN_2_TX_Msg_6_Sgn_2_error;
double CANMMCAN_2_RX_Msg_6_Sgn_3;
double CANMMCAN_2_TX_Msg_6_Sgn_3;
double CANMMCAN_2_TX_Msg_6_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_6_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_6_Sgn_3_error;
double CANMMCAN_2_RX_Msg_6_Sgn_4;
double CANMMCAN_2_TX_Msg_6_Sgn_4;
double CANMMCAN_2_TX_Msg_6_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_6_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_6_Sgn_4_error;
double CANMMCAN_2_RX_Msg_6_Sgn_5;
double CANMMCAN_2_TX_Msg_6_Sgn_5;
double CANMMCAN_2_TX_Msg_6_Sgn_5_constant;
double CANMMCAN_2_TX_Msg_6_Sgn_5_DynValue;
double CANMMCAN_2_TX_Msg_6_Sgn_5_error;
double CANMMCAN_2_RX_Msg_7_Sgn_1;
double CANMMCAN_2_TX_Msg_7_Sgn_1;
double CANMMCAN_2_TX_Msg_7_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_7_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_7_Sgn_1_error;
double CANMMCAN_2_RX_Msg_7_Sgn_2;
double CANMMCAN_2_TX_Msg_7_Sgn_2;
double CANMMCAN_2_TX_Msg_7_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_7_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_7_Sgn_2_error;
double CANMMCAN_2_RX_Msg_7_Sgn_3;
double CANMMCAN_2_TX_Msg_7_Sgn_3;
double CANMMCAN_2_TX_Msg_7_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_7_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_7_Sgn_3_error;
double CANMMCAN_2_RX_Msg_7_Sgn_4;
double CANMMCAN_2_TX_Msg_7_Sgn_4;
double CANMMCAN_2_TX_Msg_7_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_7_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_7_Sgn_4_error;
Int16 CANMMCAN_2_RX_Msg_8_Sgn_1;
Int16 CANMMCAN_2_TX_Msg_8_Sgn_1;
Int16 CANMMCAN_2_TX_Msg_8_Sgn_1_constant;
Int16 CANMMCAN_2_TX_Msg_8_Sgn_1_DynValue;
Int16 CANMMCAN_2_TX_Msg_8_Sgn_1_error;
Int16 CANMMCAN_2_RX_Msg_8_Sgn_2;
Int16 CANMMCAN_2_TX_Msg_8_Sgn_2;
Int16 CANMMCAN_2_TX_Msg_8_Sgn_2_constant;
Int16 CANMMCAN_2_TX_Msg_8_Sgn_2_DynValue;
Int16 CANMMCAN_2_TX_Msg_8_Sgn_2_error;
UInt8 CANMMCAN_2_RX_Msg_8_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_8_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_8_Sgn_3_constant;
UInt8 CANMMCAN_2_TX_Msg_8_Sgn_3_DynValue;
UInt8 CANMMCAN_2_TX_Msg_8_Sgn_3_error;
UInt8 CANMMCAN_2_RX_Msg_8_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_8_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_8_Sgn_4_constant;
UInt8 CANMMCAN_2_TX_Msg_8_Sgn_4_DynValue;
UInt8 CANMMCAN_2_TX_Msg_8_Sgn_4_error;
double CANMMCAN_2_RX_Msg_9_Sgn_1;
double CANMMCAN_2_TX_Msg_9_Sgn_1;
double CANMMCAN_2_TX_Msg_9_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_9_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_9_Sgn_1_error;
double CANMMCAN_2_RX_Msg_9_Sgn_2;
double CANMMCAN_2_TX_Msg_9_Sgn_2;
double CANMMCAN_2_TX_Msg_9_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_9_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_9_Sgn_2_error;
Int16 CANMMCAN_2_RX_Msg_9_Sgn_3;
Int16 CANMMCAN_2_TX_Msg_9_Sgn_3;
Int16 CANMMCAN_2_TX_Msg_9_Sgn_3_constant;
Int16 CANMMCAN_2_TX_Msg_9_Sgn_3_DynValue;
Int16 CANMMCAN_2_TX_Msg_9_Sgn_3_error;
UInt8 CANMMCAN_2_RX_Msg_9_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_9_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_9_Sgn_4_constant;
UInt8 CANMMCAN_2_TX_Msg_9_Sgn_4_DynValue;
UInt8 CANMMCAN_2_TX_Msg_9_Sgn_4_error;
UInt16 CANMMCAN_2_RX_Msg_10_Sgn_1;
UInt16 CANMMCAN_2_TX_Msg_10_Sgn_1;
UInt16 CANMMCAN_2_TX_Msg_10_Sgn_1_constant;
UInt16 CANMMCAN_2_TX_Msg_10_Sgn_1_DynValue;
UInt16 CANMMCAN_2_TX_Msg_10_Sgn_1_error;
double CANMMCAN_2_RX_Msg_10_Sgn_2;
double CANMMCAN_2_TX_Msg_10_Sgn_2;
double CANMMCAN_2_TX_Msg_10_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_10_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_10_Sgn_2_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_1_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_1_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_1_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_2_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_2_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_2_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_3_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_3_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_3_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_4_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_4_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_4_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_5;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_5;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_5_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_5_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_5_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_6;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_6;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_6_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_6_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_6_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_7;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_7;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_7_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_7_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_7_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_8;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_8;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_8_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_8_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_8_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_9;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_9;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_9_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_9_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_9_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_10;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_10;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_10_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_10_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_10_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_11;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_11;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_11_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_11_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_11_error;
UInt8 CANMMCAN_2_RX_Msg_11_Sgn_12;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_12;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_12_constant;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_12_DynValue;
UInt8 CANMMCAN_2_TX_Msg_11_Sgn_12_error;
double CANMMCAN_2_RX_Msg_12_Sgn_1;
double CANMMCAN_2_TX_Msg_12_Sgn_1;
double CANMMCAN_2_TX_Msg_12_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_12_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_12_Sgn_1_error;
UInt8 CANMMCAN_2_RX_Msg_12_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_2_constant;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_2_DynValue;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_2_error;
UInt8 CANMMCAN_2_RX_Msg_12_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_3_constant;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_3_DynValue;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_3_error;
UInt8 CANMMCAN_2_RX_Msg_12_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_4_constant;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_4_DynValue;
UInt8 CANMMCAN_2_TX_Msg_12_Sgn_4_error;
double CANMMCAN_2_RX_Msg_13_Sgn_1;
double CANMMCAN_2_TX_Msg_13_Sgn_1;
double CANMMCAN_2_TX_Msg_13_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_13_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_13_Sgn_1_error;
UInt8 CANMMCAN_2_RX_Msg_13_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_2_constant;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_2_DynValue;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_2_error;
UInt8 CANMMCAN_2_RX_Msg_13_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_3_constant;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_3_DynValue;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_3_error;
UInt8 CANMMCAN_2_RX_Msg_13_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_4_constant;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_4_DynValue;
UInt8 CANMMCAN_2_TX_Msg_13_Sgn_4_error;
double CANMMCAN_2_RX_Msg_14_Sgn_1;
double CANMMCAN_2_TX_Msg_14_Sgn_1;
double CANMMCAN_2_TX_Msg_14_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_14_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_14_Sgn_1_error;
double CANMMCAN_2_RX_Msg_14_Sgn_2;
double CANMMCAN_2_TX_Msg_14_Sgn_2;
double CANMMCAN_2_TX_Msg_14_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_14_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_14_Sgn_2_error;
double CANMMCAN_2_RX_Msg_14_Sgn_3;
double CANMMCAN_2_TX_Msg_14_Sgn_3;
double CANMMCAN_2_TX_Msg_14_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_14_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_14_Sgn_3_error;
double CANMMCAN_2_RX_Msg_14_Sgn_4;
double CANMMCAN_2_TX_Msg_14_Sgn_4;
double CANMMCAN_2_TX_Msg_14_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_14_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_14_Sgn_4_error;
double CANMMCAN_2_RX_Msg_15_Sgn_1;
double CANMMCAN_2_TX_Msg_15_Sgn_1;
double CANMMCAN_2_TX_Msg_15_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_15_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_15_Sgn_1_error;
double CANMMCAN_2_RX_Msg_15_Sgn_2;
double CANMMCAN_2_TX_Msg_15_Sgn_2;
double CANMMCAN_2_TX_Msg_15_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_15_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_15_Sgn_2_error;
double CANMMCAN_2_RX_Msg_15_Sgn_3;
double CANMMCAN_2_TX_Msg_15_Sgn_3;
double CANMMCAN_2_TX_Msg_15_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_15_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_15_Sgn_3_error;
double CANMMCAN_2_RX_Msg_15_Sgn_4;
double CANMMCAN_2_TX_Msg_15_Sgn_4;
double CANMMCAN_2_TX_Msg_15_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_15_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_15_Sgn_4_error;
double CANMMCAN_2_RX_Msg_16_Sgn_1;
double CANMMCAN_2_TX_Msg_16_Sgn_1;
double CANMMCAN_2_TX_Msg_16_Sgn_1_constant;
double CANMMCAN_2_TX_Msg_16_Sgn_1_DynValue;
double CANMMCAN_2_TX_Msg_16_Sgn_1_error;
double CANMMCAN_2_RX_Msg_16_Sgn_2;
double CANMMCAN_2_TX_Msg_16_Sgn_2;
double CANMMCAN_2_TX_Msg_16_Sgn_2_constant;
double CANMMCAN_2_TX_Msg_16_Sgn_2_DynValue;
double CANMMCAN_2_TX_Msg_16_Sgn_2_error;
double CANMMCAN_2_RX_Msg_16_Sgn_3;
double CANMMCAN_2_TX_Msg_16_Sgn_3;
double CANMMCAN_2_TX_Msg_16_Sgn_3_constant;
double CANMMCAN_2_TX_Msg_16_Sgn_3_DynValue;
double CANMMCAN_2_TX_Msg_16_Sgn_3_error;
double CANMMCAN_2_RX_Msg_16_Sgn_4;
double CANMMCAN_2_TX_Msg_16_Sgn_4;
double CANMMCAN_2_TX_Msg_16_Sgn_4_constant;
double CANMMCAN_2_TX_Msg_16_Sgn_4_DynValue;
double CANMMCAN_2_TX_Msg_16_Sgn_4_error;
double CANMMCAN_2_RX_Msg_16_Sgn_5;
double CANMMCAN_2_TX_Msg_16_Sgn_5;
double CANMMCAN_2_TX_Msg_16_Sgn_5_constant;
double CANMMCAN_2_TX_Msg_16_Sgn_5_DynValue;
double CANMMCAN_2_TX_Msg_16_Sgn_5_error;
double CANMMCAN_2_RX_Msg_16_Sgn_6;
double CANMMCAN_2_TX_Msg_16_Sgn_6;
double CANMMCAN_2_TX_Msg_16_Sgn_6_constant;
double CANMMCAN_2_TX_Msg_16_Sgn_6_DynValue;
double CANMMCAN_2_TX_Msg_16_Sgn_6_error;
double CANMMCAN_2_RX_Msg_16_Sgn_7;
double CANMMCAN_2_TX_Msg_16_Sgn_7;
double CANMMCAN_2_TX_Msg_16_Sgn_7_constant;
double CANMMCAN_2_TX_Msg_16_Sgn_7_DynValue;
double CANMMCAN_2_TX_Msg_16_Sgn_7_error;
double CANMMCAN_2_RX_Msg_16_Sgn_8;
double CANMMCAN_2_TX_Msg_16_Sgn_8;
double CANMMCAN_2_TX_Msg_16_Sgn_8_constant;
double CANMMCAN_2_TX_Msg_16_Sgn_8_DynValue;
double CANMMCAN_2_TX_Msg_16_Sgn_8_error;
UInt8 CANMMCAN_2_RX_Msg_17_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_17_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_17_Sgn_1_constant;
UInt8 CANMMCAN_2_TX_Msg_17_Sgn_1_DynValue;
UInt8 CANMMCAN_2_TX_Msg_17_Sgn_1_error;
UInt8 CANMMCAN_2_RX_Msg_17_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_17_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_17_Sgn_2_constant;
UInt8 CANMMCAN_2_TX_Msg_17_Sgn_2_DynValue;
UInt8 CANMMCAN_2_TX_Msg_17_Sgn_2_error;
Int8 CANMMCAN_2_RX_Msg_17_Sgn_3;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_3;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_3_constant;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_3_DynValue;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_3_error;
Int8 CANMMCAN_2_RX_Msg_17_Sgn_4;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_4;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_4_constant;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_4_DynValue;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_4_error;
Int8 CANMMCAN_2_RX_Msg_17_Sgn_5;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_5;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_5_constant;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_5_DynValue;
Int8 CANMMCAN_2_TX_Msg_17_Sgn_5_error;
UInt8 CANMMCAN_2_RX_Msg_18_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_1_constant;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_1_DynValue;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_1_error;
UInt8 CANMMCAN_2_RX_Msg_18_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_2_constant;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_2_DynValue;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_2_error;
UInt8 CANMMCAN_2_RX_Msg_18_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_3;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_3_constant;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_3_DynValue;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_3_error;
UInt8 CANMMCAN_2_RX_Msg_18_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_4;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_4_constant;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_4_DynValue;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_4_error;
UInt8 CANMMCAN_2_RX_Msg_18_Sgn_5;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_5;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_5_constant;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_5_DynValue;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_5_error;
UInt8 CANMMCAN_2_RX_Msg_18_Sgn_6;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_6;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_6_constant;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_6_DynValue;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_6_error;
UInt8 CANMMCAN_2_RX_Msg_18_Sgn_7;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_7;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_7_constant;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_7_DynValue;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_7_error;
UInt8 CANMMCAN_2_RX_Msg_18_Sgn_8;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_8;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_8_constant;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_8_DynValue;
UInt8 CANMMCAN_2_TX_Msg_18_Sgn_8_error;
UInt8 CANMMCAN_2_RX_Msg_19_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_19_Sgn_1;
UInt8 CANMMCAN_2_TX_Msg_19_Sgn_1_constant;
UInt8 CANMMCAN_2_TX_Msg_19_Sgn_1_DynValue;
UInt8 CANMMCAN_2_TX_Msg_19_Sgn_1_error;
UInt8 CANMMCAN_2_RX_Msg_19_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_19_Sgn_2;
UInt8 CANMMCAN_2_TX_Msg_19_Sgn_2_constant;
UInt8 CANMMCAN_2_TX_Msg_19_Sgn_2_DynValue;
UInt8 CANMMCAN_2_TX_Msg_19_Sgn_2_error;






volatile uint8_T CANMMCAN_2_TXs[97];
volatile uint8_T CANMMCAN_2_TXm[97];
volatile uint8_T CANMMCAN_2_TXGWs[97];
volatile uint32_T CANMMCAN_2_TXcdo[97];
