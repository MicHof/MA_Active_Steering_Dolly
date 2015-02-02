/*
 * demo_simplemodel.c
 *
 * Code generation for model "demo_simplemodel".
 *
 * Model version              : 1.222
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Mon Jan 26 11:44:09 2015
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "demo_simplemodel_trc_ptr.h"
#include "demo_simplemodel.h"
#include "demo_simplemodel_private.h"

/* Block signals (auto storage) */
B_demo_simplemodel_T demo_simplemodel_B;

/* Block states (auto storage) */
DW_demo_simplemodel_T demo_simplemodel_DW;

/* Real-time model */
RT_MODEL_demo_simplemodel_T demo_simplemodel_M_;
RT_MODEL_demo_simplemodel_T *const demo_simplemodel_M = &demo_simplemodel_M_;

/* Model output function */
static void demo_simplemodel_output(void)
{
  /* DataTypeConversion: '<S2>/Variation_DTC' incorporates:
   *  Constant: '<Root>/Variation'
   */
  demo_simplemodel_B.s2_Variation_DTC = demo_simplemodel_P.root_Variation_Value;

  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_CAN_Controller_1) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
static void demo_simplemodel_update(void)
{
  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_CAN_Controller_1) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[0];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[1];
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
  if (!(++demo_simplemodel_M->Timing.clockTick0)) {
    ++demo_simplemodel_M->Timing.clockTickH0;
  }

  demo_simplemodel_M->Timing.t[0] = demo_simplemodel_M->Timing.clockTick0 *
    demo_simplemodel_M->Timing.stepSize0 +
    demo_simplemodel_M->Timing.clockTickH0 *
    demo_simplemodel_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void demo_simplemodel_initialize(void)
{
  /* user code (Start function Body) */
  {
    /* Initialize host service for CAN monitoring */
    ts_timestamp_type ts = { 0, 0 };

    host_service(31, &ts);
  }

  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_CAN_Controller_1) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_CAN_Controller_1) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void demo_simplemodel_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/sfcn' (RTICANMM_SETUP_CAN_Controller_1) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = demo_simplemodel_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  demo_simplemodel_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  demo_simplemodel_update();
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
  demo_simplemodel_initialize();
}

void MdlTerminate(void)
{
  demo_simplemodel_terminate();
}

