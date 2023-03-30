/*
 * File: StandTurn_Balance.h
 *
 * Code generated for Simulink model 'StandTurn_Balance'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Mar 21 20:39:47 2023
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_StandTurn_Balance_h_
#define RTW_HEADER_StandTurn_Balance_h_
#include <math.h>
#ifndef StandTurn_Balance_COMMON_INCLUDES_
#define StandTurn_Balance_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* StandTurn_Balance_COMMON_INCLUDES_ */

#include "StandTurn_Balance_types.h"
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
  real_T Add;                          /* '<S17>/Add' */
  real_T Add_b;                        /* '<S41>/Add' */
  real_T Add_o;                        /* '<S11>/Add' */
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
  real32_T Divide;                     /* '<S15>/Divide' */
  real32_T Divide1;                    /* '<S15>/Divide1' */
  int32_T encoder1;                    /* '<Root>/Input' */
  int32_T encoder2;                    /* '<Root>/Input' */
  int16_T angle[3];                    /* '<Root>/Input' */
  int16_T anglev[3];                   /* '<Root>/Input' */
  int16_T current1[5];                 /* '<Root>/Input' */
  int16_T current2[5];                 /* '<Root>/Input' */
  int16_T Saturation;                  /* '<Root>/Saturation' */
  int16_T Saturation1;                 /* '<Root>/Saturation1' */
} B_StandTurn_Balance_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S34>/Delay' */
  real_T Delay_DSTATE_n;               /* '<S47>/Delay' */
  real_T flag;                         /* '<Root>/Data Store Memory10' */
  real_T Kp_speed;                     /* '<Root>/Data Store Memory13' */
  real_T Ki_speed;                     /* '<Root>/Data Store Memory14' */
  real_T Kd_speed;                     /* '<Root>/Data Store Memory15' */
  real_T machine_mid;                  /* '<Root>/Data Store Memory7' */
  real32_T DelayOneStep_DSTATE;        /* '<S12>/Delay One Step' */
  real32_T DelayOneStep_DSTATE_d;      /* '<S13>/Delay One Step' */
  real32_T UD_DSTATE;                  /* '<S36>/UD' */
  real32_T Delay_DSTATE_g;             /* '<S38>/Delay' */
  real32_T UD_DSTATE_k;                /* '<S40>/UD' */
  real32_T Delay_DSTATE_i;             /* '<S43>/Delay' */
  real32_T UD_DSTATE_o;                /* '<S45>/UD' */
  int32_T Delay_DSTATE_o[19];          /* '<S15>/Delay' */
  int32_T Delay1_DSTATE[19];           /* '<S15>/Delay1' */
  real32_T tar_speed;                  /* '<Root>/Data Store Memory12' */
  real32_T Kp_turn;                    /* '<Root>/Data Store Memory19' */
  real32_T Ki_turn;                    /* '<Root>/Data Store Memory22' */
  real32_T Kd_turn;                    /* '<Root>/Data Store Memory23' */
  int32_T yaw_begin;                   /* '<Root>/Data Store Memory11' */
  int32_T tar_yaw;                     /* '<Root>/Data Store Memory20' */
  int16_T PrevY;                       /* '<Root>/Rate Limiter1' */
  int16_T PrevY_n;                     /* '<Root>/Rate Limiter2' */
  uint8_T Output_DSTATE;               /* '<S8>/Output' */
  uint8_T Output_DSTATE_i;             /* '<S9>/Output' */
  uint8_T Output_DSTATE_a;             /* '<S10>/Output' */
  uint8_T Output_DSTATE_i5;            /* '<S7>/Output' */
} DW_StandTurn_Balance_T;

/* Real-time Model Data Structure */
struct tag_RTM_StandTurn_Balance_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_StandTurn_Balance_T StandTurn_Balance_B;

/* Block states (default storage) */
extern DW_StandTurn_Balance_T StandTurn_Balance_DW;

/* External data declarations for dependent source files */
extern const uint8_T StandTurn_Balance_U8GND;/* uint8_T ground */

/* Model entry point functions */
extern void StandTurn_Balance_initialize(void);
extern void StandTurn_Balance_step(void);
extern void StandTurn_Balance_terminate(void);

