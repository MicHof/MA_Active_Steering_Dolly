/*
 * CAN_Communication.c
 *
 * Code generation for model "CAN_Communication".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Jan 13 20:02:23 2015
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "CAN_Communication_trc_ptr.h"
#include "CAN_Communication.h"
#include "CAN_Communication_private.h"

const real_T CAN_Communication_RGND = 0.0;/* real_T ground */
const uint8_T CAN_Communication_U8GND = 0U;/* uint8_T ground */
const int16_T CAN_Communication_I16GND = 0;/* int16_T ground */

/* Block signals (auto storage) */
B_CAN_Communication_T CAN_Communication_B;

/* Block states (auto storage) */
DW_CAN_Communication_T CAN_Communication_DW;

/* Real-time model */
RT_MODEL_CAN_Communication_T CAN_Communication_M_;
RT_MODEL_CAN_Communication_T *const CAN_Communication_M = &CAN_Communication_M_;

/* Model output function */
static void CAN_Communication_output(void)
{
  /* DataTypeConversion: '<S2>/Variation_DTC' incorporates:
   *  Constant: '<Root>/Variation@RTICANMM ControllerSetup'
   */
  CAN_Communication_B.Variation_DTC =
    CAN_Communication_P.VariationRTICANMMControllerSetu;

  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S3>/Constant' */
  CAN_Communication_B.Constant = CAN_Communication_P.Constant_Value;
}

/* Model update function */
static void CAN_Communication_update(void)
{
  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[0];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[1];
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
  if (!(++CAN_Communication_M->Timing.clockTick0)) {
    ++CAN_Communication_M->Timing.clockTickH0;
  }

  CAN_Communication_M->Timing.t[0] = CAN_Communication_M->Timing.clockTick0 *
    CAN_Communication_M->Timing.stepSize0 +
    CAN_Communication_M->Timing.clockTickH0 *
    CAN_Communication_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void CAN_Communication_initialize(void)
{
  /* user code (Start function Body) */
  {
    /* Initialize host service for CAN monitoring */
    ts_timestamp_type ts = { 0, 0 };

    host_service(31, &ts);
  }

  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void CAN_Communication_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_Controller1) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = CAN_Communication_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  CAN_Communication_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  CAN_Communication_update();
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
  CAN_Communication_initialize();
}

void MdlTerminate(void)
{
  CAN_Communication_terminate();
}

