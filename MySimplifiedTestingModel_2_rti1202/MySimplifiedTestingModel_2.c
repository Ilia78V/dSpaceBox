/*
 * MySimplifiedTestingModel_2.c
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

#include "MySimplifiedTestingModel_2_trc_ptr.h"
#include "MySimplifiedTestingModel_2.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <math.h>
#include "MySimplifiedTestingModel_2_private.h"
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

/* Named constants for Chart: '<S1>/THERMO FSM' */
#define MySimplifiedTesti_IN_HANDLE_ERR ((uint8_T)2U)
#define MySimplifiedTesti_IN_WAIT_GRANT ((uint8_T)6U)
#define MySimplifiedTestin_IN_WAIT_RESP ((uint8_T)7U)
#define MySimplifiedTestingMo_IN_INIT_p ((uint8_T)3U)
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
  boolean_T active, real_T setpoint, real_T off_set, uint8_T command[127]);
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
static void MySimplifiedTesti_thermoCommand(const uint8_T address[4], uint8_T
  commandType, real_T setpoint, const uint8_T setpointReduced[16], uint32_T
  setpointReducedLength, uint8_T command[127], uint8_T *numBytes);
static void MySimplifiedTestingMo_thermCom1(uint8_T commandType, real_T setpoint,
  uint8_T command[127], uint8_T *outLen);
static void MySimplifiedT_enter_atomic_IDLE(void);
static boolean_T MySimplifiedTes_addr_ok_thermo1(const uint8_T u[127], const
  uint8_T expect_addr[4]);
static boolean_T MySimplifiedTestingMode_addr_ok(const uint8_T buf[127], uint8_T
  count, uint8_T expect_addr);
static boolean_T MySimplifiedTestingModel_len_ok(uint8_T count, uint8_T
  expect_len);
static boolean_T MySimplifiedTestingModel_crc_ok(const uint8_T buf[127], uint8_T
  count);
static real_T MySimplifiedTestingMode_bin2dec(const char_T s[8]);

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTest_parse_fc_reply(const uint8_T u[64], uint8_T *PCD1_1,
  uint8_T *PCD1_2, real_T *freq_rel_percent, uint16_T *status_word, boolean_T
  *fu_ctrl_ready, boolean_T *fu_ready, boolean_T *fault_trip, boolean_T
  *fault_no_trip, boolean_T *bus_control_active, boolean_T *bcc_ok)
{
  int32_T k;
  uint8_T b;

  /* MATLAB Function 'parse_fc_reply': '<S14>:73' */
  /* '<S14>:73:19' */
  /* '<S14>:73:22' */
  b = 0U;

  /* '<S14>:73:23' */
  for (k = 0; k < 7; k++) {
    /* '<S14>:73:24' */
    b ^= u[k];
  }

  /* '<S14>:73:26' */
  *bcc_ok = (b == u[7]);

  /* '<S14>:73:29' */
  *PCD1_1 = u[3];

  /* '<S14>:73:30' */
  *PCD1_2 = u[4];

  /* '<S14>:73:33' */
  *status_word = (uint16_T)(u[3] << 8 | u[4]);

  /* '<S14>:73:39' */
  *fu_ctrl_ready = ((*status_word & 32768U) != 0U);

  /* '<S14>:73:40' */
  *fu_ready = ((*status_word & 16384U) != 0U);

  /* '<S14>:73:41' */
  *fault_trip = ((*status_word & 8192U) != 0U);

  /* '<S14>:73:42' */
  *fault_no_trip = ((*status_word & 4096U) != 0U);

  /* '<S14>:73:43' */
  *bus_control_active = ((*status_word & 64U) != 0U);

  /* '<S14>:73:46' */
  /* '<S14>:73:47' */
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
  boolean_T active, real_T setpoint, real_T off_set, uint8_T command[127])
{
  real_T tmp;
  int16_T x;
  uint8_T pcd2[2];
  uint8_T pcd1_1;
  uint8_T pcd1_2;

  /* MATLAB Function 'fcn': '<S14>:50' */
  /* '<S14>:50:47' */
  memset(&command[0], 0, 127U * sizeof(uint8_T));

  /* '<S14>:50:48' */
  command[0] = 2U;

  /* '<S14>:50:49' */
  command[1] = 6U;

  /* '<S14>:50:50' */
  command[2] = 125U;

  /* '<S14>:50:52' */
  pcd1_1 = 4U;

  /* '<S14>:50:53' */
  pcd1_2 = 36U;
  if (!invalid_control_word) {
    /* '<S14>:50:57' */
    /* '<S14>:50:58' */
    pcd1_1 = 36U;
  }

  if (active) {
    /* '<S14>:50:62' */
    /* '<S14>:50:63' */
    pcd1_2 = 124U;

    /* '<S14>:50:64' */
    pcd1_1 = (uint8_T)(pcd1_1 | 4);
  }

  if (setpoint <= off_set) {
    /* '<S14>:50:81' */
    /* '<S14>:50:82' */
    setpoint = 0.0;
  } else {
    /* '<S14>:50:84' */
    setpoint -= off_set;
  }

  /* '<S14>:50:87' */
  /* '<S14>:50:88' */
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

  /* '<S14>:50:97' */
  /* '<S14>:50:98' */
  /* '<S14>:50:99' */
  /* '<S14>:50:100' */
  /* '<S14>:50:102' */
  /* '<S14>:50:103' */
  /* '<S14>:50:104' */
  /* '<S14>:50:105' */
  command[3] = pcd1_1;

  /* '<S14>:50:106' */
  command[4] = pcd1_2;

  /* '<S14>:50:107' */
  command[5] = pcd2[0];
  command[6] = pcd2[1];

  /* '<S14>:50:108' */
  command[7] = (uint8_T)(pcd1_1 ^ 121 ^ pcd1_2 ^ pcd2[0] ^ pcd2[1]);
}

