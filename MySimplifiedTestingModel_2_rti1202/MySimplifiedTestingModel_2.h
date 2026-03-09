/*
 * MySimplifiedTestingModel_2.h
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

#ifndef RTW_HEADER_MySimplifiedTestingModel_2_h_
#define RTW_HEADER_MySimplifiedTestingModel_2_h_
#ifndef MySimplifiedTestingModel_2_COMMON_INCLUDES_
#define MySimplifiedTestingModel_2_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <dsser.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#endif                         /* MySimplifiedTestingModel_2_COMMON_INCLUDES_ */

#include "MySimplifiedTestingModel_2_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Saturation;                   /* '<S1>/Saturation' */
  real_T CastToBoolean8;               /* '<S1>/Cast To Boolean8' */
  real_T BegrenzungArbeitstemperatur3;/* '<S1>/Begrenzung Arbeitstemperatur3' */
  real_T Clock;                        /* '<S1>/Clock' */
  real_T CastToBoolean10;              /* '<S1>/Cast To Boolean10' */
  real_T CastToDouble[2];              /* '<S1>/Cast To Double' */
  real_T Memory20;                     /* '<S1>/Memory20' */
  real_T freq_rel;                     /* '<S1>/ZKDM FSM' */
  uint32_T SFunction1_o2;              /* '<S5>/S-Function1' */
  uint32_T Cast;                       /* '<S12>/Cast' */
  uint32_T Reshape;                    /* '<S12>/Reshape' */
  int32_T SFunction1_o3;               /* '<S5>/S-Function1' */
  int32_T SFunction1;                  /* '<S15>/S-Function1' */
  uint16_T Cast1[2];                   /* '<S1>/Cast1' */
  uint16_T BytePack;                   /* '<S1>/Byte Pack' */
  uint16_T debug_command[8];           /* '<S1>/ZKDM FSM' */
  uint16_T pcd2;                       /* '<S1>/Create 8-Bytes Command' */
  uint8_T Memory3[127];                /* '<S1>/Memory3' */
  uint8_T Memory2;                     /* '<S1>/Memory2' */
  uint8_T Memory4;                     /* '<S1>/Memory4' */
  uint8_T MultiportSwitch[127];        /* '<S1>/Multiport Switch' */
  uint8_T MultiportSwitch1;            /* '<S1>/Multiport Switch1' */
  uint8_T Memory17[4];                 /* '<S1>/Memory17' */
  uint8_T Memory8;                     /* '<S1>/Memory8' */
  uint8_T Memory13;                    /* '<S1>/Memory13' */
  uint8_T Memory14[127];               /* '<S1>/Memory14' */
  uint8_T Memory15;                    /* '<S1>/Memory15' */
  uint8_T CastToBoolean11;             /* '<S1>/Cast To Boolean11' */
  uint8_T Memory10;                    /* '<S1>/Memory10' */
  uint8_T Memory21;                    /* '<S1>/Memory21' */
  uint8_T Memory9;                     /* '<S1>/Memory9' */
  uint8_T Memory19[127];               /* '<S1>/Memory19' */
  uint8_T Memory6[127];                /* '<S1>/Memory6' */
  uint8_T Memory18;                    /* '<S1>/Memory18' */
  uint8_T Memory7;                     /* '<S1>/Memory7' */
  uint8_T BegrenzungArbeitstemperatur1;
                                      /* '<S1>/Begrenzung Arbeitstemperatur1' */
  uint8_T SFunction1_o1[127];          /* '<S5>/S-Function1' */
  uint8_T Cast_g;                      /* '<S1>/Cast' */
  uint8_T Constant6;                   /* '<S1>/Constant6' */
  uint8_T Constant7;                   /* '<S1>/Constant7' */
  uint8_T Constant8;                   /* '<S1>/Constant8' */
  uint8_T Length;                      /* '<S1>/Length' */
  uint8_T req_bytes[127];              /* '<S1>/ZKDM FSM' */
  uint8_T req_len;                     /* '<S1>/ZKDM FSM' */
  uint8_T expect_addr_ZKDM;            /* '<S1>/ZKDM FSM' */
  uint8_T expect_crc_kind_ZKDM;        /* '<S1>/ZKDM FSM' */
  uint8_T expect_len_ZKDM;             /* '<S1>/ZKDM FSM' */
  uint8_T debug_pcd2[2];               /* '<S1>/ZKDM FSM' */
  uint8_T req_bytes_k[127];            /* '<S1>/THERMO FSM' */
  uint8_T req_len_a;                   /* '<S1>/THERMO FSM' */
  uint8_T expect_addr[4];              /* '<S1>/THERMO FSM' */
  uint8_T expect_len;                  /* '<S1>/THERMO FSM' */
  uint8_T expect_crc_kind;             /* '<S1>/THERMO FSM' */
  uint8_T u[127];                      /* '<S1>/MATLAB Function4' */
  uint8_T length;                      /* '<S1>/MATLAB Function4' */
  uint8_T telegram[32];                /* '<S1>/MATLAB Function1' */
  uint8_T telegramLen;                 /* '<S1>/MATLAB Function1' */
  uint8_T y[2];                        /* '<S1>/MATLAB Function' */
  uint8_T command[127];                /* '<S1>/Create 8-Bytes Command' */
  uint8_T TX_Data[127];                /* '<S1>/BUS MASTER FSM' */
  uint8_T TX_Len;                      /* '<S1>/BUS MASTER FSM' */
  uint8_T resp_err_ZKDM;               /* '<S1>/BUS MASTER FSM' */
  uint8_T resp_data[127];              /* '<S1>/BUS MASTER FSM' */
  uint8_T resp_err_THERMO;             /* '<S1>/BUS MASTER FSM' */
  uint8_T resp_len;                    /* '<S1>/BUS MASTER FSM' */
  boolean_T CastToBoolean1;            /* '<S1>/Cast To Boolean1' */
  boolean_T Memory;                    /* '<S1>/Memory' */
  boolean_T Memory1;                   /* '<S1>/Memory1' */
  boolean_T CastToBoolean;             /* '<S1>/Cast To Boolean' */
  boolean_T CastToBoolean5;            /* '<S1>/Cast To Boolean5' */
  boolean_T CastToBoolean3;            /* '<S1>/Cast To Boolean3' */
  boolean_T Memory5;                   /* '<S1>/Memory5' */
  boolean_T Memory16;                  /* '<S1>/Memory16' */
  boolean_T CastToBoolean9;            /* '<S1>/Cast To Boolean9' */
  boolean_T Memory11;                  /* '<S1>/Memory11' */
  boolean_T Memory12;                  /* '<S1>/Memory12' */
  boolean_T CastToBoolean6;            /* '<S1>/Cast To Boolean6' */
  boolean_T CastToBoolean7;            /* '<S1>/Cast To Boolean7' */
  boolean_T SFunction1_o1_p[8];        /* '<S8>/S-Function1' */
  boolean_T SFunction1_o2_i[8];        /* '<S8>/S-Function1' */
  boolean_T SFunction1_o3_h[8];        /* '<S8>/S-Function1' */
  boolean_T CastToBoolean2;            /* '<S1>/Cast To Boolean2' */
  boolean_T CastToBoolean4;            /* '<S1>/Cast To Boolean4' */
  boolean_T req_valid;                 /* '<S1>/ZKDM FSM' */
  boolean_T fault_no_trip;             /* '<S1>/ZKDM FSM' */
  boolean_T fault_trip;                /* '<S1>/ZKDM FSM' */
  boolean_T fu_ctrl_ready;             /* '<S1>/ZKDM FSM' */
  boolean_T fu_ready;                  /* '<S1>/ZKDM FSM' */
  boolean_T bus_ctrl_active;           /* '<S1>/ZKDM FSM' */
  boolean_T req_valid_d;               /* '<S1>/THERMO FSM' */
  boolean_T TX_Trigger;                /* '<S1>/BUS MASTER FSM' */
  boolean_T grant_ZKDM;                /* '<S1>/BUS MASTER FSM' */
  boolean_T resp_ok_ZKDM;              /* '<S1>/BUS MASTER FSM' */
  boolean_T grant_THERMO;              /* '<S1>/BUS MASTER FSM' */
  boolean_T resp_ok_THERMO;            /* '<S1>/BUS MASTER FSM' */
} B_MySimplifiedTestingModel_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory20_PreviousInput;       /* '<S1>/Memory20' */
  char_T str[256];                     /* '<S1>/THERMO FSM' */
  int32_T MultiportSwitch_DIMS1[2];    /* '<S1>/Multiport Switch' */
  uint16_T comm_err_count;             /* '<S1>/ZKDM FSM' */
  uint16_T comm_err_count_j;           /* '<S1>/THERMO FSM' */
  uint16_T interGap_ms;                /* '<S1>/BUS MASTER FSM' */
  uint16_T timeout_ms_THERMO;          /* '<S1>/BUS MASTER FSM' */
  uint16_T timeout_ms_ZKDM;            /* '<S1>/BUS MASTER FSM' */
  uint16_T timeout_ms;                 /* '<S1>/BUS MASTER FSM' */
  uint16_T temporalCounter_i2;         /* '<S1>/BUS MASTER FSM' */
  uint8_T Memory3_PreviousInput[127];  /* '<S1>/Memory3' */
  uint8_T Memory2_PreviousInput;       /* '<S1>/Memory2' */
  uint8_T Memory4_PreviousInput;       /* '<S1>/Memory4' */
  uint8_T Memory17_PreviousInput[4];   /* '<S1>/Memory17' */
  uint8_T Memory8_PreviousInput;       /* '<S1>/Memory8' */
  uint8_T Memory13_PreviousInput;      /* '<S1>/Memory13' */
  uint8_T Memory14_PreviousInput[127]; /* '<S1>/Memory14' */
  uint8_T Memory15_PreviousInput;      /* '<S1>/Memory15' */
  uint8_T Memory10_PreviousInput;      /* '<S1>/Memory10' */
  uint8_T Memory21_PreviousInput;      /* '<S1>/Memory21' */
  uint8_T Memory9_PreviousInput;       /* '<S1>/Memory9' */
  uint8_T Memory19_PreviousInput[127]; /* '<S1>/Memory19' */
  uint8_T Memory6_PreviousInput[127];  /* '<S1>/Memory6' */
  uint8_T Memory18_PreviousInput;      /* '<S1>/Memory18' */
  uint8_T Memory7_PreviousInput;       /* '<S1>/Memory7' */
  uint8_T fc_addr;                     /* '<S1>/ZKDM FSM' */
  uint8_T min_period_ms;               /* '<S1>/ZKDM FSM' */
  uint8_T tx_len;                      /* '<S1>/ZKDM FSM' */
  uint8_T is_active_c11_MySimplifiedTesti;/* '<S1>/ZKDM FSM' */
  uint8_T is_c11_MySimplifiedTestingModel;/* '<S1>/ZKDM FSM' */
  uint8_T REV8[256];                   /* '<S1>/ZKDM FSM' */
  uint8_T temporalCounter_i1;          /* '<S1>/ZKDM FSM' */
  uint8_T temporalCounter_i2_i;        /* '<S1>/ZKDM FSM' */
  uint8_T addr[4];                     /* '<S1>/THERMO FSM' */
  uint8_T min_period_ms_f;             /* '<S1>/THERMO FSM' */
  uint8_T is_active_c13_MySimplifiedTesti;/* '<S1>/THERMO FSM' */
  uint8_T is_c13_MySimplifiedTestingModel;/* '<S1>/THERMO FSM' */
  uint8_T temporalCounter_i1_a;        /* '<S1>/THERMO FSM' */
  uint8_T temporalCounter_i2_e;        /* '<S1>/THERMO FSM' */
  uint8_T maxRetry;                    /* '<S1>/BUS MASTER FSM' */
  uint8_T pollThermoEvery;             /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_expect_addr_ZKDM;     /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_expect_len;           /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_len;                  /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_req[127];             /* '<S1>/BUS MASTER FSM' */
  uint8_T currentDev;                  /* '<S1>/BUS MASTER FSM' */
  uint8_T pollCounter;                 /* '<S1>/BUS MASTER FSM' */
  uint8_T retry;                       /* '<S1>/BUS MASTER FSM' */
  uint8_T rxBuf[127];                  /* '<S1>/BUS MASTER FSM' */
  uint8_T rxCount;                     /* '<S1>/BUS MASTER FSM' */
  uint8_T err_THERMO;                  /* '<S1>/BUS MASTER FSM' */
  uint8_T err_ZKDM;                    /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_expect_addr_THERMO[4];/* '<S1>/BUS MASTER FSM' */
  uint8_T is_active_c6_MySimplifiedTestin;/* '<S1>/BUS MASTER FSM' */
  uint8_T is_c6_MySimplifiedTestingModel_;/* '<S1>/BUS MASTER FSM' */
  uint8_T temporalCounter_i1_f;        /* '<S1>/BUS MASTER FSM' */
  boolean_T Memory_PreviousInput;      /* '<S1>/Memory' */
  boolean_T Memory1_PreviousInput;     /* '<S1>/Memory1' */
  boolean_T Memory5_PreviousInput;     /* '<S1>/Memory5' */
  boolean_T Memory16_PreviousInput;    /* '<S1>/Memory16' */
  boolean_T Memory11_PreviousInput;    /* '<S1>/Memory11' */
  boolean_T Memory12_PreviousInput;    /* '<S1>/Memory12' */
  boolean_T READY_to_WAIT_GRANT;       /* '<S1>/ZKDM FSM' */
  boolean_T REV8_not_empty;            /* '<S1>/ZKDM FSM' */
  boolean_T READY_to_WAIT_GRANT_m;     /* '<S1>/THERMO FSM' */
} DW_MySimplifiedTestingModel_2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<S1>/Subsystem' */
} PrevZCX_MySimplifiedTestingMo_T;