/* Registration function */
RT_MODEL_CAN_Communication_T *CAN_Communication(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)CAN_Communication_M, 0,
                sizeof(RT_MODEL_CAN_Communication_T));
  rtsiSetSolverName(&CAN_Communication_M->solverInfo,"FixedStepDiscrete");
  CAN_Communication_M->solverInfoPtr = (&CAN_Communication_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CAN_Communication_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    CAN_Communication_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CAN_Communication_M->Timing.sampleTimes =
      (&CAN_Communication_M->Timing.sampleTimesArray[0]);
    CAN_Communication_M->Timing.offsetTimes =
      (&CAN_Communication_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CAN_Communication_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    CAN_Communication_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(CAN_Communication_M, &CAN_Communication_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = CAN_Communication_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    CAN_Communication_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CAN_Communication_M, -1);
  CAN_Communication_M->Timing.stepSize0 = 0.001;
  CAN_Communication_M->solverInfoPtr = (&CAN_Communication_M->solverInfo);
  CAN_Communication_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&CAN_Communication_M->solverInfo, 0.001);
  rtsiSetSolverMode(&CAN_Communication_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  CAN_Communication_M->ModelData.blockIO = ((void *) &CAN_Communication_B);
  (void) memset(((void *) &CAN_Communication_B), 0,
                sizeof(B_CAN_Communication_T));

  /* parameters */
  CAN_Communication_M->ModelData.defaultParam = ((real_T *)&CAN_Communication_P);

  /* states (dwork) */
  CAN_Communication_M->ModelData.dwork = ((void *) &CAN_Communication_DW);
  (void) memset((void *)&CAN_Communication_DW, 0,
                sizeof(DW_CAN_Communication_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &CAN_Communication_M->NonInlinedSFcns.sfcnInfo;
    CAN_Communication_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(CAN_Communication_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &CAN_Communication_M->Sizes.numSampTimes);
    CAN_Communication_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (CAN_Communication_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,CAN_Communication_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(CAN_Communication_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(CAN_Communication_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (CAN_Communication_M));
    rtssSetStepSizePtr(sfcnInfo, &CAN_Communication_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(CAN_Communication_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &CAN_Communication_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &CAN_Communication_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &CAN_Communication_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &CAN_Communication_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &CAN_Communication_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &CAN_Communication_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &CAN_Communication_M->solverInfoPtr);
  }

  CAN_Communication_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&CAN_Communication_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  2*sizeof(SimStruct));
    CAN_Communication_M->childSfunctions =
      (&CAN_Communication_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    CAN_Communication_M->childSfunctions[0] =
      (&CAN_Communication_M->NonInlinedSFcns.childSFunctions[0]);
    CAN_Communication_M->childSfunctions[1] =
      (&CAN_Communication_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: CAN_Communication/<S2>/sfcn (RTICANMM_SETUP_Controller1) */
    {
      SimStruct *rts = CAN_Communication_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = CAN_Communication_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = CAN_Communication_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = CAN_Communication_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CAN_Communication_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, CAN_Communication_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CAN_Communication_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CAN_Communication_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CAN_Communication_M->NonInlinedSFcns.statesInfo2
                         [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &CAN_Communication_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &CAN_Communication_B.Variation_DTC);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1,
                               &CAN_Communication_P.ResetRTICANMMControllerSetup_Va);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "CAN_Communication/RTICANMM ControllerSetup/sfcn");
      ssSetRTModel(rts,CAN_Communication_M);
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

    /* Level2 S-Function Block: CAN_Communication/<S4>/sfcn (RTICANMM_MAIN_CAN) */
    {
      SimStruct *rts = CAN_Communication_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = CAN_Communication_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = CAN_Communication_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = CAN_Communication_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CAN_Communication_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, CAN_Communication_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CAN_Communication_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CAN_Communication_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CAN_Communication_M->NonInlinedSFcns.statesInfo2
                         [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 14);
        ssSetPortInfoForInputs(rts,
          &CAN_Communication_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2, (real_T*)&CAN_Communication_RGND);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          ssSetInputPortRequiredContiguous(rts, 3, 1);
          ssSetInputPortSignal(rts, 3, (int16_T*)&CAN_Communication_I16GND);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          ssSetInputPortRequiredContiguous(rts, 4, 1);
          ssSetInputPortSignal(rts, 4, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          ssSetInputPortRequiredContiguous(rts, 5, 1);
          ssSetInputPortSignal(rts, 5, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          ssSetInputPortRequiredContiguous(rts, 6, 1);
          ssSetInputPortSignal(rts, 6, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          ssSetInputPortRequiredContiguous(rts, 7, 1);
          ssSetInputPortSignal(rts, 7, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }

        /* port 8 */
        {
          ssSetInputPortRequiredContiguous(rts, 8, 1);
          ssSetInputPortSignal(rts, 8, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 8, 1);
          ssSetInputPortWidth(rts, 8, 1);
        }

        /* port 9 */
        {
          ssSetInputPortRequiredContiguous(rts, 9, 1);
          ssSetInputPortSignal(rts, 9, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 9, 1);
          ssSetInputPortWidth(rts, 9, 1);
        }

        /* port 10 */
        {
          ssSetInputPortRequiredContiguous(rts, 10, 1);
          ssSetInputPortSignal(rts, 10, (uint8_T*)&CAN_Communication_U8GND);
          _ssSetInputPortNumDimensions(rts, 10, 1);
          ssSetInputPortWidth(rts, 10, 1);
        }

        /* port 11 */
        {
          ssSetInputPortRequiredContiguous(rts, 11, 1);
          ssSetInputPortSignal(rts, 11, (real_T*)&CAN_Communication_RGND);
          _ssSetInputPortNumDimensions(rts, 11, 1);
          ssSetInputPortWidth(rts, 11, 1);
        }

        /* port 12 */
        {
          ssSetInputPortRequiredContiguous(rts, 12, 1);
          ssSetInputPortSignal(rts, 12, (int16_T*)&CAN_Communication_I16GND);
          _ssSetInputPortNumDimensions(rts, 12, 1);
          ssSetInputPortWidth(rts, 12, 1);
        }

        /* port 13 */
        {
          ssSetInputPortRequiredContiguous(rts, 13, 1);
          ssSetInputPortSignal(rts, 13, (real_T*)&CAN_Communication_RGND);
          _ssSetInputPortNumDimensions(rts, 13, 1);
          ssSetInputPortWidth(rts, 13, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CAN_Communication_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 14);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            &CAN_Communication_B.sfcn_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            &CAN_Communication_B.sfcn_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &CAN_Communication_B.sfcn_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((int16_T *)
            &CAN_Communication_B.sfcn_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint8_T *)
            &CAN_Communication_B.sfcn_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint8_T *)
            &CAN_Communication_B.sfcn_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((uint8_T *)
            &CAN_Communication_B.sfcn_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((uint8_T *)
            &CAN_Communication_B.sfcn_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((uint8_T *)
            &CAN_Communication_B.sfcn_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((uint8_T *)
            &CAN_Communication_B.sfcn_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((uint8_T *)
            &CAN_Communication_B.sfcn_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *)
            &CAN_Communication_B.sfcn_o12));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((int16_T *)
            &CAN_Communication_B.sfcn_o13));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 1);
          ssSetOutputPortSignal(rts, 13, ((real_T *)
            &CAN_Communication_B.sfcn_o14));
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "CAN_Communication/RTICANMM MainBlock/sfcn");
      ssSetRTModel(rts,CAN_Communication_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &CAN_Communication_DW.sfcn_RWORK);
      ssSetPWork(rts, (void **) &CAN_Communication_DW.sfcn_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CAN_Communication_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CAN_Communication_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CAN_Communication_DW.sfcn_RWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 16);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &CAN_Communication_DW.sfcn_PWORK[0]);
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
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetInputPortConnected(rts, 6, 1);
      _ssSetInputPortConnected(rts, 7, 1);
      _ssSetInputPortConnected(rts, 8, 1);
      _ssSetInputPortConnected(rts, 9, 1);
      _ssSetInputPortConnected(rts, 10, 1);
      _ssSetInputPortConnected(rts, 11, 1);
      _ssSetInputPortConnected(rts, 12, 1);
      _ssSetInputPortConnected(rts, 13, 1);
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
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
      ssSetInputPortBufferDstPort(rts, 7, -1);
      ssSetInputPortBufferDstPort(rts, 8, -1);
      ssSetInputPortBufferDstPort(rts, 9, -1);
      ssSetInputPortBufferDstPort(rts, 10, -1);
      ssSetInputPortBufferDstPort(rts, 11, -1);
      ssSetInputPortBufferDstPort(rts, 12, -1);
      ssSetInputPortBufferDstPort(rts, 13, -1);
    }
  }

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  CAN_Communication_M->Sizes.numContStates = (0);/* Number of continuous states */
  CAN_Communication_M->Sizes.numY = (0);/* Number of model outputs */
  CAN_Communication_M->Sizes.numU = (0);/* Number of model inputs */
  CAN_Communication_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CAN_Communication_M->Sizes.numSampTimes = (1);/* Number of sample times */
  CAN_Communication_M->Sizes.numBlocks = (9);/* Number of blocks */
  CAN_Communication_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  CAN_Communication_M->Sizes.numBlockPrms = (14);/* Sum of parameter "widths" */
  return CAN_Communication_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
