/*
 * MySimplifiedTestingModel_2_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MySimplifiedTestingModel_2".
 *
 * Model version              : 1.99
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Feb 19 09:49:32 2026
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MySimplifiedTestingModel_2.h"

/* Block parameters (default storage) */
P_MySimplifiedTestingModel_2_T MySimplifiedTestingModel_2_P = {
  /* Expression: 0
   * Referenced by: '<S1>/Active'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/Setpoint'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S1>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Invalid CTW'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant16'
   */
  0.0,

  /* Expression: sfpt(1).BytesRefNumOf
   * Referenced by: '<S5>/S-Function1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/TX on'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/RX on'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/ConstantSwitch7'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/ConstantSwitch8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ConstantSwitch9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ConstantSwitch10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ConstantSwitch11'
   */
  0.0,

  /* Expression: 34
   * Referenced by: '<S1>/Constant11'
   */
  34.0,

  /* Expression: 100
   * Referenced by: '<S1>/Begrenzung Arbeitstemperatur3'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Begrenzung Arbeitstemperatur3'
   */
  0.0,

  /* Expression: 125
   * Referenced by: '<S1>/Constant13'
   */
  125.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant14'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant5'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant10'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/ConstantSwitch2'
   */
  0.0,

  /* Computed Parameter: Status_Y0
   * Referenced by: '<S11>/Status'
   */
  0,

  /* Expression: sfpt(1).BytesRefNumOf
   * Referenced by: '<S13>/S-Function1'
   */
  32U,

  /* Computed Parameter: Constant19_Value
   * Referenced by: '<S1>/Constant19'
   */
  8U,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S1>/Memory'
   */
  false,

  /* Computed Parameter: Memory1_InitialCondition
   * Referenced by: '<S1>/Memory1'
   */
  false,

  /* Computed Parameter: Memory5_InitialCondition
   * Referenced by: '<S1>/Memory5'
   */
  false,

  /* Computed Parameter: Constant12_Value
   * Referenced by: '<S1>/Constant12'
   */
  8U,

  /* Computed Parameter: Memory3_InitialCondition
   * Referenced by: '<S1>/Memory3'
   */
  0U,

  /* Computed Parameter: Memory2_InitialCondition
   * Referenced by: '<S1>/Memory2'
   */
  0U,

  /* Computed Parameter: Memory4_InitialCondition
   * Referenced by: '<S1>/Memory4'
   */
  0U,

  /* Computed Parameter: Memory8_InitialCondition
   * Referenced by: '<S1>/Memory8'
   */
  0U,

  /* Computed Parameter: Memory10_InitialCondition
   * Referenced by: '<S1>/Memory10'
   */
  0U,

  /* Computed Parameter: Memory9_InitialCondition
   * Referenced by: '<S1>/Memory9'
   */
  0U,

  /* Computed Parameter: Memory6_InitialCondition
   * Referenced by: '<S1>/Memory6'
   */
  0U,

  /* Computed Parameter: Memory7_InitialCondition
   * Referenced by: '<S1>/Memory7'
   */
  0U,

  /* Computed Parameter: BegrenzungArbeitstemperatur1_Up
   * Referenced by: '<S1>/Begrenzung Arbeitstemperatur1'
   */
  100U,

  /* Computed Parameter: BegrenzungArbeitstemperatur1_Lo
   * Referenced by: '<S1>/Begrenzung Arbeitstemperatur1'
   */
  0U,

  /* Computed Parameter: Constant15_Value
   * Referenced by: '<S1>/Constant15'
   */
  0U,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<S1>/Constant6'
   */
  12U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S1>/Constant7'
   */
  31U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S1>/Constant8'
   */
  8U,

  /* Computed Parameter: Length_Value
   * Referenced by: '<S1>/Length'
   */
  6U
};
