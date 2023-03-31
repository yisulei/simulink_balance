/*
 * File: variParaPID.c
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

#include "variParaPID.h"
#include "variParaPID_private.h"

/* Output and update for referenced model: 'variParaPID' */
void variParaPID(const real32_T *rtu_setkp, const real32_T *rtu_setki, const
                 real32_T *rtu_setilimit, const real32_T *rtu_setkd, const
                 real32_T *rtu_Inputtarget, const real32_T *rtu_Inputfeedback,
                 real32_T *rty_output, DW_variParaPID_f_T *localDW)
{
  real32_T rtb_Gain;
  real32_T rtb_KiProduct;
  real32_T rtb_Sum;
  boolean_T rtb_RelationalOperator;

  /* Sum: '<Root>/Sum' */
  rtb_Sum = *rtu_Inputtarget - *rtu_Inputfeedback;

  /* Product: '<Root>/Ki Product' */
  rtb_KiProduct = *rtu_setki * rtb_Sum;

  /* RelationalOperator: '<S2>/Relational Operator' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_RelationalOperator = (localDW->Delay_DSTATE > *rtu_setilimit);

  /* Switch: '<S2>/Switch' */
  if (rtb_RelationalOperator) {
    /* UnitDelay: '<S1>/UD'
     *
     * Block description for '<S1>/UD':
     *
     *  Store in Global RAM
     */
    localDW->Delay_DSTATE = *rtu_setilimit;
  } else {
    /* Gain: '<S2>/Gain' */
    rtb_Gain = -*rtu_setilimit;

    /* Switch: '<S2>/Switch1' incorporates:
     *  Delay: '<Root>/Delay'
     *  RelationalOperator: '<S2>/Relational Operator1'
     */
    if (localDW->Delay_DSTATE < rtb_Gain) {
      /* UnitDelay: '<S1>/UD'
       *
       * Block description for '<S1>/UD':
       *
       *  Store in Global RAM
       */
      localDW->Delay_DSTATE = rtb_Gain;
    }

    /* End of Switch: '<S2>/Switch1' */
  }

  /* End of Switch: '<S2>/Switch' */

  /* UnitDelay: '<S1>/UD' incorporates:
   *  Sum: '<Root>/Add'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  localDW->Delay_DSTATE += rtb_KiProduct;

  /* Product: '<Root>/Kd Product' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  rtb_KiProduct = (rtb_Sum - localDW->UD_DSTATE) * *rtu_setkd;

  /* Product: '<Root>/Kp Product' */
  rtb_Gain = *rtu_setkp * rtb_Sum;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  *rty_output = (rtb_Gain + localDW->Delay_DSTATE) + rtb_KiProduct;

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_Sum;
}

/* Model initialize function */
void variParaPID_initialize(const char_T **rt_errorStatus,
  RT_MODEL_variParaPID_T *const variParaPID_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(variParaPID_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
