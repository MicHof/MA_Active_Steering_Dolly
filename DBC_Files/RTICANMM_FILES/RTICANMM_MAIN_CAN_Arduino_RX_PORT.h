/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_Arduino_RX_PORT */
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
ssSetOutputPortDataType(S, 0, SS_INT16); 
ssSetOutputPortWidth(S, 0, 1); 
/* IMU_accelerometer.y */ 
ssSetOutputPortDataType(S, 1, SS_INT16); 
ssSetOutputPortWidth(S, 1, 1); 
/* IMU_accelerometer.z */ 
ssSetOutputPortDataType(S, 2, SS_INT16); 
ssSetOutputPortWidth(S, 2, 1); 
/* IMU_angels_corrected.x */ 
ssSetOutputPortDataType(S, 3, SS_INT16); 
ssSetOutputPortWidth(S, 3, 1); 
/* IMU_angels_corrected.y */ 
ssSetOutputPortDataType(S, 4, SS_INT16); 
ssSetOutputPortWidth(S, 4, 1); 
/* IMU_angels_corrected.z */ 
ssSetOutputPortDataType(S, 5, SS_INT16); 
ssSetOutputPortWidth(S, 5, 1); 
/* IMU_gyroskop.x */ 
ssSetOutputPortDataType(S, 6, SS_INT16); 
ssSetOutputPortWidth(S, 6, 1); 
/* IMU_gyroskop.y */ 
ssSetOutputPortDataType(S, 7, SS_INT16); 
ssSetOutputPortWidth(S, 7, 1); 
/* IMU_gyroskop.z */ 
ssSetOutputPortDataType(S, 8, SS_INT16); 
ssSetOutputPortWidth(S, 8, 1); 
