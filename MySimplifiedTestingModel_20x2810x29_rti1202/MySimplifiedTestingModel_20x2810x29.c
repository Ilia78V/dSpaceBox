/*
 * MySimplifiedTestingModel_20x2810x29.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MySimplifiedTestingModel_20x2810x29".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Dec  8 11:32:08 2025
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MySimplifiedTestingModel_20x2810x29_trc_ptr.h"
#include "MySimplifiedTestingModel_20x2810x29.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <math.h>
#include "rt_roundd_snf.h"
#include <stddef.h>
#include "MySimplifiedTestingModel_20x2810x29_private.h"

/* Named constants for Chart: '<S1>/BUS MASTER FSM' */
#define MySimplifi_IN_RETRY_OR_BACKOFF1 ((uint8_T)9U)
#define MySimplifie_IN_DELIVER_OK_CLEAR ((uint8_T)4U)
#define MySimplifie_IN_DELIVER_OK_PULSE ((uint8_T)5U)
#define MySimplifiedT_IN_WAIT_RX_SWITCH ((uint8_T)14U)
#define MySimplifiedTe_IN_DELIVER_ERROR ((uint8_T)3U)
#define MySimplifiedTest_IN_DELIVER_ERR ((uint8_T)2U)
#define MySimplifiedTestin_ERR_BAD_ADDR ((uint8_T)2U)
#define MySimplifiedTestin_ERR_OVERFLOW ((uint8_T)5U)
#define MySimplifiedTestin_IN_VALIDATE1 ((uint8_T)12U)
#define MySimplifiedTestin_IN_WAIT_THRE ((uint8_T)15U)
#define MySimplifiedTestingM_DEV_THERMO ((uint8_T)2U)
#define MySimplifiedTestingM_IN_BACKOFF ((uint8_T)1U)
#define MySimplifiedTestingMod_DEV_NONE ((uint8_T)0U)
#define MySimplifiedTestingMod_DEV_ZKDM ((uint8_T)1U)
#define MySimplifiedTestingMode_IN_IDLE ((uint8_T)6U)
#define MySimplifiedTestingMode_IN_INIT ((uint8_T)7U)
#define MySimplifiedTesting_ERR_BAD_CRC ((uint8_T)4U)
#define MySimplifiedTesting_ERR_BAD_LEN ((uint8_T)3U)
#define MySimplifiedTesting_ERR_TIMEOUT ((uint8_T)1U)
#define MySimplifiedTesting_IN_LOAD_REQ ((uint8_T)8U)
#define MySimplifiedTesting_IN_TX_CLEAR ((uint8_T)10U)
#define MySimplifiedTesting_IN_TX_PULSE ((uint8_T)11U)
#define MySimplifiedTesting_IN_WAIT_RX2 ((uint8_T)13U)
#define MySimplified_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Named constants for Chart: '<S1>/ZKDM FSM' */
#define MySimplifiedTesti_IN_HANDLE_ERR ((uint8_T)2U)
#define MySimplifiedTesti_IN_WAIT_GRANT ((uint8_T)6U)
#define MySimplifiedTestin_IN_WAIT_RESP ((uint8_T)7U)
#define MySimplifiedTestingMo_IN_INIT_e ((uint8_T)3U)
#define MySimplifiedTestingMod_IN_PARSE ((uint8_T)4U)
#define MySimplifiedTestingMod_IN_READY ((uint8_T)5U)
#define MySimplifiedTesting_IN_COOLDOWN ((uint8_T)1U)

/* Block signals (default storage) */
B_MySimplifiedTestingModel_20_T MySimplifiedTestingModel_20x2_B;

/* Block states (default storage) */
DW_MySimplifiedTestingModel_2_T MySimplifiedTestingModel_20x_DW;

/* Real-time model */
static RT_MODEL_MySimplifiedTestingM_T MySimplifiedTestingModel_20x_M_;
RT_MODEL_MySimplifiedTestingM_T *const MySimplifiedTestingModel_20x_M =
  &MySimplifiedTestingModel_20x_M_;

/* Forward declaration for local functions */
static void MySimplifiedT_enter_atomic_IDLE(void);
static boolean_T MySimplifiedTestingModel_crc_ok(const uint8_T buf[64], uint8_T
  count);
static boolean_T MySimplifiedTestingMode_addr_ok(const uint8_T buf[64], uint8_T
  count, uint8_T expect_addr);
static boolean_T MySimplifiedTestingModel_len_ok(uint8_T count, uint8_T
  expect_len);
static void MySimplifiedTest_parse_fc_reply(const uint8_T u[64], uint8_T *PCD1_1,
  uint8_T *PCD1_2, real_T *freq_rel_percent, uint16_T *status_word, boolean_T
  *fu_ctrl_ready, boolean_T *fu_ready, boolean_T *fault_trip, boolean_T
  *fault_no_trip, boolean_T *bus_control_active, boolean_T *bcc_ok);
static void MySimplifiedTestingModel_20_fcn(boolean_T invalid_control_word,
  boolean_T active, uint8_T setpoint, uint8_T command[64]);

/* Function for Chart: '<S1>/BUS MASTER FSM' */
static void MySimplifiedT_enter_atomic_IDLE(void)
{
  /* Entry 'IDLE': '<S3>:34' */
  MySimplifiedTestingModel_20x_DW.currentDev = MySimplifiedTestingMod_DEV_NONE;
  MySimplifiedTestingModel_20x2_B.resp_ok_ZKDM = false;
  MySimplifiedTestingModel_20x2_B.resp_ok_THERMO = false;
  MySimplifiedTestingModel_20x2_B.resp_err_ZKDM = 0U;
  MySimplifiedTestingModel_20x2_B.resp_err_THERMO = 0U;
  MySimplifiedTestingModel_20x_DW.err_ZKDM = 0U;
  MySimplifiedTestingModel_20x_DW.err_THERMO = 0U;
  MySimplifiedTestingModel_20x2_B.grant_ZKDM = false;
  MySimplifiedTestingModel_20x2_B.grant_THERMO = false;
  MySimplifiedTestingModel_20x2_B.TX_Trigger = false;
  MySimplifiedTestingModel_20x2_B.TX_Len = 0U;
  MySimplifiedTestingModel_20x_DW.rxCount = 0U;
}

/* Function for Chart: '<S1>/BUS MASTER FSM' */
static boolean_T MySimplifiedTestingModel_crc_ok(const uint8_T buf[64], uint8_T
  count)
{
  int32_T k;
  int32_T q0;
  uint32_T qY;
  uint8_T bcc;

  /* MATLAB Function 'crc_ok': '<S3>:84' */
  /* '<S3>:84:3' */
  bcc = 0U;
  q0 = count;
  qY = (uint32_T)q0 - 1U;
  if (qY > (uint32_T)q0) {
    qY = 0U;
  }

  q0 = (int32_T)qY;

  /* '<S3>:84:4' */
  for (k = 0; k < q0; k++) {
    /* '<S3>:84:5' */
    bcc ^= buf[k];
  }

  /* '<S3>:84:7' */
  return buf[count - 1] == bcc;
}

/* Function for Chart: '<S1>/BUS MASTER FSM' */
static boolean_T MySimplifiedTestingMode_addr_ok(const uint8_T buf[64], uint8_T
  count, uint8_T expect_addr)
{
  boolean_T ok;

  /* MATLAB Function 'addr_ok': '<S3>:78' */
  if (count < 3) {
    /* '<S3>:78:2' */
    /* '<S3>:78:3' */
    ok = false;
  } else {
    /* '<S3>:78:5' */
    ok = (buf[2] == expect_addr);
  }

  return ok;
}

