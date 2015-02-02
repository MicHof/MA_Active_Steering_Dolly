/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_TX_PORT */
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

/* IMU_accelerometer.x */ 
ssSetInputPortDataType(S, 0, SS_INT16); 
ssSetInputPortWidth(S, 0, 1);
/* IMU_accelerometer.y */ 
ssSetInputPortDataType(S, 1, SS_INT16); 
ssSetInputPortWidth(S, 1, 1);
/* IMU_accelerometer.z */ 
ssSetInputPortDataType(S, 2, SS_INT16); 
ssSetInputPortWidth(S, 2, 1);
/* IMU_angels_corrected.x */ 
ssSetInputPortDataType(S, 3, SS_INT16); 
ssSetInputPortWidth(S, 3, 1);
/* IMU_angels_corrected.y */ 
ssSetInputPortDataType(S, 4, SS_INT16); 
ssSetInputPortWidth(S, 4, 1);
/* IMU_angels_corrected.z */ 
ssSetInputPortDataType(S, 5, SS_INT16); 
ssSetInputPortWidth(S, 5, 1);
/* IMU_gyroskop.x */ 
ssSetInputPortDataType(S, 6, SS_INT16); 
ssSetInputPortWidth(S, 6, 1);
/* IMU_gyroskop.y */ 
ssSetInputPortDataType(S, 7, SS_INT16); 
ssSetInputPortWidth(S, 7, 1);
/* IMU_gyroskop.z */ 
ssSetInputPortDataType(S, 8, SS_INT16); 
ssSetInputPortWidth(S, 8, 1);
