/*
 * File: StandSpeed_Balance.h
 *
 * Code generated for Simulink model 'StandSpeed_Balance'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Dec 27 17:56:22 2022
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_StandSpeed_Balance_h_
#define RTW_HEADER_StandSpeed_Balance_h_
#include <math.h>
#ifndef StandSpeed_Balance_COMMON_INCLUDES_
#define StandSpeed_Balance_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* StandSpeed_Balance_COMMON_INCLUDES_ */

#include "StandSpeed_Balance_types.h"
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
  real_T Add;                          /* '<S12>/Add' */
  real_T Add_h;                        /* '<S7>/Add' */
  real32_T DataStoreRead4;             /* '<Root>/Data Store Read4' */
  real32_T DataTypeConversion;         /* '<Root>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<Root>/Data Type Conversion1' */
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
  real32_T Divide;                     /* '<S11>/Divide' */
  real32_T Divide1;                    /* '<S11>/Divide1' */
  int32_T encoder1;                    /* '<Root>/Input' */
  int32_T encoder2;                    /* '<Root>/Input' */
  int16_T angle[3];                    /* '<Root>/Input' */
  int16_T anglev[3];                   /* '<Root>/Input' */
  int16_T current1[5];                 /* '<Root>/Input' */
  int16_T current2[5];                 /* '<Root>/Input' */
  int16_T Saturation;                  /* '<Root>/Saturation' */
  int16_T Saturation1;                 /* '<Root>/Saturation1' */
} B_StandSpeed_Balance_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S30>/Delay' */
  real_T Delay_DSTATE_b;               /* '<S36>/Delay' */
  real_T Delay_DSTATE_c;               /* '<S40>/Delay' */
  real_T tar_spcurrent1;               /* '<Root>/Data Store Memory10' */
  real_T tar_spcurrent2;               /* '<Root>/Data Store Memory11' */
  real32_T DelayOneStep_DSTATE;        /* '<S8>/Delay One Step' */
  real32_T DelayOneStep_DSTATE_b;      /* '<S9>/Delay One Step' */
  real32_T Delay_DSTATE_a;             /* '<S26>/Delay' */
  real32_T UD_DSTATE;                  /* '<S28>/UD' */
  real32_T UD_DSTATE_o;                /* '<S32>/UD' */
  real32_T UD_DSTATE_e;                /* '<S38>/UD' */
  real32_T UD_DSTATE_m;                /* '<S42>/UD' */
  int32_T Delay_DSTATE_e[19];          /* '<S11>/Delay' */
  int32_T Delay1_DSTATE[19];           /* '<S11>/Delay1' */
  real32_T tar_speed;                  /* '<Root>/Data Store Memory12' */
  real32_T Kp_speed;                   /* '<Root>/Data Store Memory13' */
  real32_T Ki_speed;                   /* '<Root>/Data Store Memory14' */
  real32_T Kd_speed;                   /* '<Root>/Data Store Memory15' */
  real32_T machine_mid;                /* '<Root>/Data Store Memory7' */
  int16_T PrevY;                       /* '<Root>/Rate Limiter1' */
  int16_T PrevY_h;                     /* '<Root>/Rate Limiter2' */
  uint8_T Output_DSTATE;               /* '<S5>/Output' */
  uint8_T Output_DSTATE_a;             /* '<S6>/Output' */
  uint8_T Output_DSTATE_l;             /* '<S4>/Output' */
} DW_StandSpeed_Balance_T;

/* Real-time Model Data Structure */
struct tag_RTM_StandSpeed_Balance_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_StandSpeed_Balance_T StandSpeed_Balance_B;

/* Block states (default storage) */
extern DW_StandSpeed_Balance_T StandSpeed_Balance_DW;

/* External data declarations for dependent source files */
extern const uint8_T StandSpeed_Balance_U8GND;/* uint8_T ground */

