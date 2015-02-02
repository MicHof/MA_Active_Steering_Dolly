/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_MESSAGE_DEFAULTS */
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

CANMMCAN_Arduino_MAXMSGPERSTEP = 0;

/* DefaultGlobalEnable */
CANMMCAN_Arduino_GEIN = 1;


/* Feedthrough debug variable*/
CANMMCAN_Arduino_FTD = 0;
CANMMCAN_Arduino_RTVE = 1;


/* IMU_accelerometer */
CANMMCAN_Arduino_TXCT[0] = 0; /* TX CycleTime[s] */
CANMMCAN_Arduino_TXDT[0] = 0; /* TX DelayTime[s] */
CANMMCAN_Arduino_RXdt[0] = 0; /* RX DeltaTime[s] */
CANMMCAN_Arduino_RXt[0] = 0.0; /* RX Time[s] */
CANMMCAN_Arduino_RXerr[0] = 0; /* RX Error */
CANMMCAN_Arduino_RXLEN[0] = 6; /* RX Message Length */


/* IMU_angels_corrected */
CANMMCAN_Arduino_TXCT[2] = 0; /* TX CycleTime[s] */
CANMMCAN_Arduino_TXDT[2] = 0; /* TX DelayTime[s] */
CANMMCAN_Arduino_RXdt[2] = 0; /* RX DeltaTime[s] */
CANMMCAN_Arduino_RXt[2] = 0.0; /* RX Time[s] */
CANMMCAN_Arduino_RXerr[2] = 0; /* RX Error */
CANMMCAN_Arduino_RXLEN[2] = 6; /* RX Message Length */


/* IMU_gyroskop */
CANMMCAN_Arduino_TXCT[1] = 0; /* TX CycleTime[s] */
CANMMCAN_Arduino_TXDT[1] = 0; /* TX DelayTime[s] */
CANMMCAN_Arduino_RXdt[1] = 0; /* RX DeltaTime[s] */
CANMMCAN_Arduino_RXt[1] = 0.0; /* RX Time[s] */
CANMMCAN_Arduino_RXerr[1] = 0; /* RX Error */
CANMMCAN_Arduino_RXLEN[1] = 6; /* RX Message Length */


/* DefaultGlobalEnable TX */
CANMMCAN_Arduino_TXGEIN = 1;


/* ECU ENABLE */
/* Vector__XXX*/
CANMMCAN_Arduino_TXEEIE[0] = 1;
CANMMCAN_Arduino_TXEEIEOLD[0] = 1;




/* ------------------------------------------------------------------------------ */
/* Message Defaults: */


/* IMU_accelerometer */
CANMMCAN_Arduino_WBS[0] = 0; /* Would be sent */
CANMMCAN_Arduino_TXEIN[0] = 1; /* DefaultEnable */
CANMMCAN_Arduino_TXENIE[0] = 1; /* DefaultEnable */
CANMMCAN_Arduino_TXCIN[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Arduino_TXCIE[0] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Arduino_TXKIEXC[0] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Arduino_TXLEN[0] = 6; /* Message length */
CANMMCAN_Arduino_TXRBUF[0] = 0; /* internal -> do not change */
CANMMCAN_Arduino_TXRXBUF[0] = 0; /* internal -> do not change */
CANMMCAN_Arduino_TXusrm[0] = 1;
CANMMCAN_Arduino_TXcraw[0] = 0; /* 0: SIGNALS 1:RAWDATA */


/* IMU_gyroskop */
CANMMCAN_Arduino_WBS[1] = 0; /* Would be sent */
CANMMCAN_Arduino_TXEIN[1] = 1; /* DefaultEnable */
CANMMCAN_Arduino_TXENIE[1] = 1; /* DefaultEnable */
CANMMCAN_Arduino_TXCIN[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Arduino_TXCIE[1] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Arduino_TXKIEXC[1] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Arduino_TXLEN[1] = 6; /* Message length */
CANMMCAN_Arduino_TXRBUF[1] = 0; /* internal -> do not change */
CANMMCAN_Arduino_TXRXBUF[1] = 0; /* internal -> do not change */
CANMMCAN_Arduino_TXusrm[1] = 1;
CANMMCAN_Arduino_TXcraw[1] = 0; /* 0: SIGNALS 1:RAWDATA */


/* IMU_angels_corrected */
CANMMCAN_Arduino_WBS[2] = 0; /* Would be sent */
CANMMCAN_Arduino_TXEIN[2] = 1; /* DefaultEnable */
CANMMCAN_Arduino_TXENIE[2] = 1; /* DefaultEnable */
CANMMCAN_Arduino_TXCIN[2] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Arduino_TXCIE[2] = 1; /* DefaultCyclic 0: triggered 1: cyclic */
CANMMCAN_Arduino_TXKIEXC[2] = 1; /* Check 0: intern and/or extern    1: just intern */
CANMMCAN_Arduino_TXLEN[2] = 6; /* Message length */
CANMMCAN_Arduino_TXRBUF[2] = 0; /* internal -> do not change */
CANMMCAN_Arduino_TXRXBUF[2] = 0; /* internal -> do not change */
CANMMCAN_Arduino_TXusrm[2] = 1;
CANMMCAN_Arduino_TXcraw[2] = 0; /* 0: SIGNALS 1:RAWDATA */