/* Function for Chart: '<S1>/ZKDM FSM' */
static void MySimplifiedTesti_make_rev8_lut(uint8_T REV8[256])
{
  int32_T i;
  int32_T k;

  /* MATLAB Function 'make_rev8_lut': '<S14>:113' */
  /* '<S14>:113:19' */
  /* '<S14>:113:16' */
  /* '<S14>:113:22' */
  for (i = 0; i < 256; i++) {
    uint8_T r;

    /* '<S14>:113:23' */
    /* '<S14>:113:24' */
    r = 0U;

    /* '<S14>:113:25' */
    for (k = 0; k < 8; k++) {
      /* '<S14>:113:27' */
      r = (uint8_T)(((1 << k & i) != 0) << (7 - k) | r);
    }

    /* '<S14>:113:29' */
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

  /* MATLAB Function 'apply_mode': '<S14>:112' */
  /* '<S14>:112:3' */
  b[0] = b_in[0];
  b[1] = b_in[1];

  /* '<S14>:112:5' */
  /* '<S14>:112:6' */
  /* '<S14>:112:7' */
  if ((mode & 1U) != 0U) {
    /* '<S14>:112:9' */
    /* '<S14>:112:10' */
    varargin_1 = b_in[0];
    varargin_1 = (uint8_T)~varargin_1;
    b[0] = varargin_1;
    varargin_1 = b_in[1];
    varargin_1 = (uint8_T)~varargin_1;
    b[1] = varargin_1;
  }

  if ((mode & 4U) != 0U) {
    /* '<S14>:112:13' */
    /* '<S14>:112:15' */
    b[0] = REV8[b[0]];
    b[1] = REV8[b[1]];
  }

  if ((mode & 2U) != 0U) {
    uint8_T b_idx_1;

    /* '<S14>:112:18' */
    /* '<S14>:112:19' */
    varargin_1 = b[1];
    b_idx_1 = b[0];
    b[0] = varargin_1;
    b[1] = b_idx_1;
  }

  /* '<S14>:112:23' */
  /* '<S14>:112:24' */
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

  /* MATLAB Function 'pcd2_flipcases': '<S14>:111' */
  /* '<S14>:111:26' */
  memcpy((void *)&b[0], (void *)&pcd2, (size_t)2 * sizeof(uint8_T));

  /* '<S14>:111:16' */
  if (!MySimplifiedTestingModel_2_DW.REV8_not_empty) {
    /* '<S14>:111:19' */
    /* '<S14>:111:20' */
    MySimplifiedTesti_make_rev8_lut(MySimplifiedTestingModel_2_DW.REV8);
    MySimplifiedTestingModel_2_DW.REV8_not_empty = true;
  }

  /* '<S14>:111:26' */
  *out_labels_f1___dummy = 0;
  *out_labels_f2___dummy = 0;
  *out_labels_f3___dummy = 0;
  *out_labels_f4___dummy = 0;
  *out_labels_f5___dummy = 0;
  *out_labels_f6___dummy = 0;
  *out_labels_f7___dummy = 0;
  *out_labels_f8___dummy = 0;

  /* '<S14>:111:31' */
  /* '<S14>:111:32' */
  for (m = 0; m < 8; m++) {
    /* '<S14>:111:33' */
    out_values[m] = MySimplifiedTestingM_apply_mode(b,
      MySimplifiedTestingModel_2_DW.REV8, c[m]);
  }

  /* '<S14>:111:36' */
  /* '<S14>:111:37' */
  /* '<S14>:111:38' */
  /* '<S14>:111:39' */
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

  /* MATLAB Function 'debug_cmnd': '<S14>:110' */
  /* '<S14>:110:8' */
  /* '<S14>:110:9' */
  /* '<S14>:110:10' */
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

  /* '<S14>:110:11' */
}

/* Function for Chart: '<S1>/THERMO FSM' */
static void MySimplifiedTesti_thermoCommand(const uint8_T address[4], uint8_T
  commandType, real_T setpoint, const uint8_T setpointReduced[16], uint32_T
  setpointReducedLength, uint8_T command[127], uint8_T *numBytes)
{
  real_T tmp_0;
  int32_T c;
  int32_T q0;
  uint32_T indexEnd;
  uint8_T commandVector_data[11];
  uint8_T tmp;
  static const uint8_T d[11] = { 111U, 117U, 116U, 95U, 109U, 111U, 100U, 101U,
    95U, 48U, 53U };

  static const uint8_T e[9] = { 111U, 117U, 116U, 95U, 115U, 112U, 95U, 48U, 48U
  };

  static const uint8_T f[8] = { 105U, 110U, 95U, 112U, 118U, 95U, 48U, 48U };

  static const uint8_T g[8] = { 105U, 110U, 95U, 112U, 118U, 95U, 48U, 49U };

  static const uint8_T h[6] = { 115U, 116U, 97U, 116U, 117U, 115U };

  int32_T commandVector_size_idx_1;

  /* MATLAB Function 'thermoCommand': '<S13>:112' */
  /* '<S13>:112:23' */
  /* '<S13>:112:21' */
  /* '<S13>:112:19' */
  /* '<S13>:112:17' */
  /* '<S13>:112:15' */
  /* '<S13>:112:4' */
  memset(&command[0], 0, 127U * sizeof(uint8_T));

  /* '<S13>:112:10' */
  command[0] = address[0];
  command[1] = address[1];
  command[2] = address[2];
  command[3] = address[3];

  /* '<S13>:112:13' */
  switch (commandType) {
   case 0U:
    /* '<S13>:112:15' */
    commandVector_size_idx_1 = 11;
    for (q0 = 0; q0 < 11; q0++) {
      commandVector_data[q0] = d[q0];
    }
    break;

   case 1U:
    /* '<S13>:112:17' */
    commandVector_size_idx_1 = 9;
    for (q0 = 0; q0 < 9; q0++) {
      commandVector_data[q0] = e[q0];
    }
    break;

   case 2U:
    /* '<S13>:112:19' */
    commandVector_size_idx_1 = 8;
    for (q0 = 0; q0 < 8; q0++) {
      commandVector_data[q0] = f[q0];
    }
    break;

   case 3U:
    /* '<S13>:112:21' */
    commandVector_size_idx_1 = 8;
    for (q0 = 0; q0 < 8; q0++) {
      commandVector_data[q0] = g[q0];
    }
    break;

   case 4U:
    /* '<S13>:112:23' */
    commandVector_size_idx_1 = 6;
    for (q0 = 0; q0 < 6; q0++) {
      commandVector_data[q0] = h[q0];
    }
    break;
  }

  /* '<S13>:112:29' */
  /* '<S13>:112:31' */
  indexEnd = (uint32_T)commandVector_size_idx_1 + 5U;

  /* '<S13>:112:37' */
  memcpy(&command[4], &commandVector_data[0], (uint32_T)commandVector_size_idx_1
         * sizeof(uint8_T));
  if (!rtIsNaN(setpoint)) {
    /* '<S13>:112:40' */
    /* '<S13>:112:42' */
    /* '<S13>:112:43' */
    command[commandVector_size_idx_1 + 4] = 32U;
    if (commandType == 0) {
      /* '<S13>:112:47' */
      /* '<S13>:112:49' */
      tmp_0 = rt_roundd_snf(setpoint + 48.0);
      if (tmp_0 < 256.0) {
        if (tmp_0 >= 0.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      command[(int32_T)((uint32_T)commandVector_size_idx_1 + 5U)] = tmp;

      /* '<S13>:112:50' */
      indexEnd = (uint32_T)commandVector_size_idx_1 + 7U;
    } else {
      /* '<S13>:112:53' */
      /* '<S13>:112:54' */
      q0 = (int32_T)((uint32_T)commandVector_size_idx_1 + 6U);
      indexEnd = (uint32_T)q0 + setpointReducedLength;
      if (indexEnd < (uint32_T)q0) {
        indexEnd = MAX_uint32_T;
      }

      if ((uint32_T)commandVector_size_idx_1 + 6U > indexEnd - 1U) {
        c = -5;
      } else {
        c = commandVector_size_idx_1;
      }

      /* '<S13>:112:60' */
      commandVector_size_idx_1 = (int32_T)setpointReducedLength;
      for (q0 = 0; q0 < commandVector_size_idx_1; q0++) {
        command[(c + q0) + 5] = setpointReduced[q0];
      }
    }
  }

  /* '<S13>:112:65' */
  /* '<S13>:112:66' */
  command[(int32_T)indexEnd - 1] = 13U;

  /* '<S13>:112:69' */
  if (indexEnd > 255U) {
    indexEnd = 255U;
  }

  *numBytes = (uint8_T)indexEnd;
}

/* Function for Chart: '<S1>/THERMO FSM' */
static void MySimplifiedTestingMo_thermCom1(uint8_T commandType, real_T setpoint,
  uint8_T command[127], uint8_T *outLen)
{
  real_T r;
  real_T x;
  real_T x100;
  int32_T dlen;
  int32_T idx;
  int32_T k;
  uint8_T setpointReduced[16];
  uint8_T tmpDigits[10];
  uint8_T tens;
  static const uint8_T c[4] = { 65U, 48U, 48U, 53U };

  /* MATLAB Function 'thermCom1': '<S13>:135' */
  /* '<S13>:135:15' */
  /* '<S13>:135:64' */
  /* '<S13>:135:8' */
  for (dlen = 0; dlen < 16; dlen++) {
    setpointReduced[dlen] = 0U;
  }

  /* '<S13>:135:12' */
  x = setpoint;
  if (rtIsNaN(setpoint) || rtIsInf(setpoint)) {
    /* '<S13>:135:13' */
    /* '<S13>:135:15' */
    setpointReduced[0] = 78U;
    setpointReduced[1] = 97U;
    setpointReduced[2] = 78U;

    /* '<S13>:135:16' */
    idx = 3;
  } else {
    /* '<S13>:135:19' */
    idx = 1;
    if (setpoint < 0.0) {
      /* '<S13>:135:20' */
      /* '<S13>:135:21' */
      setpointReduced[0] = 45U;

      /* '<S13>:135:21' */
      idx = 2;

      /* '<S13>:135:22' */
      x = -setpoint;
    }

    /* '<S13>:135:26' */
    x100 = floor(x * 100.0 + 0.5);

    /* '<S13>:135:27' */
    x = floor(x100 / 100.0);

    /* '<S13>:135:28' */
    x100 -= x * 100.0;

    /* '<S13>:135:32' */
    for (dlen = 0; dlen < 10; dlen++) {
      tmpDigits[dlen] = 0U;
    }

    /* '<S13>:135:33' */
    dlen = 0;
    if (x == 0.0) {
      /* '<S13>:135:34' */
      /* '<S13>:135:35' */
      dlen = 1;

      /* '<S13>:135:36' */
      tmpDigits[0] = 48U;
    } else {
      while ((x > 0.0) && (dlen < 10)) {
        /* '<S13>:135:38' */
        /* '<S13>:135:39' */
        dlen = (int32_T)((uint32_T)dlen + 1U);

        /* '<S13>:135:40' */
        if (rtIsInf(x)) {
          r = (rtNaN);
        } else {
          r = fmod(x, 10.0);
        }

        /* '<S13>:135:41' */
        r = rt_roundd_snf(r);
        if (r < 256.0) {
          tens = (uint8_T)r;
        } else {
          tens = MAX_uint8_T;
        }

        tmpDigits[dlen - 1] = (uint8_T)(tens + 48);

        /* '<S13>:135:42' */
        x /= 10.0;
        x = floor(x);
      }
    }

    /* '<S13>:135:46' */
    for (k = dlen; k >= 1; k--) {
      /* '<S13>:135:47' */
      setpointReduced[idx - 1] = tmpDigits[k - 1];

      /* '<S13>:135:48' */
      idx = (int32_T)((uint32_T)idx + 1U);
    }

    /* '<S13>:135:52' */
    setpointReduced[idx - 1] = 46U;

    /* '<S13>:135:52' */
    idx = (int32_T)((uint32_T)idx + 1U);

    /* '<S13>:135:55' */
    r = floor(x100 / 10.0);
    if (r < 256.0) {
      if (r >= 0.0) {
        tens = (uint8_T)r;
      } else {
        tens = 0U;
      }
    } else {
      tens = MAX_uint8_T;
    }

    /* '<S13>:135:56' */
    /* '<S13>:135:57' */
    dlen = (int32_T)(tens + 48U);
    if ((uint32_T)dlen > 255U) {
      dlen = 255;
    }

    setpointReduced[idx - 1] = (uint8_T)dlen;

    /* '<S13>:135:57' */
    idx = (int32_T)((uint32_T)idx + 1U);

    /* '<S13>:135:58' */
    r = x100 - (real_T)tens * 10.0;
    if (r < 256.0) {
      if (r >= 0.0) {
        tens = (uint8_T)r;
      } else {
        tens = 0U;
      }
    } else {
      tens = MAX_uint8_T;
    }

    dlen = (int32_T)(tens + 48U);
    if ((uint32_T)dlen > 255U) {
      dlen = 255;
    }

    setpointReduced[idx - 1] = (uint8_T)dlen;

    /* '<S13>:135:58' */
    idx = (int32_T)((uint32_T)idx + 1U);

    /* '<S13>:135:60' */
    idx = (int32_T)((uint32_T)idx - 1U);
  }

  /* '<S13>:135:63' */
  MySimplifiedTesti_thermoCommand(c, commandType, setpoint, setpointReduced,
    (uint32_T)idx, command, outLen);

  /* '<S13>:135:63' */
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
static boolean_T MySimplifiedTes_addr_ok_thermo1(const uint8_T u[127], const
  uint8_T expect_addr[4])
{
  int32_T endIdx;
  int32_T sepIdx;
  boolean_T exitg1;
  boolean_T ok;

  /* MATLAB Function 'addr_ok_thermo1': '<S3>:462' */
  /* '<S3>:462:5' */
  ok = false;

  /* '<S3>:462:16' */
  endIdx = 127;

  /* '<S3>:462:17' */
  sepIdx = 0;
  exitg1 = false;
  while ((!exitg1) && (sepIdx < 127)) {
    /* '<S3>:462:17' */
    if (u[sepIdx] == 13) {
      /* '<S3>:462:18' */
      /* '<S3>:462:19' */
      endIdx = sepIdx;
      exitg1 = true;
    } else {
      sepIdx++;
    }
  }

  if (endIdx >= 1) {
    int32_T b_i;

    /* '<S3>:462:28' */
    sepIdx = 0;

    /* '<S3>:462:29' */
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= endIdx - 1)) {
      /* '<S3>:462:29' */
      if (u[b_i] == 95) {
        /* '<S3>:462:30' */
        /* '<S3>:462:31' */
        sepIdx = b_i + 1;
        exitg1 = true;
      } else {
        b_i++;
      }
    }

    if ((sepIdx != 0) && (sepIdx - 1 == 4)) {
      /* '<S3>:462:39' */
      /* '<S3>:462:48' */
      endIdx = 0;
      int32_T exitg2;
      do {
        exitg2 = 0;
        if (endIdx < 4) {
          /* '<S3>:462:48' */
          if (u[endIdx] != expect_addr[endIdx]) {
            /* '<S3>:462:49' */
            exitg2 = 1;
          } else {
            endIdx++;
          }
        } else {
          /* '<S3>:462:54' */
          ok = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    } else {
      /* '<S3>:462:35' */
      /* '<S3>:462:43' */
    }
  } else {
    /* '<S3>:462:23' */
  }

  return ok;
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
  real_T x;
  real_T x10;
  uint16_T q14;
  uint16_T status_word;
  uint8_T tmpDigits[10];
  uint8_T PCD1_1;
  uint8_T PCD1_2;
  static const char_T b[4] = { 'A', '0', '0', '5' };

  static const char_T c[4] = { 'A', '0', '0', '5' };

  real_T u1;
  int32_T e;
  int32_T i;
  int32_T idx;
  int32_T npad;
  uint32_T qY;
  int16_T x_0;
  char_T (*tmp_0)[256];
  char_T pcd2binary[16];
  char_T sfull[16];
  const char_T *tmp_1;
  char_T tmp;
  uint8_T pcd2split[2];
  uint8_T tmp_2;
  boolean_T okAddr;
  boolean_T okCrc;
  boolean_T okLen;
  static const uint8_T b_0[5] = { 65U, 48U, 48U, 53U, 95U };

  boolean_T exitg1;
  boolean_T guard1;

  /* DataTypeConversion: '<S1>/Cast To Boolean1' incorporates:
   *  Constant: '<S1>/Active'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean1 =
    (MySimplifiedTestingModel_2_P.Active_Value != 0.0);

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Constant: '<S1>/Setpoint'
   */
  x = MySimplifiedTestingModel_2_P.Setpoint_Value;
  u1 = MySimplifiedTestingModel_2_P.Saturation_LowerSat;
  x10 = MySimplifiedTestingModel_2_P.Saturation_UpperSat;
  if (x > x10) {
    /* Saturate: '<S1>/Saturation' */
    MySimplifiedTestingModel_2_B.Saturation = x10;
  } else if (x < u1) {
    /* Saturate: '<S1>/Saturation' */
    MySimplifiedTestingModel_2_B.Saturation = u1;
  } else {
    /* Saturate: '<S1>/Saturation' */
    MySimplifiedTestingModel_2_B.Saturation = x;
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

  /* DataTypeConversion: '<S1>/Cast To Boolean8' incorporates:
   *  Constant: '<S1>/ConstantSwitch12'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean8 =
    MySimplifiedTestingModel_2_P.ConstantSwitch12_Value;

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
    /* Transition: '<S14>:24' */
    MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
      MySimplifiedTestingMo_IN_INIT_p;
    MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

    /* Entry 'INIT': '<S14>:23' */
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
      /* During 'COOLDOWN': '<S14>:37' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1 >= 1) {
        /* Transition: '<S14>:39' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_READY;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_i = 0U;

        /* Entry 'READY': '<S14>:25' */
        MySimplifiedTestingModel_2_B.req_valid = false;
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT = false;
      }
      break;

     case MySimplifiedTesti_IN_HANDLE_ERR:
      /* During 'HANDLE_ERR': '<S14>:32' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1 >= 1) {
        /* Transition: '<S14>:38' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesting_IN_COOLDOWN;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

        /* Entry 'COOLDOWN': '<S14>:37' */
      }
      break;

     case MySimplifiedTestingMo_IN_INIT_p:
      /* During 'INIT': '<S14>:23' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1 >= 1) {
        /* Transition: '<S14>:26' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_READY;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_i = 0U;

        /* Entry 'READY': '<S14>:25' */
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
      /* During 'PARSE': '<S14>:30' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i2_i >=
          MySimplifiedTestingModel_2_DW.min_period_ms) {
        /* Transition: '<S14>:41' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesting_IN_COOLDOWN;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

        /* Entry 'COOLDOWN': '<S14>:37' */
      }
      break;

     case MySimplifiedTestingMod_IN_READY:
      /* During 'READY': '<S14>:25' */
      if (MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT) {
        /* Transition: '<S14>:28' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_WAIT_GRANT;

        /* Entry 'WAIT_GRANT': '<S14>:27' */
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT = false;
      } else if (MySimplifiedTestingModel_2_DW.temporalCounter_i2_i >=
                 MySimplifiedTestingModel_2_DW.min_period_ms) {
        MySimplifiedTestingModel_2_fcn
          (MySimplifiedTestingModel_2_B.CastToBoolean,
           MySimplifiedTestingModel_2_B.CastToBoolean1,
           MySimplifiedTestingModel_2_B.Saturation,
           MySimplifiedTestingModel_2_B.CastToBoolean8,
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
      /* During 'WAIT_GRANT': '<S14>:27' */
      if (MySimplifiedTestingModel_2_B.Memory) {
        /* Transition: '<S14>:33' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestin_IN_WAIT_RESP;

        /* Entry 'WAIT_RESP': '<S14>:29' */
      } else if (MySimplifiedTestingModel_2_B.Memory2 > 0) {
        /* Transition: '<S14>:34' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_HANDLE_ERR;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

        /* Entry 'HANDLE_ERR': '<S14>:32' */
        qY = MySimplifiedTestingModel_2_DW.comm_err_count + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        MySimplifiedTestingModel_2_DW.comm_err_count = (uint16_T)qY;
      }
      break;

     default:
      /* During 'WAIT_RESP': '<S14>:29' */
      if (MySimplifiedTestingModel_2_B.Memory1) {
        /* Transition: '<S14>:35' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_PARSE;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_i = 0U;

        /* Entry 'PARSE': '<S14>:30' */
        MySimplifiedTest_parse_fc_reply(&MySimplifiedTestingModel_2_B.Memory3[0],
          &PCD1_1, &PCD1_2, &MySimplifiedTestingModel_2_B.freq_rel, &status_word,
          &MySimplifiedTestingModel_2_B.fu_ctrl_ready,
          &MySimplifiedTestingModel_2_B.fu_ready,
          &MySimplifiedTestingModel_2_B.fault_trip,
          &MySimplifiedTestingModel_2_B.fault_no_trip,
          &MySimplifiedTestingModel_2_B.bus_ctrl_active, &okAddr);
        if (!okAddr) {
          qY = MySimplifiedTestingModel_2_DW.comm_err_count + 1U;
          if (qY > 65535U) {
            qY = 65535U;
          }

          MySimplifiedTestingModel_2_DW.comm_err_count = (uint16_T)qY;
        }
      } else if (MySimplifiedTestingModel_2_B.Memory2 > 0) {
        /* Transition: '<S14>:36' */
        MySimplifiedTestingModel_2_DW.is_c11_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_HANDLE_ERR;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1 = 0U;

        /* Entry 'HANDLE_ERR': '<S14>:32' */
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

  /* DataTypeConversion: '<S1>/Cast To Boolean3' incorporates:
   *  Constant: '<S1>/Constant10'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean3 =
    (MySimplifiedTestingModel_2_P.Constant10_Value != 0.0);

  /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' incorporates:
   *  Constant: '<S1>/Constant11'
   */
  x = MySimplifiedTestingModel_2_P.Constant11_Value;
  u1 = MySimplifiedTestingModel_2_P.BegrenzungArbeitstemperatur3_Lo;
  x10 = MySimplifiedTestingModel_2_P.BegrenzungArbeitstemperatur3_Up;
  if (x > x10) {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3 = x10;
  } else if (x < u1) {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3 = u1;
  } else {
    /* Saturate: '<S1>/Begrenzung Arbeitstemperatur3' */
    MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3 = x;
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
  x = MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3;

  /* MATLAB Function 'RS485/MATLAB Function4': '<S11>:1' */
  /* '<S11>:1:57' */
  /* '<S11>:1:30' */
  /* '<S11>:1:36' */
  status_word = 0U;
  if (MySimplifiedTestingModel_2_P.ConstantSwitch7_Value != 0.0) {
    /* '<S11>:1:37' */
    status_word = 32768U;
  }

  if (MySimplifiedTestingModel_2_P.ConstantSwitch8_Value != 0.0) {
    /* '<S11>:1:38' */
    status_word = (uint16_T)(status_word | 16384);
  }

  if (MySimplifiedTestingModel_2_P.ConstantSwitch9_Value != 0.0) {
    /* '<S11>:1:39' */
    status_word = (uint16_T)(status_word | 8192);
  }

  if (MySimplifiedTestingModel_2_P.ConstantSwitch10_Value != 0.0) {
    /* '<S11>:1:40' */
    status_word = (uint16_T)(status_word | 4096);
  }

  if (MySimplifiedTestingModel_2_P.ConstantSwitch11_Value != 0.0) {
    /* '<S11>:1:41' */
    status_word = (uint16_T)(status_word | 64);
  }

  /* '<S11>:1:43' */
  /* '<S11>:1:44' */
  if (rtIsInf(MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3) ||
      rtIsNaN(MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur3)) {
    /* '<S11>:1:47' */
    x = 0.0;
  }

  /* '<S11>:1:48' */
  x = fmax(0.0, fmin(100.0, x));

  /* '<S11>:1:49' */
  q14 = (uint16_T)rt_roundd_snf(x * 163.84);

  /* '<S11>:1:50' */
  /* '<S11>:1:51' */
  /* '<S11>:1:57' */
  memset(&MySimplifiedTestingModel_2_B.u[0], 0, 127U * sizeof(uint8_T));

  /* '<S11>:1:58' */
  MySimplifiedTestingModel_2_B.u[0] = 2U;

  /* '<S11>:1:59' */
  MySimplifiedTestingModel_2_B.u[1] = 6U;

  /* '<S11>:1:60' */
  u1 = rt_roundd_snf(MySimplifiedTestingModel_2_P.Constant13_Value);
  if (u1 < 256.0) {
    if (u1 >= 0.0) {
      tmp_2 = (uint8_T)u1;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  MySimplifiedTestingModel_2_B.u[2] = tmp_2;

  /* '<S11>:1:61' */
  MySimplifiedTestingModel_2_B.u[3] = (uint8_T)((uint32_T)status_word >> 8);

  /* '<S11>:1:62' */
  MySimplifiedTestingModel_2_B.u[4] = (uint8_T)(status_word & 255);

  /* '<S11>:1:63' */
  MySimplifiedTestingModel_2_B.u[5] = (uint8_T)((uint32_T)q14 >> 8);

  /* '<S11>:1:64' */
  MySimplifiedTestingModel_2_B.u[6] = (uint8_T)(q14 & 255);

  /* '<S11>:1:67' */
  PCD1_1 = 0U;

  /* '<S11>:1:68' */
  for (i = 0; i < 7; i++) {
    /* '<S11>:1:69' */
    PCD1_1 ^= MySimplifiedTestingModel_2_B.u[i];
  }

  /* '<S11>:1:71' */
  MySimplifiedTestingModel_2_B.u[7] = PCD1_1;

  /* '<S11>:1:73' */
  MySimplifiedTestingModel_2_B.length = 8U;

  /* End of MATLAB Function: '<S1>/MATLAB Function4' */

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<S1>/Constant12'
   */
  /* MATLAB Function 'RS485/MATLAB Function1': '<S10>:1' */
  /* '<S10>:1:10' */
  /* '<S10>:1:16' */
  /* '<S10>:1:6' */
  for (i = 0; i < 32; i++) {
    MySimplifiedTestingModel_2_B.telegram[i] = 0U;
  }

  /* '<S10>:1:10' */
  for (e = 0; e < 5; e++) {
    MySimplifiedTestingModel_2_B.telegram[e] = b_0[e];
  }

  /* '<S10>:1:11' */
  PCD1_1 = 6U;

  /* '<S10>:1:14' */
  x = MySimplifiedTestingModel_2_P.Constant12_Value;
  if (rtIsNaN(MySimplifiedTestingModel_2_P.Constant12_Value) || rtIsInf
      (MySimplifiedTestingModel_2_P.Constant12_Value)) {
    /* '<S10>:1:15' */
    /* '<S10>:1:16' */
    MySimplifiedTestingModel_2_B.telegram[5] = 78U;
    MySimplifiedTestingModel_2_B.telegram[6] = 97U;
    MySimplifiedTestingModel_2_B.telegram[7] = 78U;

    /* '<S10>:1:17' */
    MySimplifiedTestingModel_2_B.telegramLen = 8U;
  } else {
    if (MySimplifiedTestingModel_2_P.Constant12_Value < 0.0) {
      /* '<S10>:1:22' */
      /* '<S10>:1:23' */
      MySimplifiedTestingModel_2_B.telegram[5] = 45U;

      /* '<S10>:1:24' */
      PCD1_1 = 7U;

      /* '<S10>:1:25' */
      x = -MySimplifiedTestingModel_2_P.Constant12_Value;
    }

    /* '<S10>:1:29' */
    x10 = floor(x * 10.0 + 0.5);

    /* '<S10>:1:30' */
    x = floor(x10 / 10.0);

    /* '<S10>:1:31' */
    x10 -= x * 10.0;

    /* '<S10>:1:34' */
    for (e = 0; e < 10; e++) {
      tmpDigits[e] = 0U;
    }

    /* '<S10>:1:35' */
    PCD1_2 = 0U;
    if (x == 0.0) {
      /* '<S10>:1:37' */
      /* '<S10>:1:38' */
      PCD1_2 = 1U;

      /* '<S10>:1:39' */
      tmpDigits[0] = 48U;
    } else {
      while ((x > 0.0) && (PCD1_2 < 10)) {
        /* '<S10>:1:41' */
        /* '<S10>:1:42' */
        PCD1_2++;

        /* '<S10>:1:43' */
        if (rtIsInf(x)) {
          u1 = (rtNaN);
        } else {
          u1 = fmod(x, 10.0);
        }

        /* '<S10>:1:44' */
        u1 = rt_roundd_snf(u1);
        if (u1 < 256.0) {
          tmp_2 = (uint8_T)u1;
        } else {
          tmp_2 = MAX_uint8_T;
        }

        tmpDigits[PCD1_2 - 1] = (uint8_T)(tmp_2 + 48);

        /* '<S10>:1:45' */
        x /= 10.0;
        x = floor(x);
      }
    }

    /* '<S10>:1:50' */
    exitg1 = false;
    while ((!exitg1) && (PCD1_2 >= 1)) {
      /* '<S10>:1:51' */
      /* '<S10>:1:52' */
      MySimplifiedTestingModel_2_B.telegram[PCD1_1 - 1] = tmpDigits[PCD1_2 - 1];

      /* '<S10>:1:53' */
      e = (int32_T)(PCD1_1 + 1U);
      if ((uint32_T)e > 255U) {
        e = 255;
      }

      PCD1_1 = (uint8_T)e;
      if (PCD1_2 == 1) {
        /* '<S10>:1:54' */
        exitg1 = true;
      } else {
        /* '<S10>:1:57' */
        PCD1_2--;
      }
    }

    /* '<S10>:1:61' */
    MySimplifiedTestingModel_2_B.telegram[PCD1_1 - 1] = 46U;

    /* '<S10>:1:61' */
    e = (int32_T)(PCD1_1 + 1U);
    if ((uint32_T)e > 255U) {
      e = 255;
    }

    PCD1_1 = (uint8_T)e;

    /* '<S10>:1:62' */
    if (x10 < 256.0) {
      if (x10 >= 0.0) {
        tmp_2 = (uint8_T)x10;
      } else {
        tmp_2 = 0U;
      }
    } else {
      tmp_2 = MAX_uint8_T;
    }

    e = (int32_T)(tmp_2 + 48U);
    if ((uint32_T)e > 255U) {
      e = 255;
    }

    MySimplifiedTestingModel_2_B.telegram[PCD1_1 - 1] = (uint8_T)e;

    /* '<S10>:1:62' */
    e = (int32_T)(PCD1_1 + 1U);
    if ((uint32_T)e > 255U) {
      e = 255;
    }

    PCD1_1 = (uint8_T)e;

    /* '<S10>:1:64' */
    MySimplifiedTestingModel_2_B.telegramLen = (uint8_T)(PCD1_1 - 1);
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant15'
   */
  switch ((int32_T)MySimplifiedTestingModel_2_P.Constant_Value) {
   case 0:
    MySimplifiedTestingModel_2_DW.MultiportSwitch_DIMS1[0] = 1;
    MySimplifiedTestingModel_2_DW.MultiportSwitch_DIMS1[1] = 1;
    MySimplifiedTestingModel_2_B.MultiportSwitch[0] =
      MySimplifiedTestingModel_2_P.Constant15_Value;

    /* MultiPortSwitch: '<S1>/Multiport Switch1' incorporates:
     *  Constant: '<S1>/Constant15'
     *  MultiPortSwitch: '<S1>/Multiport Switch'
     */
    MySimplifiedTestingModel_2_B.MultiportSwitch1 =
      MySimplifiedTestingModel_2_P.Constant15_Value;
    break;

   case 1:
    MySimplifiedTestingModel_2_DW.MultiportSwitch_DIMS1[0] = 1;
    MySimplifiedTestingModel_2_DW.MultiportSwitch_DIMS1[1] = 127;
    memcpy(&MySimplifiedTestingModel_2_B.MultiportSwitch[0],
           &MySimplifiedTestingModel_2_B.u[0], 127U * sizeof(uint8_T));

    /* MultiPortSwitch: '<S1>/Multiport Switch1' incorporates:
     *  MultiPortSwitch: '<S1>/Multiport Switch'
     */
    MySimplifiedTestingModel_2_B.MultiportSwitch1 =
      MySimplifiedTestingModel_2_B.length;
    break;

   default:
    MySimplifiedTestingModel_2_DW.MultiportSwitch_DIMS1[0] = 1;
    MySimplifiedTestingModel_2_DW.MultiportSwitch_DIMS1[1] = 32;
    for (e = 0; e < 32; e++) {
      MySimplifiedTestingModel_2_B.MultiportSwitch[e] =
        MySimplifiedTestingModel_2_B.telegram[e];
    }

    /* MultiPortSwitch: '<S1>/Multiport Switch1' incorporates:
     *  MultiPortSwitch: '<S1>/Multiport Switch'
     */
    MySimplifiedTestingModel_2_B.MultiportSwitch1 =
      MySimplifiedTestingModel_2_B.telegramLen;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* Memory: '<S1>/Memory5' */
  MySimplifiedTestingModel_2_B.Memory5 =
    MySimplifiedTestingModel_2_DW.Memory5_PreviousInput;

  /* Memory: '<S1>/Memory16' */
  MySimplifiedTestingModel_2_B.Memory16 =
    MySimplifiedTestingModel_2_DW.Memory16_PreviousInput;

  /* Clock: '<S1>/Clock' */
  MySimplifiedTestingModel_2_B.Clock = MySimplifiedTestingModel_2_M->Timing.t[0];

  /* Memory: '<S1>/Memory17' */
  MySimplifiedTestingModel_2_B.Memory17[0] =
    MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[0];
  MySimplifiedTestingModel_2_B.Memory17[1] =
    MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[1];
  MySimplifiedTestingModel_2_B.Memory17[2] =
    MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[2];
  MySimplifiedTestingModel_2_B.Memory17[3] =
    MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[3];

  /* Memory: '<S1>/Memory8' */
  MySimplifiedTestingModel_2_B.Memory8 =
    MySimplifiedTestingModel_2_DW.Memory8_PreviousInput;

  /* DataTypeConversion: '<S1>/Cast To Boolean9' incorporates:
   *  Constant: '<S1>/Invalid CTW1'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean9 =
    (MySimplifiedTestingModel_2_P.InvalidCTW1_Value != 0.0);

  /* DataTypeConversion: '<S1>/Cast To Boolean10' incorporates:
   *  Constant: '<S1>/ConstantSwitch13'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean10 =
    MySimplifiedTestingModel_2_P.ConstantSwitch13_Value;

  /* Memory: '<S1>/Memory11' */
  MySimplifiedTestingModel_2_B.Memory11 =
    MySimplifiedTestingModel_2_DW.Memory11_PreviousInput;

  /* Memory: '<S1>/Memory12' */
  MySimplifiedTestingModel_2_B.Memory12 =
    MySimplifiedTestingModel_2_DW.Memory12_PreviousInput;

  /* Memory: '<S1>/Memory13' */
  MySimplifiedTestingModel_2_B.Memory13 =
    MySimplifiedTestingModel_2_DW.Memory13_PreviousInput;

  /* Memory: '<S1>/Memory14' */
  memcpy(&MySimplifiedTestingModel_2_B.Memory14[0],
         &MySimplifiedTestingModel_2_DW.Memory14_PreviousInput[0], 127U * sizeof
         (uint8_T));

  /* Memory: '<S1>/Memory15' */
  MySimplifiedTestingModel_2_B.Memory15 =
    MySimplifiedTestingModel_2_DW.Memory15_PreviousInput;

  /* DataTypeConversion: '<S1>/Cast To Boolean11' incorporates:
   *  Constant: '<S1>/ConstantSwitch14'
   */
  u1 = floor(MySimplifiedTestingModel_2_P.ConstantSwitch14_Value);
  if (rtIsNaN(u1) || rtIsInf(u1)) {
    u1 = 0.0;
  } else {
    u1 = fmod(u1, 256.0);
  }

  /* DataTypeConversion: '<S1>/Cast To Boolean11' */
  MySimplifiedTestingModel_2_B.CastToBoolean11 = (uint8_T)(u1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-u1 : (int32_T)(uint8_T)u1);

  /* Chart: '<S1>/THERMO FSM' */
  if (MySimplifiedTestingModel_2_DW.temporalCounter_i2_e < 255U) {
    MySimplifiedTestingModel_2_DW.temporalCounter_i2_e++;
  }

  /* Gateway: RS485/THERMO FSM */
  if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_a < 1U) {
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_a++;
  }

  /* During: RS485/THERMO FSM */
  if (MySimplifiedTestingModel_2_DW.is_active_c13_MySimplifiedTesti == 0U) {
    /* Entry: RS485/THERMO FSM */
    MySimplifiedTestingModel_2_DW.is_active_c13_MySimplifiedTesti = 1U;

    /* Entry Internal: RS485/THERMO FSM */
    /* Transition: '<S13>:26' */
    MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
      MySimplifiedTestingMo_IN_INIT_p;
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_a = 0U;

    /* Entry 'INIT': '<S13>:67' */
    strncpy(&MySimplifiedTestingModel_2_DW.str[0], "", 255U);
    MySimplifiedTestingModel_2_DW.str[255] = '\x00';
    tmp_0 = &MySimplifiedTestingModel_2_DW.str;
    tmp_1 = &c[0];
    for (i = 0; i < 4; i++) {
      (*tmp_0)[i] = tmp_1[i];
    }

    (*tmp_0)[4] = '\x00';
    MySimplifiedTestingModel_2_DW.addr[0] = 65U;
    MySimplifiedTestingModel_2_DW.addr[1] = 48U;
    MySimplifiedTestingModel_2_DW.addr[2] = 48U;
    MySimplifiedTestingModel_2_DW.addr[3] = 53U;
    MySimplifiedTestingModel_2_B.expect_addr[0] =
      MySimplifiedTestingModel_2_DW.addr[0];
    MySimplifiedTestingModel_2_B.expect_addr[1] =
      MySimplifiedTestingModel_2_DW.addr[1];
    MySimplifiedTestingModel_2_B.expect_addr[2] =
      MySimplifiedTestingModel_2_DW.addr[2];
    MySimplifiedTestingModel_2_B.expect_addr[3] =
      MySimplifiedTestingModel_2_DW.addr[3];
    MySimplifiedTestingModel_2_B.expect_len = 0U;
    MySimplifiedTestingModel_2_B.expect_crc_kind = 0U;
    MySimplifiedTestingModel_2_B.req_valid_d = false;
    MySimplifiedTestingModel_2_B.req_len_a = 0U;
    MySimplifiedTestingModel_2_DW.comm_err_count_j = 0U;
  } else {
    switch (MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel) {
     case MySimplifiedTesting_IN_COOLDOWN:
      /* During 'COOLDOWN': '<S13>:63' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_a >= 1) {
        /* Transition: '<S13>:49' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_READY;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_e = 0U;

        /* Entry 'READY': '<S13>:80' */
        MySimplifiedTestingModel_2_B.req_valid_d = false;
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT_m = false;
      }
      break;

     case MySimplifiedTesti_IN_HANDLE_ERR:
      /* During 'HANDLE_ERR': '<S13>:62' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_a >= 1) {
        /* Transition: '<S13>:20' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTesting_IN_COOLDOWN;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1_a = 0U;

        /* Entry 'COOLDOWN': '<S13>:63' */
      }
      break;

     case MySimplifiedTestingMo_IN_INIT_p:
      /* During 'INIT': '<S13>:67' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_a >= 1) {
        /* Transition: '<S13>:37' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_READY;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_e = 0U;

        /* Entry 'READY': '<S13>:80' */
        MySimplifiedTestingModel_2_B.req_valid_d = false;
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT_m = false;
      } else {
        strncpy(&MySimplifiedTestingModel_2_DW.str[0], "", 255U);
        MySimplifiedTestingModel_2_DW.str[255] = '\x00';
        tmp_0 = &MySimplifiedTestingModel_2_DW.str;
        tmp_1 = &b[0];
        for (i = 0; i < 4; i++) {
          (*tmp_0)[i] = tmp_1[i];
        }

        (*tmp_0)[4] = '\x00';
        MySimplifiedTestingModel_2_DW.addr[0] = 65U;
        MySimplifiedTestingModel_2_DW.addr[1] = 48U;
        MySimplifiedTestingModel_2_DW.addr[2] = 48U;
        MySimplifiedTestingModel_2_DW.addr[3] = 53U;
        MySimplifiedTestingModel_2_B.expect_addr[0] =
          MySimplifiedTestingModel_2_DW.addr[0];
        MySimplifiedTestingModel_2_B.expect_addr[1] =
          MySimplifiedTestingModel_2_DW.addr[1];
        MySimplifiedTestingModel_2_B.expect_addr[2] =
          MySimplifiedTestingModel_2_DW.addr[2];
        MySimplifiedTestingModel_2_B.expect_addr[3] =
          MySimplifiedTestingModel_2_DW.addr[3];
        MySimplifiedTestingModel_2_B.expect_len = 0U;
        MySimplifiedTestingModel_2_B.expect_crc_kind = 0U;
        MySimplifiedTestingModel_2_B.req_valid_d = false;
        MySimplifiedTestingModel_2_B.req_len_a = 0U;
        MySimplifiedTestingModel_2_DW.comm_err_count_j = 0U;
      }
      break;

     case MySimplifiedTestingMod_IN_PARSE:
      /* During 'PARSE': '<S13>:61' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i2_e >=
          MySimplifiedTestingModel_2_DW.min_period_ms_f) {
        /* Transition: '<S13>:64' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTesting_IN_COOLDOWN;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1_a = 0U;

        /* Entry 'COOLDOWN': '<S13>:63' */
      }
      break;

     case MySimplifiedTestingMod_IN_READY:
      /* During 'READY': '<S13>:80' */
      if (MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT_m) {
        /* Transition: '<S13>:52' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_WAIT_GRANT;

        /* Entry 'WAIT_GRANT': '<S13>:87' */
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT_m = false;
      } else if (MySimplifiedTestingModel_2_DW.temporalCounter_i2_e >=
                 MySimplifiedTestingModel_2_DW.min_period_ms_f) {
        MySimplifiedTestingMo_thermCom1
          (MySimplifiedTestingModel_2_B.CastToBoolean11,
           MySimplifiedTestingModel_2_B.CastToBoolean10,
           MySimplifiedTestingModel_2_B.req_bytes_k, &PCD1_1);
        MySimplifiedTestingModel_2_B.req_len_a = PCD1_1;
        MySimplifiedTestingModel_2_B.expect_addr[0] =
          MySimplifiedTestingModel_2_DW.addr[0];
        MySimplifiedTestingModel_2_B.expect_addr[1] =
          MySimplifiedTestingModel_2_DW.addr[1];
        MySimplifiedTestingModel_2_B.expect_addr[2] =
          MySimplifiedTestingModel_2_DW.addr[2];
        MySimplifiedTestingModel_2_B.expect_addr[3] =
          MySimplifiedTestingModel_2_DW.addr[3];
        MySimplifiedTestingModel_2_B.expect_len = 0U;
        MySimplifiedTestingModel_2_B.expect_crc_kind = 0U;
        MySimplifiedTestingModel_2_B.req_valid_d = true;
        MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT_m = true;
      }
      break;

     case MySimplifiedTesti_IN_WAIT_GRANT:
      /* During 'WAIT_GRANT': '<S13>:87' */
      if (MySimplifiedTestingModel_2_B.Memory11) {
        /* Transition: '<S13>:65' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTestin_IN_WAIT_RESP;

        /* Entry 'WAIT_RESP': '<S13>:31' */
      } else if (MySimplifiedTestingModel_2_B.Memory13 > 0) {
        /* Transition: '<S13>:27' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_HANDLE_ERR;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1_a = 0U;

        /* Entry 'HANDLE_ERR': '<S13>:62' */
        qY = MySimplifiedTestingModel_2_DW.comm_err_count_j + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        MySimplifiedTestingModel_2_DW.comm_err_count_j = (uint16_T)qY;
      }
      break;

     default:
      /* During 'WAIT_RESP': '<S13>:31' */
      if (MySimplifiedTestingModel_2_B.Memory12) {
        /* Transition: '<S13>:53' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTestingMod_IN_PARSE;
        MySimplifiedTestingModel_2_DW.temporalCounter_i2_e = 0U;

        /* Entry 'PARSE': '<S13>:61' */
      } else if (MySimplifiedTestingModel_2_B.Memory13 > 0) {
        /* Transition: '<S13>:66' */
        MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
          MySimplifiedTesti_IN_HANDLE_ERR;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1_a = 0U;

        /* Entry 'HANDLE_ERR': '<S13>:62' */
        qY = MySimplifiedTestingModel_2_DW.comm_err_count_j + 1U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        MySimplifiedTestingModel_2_DW.comm_err_count_j = (uint16_T)qY;
      } else {
        MySimplifiedTestingModel_2_B.req_valid_d = false;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/THERMO FSM' */

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

  /* Memory: '<S1>/Memory21' */
  MySimplifiedTestingModel_2_B.Memory21 =
    MySimplifiedTestingModel_2_DW.Memory21_PreviousInput;

  /* Memory: '<S1>/Memory9' */
  MySimplifiedTestingModel_2_B.Memory9 =
    MySimplifiedTestingModel_2_DW.Memory9_PreviousInput;

  /* Memory: '<S1>/Memory19' */
  memcpy(&MySimplifiedTestingModel_2_B.Memory19[0],
         &MySimplifiedTestingModel_2_DW.Memory19_PreviousInput[0], 127U * sizeof
         (uint8_T));

  /* Memory: '<S1>/Memory6' */
  memcpy(&MySimplifiedTestingModel_2_B.Memory6[0],
         &MySimplifiedTestingModel_2_DW.Memory6_PreviousInput[0], 127U * sizeof
         (uint8_T));

  /* Memory: '<S1>/Memory18' */
  MySimplifiedTestingModel_2_B.Memory18 =
    MySimplifiedTestingModel_2_DW.Memory18_PreviousInput;

  /* Memory: '<S1>/Memory7' */
  MySimplifiedTestingModel_2_B.Memory7 =
    MySimplifiedTestingModel_2_DW.Memory7_PreviousInput;

  /* Chart: '<S1>/BUS MASTER FSM' incorporates:
   *  Memory: '<S1>/Memory17'
   *  Memory: '<S1>/Memory19'
   *  Memory: '<S1>/Memory6'
   *  MultiPortSwitch: '<S1>/Multiport Switch'
   */
  if (MySimplifiedTestingModel_2_DW.temporalCounter_i2 < 65535U) {
    MySimplifiedTestingModel_2_DW.temporalCounter_i2++;
  }

  /* Gateway: RS485/BUS MASTER FSM */
  if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_f < 1U) {
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_f++;
  }

  /* During: RS485/BUS MASTER FSM */
  if (MySimplifiedTestingModel_2_DW.is_active_c6_MySimplifiedTestin == 0U) {
    /* Entry: RS485/BUS MASTER FSM */
    MySimplifiedTestingModel_2_DW.is_active_c6_MySimplifiedTestin = 1U;

    /* Entry Internal: RS485/BUS MASTER FSM */
    /* Transition: '<S3>:33' */
    MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
      MySimplifiedTestingMode_IN_INIT;
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_f = 0U;

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
      MySimplifiedTestingModel_2_DW.temporalCounter_i1_f = 0U;
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
        e = (int32_T)(MySimplifiedTestingModel_2_DW.pollCounter + 1U);
        if ((uint32_T)e > 255U) {
          e = 255;
        }

        i = MySimplifiedTestingModel_2_DW.pollThermoEvery;
        qY = (uint32_T)i - 1U;
        if (qY > (uint32_T)i) {
          qY = 0U;
        }

        i = (int32_T)qY;
        PCD1_1 = (uint8_T)e;
        PCD1_2 = (uint8_T)i;
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
        e = (int32_T)(MySimplifiedTestingModel_2_DW.pollCounter + 1U);
        if ((uint32_T)e > 255U) {
          e = 255;
        }

        i = MySimplifiedTestingModel_2_DW.pollThermoEvery;
        qY = (uint32_T)i - 1U;
        if (qY > (uint32_T)i) {
          qY = 0U;
        }

        i = (int32_T)qY;
        PCD1_1 = (uint8_T)e;
        PCD1_2 = (uint8_T)i;
        if (PCD1_1 <= PCD1_2) {
          MySimplifiedTestingModel_2_DW.pollCounter = PCD1_1;
        } else {
          MySimplifiedTestingModel_2_DW.pollCounter = PCD1_2;
        }
      }
      break;

     case MySimplifie_IN_DELIVER_OK_PULSE:
      /* During 'DELIVER_OK_PULSE': '<S3>:59' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_f >= 1) {
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
        MySimplifiedTestingModel_2_DW.temporalCounter_i1_f = 0U;

        /* Entry 'LOAD_REQ': '<S3>:36' */
        if (MySimplifiedTestingModel_2_DW.currentDev ==
            MySimplifiedTestingMod_DEV_ZKDM) {
          memcpy(&MySimplifiedTestingModel_2_DW.chosen_req[0],
                 &MySimplifiedTestingModel_2_B.Memory6[0], 127U * sizeof(uint8_T));
          MySimplifiedTestingModel_2_DW.chosen_len =
            MySimplifiedTestingModel_2_B.Memory7;
          MySimplifiedTestingModel_2_DW.chosen_expect_addr_ZKDM =
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
                 &MySimplifiedTestingModel_2_B.Memory19[0], 127U * sizeof
                 (uint8_T));
          MySimplifiedTestingModel_2_DW.chosen_len =
            MySimplifiedTestingModel_2_B.Memory18;
          MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO[0] =
            MySimplifiedTestingModel_2_B.Memory17[0];
          MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO[1] =
            MySimplifiedTestingModel_2_B.Memory17[1];
          MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO[2] =
            MySimplifiedTestingModel_2_B.Memory17[2];
          MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO[3] =
            MySimplifiedTestingModel_2_B.Memory17[3];
          MySimplifiedTestingModel_2_DW.chosen_expect_len =
            MySimplifiedTestingModel_2_B.Memory21;
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
        i = MySimplifiedTestingModel_2_DW.pollThermoEvery;
        qY = (uint32_T)i - 1U;
        if (qY > (uint32_T)i) {
          qY = 0U;
        }

        e = (int32_T)qY;
        if ((MySimplifiedTestingModel_2_DW.pollCounter >= e) &&
            MySimplifiedTestingModel_2_B.Memory16) {
          MySimplifiedTestingModel_2_DW.currentDev =
            MySimplifiedTestingM_DEV_THERMO;
          MySimplifiedTestingModel_2_DW.pollCounter = 0U;
        } else if (MySimplifiedTestingModel_2_B.Memory16 &&
                   (!MySimplifiedTestingModel_2_B.Memory5)) {
          MySimplifiedTestingModel_2_DW.currentDev =
            MySimplifiedTestingM_DEV_THERMO;
        } else {
          MySimplifiedTestingModel_2_DW.currentDev =
            MySimplifiedTestingMod_DEV_NONE;
        }
      }
      break;

     case MySimplifiedTestingMode_IN_INIT:
      MySimplifiedTestingModel_2_B.TX_Trigger = false;

      /* During 'INIT': '<S3>:32' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_f >= 1) {
        /* Transition: '<S3>:35' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestingMode_IN_IDLE;
        MySimplifiedT_enter_atomic_IDLE();
      }
      break;

     case MySimplifiedTesting_IN_LOAD_REQ:
      /* During 'LOAD_REQ': '<S3>:36' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_f >= 1) {
        /* Transition: '<S3>:44' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTestin_IN_WAIT_THRE;
      }
      break;

     case MySimplifi_IN_RETRY_OR_BACKOFF1:
      /* During 'RETRY_OR_BACKOFF1': '<S3>:278' */
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_f >= 1) {
        /* Transition: '<S3>:431' */
        memset(&MySimplifiedTestingModel_2_DW.rxBuf[0], 0, 127U * sizeof(uint8_T));
        MySimplifiedTestingModel_2_DW.rxCount = 0U;
        if (MySimplifiedTestingModel_2_DW.retry <
            MySimplifiedTestingModel_2_DW.maxRetry) {
          /* Transition: '<S3>:266' */
          /* Transition: '<S3>:268' */
          e = (int32_T)(MySimplifiedTestingModel_2_DW.retry + 1U);
          if ((uint32_T)e > 255U) {
            e = 255;
          }

          MySimplifiedTestingModel_2_DW.retry = (uint8_T)e;

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
      if (MySimplifiedTestingModel_2_DW.temporalCounter_i1_f >= 1) {
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
        e = (int32_T)((uint32_T)MySimplifiedTestingModel_2_DW.rxCount +
                      MySimplifiedTestingModel_2_B.MultiportSwitch1);
        if ((uint32_T)e > 255U) {
          e = 255;
        }

        okAddr = ((e <= 127) && (MySimplifiedTestingModel_2_B.MultiportSwitch1 >
                   0));
        if (okAddr) {
          /* Transition: '<S3>:391' */
          /* Transition: '<S3>:393' */
          if (MySimplifiedTestingModel_2_B.MultiportSwitch1 < 1) {
            i = -1;
          } else {
            i = MySimplifiedTestingModel_2_B.MultiportSwitch1 - 1;
          }

          e = (int32_T)(MySimplifiedTestingModel_2_DW.rxCount + 1U);
          if ((uint32_T)e > 255U) {
            e = 255;
          }

          PCD1_1 = (uint8_T)e;
          e = (int32_T)((uint32_T)MySimplifiedTestingModel_2_DW.rxCount +
                        MySimplifiedTestingModel_2_B.MultiportSwitch1);
          if ((uint32_T)e > 255U) {
            e = 255;
          }

          PCD1_2 = (uint8_T)e;
          if (PCD1_1 > PCD1_2) {
            idx = 1;
          } else {
            idx = PCD1_1;
          }

          for (e = 0; e <= i; e++) {
            MySimplifiedTestingModel_2_DW.rxBuf[(idx + e) - 1] =
              MySimplifiedTestingModel_2_B.MultiportSwitch[e];
          }

          e = (int32_T)((uint32_T)MySimplifiedTestingModel_2_DW.rxCount +
                        MySimplifiedTestingModel_2_B.MultiportSwitch1);
          if ((uint32_T)e > 255U) {
            e = 255;
          }

          MySimplifiedTestingModel_2_DW.rxCount = (uint8_T)e;

          /* Transition: '<S3>:421' */
        } else {
          e = (int32_T)((uint32_T)MySimplifiedTestingModel_2_DW.rxCount +
                        MySimplifiedTestingModel_2_B.MultiportSwitch1);
          if ((uint32_T)e > 255U) {
            e = 255;
          }

          if (e > 127) {
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
            if (MySimplifiedTestingModel_2_DW.currentDev ==
                MySimplifiedTestingMod_DEV_ZKDM) {
              /* Transition: '<S3>:450' */
              /* Transition: '<S3>:452' */
              okAddr = MySimplifiedTestingMode_addr_ok
                (MySimplifiedTestingModel_2_DW.rxBuf,
                 MySimplifiedTestingModel_2_DW.rxCount,
                 MySimplifiedTestingModel_2_DW.chosen_expect_addr_ZKDM);
              okLen = MySimplifiedTestingModel_len_ok
                (MySimplifiedTestingModel_2_DW.rxCount,
                 MySimplifiedTestingModel_2_DW.chosen_expect_len);
              okCrc = MySimplifiedTestingModel_crc_ok
                (MySimplifiedTestingModel_2_DW.rxBuf,
                 MySimplifiedTestingModel_2_DW.rxCount);

              /* Transition: '<S3>:453' */
            } else {
              /* Transition: '<S3>:454' */
              okAddr = MySimplifiedTes_addr_ok_thermo1
                (MySimplifiedTestingModel_2_DW.rxBuf,
                 MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO);
              okLen = true;
              okCrc = true;
            }

            /* Transition: '<S3>:257' */
            if (!okAddr) {
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
            } else if (!okLen) {
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
              MySimplifiedTestingModel_2_DW.temporalCounter_i1_f = 0U;
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
      okAddr = (MySimplifiedTestingModel_2_B.CastToBoolean3 &&
                MySimplifiedTestingModel_2_B.CastToBoolean6);
      if (okAddr) {
        /* Transition: '<S3>:47' */
        MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
          MySimplifiedTesting_IN_TX_PULSE;
        MySimplifiedTestingModel_2_DW.temporalCounter_i1_f = 0U;

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
      MySimplifiedTestingModel_2_DW.temporalCounter_i1_f = 0U;
    }
  }

  /* End of Chart: '<S1>/BUS MASTER FSM' */

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
  u1 = rt_roundd_snf(MySimplifiedTestingModel_2_B.Saturation * 163.84);
  if (u1 < 65536.0) {
    if (u1 >= 0.0) {
      status_word = (uint16_T)u1;
    } else {
      status_word = 0U;
    }
  } else {
    status_word = MAX_uint16_T;
  }

  /* '<S4>:1:83' */
  memcpy((void *)&pcd2split[0], (void *)&status_word, (size_t)2 * sizeof(uint8_T));

  /* '<S4>:1:85' */
  for (i = 0; i < 16; i++) {
    sfull[i] = '0';
    if ((1 << (15 - i) & status_word) != 0) {
      sfull[i] = '1';
    }
  }

  idx = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 16)) {
    if (sfull[i] == '1') {
      idx = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (idx == 0) {
    idx = 16;
  }

  e = 16 - idx;
  if (17 - idx < 16) {
    npad = idx - 1;
    for (i = 0; i < npad; i++) {
      pcd2binary[i] = '0';
    }
  } else {
    npad = 0;
  }

  for (i = 0; i <= e; i++) {
    pcd2binary[npad + i] = sfull[(idx + i) - 1];
  }

  /* '<S4>:1:86' */
  for (i = 0; i < 8; i++) {
    tmp = pcd2binary[i];
    pcd2binary[i] = pcd2binary[15 - i];
    pcd2binary[15 - i] = tmp;
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
  u1 = MySimplifiedTestingMode_bin2dec(&pcd2binary[0]);
  x = MySimplifiedTestingMode_bin2dec(&pcd2binary[8]);
  u1 = rt_roundd_snf(u1);
  if (u1 < 256.0) {
    if (u1 >= 0.0) {
      tmp_2 = (uint8_T)u1;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  MySimplifiedTestingModel_2_B.command[5] = tmp_2;
  u1 = rt_roundd_snf(x);
  if (u1 < 256.0) {
    if (u1 >= 0.0) {
      tmp_2 = (uint8_T)u1;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  MySimplifiedTestingModel_2_B.command[6] = tmp_2;

  /* '<S4>:1:106' */
  MySimplifiedTestingModel_2_B.command[7] = (uint8_T)(PCD1_1 ^ 121 ^ PCD1_2 ^
    pcd2split[0] ^ pcd2split[1]);
  MySimplifiedTestingModel_2_B.pcd2 = status_word;

  /* End of MATLAB Function: '<S1>/Create 8-Bytes Command' */

  /* DataTypeConversion: '<S1>/Cast1' */
  MySimplifiedTestingModel_2_B.Cast1[0] =
    MySimplifiedTestingModel_2_B.debug_pcd2[0];
  MySimplifiedTestingModel_2_B.Cast1[1] =
    MySimplifiedTestingModel_2_B.debug_pcd2[1];

  /* DataTypeConversion: '<S1>/Cast To Double' incorporates:
   *  DataTypeConversion: '<S1>/Cast1'
   */
  MySimplifiedTestingModel_2_B.CastToDouble[0] =
    MySimplifiedTestingModel_2_B.Cast1[0];
  MySimplifiedTestingModel_2_B.CastToDouble[1] =
    MySimplifiedTestingModel_2_B.Cast1[1];

  /* S-Function (any2byte_svd): '<S1>/Byte Pack' */

  /* Pack: <S1>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint16_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 2 */
    {
      MW_inputPortWidth = 2 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&MySimplifiedTestingModel_2_B.BytePack +
                        MW_outputPortOffset), (uint8_T*)
             &MySimplifiedTestingModel_2_B.debug_pcd2[0], MW_inputPortWidth);
    }
  }

  /* MATLAB Function: '<S1>/MATLAB Function' */
  /* MATLAB Function 'RS485/MATLAB Function': '<S9>:1' */
  /* '<S9>:1:2' */
  /* '<S9>:1:3' */
  u1 = rt_roundd_snf(MySimplifiedTestingModel_2_B.Saturation * 163.84);
  if (u1 < 32768.0) {
    if (u1 >= -32768.0) {
      x_0 = (int16_T)u1;
    } else {
      x_0 = MIN_int16_T;
    }
  } else {
    x_0 = MAX_int16_T;
  }

  memcpy((void *)&MySimplifiedTestingModel_2_B.y[0], (void *)&x_0, (size_t)2 *
         sizeof(uint8_T));

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Outputs for Triggered SubSystem: '<S1>/Subsystem' incorporates:
   *  TriggerPort: '<S12>/Trigger'
   */
  /* '<S9>:1:4' */
  okAddr = (MySimplifiedTestingModel_2_B.TX_Trigger &&
            (MySimplifiedTestingMode_PrevZCX.Subsystem_Trig_ZCE != POS_ZCSIG));
  if (okAddr) {
    /* DataTypeConversion: '<S12>/Cast' */
    MySimplifiedTestingModel_2_B.Cast = MySimplifiedTestingModel_2_B.TX_Len;

    /* Reshape: '<S12>/Reshape' */
    MySimplifiedTestingModel_2_B.Reshape = MySimplifiedTestingModel_2_B.Cast;

    /* S-Function (rti_commonblock): '<S15>/S-Function1' */
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
  x = MySimplifiedTestingModel_2_P.Constant1_Value;
  u1 = MySimplifiedTestingModel_2_P.BegrenzungArbeitstemperatur1_Lo;
  x10 = MySimplifiedTestingModel_2_P.BegrenzungArbeitstemperatur1_Up;
  if (x > x10) {
    x = x10;
  } else if (x < u1) {
    x = u1;
  }

  u1 = floor(x);
  if (rtIsNaN(u1)) {
    e = 0;
  } else {
    e = (int32_T)u1;
  }

  /* Saturate: '<S1>/Begrenzung Arbeitstemperatur1' */
  MySimplifiedTestingModel_2_B.BegrenzungArbeitstemperatur1 = (uint8_T)e;

  /* S-Function (rti_commonblock): '<S8>/S-Function1' */
  /* This comment workarounds a code generation problem */

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

  /* DataTypeConversion: '<S1>/Cast To Boolean2' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  MySimplifiedTestingModel_2_B.CastToBoolean2 =
    (MySimplifiedTestingModel_2_P.Constant5_Value != 0.0);

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

  /* Memory: '<S1>/Memory20' */
  MySimplifiedTestingModel_2_B.Memory20 =
    MySimplifiedTestingModel_2_DW.Memory20_PreviousInput;

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

  /* Update for Memory: '<S1>/Memory16' */
  MySimplifiedTestingModel_2_DW.Memory16_PreviousInput =
    MySimplifiedTestingModel_2_B.req_valid_d;

  /* Update for Memory: '<S1>/Memory17' */
  MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[0] =
    MySimplifiedTestingModel_2_B.expect_addr[0];
  MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[1] =
    MySimplifiedTestingModel_2_B.expect_addr[1];
  MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[2] =
    MySimplifiedTestingModel_2_B.expect_addr[2];
  MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[3] =
    MySimplifiedTestingModel_2_B.expect_addr[3];

  /* Update for Memory: '<S1>/Memory8' */
  MySimplifiedTestingModel_2_DW.Memory8_PreviousInput =
    MySimplifiedTestingModel_2_B.expect_addr_ZKDM;

  /* Update for Memory: '<S1>/Memory11' */
  MySimplifiedTestingModel_2_DW.Memory11_PreviousInput =
    MySimplifiedTestingModel_2_B.grant_THERMO;

  /* Update for Memory: '<S1>/Memory12' */
  MySimplifiedTestingModel_2_DW.Memory12_PreviousInput =
    MySimplifiedTestingModel_2_B.resp_ok_THERMO;

  /* Update for Memory: '<S1>/Memory13' */
  MySimplifiedTestingModel_2_DW.Memory13_PreviousInput =
    MySimplifiedTestingModel_2_B.resp_err_THERMO;

  /* Update for Memory: '<S1>/Memory14' */
  memcpy(&MySimplifiedTestingModel_2_DW.Memory14_PreviousInput[0],
         &MySimplifiedTestingModel_2_B.resp_data[0], 127U * sizeof(uint8_T));

  /* Update for Memory: '<S1>/Memory15' */
  MySimplifiedTestingModel_2_DW.Memory15_PreviousInput =
    MySimplifiedTestingModel_2_B.resp_len;

  /* Update for Memory: '<S1>/Memory10' */
  MySimplifiedTestingModel_2_DW.Memory10_PreviousInput =
    MySimplifiedTestingModel_2_B.expect_crc_kind_ZKDM;

  /* Update for Memory: '<S1>/Memory21' */
  MySimplifiedTestingModel_2_DW.Memory21_PreviousInput =
    MySimplifiedTestingModel_2_B.expect_len;

  /* Update for Memory: '<S1>/Memory9' */
  MySimplifiedTestingModel_2_DW.Memory9_PreviousInput =
    MySimplifiedTestingModel_2_B.expect_len_ZKDM;

  /* Update for Memory: '<S1>/Memory19' */
  memcpy(&MySimplifiedTestingModel_2_DW.Memory19_PreviousInput[0],
         &MySimplifiedTestingModel_2_B.req_bytes_k[0], 127U * sizeof(uint8_T));

  /* Update for Memory: '<S1>/Memory6' */
  memcpy(&MySimplifiedTestingModel_2_DW.Memory6_PreviousInput[0],
         &MySimplifiedTestingModel_2_B.req_bytes[0], 127U * sizeof(uint8_T));

  /* Update for Memory: '<S1>/Memory18' */
  MySimplifiedTestingModel_2_DW.Memory18_PreviousInput =
    MySimplifiedTestingModel_2_B.req_len_a;

  /* Update for Memory: '<S1>/Memory7' */
  MySimplifiedTestingModel_2_DW.Memory7_PreviousInput =
    MySimplifiedTestingModel_2_B.req_len;

  /* Update for Memory: '<S1>/Memory20' */
  MySimplifiedTestingModel_2_DW.Memory20_PreviousInput = 0.0;

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

    /* InitializeConditions for Memory: '<S1>/Memory16' */
    MySimplifiedTestingModel_2_DW.Memory16_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory16_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory17' */
    MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[0] =
      MySimplifiedTestingModel_2_P.Memory17_InitialCondition;
    MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[1] =
      MySimplifiedTestingModel_2_P.Memory17_InitialCondition;
    MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[2] =
      MySimplifiedTestingModel_2_P.Memory17_InitialCondition;
    MySimplifiedTestingModel_2_DW.Memory17_PreviousInput[3] =
      MySimplifiedTestingModel_2_P.Memory17_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory8' */
    MySimplifiedTestingModel_2_DW.Memory8_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory8_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory11' */
    MySimplifiedTestingModel_2_DW.Memory11_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory11_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory12' */
    MySimplifiedTestingModel_2_DW.Memory12_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory12_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory13' */
    MySimplifiedTestingModel_2_DW.Memory13_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory13_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory15' */
    MySimplifiedTestingModel_2_DW.Memory15_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory15_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory10' */
    MySimplifiedTestingModel_2_DW.Memory10_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory10_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory21' */
    MySimplifiedTestingModel_2_DW.Memory21_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory21_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory9' */
    MySimplifiedTestingModel_2_DW.Memory9_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory9_InitialCondition;
    for (i = 0; i < 127; i++) {
      /* InitializeConditions for Memory: '<S1>/Memory3' */
      MySimplifiedTestingModel_2_DW.Memory3_PreviousInput[i] =
        MySimplifiedTestingModel_2_P.Memory3_InitialCondition;

      /* InitializeConditions for Memory: '<S1>/Memory14' */
      MySimplifiedTestingModel_2_DW.Memory14_PreviousInput[i] =
        MySimplifiedTestingModel_2_P.Memory14_InitialCondition;

      /* InitializeConditions for Memory: '<S1>/Memory19' */
      MySimplifiedTestingModel_2_DW.Memory19_PreviousInput[i] =
        MySimplifiedTestingModel_2_P.Memory19_InitialCondition;

      /* InitializeConditions for Memory: '<S1>/Memory6' */
      MySimplifiedTestingModel_2_DW.Memory6_PreviousInput[i] =
        MySimplifiedTestingModel_2_P.Memory6_InitialCondition;
    }

    /* InitializeConditions for Memory: '<S1>/Memory18' */
    MySimplifiedTestingModel_2_DW.Memory18_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory18_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory7' */
    MySimplifiedTestingModel_2_DW.Memory7_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory7_InitialCondition;

    /* InitializeConditions for Memory: '<S1>/Memory20' */
    MySimplifiedTestingModel_2_DW.Memory20_PreviousInput =
      MySimplifiedTestingModel_2_P.Memory20_InitialCondition;

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

    /* SystemInitialize for Chart: '<S1>/THERMO FSM' */
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_a = 0U;
    MySimplifiedTestingModel_2_DW.temporalCounter_i2_e = 0U;
    MySimplifiedTestingModel_2_DW.is_active_c13_MySimplifiedTesti = 0U;
    MySimplifiedTestingModel_2_DW.is_c13_MySimplifiedTestingModel =
      MySimplified_IN_NO_ACTIVE_CHILD;
    MySimplifiedTestingModel_2_DW.addr[0] = 0U;
    MySimplifiedTestingModel_2_DW.addr[1] = 0U;
    MySimplifiedTestingModel_2_DW.addr[2] = 0U;
    MySimplifiedTestingModel_2_DW.addr[3] = 0U;
    MySimplifiedTestingModel_2_DW.min_period_ms_f = 50U;
    MySimplifiedTestingModel_2_DW.READY_to_WAIT_GRANT_m = false;
    MySimplifiedTestingModel_2_DW.comm_err_count_j = 0U;
    strncpy(&MySimplifiedTestingModel_2_DW.str[0], "", 255U);
    MySimplifiedTestingModel_2_DW.str[255] = '\x00';
    MySimplifiedTestingModel_2_B.req_valid_d = false;
    memset(&MySimplifiedTestingModel_2_B.req_bytes_k[0], 0, 127U * sizeof
           (uint8_T));
    MySimplifiedTestingModel_2_B.req_len_a = 0U;
    MySimplifiedTestingModel_2_B.expect_addr[0] = 0U;
    MySimplifiedTestingModel_2_B.expect_addr[1] = 0U;
    MySimplifiedTestingModel_2_B.expect_addr[2] = 0U;
    MySimplifiedTestingModel_2_B.expect_addr[3] = 0U;
    MySimplifiedTestingModel_2_B.expect_len = 0U;
    MySimplifiedTestingModel_2_B.expect_crc_kind = 0U;

    /* SystemInitialize for Chart: '<S1>/BUS MASTER FSM' */
    MySimplifiedTestingModel_2_DW.temporalCounter_i1_f = 0U;
    MySimplifiedTestingModel_2_DW.temporalCounter_i2 = 0U;
    MySimplifiedTestingModel_2_DW.is_active_c6_MySimplifiedTestin = 0U;
    MySimplifiedTestingModel_2_DW.is_c6_MySimplifiedTestingModel_ =
      MySimplified_IN_NO_ACTIVE_CHILD;
    MySimplifiedTestingModel_2_DW.interGap_ms = 5U;
    MySimplifiedTestingModel_2_DW.maxRetry = 1U;
    MySimplifiedTestingModel_2_DW.pollThermoEvery = 4U;
    MySimplifiedTestingModel_2_DW.timeout_ms_THERMO = 80U;
    MySimplifiedTestingModel_2_DW.timeout_ms_ZKDM = 20U;
    MySimplifiedTestingModel_2_DW.chosen_expect_addr_ZKDM = 0U;
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
    MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO[0] = 0U;
    MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO[1] = 0U;
    MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO[2] = 0U;
    MySimplifiedTestingModel_2_DW.chosen_expect_addr_THERMO[3] = 0U;
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
    /* SystemInitialize for S-Function (rti_commonblock): '<S15>/S-Function1' incorporates:
     *  Outport: '<S12>/Status'
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
