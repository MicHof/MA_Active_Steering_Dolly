/*
 * CAN_new.h
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
#ifndef RTW_HEADER_CAN_new_h_
#define RTW_HEADER_CAN_new_h_
#ifndef CAN_new_COMMON_INCLUDES_
# define CAN_new_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <CAN1401Tp1.h>
#include <dsts.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "multiword_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif                                 /* CAN_new_COMMON_INCLUDES_ */

#include "CAN_new_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define CAN_new_rtModel                RT_MODEL_CAN_new_T

/* Block signals (auto storage) */
typedef struct {
  real_T sfcn_o3;                      /* '<S7>/sfcn' */
  real_T sfcn_o12;                     /* '<S7>/sfcn' */
  real_T sfcn_o14;                     /* '<S7>/sfcn' */
  real_T Constant;                     /* '<S6>/Constant' */
  real_T sfcn_o1;                      /* '<S13>/sfcn' */
  real_T sfcn_o2;                      /* '<S13>/sfcn' */
  real_T sfcn_o3_n;                    /* '<S13>/sfcn' */
  real_T sfcn_o4;                      /* '<S13>/sfcn' */
  real_T sfcn_o5;                      /* '<S13>/sfcn' */
  real_T sfcn_o6;                      /* '<S13>/sfcn' */
  real_T sfcn_o7;                      /* '<S13>/sfcn' */
  real_T sfcn_o8;                      /* '<S13>/sfcn' */
  real_T sfcn_o9;                      /* '<S13>/sfcn' */
  real_T sfcn_o10;                     /* '<S13>/sfcn' */
  real_T sfcn_o11;                     /* '<S13>/sfcn' */
  real_T sfcn_o12_m;                   /* '<S13>/sfcn' */
  real_T sfcn_o13;                     /* '<S13>/sfcn' */
  real_T sfcn_o14_a;                   /* '<S13>/sfcn' */
  real_T sfcn_o15;                     /* '<S13>/sfcn' */
  real_T sfcn_o16;                     /* '<S13>/sfcn' */
  real_T sfcn_o30;                     /* '<S13>/sfcn' */
  real_T sfcn_o31;                     /* '<S13>/sfcn' */
  real_T sfcn_o32;                     /* '<S13>/sfcn' */
  real_T sfcn_o33;                     /* '<S13>/sfcn' */
  real_T sfcn_o34;                     /* '<S13>/sfcn' */
  real_T sfcn_o35;                     /* '<S13>/sfcn' */
  real_T sfcn_o36;                     /* '<S13>/sfcn' */
  real_T sfcn_o41;                     /* '<S13>/sfcn' */
  real_T sfcn_o42;                     /* '<S13>/sfcn' */
  real_T sfcn_o46;                     /* '<S13>/sfcn' */
  real_T sfcn_o59;                     /* '<S13>/sfcn' */
  real_T sfcn_o63;                     /* '<S13>/sfcn' */
  real_T sfcn_o67;                     /* '<S13>/sfcn' */
  real_T sfcn_o68;                     /* '<S13>/sfcn' */
  real_T sfcn_o69;                     /* '<S13>/sfcn' */
  real_T sfcn_o70;                     /* '<S13>/sfcn' */
  real_T sfcn_o71;                     /* '<S13>/sfcn' */
  real_T sfcn_o72;                     /* '<S13>/sfcn' */
  real_T sfcn_o73;                     /* '<S13>/sfcn' */
  real_T sfcn_o74;                     /* '<S13>/sfcn' */
  real_T sfcn_o75;                     /* '<S13>/sfcn' */
  real_T sfcn_o76;                     /* '<S13>/sfcn' */
  real_T sfcn_o77;                     /* '<S13>/sfcn' */
  real_T sfcn_o78;                     /* '<S13>/sfcn' */
  real_T sfcn_o79;                     /* '<S13>/sfcn' */
  real_T sfcn_o80;                     /* '<S13>/sfcn' */
  real_T sfcn_o81;                     /* '<S13>/sfcn' */
  real_T sfcn_o82;                     /* '<S13>/sfcn' */
  int16_T sfcn_o4_g;                   /* '<S7>/sfcn' */
  int16_T sfcn_o13_o;                  /* '<S7>/sfcn' */
  int16_T sfcn_o37;                    /* '<S13>/sfcn' */
  int16_T sfcn_o38;                    /* '<S13>/sfcn' */
  int16_T sfcn_o43;                    /* '<S13>/sfcn' */
  uint16_T sfcn_o45;                   /* '<S13>/sfcn' */
  int8_T sfcn_o85;                     /* '<S13>/sfcn' */
  int8_T sfcn_o86;                     /* '<S13>/sfcn' */
  int8_T sfcn_o87;                     /* '<S13>/sfcn' */
  uint8_T sfcn_o1_f;                   /* '<S7>/sfcn' */
  uint8_T sfcn_o2_j;                   /* '<S7>/sfcn' */
  uint8_T sfcn_o5_a;                   /* '<S7>/sfcn' */
  uint8_T sfcn_o6_b;                   /* '<S7>/sfcn' */
  uint8_T sfcn_o7_a;                   /* '<S7>/sfcn' */
  uint8_T sfcn_o8_g;                   /* '<S7>/sfcn' */
  uint8_T sfcn_o9_g;                   /* '<S7>/sfcn' */
  uint8_T sfcn_o10_j;                  /* '<S7>/sfcn' */
  uint8_T sfcn_o11_p;                  /* '<S7>/sfcn' */
  uint8_T Variation_DTC;               /* '<S5>/Variation_DTC' */
  uint8_T sfcn;                        /* '<S10>/sfcn' */
  uint8_T Variation_DTC_g;             /* '<S9>/Variation_DTC' */
  uint8_T Variation_DTC_h;             /* '<S12>/Variation_DTC' */
  uint8_T sfcn_o17;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o18;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o19;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o20;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o21;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o22;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o23;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o24;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o25;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o26;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o27;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o28;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o29;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o39;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o40;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o44;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o51;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o52;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o53;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o54;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o55;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o56;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o58;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o60;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o61;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o62;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o64;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o65;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o66;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o83;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o84;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o88;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o89;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o90;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o91;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o92;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o93;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o94;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o95;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o96;                    /* '<S13>/sfcn' */
  uint8_T sfcn_o97;                    /* '<S13>/sfcn' */
  boolean_T sfcn_o47;                  /* '<S13>/sfcn' */
  boolean_T sfcn_o48;                  /* '<S13>/sfcn' */
  boolean_T sfcn_o49;                  /* '<S13>/sfcn' */
  boolean_T sfcn_o50;                  /* '<S13>/sfcn' */
  boolean_T sfcn_o57;                  /* '<S13>/sfcn' */
} B_CAN_new_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T sfcn_RWORK;                   /* '<S7>/sfcn' */
  real_T sfcn_RWORK_c;                 /* '<S10>/sfcn' */
  real_T sfcn_RWORK_k;                 /* '<S13>/sfcn' */
  void *sfcn_PWORK[16];                /* '<S7>/sfcn' */
  void *sfcn_PWORK_a[16];              /* '<S10>/sfcn' */
  void *sfcn_PWORK_i[16];              /* '<S13>/sfcn' */
} DW_CAN_new_T;

