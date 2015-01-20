  /*********************** dSPACE target specific file *************************

   Header file CAN_Communication_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 7.2 (02-May-2014)
   Tue Jan 13 20:02:23 2015

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_CAN_Communication_trc_ptr_h_
  #define RTI_HEADER_CAN_Communication_trc_ptr_h_
  /* Include the model header file. */
  #include "CAN_Communication.h"
  #include "CAN_Communication_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_0_CAN_Communication_real_T_0;
              EXTERN_C volatile  int16_T *p_0_CAN_Communication_int16_T_1;
              EXTERN_C volatile  uint8_T *p_0_CAN_Communication_uint8_T_2;
              EXTERN_C volatile  real_T *p_1_CAN_Communication_real_T_0;
              EXTERN_C volatile  uint16_T *p_1_CAN_Communication_uint16_T_1;
              EXTERN_C volatile  uint8_T *p_1_CAN_Communication_uint8_T_2;
              EXTERN_C volatile  boolean_T *p_1_CAN_Communication_boolean_T_3;
              EXTERN_C volatile  real_T *p_2_CAN_Communication_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_0_CAN_Communication_real_T_0 = &CAN_Communication_B.sfcn_o3;\
              p_0_CAN_Communication_int16_T_1 = &CAN_Communication_B.sfcn_o4;\
              p_0_CAN_Communication_uint8_T_2 = &CAN_Communication_B.Variation_DTC;\
              p_1_CAN_Communication_real_T_0 = &CAN_Communication_P.RTICANMMCHANNEL_TLC_P1;\
              p_1_CAN_Communication_uint16_T_1 = &CAN_Communication_P.RTICANMMCHANNEL_TLC_P6[0];\
              p_1_CAN_Communication_uint8_T_2 = &CAN_Communication_P.VariationRTICANMMControllerSetu;\
              p_1_CAN_Communication_boolean_T_3 = &CAN_Communication_P.ResetRTICANMMControllerSetup_Va;\
              p_2_CAN_Communication_real_T_0 = &CAN_Communication_DW.sfcn_RWORK;\

   #endif                       /* RTI_HEADER_CAN_Communication_trc_ptr_h_ */
