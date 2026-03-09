/*
 * MySimplifiedTestingModel_2_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MySimplifiedTestingModel_2".
 *
 * Model version              : 1.104
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Mar  9 09:58:22 2026
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MySimplifiedTestingModel_2_types_h_
#define RTW_HEADER_MySimplifiedTestingModel_2_types_h_
#include "rtwtypes.h"

/* Custom Type definition for Chart: '<S1>/ZKDM FSM' */
#ifndef struct_tag_tEH1AxETsBqvmkm0OXMjcF
#define struct_tag_tEH1AxETsBqvmkm0OXMjcF

struct tag_tEH1AxETsBqvmkm0OXMjcF
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_tEH1AxETsBqvmkm0OXMjcF */

#ifndef typedef_rtString_MySimplifiedTestingM_T
#define typedef_rtString_MySimplifiedTestingM_T

typedef struct tag_tEH1AxETsBqvmkm0OXMjcF rtString_MySimplifiedTestingM_T;

#endif                             /* typedef_rtString_MySimplifiedTestingM_T */

#ifndef struct_tag_bhlIbNdlacbARFmQL4oHlC
#define struct_tag_bhlIbNdlacbARFmQL4oHlC

struct tag_bhlIbNdlacbARFmQL4oHlC
{
  rtString_MySimplifiedTestingM_T f1;
  rtString_MySimplifiedTestingM_T f2;
  rtString_MySimplifiedTestingM_T f3;
  rtString_MySimplifiedTestingM_T f4;
  rtString_MySimplifiedTestingM_T f5;
  rtString_MySimplifiedTestingM_T f6;
  rtString_MySimplifiedTestingM_T f7;
  rtString_MySimplifiedTestingM_T f8;
};

#endif                                 /* struct_tag_bhlIbNdlacbARFmQL4oHlC */

#ifndef typedef_cell_0_MySimplifiedTestingMod_T
#define typedef_cell_0_MySimplifiedTestingMod_T

typedef struct tag_bhlIbNdlacbARFmQL4oHlC cell_0_MySimplifiedTestingMod_T;

#endif                             /* typedef_cell_0_MySimplifiedTestingMod_T */

#ifndef struct_emxArray_uint8_T_1x127
#define struct_emxArray_uint8_T_1x127

struct emxArray_uint8_T_1x127
{
  uint8_T data[127];
  int32_T size[2];
};

#endif                                 /* struct_emxArray_uint8_T_1x127 */

#ifndef typedef_emxArray_uint8_T_1x127_MySimp_T
#define typedef_emxArray_uint8_T_1x127_MySimp_T

typedef struct emxArray_uint8_T_1x127 emxArray_uint8_T_1x127_MySimp_T;

#endif                             /* typedef_emxArray_uint8_T_1x127_MySimp_T */

/* Parameters (default storage) */
typedef struct P_MySimplifiedTestingModel_2_T_ P_MySimplifiedTestingModel_2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_MySimplifiedTestingMo_T RT_MODEL_MySimplifiedTestingM_T;

#endif                      /* RTW_HEADER_MySimplifiedTestingModel_2_types_h_ */
