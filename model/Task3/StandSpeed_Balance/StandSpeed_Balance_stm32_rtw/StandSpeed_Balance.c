/*
 * File: StandSpeed_Balance.c
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

#include "ifr-scope_device.h"
#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "stdio.h"
#include <string.h>
#include "StandSpeed_Balance.h"
#include "StandSpeed_Balance_private.h"

const uint8_T StandSpeed_Balance_U8GND = 0U;/* uint8_T ground */

/* Block signals (default storage) */
B_StandSpeed_Balance_T StandSpeed_Balance_B;

/* Block states (default storage) */
DW_StandSpeed_Balance_T StandSpeed_Balance_DW;

/* Real-time model */
static RT_MODEL_StandSpeed_Balance_T StandSpeed_Balance_M_;
RT_MODEL_StandSpeed_Balance_T *const StandSpeed_Balance_M =
  &StandSpeed_Balance_M_;
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
void StandSpeed_Balance_step(void)
{
  real_T rtb_Add;
  real_T rtb_Switch;
  int_T idxDelay;
  real32_T rtb_Add1_l;
  real32_T rtb_Add1_p;
  int16_T tmp;
  boolean_T rtb_Compare_g;

  /* S-Function (StackLiteDualDrive_Input): '<Root>/Input' */
  /*Input Data*/
  memcpy(&StandSpeed_Balance_B.angle[0],HI226_Angle,3*2);
  memcpy(&StandSpeed_Balance_B.anglev[0],HI226_AngleV,3*2);
  StandSpeed_Balance_B.encoder1= (int32_t)(__HAL_TIM_GetCounter(&htim5));
  StandSpeed_Balance_B.encoder2= -(int32_t)(__HAL_TIM_GetCounter(&htim2));
  memcpy(&StandSpeed_Balance_B.current1[0],adc_rawvalue[0],5*2);
  memcpy(&StandSpeed_Balance_B.current2[0],adc_rawvalue[1],5*2);

  /* Sum: '<S8>/Add4' incorporates:
   *  Delay: '<S8>/Delay One Step'
   *  Gain: '<S8>/Gain'
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain2'
   *  Gain: '<S8>/Gain3'
   *  Gain: '<S8>/Gain4'
   *  Gain: '<S8>/Gain5'
   *  Gain: '<S8>/Gain6'
   *  Gain: '<S8>/Gain7'
   *  Gain: '<S8>/Gain8'
   *  Gain: '<S8>/Gain9'
   *  Sum: '<S8>/Add'
   *  Sum: '<S8>/Add1'
   *  Sum: '<S8>/Add2'
   *  Sum: '<S8>/Add3'
   */
  StandSpeed_Balance_DW.DelayOneStep_DSTATE = ((((0.95F *
    StandSpeed_Balance_DW.DelayOneStep_DSTATE + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current1[0]) * 0.95F + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current1[1]) * 0.95F + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current1[2]) * 0.95F + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current1[3]) * 0.95F + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current1[4];

  /* Sum: '<S9>/Add4' incorporates:
   *  Delay: '<S9>/Delay One Step'
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   *  Gain: '<S9>/Gain2'
   *  Gain: '<S9>/Gain3'
   *  Gain: '<S9>/Gain4'
   *  Gain: '<S9>/Gain5'
   *  Gain: '<S9>/Gain6'
   *  Gain: '<S9>/Gain7'
   *  Gain: '<S9>/Gain8'
   *  Gain: '<S9>/Gain9'
   *  Sum: '<S9>/Add'
   *  Sum: '<S9>/Add1'
   *  Sum: '<S9>/Add2'
   *  Sum: '<S9>/Add3'
   */
  StandSpeed_Balance_DW.DelayOneStep_DSTATE_b = ((((0.95F *
    StandSpeed_Balance_DW.DelayOneStep_DSTATE_b + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current2[0]) * 0.95F + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current2[1]) * 0.95F + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current2[2]) * 0.95F + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current2[3]) * 0.95F + 0.0499992371F * (real32_T)
    StandSpeed_Balance_B.current2[4];

  /* S-Function (StackLiteDualDrive_DataLinkOutput): '<Root>/DataLinkOutput' */
  /*Output Data*/
  DataLink_UpFrameData.data[0].point= StandSpeed_Balance_B.DataStoreRead4;
  DataLink_UpFrameData.data[1].point= StandSpeed_Balance_B.Divide;
  DataLink_UpFrameData.data[2].point= StandSpeed_Balance_B.Divide1;
  DataLink_UpFrameData.data[3].point= StandSpeed_Balance_B.DataTypeConversion;
  DataLink_UpFrameData.data[4].point= StandSpeed_Balance_B.DataTypeConversion1;
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
  motor1_PwmData= StandSpeed_Balance_B.Saturation;
  motor2_PwmData= StandSpeed_Balance_B.Saturation1;
  HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,(GPIO_PinState)((uint8_T)0U));
  memcpy(ws2812_data,((const uint8_T*) &StandSpeed_Balance_U8GND),3);

  /* DataStoreRead: '<Root>/Data Store Read4' */
  StandSpeed_Balance_B.DataStoreRead4 = StandSpeed_Balance_DW.tar_speed;

  /* Outputs for Enabled SubSystem: '<Root>/encoder to rpm' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  UnitDelay: '<S5>/Output'
   */
  if (StandSpeed_Balance_DW.Output_DSTATE == 1) {
    /* Product: '<S11>/Divide' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/Constant2'
     *  Delay: '<S11>/Delay'
     *  Product: '<S11>/Product'
     *  Product: '<S11>/Product1'
     *  Sum: '<S11>/Add1'
     */
    StandSpeed_Balance_B.Divide = (real32_T)(StandSpeed_Balance_B.encoder1 -
      StandSpeed_Balance_DW.Delay_DSTATE_e[0]) * 100.0F * 60.0F / 40000.0F;

    /* Product: '<S11>/Divide1' incorporates:
     *  Constant: '<S11>/Constant3'
     *  Constant: '<S11>/Constant4'
     *  Constant: '<S11>/Constant5'
     *  Delay: '<S11>/Delay1'
     *  Product: '<S11>/Product2'
     *  Product: '<S11>/Product3'
     *  Sum: '<S11>/Add2'
     */
    StandSpeed_Balance_B.Divide1 = (real32_T)(StandSpeed_Balance_B.encoder2 -
      StandSpeed_Balance_DW.Delay1_DSTATE[0]) * 100.0F * 60.0F / 40000.0F;
    for (idxDelay = 0; idxDelay < 18; idxDelay++) {
      /* Update for Delay: '<S11>/Delay' */
      StandSpeed_Balance_DW.Delay_DSTATE_e[idxDelay] =
        StandSpeed_Balance_DW.Delay_DSTATE_e[idxDelay + 1];

      /* Update for Delay: '<S11>/Delay1' */
      StandSpeed_Balance_DW.Delay1_DSTATE[idxDelay] =
        StandSpeed_Balance_DW.Delay1_DSTATE[idxDelay + 1];
    }

    /* Update for Delay: '<S11>/Delay' */
    StandSpeed_Balance_DW.Delay_DSTATE_e[18] = StandSpeed_Balance_B.encoder1;

    /* Update for Delay: '<S11>/Delay1' */
    StandSpeed_Balance_DW.Delay1_DSTATE[18] = StandSpeed_Balance_B.encoder2;
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/encoder to rpm' */

  /* Outputs for Enabled SubSystem: '<Root>/speedPID_motor' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<S6>/Output'
   */
  if (StandSpeed_Balance_DW.Output_DSTATE_a == 1) {
    /* Sum: '<S33>/Add1' */
    rtb_Add1_p = StandSpeed_Balance_B.DataStoreRead4 -
      StandSpeed_Balance_B.Divide;

    /* Gain: '<S36>/Gain' incorporates:
     *  DataStoreRead: '<S36>/Data Store Read1'
     *  Gain: '<S40>/Gain'
     *  ManualSwitch: '<S36>/Manual Switch1'
     */
    rtb_Add = 0.01 * StandSpeed_Balance_DW.Ki_speed;

    /* Gain: '<S36>/Gain1' incorporates:
     *  Delay: '<S36>/Delay'
     *  Gain: '<S36>/Gain'
     *  Product: '<S36>/Product3'
     *  Sum: '<S36>/Add2'
     */
    StandSpeed_Balance_DW.Delay_DSTATE_b = ((real32_T)(rtb_Add * rtb_Add1_p) +
      StandSpeed_Balance_DW.Delay_DSTATE_b) * 0.995;

    /* Saturate: '<S36>/Saturation2' */
    if (StandSpeed_Balance_DW.Delay_DSTATE_b > 1500.0) {
      /* Gain: '<S36>/Gain1' */
      StandSpeed_Balance_DW.Delay_DSTATE_b = 1500.0;
    } else if (StandSpeed_Balance_DW.Delay_DSTATE_b < -1500.0) {
      /* Gain: '<S36>/Gain1' */
      StandSpeed_Balance_DW.Delay_DSTATE_b = -1500.0;
    }

    /* End of Saturate: '<S36>/Saturation2' */

    /* Sum: '<S34>/Add1' */
    rtb_Add1_l = StandSpeed_Balance_B.DataStoreRead4 -
      StandSpeed_Balance_B.Divide1;

    /* Gain: '<S40>/Gain1' incorporates:
     *  Delay: '<S40>/Delay'
     *  Product: '<S40>/Product3'
     *  Sum: '<S40>/Add2'
     */
    StandSpeed_Balance_DW.Delay_DSTATE_c = ((real32_T)(rtb_Add * rtb_Add1_l) +
      StandSpeed_Balance_DW.Delay_DSTATE_c) * 0.995;

    /* Saturate: '<S40>/Saturation2' */
    if (StandSpeed_Balance_DW.Delay_DSTATE_c > 1500.0) {
      /* Gain: '<S40>/Gain1' */
      StandSpeed_Balance_DW.Delay_DSTATE_c = 1500.0;
    } else if (StandSpeed_Balance_DW.Delay_DSTATE_c < -1500.0) {
      /* Gain: '<S40>/Gain1' */
      StandSpeed_Balance_DW.Delay_DSTATE_c = -1500.0;
    }

    /* End of Saturate: '<S40>/Saturation2' */

    /* Sum: '<S12>/Add' incorporates:
     *  DataStoreRead: '<S35>/Data Store Read2'
     *  DataStoreRead: '<S37>/Data Store Read'
     *  DataStoreRead: '<S39>/Data Store Read2'
     *  DataStoreRead: '<S41>/Data Store Read'
     *  Delay: '<S36>/Delay'
     *  Delay: '<S40>/Delay'
     *  ManualSwitch: '<S35>/Manual Switch2'
     *  ManualSwitch: '<S37>/Manual Switch'
     *  ManualSwitch: '<S39>/Manual Switch2'
     *  ManualSwitch: '<S41>/Manual Switch'
     *  Product: '<S35>/Product2'
     *  Product: '<S37>/Product'
     *  Product: '<S39>/Product2'
     *  Product: '<S41>/Product'
     *  Sum: '<S33>/Add'
     *  Sum: '<S34>/Add'
     *  Sum: '<S38>/Diff'
     *  Sum: '<S42>/Diff'
     *  UnitDelay: '<S38>/UD'
     *  UnitDelay: '<S42>/UD'
     *
     * Block description for '<S38>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S42>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S38>/UD':
     *
     *  Store in Global RAM
     *
     * Block description for '<S42>/UD':
     *
     *  Store in Global RAM
     */
    StandSpeed_Balance_B.Add = (((real_T)StandSpeed_Balance_DW.Kp_speed *
      rtb_Add1_p + StandSpeed_Balance_DW.Delay_DSTATE_b) + (real_T)(rtb_Add1_p -
      StandSpeed_Balance_DW.UD_DSTATE_e) * StandSpeed_Balance_DW.Kd_speed) +
      (((real_T)StandSpeed_Balance_DW.Kp_speed * rtb_Add1_l +
        StandSpeed_Balance_DW.Delay_DSTATE_c) + (real_T)(rtb_Add1_l -
        StandSpeed_Balance_DW.UD_DSTATE_m) * StandSpeed_Balance_DW.Kd_speed);

    /* Update for UnitDelay: '<S38>/UD'
     *
     * Block description for '<S38>/UD':
     *
     *  Store in Global RAM
     */
    StandSpeed_Balance_DW.UD_DSTATE_e = rtb_Add1_p;

    /* Update for UnitDelay: '<S42>/UD'
     *
     * Block description for '<S42>/UD':
     *
     *  Store in Global RAM
     */
    StandSpeed_Balance_DW.UD_DSTATE_m = rtb_Add1_l;
  }

  /* End of RelationalOperator: '<S3>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/speedPID_motor' */

  /* Sum: '<Root>/Add' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   */
  rtb_Add = StandSpeed_Balance_B.Add + StandSpeed_Balance_DW.machine_mid;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S4>/Output'
   */
  rtb_Compare_g = (StandSpeed_Balance_DW.Output_DSTATE_l == 1);

  /* Switch: '<S16>/FixPt Switch' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  Constant: '<S16>/Constant'
   *  Sum: '<S15>/FixPt Sum1'
   *  UnitDelay: '<S4>/Output'
   */
  if ((uint8_T)(StandSpeed_Balance_DW.Output_DSTATE_l + 1) > 1) {
    StandSpeed_Balance_DW.Output_DSTATE_l = 0U;
  } else {
    StandSpeed_Balance_DW.Output_DSTATE_l++;
  }

  /* End of Switch: '<S16>/FixPt Switch' */

  /* Switch: '<S18>/FixPt Switch' incorporates:
   *  Constant: '<S17>/FixPt Constant'
   *  Constant: '<S18>/Constant'
   *  Sum: '<S17>/FixPt Sum1'
   *  UnitDelay: '<S5>/Output'
   */
  if ((uint8_T)(StandSpeed_Balance_DW.Output_DSTATE + 1) > 1) {
    StandSpeed_Balance_DW.Output_DSTATE = 0U;
  } else {
    StandSpeed_Balance_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S18>/FixPt Switch' */

  /* Switch: '<S20>/FixPt Switch' incorporates:
   *  Constant: '<S19>/FixPt Constant'
   *  Constant: '<S20>/Constant'
   *  Sum: '<S19>/FixPt Sum1'
   *  UnitDelay: '<S6>/Output'
   */
  if ((uint8_T)(StandSpeed_Balance_DW.Output_DSTATE_a + 1) > 1) {
    StandSpeed_Balance_DW.Output_DSTATE_a = 0U;
  } else {
    StandSpeed_Balance_DW.Output_DSTATE_a++;
  }

  /* End of Switch: '<S20>/FixPt Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  StandSpeed_Balance_B.DataTypeConversion = (real32_T)rtb_Add;

  /* Abs: '<Root>/Abs' */
  if (StandSpeed_Balance_B.angle[1] < 0) {
    tmp = (int16_T)-StandSpeed_Balance_B.angle[1];
  } else {
    tmp = StandSpeed_Balance_B.angle[1];
  }

  /* End of Abs: '<Root>/Abs' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  if (tmp > 3500) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = 20972.0 * (real_T)StandSpeed_Balance_B.angle[1] *
      4.76837158203125E-7;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  StandSpeed_Balance_B.DataTypeConversion1 = (real32_T)rtb_Switch;

  /* Outputs for Enabled SubSystem: '<Root>/anglePID' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtb_Compare_g) {
    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S21>/Constant2'
     *  Constant: '<S22>/Constant'
     *  Gain: '<Root>/Gain1'
     *  Product: '<S21>/Product2'
     *  Product: '<S22>/Product'
     *  Sum: '<S7>/Add1'
     */
    StandSpeed_Balance_B.Add_h = 26214.0 * (real_T)StandSpeed_Balance_B.anglev[0]
      * 3.814697265625E-6 * 0.1 + (rtb_Add - rtb_Switch) * 70.0;
  }

  /* End of Outputs for SubSystem: '<Root>/anglePID' */

  /* Saturate: '<Root>/Saturation3' */
  if (StandSpeed_Balance_B.Add_h > 2048.0) {
    rtb_Add = 2048.0;
  } else if (StandSpeed_Balance_B.Add_h < -2048.0) {
    rtb_Add = -2048.0;
  } else {
    rtb_Add = StandSpeed_Balance_B.Add_h;
  }

  rtb_Add = floor(rtb_Add);
  if (rtIsNaN(rtb_Add)) {
    rtb_Add = 0.0;
  } else {
    rtb_Add = fmod(rtb_Add, 65536.0);
  }

  /* Switch: '<S13>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation3'
   */
  StandSpeed_Balance_B.Saturation = (int16_T)(rtb_Add < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)rtb_Add);

  /* RateLimiter: '<Root>/Rate Limiter1' */
  idxDelay = StandSpeed_Balance_B.Saturation - StandSpeed_Balance_DW.PrevY;
  if (idxDelay > 5) {
    /* Switch: '<S13>/Switch1' */
    StandSpeed_Balance_B.Saturation = (int16_T)(StandSpeed_Balance_DW.PrevY + 5);
  } else if (idxDelay < -5) {
    /* Switch: '<S13>/Switch1' */
    StandSpeed_Balance_B.Saturation = (int16_T)(StandSpeed_Balance_DW.PrevY + -5);
  }

  StandSpeed_Balance_DW.PrevY = StandSpeed_Balance_B.Saturation;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* Saturate: '<Root>/Saturation2' */
  if (StandSpeed_Balance_B.Add_h > 2048.0) {
    rtb_Add = 2048.0;
  } else if (StandSpeed_Balance_B.Add_h < -2048.0) {
    rtb_Add = -2048.0;
  } else {
    rtb_Add = StandSpeed_Balance_B.Add_h;
  }

  rtb_Add = floor(rtb_Add);
  if (rtIsNaN(rtb_Add)) {
    rtb_Add = 0.0;
  } else {
    rtb_Add = fmod(rtb_Add, 65536.0);
  }

  /* Switch: '<S14>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation2'
   */
  StandSpeed_Balance_B.Saturation1 = (int16_T)(rtb_Add < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)rtb_Add);

  /* RateLimiter: '<Root>/Rate Limiter2' */
  idxDelay = StandSpeed_Balance_B.Saturation1 - StandSpeed_Balance_DW.PrevY_h;
  if (idxDelay > 5) {
    /* Switch: '<S14>/Switch1' */
    StandSpeed_Balance_B.Saturation1 = (int16_T)(StandSpeed_Balance_DW.PrevY_h +
      5);
  } else if (idxDelay < -5) {
    /* Switch: '<S14>/Switch1' */
    StandSpeed_Balance_B.Saturation1 = (int16_T)(StandSpeed_Balance_DW.PrevY_h +
      -5);
  }

  StandSpeed_Balance_DW.PrevY_h = StandSpeed_Balance_B.Saturation1;

  /* End of RateLimiter: '<Root>/Rate Limiter2' */

  /* Sum: '<S23>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S8>/Delay One Step'
   */
  rtb_Add1_p = (real32_T)StandSpeed_Balance_B.Saturation -
    StandSpeed_Balance_DW.DelayOneStep_DSTATE;

  /* Sum: '<S26>/Add2' incorporates:
   *  Constant: '<S26>/Constant1'
   *  Delay: '<S26>/Delay'
   *  Gain: '<S26>/Gain'
   *  Product: '<S26>/Product3'
   */
  StandSpeed_Balance_DW.Delay_DSTATE_a += (real32_T)(0.03 * rtb_Add1_p);

  /* Saturate: '<S26>/Saturation' */
  if (StandSpeed_Balance_DW.Delay_DSTATE_a > 2000.0F) {
    /* Sum: '<S26>/Add2' */
    StandSpeed_Balance_DW.Delay_DSTATE_a = 2000.0F;
  } else if (StandSpeed_Balance_DW.Delay_DSTATE_a < -2000.0F) {
    /* Sum: '<S26>/Add2' */
    StandSpeed_Balance_DW.Delay_DSTATE_a = -2000.0F;
  }

  /* End of Saturate: '<S26>/Saturation' */

  /* Sum: '<S23>/Add' incorporates:
   *  Constant: '<S25>/Constant2'
   *  Constant: '<S27>/Constant'
   *  Delay: '<S26>/Delay'
   *  Product: '<S25>/Product2'
   *  Product: '<S27>/Product'
   *  Sum: '<S28>/Diff'
   *  UnitDelay: '<S28>/UD'
   *
   * Block description for '<S28>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add = (7.0 * rtb_Add1_p + StandSpeed_Balance_DW.Delay_DSTATE_a) +
    (rtb_Add1_p - StandSpeed_Balance_DW.UD_DSTATE) * 5.0;

  /* Switch: '<S13>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S8>/Delay One Step'
   *  Switch: '<S13>/Switch3'
   */
  if (StandSpeed_Balance_DW.DelayOneStep_DSTATE > -30.0F) {
    /* Switch: '<S13>/Switch' */
    if (StandSpeed_Balance_DW.DelayOneStep_DSTATE > 30.0F) {
      /* Switch: '<S13>/Switch2' */
      if (rtb_Add > 0.0) {
        rtb_Add = floor(rtb_Add);
        if (rtIsInf(rtb_Add)) {
          /* Switch: '<S13>/Switch1' */
          StandSpeed_Balance_B.Saturation = 0;
        } else {
          /* Switch: '<S13>/Switch1' */
          StandSpeed_Balance_B.Saturation = (int16_T)(int32_T)fmod(rtb_Add,
            65536.0);
        }
      } else {
        /* Switch: '<S13>/Switch1' incorporates:
         *  Constant: '<S13>/Constant'
         */
        StandSpeed_Balance_B.Saturation = 10;
      }

      /* End of Switch: '<S13>/Switch2' */
    } else {
      rtb_Add = floor(rtb_Add);
      if (rtIsNaN(rtb_Add) || rtIsInf(rtb_Add)) {
        rtb_Add = 0.0;
      } else {
        rtb_Add = fmod(rtb_Add, 65536.0);
      }

      /* Switch: '<S13>/Switch1' */
      StandSpeed_Balance_B.Saturation = (int16_T)(rtb_Add < 0.0 ? (int32_T)
        (int16_T)-(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)
        rtb_Add);
    }

    /* End of Switch: '<S13>/Switch' */
  } else if (rtb_Add > 0.0) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Switch: '<S13>/Switch3'
     */
    StandSpeed_Balance_B.Saturation = -10;
  } else {
    /* Switch: '<S13>/Switch3' */
    rtb_Add = floor(rtb_Add);
    if (rtIsNaN(rtb_Add) || rtIsInf(rtb_Add)) {
      rtb_Add = 0.0;
    } else {
      rtb_Add = fmod(rtb_Add, 65536.0);
    }

    /* Switch: '<S13>/Switch1' incorporates:
     *  Switch: '<S13>/Switch3'
     */
    StandSpeed_Balance_B.Saturation = (int16_T)(rtb_Add < 0.0 ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)
      rtb_Add);
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Saturate: '<Root>/Saturation' */
  if (StandSpeed_Balance_B.Saturation > 4200) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    StandSpeed_Balance_B.Saturation = 4200;
  } else if (StandSpeed_Balance_B.Saturation < -4200) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    StandSpeed_Balance_B.Saturation = -4200;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<S24>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S9>/Delay One Step'
   */
  rtb_Add1_l = (real32_T)StandSpeed_Balance_B.Saturation1 -
    StandSpeed_Balance_DW.DelayOneStep_DSTATE_b;

  /* Sum: '<S30>/Add2' incorporates:
   *  Constant: '<S30>/Constant1'
   *  Delay: '<S30>/Delay'
   *  Gain: '<S30>/Gain'
   *  Product: '<S30>/Product3'
   */
  StandSpeed_Balance_DW.Delay_DSTATE += (real32_T)(0.03 * rtb_Add1_l);

  /* Saturate: '<S30>/Saturation' */
  if (StandSpeed_Balance_DW.Delay_DSTATE > 2000.0) {
    /* Sum: '<S30>/Add2' */
    StandSpeed_Balance_DW.Delay_DSTATE = 2000.0;
  } else if (StandSpeed_Balance_DW.Delay_DSTATE < -2000.0) {
    /* Sum: '<S30>/Add2' */
    StandSpeed_Balance_DW.Delay_DSTATE = -2000.0;
  }

  /* End of Saturate: '<S30>/Saturation' */

  /* Sum: '<S24>/Add' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S31>/Constant'
   *  Delay: '<S30>/Delay'
   *  Product: '<S29>/Product2'
   *  Product: '<S31>/Product'
   *  Sum: '<S32>/Diff'
   *  UnitDelay: '<S32>/UD'
   *
   * Block description for '<S32>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S32>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add = (7.0 * rtb_Add1_l + StandSpeed_Balance_DW.Delay_DSTATE) +
    (rtb_Add1_l - StandSpeed_Balance_DW.UD_DSTATE_o) * 4.0;

  /* Switch: '<S14>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S9>/Delay One Step'
   *  Switch: '<S14>/Switch3'
   */
  if (StandSpeed_Balance_DW.DelayOneStep_DSTATE_b > -30.0F) {
    /* Switch: '<S14>/Switch' */
    if (StandSpeed_Balance_DW.DelayOneStep_DSTATE_b > 30.0F) {
      /* Switch: '<S14>/Switch2' */
      if (rtb_Add > 0.0) {
        rtb_Add = floor(rtb_Add);
        if (rtIsInf(rtb_Add)) {
          /* Switch: '<S14>/Switch1' */
          StandSpeed_Balance_B.Saturation1 = 0;
        } else {
          /* Switch: '<S14>/Switch1' */
          StandSpeed_Balance_B.Saturation1 = (int16_T)(int32_T)fmod(rtb_Add,
            65536.0);
        }
      } else {
        /* Switch: '<S14>/Switch1' incorporates:
         *  Constant: '<S14>/Constant'
         */
        StandSpeed_Balance_B.Saturation1 = 10;
      }

      /* End of Switch: '<S14>/Switch2' */
    } else {
      rtb_Add = floor(rtb_Add);
      if (rtIsNaN(rtb_Add) || rtIsInf(rtb_Add)) {
        rtb_Add = 0.0;
      } else {
        rtb_Add = fmod(rtb_Add, 65536.0);
      }

      /* Switch: '<S14>/Switch1' */
      StandSpeed_Balance_B.Saturation1 = (int16_T)(rtb_Add < 0.0 ? (int32_T)
        (int16_T)-(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)
        rtb_Add);
    }

    /* End of Switch: '<S14>/Switch' */
  } else if (rtb_Add > 0.0) {
    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Switch: '<S14>/Switch3'
     */
    StandSpeed_Balance_B.Saturation1 = -10;
  } else {
    /* Switch: '<S14>/Switch3' */
    rtb_Add = floor(rtb_Add);
    if (rtIsNaN(rtb_Add) || rtIsInf(rtb_Add)) {
      rtb_Add = 0.0;
    } else {
      rtb_Add = fmod(rtb_Add, 65536.0);
    }

    /* Switch: '<S14>/Switch1' incorporates:
     *  Switch: '<S14>/Switch3'
     */
    StandSpeed_Balance_B.Saturation1 = (int16_T)(rtb_Add < 0.0 ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-rtb_Add : (int32_T)(int16_T)(uint16_T)
      rtb_Add);
  }

  /* End of Switch: '<S14>/Switch1' */

  /* Saturate: '<Root>/Saturation1' */
  if (StandSpeed_Balance_B.Saturation1 > 4200) {
    /* Switch: '<S14>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    StandSpeed_Balance_B.Saturation1 = 4200;
  } else if (StandSpeed_Balance_B.Saturation1 < -4200) {
    /* Switch: '<S14>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    StandSpeed_Balance_B.Saturation1 = -4200;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* S-Function (StackLiteDualDrive_DataLinkInput): '<Root>/DataLinkInput' */

  /*Input Data*/
  StandSpeed_Balance_B.DataLinkInput_o1= DataLink_RevData[0].point;
  StandSpeed_Balance_B.DataLinkInput_o2= DataLink_RevData[1].point;
  StandSpeed_Balance_B.DataLinkInput_o3= DataLink_RevData[2].point;
  StandSpeed_Balance_B.DataLinkInput_o4= DataLink_RevData[3].point;
  StandSpeed_Balance_B.DataLinkInput_o5= DataLink_RevData[4].point;
  StandSpeed_Balance_B.DataLinkInput_o6= DataLink_RevData[5].point;
  StandSpeed_Balance_B.DataLinkInput_o7= DataLink_RevData[6].point;
  StandSpeed_Balance_B.DataLinkInput_o8= DataLink_RevData[7].point;
  StandSpeed_Balance_B.DataLinkInput_o9= DataLink_RevData[8].point;
  StandSpeed_Balance_B.DataLinkInput_o10= DataLink_RevData[9].point;

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  StandSpeed_Balance_DW.machine_mid = StandSpeed_Balance_B.DataLinkInput_o1;

  /* DataStoreWrite: '<Root>/Data Store Write2' */
  StandSpeed_Balance_DW.tar_speed = StandSpeed_Balance_B.DataLinkInput_o2;

  /* DataStoreWrite: '<Root>/Data Store Write3' */
  StandSpeed_Balance_DW.Kp_speed = StandSpeed_Balance_B.DataLinkInput_o3;

  /* DataStoreWrite: '<Root>/Data Store Write4' */
  StandSpeed_Balance_DW.Ki_speed = StandSpeed_Balance_B.DataLinkInput_o4;

  /* DataStoreWrite: '<Root>/Data Store Write5' */
  StandSpeed_Balance_DW.Kd_speed = StandSpeed_Balance_B.DataLinkInput_o5;

  /* Update for UnitDelay: '<S28>/UD'
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  StandSpeed_Balance_DW.UD_DSTATE = rtb_Add1_p;

  /* Update for UnitDelay: '<S32>/UD'
   *
   * Block description for '<S32>/UD':
   *
   *  Store in Global RAM
   */
  StandSpeed_Balance_DW.UD_DSTATE_o = rtb_Add1_l;
}

/* Model initialize function */
void StandSpeed_Balance_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void StandSpeed_Balance_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