/* Function for Chart: '<S1>/BUS MASTER FSM' */
static boolean_T MySimplifiedTestingModel_len_ok(uint8_T count, uint8_T
  expect_len)
{
  /* MATLAB Function 'len_ok': '<S3>:83' */
  /* '<S3>:83:2' */
  return count == expect_len;
}

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTest_parse_fc_reply(const uint8_T u[64], uint8_T *PCD1_1,
  uint8_T *PCD1_2, real_T *freq_rel_percent, uint16_T *status_word, boolean_T
  *fu_ctrl_ready, boolean_T *fu_ready, boolean_T *fault_trip, boolean_T
  *fault_no_trip, boolean_T *bus_control_active, boolean_T *bcc_ok)
{
  int32_T k;
  uint8_T b;

  /* MATLAB Function 'parse_fc_reply': '<S7>:73' */
  /* '<S7>:73:19' */
  /* '<S7>:73:22' */
  b = 0U;

  /* '<S7>:73:23' */
  for (k = 0; k < 7; k++) {
    /* '<S7>:73:24' */
    b ^= u[k];
  }

  /* '<S7>:73:26' */
  *bcc_ok = (b == u[7]);

  /* '<S7>:73:29' */
  *PCD1_1 = u[3];

  /* '<S7>:73:30' */
  *PCD1_2 = u[4];

  /* '<S7>:73:33' */
  *status_word = (uint16_T)(u[3] << 8 | u[4]);

  /* '<S7>:73:39' */
  *fu_ctrl_ready = ((*status_word & 32768U) != 0U);

  /* '<S7>:73:40' */
  *fu_ready = ((*status_word & 16384U) != 0U);

  /* '<S7>:73:41' */
  *fault_trip = ((*status_word & 8192U) != 0U);

  /* '<S7>:73:42' */
  *fault_no_trip = ((*status_word & 4096U) != 0U);

  /* '<S7>:73:43' */
  *bus_control_active = ((*status_word & 64U) != 0U);

  /* '<S7>:73:46' */
  /* '<S7>:73:47' */
  *freq_rel_percent = (real_T)(u[5] << 8 | u[6]) * 0.006103515625;
}

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTestingModel_20_fcn(boolean_T invalid_control_word,
  boolean_T active, uint8_T setpoint, uint8_T command[64])
{
  int32_T tmp_0;
  int16_T x;
  uint8_T pcd2[2];
  uint8_T pcd1_1;
  uint8_T tmp;

  /* MATLAB Function 'fcn': '<S7>:50' */
  /* '<S7>:50:47' */
  memset(&command[0], 0, sizeof(uint8_T) << 6U);

  /* '<S7>:50:48' */
  command[0] = 2U;

  /* '<S7>:50:49' */
  command[1] = 6U;

  /* '<S7>:50:50' */
  command[2] = 125U;

  /* '<S7>:50:52' */
  pcd1_1 = 0U;

  /* '<S7>:50:53' */
  command[4] = 46U;
  if (!invalid_control_word) {
    /* '<S7>:50:57' */
    /* '<S7>:50:58' */
    pcd1_1 = 32U;
  }

  if (active) {
    /* '<S7>:50:62' */
    /* '<S7>:50:63' */
    pcd1_1 = (uint8_T)(pcd1_1 | 16);
  }

  /* '<S7>:50:80' */
  /* '<S7>:50:81' */
  tmp_0 = (int32_T)rt_roundd_snf((real_T)setpoint * 163.84);
  if (tmp_0 < 256) {
    tmp = (uint8_T)tmp_0;
  } else {
    tmp = MAX_uint8_T;
  }

  x = tmp;
  memcpy((void *)&pcd2[0], (void *)&x, (size_t)2 * sizeof(uint8_T));

  /* '<S7>:50:82' */
  tmp = pcd2[0];
  pcd2[0] = pcd2[1];
  pcd2[1] = tmp;

  /* '<S7>:50:89' */
  /* '<S7>:50:90' */
  /* '<S7>:50:91' */
  /* '<S7>:50:92' */
  /* '<S7>:50:94' */
  /* '<S7>:50:95' */
  /* '<S7>:50:96' */
  /* '<S7>:50:97' */
  command[3] = pcd1_1;

  /* '<S7>:50:98' */
  /* '<S7>:50:99' */
  command[5] = pcd2[0];
  command[6] = pcd2[1];

  /* '<S7>:50:100' */
  command[7] = (uint8_T)(pcd1_1 ^ 87 ^ pcd2[0] ^ tmp);
}