/* Model entry point functions */
extern void StandSpeed_Balance_initialize(void);
extern void StandSpeed_Balance_step(void);
extern void StandSpeed_Balance_terminate(void);

/* Real-time Model object */
extern RT_MODEL_StandSpeed_Balance_T *const StandSpeed_Balance_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S6>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S21>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S22>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S25>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S26>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S27>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S29>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S30>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S31>/Manual Switch' : Eliminated due to constant selection input
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
 * '<Root>' : 'StandSpeed_Balance'
 * '<S1>'   : 'StandSpeed_Balance/Compare To Constant'
 * '<S2>'   : 'StandSpeed_Balance/Compare To Constant1'
 * '<S3>'   : 'StandSpeed_Balance/Compare To Constant2'
 * '<S4>'   : 'StandSpeed_Balance/Counter Limited'
 * '<S5>'   : 'StandSpeed_Balance/Counter Limited1'
 * '<S6>'   : 'StandSpeed_Balance/Counter Limited2'
 * '<S7>'   : 'StandSpeed_Balance/anglePID'
 * '<S8>'   : 'StandSpeed_Balance/currentFilter_motor1'
 * '<S9>'   : 'StandSpeed_Balance/currentFilter_motor2'
 * '<S10>'  : 'StandSpeed_Balance/currentPID'
 * '<S11>'  : 'StandSpeed_Balance/encoder to rpm'
 * '<S12>'  : 'StandSpeed_Balance/speedPID_motor'
 * '<S13>'  : 'StandSpeed_Balance/zero limit1'
 * '<S14>'  : 'StandSpeed_Balance/zero limit2'
 * '<S15>'  : 'StandSpeed_Balance/Counter Limited/Increment Real World'
 * '<S16>'  : 'StandSpeed_Balance/Counter Limited/Wrap To Zero'
 * '<S17>'  : 'StandSpeed_Balance/Counter Limited1/Increment Real World'
 * '<S18>'  : 'StandSpeed_Balance/Counter Limited1/Wrap To Zero'
 * '<S19>'  : 'StandSpeed_Balance/Counter Limited2/Increment Real World'
 * '<S20>'  : 'StandSpeed_Balance/Counter Limited2/Wrap To Zero'
 * '<S21>'  : 'StandSpeed_Balance/anglePID/D'
 * '<S22>'  : 'StandSpeed_Balance/anglePID/P'
 * '<S23>'  : 'StandSpeed_Balance/currentPID/currentPID_motor1'
 * '<S24>'  : 'StandSpeed_Balance/currentPID/currentPID_motor2'
 * '<S25>'  : 'StandSpeed_Balance/currentPID/currentPID_motor1/D'
 * '<S26>'  : 'StandSpeed_Balance/currentPID/currentPID_motor1/I'
 * '<S27>'  : 'StandSpeed_Balance/currentPID/currentPID_motor1/P'
 * '<S28>'  : 'StandSpeed_Balance/currentPID/currentPID_motor1/D/Difference'
 * '<S29>'  : 'StandSpeed_Balance/currentPID/currentPID_motor2/D'
 * '<S30>'  : 'StandSpeed_Balance/currentPID/currentPID_motor2/I'
 * '<S31>'  : 'StandSpeed_Balance/currentPID/currentPID_motor2/P'
 * '<S32>'  : 'StandSpeed_Balance/currentPID/currentPID_motor2/D/Difference'
 * '<S33>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem'
 * '<S34>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem1'
 * '<S35>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem/D'
 * '<S36>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem/I'
 * '<S37>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem/P'
 * '<S38>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem/D/Difference'
 * '<S39>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem1/D'
 * '<S40>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem1/I'
 * '<S41>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem1/P'
 * '<S42>'  : 'StandSpeed_Balance/speedPID_motor/Subsystem1/D/Difference'
 */
#endif                                 /* RTW_HEADER_StandSpeed_Balance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
