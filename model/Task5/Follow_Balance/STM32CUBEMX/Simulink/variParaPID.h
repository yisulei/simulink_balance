/*
 * File: variParaPID.h
 *
 * Code generated for Simulink model 'variParaPID'.
 *
 * Model version                  : 7.7
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Oct  6 15:40:44 2022
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_variParaPID_h_
#define RTW_HEADER_variParaPID_h_
#ifndef variParaPID_COMMON_INCLUDES_
#define variParaPID_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* variParaPID_COMMON_INCLUDES_ */

#include "variParaPID_types.h"

/* Block states (default storage) for model 'variParaPID' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<Root>/Delay' */
  real32_T UD_DSTATE;                  /* '<S1>/UD' */
} DW_variParaPID_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_variParaPID_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_variParaPID_f_T rtdw;
  RT_MODEL_variParaPID_T rtm;
} MdlrefDW_variParaPID_T;

/* Model reference registration function */
extern void variParaPID_initialize(const char_T **rt_errorStatus,
  RT_MODEL_variParaPID_T *const variParaPID_M);
extern void variParaPID(const real32_T *rtu_setkp, const real32_T *rtu_setki,
  const real32_T *rtu_setilimit, const real32_T *rtu_setkd, const real32_T
  *rtu_Inputtarget, const real32_T *rtu_Inputfeedback, real32_T *rty_output,
  DW_variParaPID_f_T *localDW);

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
 * '<Root>' : 'variParaPID'
 * '<S1>'   : 'variParaPID/Difference'
 * '<S2>'   : 'variParaPID/limit'
 */
#endif                                 /* RTW_HEADER_variParaPID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