/* Model output function */
void MySimplifiedTestingModel_20x2810x29_output(void)
{
  real_T freq_rel;
  real_T u1;
  real_T u2;
  int32_T f;
  int32_T i;
  int32_T i_0;
  int32_T k;
  uint32_T qY;
  int16_T x;
  uint16_T q14;
  uint16_T sw;
  uint8_T pcd2[2];
  uint8_T bcc;
  uint8_T tmp;
  boolean_T bcc_ok;
  boolean_T bus_ctrl_active;
  boolean_T fault_no_trip;
  boolean_T fault_trip;
  boolean_T fu_ready;
  boolean_T guard1;
  boolean_T okCrc;

  /* DataTypeConversion: '<S1>/Cast To Boolean3' incorporates:
   *  Constant: '<S1>/Constant10'
   */
  MySimplifiedTestingModel_20x2_B.CastToBoolean3 =
    (MySimplifiedTestingModel_20x2_P.Constant10_Value != 0.0);

  /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' incorporates:
   *  Constant: '<S1>/Constant11'
   */
  freq_rel = MySimplifiedTestingModel_20x2_P.Constant11_Value;
  u1 = MySimplifiedTestingModel_20x2_P.BegrenzungArbeitstemperatur3_Lo;
  u2 = MySimplifiedTestingModel_20x2_P.BegrenzungArbeitstemperatur3_Up;
  if (freq_rel > u2) {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_20x2_B.BegrenzungArbeitstemperatur3 = u2;
  } else if (freq_rel < u1) {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_20x2_B.BegrenzungArbeitstemperatur3 = u1;
  } else {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_20x2_B.BegrenzungArbeitstemperatur3 = freq_rel;
  }

  /* End of Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */

  /* MATLAB Function: '<S1>/MATLAB Function4' incorporates:
   *  Constant: '<S1>/Constant13'
   *  Constant: '<S1>/ConstantSwitch10'
   *  Constant: '<S1>/ConstantSwitch11'
   *  Constant: '<S1>/ConstantSwitch7'
   *  Constant: '<S1>/ConstantSwitch8'
   *  Constant: '<S1>/ConstantSwitch9'
   */
  freq_rel = MySimplifiedTestingModel_20x2_B.BegrenzungArbeitstemperatur3;

  /* MATLAB Function 'RS485/MATLAB Function4': '<S6>:1' */
  /* '<S6>:1:57' */
  /* '<S6>:1:30' */
  /* '<S6>:1:36' */
  sw = 0U;
  if (MySimplifiedTestingModel_20x2_P.ConstantSwitch7_Value != 0.0) {
    /* '<S6>:1:37' */
    sw = 32768U;
  }

  if (MySimplifiedTestingModel_20x2_P.ConstantSwitch8_Value != 0.0) {
    /* '<S6>:1:38' */
    sw = (uint16_T)(sw | 16384);
  }

  if (MySimplifiedTestingModel_20x2_P.ConstantSwitch9_Value != 0.0) {
    /* '<S6>:1:39' */
    sw = (uint16_T)(sw | 8192);
  }

  if (MySimplifiedTestingModel_20x2_P.ConstantSwitch10_Value != 0.0) {
    /* '<S6>:1:40' */
    sw = (uint16_T)(sw | 4096);
  }

  if (MySimplifiedTestingModel_20x2_P.ConstantSwitch11_Value != 0.0) {
    /* '<S6>:1:41' */
    sw = (uint16_T)(sw | 64);
  }

  /* '<S6>:1:43' */
  /* '<S6>:1:44' */
  if (rtIsInf(MySimplifiedTestingModel_20x2_B.BegrenzungArbeitstemperatur3) ||
      rtIsNaN(MySimplifiedTestingModel_20x2_B.BegrenzungArbeitstemperatur3)) {
    /* '<S6>:1:47' */
    freq_rel = 0.0;
  }

  /* '<S6>:1:48' */
  freq_rel = fmax(0.0, fmin(100.0, freq_rel));

  /* '<S6>:1:49' */
  q14 = (uint16_T)rt_roundd_snf(freq_rel * 163.84);

  /* '<S6>:1:50' */
  /* '<S6>:1:51' */
  /* '<S6>:1:57' */
  memset(&MySimplifiedTestingModel_20x2_B.u_d[0], 0, sizeof(uint8_T) << 6U);

  /* '<S6>:1:58' */
  MySimplifiedTestingModel_20x2_B.u_d[0] = 2U;

  /* '<S6>:1:59' */
  MySimplifiedTestingModel_20x2_B.u_d[1] = 6U;

  /* '<S6>:1:60' */
  freq_rel = rt_roundd_snf(MySimplifiedTestingModel_20x2_P.Constant13_Value);
  if (freq_rel < 256.0) {
    if (freq_rel >= 0.0) {
      tmp = (uint8_T)freq_rel;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  MySimplifiedTestingModel_20x2_B.u_d[2] = tmp;

  /* '<S6>:1:61' */
  MySimplifiedTestingModel_20x2_B.u_d[3] = (uint8_T)((uint32_T)sw >> 8);

  /* '<S6>:1:62' */
  MySimplifiedTestingModel_20x2_B.u_d[4] = (uint8_T)(sw & 255);

  /* '<S6>:1:63' */
  MySimplifiedTestingModel_20x2_B.u_d[5] = (uint8_T)((uint32_T)q14 >> 8);

  /* '<S6>:1:64' */
  MySimplifiedTestingModel_20x2_B.u_d[6] = (uint8_T)(q14 & 255);

  /* '<S6>:1:67' */
  bcc = 0U;

  /* '<S6>:1:68' */
  for (k = 0; k < 7; k++) {
    /* '<S6>:1:69' */
    bcc ^= MySimplifiedTestingModel_20x2_B.u_d[k];
  }

  /* '<S6>:1:71' */
  MySimplifiedTestingModel_20x2_B.u_d[7] = bcc;

  /* End of MATLAB Function: '<S1>/MATLAB Function4' */

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant14'
   */
  if (MySimplifiedTestingModel_20x2_P.Constant14_Value >
      MySimplifiedTestingModel_20x2_P.Switch1_Threshold) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant12'
     */
    MySimplifiedTestingModel_20x2_B.Switch1 =
      MySimplifiedTestingModel_20x2_P.Constant12_Value;
  } else {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant15'
     */
    MySimplifiedTestingModel_20x2_B.Switch1 =
      MySimplifiedTestingModel_20x2_P.Constant15_Value;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Memory: '<S1>/Memory5' */
  MySimplifiedTestingModel_20x2_B.Memory5 =
    MySimplifiedTestingModel_20x_DW.Memory5_PreviousInput;

  /* Clock: '<S1>/Clock' */
  MySimplifiedTestingModel_20x2_B.Clock =
    MySimplifiedTestingModel_20x_M->Timing.t[0];

  /* Memory: '<S1>/Memory8' */
  MySimplifiedTestingModel_20x2_B.Memory8 =
    MySimplifiedTestingModel_20x_DW.Memory8_PreviousInput;

  /* Memory: '<S1>/Memory10' */
  MySimplifiedTestingModel_20x2_B.Memory10 =
    MySimplifiedTestingModel_20x_DW.Memory10_PreviousInput;

  /* DataTypeConversion: '<S1>/Cast To Boolean6' incorporates:
   *  Constant: '<S1>/Constant17'
   */
  MySimplifiedTestingModel_20x2_B.CastToBoolean6 =
    (MySimplifiedTestingModel_20x2_P.Constant17_Value != 0.0);

  /* DataTypeConversion: '<S1>/Cast To Boolean7' */
  MySimplifiedTestingModel_20x2_B.CastToBoolean7 = false;

  /* Memory: '<S1>/Memory9' */
  MySimplifiedTestingModel_20x2_B.Memory9 =
    MySimplifiedTestingModel_20x_DW.Memory9_PreviousInput;

  /* Memory: '<S1>/Memory7' */
  MySimplifiedTestingModel_20x2_B.Memory7 =
    MySimplifiedTestingModel_20x_DW.Memory7_PreviousInput;
  for (i = 0; i < 64; i++) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant14'
     */
    if (MySimplifiedTestingModel_20x2_P.Constant14_Value >
        MySimplifiedTestingModel_20x2_P.Switch_Threshold) {
      /* Switch: '<S1>/Switch' */
      MySimplifiedTestingModel_20x2_B.Switch[i] =
        MySimplifiedTestingModel_20x2_B.u_d[i];
    } else {
      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<S1>/Constant15'
       */
      MySimplifiedTestingModel_20x2_B.Switch[i] =
        MySimplifiedTestingModel_20x2_P.Constant15_Value;
    }

    /* End of Switch: '<S1>/Switch' */

    /* Memory: '<S1>/Memory6' */
    MySimplifiedTestingModel_20x2_B.Memory6[i] =
      MySimplifiedTestingModel_20x_DW.Memory6_PreviousInput[i];

    /* SignalConversion generated from: '<S3>/ SFunction ' incorporates:
     *  Chart: '<S1>/BUS MASTER FSM'
     */
    MySimplifiedTestingModel_20x2_B.TmpSignalConversionAtSFunctionI[i] = 0U;
  }

  /* Chart: '<S1>/BUS MASTER FSM' incorporates:
   *  Memory: '<S1>/Memory6'
   *  SignalConversion generated from: '<S3>/ SFunction '
   *  Switch: '<S1>/Switch'
   */
  if (MySimplifiedTestingModel_20x_DW.temporalCounter_i2 < 65535U) {
    MySimplifiedTestingModel_20x_DW.temporalCounter_i2++;
  }

  /* Gateway: RS485/BUS MASTER FSM */
  if (MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p < 1U) {
    MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p = 1U;
  }

  /* During: RS485/BUS MASTER FSM */
  if (MySimplifiedTestingModel_20x_DW.is_active_c6_MySimplifiedTestin == 0U) {
    /* Entry: RS485/BUS MASTER FSM */
    MySimplifiedTestingModel_20x_DW.is_active_c6_MySimplifiedTestin = 1U;

    /* Entry Internal: RS485/BUS MASTER FSM */
    /* Transition: '<S3>:33' */
    MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
      MySimplifiedTestingMode_IN_INIT;
    MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p = 0U;

    /* Entry 'INIT': '<S3>:32' */
    MySimplifiedTestingModel_20x2_B.TX_Trigger = false;
    MySimplifiedTestingModel_20x2_B.TX_Len = 0U;
    MySimplifiedTestingModel_20x2_B.grant_ZKDM = false;
    MySimplifiedTestingModel_20x2_B.grant_THERMO = false;
    MySimplifiedTestingModel_20x2_B.resp_ok_ZKDM = false;
    MySimplifiedTestingModel_20x2_B.resp_ok_THERMO = false;
    MySimplifiedTestingModel_20x_DW.err_ZKDM = 0U;
    MySimplifiedTestingModel_20x_DW.err_THERMO = 0U;
    MySimplifiedTestingModel_20x_DW.currentDev = MySimplifiedTestingMod_DEV_NONE;
    MySimplifiedTestingModel_20x_DW.retry = 0U;
    MySimplifiedTestingModel_20x_DW.pollCounter = 0U;
    MySimplifiedTestingModel_20x_DW.rxCount = 0U;
  } else {
    guard1 = false;
    switch (MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_) {
     case MySimplifiedTestingM_IN_BACKOFF:
      /* During 'BACKOFF': '<S3>:65' */
      if (MySimplifiedTestingModel_20x_DW.temporalCounter_i2 >=
          MySimplifiedTestingModel_20x_DW.interGap_ms) {
        /* Transition: '<S3>:67' */
        MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestingMode_IN_IDLE;
        MySimplifiedT_enter_atomic_IDLE();
      }
      break;

     case MySimplifiedTest_IN_DELIVER_ERR:
      /* During 'DELIVER_ERR': '<S3>:56' */
      /* Transition: '<S3>:64' */
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifi_IN_RETRY_OR_BACKOFF1;
      MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p = 0U;
      break;

     case MySimplifiedTe_IN_DELIVER_ERROR:
      /* During 'DELIVER_ERROR': '<S3>:436' */
      /* Transition: '<S3>:440' */
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTestingM_IN_BACKOFF;
      MySimplifiedTestingModel_20x_DW.temporalCounter_i2 = 0U;

      /* Entry 'BACKOFF': '<S3>:65' */
      if (MySimplifiedTestingModel_20x_DW.currentDev ==
          MySimplifiedTestingMod_DEV_ZKDM) {
        i = (int32_T)(MySimplifiedTestingModel_20x_DW.pollCounter + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        k = MySimplifiedTestingModel_20x_DW.pollThermoEvery;
        qY = (uint32_T)k - 1U;
        if (qY > (uint32_T)k) {
          qY = 0U;
        }

        i_0 = (int32_T)qY;
        bcc = (uint8_T)i;
        tmp = (uint8_T)i_0;
        if (bcc <= tmp) {
          MySimplifiedTestingModel_20x_DW.pollCounter = bcc;
        } else {
          MySimplifiedTestingModel_20x_DW.pollCounter = tmp;
        }
      }
      break;

     case MySimplifie_IN_DELIVER_OK_CLEAR:
      /* During 'DELIVER_OK_CLEAR': '<S3>:60' */
      /* Transition: '<S3>:333' */
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTestingM_IN_BACKOFF;
      MySimplifiedTestingModel_20x_DW.temporalCounter_i2 = 0U;

      /* Entry 'BACKOFF': '<S3>:65' */
      if (MySimplifiedTestingModel_20x_DW.currentDev ==
          MySimplifiedTestingMod_DEV_ZKDM) {
        i = (int32_T)(MySimplifiedTestingModel_20x_DW.pollCounter + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        k = MySimplifiedTestingModel_20x_DW.pollThermoEvery;
        qY = (uint32_T)k - 1U;
        if (qY > (uint32_T)k) {
          qY = 0U;
        }

        i_0 = (int32_T)qY;
        bcc = (uint8_T)i;
        tmp = (uint8_T)i_0;
        if (bcc <= tmp) {
          MySimplifiedTestingModel_20x_DW.pollCounter = bcc;
        } else {
          MySimplifiedTestingModel_20x_DW.pollCounter = tmp;
        }
      }
      break;

     case MySimplifie_IN_DELIVER_OK_PULSE:
      /* During 'DELIVER_OK_PULSE': '<S3>:59' */
      /* Transition: '<S3>:61' */
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifie_IN_DELIVER_OK_CLEAR;

      /* Entry 'DELIVER_OK_CLEAR': '<S3>:60' */
      MySimplifiedTestingModel_20x2_B.resp_ok_ZKDM = false;
      MySimplifiedTestingModel_20x2_B.resp_ok_THERMO = false;
      break;

     case MySimplifiedTestingMode_IN_IDLE:
      MySimplifiedTestingModel_20x2_B.TX_Trigger = false;

      /* During 'IDLE': '<S3>:34' */
      if ((MySimplifiedTestingModel_20x_DW.currentDev ==
           MySimplifiedTestingMod_DEV_ZKDM) ||
          (MySimplifiedTestingModel_20x_DW.currentDev ==
           MySimplifiedTestingM_DEV_THERMO)) {
        /* Transition: '<S3>:39' */
        /* Transition: '<S3>:40' */
        MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTesting_IN_LOAD_REQ;
        MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p = 0U;

        /* Entry 'LOAD_REQ': '<S3>:36' */
        if (MySimplifiedTestingModel_20x_DW.currentDev ==
            MySimplifiedTestingMod_DEV_ZKDM) {
          memcpy(&MySimplifiedTestingModel_20x_DW.chosen_req[0],
                 &MySimplifiedTestingModel_20x2_B.Memory6[0], sizeof(uint8_T) <<
                 6U);
          MySimplifiedTestingModel_20x_DW.chosen_len =
            MySimplifiedTestingModel_20x2_B.Memory7;
          MySimplifiedTestingModel_20x_DW.chosen_expect_addr =
            MySimplifiedTestingModel_20x2_B.Memory8;
          MySimplifiedTestingModel_20x_DW.chosen_expect_len =
            MySimplifiedTestingModel_20x2_B.Memory9;
          MySimplifiedTestingModel_20x_DW.timeout_ms =
            MySimplifiedTestingModel_20x_DW.timeout_ms_ZKDM;
          MySimplifiedTestingModel_20x2_B.grant_ZKDM = true;
          MySimplifiedTestingModel_20x2_B.grant_THERMO = false;
        } else {
          memcpy(&MySimplifiedTestingModel_20x_DW.chosen_req[0],
                 &MySimplifiedTestingModel_20x2_B.TmpSignalConversionAtSFunctionI
                 [0], sizeof(uint8_T) << 6U);
          MySimplifiedTestingModel_20x_DW.chosen_len = 0U;
          MySimplifiedTestingModel_20x_DW.chosen_expect_addr = 0U;
          MySimplifiedTestingModel_20x_DW.chosen_expect_len = 0U;
          MySimplifiedTestingModel_20x_DW.timeout_ms =
            MySimplifiedTestingModel_20x_DW.timeout_ms_THERMO;
          MySimplifiedTestingModel_20x2_B.grant_ZKDM = false;
          MySimplifiedTestingModel_20x2_B.grant_THERMO = true;
        }

        memcpy(&MySimplifiedTestingModel_20x2_B.TX_Data[0],
               &MySimplifiedTestingModel_20x_DW.chosen_req[0], sizeof(uint8_T) <<
               6U);
        MySimplifiedTestingModel_20x2_B.TX_Len =
          MySimplifiedTestingModel_20x_DW.chosen_len;
        MySimplifiedTestingModel_20x_DW.retry = 0U;
        MySimplifiedTestingModel_20x_DW.rxCount = 0U;
      } else if (MySimplifiedTestingModel_20x2_B.Memory5) {
        MySimplifiedTestingModel_20x_DW.currentDev =
          MySimplifiedTestingMod_DEV_ZKDM;
      } else {
        MySimplifiedTestingModel_20x_DW.currentDev =
          MySimplifiedTestingMod_DEV_NONE;
      }
      break;

     case MySimplifiedTestingMode_IN_INIT:
      /* During 'INIT': '<S3>:32' */
      /* Transition: '<S3>:35' */
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTestingMode_IN_IDLE;
      MySimplifiedT_enter_atomic_IDLE();
      break;

     case MySimplifiedTesting_IN_LOAD_REQ:
      /* During 'LOAD_REQ': '<S3>:36' */
      /* Transition: '<S3>:44' */
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTestin_IN_WAIT_THRE;
      break;

     case MySimplifi_IN_RETRY_OR_BACKOFF1:
      /* During 'RETRY_OR_BACKOFF1': '<S3>:278' */
      /* Transition: '<S3>:431' */
      memset(&MySimplifiedTestingModel_20x_DW.rxBuf[0], 0, sizeof(uint8_T) << 6U);
      MySimplifiedTestingModel_20x_DW.rxCount = 0U;
      if (MySimplifiedTestingModel_20x_DW.retry <
          MySimplifiedTestingModel_20x_DW.maxRetry) {
        /* Transition: '<S3>:266' */
        /* Transition: '<S3>:268' */
        i = (int32_T)(MySimplifiedTestingModel_20x_DW.retry + 1U);
        MySimplifiedTestingModel_20x_DW.retry = (uint8_T)i;

        /* Transition: '<S3>:277' */
        MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestin_IN_WAIT_THRE;
      } else {
        /* Transition: '<S3>:267' */
        /* Transition: '<S3>:270' */
        /* Transition: '<S3>:439' */
        MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTe_IN_DELIVER_ERROR;

        /* Entry 'DELIVER_ERROR': '<S3>:436' */
        if (MySimplifiedTestingModel_20x_DW.currentDev ==
            MySimplifiedTestingMod_DEV_ZKDM) {
          MySimplifiedTestingModel_20x2_B.resp_err_ZKDM =
            MySimplifiedTestingModel_20x_DW.err_ZKDM;
        } else {
          MySimplifiedTestingModel_20x2_B.resp_err_THERMO =
            MySimplifiedTestingModel_20x_DW.err_THERMO;
        }
      }
      break;

     case MySimplifiedTesting_IN_TX_CLEAR:
      MySimplifiedTestingModel_20x2_B.TX_Trigger = false;

      /* During 'TX_CLEAR': '<S3>:50' */
      /* Transition: '<S3>:54' */
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTesting_IN_WAIT_RX2;
      MySimplifiedTestingModel_20x_DW.temporalCounter_i2 = 0U;
      break;

     case MySimplifiedTesting_IN_TX_PULSE:
      /* During 'TX_PULSE': '<S3>:46' */
      /* Transition: '<S3>:51' */
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTesting_IN_TX_CLEAR;

      /* Entry 'TX_CLEAR': '<S3>:50' */
      MySimplifiedTestingModel_20x2_B.TX_Trigger = false;
      break;

     case MySimplifiedTestin_IN_VALIDATE1:
      /* During 'VALIDATE1': '<S3>:258' */
      break;

     case MySimplifiedTesting_IN_WAIT_RX2:
      /* During 'WAIT_RX2': '<S3>:367' */
      if (MySimplifiedTestingModel_20x_DW.temporalCounter_i2 >=
          MySimplifiedTestingModel_20x_DW.timeout_ms) {
        /* Transition: '<S3>:57' */
        MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTest_IN_DELIVER_ERR;

        /* Entry 'DELIVER_ERR': '<S3>:56' */
        if (MySimplifiedTestingModel_20x_DW.currentDev ==
            MySimplifiedTestingMod_DEV_ZKDM) {
          MySimplifiedTestingModel_20x_DW.err_ZKDM =
            MySimplifiedTesting_ERR_TIMEOUT;
        } else {
          MySimplifiedTestingModel_20x_DW.err_THERMO =
            MySimplifiedTesting_ERR_TIMEOUT;
        }
      } else {
        /* Transition: '<S3>:390' */
        i = (int32_T)((uint32_T)MySimplifiedTestingModel_20x_DW.rxCount +
                      MySimplifiedTestingModel_20x2_B.Switch1);
        i_0 = i;
        if ((uint32_T)i_0 > 255U) {
          i_0 = 255;
        }

        okCrc = ((i_0 <= 64) && (MySimplifiedTestingModel_20x2_B.Switch1 > 0));
        if (okCrc) {
          /* Transition: '<S3>:391' */
          /* Transition: '<S3>:393' */
          if (MySimplifiedTestingModel_20x2_B.Switch1 < 1) {
            k = -1;
          } else {
            k = MySimplifiedTestingModel_20x2_B.Switch1 - 1;
          }

          i_0 = (int32_T)(MySimplifiedTestingModel_20x_DW.rxCount + 1U);
          if ((uint32_T)i_0 > 255U) {
            i_0 = 255;
          }

          bcc = (uint8_T)i_0;
          i_0 = i;
          if ((uint32_T)i_0 > 255U) {
            i_0 = 255;
          }

          tmp = (uint8_T)i_0;
          if (bcc > tmp) {
            f = 1;
          } else {
            f = bcc;
          }

          for (i_0 = 0; i_0 <= k; i_0++) {
            MySimplifiedTestingModel_20x_DW.rxBuf[(f + i_0) - 1] =
              MySimplifiedTestingModel_20x2_B.Switch[i_0];
          }

          if ((uint32_T)i > 255U) {
            i = 255;
          }

          MySimplifiedTestingModel_20x_DW.rxCount = (uint8_T)i;

          /* Transition: '<S3>:421' */
        } else {
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          if (i > 64) {
            /* Transition: '<S3>:401' */
            if (MySimplifiedTestingModel_20x_DW.currentDev ==
                MySimplifiedTestingMod_DEV_ZKDM) {
              /* Transition: '<S3>:402' */
              /* Transition: '<S3>:411' */
              MySimplifiedTestingModel_20x_DW.err_ZKDM =
                MySimplifiedTestin_ERR_OVERFLOW;

              /* Transition: '<S3>:412' */
            } else {
              /* Transition: '<S3>:403' */
              MySimplifiedTestingModel_20x_DW.err_THERMO =
                MySimplifiedTestin_ERR_OVERFLOW;
            }

            /* Transition: '<S3>:415' */
            guard1 = true;
          } else if (MySimplifiedTestingModel_20x_DW.rxCount >=
                     MySimplifiedTestingModel_20x_DW.chosen_expect_len) {
            /* Transition: '<S3>:58' */
            /* Transition: '<S3>:257' */
            okCrc = MySimplifiedTestingModel_crc_ok
              (MySimplifiedTestingModel_20x_DW.rxBuf,
               MySimplifiedTestingModel_20x_DW.rxCount);
            if (!MySimplifiedTestingMode_addr_ok
                (MySimplifiedTestingModel_20x_DW.rxBuf,
                 MySimplifiedTestingModel_20x_DW.rxCount,
                 MySimplifiedTestingModel_20x_DW.chosen_expect_addr)) {
              /* Transition: '<S3>:183' */
              /* Transition: '<S3>:207' */
              if (MySimplifiedTestingModel_20x_DW.currentDev ==
                  MySimplifiedTestingMod_DEV_ZKDM) {
                /* Transition: '<S3>:208' */
                /* Transition: '<S3>:210' */
                MySimplifiedTestingModel_20x_DW.err_ZKDM =
                  MySimplifiedTestin_ERR_BAD_ADDR;

                /* Transition: '<S3>:211' */
              } else {
                /* Transition: '<S3>:209' */
                MySimplifiedTestingModel_20x_DW.err_THERMO =
                  MySimplifiedTestin_ERR_BAD_ADDR;
              }

              /* Transition: '<S3>:212' */
              /* Transition: '<S3>:194' */
              /* Transition: '<S3>:193' */
              /* Transition: '<S3>:253' */
              guard1 = true;

              /* Transition: '<S3>:184' */
            } else if (!MySimplifiedTestingModel_len_ok
                       (MySimplifiedTestingModel_20x_DW.rxCount,
                        MySimplifiedTestingModel_20x_DW.chosen_expect_len)) {
              /* Transition: '<S3>:186' */
              /* Transition: '<S3>:218' */
              if (MySimplifiedTestingModel_20x_DW.currentDev ==
                  MySimplifiedTestingMod_DEV_ZKDM) {
                /* Transition: '<S3>:219' */
                /* Transition: '<S3>:225' */
                MySimplifiedTestingModel_20x_DW.err_ZKDM =
                  MySimplifiedTesting_ERR_BAD_LEN;

                /* Transition: '<S3>:222' */
              } else {
                /* Transition: '<S3>:228' */
                MySimplifiedTestingModel_20x_DW.err_THERMO =
                  MySimplifiedTesting_ERR_BAD_LEN;
              }

              /* Transition: '<S3>:226' */
              /* Transition: '<S3>:193' */
              /* Transition: '<S3>:253' */
              guard1 = true;

              /* Transition: '<S3>:187' */
            } else if (!okCrc) {
              /* Transition: '<S3>:189' */
              /* Transition: '<S3>:240' */
              if (MySimplifiedTestingModel_20x_DW.currentDev ==
                  MySimplifiedTestingMod_DEV_ZKDM) {
                /* Transition: '<S3>:230' */
                /* Transition: '<S3>:236' */
                MySimplifiedTestingModel_20x_DW.err_ZKDM =
                  MySimplifiedTesting_ERR_BAD_CRC;

                /* Transition: '<S3>:233' */
              } else {
                /* Transition: '<S3>:239' */
                MySimplifiedTestingModel_20x_DW.err_THERMO =
                  MySimplifiedTesting_ERR_BAD_CRC;
              }

              /* Transition: '<S3>:237' */
              /* Transition: '<S3>:253' */
              guard1 = true;
            } else {
              /* Transition: '<S3>:252' */
              memcpy(&MySimplifiedTestingModel_20x2_B.resp_data[0],
                     &MySimplifiedTestingModel_20x_DW.rxBuf[0], sizeof(uint8_T) <<
                     6U);
              MySimplifiedTestingModel_20x2_B.resp_len =
                MySimplifiedTestingModel_20x_DW.rxCount;
              if (MySimplifiedTestingModel_20x_DW.currentDev ==
                  MySimplifiedTestingMod_DEV_ZKDM) {
                /* Transition: '<S3>:242' */
                /* Transition: '<S3>:244' */
                MySimplifiedTestingModel_20x2_B.resp_ok_ZKDM = true;

                /* Transition: '<S3>:245' */
              } else {
                /* Transition: '<S3>:243' */
                MySimplifiedTestingModel_20x2_B.resp_ok_THERMO = true;
              }

              /* Transition: '<S3>:246' */
              /* Transition: '<S3>:195' */
              MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
                MySimplifie_IN_DELIVER_OK_PULSE;
              MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p = 0U;
            }
          }
        }
      }
      break;

     case MySimplifiedT_IN_WAIT_RX_SWITCH:
      /* During 'WAIT_RX_SWITCH': '<S3>:443' */
      if (MySimplifiedTestingModel_20x2_B.CastToBoolean6) {
        /* Transition: '<S3>:446' */
        MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestin_IN_WAIT_THRE;
      }
      break;

     default:
      /* During 'WAIT_THRE': '<S3>:42' */
      okCrc = (MySimplifiedTestingModel_20x2_B.CastToBoolean3 &&
               MySimplifiedTestingModel_20x2_B.CastToBoolean6);
      if (okCrc) {
        /* Transition: '<S3>:47' */
        MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTesting_IN_TX_PULSE;
        MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p = 0U;

        /* Entry 'TX_PULSE': '<S3>:46' */
        MySimplifiedTestingModel_20x2_B.TX_Trigger = true;
      } else if (!MySimplifiedTestingModel_20x2_B.CastToBoolean6) {
        /* Transition: '<S3>:444' */
        MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedT_IN_WAIT_RX_SWITCH;

        /* Entry 'WAIT_RX_SWITCH': '<S3>:443' */
      }
      break;
    }

    if (guard1) {
      MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifi_IN_RETRY_OR_BACKOFF1;
      MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p = 0U;
    }
  }

  /* DataTypeConversion: '<S1>/Cast To Boolean' incorporates:
   *  Constant: '<S1>/Constant'
   */
  MySimplifiedTestingModel_20x2_B.CastToBoolean =
    (MySimplifiedTestingModel_20x2_P.Constant_Value != 0.0);

  /* DataTypeConversion: '<S1>/Cast To Boolean1' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  MySimplifiedTestingModel_20x2_B.CastToBoolean1 =
    (MySimplifiedTestingModel_20x2_P.Constant3_Value != 0.0);

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Constant: '<S1>/Constant4'
   */
  freq_rel = MySimplifiedTestingModel_20x2_P.Constant4_Value;
  u1 = MySimplifiedTestingModel_20x2_P.Saturation_LowerSat_l;
  u2 = MySimplifiedTestingModel_20x2_P.Saturation_UpperSat_g;
  if (freq_rel > u2) {
    freq_rel = u2;
  } else if (freq_rel < u1) {
    freq_rel = u1;
  }

  freq_rel = floor(freq_rel);
  if (rtIsNaN(freq_rel)) {
    i = 0;
  } else {
    i = (int32_T)freq_rel;
  }

  /* Saturate: '<S1>/Saturation' */
  MySimplifiedTestingModel_20x2_B.Saturation_f = (uint8_T)i;

  /* MATLAB Function: '<S1>/Create 8-Bytes Command' */
  /* MATLAB Function 'RS485/Create 8-Bytes Command': '<S4>:1' */
  /* '<S4>:1:47' */
  memset(&MySimplifiedTestingModel_20x2_B.command_c[0], 0, sizeof(uint8_T) << 6U);

  /* '<S4>:1:48' */
  MySimplifiedTestingModel_20x2_B.command_c[0] = 2U;

  /* '<S4>:1:49' */
  MySimplifiedTestingModel_20x2_B.command_c[1] = 6U;

  /* '<S4>:1:50' */
  MySimplifiedTestingModel_20x2_B.command_c[2] = 125U;

  /* '<S4>:1:52' */
  bcc = 0U;

  /* '<S4>:1:53' */
  MySimplifiedTestingModel_20x2_B.command_c[4] = 46U;
  if (!MySimplifiedTestingModel_20x2_B.CastToBoolean) {
    /* '<S4>:1:57' */
    /* '<S4>:1:58' */
    bcc = 32U;
  }

  if (MySimplifiedTestingModel_20x2_B.CastToBoolean1) {
    /* '<S4>:1:62' */
    /* '<S4>:1:63' */
    bcc = (uint8_T)(bcc | 16);
  }

  /* '<S4>:1:80' */
  /* '<S4>:1:81' */
  i = (int32_T)rt_roundd_snf((real_T)
    MySimplifiedTestingModel_20x2_B.Saturation_f * 163.84);
  if (i < 256) {
    tmp = (uint8_T)i;
  } else {
    tmp = MAX_uint8_T;
  }

  x = tmp;
  memcpy((void *)&pcd2[0], (void *)&x, (size_t)2 * sizeof(uint8_T));

  /* '<S4>:1:82' */
  tmp = pcd2[0];
  pcd2[0] = pcd2[1];
  pcd2[1] = tmp;

  /* '<S4>:1:89' */
  /* '<S4>:1:90' */
  /* '<S4>:1:91' */
  /* '<S4>:1:92' */
  /* '<S4>:1:94' */
  /* '<S4>:1:95' */
  /* '<S4>:1:96' */
  /* '<S4>:1:97' */
  MySimplifiedTestingModel_20x2_B.command_c[3] = bcc;

  /* '<S4>:1:98' */
  /* '<S4>:1:99' */
  MySimplifiedTestingModel_20x2_B.command_c[5] = pcd2[0];
  MySimplifiedTestingModel_20x2_B.command_c[6] = pcd2[1];

  /* '<S4>:1:100' */
  MySimplifiedTestingModel_20x2_B.command_c[7] = (uint8_T)(bcc ^ 87 ^ pcd2[0] ^
    tmp);

  /* End of MATLAB Function: '<S1>/Create 8-Bytes Command' */

  /* DataTypeConversion: '<S1>/Cast To Boolean5' incorporates:
   *  Constant: '<S1>/Constant16'
   */
  MySimplifiedTestingModel_20x2_B.CastToBoolean5 =
    (MySimplifiedTestingModel_20x2_P.Constant16_Value != 0.0);

  /* Memory: '<S1>/Memory' */
  MySimplifiedTestingModel_20x2_B.Memory =
    MySimplifiedTestingModel_20x_DW.Memory_PreviousInput;

  /* Memory: '<S1>/Memory1' */
  MySimplifiedTestingModel_20x2_B.Memory1 =
    MySimplifiedTestingModel_20x_DW.Memory1_PreviousInput;

  /* Memory: '<S1>/Memory2' */
  MySimplifiedTestingModel_20x2_B.Memory2 =
    MySimplifiedTestingModel_20x_DW.Memory2_PreviousInput;

  /* Memory: '<S1>/Memory3' */
  memcpy(&MySimplifiedTestingModel_20x2_B.Memory3[0],
         &MySimplifiedTestingModel_20x_DW.Memory3_PreviousInput[0], sizeof
         (uint8_T) << 6U);

  /* Memory: '<S1>/Memory4' */
  MySimplifiedTestingModel_20x2_B.Memory4 =
    MySimplifiedTestingModel_20x_DW.Memory4_PreviousInput;

  /* Chart: '<S1>/ZKDM FSM' incorporates:
   *  Memory: '<S1>/Memory3'
   */
  if (MySimplifiedTestingModel_20x_DW.temporalCounter_i2_i < 255U) {
    MySimplifiedTestingModel_20x_DW.temporalCounter_i2_i++;
  }

  /* Gateway: RS485/ZKDM FSM */
  if (MySimplifiedTestingModel_20x_DW.temporalCounter_i1 < 1U) {
    MySimplifiedTestingModel_20x_DW.temporalCounter_i1 = 1U;
  }

  /* During: RS485/ZKDM FSM */
  if (MySimplifiedTestingModel_20x_DW.is_active_c11_MySimplifiedTesti == 0U) {
    /* Entry: RS485/ZKDM FSM */
    MySimplifiedTestingModel_20x_DW.is_active_c11_MySimplifiedTesti = 1U;

    /* Entry Internal: RS485/ZKDM FSM */
    /* Transition: '<S7>:24' */
    MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
      MySimplifiedTestingMo_IN_INIT_e;
    MySimplifiedTestingModel_20x_DW.temporalCounter_i1 = 0U;

    /* Entry 'INIT': '<S7>:23' */
    MySimplifiedTestingModel_20x2_B.expect_addr_ZKDM =
      MySimplifiedTestingModel_20x_DW.fc_addr;
    MySimplifiedTestingModel_20x2_B.expect_len_ZKDM = 8U;
    MySimplifiedTestingModel_20x2_B.expect_crc_kind_ZKDM = 0U;
    MySimplifiedTestingModel_20x2_B.req_valid = false;
    MySimplifiedTestingModel_20x2_B.req_len = 0U;
    MySimplifiedTestingModel_20x_DW.comm_err_count = 0U;
  } else {
    switch (MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel) {
     case MySimplifiedTesting_IN_COOLDOWN:
      /* During 'COOLDOWN': '<S7>:37' */
      /* Transition: '<S7>:39' */
      MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
        MySimplifiedTestingMod_IN_READY;
      MySimplifiedTestingModel_20x_DW.temporalCounter_i2_i = 0U;

      /* Entry 'READY': '<S7>:25' */
      MySimplifiedTestingModel_20x2_B.req_valid = false;
      MySimplifiedTestingModel_20x_DW.READY_to_WAIT_GRANT = false;
      break;

     case MySimplifiedTesti_IN_HANDLE_ERR:
      /* During 'HANDLE_ERR': '<S7>:32' */
      /* Transition: '<S7>:38' */
      MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
        MySimplifiedTesting_IN_COOLDOWN;
      MySimplifiedTestingModel_20x_DW.temporalCounter_i1 = 0U;

      /* Entry 'COOLDOWN': '<S7>:37' */
      break;

     case MySimplifiedTestingMo_IN_INIT_e:
      /* During 'INIT': '<S7>:23' */
      /* Transition: '<S7>:26' */
      MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
        MySimplifiedTestingMod_IN_READY;
      MySimplifiedTestingModel_20x_DW.temporalCounter_i2_i = 0U;

      /* Entry 'READY': '<S7>:25' */
      MySimplifiedTestingModel_20x2_B.req_valid = false;
      MySimplifiedTestingModel_20x_DW.READY_to_WAIT_GRANT = false;
      break;

     case MySimplifiedTestingMod_IN_PARSE:
      /* During 'PARSE': '<S7>:30' */
      if (MySimplifiedTestingModel_20x_DW.temporalCounter_i2_i >=
          MySimplifiedTestingModel_20x_DW.min_period_ms) {
        /* Transition: '<S7>:41' */
        MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesting_IN_COOLDOWN;
        MySimplifiedTestingModel_20x_DW.temporalCounter_i1 = 0U;

        /* Entry 'COOLDOWN': '<S7>:37' */
      }
      break;

     case MySimplifiedTestingMod_IN_READY:
      /* During 'READY': '<S7>:25' */
      if (MySimplifiedTestingModel_20x_DW.READY_to_WAIT_GRANT) {
        /* Transition: '<S7>:28' */
        MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_WAIT_GRANT;

        /* Entry 'WAIT_GRANT': '<S7>:27' */
        MySimplifiedTestingModel_20x_DW.READY_to_WAIT_GRANT = false;
      } else if (MySimplifiedTestingModel_20x_DW.temporalCounter_i2_i >=
                 MySimplifiedTestingModel_20x_DW.min_period_ms) {
        MySimplifiedTestingModel_20_fcn
          (MySimplifiedTestingModel_20x2_B.CastToBoolean,
           MySimplifiedTestingModel_20x2_B.CastToBoolean1,
           MySimplifiedTestingModel_20x2_B.Saturation_f,
           MySimplifiedTestingModel_20x2_B.req_bytes);
        MySimplifiedTestingModel_20x2_B.req_len =
          MySimplifiedTestingModel_20x_DW.tx_len;
        MySimplifiedTestingModel_20x2_B.expect_addr_ZKDM =
          MySimplifiedTestingModel_20x2_B.req_bytes[2];
        MySimplifiedTestingModel_20x2_B.expect_len_ZKDM = 8U;
        MySimplifiedTestingModel_20x2_B.expect_crc_kind_ZKDM =
          MySimplifiedTestingModel_20x2_B.req_bytes[7];
        MySimplifiedTestingModel_20x2_B.req_valid = true;
        MySimplifiedTestingModel_20x_DW.READY_to_WAIT_GRANT = true;
      }
      break;

     case MySimplifiedTesti_IN_WAIT_GRANT:
      /* During 'WAIT_GRANT': '<S7>:27' */
      if (MySimplifiedTestingModel_20x2_B.Memory) {
        /* Transition: '<S7>:33' */
        MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestin_IN_WAIT_RESP;

        /* Entry 'WAIT_RESP': '<S7>:29' */
      } else if (MySimplifiedTestingModel_20x2_B.Memory2 > 0) {
        /* Transition: '<S7>:34' */
        MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_HANDLE_ERR;
        MySimplifiedTestingModel_20x_DW.temporalCounter_i1 = 0U;

        /* Entry 'HANDLE_ERR': '<S7>:32' */
        qY = MySimplifiedTestingModel_20x_DW.comm_err_count + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        MySimplifiedTestingModel_20x_DW.comm_err_count = (uint16_T)qY;
      }
      break;

     default:
      /* During 'WAIT_RESP': '<S7>:29' */
      if (MySimplifiedTestingModel_20x2_B.Memory1) {
        /* Transition: '<S7>:35' */
        MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_PARSE;
        MySimplifiedTestingModel_20x_DW.temporalCounter_i2_i = 0U;

        /* Entry 'PARSE': '<S7>:30' */
        MySimplifiedTest_parse_fc_reply(MySimplifiedTestingModel_20x2_B.Memory3,
          &bcc, &tmp, &freq_rel, &sw, &okCrc, &fu_ready, &fault_trip,
          &fault_no_trip, &bus_ctrl_active, &bcc_ok);
        if (!bcc_ok) {
          qY = MySimplifiedTestingModel_20x_DW.comm_err_count + 1U;
          if (qY > 65535U) {
            qY = 65535U;
          }

          MySimplifiedTestingModel_20x_DW.comm_err_count = (uint16_T)qY;
        }
      } else if (MySimplifiedTestingModel_20x2_B.Memory2 > 0) {
        /* Transition: '<S7>:36' */
        MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_HANDLE_ERR;
        MySimplifiedTestingModel_20x_DW.temporalCounter_i1 = 0U;

        /* Entry 'HANDLE_ERR': '<S7>:32' */
        qY = MySimplifiedTestingModel_20x_DW.comm_err_count + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        MySimplifiedTestingModel_20x_DW.comm_err_count = (uint16_T)qY;
      } else {
        MySimplifiedTestingModel_20x2_B.req_valid = false;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/ZKDM FSM' */

  /* Saturate: '<S1>/Begrenzung Arbeitstemperatur1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  freq_rel = MySimplifiedTestingModel_20x2_P.Constant1_Value;
  u1 = MySimplifiedTestingModel_20x2_P.BegrenzungArbeitstemperatur1_Lo;
  u2 = MySimplifiedTestingModel_20x2_P.BegrenzungArbeitstemperatur1_Up;
  if (freq_rel > u2) {
    freq_rel = u2;
  } else if (freq_rel < u1) {
    freq_rel = u1;
  }

  freq_rel = floor(freq_rel);
  if (rtIsNaN(freq_rel)) {
    i = 0;
  } else {
    i = (int32_T)freq_rel;
  }

  /* Saturate: '<S1>/Begrenzung Arbeitstemperatur1' */
  MySimplifiedTestingModel_20x2_B.BegrenzungArbeitstemperatur1 = (uint8_T)i;

  /* DataTypeConversion: '<S1>/Cast To Boolean2' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  MySimplifiedTestingModel_20x2_B.CastToBoolean2 =
    (MySimplifiedTestingModel_20x2_P.Constant5_Value != 0.0);

  /* DataTypeConversion: '<S1>/Cast To Boolean4' incorporates:
   *  Constant: '<S1>/ConstantSwitch2'
   */
  MySimplifiedTestingModel_20x2_B.CastToBoolean4 =
    (MySimplifiedTestingModel_20x2_P.ConstantSwitch2_Value != 0.0);

  /* Constant: '<S1>/Constant18' */
  MySimplifiedTestingModel_20x2_B.Constant18 =
    MySimplifiedTestingModel_20x2_P.Constant18_Value;

  /* Constant: '<S1>/Constant6' */
  MySimplifiedTestingModel_20x2_B.Constant6 =
    MySimplifiedTestingModel_20x2_P.Constant6_Value;

  /* Constant: '<S1>/Constant7' */
  MySimplifiedTestingModel_20x2_B.Constant7 =
    MySimplifiedTestingModel_20x2_P.Constant7_Value;

  /* Constant: '<S1>/Constant8' */
  MySimplifiedTestingModel_20x2_B.Constant8 =
    MySimplifiedTestingModel_20x2_P.Constant8_Value;

  /* Constant: '<S1>/Constant9' */
  MySimplifiedTestingModel_20x2_B.Constant9 =
    MySimplifiedTestingModel_20x2_P.Constant9_Value;
}

/* Model update function */
void MySimplifiedTestingModel_20x2810x29_update(void)
{
  /* Update for Memory: '<S1>/Memory5' */
  MySimplifiedTestingModel_20x_DW.Memory5_PreviousInput =
    MySimplifiedTestingModel_20x2_B.req_valid;

  /* Update for Memory: '<S1>/Memory8' */
  MySimplifiedTestingModel_20x_DW.Memory8_PreviousInput =
    MySimplifiedTestingModel_20x2_B.expect_addr_ZKDM;

  /* Update for Memory: '<S1>/Memory10' */
  MySimplifiedTestingModel_20x_DW.Memory10_PreviousInput =
    MySimplifiedTestingModel_20x2_B.expect_crc_kind_ZKDM;

  /* Update for Memory: '<S1>/Memory9' */
  MySimplifiedTestingModel_20x_DW.Memory9_PreviousInput =
    MySimplifiedTestingModel_20x2_B.expect_len_ZKDM;

  /* Update for Memory: '<S1>/Memory6' */
  memcpy(&MySimplifiedTestingModel_20x_DW.Memory6_PreviousInput[0],
         &MySimplifiedTestingModel_20x2_B.req_bytes[0], sizeof(uint8_T) << 6U);

  /* Update for Memory: '<S1>/Memory7' */
  MySimplifiedTestingModel_20x_DW.Memory7_PreviousInput =
    MySimplifiedTestingModel_20x2_B.req_len;

  /* Update for Memory: '<S1>/Memory' */
  MySimplifiedTestingModel_20x_DW.Memory_PreviousInput =
    MySimplifiedTestingModel_20x2_B.grant_ZKDM;

  /* Update for Memory: '<S1>/Memory1' */
  MySimplifiedTestingModel_20x_DW.Memory1_PreviousInput =
    MySimplifiedTestingModel_20x2_B.resp_ok_ZKDM;

  /* Update for Memory: '<S1>/Memory2' */
  MySimplifiedTestingModel_20x_DW.Memory2_PreviousInput =
    MySimplifiedTestingModel_20x2_B.resp_err_ZKDM;

  /* Update for Memory: '<S1>/Memory3' */
  memcpy(&MySimplifiedTestingModel_20x_DW.Memory3_PreviousInput[0],
         &MySimplifiedTestingModel_20x2_B.resp_data[0], sizeof(uint8_T) << 6U);

  /* Update for Memory: '<S1>/Memory4' */
  MySimplifiedTestingModel_20x_DW.Memory4_PreviousInput =
    MySimplifiedTestingModel_20x2_B.resp_len;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MySimplifiedTestingModel_20x_M->Timing.clockTick0)) {
    ++MySimplifiedTestingModel_20x_M->Timing.clockTickH0;
  }

  MySimplifiedTestingModel_20x_M->Timing.t[0] =
    MySimplifiedTestingModel_20x_M->Timing.clockTick0 *
    MySimplifiedTestingModel_20x_M->Timing.stepSize0 +
    MySimplifiedTestingModel_20x_M->Timing.clockTickH0 *
    MySimplifiedTestingModel_20x_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    MySimplifiedTestingModel_20x_M->Timing.clockTick1++;
    if (!MySimplifiedTestingModel_20x_M->Timing.clockTick1) {
      MySimplifiedTestingModel_20x_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void MySimplifiedTestingModel_20x2810x29_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MySimplifiedTestingModel_20x_M, 0,
                sizeof(RT_MODEL_MySimplifiedTestingM_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MySimplifiedTestingModel_20x_M->solverInfo,
                          &MySimplifiedTestingModel_20x_M->Timing.simTimeStep);
    rtsiSetTPtr(&MySimplifiedTestingModel_20x_M->solverInfo, &rtmGetTPtr
                (MySimplifiedTestingModel_20x_M));
    rtsiSetStepSizePtr(&MySimplifiedTestingModel_20x_M->solverInfo,
                       &MySimplifiedTestingModel_20x_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&MySimplifiedTestingModel_20x_M->solverInfo,
                          (&rtmGetErrorStatus(MySimplifiedTestingModel_20x_M)));
    rtsiSetRTModelPtr(&MySimplifiedTestingModel_20x_M->solverInfo,
                      MySimplifiedTestingModel_20x_M);
  }

  rtsiSetSimTimeStep(&MySimplifiedTestingModel_20x_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&MySimplifiedTestingModel_20x_M->solverInfo, false);
  rtsiSetSolverName(&MySimplifiedTestingModel_20x_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(MySimplifiedTestingModel_20x_M,
             &MySimplifiedTestingModel_20x_M->Timing.tArray[0]);
  MySimplifiedTestingModel_20x_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &MySimplifiedTestingModel_20x2_B), 0,
                sizeof(B_MySimplifiedTestingModel_20_T));

  /* states (dwork) */
  (void) memset((void *)&MySimplifiedTestingModel_20x_DW, 0,
                sizeof(DW_MySimplifiedTestingModel_2_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    MySimplifiedTestingModel_20x2810x29_rti_init_trc_pointers();
  }

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    MySimplifiedTestingModel_20x_DW.Memory5_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory5_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory8' */
    MySimplifiedTestingModel_20x_DW.Memory8_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory8_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory10' */
    MySimplifiedTestingModel_20x_DW.Memory10_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory10_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory9' */
    MySimplifiedTestingModel_20x_DW.Memory9_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory9_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory7' */
    MySimplifiedTestingModel_20x_DW.Memory7_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory7_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    MySimplifiedTestingModel_20x_DW.Memory_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    MySimplifiedTestingModel_20x_DW.Memory1_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory1_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    MySimplifiedTestingModel_20x_DW.Memory2_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory2_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    MySimplifiedTestingModel_20x_DW.Memory4_PreviousInput =
      MySimplifiedTestingModel_20x2_P.Memory4_InitialCondition;

    /* SystemInitialize for Chart: '<S1>/BUS MASTER FSM' */
    MySimplifiedTestingModel_20x_DW.temporalCounter_i1_p = 0U;
    MySimplifiedTestingModel_20x_DW.temporalCounter_i2 = 0U;
    MySimplifiedTestingModel_20x_DW.is_active_c6_MySimplifiedTestin = 0U;
    MySimplifiedTestingModel_20x_DW.is_c6_MySimplifiedTestingModel_ =
      MySimplified_IN_NO_ACTIVE_CHILD;
    MySimplifiedTestingModel_20x_DW.interGap_ms = 5U;
    MySimplifiedTestingModel_20x_DW.maxRetry = 1U;
    MySimplifiedTestingModel_20x_DW.pollThermoEvery = 4U;
    MySimplifiedTestingModel_20x_DW.timeout_ms_THERMO = 80U;
    MySimplifiedTestingModel_20x_DW.timeout_ms_ZKDM = 20U;
    MySimplifiedTestingModel_20x_DW.chosen_expect_addr = 0U;
    MySimplifiedTestingModel_20x_DW.chosen_expect_len = 0U;
    MySimplifiedTestingModel_20x_DW.chosen_len = 0U;
    MySimplifiedTestingModel_20x_DW.currentDev = 0U;
    MySimplifiedTestingModel_20x_DW.pollCounter = 0U;
    MySimplifiedTestingModel_20x_DW.retry = 0U;
    MySimplifiedTestingModel_20x_DW.rxCount = 0U;
    MySimplifiedTestingModel_20x_DW.timeout_ms = 20U;
    MySimplifiedTestingModel_20x_DW.err_THERMO = 0U;
    MySimplifiedTestingModel_20x_DW.err_ZKDM = 0U;
    for (i = 0; i < 64; i++) {
      /* InitializeConditions for Memory: '<S1>/Memory6' */
      MySimplifiedTestingModel_20x_DW.Memory6_PreviousInput[i] =
        MySimplifiedTestingModel_20x2_P.Memory6_InitialCondition;

      /* InitializeConditions for Memory: '<S1>/Memory3' */
      MySimplifiedTestingModel_20x_DW.Memory3_PreviousInput[i] =
        MySimplifiedTestingModel_20x2_P.Memory3_InitialCondition;

      /* SystemInitialize for Chart: '<S1>/BUS MASTER FSM' */
      MySimplifiedTestingModel_20x_DW.chosen_req[i] = 0U;
      MySimplifiedTestingModel_20x_DW.rxBuf[i] = 0U;
      MySimplifiedTestingModel_20x2_B.TX_Data[i] = 0U;
    }

    /* SystemInitialize for Chart: '<S1>/BUS MASTER FSM' */
    MySimplifiedTestingModel_20x2_B.TX_Len = 0U;
    MySimplifiedTestingModel_20x2_B.TX_Trigger = false;
    MySimplifiedTestingModel_20x2_B.grant_ZKDM = false;
    MySimplifiedTestingModel_20x2_B.resp_err_ZKDM = 0U;
    MySimplifiedTestingModel_20x2_B.resp_ok_ZKDM = false;
    memset(&MySimplifiedTestingModel_20x2_B.resp_data[0], 0, sizeof(uint8_T) <<
           6U);
    MySimplifiedTestingModel_20x2_B.resp_err_THERMO = 0U;
    MySimplifiedTestingModel_20x2_B.resp_len = 0U;
    MySimplifiedTestingModel_20x2_B.grant_THERMO = false;
    MySimplifiedTestingModel_20x2_B.resp_ok_THERMO = false;

    /* SystemInitialize for Chart: '<S1>/ZKDM FSM' */
    MySimplifiedTestingModel_20x_DW.temporalCounter_i1 = 0U;
    MySimplifiedTestingModel_20x_DW.temporalCounter_i2_i = 0U;
    MySimplifiedTestingModel_20x_DW.is_active_c11_MySimplifiedTesti = 0U;
    MySimplifiedTestingModel_20x_DW.is_c11_MySimplifiedTestingModel =
      MySimplified_IN_NO_ACTIVE_CHILD;
    MySimplifiedTestingModel_20x_DW.fc_addr = 253U;
    MySimplifiedTestingModel_20x_DW.min_period_ms = 50U;
    MySimplifiedTestingModel_20x_DW.READY_to_WAIT_GRANT = false;
    MySimplifiedTestingModel_20x_DW.tx_len = 8U;
    MySimplifiedTestingModel_20x_DW.comm_err_count = 0U;
    MySimplifiedTestingModel_20x2_B.req_valid = false;
    memset(&MySimplifiedTestingModel_20x2_B.req_bytes[0], 0, sizeof(uint8_T) <<
           6U);
    MySimplifiedTestingModel_20x2_B.req_len = 0U;
    MySimplifiedTestingModel_20x2_B.expect_addr_ZKDM = 0U;
    MySimplifiedTestingModel_20x2_B.expect_crc_kind_ZKDM = 0U;
    MySimplifiedTestingModel_20x2_B.expect_len_ZKDM = 0U;
  }
}

/* Model terminate function */
void MySimplifiedTestingModel_20x2810x29_terminate(void)
{
  /* (no terminate code required) */
}
