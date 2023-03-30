/*
 * File: angle_led.h
 *
 * Code generated for Simulink model 'angle_led'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Oct 29 21:45:31 2022
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_angle_led_h_
#define RTW_HEADER_angle_led_h_
#ifndef angle_led_COMMON_INCLUDES_
#define angle_led_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* angle_led_COMMON_INCLUDES_ */

#include "angle_led_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  int32_T encoder1;                    /* '<Root>/Input' */
  int32_T encoder2;                    /* '<Root>/Input' */
  int16_T angle[3];                    /* '<Root>/Input' */
  int16_T anglev[3];                   /* '<Root>/Input' */
  int16_T current1[5];                 /* '<Root>/Input' */
  int16_T current2[5];                 /* '<Root>/Input' */
  uint8_T LogicalOperator;             /* '<S5>/Logical Operator' */
} B_angle_led_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T Output_DSTATE;              /* '<S4>/Output' */
  uint8_T Output_DSTATE_a;             /* '<S3>/Output' */
  uint8_T Delay1_DSTATE;               /* '<S5>/Delay1' */
} DW_angle_led_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Constant1_Value
   * Referenced by: '<Root>/Constant1'
   */
  uint8_T Constant1_Value[3];
} ConstP_angle_led_T;

/* Real-time Model Data Structure */
struct tag_RTM_angle_led_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_angle_led_T angle_led_B;

/* Block states (default storage) */
extern DW_angle_led_T angle_led_DW;

/* Constant parameters (default storage) */
extern const ConstP_angle_led_T angle_led_ConstP;

/* Model entry point functions */
extern void angle_led_initialize(void);
extern void angle_led_step(void);
extern void angle_led_terminate(void);

/* Real-time Model object */
extern RT_MODEL_angle_led_T *const angle_led_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * '<Root>' : 'angle_led'
 * '<S1>'   : 'angle_led/Compare To Constant'
 * '<S2>'   : 'angle_led/Compare To Constant1'
 * '<S3>'   : 'angle_led/Counter Limited'
 * '<S4>'   : 'angle_led/Counter Limited1'
 * '<S5>'   : 'angle_led/LED Blink1'
 * '<S6>'   : 'angle_led/Counter Limited/Increment Real World'
 * '<S7>'   : 'angle_led/Counter Limited/Wrap To Zero'
 * '<S8>'   : 'angle_led/Counter Limited1/Increment Real World'
 * '<S9>'   : 'angle_led/Counter Limited1/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_angle_led_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
