/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_RX_OUTPUT */
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

/* Capture Message 1 RX Status */ 
((boolean_T*) ssGetOutputPortSignal(S, 8))[0] = CANMMCAN_Arduino_CAPS[0];
/* Capture Message 2 RX Status */ 
((boolean_T*) ssGetOutputPortSignal(S, 21))[0] = CANMMCAN_Arduino_CAPS[1];
/* Capture Message 3 RX Status */ 
((boolean_T*) ssGetOutputPortSignal(S, 34))[0] = CANMMCAN_Arduino_CAPS[2];
/* Capture Message 4 RX Status */ 
((boolean_T*) ssGetOutputPortSignal(S, 47))[0] = CANMMCAN_Arduino_CAPS[3];
/* Capture Message 5 RX Status */ 
((boolean_T*) ssGetOutputPortSignal(S, 60))[0] = CANMMCAN_Arduino_CAPS[4];
/* Capture Message 6 RX Status */ 
((boolean_T*) ssGetOutputPortSignal(S, 73))[0] = CANMMCAN_Arduino_CAPS[5];
/* Capture Message 7 RX Status */ 
((boolean_T*) ssGetOutputPortSignal(S, 86))[0] = CANMMCAN_Arduino_CAPS[6];
/* Capture Message 8 RX Status */ 
((boolean_T*) ssGetOutputPortSignal(S, 99))[0] = CANMMCAN_Arduino_CAPS[7];
