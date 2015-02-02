/*
 * CAN_new.c
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
#include "CAN_new_trc_ptr.h"
#include "CAN_new.h"
#include "CAN_new_private.h"

const int16_T CAN_new_I16GND = 0;      /* int16_T ground */

/* Block signals (auto storage) */
B_CAN_new_T CAN_new_B;

/* Block states (auto storage) */
DW_CAN_new_T CAN_new_DW;

/* Real-time model */
RT_MODEL_CAN_new_T CAN_new_M_;
RT_MODEL_CAN_new_T *const CAN_new_M = &CAN_new_M_;

/* Model output function */
static void CAN_new_output(void)
{
  /* Level2 S-Function Block: '<S7>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* DataTypeConversion: '<S5>/Variation_DTC' incorporates:
   *  Constant: '<S1>/Variation@RTICANMM ControllerSetup'
   */
  CAN_new_B.Variation_DTC = CAN_new_P.VariationRTICANMMControllerSetu;

  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S6>/Constant' */
  CAN_new_B.Constant = CAN_new_P.Constant_Value;

  /* Level2 S-Function Block: '<S10>/sfcn' (RTICANMM_MAIN_CAN_Arduino) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S12>/IMU_accel_corrected_x' incorporates:
   *  Constant: '<S12>/Accelerometer_init_x'
   */
  CAN_new_B.IMU_accel_corrected_x = CAN_new_P.Accelerometer_init_x_Value +
    (real_T)CAN_new_B.sfcn_o1_d;

  /* Sum: '<S12>/IMU_accel_corrected_y' incorporates:
   *  Constant: '<S12>/Accelerometer_init_y'
   */
  CAN_new_B.IMU_accel_corrected_y = (real_T)CAN_new_B.sfcn_o2_p +
    CAN_new_P.Accelerometer_init_y_Value;

  /* Sum: '<S12>/IMU_accel_corrected_z' incorporates:
   *  Constant: '<S12>/Accelerometer_init_z '
   */
  CAN_new_B.IMU_accel_corrected_z = (real_T)CAN_new_B.sfcn_o3_nj +
    CAN_new_P.Accelerometer_init_z_Value;

  /* Sum: '<S13>/IMU_angle_corrected_x' incorporates:
   *  Constant: '<S13>/angle_init_x'
   */
  CAN_new_B.IMU_angle_corrected_x = CAN_new_P.angle_init_x_Value + (real_T)
    CAN_new_B.sfcn_o4_n;

  /* Sum: '<S13>/IMU_angle_corrected_y' incorporates:
   *  Constant: '<S13>/angle_init_y'
   */
  CAN_new_B.IMU_angle_corrected_y = (real_T)CAN_new_B.sfcn_o5_e +
    CAN_new_P.angle_init_y_Value;

  /* Sum: '<S13>/IMU_angle_corrected_z' incorporates:
   *  Constant: '<S13>/angle_init_z '
   */
  CAN_new_B.IMU_angle_corrected_z = (real_T)CAN_new_B.sfcn_o6_k +
    CAN_new_P.angle_init_z_Value;

  /* Sum: '<S14>/IMU_gyro_corrected_x' incorporates:
   *  Constant: '<S14>/gyro_init_x'
   */
  CAN_new_B.IMU_gyro_corrected_x = CAN_new_P.gyro_init_x_Value + (real_T)
    CAN_new_B.sfcn_o7_p;

  /* Sum: '<S14>/IMU_gyro_corrected_y' incorporates:
   *  Constant: '<S14>/gyro_init_y'
   */
  CAN_new_B.IMU_gyro_corrected_y = (real_T)CAN_new_B.sfcn_o8_n +
    CAN_new_P.gyro_init_y_Value;

  /* Sum: '<S14>/IMU_gyro_corrected_z' incorporates:
   *  Constant: '<S14>/gyro_init_z '
   */
  CAN_new_B.IMU_gyro_corrected_z = (real_T)CAN_new_B.sfcn_o9_c +
    CAN_new_P.gyro_init_z_Value;

  /* DataTypeConversion: '<S9>/Variation_DTC' incorporates:
   *  Constant: '<S2>/Variation@RTICANMM ControllerSetup'
   */
  CAN_new_B.Variation_DTC_g = CAN_new_P.VariationRTICANMMControllerSe_i;

  /* Level2 S-Function Block: '<S9>/sfcn' (RTICANMM_SETUP_Controller3) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S20>/sfcn' (RTICANMM_MAIN_CAN_2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* DataTypeConversion: '<S19>/Variation_DTC' incorporates:
   *  Constant: '<S3>/Variation@RTICANMM ControllerSetup'
   */
  CAN_new_B.Variation_DTC_h = CAN_new_P.VariationRTICANMMControllerSe_h;

  /* Level2 S-Function Block: '<S19>/sfcn' (RTICANMM_SETUP_Controller2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
static void CAN_new_update(void)
{
  /* Level2 S-Function Block: '<S7>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[0];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[1];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S10>/sfcn' (RTICANMM_MAIN_CAN_Arduino) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[2];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S9>/sfcn' (RTICANMM_SETUP_Controller3) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[3];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S20>/sfcn' (RTICANMM_MAIN_CAN_2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[4];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S19>/sfcn' (RTICANMM_SETUP_Controller2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[5];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++CAN_new_M->Timing.clockTick0)) {
    ++CAN_new_M->Timing.clockTickH0;
  }

  CAN_new_M->Timing.t[0] = CAN_new_M->Timing.clockTick0 *
    CAN_new_M->Timing.stepSize0 + CAN_new_M->Timing.clockTickH0 *
    CAN_new_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void CAN_new_initialize(void)
{
  /* user code (Start function Body) */
  {
    /* Initialize host service for CAN monitoring */
    ts_timestamp_type ts = { 0, 0 };

    host_service(31, &ts);
  }

  /* Level2 S-Function Block: '<S7>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S10>/sfcn' (RTICANMM_MAIN_CAN_Arduino) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S9>/sfcn' (RTICANMM_SETUP_Controller3) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S20>/sfcn' (RTICANMM_MAIN_CAN_2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S19>/sfcn' (RTICANMM_SETUP_Controller2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S7>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S10>/sfcn' (RTICANMM_MAIN_CAN_Arduino) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S9>/sfcn' (RTICANMM_SETUP_Controller3) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[3];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S20>/sfcn' (RTICANMM_MAIN_CAN_2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[4];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S19>/sfcn' (RTICANMM_SETUP_Controller2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[5];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void CAN_new_terminate(void)
{
  /* Level2 S-Function Block: '<S7>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/sfcn' (RTICANMM_MAIN_CAN_Arduino) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/sfcn' (RTICANMM_SETUP_Controller3) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S20>/sfcn' (RTICANMM_MAIN_CAN_2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S19>/sfcn' (RTICANMM_SETUP_Controller2) */
  {
    SimStruct *rts = CAN_new_M->childSfunctions[5];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  CAN_new_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  CAN_new_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  CAN_new_initialize();
}

void MdlTerminate(void)
{
  CAN_new_terminate();
}

/* Registration function */
RT_MODEL_CAN_new_T *CAN_new(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)CAN_new_M, 0,
                sizeof(RT_MODEL_CAN_new_T));
  rtsiSetSolverName(&CAN_new_M->solverInfo,"FixedStepDiscrete");
  CAN_new_M->solverInfoPtr = (&CAN_new_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CAN_new_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    CAN_new_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CAN_new_M->Timing.sampleTimes = (&CAN_new_M->Timing.sampleTimesArray[0]);
    CAN_new_M->Timing.offsetTimes = (&CAN_new_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CAN_new_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    CAN_new_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(CAN_new_M, &CAN_new_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = CAN_new_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    CAN_new_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CAN_new_M, -1);
  CAN_new_M->Timing.stepSize0 = 0.001;
  CAN_new_M->solverInfoPtr = (&CAN_new_M->solverInfo);
  CAN_new_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&CAN_new_M->solverInfo, 0.001);
  rtsiSetSolverMode(&CAN_new_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  CAN_new_M->ModelData.blockIO = ((void *) &CAN_new_B);
  (void) memset(((void *) &CAN_new_B), 0,
                sizeof(B_CAN_new_T));

  /* parameters */
  CAN_new_M->ModelData.defaultParam = ((real_T *)&CAN_new_P);

  /* states (dwork) */
  CAN_new_M->ModelData.dwork = ((void *) &CAN_new_DW);
  (void) memset((void *)&CAN_new_DW, 0,
                sizeof(DW_CAN_new_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &CAN_new_M->NonInlinedSFcns.sfcnInfo;
    CAN_new_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(CAN_new_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &CAN_new_M->Sizes.numSampTimes);
    CAN_new_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(CAN_new_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,CAN_new_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(CAN_new_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(CAN_new_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(CAN_new_M));
    rtssSetStepSizePtr(sfcnInfo, &CAN_new_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(CAN_new_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &CAN_new_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &CAN_new_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &CAN_new_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &CAN_new_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &CAN_new_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &CAN_new_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &CAN_new_M->solverInfoPtr);
  }

  CAN_new_M->Sizes.numSFcns = (6);

  /* register each child */
  {
    (void) memset((void *)&CAN_new_M->NonInlinedSFcns.childSFunctions[0], 0,
                  6*sizeof(SimStruct));
    CAN_new_M->childSfunctions = (&CAN_new_M->
      NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 6; i++) {
        CAN_new_M->childSfunctions[i] =
          (&CAN_new_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: CAN_new/<S7>/sfcn (RTICANMM_MAIN_CAN) */
    {
      SimStruct *rts = CAN_new_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = CAN_new_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = CAN_new_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = CAN_new_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CAN_new_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, CAN_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CAN_new_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CAN_new_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CAN_new_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CAN_new_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 14);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) &CAN_new_B.sfcn_o1_f));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *) &CAN_new_B.sfcn_o2_j));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &CAN_new_B.sfcn_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((int16_T *) &CAN_new_B.sfcn_o4_g));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint8_T *) &CAN_new_B.sfcn_o5_a));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint8_T *) &CAN_new_B.sfcn_o6_b));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((uint8_T *) &CAN_new_B.sfcn_o7_a));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((uint8_T *) &CAN_new_B.sfcn_o8_g));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((uint8_T *) &CAN_new_B.sfcn_o9_g));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((uint8_T *) &CAN_new_B.sfcn_o10_j));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((uint8_T *) &CAN_new_B.sfcn_o11_p));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *) &CAN_new_B.sfcn_o12));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((int16_T *) &CAN_new_B.sfcn_o13_o));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 1);
          ssSetOutputPortSignal(rts, 13, ((real_T *) &CAN_new_B.sfcn_o14));
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "CAN_new/Angle_Sensor/RTICANMM MainBlock/sfcn");
      ssSetRTModel(rts,CAN_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &CAN_new_DW.sfcn_RWORK);
      ssSetPWork(rts, (void **) &CAN_new_DW.sfcn_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CAN_new_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CAN_new_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CAN_new_DW.sfcn_RWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 16);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &CAN_new_DW.sfcn_PWORK[0]);
      }

      /* registration */
      RTICANMM_MAIN_CAN(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 1);
      _ssSetOutputPortConnected(rts, 12, 1);
      _ssSetOutputPortConnected(rts, 13, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);
      _ssSetOutputPortBeingMerged(rts, 12, 0);
      _ssSetOutputPortBeingMerged(rts, 13, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CAN_new/<S5>/sfcn (RTICANMM_SETUP_Controller1) */
    {
      SimStruct *rts = CAN_new_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = CAN_new_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = CAN_new_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = CAN_new_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CAN_new_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, CAN_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CAN_new_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CAN_new_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CAN_new_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &CAN_new_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &CAN_new_B.Variation_DTC);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1,
                               &CAN_new_P.ResetRTICANMMControllerSetup_Va);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "CAN_new/Angle_Sensor/RTICANMM ControllerSetup/sfcn");
      ssSetRTModel(rts,CAN_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      RTICANMM_SETUP_Controller1(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: CAN_new/<S10>/sfcn (RTICANMM_MAIN_CAN_Arduino) */
    {
      SimStruct *rts = CAN_new_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = CAN_new_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = CAN_new_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = CAN_new_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CAN_new_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, CAN_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CAN_new_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CAN_new_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CAN_new_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 9);
        ssSetPortInfoForInputs(rts,
          &CAN_new_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          ssSetInputPortRequiredContiguous(rts, 3, 1);
          ssSetInputPortSignal(rts, 3, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          ssSetInputPortRequiredContiguous(rts, 4, 1);
          ssSetInputPortSignal(rts, 4, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          ssSetInputPortRequiredContiguous(rts, 5, 1);
          ssSetInputPortSignal(rts, 5, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          ssSetInputPortRequiredContiguous(rts, 6, 1);
          ssSetInputPortSignal(rts, 6, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          ssSetInputPortRequiredContiguous(rts, 7, 1);
          ssSetInputPortSignal(rts, 7, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }

        /* port 8 */
        {
          ssSetInputPortRequiredContiguous(rts, 8, 1);
          ssSetInputPortSignal(rts, 8, (int16_T*)&CAN_new_I16GND);
          _ssSetInputPortNumDimensions(rts, 8, 1);
          ssSetInputPortWidth(rts, 8, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CAN_new_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 9);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int16_T *) &CAN_new_B.sfcn_o1_d));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((int16_T *) &CAN_new_B.sfcn_o2_p));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((int16_T *) &CAN_new_B.sfcn_o3_nj));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((int16_T *) &CAN_new_B.sfcn_o4_n));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((int16_T *) &CAN_new_B.sfcn_o5_e));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int16_T *) &CAN_new_B.sfcn_o6_k));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((int16_T *) &CAN_new_B.sfcn_o7_p));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((int16_T *) &CAN_new_B.sfcn_o8_n));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((int16_T *) &CAN_new_B.sfcn_o9_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "CAN_new/Arduino/RTICANMM MainBlock/sfcn");
      ssSetRTModel(rts,CAN_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &CAN_new_DW.sfcn_RWORK_c);
      ssSetPWork(rts, (void **) &CAN_new_DW.sfcn_PWORK_a[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CAN_new_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CAN_new_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CAN_new_DW.sfcn_RWORK_c);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 16);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &CAN_new_DW.sfcn_PWORK_a[0]);
      }

      /* registration */
      RTICANMM_MAIN_CAN_Arduino(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetInputPortConnected(rts, 6, 1);
      _ssSetInputPortConnected(rts, 7, 1);
      _ssSetInputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
      ssSetInputPortBufferDstPort(rts, 7, -1);
      ssSetInputPortBufferDstPort(rts, 8, -1);
    }

    /* Level2 S-Function Block: CAN_new/<S9>/sfcn (RTICANMM_SETUP_Controller3) */
    {
      SimStruct *rts = CAN_new_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = CAN_new_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = CAN_new_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = CAN_new_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CAN_new_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, CAN_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CAN_new_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CAN_new_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CAN_new_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &CAN_new_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &CAN_new_B.Variation_DTC_g);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1,
                               &CAN_new_P.ResetRTICANMMControllerSetup__d);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "CAN_new/Arduino/RTICANMM ControllerSetup/sfcn");
      ssSetRTModel(rts,CAN_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      RTICANMM_SETUP_Controller3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: CAN_new/<S20>/sfcn (RTICANMM_MAIN_CAN_2) */
    {
      SimStruct *rts = CAN_new_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = CAN_new_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = CAN_new_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = CAN_new_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CAN_new_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, CAN_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CAN_new_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CAN_new_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CAN_new_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CAN_new_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 97);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CAN_new_B.sfcn_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &CAN_new_B.sfcn_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &CAN_new_B.sfcn_o3_n));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &CAN_new_B.sfcn_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &CAN_new_B.sfcn_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &CAN_new_B.sfcn_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &CAN_new_B.sfcn_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &CAN_new_B.sfcn_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *) &CAN_new_B.sfcn_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *) &CAN_new_B.sfcn_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *) &CAN_new_B.sfcn_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *) &CAN_new_B.sfcn_o12_m));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((real_T *) &CAN_new_B.sfcn_o13));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 1);
          ssSetOutputPortSignal(rts, 13, ((real_T *) &CAN_new_B.sfcn_o14_a));
        }

        /* port 14 */
        {
          _ssSetOutputPortNumDimensions(rts, 14, 1);
          ssSetOutputPortWidth(rts, 14, 1);
          ssSetOutputPortSignal(rts, 14, ((real_T *) &CAN_new_B.sfcn_o15));
        }

        /* port 15 */
        {
          _ssSetOutputPortNumDimensions(rts, 15, 1);
          ssSetOutputPortWidth(rts, 15, 1);
          ssSetOutputPortSignal(rts, 15, ((real_T *) &CAN_new_B.sfcn_o16));
        }

        /* port 16 */
        {
          _ssSetOutputPortNumDimensions(rts, 16, 1);
          ssSetOutputPortWidth(rts, 16, 1);
          ssSetOutputPortSignal(rts, 16, ((uint8_T *) &CAN_new_B.sfcn_o17));
        }

        /* port 17 */
        {
          _ssSetOutputPortNumDimensions(rts, 17, 1);
          ssSetOutputPortWidth(rts, 17, 1);
          ssSetOutputPortSignal(rts, 17, ((uint8_T *) &CAN_new_B.sfcn_o18));
        }

        /* port 18 */
        {
          _ssSetOutputPortNumDimensions(rts, 18, 1);
          ssSetOutputPortWidth(rts, 18, 1);
          ssSetOutputPortSignal(rts, 18, ((uint8_T *) &CAN_new_B.sfcn_o19));
        }

        /* port 19 */
        {
          _ssSetOutputPortNumDimensions(rts, 19, 1);
          ssSetOutputPortWidth(rts, 19, 1);
          ssSetOutputPortSignal(rts, 19, ((uint8_T *) &CAN_new_B.sfcn_o20));
        }

        /* port 20 */
        {
          _ssSetOutputPortNumDimensions(rts, 20, 1);
          ssSetOutputPortWidth(rts, 20, 1);
          ssSetOutputPortSignal(rts, 20, ((uint8_T *) &CAN_new_B.sfcn_o21));
        }

        /* port 21 */
        {
          _ssSetOutputPortNumDimensions(rts, 21, 1);
          ssSetOutputPortWidth(rts, 21, 1);
          ssSetOutputPortSignal(rts, 21, ((uint8_T *) &CAN_new_B.sfcn_o22));
        }

        /* port 22 */
        {
          _ssSetOutputPortNumDimensions(rts, 22, 1);
          ssSetOutputPortWidth(rts, 22, 1);
          ssSetOutputPortSignal(rts, 22, ((uint8_T *) &CAN_new_B.sfcn_o23));
        }

        /* port 23 */
        {
          _ssSetOutputPortNumDimensions(rts, 23, 1);
          ssSetOutputPortWidth(rts, 23, 1);
          ssSetOutputPortSignal(rts, 23, ((uint8_T *) &CAN_new_B.sfcn_o24));
        }

        /* port 24 */
        {
          _ssSetOutputPortNumDimensions(rts, 24, 1);
          ssSetOutputPortWidth(rts, 24, 1);
          ssSetOutputPortSignal(rts, 24, ((uint8_T *) &CAN_new_B.sfcn_o25));
        }

        /* port 25 */
        {
          _ssSetOutputPortNumDimensions(rts, 25, 1);
          ssSetOutputPortWidth(rts, 25, 1);
          ssSetOutputPortSignal(rts, 25, ((uint8_T *) &CAN_new_B.sfcn_o26));
        }

        /* port 26 */
        {
          _ssSetOutputPortNumDimensions(rts, 26, 1);
          ssSetOutputPortWidth(rts, 26, 1);
          ssSetOutputPortSignal(rts, 26, ((uint8_T *) &CAN_new_B.sfcn_o27));
        }

        /* port 27 */
        {
          _ssSetOutputPortNumDimensions(rts, 27, 1);
          ssSetOutputPortWidth(rts, 27, 1);
          ssSetOutputPortSignal(rts, 27, ((uint8_T *) &CAN_new_B.sfcn_o28));
        }

        /* port 28 */
        {
          _ssSetOutputPortNumDimensions(rts, 28, 1);
          ssSetOutputPortWidth(rts, 28, 1);
          ssSetOutputPortSignal(rts, 28, ((uint8_T *) &CAN_new_B.sfcn_o29));
        }

        /* port 29 */
        {
          _ssSetOutputPortNumDimensions(rts, 29, 1);
          ssSetOutputPortWidth(rts, 29, 1);
          ssSetOutputPortSignal(rts, 29, ((real_T *) &CAN_new_B.sfcn_o30));
        }

        /* port 30 */
        {
          _ssSetOutputPortNumDimensions(rts, 30, 1);
          ssSetOutputPortWidth(rts, 30, 1);
          ssSetOutputPortSignal(rts, 30, ((real_T *) &CAN_new_B.sfcn_o31));
        }

        /* port 31 */
        {
          _ssSetOutputPortNumDimensions(rts, 31, 1);
          ssSetOutputPortWidth(rts, 31, 1);
          ssSetOutputPortSignal(rts, 31, ((real_T *) &CAN_new_B.sfcn_o32));
        }

        /* port 32 */
        {
          _ssSetOutputPortNumDimensions(rts, 32, 1);
          ssSetOutputPortWidth(rts, 32, 1);
          ssSetOutputPortSignal(rts, 32, ((real_T *) &CAN_new_B.sfcn_o33));
        }

        /* port 33 */
        {
          _ssSetOutputPortNumDimensions(rts, 33, 1);
          ssSetOutputPortWidth(rts, 33, 1);
          ssSetOutputPortSignal(rts, 33, ((real_T *) &CAN_new_B.sfcn_o34));
        }

        /* port 34 */
        {
          _ssSetOutputPortNumDimensions(rts, 34, 1);
          ssSetOutputPortWidth(rts, 34, 1);
          ssSetOutputPortSignal(rts, 34, ((real_T *) &CAN_new_B.sfcn_o35));
        }

        /* port 35 */
        {
          _ssSetOutputPortNumDimensions(rts, 35, 1);
          ssSetOutputPortWidth(rts, 35, 1);
          ssSetOutputPortSignal(rts, 35, ((real_T *) &CAN_new_B.sfcn_o36));
        }

        /* port 36 */
        {
          _ssSetOutputPortNumDimensions(rts, 36, 1);
          ssSetOutputPortWidth(rts, 36, 1);
          ssSetOutputPortSignal(rts, 36, ((int16_T *) &CAN_new_B.sfcn_o37));
        }

        /* port 37 */
        {
          _ssSetOutputPortNumDimensions(rts, 37, 1);
          ssSetOutputPortWidth(rts, 37, 1);
          ssSetOutputPortSignal(rts, 37, ((int16_T *) &CAN_new_B.sfcn_o38));
        }

        /* port 38 */
        {
          _ssSetOutputPortNumDimensions(rts, 38, 1);
          ssSetOutputPortWidth(rts, 38, 1);
          ssSetOutputPortSignal(rts, 38, ((uint8_T *) &CAN_new_B.sfcn_o39));
        }

        /* port 39 */
        {
          _ssSetOutputPortNumDimensions(rts, 39, 1);
          ssSetOutputPortWidth(rts, 39, 1);
          ssSetOutputPortSignal(rts, 39, ((uint8_T *) &CAN_new_B.sfcn_o40));
        }

        /* port 40 */
        {
          _ssSetOutputPortNumDimensions(rts, 40, 1);
          ssSetOutputPortWidth(rts, 40, 1);
          ssSetOutputPortSignal(rts, 40, ((real_T *) &CAN_new_B.sfcn_o41));
        }

        /* port 41 */
        {
          _ssSetOutputPortNumDimensions(rts, 41, 1);
          ssSetOutputPortWidth(rts, 41, 1);
          ssSetOutputPortSignal(rts, 41, ((real_T *) &CAN_new_B.sfcn_o42));
        }

        /* port 42 */
        {
          _ssSetOutputPortNumDimensions(rts, 42, 1);
          ssSetOutputPortWidth(rts, 42, 1);
          ssSetOutputPortSignal(rts, 42, ((int16_T *) &CAN_new_B.sfcn_o43));
        }

        /* port 43 */
        {
          _ssSetOutputPortNumDimensions(rts, 43, 1);
          ssSetOutputPortWidth(rts, 43, 1);
          ssSetOutputPortSignal(rts, 43, ((uint8_T *) &CAN_new_B.sfcn_o44));
        }

        /* port 44 */
        {
          _ssSetOutputPortNumDimensions(rts, 44, 1);
          ssSetOutputPortWidth(rts, 44, 1);
          ssSetOutputPortSignal(rts, 44, ((uint16_T *) &CAN_new_B.sfcn_o45));
        }

        /* port 45 */
        {
          _ssSetOutputPortNumDimensions(rts, 45, 1);
          ssSetOutputPortWidth(rts, 45, 1);
          ssSetOutputPortSignal(rts, 45, ((real_T *) &CAN_new_B.sfcn_o46));
        }

        /* port 46 */
        {
          _ssSetOutputPortNumDimensions(rts, 46, 1);
          ssSetOutputPortWidth(rts, 46, 1);
          ssSetOutputPortSignal(rts, 46, ((boolean_T *) &CAN_new_B.sfcn_o47));
        }

        /* port 47 */
        {
          _ssSetOutputPortNumDimensions(rts, 47, 1);
          ssSetOutputPortWidth(rts, 47, 1);
          ssSetOutputPortSignal(rts, 47, ((boolean_T *) &CAN_new_B.sfcn_o48));
        }

        /* port 48 */
        {
          _ssSetOutputPortNumDimensions(rts, 48, 1);
          ssSetOutputPortWidth(rts, 48, 1);
          ssSetOutputPortSignal(rts, 48, ((boolean_T *) &CAN_new_B.sfcn_o49));
        }

        /* port 49 */
        {
          _ssSetOutputPortNumDimensions(rts, 49, 1);
          ssSetOutputPortWidth(rts, 49, 1);
          ssSetOutputPortSignal(rts, 49, ((boolean_T *) &CAN_new_B.sfcn_o50));
        }

        /* port 50 */
        {
          _ssSetOutputPortNumDimensions(rts, 50, 1);
          ssSetOutputPortWidth(rts, 50, 1);
          ssSetOutputPortSignal(rts, 50, ((uint8_T *) &CAN_new_B.sfcn_o51));
        }

        /* port 51 */
        {
          _ssSetOutputPortNumDimensions(rts, 51, 1);
          ssSetOutputPortWidth(rts, 51, 1);
          ssSetOutputPortSignal(rts, 51, ((uint8_T *) &CAN_new_B.sfcn_o52));
        }

        /* port 52 */
        {
          _ssSetOutputPortNumDimensions(rts, 52, 1);
          ssSetOutputPortWidth(rts, 52, 1);
          ssSetOutputPortSignal(rts, 52, ((uint8_T *) &CAN_new_B.sfcn_o53));
        }

        /* port 53 */
        {
          _ssSetOutputPortNumDimensions(rts, 53, 1);
          ssSetOutputPortWidth(rts, 53, 1);
          ssSetOutputPortSignal(rts, 53, ((uint8_T *) &CAN_new_B.sfcn_o54));
        }

        /* port 54 */
        {
          _ssSetOutputPortNumDimensions(rts, 54, 1);
          ssSetOutputPortWidth(rts, 54, 1);
          ssSetOutputPortSignal(rts, 54, ((uint8_T *) &CAN_new_B.sfcn_o55));
        }

        /* port 55 */
        {
          _ssSetOutputPortNumDimensions(rts, 55, 1);
          ssSetOutputPortWidth(rts, 55, 1);
          ssSetOutputPortSignal(rts, 55, ((uint8_T *) &CAN_new_B.sfcn_o56));
        }

        /* port 56 */
        {
          _ssSetOutputPortNumDimensions(rts, 56, 1);
          ssSetOutputPortWidth(rts, 56, 1);
          ssSetOutputPortSignal(rts, 56, ((boolean_T *) &CAN_new_B.sfcn_o57));
        }

        /* port 57 */
        {
          _ssSetOutputPortNumDimensions(rts, 57, 1);
          ssSetOutputPortWidth(rts, 57, 1);
          ssSetOutputPortSignal(rts, 57, ((uint8_T *) &CAN_new_B.sfcn_o58));
        }

        /* port 58 */
        {
          _ssSetOutputPortNumDimensions(rts, 58, 1);
          ssSetOutputPortWidth(rts, 58, 1);
          ssSetOutputPortSignal(rts, 58, ((real_T *) &CAN_new_B.sfcn_o59));
        }

        /* port 59 */
        {
          _ssSetOutputPortNumDimensions(rts, 59, 1);
          ssSetOutputPortWidth(rts, 59, 1);
          ssSetOutputPortSignal(rts, 59, ((uint8_T *) &CAN_new_B.sfcn_o60));
        }

        /* port 60 */
        {
          _ssSetOutputPortNumDimensions(rts, 60, 1);
          ssSetOutputPortWidth(rts, 60, 1);
          ssSetOutputPortSignal(rts, 60, ((uint8_T *) &CAN_new_B.sfcn_o61));
        }

        /* port 61 */
        {
          _ssSetOutputPortNumDimensions(rts, 61, 1);
          ssSetOutputPortWidth(rts, 61, 1);
          ssSetOutputPortSignal(rts, 61, ((uint8_T *) &CAN_new_B.sfcn_o62));
        }

        /* port 62 */
        {
          _ssSetOutputPortNumDimensions(rts, 62, 1);
          ssSetOutputPortWidth(rts, 62, 1);
          ssSetOutputPortSignal(rts, 62, ((real_T *) &CAN_new_B.sfcn_o63));
        }

        /* port 63 */
        {
          _ssSetOutputPortNumDimensions(rts, 63, 1);
          ssSetOutputPortWidth(rts, 63, 1);
          ssSetOutputPortSignal(rts, 63, ((uint8_T *) &CAN_new_B.sfcn_o64));
        }

        /* port 64 */
        {
          _ssSetOutputPortNumDimensions(rts, 64, 1);
          ssSetOutputPortWidth(rts, 64, 1);
          ssSetOutputPortSignal(rts, 64, ((uint8_T *) &CAN_new_B.sfcn_o65));
        }

        /* port 65 */
        {
          _ssSetOutputPortNumDimensions(rts, 65, 1);
          ssSetOutputPortWidth(rts, 65, 1);
          ssSetOutputPortSignal(rts, 65, ((uint8_T *) &CAN_new_B.sfcn_o66));
        }

        /* port 66 */
        {
          _ssSetOutputPortNumDimensions(rts, 66, 1);
          ssSetOutputPortWidth(rts, 66, 1);
          ssSetOutputPortSignal(rts, 66, ((real_T *) &CAN_new_B.sfcn_o67));
        }

        /* port 67 */
        {
          _ssSetOutputPortNumDimensions(rts, 67, 1);
          ssSetOutputPortWidth(rts, 67, 1);
          ssSetOutputPortSignal(rts, 67, ((real_T *) &CAN_new_B.sfcn_o68));
        }

        /* port 68 */
        {
          _ssSetOutputPortNumDimensions(rts, 68, 1);
          ssSetOutputPortWidth(rts, 68, 1);
          ssSetOutputPortSignal(rts, 68, ((real_T *) &CAN_new_B.sfcn_o69));
        }

        /* port 69 */
        {
          _ssSetOutputPortNumDimensions(rts, 69, 1);
          ssSetOutputPortWidth(rts, 69, 1);
          ssSetOutputPortSignal(rts, 69, ((real_T *) &CAN_new_B.sfcn_o70));
        }

        /* port 70 */
        {
          _ssSetOutputPortNumDimensions(rts, 70, 1);
          ssSetOutputPortWidth(rts, 70, 1);
          ssSetOutputPortSignal(rts, 70, ((real_T *) &CAN_new_B.sfcn_o71));
        }

        /* port 71 */
        {
          _ssSetOutputPortNumDimensions(rts, 71, 1);
          ssSetOutputPortWidth(rts, 71, 1);
          ssSetOutputPortSignal(rts, 71, ((real_T *) &CAN_new_B.sfcn_o72));
        }

        /* port 72 */
        {
          _ssSetOutputPortNumDimensions(rts, 72, 1);
          ssSetOutputPortWidth(rts, 72, 1);
          ssSetOutputPortSignal(rts, 72, ((real_T *) &CAN_new_B.sfcn_o73));
        }

        /* port 73 */
        {
          _ssSetOutputPortNumDimensions(rts, 73, 1);
          ssSetOutputPortWidth(rts, 73, 1);
          ssSetOutputPortSignal(rts, 73, ((real_T *) &CAN_new_B.sfcn_o74));
        }

        /* port 74 */
        {
          _ssSetOutputPortNumDimensions(rts, 74, 1);
          ssSetOutputPortWidth(rts, 74, 1);
          ssSetOutputPortSignal(rts, 74, ((real_T *) &CAN_new_B.sfcn_o75));
        }

        /* port 75 */
        {
          _ssSetOutputPortNumDimensions(rts, 75, 1);
          ssSetOutputPortWidth(rts, 75, 1);
          ssSetOutputPortSignal(rts, 75, ((real_T *) &CAN_new_B.sfcn_o76));
        }

        /* port 76 */
        {
          _ssSetOutputPortNumDimensions(rts, 76, 1);
          ssSetOutputPortWidth(rts, 76, 1);
          ssSetOutputPortSignal(rts, 76, ((real_T *) &CAN_new_B.sfcn_o77));
        }

        /* port 77 */
        {
          _ssSetOutputPortNumDimensions(rts, 77, 1);
          ssSetOutputPortWidth(rts, 77, 1);
          ssSetOutputPortSignal(rts, 77, ((real_T *) &CAN_new_B.sfcn_o78));
        }

        /* port 78 */
        {
          _ssSetOutputPortNumDimensions(rts, 78, 1);
          ssSetOutputPortWidth(rts, 78, 1);
          ssSetOutputPortSignal(rts, 78, ((real_T *) &CAN_new_B.sfcn_o79));
        }

        /* port 79 */
        {
          _ssSetOutputPortNumDimensions(rts, 79, 1);
          ssSetOutputPortWidth(rts, 79, 1);
          ssSetOutputPortSignal(rts, 79, ((real_T *) &CAN_new_B.sfcn_o80));
        }

        /* port 80 */
        {
          _ssSetOutputPortNumDimensions(rts, 80, 1);
          ssSetOutputPortWidth(rts, 80, 1);
          ssSetOutputPortSignal(rts, 80, ((real_T *) &CAN_new_B.sfcn_o81));
        }

        /* port 81 */
        {
          _ssSetOutputPortNumDimensions(rts, 81, 1);
          ssSetOutputPortWidth(rts, 81, 1);
          ssSetOutputPortSignal(rts, 81, ((real_T *) &CAN_new_B.sfcn_o82));
        }

        /* port 82 */
        {
          _ssSetOutputPortNumDimensions(rts, 82, 1);
          ssSetOutputPortWidth(rts, 82, 1);
          ssSetOutputPortSignal(rts, 82, ((uint8_T *) &CAN_new_B.sfcn_o83));
        }

        /* port 83 */
        {
          _ssSetOutputPortNumDimensions(rts, 83, 1);
          ssSetOutputPortWidth(rts, 83, 1);
          ssSetOutputPortSignal(rts, 83, ((uint8_T *) &CAN_new_B.sfcn_o84));
        }

        /* port 84 */
        {
          _ssSetOutputPortNumDimensions(rts, 84, 1);
          ssSetOutputPortWidth(rts, 84, 1);
          ssSetOutputPortSignal(rts, 84, ((int8_T *) &CAN_new_B.sfcn_o85));
        }

        /* port 85 */
        {
          _ssSetOutputPortNumDimensions(rts, 85, 1);
          ssSetOutputPortWidth(rts, 85, 1);
          ssSetOutputPortSignal(rts, 85, ((int8_T *) &CAN_new_B.sfcn_o86));
        }

        /* port 86 */
        {
          _ssSetOutputPortNumDimensions(rts, 86, 1);
          ssSetOutputPortWidth(rts, 86, 1);
          ssSetOutputPortSignal(rts, 86, ((int8_T *) &CAN_new_B.sfcn_o87));
        }

        /* port 87 */
        {
          _ssSetOutputPortNumDimensions(rts, 87, 1);
          ssSetOutputPortWidth(rts, 87, 1);
          ssSetOutputPortSignal(rts, 87, ((uint8_T *) &CAN_new_B.sfcn_o88));
        }

        /* port 88 */
        {
          _ssSetOutputPortNumDimensions(rts, 88, 1);
          ssSetOutputPortWidth(rts, 88, 1);
          ssSetOutputPortSignal(rts, 88, ((uint8_T *) &CAN_new_B.sfcn_o89));
        }

        /* port 89 */
        {
          _ssSetOutputPortNumDimensions(rts, 89, 1);
          ssSetOutputPortWidth(rts, 89, 1);
          ssSetOutputPortSignal(rts, 89, ((uint8_T *) &CAN_new_B.sfcn_o90));
        }

        /* port 90 */
        {
          _ssSetOutputPortNumDimensions(rts, 90, 1);
          ssSetOutputPortWidth(rts, 90, 1);
          ssSetOutputPortSignal(rts, 90, ((uint8_T *) &CAN_new_B.sfcn_o91));
        }

        /* port 91 */
        {
          _ssSetOutputPortNumDimensions(rts, 91, 1);
          ssSetOutputPortWidth(rts, 91, 1);
          ssSetOutputPortSignal(rts, 91, ((uint8_T *) &CAN_new_B.sfcn_o92));
        }

        /* port 92 */
        {
          _ssSetOutputPortNumDimensions(rts, 92, 1);
          ssSetOutputPortWidth(rts, 92, 1);
          ssSetOutputPortSignal(rts, 92, ((uint8_T *) &CAN_new_B.sfcn_o93));
        }

        /* port 93 */
        {
          _ssSetOutputPortNumDimensions(rts, 93, 1);
          ssSetOutputPortWidth(rts, 93, 1);
          ssSetOutputPortSignal(rts, 93, ((uint8_T *) &CAN_new_B.sfcn_o94));
        }

        /* port 94 */
        {
          _ssSetOutputPortNumDimensions(rts, 94, 1);
          ssSetOutputPortWidth(rts, 94, 1);
          ssSetOutputPortSignal(rts, 94, ((uint8_T *) &CAN_new_B.sfcn_o95));
        }

        /* port 95 */
        {
          _ssSetOutputPortNumDimensions(rts, 95, 1);
          ssSetOutputPortWidth(rts, 95, 1);
          ssSetOutputPortSignal(rts, 95, ((uint8_T *) &CAN_new_B.sfcn_o96));
        }

        /* port 96 */
        {
          _ssSetOutputPortNumDimensions(rts, 96, 1);
          ssSetOutputPortWidth(rts, 96, 1);
          ssSetOutputPortSignal(rts, 96, ((uint8_T *) &CAN_new_B.sfcn_o97));
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "CAN_new/ETS_CAN1/RTICANMM MainBlock/sfcn");
      ssSetRTModel(rts,CAN_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &CAN_new_DW.sfcn_RWORK_k);
      ssSetPWork(rts, (void **) &CAN_new_DW.sfcn_PWORK_i[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CAN_new_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CAN_new_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CAN_new_DW.sfcn_RWORK_k);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 16);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &CAN_new_DW.sfcn_PWORK_i[0]);
      }

      /* registration */
      RTICANMM_MAIN_CAN_2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 1);
      _ssSetOutputPortConnected(rts, 12, 1);
      _ssSetOutputPortConnected(rts, 13, 1);
      _ssSetOutputPortConnected(rts, 14, 1);
      _ssSetOutputPortConnected(rts, 15, 1);
      _ssSetOutputPortConnected(rts, 16, 1);
      _ssSetOutputPortConnected(rts, 17, 1);
      _ssSetOutputPortConnected(rts, 18, 1);
      _ssSetOutputPortConnected(rts, 19, 1);
      _ssSetOutputPortConnected(rts, 20, 1);
      _ssSetOutputPortConnected(rts, 21, 1);
      _ssSetOutputPortConnected(rts, 22, 1);
      _ssSetOutputPortConnected(rts, 23, 1);
      _ssSetOutputPortConnected(rts, 24, 1);
      _ssSetOutputPortConnected(rts, 25, 1);
      _ssSetOutputPortConnected(rts, 26, 1);
      _ssSetOutputPortConnected(rts, 27, 1);
      _ssSetOutputPortConnected(rts, 28, 1);
      _ssSetOutputPortConnected(rts, 29, 1);
      _ssSetOutputPortConnected(rts, 30, 1);
      _ssSetOutputPortConnected(rts, 31, 1);
      _ssSetOutputPortConnected(rts, 32, 1);
      _ssSetOutputPortConnected(rts, 33, 1);
      _ssSetOutputPortConnected(rts, 34, 1);
      _ssSetOutputPortConnected(rts, 35, 1);
      _ssSetOutputPortConnected(rts, 36, 1);
      _ssSetOutputPortConnected(rts, 37, 1);
      _ssSetOutputPortConnected(rts, 38, 1);
      _ssSetOutputPortConnected(rts, 39, 1);
      _ssSetOutputPortConnected(rts, 40, 1);
      _ssSetOutputPortConnected(rts, 41, 1);
      _ssSetOutputPortConnected(rts, 42, 1);
      _ssSetOutputPortConnected(rts, 43, 1);
      _ssSetOutputPortConnected(rts, 44, 1);
      _ssSetOutputPortConnected(rts, 45, 1);
      _ssSetOutputPortConnected(rts, 46, 1);
      _ssSetOutputPortConnected(rts, 47, 1);
      _ssSetOutputPortConnected(rts, 48, 1);
      _ssSetOutputPortConnected(rts, 49, 1);
      _ssSetOutputPortConnected(rts, 50, 1);
      _ssSetOutputPortConnected(rts, 51, 1);
      _ssSetOutputPortConnected(rts, 52, 1);
      _ssSetOutputPortConnected(rts, 53, 1);
      _ssSetOutputPortConnected(rts, 54, 1);
      _ssSetOutputPortConnected(rts, 55, 1);
      _ssSetOutputPortConnected(rts, 56, 1);
      _ssSetOutputPortConnected(rts, 57, 1);
      _ssSetOutputPortConnected(rts, 58, 1);
      _ssSetOutputPortConnected(rts, 59, 1);
      _ssSetOutputPortConnected(rts, 60, 1);
      _ssSetOutputPortConnected(rts, 61, 1);
      _ssSetOutputPortConnected(rts, 62, 1);
      _ssSetOutputPortConnected(rts, 63, 1);
      _ssSetOutputPortConnected(rts, 64, 1);
      _ssSetOutputPortConnected(rts, 65, 1);
      _ssSetOutputPortConnected(rts, 66, 1);
      _ssSetOutputPortConnected(rts, 67, 1);
      _ssSetOutputPortConnected(rts, 68, 1);
      _ssSetOutputPortConnected(rts, 69, 1);
      _ssSetOutputPortConnected(rts, 70, 1);
      _ssSetOutputPortConnected(rts, 71, 1);
      _ssSetOutputPortConnected(rts, 72, 1);
      _ssSetOutputPortConnected(rts, 73, 1);
      _ssSetOutputPortConnected(rts, 74, 1);
      _ssSetOutputPortConnected(rts, 75, 1);
      _ssSetOutputPortConnected(rts, 76, 1);
      _ssSetOutputPortConnected(rts, 77, 1);
      _ssSetOutputPortConnected(rts, 78, 1);
      _ssSetOutputPortConnected(rts, 79, 1);
      _ssSetOutputPortConnected(rts, 80, 1);
      _ssSetOutputPortConnected(rts, 81, 1);
      _ssSetOutputPortConnected(rts, 82, 1);
      _ssSetOutputPortConnected(rts, 83, 1);
      _ssSetOutputPortConnected(rts, 84, 1);
      _ssSetOutputPortConnected(rts, 85, 1);
      _ssSetOutputPortConnected(rts, 86, 1);
      _ssSetOutputPortConnected(rts, 87, 1);
      _ssSetOutputPortConnected(rts, 88, 1);
      _ssSetOutputPortConnected(rts, 89, 1);
      _ssSetOutputPortConnected(rts, 90, 1);
      _ssSetOutputPortConnected(rts, 91, 1);
      _ssSetOutputPortConnected(rts, 92, 1);
      _ssSetOutputPortConnected(rts, 93, 1);
      _ssSetOutputPortConnected(rts, 94, 1);
      _ssSetOutputPortConnected(rts, 95, 1);
      _ssSetOutputPortConnected(rts, 96, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);
      _ssSetOutputPortBeingMerged(rts, 12, 0);
      _ssSetOutputPortBeingMerged(rts, 13, 0);
      _ssSetOutputPortBeingMerged(rts, 14, 0);
      _ssSetOutputPortBeingMerged(rts, 15, 0);
      _ssSetOutputPortBeingMerged(rts, 16, 0);
      _ssSetOutputPortBeingMerged(rts, 17, 0);
      _ssSetOutputPortBeingMerged(rts, 18, 0);
      _ssSetOutputPortBeingMerged(rts, 19, 0);
      _ssSetOutputPortBeingMerged(rts, 20, 0);
      _ssSetOutputPortBeingMerged(rts, 21, 0);
      _ssSetOutputPortBeingMerged(rts, 22, 0);
      _ssSetOutputPortBeingMerged(rts, 23, 0);
      _ssSetOutputPortBeingMerged(rts, 24, 0);
      _ssSetOutputPortBeingMerged(rts, 25, 0);
      _ssSetOutputPortBeingMerged(rts, 26, 0);
      _ssSetOutputPortBeingMerged(rts, 27, 0);
      _ssSetOutputPortBeingMerged(rts, 28, 0);
      _ssSetOutputPortBeingMerged(rts, 29, 0);
      _ssSetOutputPortBeingMerged(rts, 30, 0);
      _ssSetOutputPortBeingMerged(rts, 31, 0);
      _ssSetOutputPortBeingMerged(rts, 32, 0);
      _ssSetOutputPortBeingMerged(rts, 33, 0);
      _ssSetOutputPortBeingMerged(rts, 34, 0);
      _ssSetOutputPortBeingMerged(rts, 35, 0);
      _ssSetOutputPortBeingMerged(rts, 36, 0);
      _ssSetOutputPortBeingMerged(rts, 37, 0);
      _ssSetOutputPortBeingMerged(rts, 38, 0);
      _ssSetOutputPortBeingMerged(rts, 39, 0);
      _ssSetOutputPortBeingMerged(rts, 40, 0);
      _ssSetOutputPortBeingMerged(rts, 41, 0);
      _ssSetOutputPortBeingMerged(rts, 42, 0);
      _ssSetOutputPortBeingMerged(rts, 43, 0);
      _ssSetOutputPortBeingMerged(rts, 44, 0);
      _ssSetOutputPortBeingMerged(rts, 45, 0);
      _ssSetOutputPortBeingMerged(rts, 46, 0);
      _ssSetOutputPortBeingMerged(rts, 47, 0);
      _ssSetOutputPortBeingMerged(rts, 48, 0);
      _ssSetOutputPortBeingMerged(rts, 49, 0);
      _ssSetOutputPortBeingMerged(rts, 50, 0);
      _ssSetOutputPortBeingMerged(rts, 51, 0);
      _ssSetOutputPortBeingMerged(rts, 52, 0);
      _ssSetOutputPortBeingMerged(rts, 53, 0);
      _ssSetOutputPortBeingMerged(rts, 54, 0);
      _ssSetOutputPortBeingMerged(rts, 55, 0);
      _ssSetOutputPortBeingMerged(rts, 56, 0);
      _ssSetOutputPortBeingMerged(rts, 57, 0);
      _ssSetOutputPortBeingMerged(rts, 58, 0);
      _ssSetOutputPortBeingMerged(rts, 59, 0);
      _ssSetOutputPortBeingMerged(rts, 60, 0);
      _ssSetOutputPortBeingMerged(rts, 61, 0);
      _ssSetOutputPortBeingMerged(rts, 62, 0);
      _ssSetOutputPortBeingMerged(rts, 63, 0);
      _ssSetOutputPortBeingMerged(rts, 64, 0);
      _ssSetOutputPortBeingMerged(rts, 65, 0);
      _ssSetOutputPortBeingMerged(rts, 66, 0);
      _ssSetOutputPortBeingMerged(rts, 67, 0);
      _ssSetOutputPortBeingMerged(rts, 68, 0);
      _ssSetOutputPortBeingMerged(rts, 69, 0);
      _ssSetOutputPortBeingMerged(rts, 70, 0);
      _ssSetOutputPortBeingMerged(rts, 71, 0);
      _ssSetOutputPortBeingMerged(rts, 72, 0);
      _ssSetOutputPortBeingMerged(rts, 73, 0);
      _ssSetOutputPortBeingMerged(rts, 74, 0);
      _ssSetOutputPortBeingMerged(rts, 75, 0);
      _ssSetOutputPortBeingMerged(rts, 76, 0);
      _ssSetOutputPortBeingMerged(rts, 77, 0);
      _ssSetOutputPortBeingMerged(rts, 78, 0);
      _ssSetOutputPortBeingMerged(rts, 79, 0);
      _ssSetOutputPortBeingMerged(rts, 80, 0);
      _ssSetOutputPortBeingMerged(rts, 81, 0);
      _ssSetOutputPortBeingMerged(rts, 82, 0);
      _ssSetOutputPortBeingMerged(rts, 83, 0);
      _ssSetOutputPortBeingMerged(rts, 84, 0);
      _ssSetOutputPortBeingMerged(rts, 85, 0);
      _ssSetOutputPortBeingMerged(rts, 86, 0);
      _ssSetOutputPortBeingMerged(rts, 87, 0);
      _ssSetOutputPortBeingMerged(rts, 88, 0);
      _ssSetOutputPortBeingMerged(rts, 89, 0);
      _ssSetOutputPortBeingMerged(rts, 90, 0);
      _ssSetOutputPortBeingMerged(rts, 91, 0);
      _ssSetOutputPortBeingMerged(rts, 92, 0);
      _ssSetOutputPortBeingMerged(rts, 93, 0);
      _ssSetOutputPortBeingMerged(rts, 94, 0);
      _ssSetOutputPortBeingMerged(rts, 95, 0);
      _ssSetOutputPortBeingMerged(rts, 96, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CAN_new/<S19>/sfcn (RTICANMM_SETUP_Controller2) */
    {
      SimStruct *rts = CAN_new_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = CAN_new_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = CAN_new_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = CAN_new_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CAN_new_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, CAN_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CAN_new_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CAN_new_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CAN_new_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &CAN_new_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &CAN_new_B.Variation_DTC_h);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1,
                               &CAN_new_P.ResetRTICANMMControllerSetup__k);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "CAN_new/ETS_CAN1/RTICANMM ControllerSetup/sfcn");
      ssSetRTModel(rts,CAN_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      RTICANMM_SETUP_Controller2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  CAN_new_M->Sizes.numContStates = (0);/* Number of continuous states */
  CAN_new_M->Sizes.numY = (0);         /* Number of model outputs */
  CAN_new_M->Sizes.numU = (0);         /* Number of model inputs */
  CAN_new_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CAN_new_M->Sizes.numSampTimes = (1); /* Number of sample times */
  CAN_new_M->Sizes.numBlocks = (41);   /* Number of blocks */
  CAN_new_M->Sizes.numBlockIO = (133); /* Number of block outputs */
  CAN_new_M->Sizes.numBlockPrms = (49);/* Sum of parameter "widths" */
  return CAN_new_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