/* Backward compatible GRT Identifiers */
#define rtB                            CAN_new_B
#define BlockIO                        B_CAN_new_T
#define rtP                            CAN_new_P
#define Parameters                     P_CAN_new_T
#define rtDWork                        CAN_new_DW
#define D_Work                         DW_CAN_new_T

/* Parameters (auto storage) */
struct P_CAN_new_T_ {
  real_T RTICANMMCHANNEL_TLC_P1;       /* Expression: 1401
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P2;       /* Expression: 1
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P3;       /* Expression: 1
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P4;       /* Expression: 0
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P5;       /* Expression: 500
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T RTICANMMCHANNEL_TLC_P1_k;     /* Expression: 1401
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P2_k;     /* Expression: 2
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P3_b;     /* Expression: 1
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P4_b;     /* Expression: 0
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P5_p;     /* Expression: 500
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P1_n;     /* Expression: 1401
                                        * Referenced by: '<S12>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P2_o;     /* Expression: 1
                                        * Referenced by: '<S12>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P3_n;     /* Expression: 2
                                        * Referenced by: '<S12>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P4_bc;    /* Expression: 0
                                        * Referenced by: '<S12>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P5_k;     /* Expression: 500
                                        * Referenced by: '<S12>/RTICANMMCHANNEL_TLC'
                                        */
  uint16_T RTICANMMCHANNEL_TLC_P6[6];  /* Computed Parameter: RTICANMMCHANNEL_TLC_P6
                                        * Referenced by: '<S5>/RTICANMMCHANNEL_TLC'
                                        */
  uint16_T RTICANMMCHANNEL_TLC_P6_n[6];/* Computed Parameter: RTICANMMCHANNEL_TLC_P6_n
                                        * Referenced by: '<S9>/RTICANMMCHANNEL_TLC'
                                        */
  uint16_T RTICANMMCHANNEL_TLC_P6_j[6];/* Computed Parameter: RTICANMMCHANNEL_TLC_P6_j
                                        * Referenced by: '<S12>/RTICANMMCHANNEL_TLC'
                                        */
  uint8_T VariationRTICANMMControllerSetu;/* Computed Parameter: VariationRTICANMMControllerSetu
                                           * Referenced by: '<S1>/Variation@RTICANMM ControllerSetup'
                                           */
  uint8_T VariationRTICANMMControllerSe_i;/* Computed Parameter: VariationRTICANMMControllerSe_i
                                           * Referenced by: '<S2>/Variation@RTICANMM ControllerSetup'
                                           */
  uint8_T VariationRTICANMMControllerSe_h;/* Computed Parameter: VariationRTICANMMControllerSe_h
                                           * Referenced by: '<S3>/Variation@RTICANMM ControllerSetup'
                                           */
  boolean_T ResetRTICANMMControllerSetup_Va;/* Computed Parameter: ResetRTICANMMControllerSetup_Va
                                             * Referenced by: '<S1>/Reset@RTICANMM ControllerSetup'
                                             */
  boolean_T ResetRTICANMMControllerSetup__d;/* Computed Parameter: ResetRTICANMMControllerSetup__d
                                             * Referenced by: '<S2>/Reset@RTICANMM ControllerSetup'
                                             */
  boolean_T ResetRTICANMMControllerSetup__k;/* Computed Parameter: ResetRTICANMMControllerSetup__k
                                             * Referenced by: '<S3>/Reset@RTICANMM ControllerSetup'
                                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_CAN_new_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[6];
    SimStruct *childSFunctionPtrs[6];
    struct _ssBlkInfo2 blkInfo2[6];
    struct _ssSFcnModelMethods2 methods2[6];
    struct _ssSFcnModelMethods3 methods3[6];
    struct _ssStatesInfo2 statesInfo2[6];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[14];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[97];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn5;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_CAN_new_T CAN_new_P;

/* Block signals (auto storage) */
extern B_CAN_new_T CAN_new_B;

/* Block states (auto storage) */
extern DW_CAN_new_T CAN_new_DW;

/* Real-time Model object */
extern RT_MODEL_CAN_new_T *const CAN_new_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CAN_new'
 * '<S1>'   : 'CAN_new/Angle_Sensor'
 * '<S2>'   : 'CAN_new/Arduino'
 * '<S3>'   : 'CAN_new/ETS_CAN1'
 * '<S4>'   : 'CAN_new/RTI Data'
 * '<S5>'   : 'CAN_new/Angle_Sensor/RTICANMM ControllerSetup'
 * '<S6>'   : 'CAN_new/Angle_Sensor/RTICANMM GeneralSetup'
 * '<S7>'   : 'CAN_new/Angle_Sensor/RTICANMM MainBlock'
 * '<S8>'   : 'CAN_new/Angle_Sensor/RTICANMM MainBlock/converter'
 * '<S9>'   : 'CAN_new/Arduino/RTICANMM ControllerSetup'
 * '<S10>'  : 'CAN_new/Arduino/RTICANMM MainBlock'
 * '<S11>'  : 'CAN_new/Arduino/RTICANMM MainBlock/converter'
 * '<S12>'  : 'CAN_new/ETS_CAN1/RTICANMM ControllerSetup'
 * '<S13>'  : 'CAN_new/ETS_CAN1/RTICANMM MainBlock'
 * '<S14>'  : 'CAN_new/ETS_CAN1/RTICANMM MainBlock/converter'
 * '<S15>'  : 'CAN_new/RTI Data/RTI Data Store'
 * '<S16>'  : 'CAN_new/RTI Data/RTI Data Store/RTI Data Store'
 * '<S17>'  : 'CAN_new/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_CAN_new_h_ */
