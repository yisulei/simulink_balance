/*
 * File: Follow_Balance.h
 *
 * Code generated for Simulink model 'Follow_Balance'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Apr 11 20:11:05 2023
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Follow_Balance_h_
#define RTW_HEADER_Follow_Balance_h_
#include <math.h>
#ifndef Follow_Balance_COMMON_INCLUDES_
#define Follow_Balance_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Follow_Balance_COMMON_INCLUDES_ */

#include "Follow_Balance_types.h"
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
  real_T Saturation;                   /* '<S17>/Saturation' */
  real_T Add;                          /* '<S42>/Add' */
  real_T Add_o;                        /* '<S11>/Add' */
  real32_T DataStoreRead10;            /* '<Root>/Data Store Read10' */
  real32_T DataStoreRead14;            /* '<Root>/Data Store Read14' */
  real32_T DataStoreRead19;            /* '<Root>/Data Store Read19' */
  real32_T DataStoreRead20;            /* '<Root>/Data Store Read20' */
  real32_T DataTypeConversion11;       /* '<Root>/Data Type Conversion11' */
  real32_T DataTypeConversion3;        /* '<Root>/Data Type Conversion3' */
  real32_T DataTypeConversion8;        /* '<Root>/Data Type Conversion8' */
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
  real32_T Delay;                      /* '<S56>/Delay' */
  real32_T Divide;                     /* '<S15>/Divide' */
  real32_T Divide1;                    /* '<S15>/Divide1' */
  int32_T encoder1;                    /* '<Root>/Input' */
  int32_T encoder2;                    /* '<Root>/Input' */
  int32_T RPiDataInput_o1;             /* '<Root>/RPiDataInput' */
  int32_T RPiDataInput_o2;             /* '<Root>/RPiDataInput' */
  int32_T RPiDataInput_o3;             /* '<Root>/RPiDataInput' */
  int32_T RPiDataInput_o4;             /* '<Root>/RPiDataInput' */
  int16_T angle[3];                    /* '<Root>/Input' */
  int16_T anglev[3];                   /* '<Root>/Input' */
  int16_T current1[5];                 /* '<Root>/Input' */
  int16_T current2[5];                 /* '<Root>/Input' */
  int16_T Saturation_d;                /* '<Root>/Saturation' */
  int16_T Saturation1;                 /* '<Root>/Saturation1' */
} B_Follow_Balance_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S35>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S53>/Delay' */
  real_T UD_DSTATE;                    /* '<S57>/UD' */
  real_T UD_DSTATE_o;                  /* '<S46>/UD' */
  real_T test_ball;                    /* '<Root>/Data Store Memory17' */
  real_T Ki_sper;                      /* '<Root>/Data Store Memory29' */
  real_T flag;                         /* '<Root>/Data Store Memory10' */
  real_T tar_speed;                    /* '<Root>/Data Store Memory12' */
  real_T Ki_speed;                     /* '<Root>/Data Store Memory14' */
  real_T Kd_speed;                     /* '<Root>/Data Store Memory15' */
  real_T tar_lenth;                    /* '<Root>/Data Store Memory25' */
  real_T machine_mid;                  /* '<Root>/Data Store Memory7' */
  real32_T DelayOneStep_DSTATE;        /* '<S12>/Delay One Step' */
  real32_T DelayOneStep_DSTATE_d;      /* '<S13>/Delay One Step' */
  real32_T UD_DSTATE_f;                /* '<S37>/UD' */
  real32_T Delay_DSTATE_g;             /* '<S39>/Delay' */
  real32_T UD_DSTATE_k;                /* '<S41>/UD' */
  real32_T Delay_DSTATE_p;             /* '<S56>/Delay' */
  real32_T Delay_DSTATE_n;             /* '<S48>/Delay' */
  real32_T Delay_DSTATE_i;             /* '<S44>/Delay' */
  int32_T Delay_DSTATE_o[19];          /* '<S15>/Delay' */
  int32_T Delay1_DSTATE[19];           /* '<S15>/Delay1' */
  real32_T usart_input3;               /* '<Root>/Data Store Memory18' */
  real32_T tar_yaw;                    /* '<Root>/Data Store Memory20' */
  real32_T usart_input4;               /* '<Root>/Data Store Memory24' */
  int32_T yaw_begin;                   /* '<Root>/Data Store Memory11' */
  int16_T PrevY;                       /* '<Root>/Rate Limiter1' */
  int16_T PrevY_n;                     /* '<Root>/Rate Limiter2' */
  uint8_T Output_DSTATE;               /* '<S8>/Output' */
  uint8_T Output_DSTATE_i;             /* '<S9>/Output' */
  uint8_T Output_DSTATE_a;             /* '<S10>/Output' */
  uint8_T Output_DSTATE_i5;            /* '<S7>/Output' */
} DW_Follow_Balance_T;

/* Real-time Model Data Structure */
struct tag_RTM_Follow_Balance_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Follow_Balance_T Follow_Balance_B;

/* Block states (default storage) */
extern DW_Follow_Balance_T Follow_Balance_DW;

/* External data declarations for dependent source files */
extern const uint8_T Follow_Balance_U8GND;/* uint8_T ground */

