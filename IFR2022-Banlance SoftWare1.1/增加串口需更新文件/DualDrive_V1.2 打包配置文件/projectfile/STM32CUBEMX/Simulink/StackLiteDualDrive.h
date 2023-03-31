/*
 * File: StackLiteDualDrive.h
 *
 * Code generated for Simulink model 'StackLiteDualDrive'.
 *
 * Model version                  : 1.60
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Nov  1 22:41:41 2022
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_StackLiteDualDrive_h_
#define RTW_HEADER_StackLiteDualDrive_h_
#include <math.h>
#ifndef StackLiteDualDrive_COMMON_INCLUDES_
#define StackLiteDualDrive_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* StackLiteDualDrive_COMMON_INCLUDES_ */

#include "StackLiteDualDrive_types.h"

/* Child system includes */
#include "variParaPID.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Add4;                       /* '<S6>/Add4' */
  real32_T Add4_e;                     /* '<S7>/Add4' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T DataLinkInput_o1;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o2;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o3;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o4;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o5;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o6;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o7;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o8;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o9;           /* '<Root>/DataLinkInput' */
  real32_T DataLinkInput_o10;          /* '<Root>/DataLinkInput' */
  real32_T Saturation1;                /* '<S8>/Saturation1' */
  real32_T OutportBufferForm2;         /* '<S8>/Saturation1' */
  int32_T encoder1;                    /* '<Root>/Input' */
  int32_T encoder2;                    /* '<Root>/Input' */
  int16_T angle[3];                    /* '<Root>/Input' */
  int16_T anglev[3];                   /* '<Root>/Input' */
  int16_T current1[5];                 /* '<Root>/Input' */
  int16_T current2[5];                 /* '<Root>/Input' */
  int16_T Switch1;                     /* '<S10>/Switch1' */
  int16_T Switch1_e;                   /* '<S9>/Switch1' */
  uint8_T ws2812[3];                   /* '<Root>/Data Type Conversion3' */
  uint8_T LogicalOperator;             /* '<S5>/Logical Operator' */
} B_StackLiteDualDrive_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DelayOneStep_DSTATE;        /* '<S6>/Delay One Step' */
  real32_T DelayOneStep_DSTATE_a;      /* '<S7>/Delay One Step' */
  real32_T Delay2_DSTATE;              /* '<S16>/Delay2' */
  real32_T DelayOneStep_DSTATE_i;      /* '<S17>/Delay One Step' */
  int32_T Delay_DSTATE[5];             /* '<S8>/Delay' */
  int32_T Delay1_DSTATE[5];            /* '<S8>/Delay1' */
  real32_T PrevY;                      /* '<Root>/Rate Limiter' */
  real32_T PrevY_d;                    /* '<Root>/Rate Limiter1' */
  real32_T M1_Current_Kp;              /* '<Root>/Data Store Memory' */
  real32_T M1_Current_Ki;              /* '<Root>/Data Store Memory1' */
  real32_T M1_Current_Kd;              /* '<Root>/Data Store Memory2' */
  real32_T M2_Current_Kp;              /* '<Root>/Data Store Memory3' */
  real32_T M2_Current_Ki;              /* '<Root>/Data Store Memory4' */
  real32_T M2_Current_Kd;              /* '<Root>/Data Store Memory5' */
  real32_T M1_Current_iLimit;          /* '<Root>/Data Store Memory7' */
  real32_T M2_Current_iLimit;          /* '<Root>/Data Store Memory8' */
  real32_T UpRight_Kp;                 /* '<S8>/Data Store Memory' */
  real32_T UpRight_Ki;                 /* '<S8>/Data Store Memory1' */
  real32_T UpRight_Kd;                 /* '<S8>/Data Store Memory2' */
  real32_T Speed_Kp;                   /* '<S8>/Data Store Memory3' */
  real32_T Speed_Ki;                   /* '<S8>/Data Store Memory4' */
  real32_T Speed_Kd;                   /* '<S8>/Data Store Memory5' */
  real32_T UpRight_Set;                /* '<S8>/Data Store Memory6' */
  real32_T UpRight_iLimit;             /* '<S8>/Data Store Memory7' */
  real32_T Speed_Set;                  /* '<S8>/Data Store Memory8' */
  real32_T Speed_iLimit;               /* '<S8>/Data Store Memory9' */
  uint32_T CircBufIdx;                 /* '<S8>/Delay' */
  uint32_T CircBufIdx_h;               /* '<S8>/Delay1' */
  uint16_T Output_DSTATE;              /* '<S3>/Output' */
  uint8_T Output_DSTATE_l;             /* '<S4>/Output' */
  uint8_T Delay1_DSTATE_j;             /* '<S5>/Delay1' */
  MdlrefDW_variParaPID_T M1_Current_PID_InstanceData;/* '<Root>/M1_Current_PID' */
  MdlrefDW_variParaPID_T M2_Current_PID_InstanceData;/* '<Root>/M2_Current_PID' */
  MdlrefDW_variParaPID_T Speed_PID_InstanceData;/* '<S8>/Speed_PID' */
} DW_StackLiteDualDrive_T;

/* Real-time Model Data Structure */
struct tag_RTM_StackLiteDualDrive_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_StackLiteDualDrive_T StackLiteDualDrive_B;

/* Block states (default storage) */
extern DW_StackLiteDualDrive_T StackLiteDualDrive_DW;

/* Model entry point functions */
extern void StackLiteDualDrive_initialize(void);
extern void StackLiteDualDrive_step(void);
extern void StackLiteDualDrive_terminate(void);

/* Real-time Model object */
extern RT_MODEL_StackLiteDualDrive_T *const StackLiteDualDrive_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

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
 * '<Root>' : 'StackLiteDualDrive'
 * '<S1>'   : 'StackLiteDualDrive/Compare To Constant'
 * '<S2>'   : 'StackLiteDualDrive/Compare To Constant1'
 * '<S3>'   : 'StackLiteDualDrive/Counter Limited'
 * '<S4>'   : 'StackLiteDualDrive/Counter Limited1'
 * '<S5>'   : 'StackLiteDualDrive/LED Blink'
 * '<S6>'   : 'StackLiteDualDrive/M1 current filter'
 * '<S7>'   : 'StackLiteDualDrive/M2 current filter'
 * '<S8>'   : 'StackLiteDualDrive/main control'
 * '<S9>'   : 'StackLiteDualDrive/zero limit1'
 * '<S10>'  : 'StackLiteDualDrive/zero limit2'
 * '<S11>'  : 'StackLiteDualDrive/Counter Limited/Increment Real World'
 * '<S12>'  : 'StackLiteDualDrive/Counter Limited/Wrap To Zero'
 * '<S13>'  : 'StackLiteDualDrive/Counter Limited1/Increment Real World'
 * '<S14>'  : 'StackLiteDualDrive/Counter Limited1/Wrap To Zero'
 * '<S15>'  : 'StackLiteDualDrive/main control/Judgement dumping'
 * '<S16>'  : 'StackLiteDualDrive/main control/Upright PID'
 * '<S17>'  : 'StackLiteDualDrive/main control/anglev filter'
 * '<S18>'  : 'StackLiteDualDrive/main control/Upright PID/limit'
 */
#endif                                 /* RTW_HEADER_StackLiteDualDrive_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
