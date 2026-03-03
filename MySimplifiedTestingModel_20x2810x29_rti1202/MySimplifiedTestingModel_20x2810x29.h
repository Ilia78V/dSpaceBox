/*
 * MySimplifiedTestingModel_20x2810x29.h
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

#ifndef RTW_HEADER_MySimplifiedTestingModel_20x2810x29_h_
#define RTW_HEADER_MySimplifiedTestingModel_20x2810x29_h_
#ifndef MySimplifiedTestingModel_20x2810x29_COMMON_INCLUDES_
#define MySimplifiedTestingModel_20x2810x29_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                /* MySimplifiedTestingModel_20x2810x29_COMMON_INCLUDES_ */

#include "MySimplifiedTestingModel_20x2810x29_types.h"
#include <string.h>
#include "rt_nonfinite.h"

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

#define MySimplifiedTestingModel_20x2810x29_M (MySimplifiedTestingModel_20x_M)

/* Block signals (default storage) */
typedef struct {
  real_T BegrenzungArbeitstemperatur3;/* '<S1>/Begrenzung Arbeitstemperatur3' */
  real_T Clock;                        /* '<S1>/Clock' */
  real_T Constant18;                   /* '<S1>/Constant18' */
  real_T u;                            /* '<S5>/u' */
  real_T TmpSignalConversionAtuOutport1;/* '<S5>/u' */
  real_T u1;                           /* '<S5>/u1' */
  real_T TmpSignalConversionAtu1Outport1;/* '<S5>/u1' */
  real_T u2;                           /* '<S5>/u2' */
  real_T TmpSignalConversionAtu2Outport1;/* '<S5>/u2' */
  real_T Saturation;                   /* '<S5>/Saturation' */
  uint8_T Switch[64];                  /* '<S1>/Switch' */
  uint8_T Switch1;                     /* '<S1>/Switch1' */
  uint8_T Memory8;                     /* '<S1>/Memory8' */
  uint8_T Memory10;                    /* '<S1>/Memory10' */
  uint8_T Memory9;                     /* '<S1>/Memory9' */
  uint8_T Memory6[64];                 /* '<S1>/Memory6' */
  uint8_T Memory7;                     /* '<S1>/Memory7' */
  uint8_T Saturation_f;                /* '<S1>/Saturation' */
  uint8_T Memory2;                     /* '<S1>/Memory2' */
  uint8_T Memory3[64];                 /* '<S1>/Memory3' */
  uint8_T Memory4;                     /* '<S1>/Memory4' */
  uint8_T BegrenzungArbeitstemperatur1;
                                      /* '<S1>/Begrenzung Arbeitstemperatur1' */
  uint8_T Constant6;                   /* '<S1>/Constant6' */
  uint8_T Constant7;                   /* '<S1>/Constant7' */
  uint8_T Constant8;                   /* '<S1>/Constant8' */
  uint8_T Constant9;                   /* '<S1>/Constant9' */
  uint8_T TmpSignalConversionAtyInport1[63];/* '<S5>/Create 8-Bytes Command' */
  uint8_T command[63];                 /* '<S5>/Create 8-Bytes Command' */
  uint8_T req_bytes[64];               /* '<S1>/ZKDM FSM' */
  uint8_T req_len;                     /* '<S1>/ZKDM FSM' */
  uint8_T expect_addr_ZKDM;            /* '<S1>/ZKDM FSM' */
  uint8_T expect_crc_kind_ZKDM;        /* '<S1>/ZKDM FSM' */
  uint8_T expect_len_ZKDM;             /* '<S1>/ZKDM FSM' */
  uint8_T u_d[64];                     /* '<S1>/MATLAB Function4' */
  uint8_T command_c[64];               /* '<S1>/Create 8-Bytes Command' */
  uint8_T TmpSignalConversionAtSFunctionI[64];/* '<S1>/BUS MASTER FSM' */
  uint8_T TX_Data[64];                 /* '<S1>/BUS MASTER FSM' */
  uint8_T TX_Len;                      /* '<S1>/BUS MASTER FSM' */
  uint8_T resp_err_ZKDM;               /* '<S1>/BUS MASTER FSM' */
  uint8_T resp_data[64];               /* '<S1>/BUS MASTER FSM' */
  uint8_T resp_err_THERMO;             /* '<S1>/BUS MASTER FSM' */
  uint8_T resp_len;                    /* '<S1>/BUS MASTER FSM' */
  boolean_T CastToBoolean3;            /* '<S1>/Cast To Boolean3' */
  boolean_T Memory5;                   /* '<S1>/Memory5' */
  boolean_T CastToBoolean6;            /* '<S1>/Cast To Boolean6' */
  boolean_T CastToBoolean7;            /* '<S1>/Cast To Boolean7' */
  boolean_T CastToBoolean;             /* '<S1>/Cast To Boolean' */
  boolean_T CastToBoolean1;            /* '<S1>/Cast To Boolean1' */
  boolean_T CastToBoolean5;            /* '<S1>/Cast To Boolean5' */
  boolean_T Memory;                    /* '<S1>/Memory' */
  boolean_T Memory1;                   /* '<S1>/Memory1' */
  boolean_T CastToBoolean2;            /* '<S1>/Cast To Boolean2' */
  boolean_T CastToBoolean4;            /* '<S1>/Cast To Boolean4' */
  boolean_T CastToBoolean_o;           /* '<S5>/Cast To Boolean' */
  boolean_T CastToBoolean1_j;          /* '<S5>/Cast To Boolean1' */
  boolean_T req_valid;                 /* '<S1>/ZKDM FSM' */
  boolean_T TX_Trigger;                /* '<S1>/BUS MASTER FSM' */
  boolean_T grant_ZKDM;                /* '<S1>/BUS MASTER FSM' */
  boolean_T resp_ok_ZKDM;              /* '<S1>/BUS MASTER FSM' */
  boolean_T grant_THERMO;              /* '<S1>/BUS MASTER FSM' */
  boolean_T resp_ok_THERMO;            /* '<S1>/BUS MASTER FSM' */
} B_MySimplifiedTestingModel_20_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T comm_err_count;             /* '<S1>/ZKDM FSM' */
  uint16_T interGap_ms;                /* '<S1>/BUS MASTER FSM' */
  uint16_T timeout_ms_THERMO;          /* '<S1>/BUS MASTER FSM' */
  uint16_T timeout_ms_ZKDM;            /* '<S1>/BUS MASTER FSM' */
  uint16_T timeout_ms;                 /* '<S1>/BUS MASTER FSM' */
  uint16_T temporalCounter_i2;         /* '<S1>/BUS MASTER FSM' */
  uint8_T Memory8_PreviousInput;       /* '<S1>/Memory8' */
  uint8_T Memory10_PreviousInput;      /* '<S1>/Memory10' */
  uint8_T Memory9_PreviousInput;       /* '<S1>/Memory9' */
  uint8_T Memory6_PreviousInput[64];   /* '<S1>/Memory6' */
  uint8_T Memory7_PreviousInput;       /* '<S1>/Memory7' */
  uint8_T Memory2_PreviousInput;       /* '<S1>/Memory2' */
  uint8_T Memory3_PreviousInput[64];   /* '<S1>/Memory3' */
  uint8_T Memory4_PreviousInput;       /* '<S1>/Memory4' */
  uint8_T fc_addr;                     /* '<S1>/ZKDM FSM' */
  uint8_T min_period_ms;               /* '<S1>/ZKDM FSM' */
  uint8_T tx_len;                      /* '<S1>/ZKDM FSM' */
  uint8_T is_active_c11_MySimplifiedTesti;/* '<S1>/ZKDM FSM' */
  uint8_T is_c11_MySimplifiedTestingModel;/* '<S1>/ZKDM FSM' */
  uint8_T temporalCounter_i1;          /* '<S1>/ZKDM FSM' */
  uint8_T temporalCounter_i2_i;        /* '<S1>/ZKDM FSM' */
  uint8_T maxRetry;                    /* '<S1>/BUS MASTER FSM' */
  uint8_T pollThermoEvery;             /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_expect_addr;          /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_expect_len;           /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_len;                  /* '<S1>/BUS MASTER FSM' */
  uint8_T chosen_req[64];              /* '<S1>/BUS MASTER FSM' */
  uint8_T currentDev;                  /* '<S1>/BUS MASTER FSM' */
  uint8_T pollCounter;                 /* '<S1>/BUS MASTER FSM' */
  uint8_T retry;                       /* '<S1>/BUS MASTER FSM' */
  uint8_T rxBuf[64];                   /* '<S1>/BUS MASTER FSM' */
  uint8_T rxCount;                     /* '<S1>/BUS MASTER FSM' */
  uint8_T err_THERMO;                  /* '<S1>/BUS MASTER FSM' */
  uint8_T err_ZKDM;                    /* '<S1>/BUS MASTER FSM' */
  uint8_T is_active_c6_MySimplifiedTestin;/* '<S1>/BUS MASTER FSM' */
  uint8_T is_c6_MySimplifiedTestingModel_;/* '<S1>/BUS MASTER FSM' */
  uint8_T temporalCounter_i1_p;        /* '<S1>/BUS MASTER FSM' */
  boolean_T Memory5_PreviousInput;     /* '<S1>/Memory5' */
  boolean_T Memory_PreviousInput;      /* '<S1>/Memory' */
  boolean_T Memory1_PreviousInput;     /* '<S1>/Memory1' */
  boolean_T READY_to_WAIT_GRANT;       /* '<S1>/ZKDM FSM' */
} DW_MySimplifiedTestingModel_2_T;

