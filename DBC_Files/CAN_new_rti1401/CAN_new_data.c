/*
 * CAN_new_data.c
 *
 * Code generation for model "CAN_new".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Thu Jan 22 10:17:19 2015
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "CAN_new.h"
#include "CAN_new_private.h"

/* Block parameters (auto storage) */
P_CAN_new_T CAN_new_P = {
  1401.0,                              /* Expression: 1401
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  1401.0,                              /* Expression: 1401
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  1401.0,                              /* Expression: 1401
                                        * Referenced by: '<S14>/RTICANMMCHANNEL_TLC'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/RTICANMMCHANNEL_TLC'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S14>/RTICANMMCHANNEL_TLC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/RTICANMMCHANNEL_TLC'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S14>/RTICANMMCHANNEL_TLC'
                                        */

  /*  Computed Parameter: RTICANMMCHANNEL_TLC_P6
   * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
   */
  { 117U, 110U, 117U, 115U, 101U, 100U },

  /*  Computed Parameter: RTICANMMCHANNEL_TLC_P6_n
   * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
   */
  { 117U, 110U, 117U, 115U, 101U, 100U },

  /*  Computed Parameter: RTICANMMCHANNEL_TLC_P6_j
   * Referenced by: '<S14>/RTICANMMCHANNEL_TLC'
   */
  { 117U, 110U, 117U, 115U, 101U, 100U },
  1U,                                  /* Computed Parameter: VariationRTICANMMControllerSetu
                                        * Referenced by: '<S1>/Variation@RTICANMM ControllerSetup'
                                        */
  1U,                                  /* Computed Parameter: VariationRTICANMMControllerSe_i
                                        * Referenced by: '<S2>/Variation@RTICANMM ControllerSetup'
                                        */
  1U,                                  /* Computed Parameter: VariationRTICANMMControllerSe_h
                                        * Referenced by: '<S3>/Variation@RTICANMM ControllerSetup'
                                        */
  0,                                   /* Computed Parameter: ResetRTICANMMControllerSetup_Va
                                        * Referenced by: '<S1>/Reset@RTICANMM ControllerSetup'
                                        */
  0,                                   /* Computed Parameter: ResetRTICANMMControllerSetup__d
                                        * Referenced by: '<S2>/Reset@RTICANMM ControllerSetup'
                                        */
  0                                    /* Computed Parameter: ResetRTICANMMControllerSetup__k
                                        * Referenced by: '<S3>/Reset@RTICANMM ControllerSetup'
                                        */
};
