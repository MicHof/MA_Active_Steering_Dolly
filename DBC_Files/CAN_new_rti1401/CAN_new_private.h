/*
 * CAN_new_private.h
 *
 * Code generation for model "CAN_new".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Tue Jan 20 10:43:32 2015
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_CAN_new_private_h_
#define RTW_HEADER_CAN_new_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void RTICANMM_MAIN_CAN(SimStruct *rts);
extern void RTICANMM_SETUP_Controller1(SimStruct *rts);
extern void RTICANMM_MAIN_CAN_Arduino(SimStruct *rts);
extern void RTICANMM_SETUP_Controller3(SimStruct *rts);
extern void RTICANMM_SETUP_Controller2(SimStruct *rts);
extern void RTICANMM_MAIN_CAN_2(SimStruct *rts);

#endif                                 /* RTW_HEADER_CAN_new_private_h_ */