/* Parameters (default storage) */
struct P_MySimplifiedTestingModel_20_T_ {
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant10'
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
  real_T Constant14_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant14'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch1'
                                        */
  real_T Constant17_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant17'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 34
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant16'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T ConstantSwitch2_Value;        /* Expression: 0
                                        * Referenced by: '<S1>/ConstantSwitch2'
                                        */
  real_T Constant18_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant18'
                                        */
  boolean_T Memory5_InitialCondition;
                                 /* Computed Parameter: Memory5_InitialCondition
                                  * Referenced by: '<S1>/Memory5'
                                  */
  boolean_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S1>/Memory'
                                   */
  boolean_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S1>/Memory1'
                                  */
  uint8_T Constant12_Value;            /* Computed Parameter: Constant12_Value
                                        * Referenced by: '<S1>/Constant12'
                                        */
  uint8_T Constant15_Value;            /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S1>/Constant15'
                                        */
  uint8_T Memory8_InitialCondition;
                                 /* Computed Parameter: Memory8_InitialCondition
                                  * Referenced by: '<S1>/Memory8'
                                  */
  uint8_T Memory10_InitialCondition;
                                /* Computed Parameter: Memory10_InitialCondition
                                 * Referenced by: '<S1>/Memory10'
                                 */
  uint8_T Memory9_InitialCondition;
                                 /* Computed Parameter: Memory9_InitialCondition
                                  * Referenced by: '<S1>/Memory9'
                                  */
  uint8_T Memory6_InitialCondition;
                                 /* Computed Parameter: Memory6_InitialCondition
                                  * Referenced by: '<S1>/Memory6'
                                  */
  uint8_T Memory7_InitialCondition;
                                 /* Computed Parameter: Memory7_InitialCondition
                                  * Referenced by: '<S1>/Memory7'
                                  */
  uint8_T Saturation_UpperSat_g;    /* Computed Parameter: Saturation_UpperSat_g
                                     * Referenced by: '<S1>/Saturation'
                                     */
  uint8_T Saturation_LowerSat_l;    /* Computed Parameter: Saturation_LowerSat_l
                                     * Referenced by: '<S1>/Saturation'
                                     */
  uint8_T Memory2_InitialCondition;
                                 /* Computed Parameter: Memory2_InitialCondition
                                  * Referenced by: '<S1>/Memory2'
                                  */
  uint8_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S1>/Memory3'
                                  */
  uint8_T Memory4_InitialCondition;
                                 /* Computed Parameter: Memory4_InitialCondition
                                  * Referenced by: '<S1>/Memory4'
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
  uint8_T Constant9_Value;             /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S1>/Constant9'
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
extern P_MySimplifiedTestingModel_20_T MySimplifiedTestingModel_20x2_P;

/* Block signals (default storage) */
extern B_MySimplifiedTestingModel_20_T MySimplifiedTestingModel_20x2_B;

/* Block states (default storage) */
extern DW_MySimplifiedTestingModel_2_T MySimplifiedTestingModel_20x_DW;

/* Model entry point functions */
extern void MySimplifiedTestingModel_20x2810x29_initialize(void);
extern void MySimplifiedTestingModel_20x2810x29_output(void);
extern void MySimplifiedTestingModel_20x2810x29_update(void);
extern void MySimplifiedTestingModel_20x2810x29_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MySimplifiedTestingM_T *const MySimplifiedTestingModel_20x_M;

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
 * '<Root>' : 'MySimplifiedTestingModel_20x2810x29'
 * '<S1>'   : 'MySimplifiedTestingModel_20x2810x29/RS485'
 * '<S2>'   : 'MySimplifiedTestingModel_20x2810x29/RTI Data'
 * '<S3>'   : 'MySimplifiedTestingModel_20x2810x29/RS485/BUS MASTER FSM'
 * '<S4>'   : 'MySimplifiedTestingModel_20x2810x29/RS485/Create 8-Bytes Command'
 * '<S5>'   : 'MySimplifiedTestingModel_20x2810x29/RS485/Create FC-Protocol Command 8-Bytes'
 * '<S6>'   : 'MySimplifiedTestingModel_20x2810x29/RS485/MATLAB Function4'
 * '<S7>'   : 'MySimplifiedTestingModel_20x2810x29/RS485/ZKDM FSM'
 * '<S8>'   : 'MySimplifiedTestingModel_20x2810x29/RS485/Create FC-Protocol Command 8-Bytes/Create 8-Bytes Command'
 * '<S9>'   : 'MySimplifiedTestingModel_20x2810x29/RTI Data/RTI Data Store'
 * '<S10>'  : 'MySimplifiedTestingModel_20x2810x29/RTI Data/RTI Data Store/RTI Data Store'
 * '<S11>'  : 'MySimplifiedTestingModel_20x2810x29/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                   /* RTW_HEADER_MySimplifiedTestingModel_20x2810x29_h_ */
