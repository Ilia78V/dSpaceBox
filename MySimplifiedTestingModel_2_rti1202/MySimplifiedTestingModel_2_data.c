/*
 * MySimplifiedTestingModel_2_data.c
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

  /* Expression: 34
   * Referenced by: '<S1>/ConstantSwitch12'
   */
  34.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant10'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant'
   */
  2.0,

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

  /* Expression: 8
   * Referenced by: '<S1>/Constant12'
   */
  8.0,

  /* Expression: 1
   * Referenced by: '<S1>/Invalid CTW1'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S1>/ConstantSwitch13'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S1>/ConstantSwitch14'
   */
  0.0,

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

  /* Expression: sfpt(1).BytesRefNumOf
   * Referenced by: '<S5>/S-Function1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/ConstantSwitch2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Memory20'
   */
  0.0,

  /* Computed Parameter: Status_Y0
   * Referenced by: '<S12>/Status'
   */
  0,

  /* Expression: sfpt(1).BytesRefNumOf
   * Referenced by: '<S15>/S-Function1'
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

  /* Computed Parameter: Memory16_InitialCondition
   * Referenced by: '<S1>/Memory16'
   */
  false,

  /* Computed Parameter: Memory11_InitialCondition
   * Referenced by: '<S1>/Memory11'
   */
  false,

  /* Computed Parameter: Memory12_InitialCondition
   * Referenced by: '<S1>/Memory12'
   */
  false,

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

  /* Computed Parameter: Constant15_Value
   * Referenced by: '<S1>/Constant15'
   */
  0U,

  /* Computed Parameter: Memory17_InitialCondition
   * Referenced by: '<S1>/Memory17'
   */
  0U,

  /* Computed Parameter: Memory8_InitialCondition
   * Referenced by: '<S1>/Memory8'
   */
  0U,

  /* Computed Parameter: Memory13_InitialCondition
   * Referenced by: '<S1>/Memory13'
   */
  0U,

  /* Computed Parameter: Memory14_InitialCondition
   * Referenced by: '<S1>/Memory14'
   */
  0U,

  /* Computed Parameter: Memory15_InitialCondition
   * Referenced by: '<S1>/Memory15'
   */
  0U,

  /* Computed Parameter: Memory10_InitialCondition
   * Referenced by: '<S1>/Memory10'
   */
  0U,

  /* Computed Parameter: Memory21_InitialCondition
   * Referenced by: '<S1>/Memory21'
   */
  0U,

  /* Computed Parameter: Memory9_InitialCondition
   * Referenced by: '<S1>/Memory9'
   */
  0U,

  /* Computed Parameter: Memory19_InitialCondition
   * Referenced by: '<S1>/Memory19'
   */
  0U,

  /* Computed Parameter: Memory6_InitialCondition
   * Referenced by: '<S1>/Memory6'
   */
  0U,

  /* Computed Parameter: Memory18_InitialCondition
   * Referenced by: '<S1>/Memory18'
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
