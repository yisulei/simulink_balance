/*
 * File: angle_motor.c
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

#include "ifr-scope_device.h"
#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "stdio.h"
#include <string.h>
#include "angle_motor.h"
#include "angle_motor_private.h"

const uint8_T angle_motor_U8GND = 0U;  /* uint8_T ground */

/* Block signals (default storage) */
B_angle_motor_T angle_motor_B;

/* Block states (default storage) */
DW_angle_motor_T angle_motor_DW;

/* Real-time model */
static RT_MODEL_angle_motor_T angle_motor_M_;
RT_MODEL_angle_motor_T *const angle_motor_M = &angle_motor_M_;
extern union _floatchar DataLink_RevData[10];//data config from host
extern struct _datalink_upframedata DataLink_UpFrameData;//data Up to Host
extern int16_t HI226_Angle[3];
extern int16_t HI226_AngleV[3];
extern int16_t adc_rawvalue[2][5];
extern int16_t motor1_PwmData;
extern int16_t motor2_PwmData;
extern uint8_t led_data;
extern uint8_t ws2812_data[3];

/* Model step function */
void angle_motor_step(void)
{
  real_T rtb_Add;
  int_T idxDelay;
  real32_T rtb_Add1_m5;
  boolean_T rtb_Compare_o;

  /* S-Function (StackLiteDualDrive_Input): '<Root>/Input1' */
  /*Input Data*/
  memcpy(&angle_motor_B.angle[0],HI226_Angle,3*2);
  memcpy(&angle_motor_B.anglev[0],HI226_AngleV,3*2);
  angle_motor_B.encoder1= (int32_t)(__HAL_TIM_GetCounter(&htim5));
  angle_motor_B.encoder2= -(int32_t)(__HAL_TIM_GetCounter(&htim2));
  memcpy(&angle_motor_B.current1[0],adc_rawvalue[0],5*2);
  memcpy(&angle_motor_B.current1_j[0],adc_rawvalue[1],5*2);

  /* S-Function (StackLiteDualDrive_DataLinkInput): '<Root>/DataLinkInput' */

  /*Input Data*/
  angle_motor_B.DataLinkInput_o1= DataLink_RevData[0].point;
  angle_motor_B.DataLinkInput_o2= DataLink_RevData[1].point;
  angle_motor_B.DataLinkInput_o3= DataLink_RevData[2].point;
  angle_motor_B.DataLinkInput_o4= DataLink_RevData[3].point;
  angle_motor_B.DataLinkInput_o5= DataLink_RevData[4].point;
  angle_motor_B.DataLinkInput_o6= DataLink_RevData[5].point;
  angle_motor_B.DataLinkInput_o7= DataLink_RevData[6].point;
  angle_motor_B.DataLinkInput_o8= DataLink_RevData[7].point;
  angle_motor_B.DataLinkInput_o9= DataLink_RevData[8].point;
  angle_motor_B.DataLinkInput_o10= DataLink_RevData[9].point;

  /* S-Function (StackLiteDualDrive_DataLinkOutput): '<Root>/DataLinkOutput' */
  /*Output Data*/
  DataLink_UpFrameData.data[0].point= angle_motor_B.DataLinkInput_o1;
  DataLink_UpFrameData.data[1].point= angle_motor_B.Divide;
  DataLink_UpFrameData.data[2].point= angle_motor_B.Divide1;
  DataLink_UpFrameData.data[3].point= angle_motor_B.Add_m;
  DataLink_UpFrameData.data[4].point= 0.0F;
  DataLink_UpFrameData.data[5].point= 0.0F;
  DataLink_UpFrameData.data[6].point= 0.0F;
  DataLink_UpFrameData.data[7].point= 0.0F;
  DataLink_UpFrameData.data[8].point= 0.0F;
  DataLink_UpFrameData.data[9].point= 0.0F;
  DataLink_UpFrameData.data[10].point= 0.0F;
  DataLink_UpFrameData.data[11].point= 0.0F;
  DataLink_UpFrameData.data[12].point= 0.0F;
  DataLink_UpFrameData.data[13].point= 0.0F;
  DataLink_UpFrameData.data[14].point= 0.0F;
  DataLink_UpFrameData.data[15].point= 0.0F;
  DataLink_UpFrameData.data[16].point= 0.0F;
  DataLink_UpFrameData.data[17].point= 0.0F;
  DataLink_UpFrameData.data[18].point= 0.0F;
  DataLink_UpFrameData.data[19].point= 0.0F;

  /* S-Function (StackLiteDualDrive_Output): '<Root>/Output' */
  /*Output Data*/
  motor1_PwmData= angle_motor_B.Saturation2;
  motor2_PwmData= angle_motor_B.Saturation1;
  HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,(GPIO_PinState)((uint8_T)0U));
  memcpy(ws2812_data,((const uint8_T*) &angle_motor_U8GND),3);

  /* Outputs for Enabled SubSystem: '<Root>/encoder to rpm' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<S6>/Output'
   */
  if (angle_motor_DW.Output_DSTATE == 1) {
    /* Product: '<S9>/Divide' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant2'
     *  Delay: '<S9>/Delay'
     *  Product: '<S9>/Product'
     *  Product: '<S9>/Product1'
     *  Sum: '<S9>/Add1'
     */
    angle_motor_B.Divide = (real32_T)(angle_motor_B.encoder1 -
      angle_motor_DW.Delay_DSTATE_f[0]) * 100.0F * 60.0F / 40000.0F;

    /* Product: '<S9>/Divide1' incorporates:
     *  Constant: '<S9>/Constant3'
     *  Constant: '<S9>/Constant4'
     *  Constant: '<S9>/Constant5'
     *  Delay: '<S9>/Delay1'
     *  Product: '<S9>/Product2'
     *  Product: '<S9>/Product3'
     *  Sum: '<S9>/Add2'
     */
    angle_motor_B.Divide1 = (real32_T)(angle_motor_B.encoder2 -
      angle_motor_DW.Delay1_DSTATE[0]) * 100.0F * 60.0F / 40000.0F;
    for (idxDelay = 0; idxDelay < 18; idxDelay++) {
      /* Update for Delay: '<S9>/Delay' */
      angle_motor_DW.Delay_DSTATE_f[idxDelay] =
        angle_motor_DW.Delay_DSTATE_f[idxDelay + 1];

      /* Update for Delay: '<S9>/Delay1' */
      angle_motor_DW.Delay1_DSTATE[idxDelay] =
        angle_motor_DW.Delay1_DSTATE[idxDelay + 1];
    }

    /* Update for Delay: '<S9>/Delay' */
    angle_motor_DW.Delay_DSTATE_f[18] = angle_motor_B.encoder1;

    /* Update for Delay: '<S9>/Delay1' */
    angle_motor_DW.Delay1_DSTATE[18] = angle_motor_B.encoder2;
  }

  /* End of RelationalOperator: '<S3>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/encoder to rpm' */

  /* Outputs for Enabled SubSystem: '<Root>/speedPID_motor2' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S4>/Output'
   */
  if (angle_motor_DW.Output_DSTATE_d == 1) {
    /* Sum: '<S11>/Add1' */
    rtb_Add1_m5 = angle_motor_B.DataLinkInput_o1 - angle_motor_B.Divide1;

    /* Gain: '<S28>/Gain1' incorporates:
     *  DataStoreWrite: '<Root>/Data Store Write2'
     *  Delay: '<S28>/Delay'
     *  Gain: '<S28>/Gain'
     *  ManualSwitch: '<S28>/Manual Switch1'
     *  Product: '<S28>/Product3'
     *  Sum: '<S28>/Add2'
     */
    angle_motor_DW.Delay_DSTATE_d = ((real32_T)(0.01 *
      angle_motor_B.DataLinkInput_o3 * rtb_Add1_m5) +
      angle_motor_DW.Delay_DSTATE_d) * 0.995;

    /* Saturate: '<S28>/Saturation2' */
    if (angle_motor_DW.Delay_DSTATE_d > 1500.0) {
      /* Gain: '<S28>/Gain1' */
      angle_motor_DW.Delay_DSTATE_d = 1500.0;
    } else if (angle_motor_DW.Delay_DSTATE_d < -1500.0) {
      /* Gain: '<S28>/Gain1' */
      angle_motor_DW.Delay_DSTATE_d = -1500.0;
    }

    /* End of Saturate: '<S28>/Saturation2' */

    /* Sum: '<S11>/Add' incorporates:
     *  DataStoreWrite: '<Root>/Data Store Write'
     *  DataStoreWrite: '<Root>/Data Store Write3'
     *  Delay: '<S28>/Delay'
     *  ManualSwitch: '<S27>/Manual Switch2'
     *  ManualSwitch: '<S29>/Manual Switch'
     *  Product: '<S27>/Product2'
     *  Product: '<S29>/Product'
     *  Sum: '<S30>/Diff'
     *  UnitDelay: '<S30>/UD'
     *
     * Block description for '<S30>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S30>/UD':
     *
     *  Store in Global RAM
     */
    angle_motor_B.Add = ((real_T)angle_motor_B.DataLinkInput_o2 * rtb_Add1_m5 +
                         angle_motor_DW.Delay_DSTATE_d) + (real_T)(rtb_Add1_m5 -
      angle_motor_DW.UD_DSTATE_i) * angle_motor_B.DataLinkInput_o4;

    /* Update for UnitDelay: '<S30>/UD'
     *
     * Block description for '<S30>/UD':
     *
     *  Store in Global RAM
     */
    angle_motor_DW.UD_DSTATE_i = rtb_Add1_m5;
  }

  /* End of RelationalOperator: '<S1>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/speedPID_motor2' */

  /* Saturate: '<Root>/Saturation3' */
  if (angle_motor_B.Add > 2048.0) {
    rtb_Add = 2048.0;
  } else if (angle_motor_B.Add < -2048.0) {
    rtb_Add = -2048.0;
  } else {
    rtb_Add = angle_motor_B.Add;
  }

  rtb_Add = floor(rtb_Add);
  if (rtIsNaN(rtb_Add)) {
    rtb_Add = 0.0;
  } else {
    rtb_Add = fmod(rtb_Add, 65536.0);
  }

  /* Switch: '<S12>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation3'
   */
  angle_motor_B.Saturation1 = (int16_T)(rtb_Add < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)rtb_Add);

  /* RateLimiter: '<Root>/Rate Limiter1' */
  if (angle_motor_B.Saturation1 - angle_motor_DW.PrevY > 5) {
    /* Switch: '<S12>/Switch1' */
    angle_motor_B.Saturation1 = (int16_T)(angle_motor_DW.PrevY + 5);
  } else if (angle_motor_B.Saturation1 - angle_motor_DW.PrevY < -5) {
    /* Switch: '<S12>/Switch1' */
    angle_motor_B.Saturation1 = (int16_T)(angle_motor_DW.PrevY + -5);
  }

  angle_motor_DW.PrevY = angle_motor_B.Saturation1;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* Sum: '<Root>/Add' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   */
  angle_motor_B.Add_m = angle_motor_B.DataLinkInput_o8 + (real32_T)
    angle_motor_B.Saturation1;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  UnitDelay: '<S5>/Output'
   */
  rtb_Compare_o = (angle_motor_DW.Output_DSTATE_j == 1);

  /* Switch: '<S14>/FixPt Switch' incorporates:
   *  Constant: '<S13>/FixPt Constant'
   *  Constant: '<S14>/Constant'
   *  Sum: '<S13>/FixPt Sum1'
   *  UnitDelay: '<S4>/Output'
   */
  if ((uint8_T)(angle_motor_DW.Output_DSTATE_d + 1) > 1) {
    angle_motor_DW.Output_DSTATE_d = 0U;
  } else {
    angle_motor_DW.Output_DSTATE_d++;
  }

  /* End of Switch: '<S14>/FixPt Switch' */

  /* Switch: '<S16>/FixPt Switch' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  Constant: '<S16>/Constant'
   *  Sum: '<S15>/FixPt Sum1'
   *  UnitDelay: '<S5>/Output'
   */
  if ((uint8_T)(angle_motor_DW.Output_DSTATE_j + 1) > 1) {
    angle_motor_DW.Output_DSTATE_j = 0U;
  } else {
    angle_motor_DW.Output_DSTATE_j++;
  }

  /* End of Switch: '<S16>/FixPt Switch' */

  /* Switch: '<S18>/FixPt Switch' incorporates:
   *  Constant: '<S17>/FixPt Constant'
   *  Constant: '<S18>/Constant'
   *  Sum: '<S17>/FixPt Sum1'
   *  UnitDelay: '<S6>/Output'
   */
  if ((uint8_T)(angle_motor_DW.Output_DSTATE + 1) > 1) {
    angle_motor_DW.Output_DSTATE = 0U;
  } else {
    angle_motor_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S18>/FixPt Switch' */

  /* Sum: '<S7>/Add4' incorporates:
   *  Delay: '<S7>/Delay One Step'
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   *  Gain: '<S7>/Gain3'
   *  Gain: '<S7>/Gain4'
   *  Gain: '<S7>/Gain5'
   *  Gain: '<S7>/Gain6'
   *  Gain: '<S7>/Gain7'
   *  Gain: '<S7>/Gain8'
   *  Gain: '<S7>/Gain9'
   *  Sum: '<S7>/Add'
   *  Sum: '<S7>/Add1'
   *  Sum: '<S7>/Add2'
   *  Sum: '<S7>/Add3'
   */
  angle_motor_DW.DelayOneStep_DSTATE = ((((0.95F *
    angle_motor_DW.DelayOneStep_DSTATE + 0.0499992371F * (real32_T)
    angle_motor_B.current1_j[0]) * 0.95F + 0.0499992371F * (real32_T)
    angle_motor_B.current1_j[1]) * 0.95F + 0.0499992371F * (real32_T)
    angle_motor_B.current1_j[2]) * 0.95F + 0.0499992371F * (real32_T)
    angle_motor_B.current1_j[3]) * 0.95F + 0.0499992371F * (real32_T)
    angle_motor_B.current1_j[4];

  /* Sum: '<S8>/Add1' incorporates:
   *  Delay: '<S7>/Delay One Step'
   */
  rtb_Add1_m5 = angle_motor_B.Add_m - angle_motor_DW.DelayOneStep_DSTATE;

  /* Gain: '<S20>/Gain1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write4'
   *  Delay: '<S20>/Delay'
   *  Gain: '<S20>/Gain'
   *  ManualSwitch: '<S20>/Manual Switch1'
   *  Product: '<S20>/Product3'
   *  Sum: '<S20>/Add2'
   */
  angle_motor_DW.Delay_DSTATE = ((real32_T)(0.01 *
    angle_motor_B.DataLinkInput_o6 * rtb_Add1_m5) + angle_motor_DW.Delay_DSTATE)
    * 0.998;

  /* Saturate: '<S20>/Saturation' */
  if (angle_motor_DW.Delay_DSTATE > 2000.0) {
    /* Gain: '<S20>/Gain1' */
    angle_motor_DW.Delay_DSTATE = 2000.0;
  } else if (angle_motor_DW.Delay_DSTATE < -2000.0) {
    /* Gain: '<S20>/Gain1' */
    angle_motor_DW.Delay_DSTATE = -2000.0;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* Sum: '<S8>/Add' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write1'
   *  DataStoreWrite: '<Root>/Data Store Write5'
   *  Delay: '<S20>/Delay'
   *  ManualSwitch: '<S19>/Manual Switch2'
   *  ManualSwitch: '<S21>/Manual Switch'
   *  Product: '<S19>/Product2'
   *  Product: '<S21>/Product'
   *  Sum: '<S22>/Diff'
   *  UnitDelay: '<S22>/UD'
   *
   * Block description for '<S22>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S22>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add = ((real_T)angle_motor_B.DataLinkInput_o5 * rtb_Add1_m5 +
             angle_motor_DW.Delay_DSTATE) + (real_T)(rtb_Add1_m5 -
    angle_motor_DW.UD_DSTATE) * angle_motor_B.DataLinkInput_o7;

  /* Switch: '<S12>/Switch1' incorporates:
   *  Delay: '<S7>/Delay One Step'
   *  Switch: '<S12>/Switch3'
   */
  if (angle_motor_DW.DelayOneStep_DSTATE > -30.0F) {
    /* Switch: '<S12>/Switch' */
    if (angle_motor_DW.DelayOneStep_DSTATE > 30.0F) {
      /* Switch: '<S12>/Switch2' */
      if (rtb_Add > 0.0) {
        rtb_Add = floor(rtb_Add);
        if (rtIsInf(rtb_Add)) {
          /* Switch: '<S12>/Switch1' */
          angle_motor_B.Saturation1 = 0;
        } else {
          /* Switch: '<S12>/Switch1' */
          angle_motor_B.Saturation1 = (int16_T)(int32_T)fmod(rtb_Add, 65536.0);
        }
      } else {
        /* Switch: '<S12>/Switch1' incorporates:
         *  Constant: '<S12>/Constant'
         */
        angle_motor_B.Saturation1 = 10;
      }

      /* End of Switch: '<S12>/Switch2' */
    } else {
      rtb_Add = floor(rtb_Add);
      if (rtIsNaN(rtb_Add) || rtIsInf(rtb_Add)) {
        rtb_Add = 0.0;
      } else {
        rtb_Add = fmod(rtb_Add, 65536.0);
      }

      /* Switch: '<S12>/Switch1' */
      angle_motor_B.Saturation1 = (int16_T)(rtb_Add < 0.0 ? (int32_T)(int16_T)
        -(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)rtb_Add);
    }

    /* End of Switch: '<S12>/Switch' */
  } else if (rtb_Add > 0.0) {
    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Switch: '<S12>/Switch3'
     */
    angle_motor_B.Saturation1 = -10;
  } else {
    /* Switch: '<S12>/Switch3' */
    rtb_Add = floor(rtb_Add);
    if (rtIsNaN(rtb_Add) || rtIsInf(rtb_Add)) {
      rtb_Add = 0.0;
    } else {
      rtb_Add = fmod(rtb_Add, 65536.0);
    }

    /* Switch: '<S12>/Switch1' incorporates:
     *  Switch: '<S12>/Switch3'
     */
    angle_motor_B.Saturation1 = (int16_T)(rtb_Add < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)rtb_Add);
  }

  /* End of Switch: '<S12>/Switch1' */

  /* Saturate: '<Root>/Saturation1' */
  if (angle_motor_B.Saturation1 > 4200) {
    /* Switch: '<S12>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    angle_motor_B.Saturation1 = 4200;
  } else if (angle_motor_B.Saturation1 < -4200) {
    /* Switch: '<S12>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    angle_motor_B.Saturation1 = -4200;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Outputs for Enabled SubSystem: '<Root>/speedPID_motor1' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (rtb_Compare_o) {
    real32_T rtb_Add1_n;

    /* Sum: '<S10>/Add1' */
    rtb_Add1_n = angle_motor_B.DataLinkInput_o1 - angle_motor_B.Divide;

    /* Gain: '<S24>/Gain1' incorporates:
     *  Constant: '<S24>/Constant1'
     *  Delay: '<S24>/Delay'
     *  Gain: '<S24>/Gain'
     *  Product: '<S24>/Product3'
     *  Sum: '<S24>/Add2'
     */
    angle_motor_DW.Delay_DSTATE_c = ((real32_T)(-1.6 * rtb_Add1_n) +
      angle_motor_DW.Delay_DSTATE_c) * 0.99;

    /* Saturate: '<S24>/Saturation' */
    if (angle_motor_DW.Delay_DSTATE_c > 600.0) {
      /* Gain: '<S24>/Gain1' */
      angle_motor_DW.Delay_DSTATE_c = 600.0;
    } else if (angle_motor_DW.Delay_DSTATE_c < -600.0) {
      /* Gain: '<S24>/Gain1' */
      angle_motor_DW.Delay_DSTATE_c = -600.0;
    }

    /* End of Saturate: '<S24>/Saturation' */

    /* Sum: '<S10>/Add' incorporates:
     *  Constant: '<S23>/Constant2'
     *  Constant: '<S25>/Constant'
     *  Delay: '<S24>/Delay'
     *  Product: '<S23>/Product2'
     *  Product: '<S25>/Product'
     *  Sum: '<S26>/Diff'
     *  UnitDelay: '<S26>/UD'
     *
     * Block description for '<S26>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S26>/UD':
     *
     *  Store in Global RAM
     */
    angle_motor_B.Add_o = (-40.0 * rtb_Add1_n + angle_motor_DW.Delay_DSTATE_c) +
      (rtb_Add1_n - angle_motor_DW.UD_DSTATE_j) * -150.0;

    /* Update for UnitDelay: '<S26>/UD'
     *
     * Block description for '<S26>/UD':
     *
     *  Store in Global RAM
     */
    angle_motor_DW.UD_DSTATE_j = rtb_Add1_n;
  }

  /* End of Outputs for SubSystem: '<Root>/speedPID_motor1' */

  /* Saturate: '<Root>/Saturation2' */
  if (angle_motor_B.Add_o > 4200.0) {
    rtb_Add = 4200.0;
  } else if (angle_motor_B.Add_o < -4200.0) {
    rtb_Add = -4200.0;
  } else {
    rtb_Add = angle_motor_B.Add_o;
  }

  rtb_Add = floor(rtb_Add);
  if (rtIsNaN(rtb_Add)) {
    rtb_Add = 0.0;
  } else {
    rtb_Add = fmod(rtb_Add, 65536.0);
  }

  /* Saturate: '<Root>/Saturation2' */
  angle_motor_B.Saturation2 = (int16_T)(rtb_Add < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)rtb_Add);

  /* Update for UnitDelay: '<S22>/UD'
   *
   * Block description for '<S22>/UD':
   *
   *  Store in Global RAM
   */
  angle_motor_DW.UD_DSTATE = rtb_Add1_m5;
}

/* Model initialize function */
void angle_motor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void angle_motor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
