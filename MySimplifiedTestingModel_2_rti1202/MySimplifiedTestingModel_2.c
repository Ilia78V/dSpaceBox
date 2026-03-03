/*
 * MySimplifiedTestingModel_2.c
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

#include "MySimplifiedTestingModel_2_trc_ptr.h"
#include "MySimplifiedTestingModel_2.h"
#include "rtwtypes.h"
#include <string.h>
#include "MySimplifiedTestingModel_2_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MySimplifiedTestingModel_2_types.h"
#include "zero_crossing_types.h"

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
B_MySimplifiedTestingModel_2_T MySimplifiedTestingModel_2_B;

/* Block states (default storage) */
DW_MySimplifiedTestingModel_2_T MySimplifiedTestingModel_2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_MySimplifiedTestingMo_T MySimplifiedTestingMode_PrevZCX;

/* Real-time model */
static RT_MODEL_MySimplifiedTestingM_T MySimplifiedTestingModel_2_M_;
RT_MODEL_MySimplifiedTestingM_T *const MySimplifiedTestingModel_2_M =
  &MySimplifiedTestingModel_2_M_;

/* Forward declaration for local functions */
static void MySimplifiedTest_parse_fc_reply(const uint8_T u[64], uint8_T *PCD1_1,
  uint8_T *PCD1_2, real_T *freq_rel_percent, uint16_T *status_word, boolean_T
  *fu_ctrl_ready, boolean_T *fu_ready, boolean_T *fault_trip, boolean_T
  *fault_no_trip, boolean_T *bus_control_active, boolean_T *bcc_ok);
static void MySimplifiedTestingModel_2_fcn(boolean_T invalid_control_word,
  boolean_T active, real_T setpoint, uint8_T command[127]);
static void MySimplifiedTesti_make_rev8_lut(uint8_T REV8[256]);
static uint16_T MySimplifiedTestingM_apply_mode(const uint8_T b_in[2], const
  uint8_T REV8[256], uint8_T mode);
static void MySimplifiedTest_pcd2_flipcases(uint16_T pcd2, uint8_T out_modes[8],
  int32_T *out_labels_f1___dummy, int32_T *out_labels_f2___dummy, int32_T
  *out_labels_f3___dummy, int32_T *out_labels_f4___dummy, int32_T
  *out_labels_f5___dummy, int32_T *out_labels_f6___dummy, int32_T
  *out_labels_f7___dummy, int32_T *out_labels_f8___dummy, uint16_T out_values[8],
  uint16_T out_asArray[8]);
static void MySimplifiedTestingM_debug_cmnd(real_T setpoint, uint16_T cmnds[8]);
static void MySimplifiedT_enter_atomic_IDLE(void);
static boolean_T MySimplifiedTestingModel_crc_ok(const uint8_T buf[127], uint8_T
  count);
static boolean_T MySimplifiedTestingMode_addr_ok(const uint8_T buf[127], uint8_T
  count, uint8_T expect_addr);
static boolean_T MySimplifiedTestingModel_len_ok(uint8_T count, uint8_T
  expect_len);
static real_T MySimplifiedTestingMode_bin2dec(const char_T s[8]);

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTest_parse_fc_reply(const uint8_T u[64], uint8_T *PCD1_1,
  uint8_T *PCD1_2, real_T *freq_rel_percent, uint16_T *status_word, boolean_T
  *fu_ctrl_ready, boolean_T *fu_ready, boolean_T *fault_trip, boolean_T
  *fault_no_trip, boolean_T *bus_control_active, boolean_T *bcc_ok)
{
  int32_T k;
  uint8_T b;

  /* MATLAB Function 'parse_fc_reply': '<S12>:73' */
  /* '<S12>:73:19' */
  /* '<S12>:73:22' */
  b = 0U;

  /* '<S12>:73:23' */
  for (k = 0; k < 7; k++) {
    /* '<S12>:73:24' */
    b ^= u[k];
  }

  /* '<S12>:73:26' */
  *bcc_ok = (b == u[7]);

  /* '<S12>:73:29' */
  *PCD1_1 = u[3];

  /* '<S12>:73:30' */
  *PCD1_2 = u[4];

  /* '<S12>:73:33' */
  *status_word = (uint16_T)(u[3] << 8 | u[4]);

  /* '<S12>:73:39' */
  *fu_ctrl_ready = ((*status_word & 32768U) != 0U);

  /* '<S12>:73:40' */
  *fu_ready = ((*status_word & 16384U) != 0U);

  /* '<S12>:73:41' */
  *fault_trip = ((*status_word & 8192U) != 0U);

  /* '<S12>:73:42' */
  *fault_no_trip = ((*status_word & 4096U) != 0U);

  /* '<S12>:73:43' */
  *bus_control_active = ((*status_word & 64U) != 0U);

  /* '<S12>:73:46' */
  /* '<S12>:73:47' */
  *freq_rel_percent = (real_T)(u[5] << 8 | u[6]) * 0.006103515625;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTestingModel_2_fcn(boolean_T invalid_control_word,
  boolean_T active, real_T setpoint, uint8_T command[127])
{
  real_T tmp;
  int16_T x;
  uint8_T pcd2[2];
  uint8_T pcd1_1;
  uint8_T pcd1_2;

  /* MATLAB Function 'fcn': '<S12>:50' */
  /* '<S12>:50:47' */
  memset(&command[0], 0, 127U * sizeof(uint8_T));

  /* '<S12>:50:48' */
  command[0] = 2U;

  /* '<S12>:50:49' */
  command[1] = 6U;

  /* '<S12>:50:50' */
  command[2] = 125U;

  /* '<S12>:50:52' */
  pcd1_1 = 4U;

  /* '<S12>:50:53' */
  pcd1_2 = 36U;
  if (!invalid_control_word) {
    /* '<S12>:50:57' */
    /* '<S12>:50:58' */
    pcd1_1 = 36U;
  }

  if (active) {
    /* '<S12>:50:62' */
    /* '<S12>:50:63' */
    pcd1_2 = 124U;

    /* '<S12>:50:64' */
    pcd1_1 = (uint8_T)(pcd1_1 | 4);
  }

  /* '<S12>:50:81' */
  /* '<S12>:50:82' */
  tmp = rt_roundd_snf(setpoint * 163.84);
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      x = (int16_T)tmp;
    } else {
      x = MIN_int16_T;
    }
  } else {
    x = MAX_int16_T;
  }

  memcpy((void *)&pcd2[0], (void *)&x, (size_t)2 * sizeof(uint8_T));

  /* '<S12>:50:91' */
  /* '<S12>:50:92' */
  /* '<S12>:50:93' */
  /* '<S12>:50:94' */
  /* '<S12>:50:96' */
  /* '<S12>:50:97' */
  /* '<S12>:50:98' */
  /* '<S12>:50:99' */
  command[3] = pcd1_1;

  /* '<S12>:50:100' */
  command[4] = pcd1_2;

  /* '<S12>:50:101' */
  command[5] = pcd2[0];
  command[6] = pcd2[1];

  /* '<S12>:50:102' */
  command[7] = (uint8_T)(pcd1_1 ^ 121 ^ pcd1_2 ^ pcd2[0] ^ pcd2[1]);
}

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTesti_make_rev8_lut(uint8_T REV8[256])
{
  int32_T i;
  int32_T k;

  /* MATLAB Function 'make_rev8_lut': '<S12>:113' */
  /* '<S12>:113:19' */
  /* '<S12>:113:16' */
  /* '<S12>:113:22' */
  for (i = 0; i < 256; i++) {
    uint8_T r;

    /* '<S12>:113:23' */
    /* '<S12>:113:24' */
    r = 0U;

    /* '<S12>:113:25' */
    for (k = 0; k < 8; k++) {
      /* '<S12>:113:27' */
      r = (uint8_T)(((1 << k & i) != 0) << (7 - k) | r);
    }

    /* '<S12>:113:29' */
    REV8[i] = r;
  }
}