/* Real-time Model object */
extern RT_MODEL_StandTurn_Balance_T *const StandTurn_Balance_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S21>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S29>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S30>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S33>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S34>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S35>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S37>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S38>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S39>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S42>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S43>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S44>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S42>/Constant2' : Unused code path elimination
 * Block '<S43>/Constant1' : Unused code path elimination
 * Block '<S44>/Constant' : Unused code path elimination
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
 * '<Root>' : 'StandTurn_Balance'
 * '<S1>'   : 'StandTurn_Balance/Compare To Constant'
 * '<S2>'   : 'StandTurn_Balance/Compare To Constant1'
 * '<S3>'   : 'StandTurn_Balance/Compare To Constant2'
 * '<S4>'   : 'StandTurn_Balance/Compare To Constant3'
 * '<S5>'   : 'StandTurn_Balance/Compare To Constant4'
 * '<S6>'   : 'StandTurn_Balance/Compare To Constant5'
 * '<S7>'   : 'StandTurn_Balance/Counter Limited'
 * '<S8>'   : 'StandTurn_Balance/Counter Limited1'
 * '<S9>'   : 'StandTurn_Balance/Counter Limited2'
 * '<S10>'  : 'StandTurn_Balance/Counter Limited3'
 * '<S11>'  : 'StandTurn_Balance/anglePID'
 * '<S12>'  : 'StandTurn_Balance/currentFilter_motor1'
 * '<S13>'  : 'StandTurn_Balance/currentFilter_motor2'
 * '<S14>'  : 'StandTurn_Balance/currentPID'
 * '<S15>'  : 'StandTurn_Balance/encoder to rpm'
 * '<S16>'  : 'StandTurn_Balance/speedPID_motor'
 * '<S17>'  : 'StandTurn_Balance/turnPID'
 * '<S18>'  : 'StandTurn_Balance/yaw to zero'
 * '<S19>'  : 'StandTurn_Balance/zero limit1'
 * '<S20>'  : 'StandTurn_Balance/zero limit2'
 * '<S21>'  : 'StandTurn_Balance/Counter Limited/Increment Real World'
 * '<S22>'  : 'StandTurn_Balance/Counter Limited/Wrap To Zero'
 * '<S23>'  : 'StandTurn_Balance/Counter Limited1/Increment Real World'
 * '<S24>'  : 'StandTurn_Balance/Counter Limited1/Wrap To Zero'
 * '<S25>'  : 'StandTurn_Balance/Counter Limited2/Increment Real World'
 * '<S26>'  : 'StandTurn_Balance/Counter Limited2/Wrap To Zero'
 * '<S27>'  : 'StandTurn_Balance/Counter Limited3/Increment Real World'
 * '<S28>'  : 'StandTurn_Balance/Counter Limited3/Wrap To Zero'
 * '<S29>'  : 'StandTurn_Balance/anglePID/D'
 * '<S30>'  : 'StandTurn_Balance/anglePID/P'
 * '<S31>'  : 'StandTurn_Balance/currentPID/currentPID_motor1'
 * '<S32>'  : 'StandTurn_Balance/currentPID/currentPID_motor2'
 * '<S33>'  : 'StandTurn_Balance/currentPID/currentPID_motor1/D'
 * '<S34>'  : 'StandTurn_Balance/currentPID/currentPID_motor1/I'
 * '<S35>'  : 'StandTurn_Balance/currentPID/currentPID_motor1/P'
 * '<S36>'  : 'StandTurn_Balance/currentPID/currentPID_motor1/D/Difference'
 * '<S37>'  : 'StandTurn_Balance/currentPID/currentPID_motor2/D'
 * '<S38>'  : 'StandTurn_Balance/currentPID/currentPID_motor2/I'
 * '<S39>'  : 'StandTurn_Balance/currentPID/currentPID_motor2/P'
 * '<S40>'  : 'StandTurn_Balance/currentPID/currentPID_motor2/D/Difference'
 * '<S41>'  : 'StandTurn_Balance/speedPID_motor/Subsystem2'
 * '<S42>'  : 'StandTurn_Balance/speedPID_motor/Subsystem2/D'
 * '<S43>'  : 'StandTurn_Balance/speedPID_motor/Subsystem2/I'
 * '<S44>'  : 'StandTurn_Balance/speedPID_motor/Subsystem2/P'
 * '<S45>'  : 'StandTurn_Balance/speedPID_motor/Subsystem2/D/Difference'
 * '<S46>'  : 'StandTurn_Balance/turnPID/D'
 * '<S47>'  : 'StandTurn_Balance/turnPID/I'
 * '<S48>'  : 'StandTurn_Balance/turnPID/P'
 */
#endif                                 /* RTW_HEADER_StandTurn_Balance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
