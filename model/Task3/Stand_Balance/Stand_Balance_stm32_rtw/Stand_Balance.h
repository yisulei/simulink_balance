/*
 * File: Stand_Balance.h
 *
 * Code generated for Simulink model 'Stand_Balance'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Mar  1 10:54:59 2023
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Stand_Balance_h_
#define RTW_HEADER_Stand_Balance_h_
#include <math.h>
#ifndef Stand_Balance_COMMON_INCLUDES_
#define Stand_Balance_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Stand_Balance_COMMON_INCLUDES_ */

#include "Stand_Balance_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<S3>/Add' */
  real32_T DataStoreRead4;             /* '<Root>/Data Store Read4' */
  real32_T DataStoreRead5;             /* '<Root>/Data Store Read5' */
  real32_T DataTypeConversion3;        /* '<Root>/Data Type Conversion3' */
  real32_T ManualSwitch;               /* '<Root>/Manual Switch' */
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
  int32_T encoder1;                    /* '<Root>/Input' */
  int32_T encoder2;                    /* '<Root>/Input' */
  int16_T angle[3];                    /* '<Root>/Input' */
  int16_T anglev[3];                   /* '<Root>/Input' */
  int16_T current1[5];                 /* '<Root>/Input' */
  int16_T current2[5];                 /* '<Root>/Input' */
  int16_T Saturation;                  /* '<Root>/Saturation' */
  int16_T Saturation1;                 /* '<Root>/Saturation1' */
} B_Stand_Balance_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S16>/Delay' */
  real_T Delay_DSTATE_i;               /* '<S20>/Delay' */
  real32_T DelayOneStep_DSTATE;        /* '<S4>/Delay One Step' */
  real32_T DelayOneStep_DSTATE_p;      /* '<S5>/Delay One Step' */
  real32_T UD_DSTATE;                  /* '<S18>/UD' */
  real32_T UD_DSTATE_c;                /* '<S22>/UD' */
  real32_T tar_current;                /* '<Root>/Data Store Memory6' */
  real32_T machine_mid;                /* '<Root>/Data Store Memory7' */
  int16_T PrevY;                       /* '<Root>/Rate Limiter1' */
  uint8_T Output_DSTATE;               /* '<S2>/Output' */
} DW_Stand_Balance_T;

/* Real-time Model Data Structure */
struct tag_RTM_Stand_Balance_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Stand_Balance_T Stand_Balance_B;

/* Block states (default storage) */
extern DW_Stand_Balance_T Stand_Balance_DW;

/* External data declarations for dependent source files */
extern const uint8_T Stand_Balance_U8GND;/* uint8_T ground */

/* Model entry point functions */
extern void Stand_Balance_initialize(void);
extern void Stand_Balance_step(void);
extern void Stand_Balance_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Stand_Balance_T *const Stand_Balance_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S11>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S12>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S15>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S16>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S17>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S19>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S20>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S21>/Manual Switch' : Eliminated due to constant selection input
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
 * '<Root>' : 'Stand_Balance'
 * '<S1>'   : 'Stand_Balance/Compare To Constant'
 * '<S2>'   : 'Stand_Balance/Counter Limited'
 * '<S3>'   : 'Stand_Balance/anglePID'
 * '<S4>'   : 'Stand_Balance/currentFilter_motor1'
 * '<S5>'   : 'Stand_Balance/currentFilter_motor2'
 * '<S6>'   : 'Stand_Balance/currentPID'
 * '<S7>'   : 'Stand_Balance/zero limit1'
 * '<S8>'   : 'Stand_Balance/zero limit2'
 * '<S9>'   : 'Stand_Balance/Counter Limited/Increment Real World'
 * '<S10>'  : 'Stand_Balance/Counter Limited/Wrap To Zero'
 * '<S11>'  : 'Stand_Balance/anglePID/D'
 * '<S12>'  : 'Stand_Balance/anglePID/P'
 * '<S13>'  : 'Stand_Balance/currentPID/currentPID_motor1'
 * '<S14>'  : 'Stand_Balance/currentPID/currentPID_motor2'
 * '<S15>'  : 'Stand_Balance/currentPID/currentPID_motor1/D'
 * '<S16>'  : 'Stand_Balance/currentPID/currentPID_motor1/I'
 * '<S17>'  : 'Stand_Balance/currentPID/currentPID_motor1/P'
 * '<S18>'  : 'Stand_Balance/currentPID/currentPID_motor1/D/Difference'
 * '<S19>'  : 'Stand_Balance/currentPID/currentPID_motor2/D'
 * '<S20>'  : 'Stand_Balance/currentPID/currentPID_motor2/I'
 * '<S21>'  : 'Stand_Balance/currentPID/currentPID_motor2/P'
 * '<S22>'  : 'Stand_Balance/currentPID/currentPID_motor2/D/Difference'
 */
#endif                                 /* RTW_HEADER_Stand_Balance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