/* Function for Chart: '<S1>/ZKDM FSM' */
static uint16_T MySimplifiedTestingM_apply_mode(const uint8_T b_in[2], const
  uint8_T REV8[256], uint8_T mode)
{
  uint16_T y;
  uint8_T b[2];
  uint8_T varargin_1;

  /* MATLAB Function 'apply_mode': '<S12>:112' */
  /* '<S12>:112:3' */
  b[0] = b_in[0];
  b[1] = b_in[1];

  /* '<S12>:112:5' */
  /* '<S12>:112:6' */
  /* '<S12>:112:7' */
  if ((mode & 1U) != 0U) {
    /* '<S12>:112:9' */
    /* '<S12>:112:10' */
    varargin_1 = b_in[0];
    varargin_1 = (uint8_T)~varargin_1;
    b[0] = varargin_1;
    varargin_1 = b_in[1];
    varargin_1 = (uint8_T)~varargin_1;
    b[1] = varargin_1;
  }

  if ((mode & 4U) != 0U) {
    /* '<S12>:112:13' */
    /* '<S12>:112:15' */
    b[0] = REV8[b[0]];
    b[1] = REV8[b[1]];
  }

  if ((mode & 2U) != 0U) {
    uint8_T b_idx_1;

    /* '<S12>:112:18' */
    /* '<S12>:112:19' */
    varargin_1 = b[1];
    b_idx_1 = b[0];
    b[0] = varargin_1;
    b[1] = b_idx_1;
  }

  /* '<S12>:112:23' */
  /* '<S12>:112:24' */
  memcpy((void *)&y, (void *)&b[0], (size_t)1 * sizeof(uint16_T));
  return y;
}

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTest_pcd2_flipcases(uint16_T pcd2, uint8_T out_modes[8],
  int32_T *out_labels_f1___dummy, int32_T *out_labels_f2___dummy, int32_T
  *out_labels_f3___dummy, int32_T *out_labels_f4___dummy, int32_T
  *out_labels_f5___dummy, int32_T *out_labels_f6___dummy, int32_T
  *out_labels_f7___dummy, int32_T *out_labels_f8___dummy, uint16_T out_values[8],
  uint16_T out_asArray[8])
{
  int32_T m;
  uint8_T b[2];
  static const uint8_T c[8] = { 0U, 1U, 4U, 2U, 6U, 5U, 3U, 7U };

  /* MATLAB Function 'pcd2_flipcases': '<S12>:111' */
  /* '<S12>:111:26' */
  memcpy((void *)&b[0], (void *)&pcd2, (size_t)2 * sizeof(uint8_T));

  /* '<S12>:111:16' */
  if (!MySimplifiedTestingModel_2_DW.REV8_not_empty) {
    /* '<S12>:111:19' */
    /* '<S12>:111:20' */
    MySimplifiedTesti_make_rev8_lut(MySimplifiedTestingModel_2_DW.REV8);
    MySimplifiedTestingModel_2_DW.REV8_not_empty = true;
  }

  /* '<S12>:111:26' */
  *out_labels_f1___dummy = 0;
  *out_labels_f2___dummy = 0;
  *out_labels_f3___dummy = 0;
  *out_labels_f4___dummy = 0;
  *out_labels_f5___dummy = 0;
  *out_labels_f6___dummy = 0;
  *out_labels_f7___dummy = 0;
  *out_labels_f8___dummy = 0;

  /* '<S12>:111:31' */
  /* '<S12>:111:32' */
  for (m = 0; m < 8; m++) {
    /* '<S12>:111:33' */
    out_values[m] = MySimplifiedTestingM_apply_mode(b,
      MySimplifiedTestingModel_2_DW.REV8, c[m]);
  }

  /* '<S12>:111:36' */
  /* '<S12>:111:37' */
  /* '<S12>:111:38' */
  /* '<S12>:111:39' */
  for (m = 0; m < 8; m++) {
    out_modes[m] = (uint8_T)m;
    out_asArray[m] = out_values[m];
  }
}

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTestingM_debug_cmnd(real_T setpoint, uint16_T cmnds[8])
{
  cell_0_MySimplifiedTestingMod_T expl_temp_0;
  real_T tmp_0;
  uint16_T expl_temp_1[8];
  uint16_T tmp;
  uint8_T expl_temp[8];

  /* MATLAB Function 'debug_cmnd': '<S12>:110' */
  /* '<S12>:110:8' */
  /* '<S12>:110:9' */
  /* '<S12>:110:10' */
  tmp_0 = rt_roundd_snf(setpoint * 163.84);
  if (tmp_0 < 65536.0) {
    if (tmp_0 >= 0.0) {
      tmp = (uint16_T)tmp_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  MySimplifiedTest_pcd2_flipcases(tmp, expl_temp, &expl_temp_0.f1.__dummy,
    &expl_temp_0.f2.__dummy, &expl_temp_0.f3.__dummy, &expl_temp_0.f4.__dummy,
    &expl_temp_0.f5.__dummy, &expl_temp_0.f6.__dummy, &expl_temp_0.f7.__dummy,
    &expl_temp_0.f8.__dummy, cmnds, expl_temp_1);

  /* '<S12>:110:11' */
}

/* Function for Chart: '<S1>/BUS MASTER FSM' */
static void MySimplifiedT_enter_atomic_IDLE(void)
{
  /* Entry 'IDLE': '<S3>:34' */
  MySimplifiedTestingModel_2_DW.currentDev = MySimplifiedTestingMod_DEV_NONE;
  MySimplifiedTestingModel_2_B.resp_ok_ZKDM = false;
  MySimplifiedTestingModel_2_B.resp_ok_THERMO = false;
  MySimplifiedTestingModel_2_B.resp_err_ZKDM = 0U;
  MySimplifiedTestingModel_2_B.resp_err_THERMO = 0U;
  MySimplifiedTestingModel_2_DW.err_ZKDM = 0U;
  MySimplifiedTestingModel_2_DW.err_THERMO = 0U;
  MySimplifiedTestingModel_2_B.grant_ZKDM = false;
  MySimplifiedTestingModel_2_B.grant_THERMO = false;
  MySimplifiedTestingModel_2_B.TX_Trigger = false;
  MySimplifiedTestingModel_2_B.TX_Len = 0U;
  MySimplifiedTestingModel_2_DW.rxCount = 0U;
}

/* Function for Chart: '<S1>/BUS MASTER FSM' */
static boolean_T MySimplifiedTestingModel_crc_ok(const uint8_T buf[127], uint8_T
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
static boolean_T MySimplifiedTestingMode_addr_ok(const uint8_T buf[127], uint8_T
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

/* Function for MATLAB Function: '<S1>/Create 8-Bytes Command' */
static real_T MySimplifiedTestingMode_bin2dec(const char_T s[8])
{
  real_T x;
  uint64_T a;
  uint64_T p2;
  int32_T first;
  int32_T idx;
  int32_T j;
  int32_T last;
  int32_T nbits;
  boolean_T b_signed;
  boolean_T hasPrefix;
  static const boolean_T b[128] = { false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  boolean_T exitg1;
  first = 1;
  b_signed = false;
  nbits = 112;
  hasPrefix = false;
  exitg1 = false;
  while ((!exitg1) && (first < 8)) {
    j = (uint8_T)s[first - 1];
    if ((j == 0) || b[j & 127]) {
      first++;
    } else {
      exitg1 = true;
    }
  }

  if ((s[first - 1] == '0') && (first < 8) && ((s[first] == 'b') || (s[first] ==
        'B'))) {
    first += 2;
    hasPrefix = true;
  }

  last = 8;
  exitg1 = false;
  while ((!exitg1) && (last > first)) {
    j = (uint8_T)s[last - 1];
    if ((j == 0) || b[j & 127]) {
      last--;
    } else {
      exitg1 = true;
    }
  }

  if (hasPrefix && (first > last)) {
    first -= 2;
  }

  idx = last - 1;
  while ((idx + 1 > first) && (s[idx] >= '0') && (s[idx] <= '9')) {
    idx--;
  }

  if ((s[idx] == 's') || (s[idx] == 'S')) {
    b_signed = true;
    if (idx + 2 == last) {
      nbits = (uint8_T)s[last - 1];
    } else if (idx + 3 == last) {
      nbits = ((uint8_T)s[idx + 1] - 48) * 10 + (uint8_T)s[last - 1];
    } else {
      nbits = 48;
    }

    last = idx;
  } else if ((s[idx] == 'u') || (s[idx] == 'U')) {
    if (idx + 2 == last) {
      nbits = (uint8_T)s[last - 1];
    } else if (idx + 3 == last) {
      nbits = ((uint8_T)s[idx + 1] - 48) * 10 + (uint8_T)s[last - 1];
    } else {
      nbits = 48;
    }

    last = idx;
  }

  idx = 0;
  p2 = 1ULL;
  a = 0ULL;
  exitg1 = false;
  while ((!exitg1) && (first < last)) {
    j = (uint8_T)s[first - 1];
    if ((j == 0) || b[j & 127]) {
      first++;
    } else {
      exitg1 = true;
    }
  }

  for (j = last; j >= first; j--) {
    char_T s_0;
    s_0 = s[j - 1];
    if (s_0 == '1') {
      a += p2;
      p2 += p2;
      idx++;
    } else if (s_0 == '0') {
      p2 += p2;
      idx++;
    }
  }

  if (b_signed) {
    if (nbits - 48 == 64) {
      x = (real_T)a;
    } else if ((nbits - 48 == idx) && (s[first - 1] == '1')) {
      x = (real_T)a - (real_T)p2;
    } else {
      x = (real_T)a;
    }
  } else {
    x = (real_T)a;
  }

  return x;
}

/* Model output function */
void MySimplifiedTestingModel_2_output(void)
{
  real_T u0;
  real_T u1;
  real_T u2;
  int32_T f;
  int32_T i;
  int32_T idx;
  int32_T k;
  uint32_T qY;
  int16_T x;
  uint16_T q14;
  uint16_T status_word;
  char_T pcd2binary[16];
  char_T sfull[16];
  char_T tmp;
  uint8_T pcd2split[2];
  uint8_T PCD1_1;
  uint8_T PCD1_2;
  uint8_T tmp_0;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T okCrc;

  /* DataTypeConversion: '<S1>/Cast To Boolean1' incorporates:
   *  Constant: '<S1>/Active'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean1 =
    (MySimplifiedTestingModel_2_P.Active_Value != 0.0);

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Constant: '<S1>/Setpoint'
   */
  u0 = MySimplifiedTestingModel_2_P.Setpoint_Value;
  u1 = MySimplifiedTestingModel_2_P.Saturation_LowerSat;
  u2 = MySimplifiedTestingModel_2_P.Saturation_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S1>/Saturation' */
    MySimplifiedTestingModel_2_B.Saturation = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S1>/Saturation' */
    MySimplifiedTestingModel_2_B.Saturation = u1;
  } else {
    /* Saturate: '<S1>/Saturation' */
    MySimplifiedTestingModel_2_B.Saturation = u0;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Memory: '<S1>/Memory' */
  MySimplifiedTestingModel_2_B.Memory =
    MySimplifiedTestingModel_2_DW.Memory_PreviousInput;

  /* Memory: '<S1>/Memory1' */
  MySimplifiedTestingModel_2_B.Memory1 =
    MySimplifiedTestingModel_2_DW.Memory1_PreviousInput;

  /* Memory: '<S1>/Memory3' */
  memcpy(&MySimplifiedTestingModel_2_B.Memory3[0],
         &MySimplifiedTestingModel_2_DW.Memory3_PreviousInput[0], 127U * sizeof
         (uint8_T));

  /* Memory: '<S1>/Memory2' */
  MySimplifiedTestingModel_2_B.Memory2 =
    MySimplifiedTestingModel_2_DW.Memory2_PreviousInput;

  /* Memory: '<S1>/Memory4' */
  MySimplifiedTestingModel_2_B.Memory4 =
    MySimplifiedTestingModel_2_DW.Memory4_PreviousInput;

  /* DataTypeConversion: '<S1>/Cast To Boolean' incorporates:
   *  Constant: '<S1>/Invalid CTW'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean =
    (MySimplifiedTestingModel_2_P.InvalidCTW_Value != 0.0);

  /* DataTypeConversion: '<S1>/Cast To Boolean5' incorporates:
   *  Constant: '<S1>/Constant16'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean5 =
    (MySimplifiedTestingModel_2_P.Constant16_Value != 0.0);

  /* Chart: '<S1>/ZKDM FSM' incorporates:
   *  Memory: '<S1>/Memory3'
   */
  if (MySimplifiedTestingModel_2_DW.temporalCounter_i2_i < 255U) {
    MySimplifiedTestingModel_2_DW.temporalCounter_i2_i++;
  }

  /* Gateway: RS485/ZKDM FSM */
  if (MySimplifiedTestingModel_2_DW.temporalCounter_i1 < 1U) {
    MySimplifiedTestingModel_2_DW.temporalCounter_i1++;
  }

  /* During: RS485/ZKDM FSM */
  if (MySimplifiedTestingModel_2_DW.is_active_c11_MySimplifiedTesti == 0U) {
    /* Entry: RS485/ZKDM FSM */
    MySimplifiedTestingModel_2_DW.is_active_c11_MySimplifiedTesti = 1U;

    /* Entry Internal: RS485/ZKDM FSM */
    /* Transition: '<S12>:24' */
    MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
      MySimplifiedTestingMo_IN_INIT_e;
    MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

    /* Entry 'INIT': '<S12>:23' */
    MySimplifiedTestingModel_2_B.expect_addr_ZKDM =
      MySimplifiedTestingModel_2_DW.fc_addr;
    MySimplifiedTestingModel_2_B.expect_len_ZKDM = 8U;
    MySimplifiedTestingModel_2_B.expect_crc_kind_ZKDM = 0U;
    MySimplifiedTestingModel_2_B.freq_rel = 0.0;
    MySimplifiedTestingModel_2_B.fu_ctrl_ready = false;
    MySimplifiedTestingModel_2_B.fu_ready = false;
    MySimplifiedTestingModel_2_B.fault_trip = false;
    MySimplifiedTestingModel_2_B.fault_no_trip = false;
    MySimplifiedTestingModel_2_B.bus_ctrl_active = false;
    MySimplifiedTestingModel_2_B.req_valid = false;
    MySimplifiedTestingModel_2_B.req_len = 0U;
    MySimplifiedTestingModel_2_DW.comm_err_count = 0U;
  } else {
    switch (MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel) {
     case MySimplifiedTesting_IN_COOLDOWN:
      /* During 'COOLDOWN': '<S12>:37' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1 >= 1) {
        /* Transition: '<S12>:39' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_READY;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_i = 0U;

        /* Entry 'READY': '<S12>:25' */
        MySimplifiedTestingModel_2_B.req_valid = false;
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT = false;
      }
      break;

     case MySimplifiedTesti_IN_HANDLE_ERR:
      /* During 'HANDLE_ERR': '<S12>:32' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1 >= 1) {
        /* Transition: '<S12>:38' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesting_IN_COOLDOWN;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

        /* Entry 'COOLDOWN': '<S12>:37' */
      }
      break;

     case MySimplifiedTestingMo_IN_INIT_e:
      /* During 'INIT': '<S12>:23' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1 >= 1) {
        /* Transition: '<S12>:26' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_READY;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_i = 0U;

        /* Entry 'READY': '<S12>:25' */
        MySimplifiedTestingModel_2_B.req_valid = false;
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT = false;
      } else {
        MySimplifiedTestingModel_2_B.expect_addr_ZKDM =
          MySimplifiedTestingModel_2_DW.fc_addr;
        MySimplifiedTestingModel_2_B.expect_len_ZKDM = 8U;
        MySimplifiedTestingModel_2_B.expect_crc_kind_ZKDM = 0U;
        MySimplifiedTestingModel_2_B.freq_rel = 0.0;
        MySimplifiedTestingModel_2_B.fu_ctrl_ready = false;
        MySimplifiedTestingModel_2_B.fu_ready = false;
        MySimplifiedTestingModel_2_B.fault_trip = false;
        MySimplifiedTestingModel_2_B.fault_no_trip = false;
        MySimplifiedTestingModel_2_B.bus_ctrl_active = false;
        MySimplifiedTestingModel_2_B.req_valid = false;
        MySimplifiedTestingModel_2_B.req_len = 0U;
        MySimplifiedTestingModel_2_DW.comm_err_count = 0U;
      }
      break;

     case MySimplifiedTestingMod_IN_PARSE:
      /* During 'PARSE': '<S12>:30' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i2_i >=
          MySimplifiedTestingModel_2_DW.min_period_ms) {
        /* Transition: '<S12>:41' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesting_IN_COOLDOWN;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

        /* Entry 'COOLDOWN': '<S12>:37' */
      }
      break;

     case MySimplifiedTestingMod_IN_READY:
      /* During 'READY': '<S12>:25' */
      if (MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT) {
        /* Transition: '<S12>:28' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_WAIT_GRANT;

        /* Entry 'WAIT_GRANT': '<S12>:27' */
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT = false;
      } else if (MySimplifiedTestingModel_2_DW.temporalCounter_i2_i >=
                 MySimplifiedTestingModel_2_DW.min_period_ms) {
        MySimplifiedTestingModel_2_fcn
          (MySimplifiedTestingModel_2_B.CastToBoolean,
           MySimplifiedTestingModel_2_B.CastToBoolean1,
           MySimplifiedTestingModel_2_B.Saturation,
           MySimplifiedTestingModel_2_B.req_bytes);
        MySimplifiedTestingModel_2_B.debug_pcd2[0] =
          MySimplifiedTestingModel_2_B.req_bytes[5];
        MySimplifiedTestingModel_2_B.debug_pcd2[1] =
          MySimplifiedTestingModel_2_B.req_bytes[6];
        MySimplifiedTestingM_debug_cmnd(MySimplifiedTestingModel_2_B.Saturation,
          MySimplifiedTestingModel_2_B.debug_command);
        MySimplifiedTestingModel_2_B.req_len =
          MySimplifiedTestingModel_2_DW.tx_len;
        MySimplifiedTestingModel_2_B.expect_addr_ZKDM =
          MySimplifiedTestingModel_2_B.req_bytes[2];
        MySimplifiedTestingModel_2_B.expect_len_ZKDM = 8U;
        MySimplifiedTestingModel_2_B.expect_crc_kind_ZKDM =
          MySimplifiedTestingModel_2_B.req_bytes[7];
        MySimplifiedTestingModel_2_B.req_valid = true;
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT = true;
      }
      break;

     case MySimplifiedTesti_IN_WAIT_GRANT:
      /* During 'WAIT_GRANT': '<S12>:27' */
      if (MySimplifiedTestingModel_2_B.Memory) {
        /* Transition: '<S12>:33' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestin_IN_WAIT_RESP;

        /* Entry 'WAIT_RESP': '<S12>:29' */
      } else if (MySimplifiedTestingModel_2_B.Memory2 > 0) {
        /* Transition: '<S12>:34' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_HANDLE_ERR;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

        /* Entry 'HANDLE_ERR': '<S12>:32' */
        qY = MySimplifiedTestingModel_2_DW.comm_err_count + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        MySimplifiedTestingModel_2_DW.comm_err_count = (uint16_T)qY;
      }
      break;

     default:
      /* During 'WAIT_RESP': '<S12>:29' */
      if (MySimplifiedTestingModel_2_B.Memory1) {
        /* Transition: '<S12>:35' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_PARSE;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_i = 0U;

        /* Entry 'PARSE': '<S12>:30' */
        MySimplifiedTest_parse_fc_reply(&MySimplifiedTestingModel_2_B.Memory3[0],
          &PCD1_1, &PCD1_2, &MySimplifiedTestingModel_2_B.freq_rel, &status_word,
          &MySimplifiedTestingModel_2_B.fu_ctrl_ready,
          &MySimplifiedTestingModel_2_B.fu_ready,
          &MySimplifiedTestingModel_2_B.fault_trip,
          &MySimplifiedTestingModel_2_B.fault_no_trip,
          &MySimplifiedTestingModel_2_B.bus_ctrl_active, &okCrc);
        if (!okCrc) {
          qY = MySimplifiedTestingModel_2_DW.comm_err_count + 1U;
          if (qY > 65535U) {
            qY = 65535U;
          }

          MySimplifiedTestingModel_2_DW.comm_err_count = (uint16_T)qY;
        }
      } else if (MySimplifiedTestingModel_2_B.Memory2 > 0) {
        /* Transition: '<S12>:36' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_HANDLE_ERR;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

        /* Entry 'HANDLE_ERR': '<S12>:32' */
        qY = MySimplifiedTestingModel_2_DW.comm_err_count + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        MySimplifiedTestingModel_2_DW.comm_err_count = (uint16_T)qY;
      } else {
        MySimplifiedTestingModel_2_B.req_valid = false;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/ZKDM FSM' */

  /* S-Function (rti_commonblock): '<S8>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1202SER #1 Unit:GENSER Group:STATUS */
  MySimplifiedTestingModel_2_B.SFunction1_o1_p[0] = rtiDS1202SER_B1_Ser[0]
    ->lineStatusReg.Bit.DSSER_RECEIVE_DATA_RDY;
  MySimplifiedTestingModel_2_B.SFunction1_o1_p[1] = rtiDS1202SER_B1_Ser[0]
    ->lineStatusReg.Bit.DSSER_OVERRUN_ERR;
  MySimplifiedTestingModel_2_B.SFunction1_o1_p[2] = rtiDS1202SER_B1_Ser[0]
    ->lineStatusReg.Bit.DSSER_PARITY_ERR;
  MySimplifiedTestingModel_2_B.SFunction1_o1_p[3] = rtiDS1202SER_B1_Ser[0]
    ->lineStatusReg.Bit.DSSER_FRAMING_ERR;
  MySimplifiedTestingModel_2_B.SFunction1_o1_p[4] = rtiDS1202SER_B1_Ser[0]
    ->lineStatusReg.Bit.DSSER_BREAK_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o1_p[5] = rtiDS1202SER_B1_Ser[0]
    ->lineStatusReg.Bit.DSSER_THR_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o1_p[6] = rtiDS1202SER_B1_Ser[0]
    ->lineStatusReg.Bit.DSSER_THR_TSR_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o1_p[7] = rtiDS1202SER_B1_Ser[0]
    ->lineStatusReg.Bit.DSSER_FIFO_DATA_ERR;
  MySimplifiedTestingModel_2_B.SFunction1_o2_i[0] = rtiDS1202SER_B1_Ser[0]
    ->modemStatusReg.Bit.DSSER_CTS_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o2_i[1] = rtiDS1202SER_B1_Ser[0]
    ->modemStatusReg.Bit.DSSER_DSR_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o2_i[2] = rtiDS1202SER_B1_Ser[0]
    ->modemStatusReg.Bit.DSSER_RI_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o2_i[3] = rtiDS1202SER_B1_Ser[0]
    ->modemStatusReg.Bit.DSSER_CD_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o2_i[4] = rtiDS1202SER_B1_Ser[0]
    ->modemStatusReg.Bit.DSSER_RTS_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o2_i[5] = rtiDS1202SER_B1_Ser[0]
    ->modemStatusReg.Bit.DSSER_DTR_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o2_i[6] = rtiDS1202SER_B1_Ser[0]
    ->modemStatusReg.Bit.DSSER_OP1_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o2_i[7] = rtiDS1202SER_B1_Ser[0]
    ->modemStatusReg.Bit.DSSER_OP2_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o3_h[0] = rtiDS1202SER_B1_Ser[0]
    ->intStatusReg.Bit.DSSER_INT_STATUS;
  MySimplifiedTestingModel_2_B.SFunction1_o3_h[1] = rtiDS1202SER_B1_Ser[0]
    ->intStatusReg.Bit.DSSER_INT_PRIORITY_BIT0;
  MySimplifiedTestingModel_2_B.SFunction1_o3_h[2] = rtiDS1202SER_B1_Ser[0]
    ->intStatusReg.Bit.DSSER_INT_PRIORITY_BIT1;
  MySimplifiedTestingModel_2_B.SFunction1_o3_h[3] = rtiDS1202SER_B1_Ser[0]
    ->intStatusReg.Bit.DSSER_INT_PRIORITY_BIT2;
  MySimplifiedTestingModel_2_B.SFunction1_o3_h[4] = rtiDS1202SER_B1_Ser[0]
    ->intStatusReg.Bit.DSSER_BIT4;
  MySimplifiedTestingModel_2_B.SFunction1_o3_h[5] = rtiDS1202SER_B1_Ser[0]
    ->intStatusReg.Bit.DSSER_BIT5;
  MySimplifiedTestingModel_2_B.SFunction1_o3_h[6] = rtiDS1202SER_B1_Ser[0]
    ->intStatusReg.Bit.DSSER_FIFO_STATUS_BIT0;
  MySimplifiedTestingModel_2_B.SFunction1_o3_h[7] = rtiDS1202SER_B1_Ser[0]
    ->intStatusReg.Bit.DSSER_FIFO_STATUS_BIT1;

  /* S-Function (rti_commonblock): '<S5>/S-Function1' incorporates:
   *  Constant: '<S1>/Constant19'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1202SER #1 Unit:GENSER Group:RECEIVE */
  {
    UInt32 rxFifoLevel;
    UInt32 bytesRefNumOf;
    bytesRefNumOf = (MySimplifiedTestingModel_2_P.Constant19_Value <= 127) ?
      MySimplifiedTestingModel_2_P.Constant19_Value : 127;
    rxFifoLevel = dsser_receive_fifo_level(rtiDS1202SER_B1_Ser[1]);
    if (rxFifoLevel >= bytesRefNumOf) {
      MySimplifiedTestingModel_2_B.SFunction1_o3 = dsser_receive
        (rtiDS1202SER_B1_Ser[1], bytesRefNumOf, (UInt8 *)
         &MySimplifiedTestingModel_2_B.SFunction1_o1[0], (UInt32 *)
         &MySimplifiedTestingModel_2_B.SFunction1_o2);
    } else {
      UInt32 *temp = (UInt32 *) &MySimplifiedTestingModel_2_B.SFunction1_o2;
      *temp = 0;
      MySimplifiedTestingModel_2_B.SFunction1_o3 = DSSER_NO_DATA;
    }
  }

  /* DataTypeConversion: '<S1>/Cast' */
  MySimplifiedTestingModel_2_B.Cast_g = (uint8_T)
    MySimplifiedTestingModel_2_B.SFunction1_o2;

  /* Memory: '<S1>/Memory5' */
  MySimplifiedTestingModel_2_B.Memory5 =
    MySimplifiedTestingModel_2_DW.Memory5_PreviousInput;

  /* Clock: '<S1>/Clock' */
  MySimplifiedTestingModel_2_B.Clock = MySimplifiedTestingModel_2_M->Timing.t[0];

  /* Memory: '<S1>/Memory8' */
  MySimplifiedTestingModel_2_B.Memory8 =
    MySimplifiedTestingModel_2_DW.Memory8_PreviousInput;

  /* Memory: '<S1>/Memory10' */
  MySimplifiedTestingModel_2_B.Memory10 =
    MySimplifiedTestingModel_2_DW.Memory10_PreviousInput;

  /* DataTypeConversion: '<S1>/Cast To Boolean6' incorporates:
   *  Constant: '<S1>/TX on'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean6 =
    (MySimplifiedTestingModel_2_P.TXon_Value != 0.0);

  /* DataTypeConversion: '<S1>/Cast To Boolean7' incorporates:
   *  Constant: '<S1>/RX on'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean7 =
    (MySimplifiedTestingModel_2_P.RXon_Value != 0.0);

  /* Memory: '<S1>/Memory9' */
  MySimplifiedTestingModel_2_B.Memory9 =
    MySimplifiedTestingModel_2_DW.Memory9_PreviousInput;

  /* Memory: '<S1>/Memory7' */
  MySimplifiedTestingModel_2_B.Memory7 =
    MySimplifiedTestingModel_2_DW.Memory7_PreviousInput;
  for (i = 0; i < 127; i++) {
    /* Memory: '<S1>/Memory6' */
    MySimplifiedTestingModel_2_B.Memory6[i] =
      MySimplifiedTestingModel_2_DW.Memory6_PreviousInput[i];

    /* SignalConversion generated from: '<S3>/ SFunction ' incorporates:
     *  Chart: '<S1>/BUS MASTER FSM'
     */
    MySimplifiedTestingModel_2_B.TmpSignalConversionAtSFunctionI[i] = 0U;
  }

  /* Chart: '<S1>/BUS MASTER FSM' incorporates:
   *  Memory: '<S1>/Memory6'
   *  S-Function (rti_commonblock): '<S5>/S-Function1'
   *  SignalConversion generated from: '<S3>/ SFunction '
   */
  if (MySimplifiedTestingModel_2_DW.temporalCounter_i2 < 65535U) {
    MySimplifiedTestingModel_2_DW.temporalCounter_i2++;
  }

  /* Gateway: RS485/BUS MASTER FSM */
  if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_p < 1U) {
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_p++;
  }

  /* During: RS485/BUS MASTER FSM */
  if (MySimplifiedTestingModel_2_DW.is_active_c6_MySimplifiedTestin == 0U) {
    /* Entry: RS485/BUS MASTER FSM */
    MySimplifiedTestingModel_2_DW.is_active_c6_MySimplifiedTestin = 1U;

    /* Entry Internal: RS485/BUS MASTER FSM */
    /* Transition: '<S3>:33' */
    MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
      MySimplifiedTestingMode_IN_INIT;
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_p = 0U;

    /* Entry 'INIT': '<S3>:32' */
    MySimplifiedTestingModel_2_B.TX_Trigger = false;
    MySimplifiedTestingModel_2_B.TX_Len = 0U;
    MySimplifiedTestingModel_2_B.grant_ZKDM = false;
    MySimplifiedTestingModel_2_B.grant_THERMO = false;
    MySimplifiedTestingModel_2_B.resp_ok_ZKDM = false;
    MySimplifiedTestingModel_2_B.resp_ok_THERMO = false;
    MySimplifiedTestingModel_2_DW.err_ZKDM = 0U;
    MySimplifiedTestingModel_2_DW.err_THERMO = 0U;
    MySimplifiedTestingModel_2_DW.currentDev = MySimplifiedTestingMod_DEV_NONE;
    MySimplifiedTestingModel_2_DW.retry = 0U;
    MySimplifiedTestingModel_2_DW.pollCounter = 0U;
    MySimplifiedTestingModel_2_DW.rxCount = 0U;
  } else {
    guard1 = false;
    switch (MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_) {
     case MySimplifiedTestingM_IN_BACKOFF:
      /* During 'BACKOFF': '<S3>:65' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i2 >=
          MySimplifiedTestingModel_2_DW.interGap_ms) {
        /* Transition: '<S3>:67' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestingMode_IN_IDLE;
        MySimplifiedT_enter_atomic_IDLE();
      }
      break;

     case MySimplifiedTest_IN_DELIVER_ERR:
      /* During 'DELIVER_ERR': '<S3>:56' */
      /* Transition: '<S3>:64' */
      MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifi_IN_RETRY_OR_BACKOFF1;
      MySimplifiedTestingModel_2_DW.temporalCounter_i1_p = 0U;
      break;

     case MySimplifiedTe_IN_DELIVER_ERROR:
      /* During 'DELIVER_ERROR': '<S3>:436' */
      /* Transition: '<S3>:440' */
      MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTestingM_IN_BACKOFF;
      MySimplifiedTestingModel_2_DW.temporalCounter_i2 = 0U;

      /* Entry 'BACKOFF': '<S3>:65' */
      if (MySimplifiedTestingModel_2_DW.currentDev ==
          MySimplifiedTestingMod_DEV_ZKDM) {
        i = (int32_T)(MySimplifiedTestingModel_2_DW.pollCounter + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        idx = MySimplifiedTestingModel_2_DW.pollThermoEvery;
        qY = (uint32_T)idx - 1U;
        if (qY > (uint32_T)idx) {
          qY = 0U;
        }

        idx = (int32_T)qY;
        PCD1_1 = (uint8_T)i;
        PCD1_2 = (uint8_T)idx;
        if (PCD1_1 <= PCD1_2) {
          MySimplifiedTestingModel_2_DW.pollCounter = PCD1_1;
        } else {
          MySimplifiedTestingModel_2_DW.pollCounter = PCD1_2;
        }
      }
      break;

     case MySimplifie_IN_DELIVER_OK_CLEAR:
      /* During 'DELIVER_OK_CLEAR': '<S3>:60' */
      /* Transition: '<S3>:333' */
      MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTestingM_IN_BACKOFF;
      MySimplifiedTestingModel_2_DW.temporalCounter_i2 = 0U;

      /* Entry 'BACKOFF': '<S3>:65' */
      if (MySimplifiedTestingModel_2_DW.currentDev ==
          MySimplifiedTestingMod_DEV_ZKDM) {
        i = (int32_T)(MySimplifiedTestingModel_2_DW.pollCounter + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        idx = MySimplifiedTestingModel_2_DW.pollThermoEvery;
        qY = (uint32_T)idx - 1U;
        if (qY > (uint32_T)idx) {
          qY = 0U;
        }

        idx = (int32_T)qY;
        PCD1_1 = (uint8_T)i;
        PCD1_2 = (uint8_T)idx;
        if (PCD1_1 <= PCD1_2) {
          MySimplifiedTestingModel_2_DW.pollCounter = PCD1_1;
        } else {
          MySimplifiedTestingModel_2_DW.pollCounter = PCD1_2;
        }
      }
      break;

     case MySimplifie_IN_DELIVER_OK_PULSE:
      /* During 'DELIVER_OK_PULSE': '<S3>:59' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_p >= 1) {
        /* Transition: '<S3>:61' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifie_IN_DELIVER_OK_CLEAR;

        /* Entry 'DELIVER_OK_CLEAR': '<S3>:60' */
        MySimplifiedTestingModel_2_B.resp_ok_ZKDM = false;
        MySimplifiedTestingModel_2_B.resp_ok_THERMO = false;
      }
      break;

     case MySimplifiedTestingMode_IN_IDLE:
      MySimplifiedTestingModel_2_B.TX_Trigger = false;

      /* During 'IDLE': '<S3>:34' */
      if ((MySimplifiedTestingModel_2_DW.currentDev ==
           MySimplifiedTestingMod_DEV_ZKDM) ||
          (MySimplifiedTestingModel_2_DW.currentDev ==
           MySimplifiedTestingM_DEV_THERMO)) {
        /* Transition: '<S3>:39' */
        /* Transition: '<S3>:40' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTesting_IN_LOAD_REQ;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1_p = 0U;

        /* Entry 'LOAD_REQ': '<S3>:36' */
        if (MySimplifiedTestingModel_2_DW.currentDev ==
            MySimplifiedTestingMod_DEV_ZKDM) {
          memcpy(&MySimplifiedTestingModel_2_DW.chosen_req[0],
                 &MySimplifiedTestingModel_2_B.Memory6[0], 127U * sizeof(uint8_T));
          MySimplifiedTestingModel_2_DW.chosen_len =
            MySimplifiedTestingModel_2_B.Memory7;
          MySimplifiedTestingModel_2_DW.chosen_expect_addr =
            MySimplifiedTestingModel_2_B.Memory8;
          MySimplifiedTestingModel_2_DW.chosen_expect_len =
            MySimplifiedTestingModel_2_B.Memory9;
          MySimplifiedTestingModel_2_DW.timeout_ms =
            MySimplifiedTestingModel_2_DW.timeout_ms_ZKDM;
          MySimplifiedTestingModel_2_B.grant_ZKDM = true;
          MySimplifiedTestingModel_2_B.grant_THERMO = false;
        } else if (MySimplifiedTestingModel_2_DW.currentDev ==
                   MySimplifiedTestingM_DEV_THERMO) {
          memcpy(&MySimplifiedTestingModel_2_DW.chosen_req[0],
                 &MySimplifiedTestingModel_2_B.TmpSignalConversionAtSFunctionI[0],
                 127U * sizeof(uint8_T));
          MySimplifiedTestingModel_2_DW.chosen_len = 0U;
          MySimplifiedTestingModel_2_DW.chosen_expect_addr = 0U;
          MySimplifiedTestingModel_2_DW.chosen_expect_len = 0U;
          MySimplifiedTestingModel_2_DW.timeout_ms =
            MySimplifiedTestingModel_2_DW.timeout_ms_THERMO;
          MySimplifiedTestingModel_2_B.grant_ZKDM = false;
          MySimplifiedTestingModel_2_B.grant_THERMO = true;
        }

        memcpy(&MySimplifiedTestingModel_2_B.TX_Data[0],
               &MySimplifiedTestingModel_2_DW.chosen_req[0], 127U * sizeof
               (uint8_T));
        MySimplifiedTestingModel_2_B.TX_Len =
          MySimplifiedTestingModel_2_DW.chosen_len;
        MySimplifiedTestingModel_2_DW.retry = 0U;
        MySimplifiedTestingModel_2_DW.rxCount = 0U;
      } else if (MySimplifiedTestingModel_2_B.Memory5) {
        MySimplifiedTestingModel_2_DW.currentDev =
          MySimplifiedTestingMod_DEV_ZKDM;
      } else {
        MySimplifiedTestingModel_2_DW.currentDev =
          MySimplifiedTestingMod_DEV_NONE;
      }
      break;

     case MySimplifiedTestingMode_IN_INIT:
      MySimplifiedTestingModel_2_B.TX_Trigger = false;

      /* During 'INIT': '<S3>:32' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_p >= 1) {
        /* Transition: '<S3>:35' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestingMode_IN_IDLE;
        MySimplifiedT_enter_atomic_IDLE();
      }
      break;

     case MySimplifiedTesting_IN_LOAD_REQ:
      /* During 'LOAD_REQ': '<S3>:36' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_p >= 1) {
        /* Transition: '<S3>:44' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestin_IN_WAIT_THRE;
      }
      break;

     case MySimplifi_IN_RETRY_OR_BACKOFF1:
      /* During 'RETRY_OR_BACKOFF1': '<S3>:278' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_p >= 1) {
        /* Transition: '<S3>:431' */
        memset(&MySimplifiedTestingModel_2_DW.rxBuf[0], 0, 127U * sizeof(uint8_T));
        MySimplifiedTestingModel_2_DW.rxCount = 0U;
        if (MySimplifiedTestingModel_2_DW.retry <
            MySimplifiedTestingModel_2_DW.maxRetry) {
          /* Transition: '<S3>:266' */
          /* Transition: '<S3>:268' */
          i = (int32_T)(MySimplifiedTestingModel_2_DW.retry + 1U);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          MySimplifiedTestingModel_2_DW.retry = (uint8_T)i;

          /* Transition: '<S3>:277' */
          MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
            MySimplifiedTestin_IN_WAIT_THRE;
        } else {
          /* Transition: '<S3>:267' */
          /* Transition: '<S3>:270' */
          /* Transition: '<S3>:439' */
          MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
            MySimplifiedTe_IN_DELIVER_ERROR;

          /* Entry 'DELIVER_ERROR': '<S3>:436' */
          if (MySimplifiedTestingModel_2_DW.currentDev ==
              MySimplifiedTestingMod_DEV_ZKDM) {
            MySimplifiedTestingModel_2_B.resp_err_ZKDM =
              MySimplifiedTestingModel_2_DW.err_ZKDM;
          } else {
            MySimplifiedTestingModel_2_B.resp_err_THERMO =
              MySimplifiedTestingModel_2_DW.err_THERMO;
          }
        }
      }
      break;

     case MySimplifiedTesting_IN_TX_CLEAR:
      MySimplifiedTestingModel_2_B.TX_Trigger = false;

      /* During 'TX_CLEAR': '<S3>:50' */
      /* Transition: '<S3>:54' */
      MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifiedTesting_IN_WAIT_RX2;
      MySimplifiedTestingModel_2_DW.temporalCounter_i2 = 0U;
      break;

     case MySimplifiedTesting_IN_TX_PULSE:
      MySimplifiedTestingModel_2_B.TX_Trigger = true;

      /* During 'TX_PULSE': '<S3>:46' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_p >= 1) {
        /* Transition: '<S3>:51' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTesting_IN_TX_CLEAR;

        /* Entry 'TX_CLEAR': '<S3>:50' */
        MySimplifiedTestingModel_2_B.TX_Trigger = false;
      }
      break;

     case MySimplifiedTestin_IN_VALIDATE1:
      /* During 'VALIDATE1': '<S3>:258' */
      break;

     case MySimplifiedTesting_IN_WAIT_RX2:
      /* During 'WAIT_RX2': '<S3>:367' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i2 >=
          MySimplifiedTestingModel_2_DW.timeout_ms) {
        /* Transition: '<S3>:57' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTest_IN_DELIVER_ERR;

        /* Entry 'DELIVER_ERR': '<S3>:56' */
        if (MySimplifiedTestingModel_2_DW.currentDev ==
            MySimplifiedTestingMod_DEV_ZKDM) {
          MySimplifiedTestingModel_2_DW.err_ZKDM =
            MySimplifiedTesting_ERR_TIMEOUT;
        } else {
          MySimplifiedTestingModel_2_DW.err_THERMO =
            MySimplifiedTesting_ERR_TIMEOUT;
        }
      } else {
        /* Transition: '<S3>:390' */
        i = (int32_T)((uint32_T)MySimplifiedTestingModel_2_DW.rxCount +
                      MySimplifiedTestingModel_2_B.Cast_g);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        okCrc = ((i <= 127) && (MySimplifiedTestingModel_2_B.Cast_g > 0));
        if (okCrc) {
          /* Transition: '<S3>:391' */
          /* Transition: '<S3>:393' */
          if (MySimplifiedTestingModel_2_B.Cast_g < 1) {
            idx = -1;
          } else {
            idx = MySimplifiedTestingModel_2_B.Cast_g - 1;
          }

          i = (int32_T)(MySimplifiedTestingModel_2_DW.rxCount + 1U);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          PCD1_1 = (uint8_T)i;
          i = (int32_T)((uint32_T)MySimplifiedTestingModel_2_DW.rxCount +
                        MySimplifiedTestingModel_2_B.Cast_g);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          PCD1_2 = (uint8_T)i;
          if (PCD1_1 > PCD1_2) {
            f = 1;
          } else {
            f = PCD1_1;
          }

          for (i = 0; i <= idx; i++) {
            MySimplifiedTestingModel_2_DW.rxBuf[(f + i) - 1] =
              MySimplifiedTestingModel_2_B.SFunction1_o1[i];
          }

          i = (int32_T)((uint32_T)MySimplifiedTestingModel_2_DW.rxCount +
                        MySimplifiedTestingModel_2_B.Cast_g);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          MySimplifiedTestingModel_2_DW.rxCount = (uint8_T)i;

          /* Transition: '<S3>:421' */
        } else {
          i = (int32_T)((uint32_T)MySimplifiedTestingModel_2_DW.rxCount +
                        MySimplifiedTestingModel_2_B.Cast_g);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          if (i > 127) {
            /* Transition: '<S3>:401' */
            if (MySimplifiedTestingModel_2_DW.currentDev ==
                MySimplifiedTestingMod_DEV_ZKDM) {
              /* Transition: '<S3>:402' */
              /* Transition: '<S3>:411' */
              MySimplifiedTestingModel_2_DW.err_ZKDM =
                MySimplifiedTestin_ERR_OVERFLOW;

              /* Transition: '<S3>:412' */
            } else {
              /* Transition: '<S3>:403' */
              MySimplifiedTestingModel_2_DW.err_THERMO =
                MySimplifiedTestin_ERR_OVERFLOW;
            }

            /* Transition: '<S3>:415' */
            guard1 = true;
          } else if (MySimplifiedTestingModel_2_DW.rxCount >=
                     MySimplifiedTestingModel_2_DW.chosen_expect_len) {
            /* Transition: '<S3>:58' */
            /* Transition: '<S3>:257' */
            okCrc = MySimplifiedTestingModel_crc_ok
              (MySimplifiedTestingModel_2_DW.rxBuf,
               MySimplifiedTestingModel_2_DW.rxCount);
            if (!MySimplifiedTestingMode_addr_ok
                (MySimplifiedTestingModel_2_DW.rxBuf,
                 MySimplifiedTestingModel_2_DW.rxCount,
                 MySimplifiedTestingModel_2_DW.chosen_expect_addr)) {
              /* Transition: '<S3>:183' */
              /* Transition: '<S3>:207' */
              if (MySimplifiedTestingModel_2_DW.currentDev ==
                  MySimplifiedTestingMod_DEV_ZKDM) {
                /* Transition: '<S3>:208' */
                /* Transition: '<S3>:210' */
                MySimplifiedTestingModel_2_DW.err_ZKDM =
                  MySimplifiedTestin_ERR_BAD_ADDR;

                /* Transition: '<S3>:211' */
              } else {
                /* Transition: '<S3>:209' */
                MySimplifiedTestingModel_2_DW.err_THERMO =
                  MySimplifiedTestin_ERR_BAD_ADDR;
              }

              /* Transition: '<S3>:212' */
              /* Transition: '<S3>:194' */
              /* Transition: '<S3>:193' */
              /* Transition: '<S3>:253' */
              guard1 = true;

              /* Transition: '<S3>:184' */
            } else if (!MySimplifiedTestingModel_len_ok
                       (MySimplifiedTestingModel_2_DW.rxCount,
                        MySimplifiedTestingModel_2_DW.chosen_expect_len)) {
              /* Transition: '<S3>:186' */
              /* Transition: '<S3>:218' */
              if (MySimplifiedTestingModel_2_DW.currentDev ==
                  MySimplifiedTestingMod_DEV_ZKDM) {
                /* Transition: '<S3>:219' */
                /* Transition: '<S3>:225' */
                MySimplifiedTestingModel_2_DW.err_ZKDM =
                  MySimplifiedTesting_ERR_BAD_LEN;

                /* Transition: '<S3>:222' */
              } else {
                /* Transition: '<S3>:228' */
                MySimplifiedTestingModel_2_DW.err_THERMO =
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
              if (MySimplifiedTestingModel_2_DW.currentDev ==
                  MySimplifiedTestingMod_DEV_ZKDM) {
                /* Transition: '<S3>:230' */
                /* Transition: '<S3>:236' */
                MySimplifiedTestingModel_2_DW.err_ZKDM =
                  MySimplifiedTesting_ERR_BAD_CRC;

                /* Transition: '<S3>:233' */
              } else {
                /* Transition: '<S3>:239' */
                MySimplifiedTestingModel_2_DW.err_THERMO =
                  MySimplifiedTesting_ERR_BAD_CRC;
              }

              /* Transition: '<S3>:237' */
              /* Transition: '<S3>:253' */
              guard1 = true;
            } else {
              /* Transition: '<S3>:252' */
              memcpy(&MySimplifiedTestingModel_2_B.resp_data[0],
                     &MySimplifiedTestingModel_2_DW.rxBuf[0], 127U * sizeof
                     (uint8_T));
              MySimplifiedTestingModel_2_B.resp_len =
                MySimplifiedTestingModel_2_DW.rxCount;
              if (MySimplifiedTestingModel_2_DW.currentDev ==
                  MySimplifiedTestingMod_DEV_ZKDM) {
                /* Transition: '<S3>:242' */
                /* Transition: '<S3>:244' */
                MySimplifiedTestingModel_2_B.resp_ok_ZKDM = true;

                /* Transition: '<S3>:245' */
              } else {
                /* Transition: '<S3>:243' */
                MySimplifiedTestingModel_2_B.resp_ok_THERMO = true;
              }

              /* Transition: '<S3>:246' */
              /* Transition: '<S3>:195' */
              MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
                MySimplifie_IN_DELIVER_OK_PULSE;
              MySimplifiedTestingModel_2_DW.temporalCounter_i1_p = 0U;
            }
          }
        }
      }
      break;

     case MySimplifiedT_IN_WAIT_RX_SWITCH:
      /* During 'WAIT_RX_SWITCH': '<S3>:443' */
      if (MySimplifiedTestingModel_2_B.CastToBoolean6) {
        /* Transition: '<S3>:446' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestin_IN_WAIT_THRE;
      } else if (MySimplifiedTestingModel_2_B.CastToBoolean7) {
        /* Transition: '<S3>:445' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTesting_IN_WAIT_RX2;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2 = 0U;
      }
      break;

     default:
      /* During 'WAIT_THRE': '<S3>:42' */
      okCrc = (MySimplifiedTestingModel_2_B.SFunction1_o1_p[5] &&
               MySimplifiedTestingModel_2_B.CastToBoolean6);
      if (okCrc) {
        /* Transition: '<S3>:47' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTesting_IN_TX_PULSE;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1_p = 0U;

        /* Entry 'TX_PULSE': '<S3>:46' */
        MySimplifiedTestingModel_2_B.TX_Trigger = true;
      } else if (!MySimplifiedTestingModel_2_B.CastToBoolean6) {
        /* Transition: '<S3>:444' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedT_IN_WAIT_RX_SWITCH;

        /* Entry 'WAIT_RX_SWITCH': '<S3>:443' */
      }
      break;
    }

    if (guard1) {
      MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
        MySimplifi_IN_RETRY_OR_BACKOFF1;
      MySimplifiedTestingModel_2_DW.temporalCounter_i1_p = 0U;
    }
  }

  /* MATLAB Function: '<S1>/Create 8-Bytes Command' */
  /* MATLAB Function 'RS485/Create 8-Bytes Command': '<S4>:1' */
  /* '<S4>:1:47' */
  memset(&MySimplifiedTestingModel_2_B.command[0], 0, 127U * sizeof(uint8_T));

  /* '<S4>:1:48' */
  MySimplifiedTestingModel_2_B.command[0] = 2U;

  /* '<S4>:1:49' */
  MySimplifiedTestingModel_2_B.command[1] = 6U;

  /* '<S4>:1:50' */
  MySimplifiedTestingModel_2_B.command[2] = 125U;

  /* '<S4>:1:52' */
  PCD1_1 = 4U;

  /* '<S4>:1:53' */
  PCD1_2 = 36U;
  if (!MySimplifiedTestingModel_2_B.CastToBoolean) {
    /* '<S4>:1:57' */
    /* '<S4>:1:58' */
    PCD1_1 = 36U;
  }

  if (MySimplifiedTestingModel_2_B.CastToBoolean1) {
    /* '<S4>:1:62' */
    /* '<S4>:1:63' */
    PCD1_2 = 124U;

    /* '<S4>:1:64' */
    PCD1_1 = (uint8_T)(PCD1_1 | 4);
  }

  /* '<S4>:1:81' */
  /* '<S4>:1:82' */
  u0 = rt_roundd_snf(MySimplifiedTestingModel_2_B.Saturation * 163.84);
  if (u0 < 65536.0) {
    if (u0 >= 0.0) {
      status_word = (uint16_T)u0;
    } else {
      status_word = 0U;
    }
  } else {
    status_word = MAX_uint16_T;
  }

  /* '<S4>:1:83' */
  memcpy((void *)&pcd2split[0], (void *)&status_word, (size_t)2 * sizeof(uint8_T));

  /* '<S4>:1:85' */
  for (idx = 0; idx < 16; idx++) {
    sfull[idx] = '0';
    if ((1 << (15 - idx) & status_word) != 0) {
      sfull[idx] = '1';
    }
  }

  idx = 0;
  f = 0;
  exitg1 = false;
  while ((!exitg1) && (f < 16)) {
    if (sfull[f] == '1') {
      idx = f + 1;
      exitg1 = true;
    } else {
      f++;
    }
  }

  if (idx == 0) {
    idx = 16;
  }

  f = 16 - idx;
  if (17 - idx < 16) {
    i = idx - 1;
    for (k = 0; k < i; k++) {
      pcd2binary[k] = '0';
    }
  } else {
    i = 0;
  }

  for (k = 0; k <= f; k++) {
    pcd2binary[i + k] = sfull[(idx + k) - 1];
  }

  /* '<S4>:1:86' */
  for (idx = 0; idx < 8; idx++) {
    tmp = pcd2binary[idx];
    pcd2binary[idx] = pcd2binary[15 - idx];
    pcd2binary[15 - idx] = tmp;
  }

  /* '<S4>:1:95' */
  /* '<S4>:1:96' */
  /* '<S4>:1:97' */
  /* '<S4>:1:98' */
  /* '<S4>:1:100' */
  /* '<S4>:1:101' */
  /* '<S4>:1:102' */
  /* '<S4>:1:103' */
  MySimplifiedTestingModel_2_B.command[3] = PCD1_1;

  /* '<S4>:1:104' */
  MySimplifiedTestingModel_2_B.command[4] = PCD1_2;

  /* '<S4>:1:105' */
  u0 = MySimplifiedTestingMode_bin2dec(&pcd2binary[0]);
  u1 = MySimplifiedTestingMode_bin2dec(&pcd2binary[8]);
  u0 = rt_roundd_snf(u0);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp_0 = (uint8_T)u0;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  MySimplifiedTestingModel_2_B.command[5] = tmp_0;
  u0 = rt_roundd_snf(u1);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp_0 = (uint8_T)u0;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  MySimplifiedTestingModel_2_B.command[6] = tmp_0;

  /* '<S4>:1:106' */
  MySimplifiedTestingModel_2_B.command[7] = (uint8_T)(PCD1_1 ^ 121 ^ PCD1_2 ^
    pcd2split[0] ^ pcd2split[1]);
  MySimplifiedTestingModel_2_B.pcd2 = status_word;

  /* End of MATLAB Function: '<S1>/Create 8-Bytes Command' */

  /* MATLAB Function: '<S1>/MATLAB Function' */
  /* MATLAB Function 'RS485/MATLAB Function': '<S9>:1' */
  /* '<S9>:1:2' */
  /* '<S9>:1:3' */
  u0 = rt_roundd_snf(MySimplifiedTestingModel_2_B.Saturation * 163.84);
  if (u0 < 32768.0) {
    if (u0 >= -32768.0) {
      x = (int16_T)u0;
    } else {
      x = MIN_int16_T;
    }
  } else {
    x = MAX_int16_T;
  }

  memcpy((void *)&MySimplifiedTestingModel_2_B.y[0], (void *)&x, (size_t)2 *
         sizeof(uint8_T));

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Outputs for Triggered SubSystem: '<S1>/Subsystem' incorporates:
   *  TriggerPort: '<S11>/Trigger'
   */
  /* '<S9>:1:4' */
  okCrc = (MySimplifiedTestingModel_2_B.TX_Trigger &&
           (MySimplifiedTestingMode_PrevZCX.Subsystem_Trig_ZCE != POS_ZCSIG));
  if (okCrc) {
    /* DataTypeConversion: '<S11>/Cast' */
    MySimplifiedTestingModel_2_B.Cast = MySimplifiedTestingModel_2_B.TX_Len;

    /* Reshape: '<S11>/Reshape' */
    MySimplifiedTestingModel_2_B.Reshape = MySimplifiedTestingModel_2_B.Cast;

    /* S-Function (rti_commonblock): '<S13>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1202SER #1 Unit:GENSER Group:TRANSMIT */
    {
      UInt32 txFifoLevel;
      UInt32 bytesRefNumOf;
      bytesRefNumOf = (MySimplifiedTestingModel_2_B.Reshape <= 127) ?
        MySimplifiedTestingModel_2_B.Reshape : 127;
      txFifoLevel = dsser_transmit_fifo_level(rtiDS1202SER_B1_Ser[0]);
      if (((rtiDS1202SER_B1_Ser[0]->fifo_size) - txFifoLevel) > bytesRefNumOf) {
        UInt32 bytesActNumOfAddr;
        MySimplifiedTestingModel_2_B.SFunction1 = dsser_transmit
          (rtiDS1202SER_B1_Ser[0], bytesRefNumOf,
           &MySimplifiedTestingModel_2_B.TX_Data[0], &(bytesActNumOfAddr));
      } else {
        MySimplifiedTestingModel_2_B.SFunction1 = DSSER_FIFO_OVERFLOW;
      }
    }
  }

  MySimplifiedTestingMode_PrevZCX.Subsystem_Trig_ZCE =
    MySimplifiedTestingModel_2_B.TX_Trigger;

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* Saturate: '<S1>/Begrenzung Arbeitstemperatur1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  u0 = MySimplifiedTestingModel_2_P.Constant1_Value;
  u1 = MySimplifiedTestingModel_2_P.BegrenzungArbeitstemperatur1_Lo;
  u2 = MySimplifiedTestingModel_2_P.BegrenzungArbeitstemperatur1_Up;
  if (u0 > u2) {
    u0 = u2;
  } else if (u0 < u1) {
    u0 = u1;
  }

  u0 = floor(u0);
  if (rtIsNaN(u0)) {
    i = 0;
  } else {
    i = (int32_T)u0;
  }

  /* Saturate: '<S1>/Begrenzung Arbeitstemperatur1' */
  MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur1 = (uint8_T)i;

  /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' incorporates:
   *  Constant: '<S1>/Constant11'
   */
  u0 = MySimplifiedTestingModel_2_P.Constant11_Value;
  u1 = MySimplifiedTestingModel_2_P.BegrenzungArbeitstemperatur3_Lo;
  u2 = MySimplifiedTestingModel_2_P.BegrenzungArbeitstemperatur3_Up;
  if (u0 > u2) {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3 = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3 = u1;
  } else {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3 = u0;
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
  u0 = MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3;

  /* MATLAB Function 'RS485/MATLAB Function4': '<S10>:1' */
  /* '<S10>:1:57' */
  /* '<S10>:1:30' */
  /* '<S10>:1:36' */
  status_word = 0U;
  if (MySimplifiedTestingModel_2_P.ConstantSwitch7_Value != 0.0) {
    /* '<S10>:1:37' */
    status_word = 32768U;
  }

  if (MySimplifiedTestingModel_2_P.ConstantSwitch8_Value != 0.0) {
    /* '<S10>:1:38' */
    status_word = (uint16_T)(status_word | 16384);
  }

  if (MySimplifiedTestingModel_2_P.ConstantSwitch9_Value != 0.0) {
    /* '<S10>:1:39' */
    status_word = (uint16_T)(status_word | 8192);
  }

  if (MySimplifiedTestingModel_2_P.ConstantSwitch10_Value != 0.0) {
    /* '<S10>:1:40' */
    status_word = (uint16_T)(status_word | 4096);
  }

  if (MySimplifiedTestingModel_2_P.ConstantSwitch11_Value != 0.0) {
    /* '<S10>:1:41' */
    status_word = (uint16_T)(status_word | 64);
  }

  /* '<S10>:1:43' */
  /* '<S10>:1:44' */
  if (rtIsInf(MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3) ||
      rtIsNaN(MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3)) {
    /* '<S10>:1:47' */
    u0 = 0.0;
  }

  /* '<S10>:1:48' */
  u0 = fmax(0.0, fmin(100.0, u0));

  /* '<S10>:1:49' */
  q14 = (uint16_T)rt_roundd_snf(u0 * 163.84);

  /* '<S10>:1:50' */
  /* '<S10>:1:51' */
  /* '<S10>:1:57' */
  memset(&MySimplifiedTestingModel_2_B.u[0], 0, sizeof(uint8_T) << 6U);

  /* '<S10>:1:58' */
  MySimplifiedTestingModel_2_B.u[0] = 2U;

  /* '<S10>:1:59' */
  MySimplifiedTestingModel_2_B.u[1] = 6U;

  /* '<S10>:1:60' */
  u0 = rt_roundd_snf(MySimplifiedTestingModel_2_P.Constant13_Value);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp_0 = (uint8_T)u0;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  MySimplifiedTestingModel_2_B.u[2] = tmp_0;

  /* '<S10>:1:61' */
  MySimplifiedTestingModel_2_B.u[3] = (uint8_T)((uint32_T)status_word >> 8);

  /* '<S10>:1:62' */
  MySimplifiedTestingModel_2_B.u[4] = (uint8_T)(status_word & 255);

  /* '<S10>:1:63' */
  MySimplifiedTestingModel_2_B.u[5] = (uint8_T)((uint32_T)q14 >> 8);

  /* '<S10>:1:64' */
  MySimplifiedTestingModel_2_B.u[6] = (uint8_T)(q14 & 255);

  /* '<S10>:1:67' */
  PCD1_1 = 0U;

  /* '<S10>:1:68' */
  for (k = 0; k < 7; k++) {
    /* '<S10>:1:69' */
    PCD1_1 ^= MySimplifiedTestingModel_2_B.u[k];
  }

  /* '<S10>:1:71' */
  MySimplifiedTestingModel_2_B.u[7] = PCD1_1;

  /* End of MATLAB Function: '<S1>/MATLAB Function4' */
  for (i = 0; i < 64; i++) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant14'
     */
    if (MySimplifiedTestingModel_2_P.Constant14_Value >
        MySimplifiedTestingModel_2_P.Switch_Threshold) {
      /* Switch: '<S1>/Switch' */
      MySimplifiedTestingModel_2_B.Switch[i] = MySimplifiedTestingModel_2_B.u[i];
    } else {
      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<S1>/Constant15'
       */
      MySimplifiedTestingModel_2_B.Switch[i] =
        MySimplifiedTestingModel_2_P.Constant15_Value;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant14'
   */
  if (MySimplifiedTestingModel_2_P.Constant14_Value >
      MySimplifiedTestingModel_2_P.Switch1_Threshold) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant12'
     */
    MySimplifiedTestingModel_2_B.Switch1 =
      MySimplifiedTestingModel_2_P.Constant12_Value;
  } else {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant15'
     */
    MySimplifiedTestingModel_2_B.Switch1 =
      MySimplifiedTestingModel_2_P.Constant15_Value;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* DataTypeConversion: '<S1>/Cast To Boolean2' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean2 =
    (MySimplifiedTestingModel_2_P.Constant5_Value != 0.0);

  /* DataTypeConversion: '<S1>/Cast To Boolean3' incorporates:
   *  Constant: '<S1>/Constant10'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean3 =
    (MySimplifiedTestingModel_2_P.Constant10_Value != 0.0);

  /* DataTypeConversion: '<S1>/Cast To Boolean4' incorporates:
   *  Constant: '<S1>/ConstantSwitch2'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean4 =
    (MySimplifiedTestingModel_2_P.ConstantSwitch2_Value != 0.0);

  /* Constant: '<S1>/Constant6' */
  MySimplifiedTestingModel_2_B.Constant6 =
    MySimplifiedTestingModel_2_P.Constant6_Value;

  /* Constant: '<S1>/Constant7' */
  MySimplifiedTestingModel_2_B.Constant7 =
    MySimplifiedTestingModel_2_P.Constant7_Value;

  /* Constant: '<S1>/Constant8' */
  MySimplifiedTestingModel_2_B.Constant8 =
    MySimplifiedTestingModel_2_P.Constant8_Value;

  /* Constant: '<S1>/Length' */
  MySimplifiedTestingModel_2_B.Length =
    MySimplifiedTestingModel_2_P.Length_Value;

  /* S-Function (rti_commonblock): '<S6>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function1' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
void MySimplifiedTestingModel_2_update(void)
{
  /* Update for Memory: '<S1>/Memory' */
  MySimplifiedTestingModel_2_DW.Memory_PreviousInput =
    MySimplifiedTestingModel_2_B.grant_ZKDM;

  /* Update for Memory: '<S1>/Memory1' */
  MySimplifiedTestingModel_2_DW.Memory1_PreviousInput =
    MySimplifiedTestingModel_2_B.resp_ok_ZKDM;

  /* Update for Memory: '<S1>/Memory3' */
  memcpy(&MySimplifiedTestingModel_2_DW.Memory3_PreviousInput[0],
         &MySimplifiedTestingModel_2_B.resp_data[0], 127U * sizeof(uint8_T));

  /* Update for Memory: '<S1>/Memory2' */
  MySimplifiedTestingModel_2_DW.Memory2_PreviousInput =
    MySimplifiedTestingModel_2_B.resp_err_ZKDM;

  /* Update for Memory: '<S1>/Memory4' */
  MySimplifiedTestingModel_2_DW.Memory4_PreviousInput =
    MySimplifiedTestingModel_2_B.resp_len;

  /* Update for Memory: '<S1>/Memory5' */
  MySimplifiedTestingModel_2_DW.Memory5_PreviousInput =
    MySimplifiedTestingModel_2_B.req_valid;

  /* Update for Memory: '<S1>/Memory8' */
  MySimplifiedTestingModel_2_DW.Memory8_PreviousInput =
    MySimplifiedTestingModel_2_B.expect_addr_ZKDM;

  /* Update for Memory: '<S1>/Memory10' */
  MySimplifiedTestingModel_2_DW.Memory10_PreviousInput =
    MySimplifiedTestingModel_2_B.expect_crc_kind_ZKDM;

  /* Update for Memory: '<S1>/Memory9' */
  MySimplifiedTestingModel_2_DW.Memory9_PreviousInput =
    MySimplifiedTestingModel_2_B.expect_len_ZKDM;

  /* Update for Memory: '<S1>/Memory6' */
  memcpy(&MySimplifiedTestingModel_2_DW.Memory6_PreviousInput[0],
         &MySimplifiedTestingModel_2_B.req_bytes[0], 127U * sizeof(uint8_T));

  /* Update for Memory: '<S1>/Memory7' */
  MySimplifiedTestingModel_2_DW.Memory7_PreviousInput =
    MySimplifiedTestingModel_2_B.req_len;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MySimplifiedTestingModel_2_M->Timing.clockTick0)) {
    ++MySimplifiedTestingModel_2_M->Timing.clockTickH0;
  }

  MySimplifiedTestingModel_2_M->Timing.t[0] =
    MySimplifiedTestingModel_2_M->Timing.clockTick0 *
    MySimplifiedTestingModel_2_M->Timing.stepSize0 +
    MySimplifiedTestingModel_2_M->Timing.clockTickH0 *
    MySimplifiedTestingModel_2_M->Timing.stepSize0 * 4294967296.0;

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
    MySimplifiedTestingModel_2_M->Timing.clockTick1++;
    if (!MySimplifiedTestingModel_2_M->Timing.clockTick1) {
      MySimplifiedTestingModel_2_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void MySimplifiedTestingModel_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MySimplifiedTestingModel_2_M, 0,
                sizeof(RT_MODEL_MySimplifiedTestingM_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MySimplifiedTestingModel_2_M->solverInfo,
                          &MySimplifiedTestingModel_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&MySimplifiedTestingModel_2_M->solverInfo, &rtmGetTPtr
                (MySimplifiedTestingModel_2_M));
    rtsiSetStepSizePtr(&MySimplifiedTestingModel_2_M->solverInfo,
                       &MySimplifiedTestingModel_2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&MySimplifiedTestingModel_2_M->solverInfo,
                          (&rtmGetErrorStatus(MySimplifiedTestingModel_2_M)));
    rtsiSetRTModelPtr(&MySimplifiedTestingModel_2_M->solverInfo,
                      MySimplifiedTestingModel_2_M);
  }

  rtsiSetSimTimeStep(&MySimplifiedTestingModel_2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&MySimplifiedTestingModel_2_M->solverInfo,
    false);
  rtsiSetSolverName(&MySimplifiedTestingModel_2_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(MySimplifiedTestingModel_2_M,
             &MySimplifiedTestingModel_2_M->Timing.tArray[0]);
  MySimplifiedTestingModel_2_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &MySimplifiedTestingModel_2_B), 0,
                sizeof(B_MySimplifiedTestingModel_2_T));

  /* states (dwork) */
  (void) memset((void *)&MySimplifiedTestingModel_2_DW, 0,
                sizeof(DW_MySimplifiedTestingModel_2_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    MySimplifiedTestingModel_2_rti_init_trc_pointers();
  }

  MySimplifiedTestingMode_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    MySimplifiedTestingModel_2_DW.Memory_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    MySimplifiedTestingModel_2_DW.Memory1_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory1_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    MySimplifiedTestingModel_2_DW.Memory2_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory2_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    MySimplifiedTestingModel_2_DW.Memory4_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory4_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    MySimplifiedTestingModel_2_DW.Memory5_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory5_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory8' */
    MySimplifiedTestingModel_2_DW.Memory8_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory8_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory10' */
    MySimplifiedTestingModel_2_DW.Memory10_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory10_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory9' */
    MySimplifiedTestingModel_2_DW.Memory9_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory9_InitialCondition;
    for (i = 0; i < 127; i++) {
      /* InitializeConditions for Memory: '<S1>/Memory3' */
      MySimplifiedTestingModel_2_DW.Memory3_PreviousInput[i] =
        MySimplifiedTestingModel_2_P.Memory3_InitialCondition;

      /* InitializeConditions for Memory: '<S1>/Memory6' */
      MySimplifiedTestingModel_2_DW.Memory6_PreviousInput[i] =
        MySimplifiedTestingModel_2_P.Memory6_InitialCondition;
    }

    /* InitializeConditions for Memory: '<S1>/Memory7' */
    MySimplifiedTestingModel_2_DW.Memory7_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory7_InitialCondition;

    /* SystemInitialize for Chart: '<S1>/ZKDM FSM' */
    MySimplifiedTestingModel_2_DW.REV8_not_empty = false;
    MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;
    MySimplifiedTestingModel_2_DW.temporalCounter_i2_i = 0U;
    MySimplifiedTestingModel_2_DW.is_active_c11_MySimplifiedTesti = 0U;
    MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
      MySimplified_IN_NO_ACTIVE_CHILD;
    MySimplifiedTestingModel_2_DW.fc_addr = 253U;
    MySimplifiedTestingModel_2_DW.min_period_ms = 50U;
    MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT = false;
    MySimplifiedTestingModel_2_DW.tx_len = 8U;
    MySimplifiedTestingModel_2_DW.comm_err_count = 0U;
    MySimplifiedTestingModel_2_B.req_valid = false;
    memset(&MySimplifiedTestingModel_2_B.req_bytes[0], 0, 127U * sizeof(uint8_T));
    MySimplifiedTestingModel_2_B.req_len = 0U;
    MySimplifiedTestingModel_2_B.expect_addr_ZKDM = 0U;
    MySimplifiedTestingModel_2_B.expect_crc_kind_ZKDM = 0U;
    MySimplifiedTestingModel_2_B.expect_len_ZKDM = 0U;
    MySimplifiedTestingModel_2_B.fault_no_trip = false;
    MySimplifiedTestingModel_2_B.fault_trip = false;
    MySimplifiedTestingModel_2_B.fu_ctrl_ready = false;
    MySimplifiedTestingModel_2_B.fu_ready = false;
    MySimplifiedTestingModel_2_B.bus_ctrl_active = false;
    MySimplifiedTestingModel_2_B.freq_rel = 0.0;
    for (i = 0; i < 8; i++) {
      MySimplifiedTestingModel_2_B.debug_command[i] = 0U;
    }

    MySimplifiedTestingModel_2_B.debug_pcd2[0] = 0U;
    MySimplifiedTestingModel_2_B.debug_pcd2[1] = 0U;

    /* End of SystemInitialize for Chart: '<S1>/ZKDM FSM' */

    /* SystemInitialize for Chart: '<S1>/BUS MASTER FSM' */
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_p = 0U;
    MySimplifiedTestingModel_2_DW.temporalCounter_i2 = 0U;
    MySimplifiedTestingModel_2_DW.is_active_c6_MySimplifiedTestin = 0U;
    MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
      MySimplified_IN_NO_ACTIVE_CHILD;
    MySimplifiedTestingModel_2_DW.interGap_ms = 5U;
    MySimplifiedTestingModel_2_DW.maxRetry = 1U;
    MySimplifiedTestingModel_2_DW.pollThermoEvery = 4U;
    MySimplifiedTestingModel_2_DW.timeout_ms_THERMO = 80U;
    MySimplifiedTestingModel_2_DW.timeout_ms_ZKDM = 20U;
    MySimplifiedTestingModel_2_DW.chosen_expect_addr = 0U;
    MySimplifiedTestingModel_2_DW.chosen_expect_len = 0U;
    MySimplifiedTestingModel_2_DW.chosen_len = 0U;
    MySimplifiedTestingModel_2_DW.currentDev = 0U;
    MySimplifiedTestingModel_2_DW.pollCounter = 0U;
    MySimplifiedTestingModel_2_DW.retry = 0U;
    memset(&MySimplifiedTestingModel_2_DW.chosen_req[0], 0, 127U * sizeof
           (uint8_T));
    memset(&MySimplifiedTestingModel_2_DW.rxBuf[0], 0, 127U * sizeof(uint8_T));
    MySimplifiedTestingModel_2_DW.rxCount = 0U;
    MySimplifiedTestingModel_2_DW.timeout_ms = 20U;
    MySimplifiedTestingModel_2_DW.err_THERMO = 0U;
    MySimplifiedTestingModel_2_DW.err_ZKDM = 0U;
    memset(&MySimplifiedTestingModel_2_B.TX_Data[0], 0, 127U * sizeof(uint8_T));
    MySimplifiedTestingModel_2_B.TX_Len = 0U;
    MySimplifiedTestingModel_2_B.TX_Trigger = false;
    MySimplifiedTestingModel_2_B.grant_ZKDM = false;
    MySimplifiedTestingModel_2_B.resp_err_ZKDM = 0U;
    MySimplifiedTestingModel_2_B.resp_ok_ZKDM = false;
    memset(&MySimplifiedTestingModel_2_B.resp_data[0], 0, 127U * sizeof(uint8_T));
    MySimplifiedTestingModel_2_B.resp_err_THERMO = 0U;
    MySimplifiedTestingModel_2_B.resp_len = 0U;
    MySimplifiedTestingModel_2_B.grant_THERMO = false;
    MySimplifiedTestingModel_2_B.resp_ok_THERMO = false;

    /* SystemInitialize for Triggered SubSystem: '<S1>/Subsystem' */
    /* SystemInitialize for S-Function (rti_commonblock): '<S13>/S-Function1' incorporates:
     *  Outport: '<S11>/Status'
     */
    MySimplifiedTestingModel_2_B.SFunction1 =
      MySimplifiedTestingModel_2_P.Status_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem' */
  }
}

/* Model terminate function */
void MySimplifiedTestingModel_2_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S6>/S-Function1' */

  /* dSPACE I/O Board DS1202SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS1202SER_B1_Ser[0]);
  dsser_fifo_reset(rtiDS1202SER_B1_Ser[0]);

  /* Terminate for S-Function (rti_commonblock): '<S7>/S-Function1' */

  /* dSPACE I/O Board DS1202SER #1 Unit:GENSER Group:SETUP */
  dsser_disable(rtiDS1202SER_B1_Ser[1]);
  dsser_fifo_reset(rtiDS1202SER_B1_Ser[1]);
}
