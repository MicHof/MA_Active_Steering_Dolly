  /*********************** dSPACE target specific file *************************

   Header file demo_simplemodel_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 7.2 (02-May-2014)
   Mon Jan 26 11:44:09 2015

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_demo_simplemodel_trc_ptr_h_
  #define RTI_HEADER_demo_simplemodel_trc_ptr_h_
  /* Include the model header file. */
  #include "demo_simplemodel.h"
  #include "demo_simplemodel_private.h"

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
              EXTERN_C volatile  uint8_T *p_demo_simplemodel_B_uint8_T_0;
              EXTERN_C volatile  real_T *p_demo_simplemodel_P_real_T_0;
              EXTERN_C volatile  uint16_T *p_demo_simplemodel_P_uint16_T_1;
              EXTERN_C volatile  uint8_T *p_demo_simplemodel_P_uint8_T_2;
              EXTERN_C volatile  boolean_T *p_demo_simplemodel_P_boolean_T_3;
              EXTERN_C volatile  real_T *p_demo_simplemodel_DW_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_demo_simplemodel_B_uint8_T_0 = &demo_simplemodel_B.s2_Variation_DTC;\
              p_demo_simplemodel_P_real_T_0 = &demo_simplemodel_P.s2_RTICANMMCHANNEL_TLC_P1;\
              p_demo_simplemodel_P_uint16_T_1 = &demo_simplemodel_P.s2_RTICANMMCHANNEL_TLC_P6[0];\
              p_demo_simplemodel_P_uint8_T_2 = &demo_simplemodel_P.root_Variation_Value;\
              p_demo_simplemodel_P_boolean_T_3 = &demo_simplemodel_P.root_Reset_Value;\
              p_demo_simplemodel_DW_real_T_0 = &demo_simplemodel_DW.s4_sfcn_RWORK;\

   #endif                       /* RTI_HEADER_demo_simplemodel_trc_ptr_h_ */
