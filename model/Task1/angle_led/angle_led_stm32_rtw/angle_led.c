/*
 * File: angle_led.c
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

#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "stdio.h"
#include <string.h>
#include "angle_led.h"
#include "angle_led_private.h"

/* Block signals (default storage) */
B_angle_led_T angle_led_B;

/* Block states (default storage) */
DW_angle_led_T angle_led_DW;

/* Real-time model */
static RT_MODEL_angle_led_T angle_led_M_;
RT_MODEL_angle_led_T *const angle_led_M = &angle_led_M_;
extern int16_t HI226_Angle[3];
extern int16_t HI226_AngleV[3];
extern int16_t adc_rawvalue[2][5];
extern int16_t motor1_PwmData;
extern int16_t motor2_PwmData;
extern uint8_t led_data;
extern uint8_t ws2812_data[3];

/* Model step function */
void angle_led_step(void)
{
  int16_T tmp_0;
  boolean_T tmp;

  /* S-Function (StackLiteDualDrive_Input): '<Root>/Input' */
  /*Input Data*/
  memcpy(&angle_led_B.angle[0],HI226_Angle,3*2);
  memcpy(&angle_led_B.anglev[0],HI226_AngleV,3*2);
  angle_led_B.encoder1= (int32_t)(__HAL_TIM_GetCounter(&htim2));
  angle_led_B.encoder2= -(int32_t)(__HAL_TIM_GetCounter(&htim5));
  memcpy(&angle_led_B.current1[0],adc_rawvalue[0],5*2);
  memcpy(&angle_led_B.current2[0],adc_rawvalue[1],5*2);

  /* Abs: '<Root>/Abs' */
  if (angle_led_B.angle[1] < 0) {
    tmp_0 = (int16_T)-angle_led_B.angle[1];
  } else {
    tmp_0 = angle_led_B.angle[1];
  }

  /* End of Abs: '<Root>/Abs' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  UnitDelay: '<S3>/Output'
   *  UnitDelay: '<S4>/Output'
   */
  if (tmp_0 > 3000) {
    tmp = (angle_led_DW.Output_DSTATE_a == 200);
  } else {
    tmp = (angle_led_DW.Output_DSTATE == 500);
  }

  /* End of Switch: '<Root>/Switch' */

  /* Outputs for Enabled SubSystem: '<Root>/LED Blink1' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (tmp) {
    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Delay: '<S5>/Delay1'
     */
    angle_led_B.LogicalOperator = (uint8_T)(angle_led_DW.Delay1_DSTATE == 0);

    /* Update for Delay: '<S5>/Delay1' */
    angle_led_DW.Delay1_DSTATE = angle_led_B.LogicalOperator;
  }

  /* End of Outputs for SubSystem: '<Root>/LED Blink1' */

  /* Switch: '<S9>/FixPt Switch' incorporates:
   *  Constant: '<S8>/FixPt Constant'
   *  Constant: '<S9>/Constant'
   *  Sum: '<S8>/FixPt Sum1'
   *  UnitDelay: '<S4>/Output'
   */
  if ((uint16_T)(angle_led_DW.Output_DSTATE + 1) > 500) {
    angle_led_DW.Output_DSTATE = 0U;
  } else {
    angle_led_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S9>/FixPt Switch' */

  /* Switch: '<S7>/FixPt Switch' incorporates:
   *  Constant: '<S6>/FixPt Constant'
   *  Constant: '<S7>/Constant'
   *  Sum: '<S6>/FixPt Sum1'
   *  UnitDelay: '<S3>/Output'
   */
  if ((uint8_T)(angle_led_DW.Output_DSTATE_a + 1) > 200) {
    angle_led_DW.Output_DSTATE_a = 0U;
  } else {
    angle_led_DW.Output_DSTATE_a++;
  }

  /* End of Switch: '<S7>/FixPt Switch' */

  /* S-Function (StackLiteDualDrive_Output): '<Root>/Output' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  /*Output Data*/
  motor1_PwmData= 0;
  motor2_PwmData= 0;
  HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,(GPIO_PinState)
                    angle_led_B.LogicalOperator);
  memcpy(ws2812_data,angle_led_ConstP.Constant1_Value,3);
}

/* Model initialize function */
void angle_led_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void angle_led_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
