/*
 * File: Stand_Balance.c
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

#include "ifr-scope_device.h"
#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "stdio.h"
#include <string.h>
#include "Stand_Balance.h"
#include "Stand_Balance_private.h"

const uint8_T Stand_Balance_U8GND = 0U;/* uint8_T ground */

/* Block signals (default storage) */
B_Stand_Balance_T Stand_Balance_B;

/* Block states (default storage) */
DW_Stand_Balance_T Stand_Balance_DW;

/* Real-time model */
static RT_MODEL_Stand_Balance_T Stand_Balance_M_;
RT_MODEL_Stand_Balance_T *const Stand_Balance_M = &Stand_Balance_M_;
extern struct _datalink_upframedata DataLink_UpFrameData;//data Up to Host
extern int16_t HI226_Angle[3];
extern int16_t HI226_AngleV[3];
extern int16_t adc_rawvalue[2][5];
extern int16_t motor1_PwmData;
extern int16_t motor2_PwmData;
extern uint8_t led_data;
extern uint8_t ws2812_data[3];
extern union _floatchar DataLink_RevData[10];//data config from host

/* Model step function */
void Stand_Balance_step(void)
{
  real_T rtb_Switch;
  int32_T tmp_0;
  real32_T rtb_Add1_a;
  real32_T rtb_Add1_k;
  int16_T tmp;
  boolean_T rtb_Compare;

  /* S-Function (StackLiteDualDrive_Input): '<Root>/Input' */
  /*Input Data*/
  memcpy(&Stand_Balance_B.angle[0],HI226_Angle,3*2);
  memcpy(&Stand_Balance_B.anglev[0],HI226_AngleV,3*2);
  Stand_Balance_B.encoder1= (int32_t)(__HAL_TIM_GetCounter(&htim5));
  Stand_Balance_B.encoder2= -(int32_t)(__HAL_TIM_GetCounter(&htim2));
  memcpy(&Stand_Balance_B.current1[0],adc_rawvalue[0],5*2);
  memcpy(&Stand_Balance_B.current2[0],adc_rawvalue[1],5*2);

  /* Sum: '<S4>/Add4' incorporates:
   *  Delay: '<S4>/Delay One Step'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain2'
   *  Gain: '<S4>/Gain3'
   *  Gain: '<S4>/Gain4'
   *  Gain: '<S4>/Gain5'
   *  Gain: '<S4>/Gain6'
   *  Gain: '<S4>/Gain7'
   *  Gain: '<S4>/Gain8'
   *  Gain: '<S4>/Gain9'
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add2'
   *  Sum: '<S4>/Add3'
   */
  Stand_Balance_DW.DelayOneStep_DSTATE = ((((0.95F *
    Stand_Balance_DW.DelayOneStep_DSTATE + 0.0499992371F * (real32_T)
    Stand_Balance_B.current1[0]) * 0.95F + 0.0499992371F * (real32_T)
    Stand_Balance_B.current1[1]) * 0.95F + 0.0499992371F * (real32_T)
    Stand_Balance_B.current1[2]) * 0.95F + 0.0499992371F * (real32_T)
    Stand_Balance_B.current1[3]) * 0.95F + 0.0499992371F * (real32_T)
    Stand_Balance_B.current1[4];

  /* Sum: '<S5>/Add4' incorporates:
   *  Delay: '<S5>/Delay One Step'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain3'
   *  Gain: '<S5>/Gain4'
   *  Gain: '<S5>/Gain5'
   *  Gain: '<S5>/Gain6'
   *  Gain: '<S5>/Gain7'
   *  Gain: '<S5>/Gain8'
   *  Gain: '<S5>/Gain9'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   *  Sum: '<S5>/Add2'
   *  Sum: '<S5>/Add3'
   */
  Stand_Balance_DW.DelayOneStep_DSTATE_p = ((((0.95F *
    Stand_Balance_DW.DelayOneStep_DSTATE_p + 0.0499992371F * (real32_T)
    Stand_Balance_B.current2[0]) * 0.95F + 0.0499992371F * (real32_T)
    Stand_Balance_B.current2[1]) * 0.95F + 0.0499992371F * (real32_T)
    Stand_Balance_B.current2[2]) * 0.95F + 0.0499992371F * (real32_T)
    Stand_Balance_B.current2[3]) * 0.95F + 0.0499992371F * (real32_T)
    Stand_Balance_B.current2[4];

  /* S-Function (StackLiteDualDrive_DataLinkOutput): '<Root>/DataLinkOutput' */
  /*Output Data*/
  DataLink_UpFrameData.data[0].point= Stand_Balance_B.ManualSwitch;
  DataLink_UpFrameData.data[1].point= Stand_Balance_B.DataStoreRead4;
  DataLink_UpFrameData.data[2].point= Stand_Balance_B.DataStoreRead5;
  DataLink_UpFrameData.data[3].point= Stand_Balance_B.DataTypeConversion3;
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
  motor1_PwmData= Stand_Balance_B.Saturation;
  motor2_PwmData= Stand_Balance_B.Saturation1;
  HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,(GPIO_PinState)((uint8_T)0U));
  memcpy(ws2812_data,((const uint8_T*) &Stand_Balance_U8GND),3);

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_Compare = (Stand_Balance_DW.Output_DSTATE == 1);

  /* Switch: '<S10>/FixPt Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S9>/FixPt Constant'
   *  Sum: '<S9>/FixPt Sum1'
   *  UnitDelay: '<S2>/Output'
   */
  if ((uint8_T)(Stand_Balance_DW.Output_DSTATE + 1) > 1) {
    Stand_Balance_DW.Output_DSTATE = 0U;
  } else {
    Stand_Balance_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S10>/FixPt Switch' */

  /* DataStoreRead: '<Root>/Data Store Read4' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S4>/Delay One Step'
   */
  Stand_Balance_B.DataStoreRead4 = Stand_Balance_DW.DelayOneStep_DSTATE;

  /* DataStoreRead: '<Root>/Data Store Read5' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S5>/Delay One Step'
   */
  Stand_Balance_B.DataStoreRead5 = Stand_Balance_DW.DelayOneStep_DSTATE_p;

  /* Abs: '<Root>/Abs' */
  if (Stand_Balance_B.angle[1] < 0) {
    tmp = (int16_T)-Stand_Balance_B.angle[1];
  } else {
    tmp = Stand_Balance_B.angle[1];
  }

  /* End of Abs: '<Root>/Abs' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  if (tmp > 3500) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = 20972.0 * (real_T)Stand_Balance_B.angle[1] *
      4.76837158203125E-7;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  Stand_Balance_B.DataTypeConversion3 = (real32_T)rtb_Switch;

  /* Outputs for Enabled SubSystem: '<Root>/anglePID' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtb_Compare) {
    /* Sum: '<S3>/Add' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S12>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read1'
     *  Gain: '<Root>/Gain1'
     *  Product: '<S11>/Product2'
     *  Product: '<S12>/Product'
     *  Sum: '<Root>/Add'
     *  Sum: '<S3>/Add1'
     */
    Stand_Balance_B.Add = 26214.0 * (real_T)Stand_Balance_B.anglev[0] *
      3.814697265625E-6 * 0.1 + (Stand_Balance_DW.machine_mid - rtb_Switch) *
      70.0;
  }

  /* End of Outputs for SubSystem: '<Root>/anglePID' */

  /* Saturate: '<Root>/Saturation3' */
  if (Stand_Balance_B.Add > 2048.0) {
    rtb_Switch = 2048.0;
  } else if (Stand_Balance_B.Add < -2048.0) {
    rtb_Switch = -2048.0;
  } else {
    rtb_Switch = Stand_Balance_B.Add;
  }

  rtb_Switch = floor(rtb_Switch);
  if (rtIsNaN(rtb_Switch)) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = fmod(rtb_Switch, 65536.0);
  }

  /* Switch: '<S8>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation3'
   */
  Stand_Balance_B.Saturation1 = (int16_T)(rtb_Switch < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Switch : (int32_T)(int16_T)(uint16_T)rtb_Switch);

  /* RateLimiter: '<Root>/Rate Limiter1' */
  tmp_0 = Stand_Balance_B.Saturation1 - Stand_Balance_DW.PrevY;
  if (tmp_0 > 5) {
    /* Switch: '<S8>/Switch1' */
    Stand_Balance_B.Saturation1 = (int16_T)(Stand_Balance_DW.PrevY + 5);
  } else if (tmp_0 < -5) {
    /* Switch: '<S8>/Switch1' */
    Stand_Balance_B.Saturation1 = (int16_T)(Stand_Balance_DW.PrevY + -5);
  }

  Stand_Balance_DW.PrevY = Stand_Balance_B.Saturation1;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* ManualSwitch: '<Root>/Manual Switch' */
  Stand_Balance_B.ManualSwitch = Stand_Balance_B.Saturation1;

  /* Sum: '<S13>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S4>/Delay One Step'
   */
  rtb_Add1_k = Stand_Balance_B.ManualSwitch -
    Stand_Balance_DW.DelayOneStep_DSTATE;

  /* Sum: '<S16>/Add2' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Delay: '<S16>/Delay'
   *  Gain: '<S16>/Gain'
   *  Product: '<S16>/Product3'
   */
  Stand_Balance_DW.Delay_DSTATE += (real32_T)(0.03 * rtb_Add1_k);

  /* Saturate: '<S16>/Saturation' */
  if (Stand_Balance_DW.Delay_DSTATE > 2000.0) {
    /* Sum: '<S16>/Add2' */
    Stand_Balance_DW.Delay_DSTATE = 2000.0;
  } else if (Stand_Balance_DW.Delay_DSTATE < -2000.0) {
    /* Sum: '<S16>/Add2' */
    Stand_Balance_DW.Delay_DSTATE = -2000.0;
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S17>/Constant'
   *  Delay: '<S16>/Delay'
   *  Product: '<S15>/Product2'
   *  Product: '<S17>/Product'
   *  Sum: '<S18>/Diff'
   *  UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch = (7.0 * rtb_Add1_k + Stand_Balance_DW.Delay_DSTATE) + (rtb_Add1_k
    - Stand_Balance_DW.UD_DSTATE) * 5.0;

  /* Switch: '<S7>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S4>/Delay One Step'
   *  Switch: '<S7>/Switch3'
   */
  if (Stand_Balance_DW.DelayOneStep_DSTATE > -30.0F) {
    /* Switch: '<S7>/Switch' */
    if (Stand_Balance_DW.DelayOneStep_DSTATE > 30.0F) {
      /* Switch: '<S7>/Switch2' */
      if (rtb_Switch > 0.0) {
        rtb_Switch = floor(rtb_Switch);
        if (rtIsInf(rtb_Switch)) {
          /* Switch: '<S8>/Switch1' */
          Stand_Balance_B.Saturation1 = 0;
        } else {
          /* Switch: '<S8>/Switch1' */
          Stand_Balance_B.Saturation1 = (int16_T)(int32_T)fmod(rtb_Switch,
            65536.0);
        }
      } else {
        /* Switch: '<S8>/Switch1' incorporates:
         *  Constant: '<S7>/Constant'
         */
        Stand_Balance_B.Saturation1 = 10;
      }

      /* End of Switch: '<S7>/Switch2' */
    } else {
      rtb_Switch = floor(rtb_Switch);
      if (rtIsNaN(rtb_Switch) || rtIsInf(rtb_Switch)) {
        rtb_Switch = 0.0;
      } else {
        rtb_Switch = fmod(rtb_Switch, 65536.0);
      }

      /* Switch: '<S8>/Switch1' */
      Stand_Balance_B.Saturation1 = (int16_T)(rtb_Switch < 0.0 ? (int32_T)
        (int16_T)-(int16_T)(uint16_T)-rtb_Switch : (int32_T)(int16_T)(uint16_T)
        rtb_Switch);
    }

    /* End of Switch: '<S7>/Switch' */
  } else if (rtb_Switch > 0.0) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Switch: '<S7>/Switch3'
     */
    Stand_Balance_B.Saturation1 = -10;
  } else {
    /* Switch: '<S7>/Switch3' */
    rtb_Switch = floor(rtb_Switch);
    if (rtIsNaN(rtb_Switch) || rtIsInf(rtb_Switch)) {
      rtb_Switch = 0.0;
    } else {
      rtb_Switch = fmod(rtb_Switch, 65536.0);
    }

    /* Switch: '<S8>/Switch1' incorporates:
     *  Switch: '<S7>/Switch3'
     */
    Stand_Balance_B.Saturation1 = (int16_T)(rtb_Switch < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Switch : (int32_T)(int16_T)(uint16_T)rtb_Switch);
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Saturate: '<Root>/Saturation' */
  if (Stand_Balance_B.Saturation1 > 4200) {
    /* Saturate: '<Root>/Saturation' */
    Stand_Balance_B.Saturation = 4200;
  } else if (Stand_Balance_B.Saturation1 < -4200) {
    /* Saturate: '<Root>/Saturation' */
    Stand_Balance_B.Saturation = -4200;
  } else {
    /* Saturate: '<Root>/Saturation' */
    Stand_Balance_B.Saturation = Stand_Balance_B.Saturation1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<S14>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S5>/Delay One Step'
   */
  rtb_Add1_a = Stand_Balance_B.ManualSwitch -
    Stand_Balance_DW.DelayOneStep_DSTATE_p;

  /* Sum: '<S20>/Add2' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Delay: '<S20>/Delay'
   *  Gain: '<S20>/Gain'
   *  Product: '<S20>/Product3'
   */
  Stand_Balance_DW.Delay_DSTATE_i += (real32_T)(0.03 * rtb_Add1_a);

  /* Saturate: '<S20>/Saturation' */
  if (Stand_Balance_DW.Delay_DSTATE_i > 2000.0) {
    /* Sum: '<S20>/Add2' */
    Stand_Balance_DW.Delay_DSTATE_i = 2000.0;
  } else if (Stand_Balance_DW.Delay_DSTATE_i < -2000.0) {
    /* Sum: '<S20>/Add2' */
    Stand_Balance_DW.Delay_DSTATE_i = -2000.0;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* Sum: '<S14>/Add' incorporates:
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S21>/Constant'
   *  Delay: '<S20>/Delay'
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
  rtb_Switch = (7.0 * rtb_Add1_a + Stand_Balance_DW.Delay_DSTATE_i) +
    (rtb_Add1_a - Stand_Balance_DW.UD_DSTATE_c) * 4.0;

  /* Switch: '<S8>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S5>/Delay One Step'
   *  Switch: '<S8>/Switch3'
   */
  if (Stand_Balance_DW.DelayOneStep_DSTATE_p > -30.0F) {
    /* Switch: '<S8>/Switch' */
    if (Stand_Balance_DW.DelayOneStep_DSTATE_p > 30.0F) {
      /* Switch: '<S8>/Switch2' */
      if (rtb_Switch > 0.0) {
        rtb_Switch = floor(rtb_Switch);
        if (rtIsInf(rtb_Switch)) {
          /* Switch: '<S8>/Switch1' */
          Stand_Balance_B.Saturation1 = 0;
        } else {
          /* Switch: '<S8>/Switch1' */
          Stand_Balance_B.Saturation1 = (int16_T)(int32_T)fmod(rtb_Switch,
            65536.0);
        }
      } else {
        /* Switch: '<S8>/Switch1' incorporates:
         *  Constant: '<S8>/Constant'
         */
        Stand_Balance_B.Saturation1 = 10;
      }

      /* End of Switch: '<S8>/Switch2' */
    } else {
      rtb_Switch = floor(rtb_Switch);
      if (rtIsNaN(rtb_Switch) || rtIsInf(rtb_Switch)) {
        rtb_Switch = 0.0;
      } else {
        rtb_Switch = fmod(rtb_Switch, 65536.0);
      }

      /* Switch: '<S8>/Switch1' */
      Stand_Balance_B.Saturation1 = (int16_T)(rtb_Switch < 0.0 ? (int32_T)
        (int16_T)-(int16_T)(uint16_T)-rtb_Switch : (int32_T)(int16_T)(uint16_T)
        rtb_Switch);
    }

    /* End of Switch: '<S8>/Switch' */
  } else if (rtb_Switch > 0.0) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Switch: '<S8>/Switch3'
     */
    Stand_Balance_B.Saturation1 = -10;
  } else {
    /* Switch: '<S8>/Switch3' */
    rtb_Switch = floor(rtb_Switch);
    if (rtIsNaN(rtb_Switch) || rtIsInf(rtb_Switch)) {
      rtb_Switch = 0.0;
    } else {
      rtb_Switch = fmod(rtb_Switch, 65536.0);
    }

    /* Switch: '<S8>/Switch1' incorporates:
     *  Switch: '<S8>/Switch3'
     */
    Stand_Balance_B.Saturation1 = (int16_T)(rtb_Switch < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Switch : (int32_T)(int16_T)(uint16_T)rtb_Switch);
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Saturate: '<Root>/Saturation1' */
  if (Stand_Balance_B.Saturation1 > 4200) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Stand_Balance_B.Saturation1 = 4200;
  } else if (Stand_Balance_B.Saturation1 < -4200) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Stand_Balance_B.Saturation1 = -4200;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* S-Function (StackLiteDualDrive_DataLinkInput): '<Root>/DataLinkInput' */

  /*Input Data*/
  Stand_Balance_B.DataLinkInput_o1= DataLink_RevData[0].point;
  Stand_Balance_B.DataLinkInput_o2= DataLink_RevData[1].point;
  Stand_Balance_B.DataLinkInput_o3= DataLink_RevData[2].point;
  Stand_Balance_B.DataLinkInput_o4= DataLink_RevData[3].point;
  Stand_Balance_B.DataLinkInput_o5= DataLink_RevData[4].point;
  Stand_Balance_B.DataLinkInput_o6= DataLink_RevData[5].point;
  Stand_Balance_B.DataLinkInput_o7= DataLink_RevData[6].point;
  Stand_Balance_B.DataLinkInput_o8= DataLink_RevData[7].point;
  Stand_Balance_B.DataLinkInput_o9= DataLink_RevData[8].point;
  Stand_Balance_B.DataLinkInput_o10= DataLink_RevData[9].point;

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  Stand_Balance_DW.machine_mid = Stand_Balance_B.DataLinkInput_o1;

  /* DataStoreWrite: '<Root>/Data Store Write2' */
  Stand_Balance_DW.tar_current = Stand_Balance_B.DataLinkInput_o2;

  /* Update for UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  Stand_Balance_DW.UD_DSTATE = rtb_Add1_k;

  /* Update for UnitDelay: '<S22>/UD'
   *
   * Block description for '<S22>/UD':
   *
   *  Store in Global RAM
   */
  Stand_Balance_DW.UD_DSTATE_c = rtb_Add1_a;
}

/* Model initialize function */
void Stand_Balance_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void Stand_Balance_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