/* Registration function */
RT_MODEL_demo_simplemodel_T *demo_simplemodel(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)demo_simplemodel_M, 0,
                sizeof(RT_MODEL_demo_simplemodel_T));
  rtsiSetSolverName(&demo_simplemodel_M->solverInfo,"FixedStepDiscrete");
  demo_simplemodel_M->solverInfoPtr = (&demo_simplemodel_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = demo_simplemodel_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    demo_simplemodel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    demo_simplemodel_M->Timing.sampleTimes =
      (&demo_simplemodel_M->Timing.sampleTimesArray[0]);
    demo_simplemodel_M->Timing.offsetTimes =
      (&demo_simplemodel_M->Timing.offsetTimesArray[0]);

    /* task periods */
    demo_simplemodel_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    demo_simplemodel_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(demo_simplemodel_M, &demo_simplemodel_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = demo_simplemodel_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    demo_simplemodel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(demo_simplemodel_M, -1);
  demo_simplemodel_M->Timing.stepSize0 = 0.001;
  demo_simplemodel_M->solverInfoPtr = (&demo_simplemodel_M->solverInfo);
  demo_simplemodel_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&demo_simplemodel_M->solverInfo, 0.001);
  rtsiSetSolverMode(&demo_simplemodel_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  demo_simplemodel_M->ModelData.blockIO = ((void *) &demo_simplemodel_B);
  (void) memset(((void *) &demo_simplemodel_B), 0,
                sizeof(B_demo_simplemodel_T));

  /* parameters */
  demo_simplemodel_M->ModelData.defaultParam = ((real_T *)&demo_simplemodel_P);

  /* states (dwork) */
  demo_simplemodel_M->ModelData.dwork = ((void *) &demo_simplemodel_DW);
  (void) memset((void *)&demo_simplemodel_DW, 0,
                sizeof(DW_demo_simplemodel_T));
  demo_simplemodel_DW.s4_sfcn_RWORK = 0.0;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &demo_simplemodel_M->NonInlinedSFcns.sfcnInfo;
    demo_simplemodel_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(demo_simplemodel_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &demo_simplemodel_M->Sizes.numSampTimes);
    demo_simplemodel_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (demo_simplemodel_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,demo_simplemodel_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(demo_simplemodel_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(demo_simplemodel_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (demo_simplemodel_M));
    rtssSetStepSizePtr(sfcnInfo, &demo_simplemodel_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(demo_simplemodel_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &demo_simplemodel_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &demo_simplemodel_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &demo_simplemodel_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &demo_simplemodel_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &demo_simplemodel_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &demo_simplemodel_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &demo_simplemodel_M->solverInfoPtr);
  }

  demo_simplemodel_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&demo_simplemodel_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    demo_simplemodel_M->childSfunctions =
      (&demo_simplemodel_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    demo_simplemodel_M->childSfunctions[0] =
      (&demo_simplemodel_M->NonInlinedSFcns.childSFunctions[0]);
    demo_simplemodel_M->childSfunctions[1] =
      (&demo_simplemodel_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: demo_simplemodel/<S2>/sfcn (RTICANMM_SETUP_CAN_Controller_1) */
    {
      SimStruct *rts = demo_simplemodel_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = demo_simplemodel_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = demo_simplemodel_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = demo_simplemodel_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &demo_simplemodel_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, demo_simplemodel_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &demo_simplemodel_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &demo_simplemodel_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &demo_simplemodel_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &demo_simplemodel_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &demo_simplemodel_B.s2_Variation_DTC);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &demo_simplemodel_P.root_Reset_Value);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "demo_simplemodel/RTICANMM ControllerSetup/sfcn");
      ssSetRTModel(rts,demo_simplemodel_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      RTICANMM_SETUP_CAN_Controller_1(rts);
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

    /* Level2 S-Function Block: demo_simplemodel/<S4>/sfcn (RTICANMM_MAIN_CAN) */
    {
      SimStruct *rts = demo_simplemodel_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = demo_simplemodel_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = demo_simplemodel_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = demo_simplemodel_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &demo_simplemodel_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, demo_simplemodel_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &demo_simplemodel_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &demo_simplemodel_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &demo_simplemodel_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "demo_simplemodel/RTICANMM MainBlock/sfcn");
      ssSetRTModel(rts,demo_simplemodel_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &demo_simplemodel_DW.s4_sfcn_RWORK);
      ssSetPWork(rts, (void **) &demo_simplemodel_DW.s4_sfcn_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &demo_simplemodel_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &demo_simplemodel_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &demo_simplemodel_DW.s4_sfcn_RWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 16);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &demo_simplemodel_DW.s4_sfcn_PWORK[0]);
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
      /* Update the BufferDstPort flags for each input port */
    }
  }

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  demo_simplemodel_M->Sizes.numContStates = (0);/* Number of continuous states */
  demo_simplemodel_M->Sizes.numY = (0);/* Number of model outputs */
  demo_simplemodel_M->Sizes.numU = (0);/* Number of model inputs */
  demo_simplemodel_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  demo_simplemodel_M->Sizes.numSampTimes = (1);/* Number of sample times */
  demo_simplemodel_M->Sizes.numBlocks = (8);/* Number of blocks */
  demo_simplemodel_M->Sizes.numBlockIO = (1);/* Number of block outputs */
  demo_simplemodel_M->Sizes.numBlockPrms = (13);/* Sum of parameter "widths" */
  return demo_simplemodel_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
