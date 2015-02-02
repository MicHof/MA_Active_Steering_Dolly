  /*********************** dSPACE target specific file *************************

   Header file CAN_new_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 7.2 (02-May-2014)
   Tue Jan 27 15:24:17 2015

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_CAN_new_trc_ptr_h_
  #define RTI_HEADER_CAN_new_trc_ptr_h_
  /* Include the model header file. */
  #include "CAN_new.h"
  #include "CAN_new_private.h"

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
              EXTERN_C volatile  real_T *p_CAN_new_B_real_T_0;
              EXTERN_C volatile  int16_T *p_CAN_new_B_int16_T_1;
              EXTERN_C volatile  uint16_T *p_CAN_new_B_uint16_T_2;
              EXTERN_C volatile  int8_T *p_CAN_new_B_int8_T_3;
              EXTERN_C volatile  uint8_T *p_CAN_new_B_uint8_T_4;
              EXTERN_C volatile  boolean_T *p_CAN_new_B_boolean_T_5;
              EXTERN_C volatile  real_T *p_CAN_new_P_real_T_0;
              EXTERN_C volatile  uint16_T *p_CAN_new_P_uint16_T_1;
              EXTERN_C volatile  uint8_T *p_CAN_new_P_uint8_T_2;
              EXTERN_C volatile  boolean_T *p_CAN_new_P_boolean_T_3;
              EXTERN_C volatile  real_T *p_CAN_new_DW_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_CAN_new_B_real_T_0 = &CAN_new_B.sfcn_o3;\
              p_CAN_new_B_int16_T_1 = &CAN_new_B.sfcn_o4_g;\
              p_CAN_new_B_uint16_T_2 = &CAN_new_B.sfcn_o45;\
              p_CAN_new_B_int8_T_3 = &CAN_new_B.sfcn_o85;\
              p_CAN_new_B_uint8_T_4 = &CAN_new_B.sfcn_o1_f;\
              p_CAN_new_B_boolean_T_5 = &CAN_new_B.sfcn_o47;\
              p_CAN_new_P_real_T_0 = &CAN_new_P.RTICANMMCHANNEL_TLC_P1;\
              p_CAN_new_P_uint16_T_1 = &CAN_new_P.RTICANMMCHANNEL_TLC_P6[0];\
              p_CAN_new_P_uint8_T_2 = &CAN_new_P.VariationRTICANMMControllerSetu;\
              p_CAN_new_P_boolean_T_3 = &CAN_new_P.ResetRTICANMMControllerSetup_Va;\
              p_CAN_new_DW_real_T_0 = &CAN_new_DW.sfcn_RWORK;\

   #endif                       /* RTI_HEADER_CAN_new_trc_ptr_h_ */
