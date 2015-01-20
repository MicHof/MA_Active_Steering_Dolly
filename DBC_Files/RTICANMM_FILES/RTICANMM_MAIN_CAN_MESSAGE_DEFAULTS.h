/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_MESSAGE_DEFAULTS */
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

CANMMCAN_MAXMSGPERSTEP = 0;

/* DefaultGlobalEnable */
CANMMCAN_GEIN = 1;


/* Feedthrough debug variable*/
CANMMCAN_FTD = 0;
CANMMCAN_RTVE = 1;


/* AngleSensor */
CANMMCAN_RXCT1 = 0; /* RX CycleTime[s] */
CANMMCAN_RXdt[1] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[1] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[1] = 0; /* RX Error */
CANMMCAN_RXLEN[1] = 5; /* RX Message Length */


/* ISO11992_EBS21 */
CANMMCAN_RXCT2 = 0; /* RX CycleTime[s] */
CANMMCAN_RXdt[0] = 0; /* RX DeltaTime[s] */
CANMMCAN_RXt[0] = 0.0; /* RX Time[s] */
CANMMCAN_RXerr[0] = 0; /* RX Error */
CANMMCAN_RXLEN[0] = 8; /* RX Message Length */


/* ECU ENABLE */



