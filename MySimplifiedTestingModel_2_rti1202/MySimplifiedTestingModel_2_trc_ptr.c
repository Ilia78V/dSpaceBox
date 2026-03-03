/***************************************************************************

   Source file MySimplifiedTestingModel_2_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1202 23.1 (02-May-2023)
   Thu Feb 19 09:49:32 2026

   Copyright 2026, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "MySimplifiedTestingModel_2_trc_ptr.h"
#include "MySimplifiedTestingModel_2.h"
#include "MySimplifiedTestingModel_2_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_MySimplifiedTestingModel_2_real_T_0 = NULL;
volatile uint32_T *p_0_MySimplifiedTestingModel_2_uint32_T_1 = NULL;
volatile int32_T *p_0_MySimplifiedTestingModel_2_int32_T_2 = NULL;
volatile uint16_T *p_0_MySimplifiedTestingModel_2_uint16_T_3 = NULL;
volatile uint8_T *p_0_MySimplifiedTestingModel_2_uint8_T_4 = NULL;
volatile boolean_T *p_0_MySimplifiedTestingModel_2_boolean_T_5 = NULL;
volatile real_T *p_1_MySimplifiedTestingModel_2_real_T_0 = NULL;
volatile int32_T *p_1_MySimplifiedTestingModel_2_int32_T_1 = NULL;
volatile uint32_T *p_1_MySimplifiedTestingModel_2_uint32_T_2 = NULL;
volatile boolean_T *p_1_MySimplifiedTestingModel_2_boolean_T_3 = NULL;
volatile uint8_T *p_1_MySimplifiedTestingModel_2_uint8_T_4 = NULL;
volatile uint16_T *p_2_MySimplifiedTestingModel_2_uint16_T_0 = NULL;
volatile uint8_T *p_2_MySimplifiedTestingModel_2_uint8_T_1 = NULL;
volatile boolean_T *p_2_MySimplifiedTestingModel_2_boolean_T_2 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_MySimplifiedTestingModel_2_real_T_0 =
    &MySimplifiedTestingModel_2_B.Saturation;
  p_0_MySimplifiedTestingModel_2_uint32_T_1 =
    &MySimplifiedTestingModel_2_B.SFunction1_o2;
  p_0_MySimplifiedTestingModel_2_int32_T_2 =
    &MySimplifiedTestingModel_2_B.SFunction1_o3;
  p_0_MySimplifiedTestingModel_2_uint16_T_3 =
    &MySimplifiedTestingModel_2_B.debug_command[0];
  p_0_MySimplifiedTestingModel_2_uint8_T_4 =
    &MySimplifiedTestingModel_2_B.Memory3[0];
  p_0_MySimplifiedTestingModel_2_boolean_T_5 =
    &MySimplifiedTestingModel_2_B.CastToBoolean1;
  p_1_MySimplifiedTestingModel_2_real_T_0 =
    &MySimplifiedTestingModel_2_P.Active_Value;
  p_1_MySimplifiedTestingModel_2_int32_T_1 =
    &MySimplifiedTestingModel_2_P.Status_Y0;
  p_1_MySimplifiedTestingModel_2_uint32_T_2 =
    &MySimplifiedTestingModel_2_P.SFunction1_BytesRefNumOf_e;
  p_1_MySimplifiedTestingModel_2_boolean_T_3 =
    &MySimplifiedTestingModel_2_P.Memory_InitialCondition;
  p_1_MySimplifiedTestingModel_2_uint8_T_4 =
    &MySimplifiedTestingModel_2_P.Constant12_Value;
  p_2_MySimplifiedTestingModel_2_uint16_T_0 =
    &MySimplifiedTestingModel_2_DW.comm_err_count;
  p_2_MySimplifiedTestingModel_2_uint8_T_1 =
    &MySimplifiedTestingModel_2_DW.Memory3_PreviousInput[0];
  p_2_MySimplifiedTestingModel_2_boolean_T_2 =
    &MySimplifiedTestingModel_2_DW.Memory_PreviousInput;
}

void MySimplifiedTestingModel_2_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
