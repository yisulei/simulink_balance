/*
 * File: angle_motor.h
 *
 * Code generated for Simulink model 'angle_motor'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Mar  7 19:23:13 2023
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_angle_motor_h_
#define RTW_HEADER_angle_motor_h_
#include <math.h>
#ifndef angle_motor_COMMON_INCLUDES_
#define angle_motor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* angle_motor_COMMON_INCLUDES_ */

#include "angle_motor_types.h"
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
  real_T Add;                          /* '<S11>/Add' */
  real_T Add_o;                        /* '<S10>/Add' */
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
  real32_T Add_m;                      /* '<Root>/Add' */
  real32_T Divide;                     /* '<S9>/Divide' */
  real32_T Divide1;                    /* '<S9>/Divide1' */
  int32_T encoder1;                    /* '<Root>/Input1' */
  int32_T encoder2;                    /* '<Root>/Input1' */
  int16_T angle[3];                    /* '<Root>/Input1' */
  int16_T anglev[3];                   /* '<Root>/Input1' */
  int16_T current1[5];                 /* '<Root>/Input1' */
  int16_T current1_j[5];               /* '<Root>/Input1' */
  int16_T Saturation1;                 /* '<Root>/Saturation1' */
  int16_T Saturation2;                 /* '<Root>/Saturation2' */
} B_angle_motor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S20>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S28>/Delay' */
  real_T Delay_DSTATE_c;               /* '<S24>/Delay' */
  real32_T DelayOneStep_DSTATE;        /* '<S7>/Delay One Step' */
  real32_T UD_DSTATE;                  /* '<S22>/UD' */
  real32_T UD_DSTATE_i;                /* '<S30>/UD' */
  real32_T UD_DSTATE_j;                /* '<S26>/UD' */
  int32_T Delay_DSTATE_f[19];          /* '<S9>/Delay' */
  int32_T Delay1_DSTATE[19];           /* '<S9>/Delay1' */
  int16_T PrevY;                       /* '<Root>/Rate Limiter1' */
  uint8_T Output_DSTATE;               /* '<S6>/Output' */
  uint8_T Output_DSTATE_d;             /* '<S4>/Output' */
  uint8_T Output_DSTATE_j;             /* '<S5>/Output' */
} DW_angle_motor_T;

/* Real-time Model Data Structure */
struct tag_RTM_angle_motor_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_angle_motor_T angle_motor_B;

/* Block states (default storage) */
extern DW_angle_motor_T angle_motor_DW;

/* External data declarations for dependent source files */
extern const uint8_T angle_motor_U8GND;/* uint8_T ground */

/* Model entry point functions */
extern void angle_motor_initialize(void);
extern void angle_motor_step(void);
extern void angle_motor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_angle_motor_T *const angle_motor_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S6>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S23>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S24>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S25>/Manual Switch' : Eliminated due to constant selection input
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
 * '<Root>' : 'angle_motor'
 * '<S1>'   : 'angle_motor/Compare To Constant'
 * '<S2>'   : 'angle_motor/Compare To Constant1'
 * '<S3>'   : 'angle_motor/Compare To Constant2'
 * '<S4>'   : 'angle_motor/Counter Limited'
 * '<S5>'   : 'angle_motor/Counter Limited1'
 * '<S6>'   : 'angle_motor/Counter Limited2'
 * '<S7>'   : 'angle_motor/M1 current filter'
 * '<S8>'   : 'angle_motor/currentPID_motor2'
 * '<S9>'   : 'angle_motor/encoder to rpm'
 * '<S10>'  : 'angle_motor/speedPID_motor1'
 * '<S11>'  : 'angle_motor/speedPID_motor2'
 * '<S12>'  : 'angle_motor/zero limit2'
 * '<S13>'  : 'angle_motor/Counter Limited/Increment Real World'
 * '<S14>'  : 'angle_motor/Counter Limited/Wrap To Zero'
 * '<S15>'  : 'angle_motor/Counter Limited1/Increment Real World'
 * '<S16>'  : 'angle_motor/Counter Limited1/Wrap To Zero'
 * '<S17>'  : 'angle_motor/Counter Limited2/Increment Real World'
 * '<S18>'  : 'angle_motor/Counter Limited2/Wrap To Zero'
 * '<S19>'  : 'angle_motor/currentPID_motor2/D'
 * '<S20>'  : 'angle_motor/currentPID_motor2/I'
 * '<S21>'  : 'angle_motor/currentPID_motor2/P'
 * '<S22>'  : 'angle_motor/currentPID_motor2/D/Difference'
 * '<S23>'  : 'angle_motor/speedPID_motor1/D'
 * '<S24>'  : 'angle_motor/speedPID_motor1/I'
 * '<S25>'  : 'angle_motor/speedPID_motor1/P'
 * '<S26>'  : 'angle_motor/speedPID_motor1/D/Difference'
 * '<S27>'  : 'angle_motor/speedPID_motor2/D'
 * '<S28>'  : 'angle_motor/speedPID_motor2/I'
 * '<S29>'  : 'angle_motor/speedPID_motor2/P'
 * '<S30>'  : 'angle_motor/speedPID_motor2/D/Difference'
 */
#endif                                 /* RTW_HEADER_angle_motor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
