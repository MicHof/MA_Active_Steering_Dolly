/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_RX_PORT */
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

/* AngleSensor.PacketType */ 
ssSetOutputPortDataType(S, 0, SS_UINT8); 
ssSetOutputPortWidth(S, 0, 1); 
/* AngleSensor.MessageCounter */ 
ssSetOutputPortDataType(S, 1, SS_UINT8); 
ssSetOutputPortWidth(S, 1, 1); 
/* AngleSensor.Angle */ 
ssSetOutputPortDataType(S, 2, SS_DOUBLE); 
ssSetOutputPortWidth(S, 2, 1); 
/* AngleSensor.Temperature */ 
ssSetOutputPortDataType(S, 3, SS_INT16); 
ssSetOutputPortWidth(S, 3, 1); 
/* AngleSensor.AlarmWarningBits */ 
ssSetOutputPortDataType(S, 4, SS_UINT8); 
ssSetOutputPortWidth(S, 4, 1); 
/* ISO11992_EBS21.VehicleABSActive */ 
ssSetOutputPortDataType(S, 5, SS_UINT8); 
ssSetOutputPortWidth(S, 5, 1); 
/* ISO11992_EBS21.VehicleRetarderCtrlActive */ 
ssSetOutputPortDataType(S, 6, SS_UINT8); 
ssSetOutputPortWidth(S, 6, 1); 
/* ISO11992_EBS21.VehicleServiceBrakeActive */ 
ssSetOutputPortDataType(S, 7, SS_UINT8); 
ssSetOutputPortWidth(S, 7, 1); 
/* ISO11992_EBS21.AutomTowedVehBreakActive */ 
ssSetOutputPortDataType(S, 8, SS_UINT8); 
ssSetOutputPortWidth(S, 8, 1); 
/* ISO11992_EBS21.VDCActive */ 
ssSetOutputPortDataType(S, 9, SS_UINT8); 
ssSetOutputPortWidth(S, 9, 1); 
/* ISO11992_EBS21.SupplyLineBrakingRequest */ 
ssSetOutputPortDataType(S, 10, SS_UINT8); 
ssSetOutputPortWidth(S, 10, 1); 
/* ISO11992_EBS21.Wheel_BasedVehicleSpeed */ 
ssSetOutputPortDataType(S, 11, SS_DOUBLE); 
ssSetOutputPortWidth(S, 11, 1); 
/* ISO11992_EBS21.ActualRetarderPercTorque */ 
ssSetOutputPortDataType(S, 12, SS_INT16); 
ssSetOutputPortWidth(S, 12, 1); 
/* ISO11992_EBS21.WheelSpeedDiffMainAxle */ 
ssSetOutputPortDataType(S, 13, SS_DOUBLE); 
ssSetOutputPortWidth(S, 13, 1); 
