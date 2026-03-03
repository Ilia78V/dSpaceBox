/***************************************************************************

   Source file MySimplifiedTestingModel_20x2810x29_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1202 23.1 (02-May-2023)
   Mon Dec  8 11:32:08 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "MySimplifiedTestingModel_20x2810x29_trc_ptr.h"
#include "MySimplifiedTestingModel_20x2810x29.h"
#include "MySimplifiedTestingModel_20x2810x29_private.h"

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
volatile real_T *p_0_MySimplifiedTestingModel_20x2810x29_real_T_0 = NULL;
volatile uint8_T *p_0_MySimplifiedTestingModel_20x2810x29_uint8_T_1 = NULL;
volatile boolean_T *p_0_MySimplifiedTestingModel_20x2810x29_boolean_T_2 = NULL;
volatile real_T *p_1_MySimplifiedTestingModel_20x2810x29_real_T_0 = NULL;
volatile boolean_T *p_1_MySimplifiedTestingModel_20x2810x29_boolean_T_1 = NULL;
volatile uint8_T *p_1_MySimplifiedTestingModel_20x2810x29_uint8_T_2 = NULL;
volatile uint16_T *p_2_MySimplifiedTestingModel_20x2810x29_uint16_T_0 = NULL;
volatile uint8_T *p_2_MySimplifiedTestingModel_20x2810x29_uint8_T_1 = NULL;
volatile boolean_T *p_2_MySimplifiedTestingModel_20x2810x29_boolean_T_2 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_MySimplifiedTestingModel_20x2810x29_real_T_0 =
    &MySimplifiedTestingModel_20x2_B.BegrenzungArbeitstemperatur3;
  p_0_MySimplifiedTestingModel_20x2810x29_uint8_T_1 =
    &MySimplifiedTestingModel_20x2_B.Switch[0];
  p_0_MySimplifiedTestingModel_20x2810x29_boolean_T_2 =
    &MySimplifiedTestingModel_20x2_B.CastToBoolean3;
  p_1_MySimplifiedTestingModel_20x2810x29_real_T_0 =
    &MySimplifiedTestingModel_20x2_P.Saturation_UpperSat;
  p_1_MySimplifiedTestingModel_20x2810x29_boolean_T_1 =
    &MySimplifiedTestingModel_20x2_P.Memory5_InitialCondition;
  p_1_MySimplifiedTestingModel_20x2810x29_uint8_T_2 =
    &MySimplifiedTestingModel_20x2_P.Constant12_Value;
  p_2_MySimplifiedTestingModel_20x2810x29_uint16_T_0 =
    &MySimplifiedTestingModel_20x_DW.comm_err_count;
  p_2_MySimplifiedTestingModel_20x2810x29_uint8_T_1 =
    &MySimplifiedTestingModel_20x_DW.Memory8_PreviousInput;
  p_2_MySimplifiedTestingModel_20x2810x29_boolean_T_2 =
    &MySimplifiedTestingModel_20x_DW.Memory5_PreviousInput;
}

void MySimplifiedTestingModel_20x2810x29_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