/* Model entry point functions */
extern void Follow_Balance_initialize(void);
extern void Follow_Balance_step(void);
extern void Follow_Balance_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Follow_Balance_T *const Follow_Balance_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S22>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<Root>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S30>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S31>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S34>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S35>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S36>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S38>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S39>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S40>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S43>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S44>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S45>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S47>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S48>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S49>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S50>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S53>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S54>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S43>/Constant2' : Unused code path elimination
 * Block '<S44>/Constant1' : Unused code path elimination
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
 * '<Root>' : 'Follow_Balance'
 * '<S1>'   : 'Follow_Balance/Compare To Constant'
 * '<S2>'   : 'Follow_Balance/Compare To Constant1'
 * '<S3>'   : 'Follow_Balance/Compare To Constant2'
 * '<S4>'   : 'Follow_Balance/Compare To Constant3'
 * '<S5>'   : 'Follow_Balance/Compare To Constant4'
 * '<S6>'   : 'Follow_Balance/Compare To Constant5'
 * '<S7>'   : 'Follow_Balance/Counter Limited'
 * '<S8>'   : 'Follow_Balance/Counter Limited1'
 * '<S9>'   : 'Follow_Balance/Counter Limited2'
 * '<S10>'  : 'Follow_Balance/Counter Limited3'
 * '<S11>'  : 'Follow_Balance/anglePID'
 * '<S12>'  : 'Follow_Balance/currentFilter_motor1'
 * '<S13>'  : 'Follow_Balance/currentFilter_motor2'
 * '<S14>'  : 'Follow_Balance/currentPID'
 * '<S15>'  : 'Follow_Balance/encoder to rpm'
 * '<S16>'  : 'Follow_Balance/speedPID_motor'
 * '<S17>'  : 'Follow_Balance/turnPID'
 * '<S18>'  : 'Follow_Balance/usart to tar'
 * '<S19>'  : 'Follow_Balance/yaw to zero'
 * '<S20>'  : 'Follow_Balance/zero limit1'
 * '<S21>'  : 'Follow_Balance/zero limit2'
 * '<S22>'  : 'Follow_Balance/Counter Limited/Increment Real World'
 * '<S23>'  : 'Follow_Balance/Counter Limited/Wrap To Zero'
 * '<S24>'  : 'Follow_Balance/Counter Limited1/Increment Real World'
 * '<S25>'  : 'Follow_Balance/Counter Limited1/Wrap To Zero'
 * '<S26>'  : 'Follow_Balance/Counter Limited2/Increment Real World'
 * '<S27>'  : 'Follow_Balance/Counter Limited2/Wrap To Zero'
 * '<S28>'  : 'Follow_Balance/Counter Limited3/Increment Real World'
 * '<S29>'  : 'Follow_Balance/Counter Limited3/Wrap To Zero'
 * '<S30>'  : 'Follow_Balance/anglePID/D'
 * '<S31>'  : 'Follow_Balance/anglePID/P'
 * '<S32>'  : 'Follow_Balance/currentPID/currentPID_motor1'
 * '<S33>'  : 'Follow_Balance/currentPID/currentPID_motor2'
 * '<S34>'  : 'Follow_Balance/currentPID/currentPID_motor1/D'
 * '<S35>'  : 'Follow_Balance/currentPID/currentPID_motor1/I'
 * '<S36>'  : 'Follow_Balance/currentPID/currentPID_motor1/P'
 * '<S37>'  : 'Follow_Balance/currentPID/currentPID_motor1/D/Difference'
 * '<S38>'  : 'Follow_Balance/currentPID/currentPID_motor2/D'
 * '<S39>'  : 'Follow_Balance/currentPID/currentPID_motor2/I'
 * '<S40>'  : 'Follow_Balance/currentPID/currentPID_motor2/P'
 * '<S41>'  : 'Follow_Balance/currentPID/currentPID_motor2/D/Difference'
 * '<S42>'  : 'Follow_Balance/speedPID_motor/Subsystem2'
 * '<S43>'  : 'Follow_Balance/speedPID_motor/Subsystem2/D'
 * '<S44>'  : 'Follow_Balance/speedPID_motor/Subsystem2/I'
 * '<S45>'  : 'Follow_Balance/speedPID_motor/Subsystem2/P'
 * '<S46>'  : 'Follow_Balance/speedPID_motor/Subsystem2/D/Difference'
 * '<S47>'  : 'Follow_Balance/turnPID/D'
 * '<S48>'  : 'Follow_Balance/turnPID/I'
 * '<S49>'  : 'Follow_Balance/turnPID/P'
 * '<S50>'  : 'Follow_Balance/usart to tar/D'
 * '<S51>'  : 'Follow_Balance/usart to tar/Enabled Subsystem'
 * '<S52>'  : 'Follow_Balance/usart to tar/Enabled Subsystem1'
 * '<S53>'  : 'Follow_Balance/usart to tar/I'
 * '<S54>'  : 'Follow_Balance/usart to tar/P'
 * '<S55>'  : 'Follow_Balance/usart to tar/Subsystem'
 * '<S56>'  : 'Follow_Balance/usart to tar/Subsystem1'
 * '<S57>'  : 'Follow_Balance/usart to tar/D/Difference'
 * '<S58>'  : 'Follow_Balance/usart to tar/Subsystem/Enabled Subsystem'
 * '<S59>'  : 'Follow_Balance/usart to tar/Subsystem/Enabled Subsystem1'
 * '<S60>'  : 'Follow_Balance/usart to tar/Subsystem/Enabled Subsystem2'
 */
#endif                                 /* RTW_HEADER_Follow_Balance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
