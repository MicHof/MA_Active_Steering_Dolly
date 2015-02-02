/*
 * CAN_new_data.c
 *
 * Code generation for model "CAN_new".
 *
 * Model version              : 1.24
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Mon Feb 02 10:16:50 2015
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
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<S12>/Accelerometer_init_x'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S12>/Accelerometer_init_y'
                                        */
  -260.0,                              /* Expression: -260
                                        * Referenced by: '<S12>/Accelerometer_init_z '
                                        */
  -155.0,                              /* Expression: -155
                                        * Referenced by: '<S13>/angle_init_x'
                                        */
  -51.0,                               /* Expression: -51
                                        * Referenced by: '<S13>/angle_init_y'
                                        */
  450.0,                               /* Expression: 450
                                        * Referenced by: '<S13>/angle_init_z '
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S14>/gyro_init_x'
                                        */
  161.0,                               /* Expression: 161
                                        * Referenced by: '<S14>/gyro_init_y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/gyro_init_z '
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
                                        * Referenced by: '<S19>/RTICANMMCHANNEL_TLC'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/RTICANMMCHANNEL_TLC'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S19>/RTICANMMCHANNEL_TLC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/RTICANMMCHANNEL_TLC'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S19>/RTICANMMCHANNEL_TLC'
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
   * Referenced by: '<S19>/RTICANMMCHANNEL_TLC'
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