/* Parameters (default storage) */
struct P_MySimplifiedTestingModel_2_T_ {
  real_T Active_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/Active'
                                        */
  real_T Setpoint_Value;               /* Expression: 100
                                        * Referenced by: '<S1>/Setpoint'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T InvalidCTW_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Invalid CTW'
                                        */
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant16'
                                        */
  real_T ConstantSwitch12_Value;       /* Expression: 34
                                        * Referenced by: '<S1>/ConstantSwitch12'
                                        */
  real_T Constant10_Value;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant10'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T ConstantSwitch7_Value;        /* Expression: 1
                                        * Referenced by: '<S1>/ConstantSwitch7'
                                        */
  real_T ConstantSwitch8_Value;        /* Expression: 0
                                        * Referenced by: '<S1>/ConstantSwitch8'
                                        */
  real_T ConstantSwitch9_Value;        /* Expression: 0
                                        * Referenced by: '<S1>/ConstantSwitch9'
                                        */
  real_T ConstantSwitch10_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/ConstantSwitch10'
                                        */
  real_T ConstantSwitch11_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/ConstantSwitch11'
                                        */
  real_T Constant11_Value;             /* Expression: 34
                                        * Referenced by: '<S1>/Constant11'
                                        */
  real_T BegrenzungArbeitstemperatur3_Up;/* Expression: 100
                                          * Referenced by: '<S1>/Begrenzung Arbeitstemperatur3'
                                          */
  real_T BegrenzungArbeitstemperatur3_Lo;/* Expression: 0
                                          * Referenced by: '<S1>/Begrenzung Arbeitstemperatur3'
                                          */
  real_T Constant13_Value;             /* Expression: 125
                                        * Referenced by: '<S1>/Constant13'
                                        */
  real_T Constant12_Value;             /* Expression: 8
                                        * Referenced by: '<S1>/Constant12'
                                        */
  real_T InvalidCTW1_Value;            /* Expression: 1
                                        * Referenced by: '<S1>/Invalid CTW1'
                                        */
  real_T ConstantSwitch13_Value;       /* Expression: 10
                                        * Referenced by: '<S1>/ConstantSwitch13'
                                        */
  real_T ConstantSwitch14_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/ConstantSwitch14'
                                        */
  real_T TXon_Value;                   /* Expression: 1
                                        * Referenced by: '<S1>/TX on'
                                        */
  real_T RXon_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/RX on'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T SFunction1_BytesRefNumOf;     /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S5>/S-Function1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T ConstantSwitch2_Value;        /* Expression: 0
                                        * Referenced by: '<S1>/ConstantSwitch2'
                                        */
  real_T Memory20_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S1>/Memory20'
                                        */
  int32_T Status_Y0;                   /* Computed Parameter: Status_Y0
                                        * Referenced by: '<S12>/Status'
                                        */
  uint32_T SFunction1_BytesRefNumOf_e; /* Expression: sfpt(1).BytesRefNumOf
                                        * Referenced by: '<S15>/S-Function1'
                                        */
  uint32_T Constant19_Value;           /* Computed Parameter: Constant19_Value
                                        * Referenced by: '<S1>/Constant19'
                                        */
  boolean_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S1>/Memory'
                                   */
  boolean_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S1>/Memory1'
                                  */
  boolean_T Memory5_InitialCondition;
                                 /* Computed Parameter: Memory5_InitialCondition
                                  * Referenced by: '<S1>/Memory5'
                                  */
  boolean_T Memory16_InitialCondition;
                                /* Computed Parameter: Memory16_InitialCondition
                                 * Referenced by: '<S1>/Memory16'
                                 */
  boolean_T Memory11_InitialCondition;
                                /* Computed Parameter: Memory11_InitialCondition
                                 * Referenced by: '<S1>/Memory11'
                                 */
  boolean_T Memory12_InitialCondition;
                                /* Computed Parameter: Memory12_InitialCondition
                                 * Referenced by: '<S1>/Memory12'
                                 */
  uint8_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S1>/Memory3'
                                  */
  uint8_T Memory2_InitialCondition;
                                 /* Computed Parameter: Memory2_InitialCondition
                                  * Referenced by: '<S1>/Memory2'
                                  */
  uint8_T Memory4_InitialCondition;
                                 /* Computed Parameter: Memory4_InitialCondition
                                  * Referenced by: '<S1>/Memory4'
                                  */
  uint8_T Constant15_Value;            /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S1>/Constant15'
                                        */
  uint8_T Memory17_InitialCondition;
                                /* Computed Parameter: Memory17_InitialCondition
                                 * Referenced by: '<S1>/Memory17'
                                 */
  uint8_T Memory8_InitialCondition;
                                 /* Computed Parameter: Memory8_InitialCondition
                                  * Referenced by: '<S1>/Memory8'
                                  */
  uint8_T Memory13_InitialCondition;
                                /* Computed Parameter: Memory13_InitialCondition
                                 * Referenced by: '<S1>/Memory13'
                                 */
  uint8_T Memory14_InitialCondition;
                                /* Computed Parameter: Memory14_InitialCondition
                                 * Referenced by: '<S1>/Memory14'
                                 */
  uint8_T Memory15_InitialCondition;
                                /* Computed Parameter: Memory15_InitialCondition
                                 * Referenced by: '<S1>/Memory15'
                                 */
  uint8_T Memory10_InitialCondition;
                                /* Computed Parameter: Memory10_InitialCondition
                                 * Referenced by: '<S1>/Memory10'
                                 */
  uint8_T Memory21_InitialCondition;
                                /* Computed Parameter: Memory21_InitialCondition
                                 * Referenced by: '<S1>/Memory21'
                                 */
  uint8_T Memory9_InitialCondition;
                                 /* Computed Parameter: Memory9_InitialCondition
                                  * Referenced by: '<S1>/Memory9'
                                  */
  uint8_T Memory19_InitialCondition;
                                /* Computed Parameter: Memory19_InitialCondition
                                 * Referenced by: '<S1>/Memory19'
                                 */
  uint8_T Memory6_InitialCondition;
                                 /* Computed Parameter: Memory6_InitialCondition
                                  * Referenced by: '<S1>/Memory6'
                                  */
  uint8_T Memory18_InitialCondition;
                                /* Computed Parameter: Memory18_InitialCondition
                                 * Referenced by: '<S1>/Memory18'
                                 */
  uint8_T Memory7_InitialCondition;
                                 /* Computed Parameter: Memory7_InitialCondition
                                  * Referenced by: '<S1>/Memory7'
                                  */
  uint8_T BegrenzungArbeitstemperatur1_Up;
                          /* Computed Parameter: BegrenzungArbeitstemperatur1_Up
                           * Referenced by: '<S1>/Begrenzung Arbeitstemperatur1'
                           */
  uint8_T BegrenzungArbeitstemperatur1_Lo;
                          /* Computed Parameter: BegrenzungArbeitstemperatur1_Lo
                           * Referenced by: '<S1>/Begrenzung Arbeitstemperatur1'
                           */
  uint8_T Constant6_Value;             /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S1>/Constant6'
                                        */
  uint8_T Constant7_Value;             /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S1>/Constant7'
                                        */
  uint8_T Constant8_Value;             /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S1>/Constant8'
                                        */
  uint8_T Length_Value;                /* Computed Parameter: Length_Value
                                        * Referenced by: '<S1>/Length'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MySimplifiedTestingMo_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_MySimplifiedTestingModel_2_T MySimplifiedTestingModel_2_P;

/* Block signals (default storage) */
extern B_MySimplifiedTestingModel_2_T MySimplifiedTestingModel_2_B;

/* Block states (default storage) */
extern DW_MySimplifiedTestingModel_2_T MySimplifiedTestingModel_2_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_MySimplifiedTestingMo_T MySimplifiedTestingMode_PrevZCX;

/* Model entry point functions */
extern void MySimplifiedTestingModel_2_initialize(void);
extern void MySimplifiedTestingModel_2_output(void);
extern void MySimplifiedTestingModel_2_update(void);
extern void MySimplifiedTestingModel_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MySimplifiedTestingM_T *const MySimplifiedTestingModel_2_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MySimplifiedTestingModel_2'
 * '<S1>'   : 'MySimplifiedTestingModel_2/RS485'
 * '<S2>'   : 'MySimplifiedTestingModel_2/RTI Data'
 * '<S3>'   : 'MySimplifiedTestingModel_2/RS485/BUS MASTER FSM'
 * '<S4>'   : 'MySimplifiedTestingModel_2/RS485/Create 8-Bytes Command'
 * '<S5>'   : 'MySimplifiedTestingModel_2/RS485/DS1202SER_RX_C2'
 * '<S6>'   : 'MySimplifiedTestingModel_2/RS485/DS1202SER_SETUP_C1'
 * '<S7>'   : 'MySimplifiedTestingModel_2/RS485/DS1202SER_SETUP_C2'
 * '<S8>'   : 'MySimplifiedTestingModel_2/RS485/DS1202SER_STAT_C1'
 * '<S9>'   : 'MySimplifiedTestingModel_2/RS485/MATLAB Function'
 * '<S10>'  : 'MySimplifiedTestingModel_2/RS485/MATLAB Function1'
 * '<S11>'  : 'MySimplifiedTestingModel_2/RS485/MATLAB Function4'
 * '<S12>'  : 'MySimplifiedTestingModel_2/RS485/Subsystem'
 * '<S13>'  : 'MySimplifiedTestingModel_2/RS485/THERMO FSM'
 * '<S14>'  : 'MySimplifiedTestingModel_2/RS485/ZKDM FSM'
 * '<S15>'  : 'MySimplifiedTestingModel_2/RS485/Subsystem/DS1202SER_TX_C1'
 * '<S16>'  : 'MySimplifiedTestingModel_2/RTI Data/RTI Data Store'
 * '<S17>'  : 'MySimplifiedTestingModel_2/RTI Data/RTI Data Store/RTI Data Store'
 * '<S18>'  : 'MySimplifiedTestingModel_2/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                            /* RTW_HEADER_MySimplifiedTestingModel_2_h_ */
