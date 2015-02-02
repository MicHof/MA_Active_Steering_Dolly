/***************************************************************************

   Source file CAN_new_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 7.2 (02-May-2014)
   Mon Feb 02 10:16:50 2015

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "CAN_new_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_CAN_new_B_real_T_0 = 0;
volatile int16_T *p_CAN_new_B_int16_T_1 = 0;
volatile uint16_T *p_CAN_new_B_uint16_T_2 = 0;
volatile int8_T *p_CAN_new_B_int8_T_3 = 0;
volatile uint8_T *p_CAN_new_B_uint8_T_4 = 0;
volatile boolean_T *p_CAN_new_B_boolean_T_5 = 0;
volatile real_T *p_CAN_new_P_real_T_0 = 0;
volatile uint16_T *p_CAN_new_P_uint16_T_1 = 0;
volatile uint8_T *p_CAN_new_P_uint8_T_2 = 0;
volatile boolean_T *p_CAN_new_P_boolean_T_3 = 0;
volatile real_T *p_CAN_new_DW_real_T_0 = 0;
