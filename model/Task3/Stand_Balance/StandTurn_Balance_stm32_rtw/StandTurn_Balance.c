/*
 * File: StandTurn_Balance.c
 *
 * Code generated for Simulink model 'StandTurn_Balance'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Feb 24 15:42:59 2023
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
#include "StandTurn_Balance.h"
#include "StandTurn_Balance_private.h"

const uint8_T StandTurn_Balance_U8GND = 0U;/* uint8_T ground */

/* Block signals (default storage) */
B_StandTurn_Balance_T StandTurn_Balance_B;

/* Block states (default storage) */
DW_StandTurn_Balance_T StandTurn_Balance_DW;

/* Real-time model */
static RT_MODEL_StandTurn_Balance_T StandTurn_Balance_M_;
RT_MODEL_StandTurn_Balance_T *const StandTurn_Balance_M = &StandTurn_Balance_M_;
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
void StandTurn_Balance_step(void)
{
  real_T rtb_Add_a;
  int32_T angle_yaw;
  int32_T rtb_Add1_m;
  real32_T rtb_Add1_js;
  real32_T rtb_Add1_o;

  /* S-Function (StackLiteDualDrive_Input): '<Root>/Input' */
  /*Input Data*/
  memcpy(&StandTurn_Balance_B.angle[0],HI226_Angle,3*2);
  memcpy(&StandTurn_Balance_B.anglev[0],HI226_AngleV,3*2);
  StandTurn_Balance_B.encoder1= (int32_t)(__HAL_TIM_GetCounter(&htim5));
  StandTurn_Balance_B.encoder2= -(int32_t)(__HAL_TIM_GetCounter(&htim2));
  memcpy(&StandTurn_Balance_B.current1[0],adc_rawvalue[0],5*2);
  memcpy(&StandTurn_Balance_B.current2[0],adc_rawvalue[1],5*2);

  /* Sum: '<S13>/Add4' incorporates:
   *  Delay: '<S13>/Delay One Step'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain1'
   *  Gain: '<S13>/Gain2'
   *  Gain: '<S13>/Gain3'
   *  Gain: '<S13>/Gain4'
   *  Gain: '<S13>/Gain5'
   *  Gain: '<S13>/Gain6'
   *  Gain: '<S13>/Gain7'
   *  Gain: '<S13>/Gain8'
   *  Gain: '<S13>/Gain9'
   *  Sum: '<S13>/Add'
   *  Sum: '<S13>/Add1'
   *  Sum: '<S13>/Add2'
   *  Sum: '<S13>/Add3'
   */
  StandTurn_Balance_DW.DelayOneStep_DSTATE = ((((0.95F *
    StandTurn_Balance_DW.DelayOneStep_DSTATE + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current1[0]) * 0.95F + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current1[1]) * 0.95F + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current1[2]) * 0.95F + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current1[3]) * 0.95F + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current1[4];

  /* Sum: '<S14>/Add4' incorporates:
   *  Delay: '<S14>/Delay One Step'
   *  Gain: '<S14>/Gain'
   *  Gain: '<S14>/Gain1'
   *  Gain: '<S14>/Gain2'
   *  Gain: '<S14>/Gain3'
   *  Gain: '<S14>/Gain4'
   *  Gain: '<S14>/Gain5'
   *  Gain: '<S14>/Gain6'
   *  Gain: '<S14>/Gain7'
   *  Gain: '<S14>/Gain8'
   *  Gain: '<S14>/Gain9'
   *  Sum: '<S14>/Add'
   *  Sum: '<S14>/Add1'
   *  Sum: '<S14>/Add2'
   *  Sum: '<S14>/Add3'
   */
  StandTurn_Balance_DW.DelayOneStep_DSTATE_d = ((((0.95F *
    StandTurn_Balance_DW.DelayOneStep_DSTATE_d + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current2[0]) * 0.95F + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current2[1]) * 0.95F + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current2[2]) * 0.95F + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current2[3]) * 0.95F + 0.0499992371F * (real32_T)
    StandTurn_Balance_B.current2[4];

  /* Gain: '<Root>/Gain3' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write8'
   */
  angle_yaw = 26214 * StandTurn_Balance_B.angle[2];

  /* S-Function (StackLiteDualDrive_DataLinkOutput): '<Root>/DataLinkOutput' */
  /*Output Data*/
  DataLink_UpFrameData.data[0].point= StandTurn_Balance_B.DataStoreRead9;
  DataLink_UpFrameData.data[1].point= StandTurn_Balance_B.DataTypeConversion1;
  DataLink_UpFrameData.data[2].point= StandTurn_Balance_B.Divide;
  DataLink_UpFrameData.data[3].point= StandTurn_Balance_B.Divide1;
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
  motor1_PwmData= StandTurn_Balance_B.Saturation;
  motor2_PwmData= StandTurn_Balance_B.Saturation1;
  HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,(GPIO_PinState)((uint8_T)0U));
  memcpy(ws2812_data,((const uint8_T*) &StandTurn_Balance_U8GND),3);

  /* Outputs for Enabled SubSystem: '<Root>/encoder to rpm' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  UnitDelay: '<S8>/Output'
   */
  if (StandTurn_Balance_DW.Output_DSTATE == 1) {
    /* Product: '<S17>/Divide' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/Constant2'
     *  Delay: '<S17>/Delay'
     *  Product: '<S17>/Product'
     *  Product: '<S17>/Product1'
     *  Sum: '<S17>/Add1'
     */
    StandTurn_Balance_B.Divide = (real32_T)(StandTurn_Balance_B.encoder1 -
      StandTurn_Balance_DW.Delay_DSTATE_o[0]) * 100.0F * 60.0F / 40000.0F;

    /* Product: '<S17>/Divide1' incorporates:
     *  Constant: '<S17>/Constant3'
     *  Constant: '<S17>/Constant4'
     *  Constant: '<S17>/Constant5'
     *  Delay: '<S17>/Delay1'
     *  Product: '<S17>/Product2'
     *  Product: '<S17>/Product3'
     *  Sum: '<S17>/Add2'
     */
    StandTurn_Balance_B.Divide1 = (real32_T)(StandTurn_Balance_B.encoder2 -
      StandTurn_Balance_DW.Delay1_DSTATE[0]) * 100.0F * 60.0F / 40000.0F;
    for (rtb_Add1_m = 0; rtb_Add1_m < 18; rtb_Add1_m++) {
      /* Update for Delay: '<S17>/Delay' */
      StandTurn_Balance_DW.Delay_DSTATE_o[rtb_Add1_m] =
        StandTurn_Balance_DW.Delay_DSTATE_o[rtb_Add1_m + 1];

      /* Update for Delay: '<S17>/Delay1' */
      StandTurn_Balance_DW.Delay1_DSTATE[rtb_Add1_m] =
        StandTurn_Balance_DW.Delay1_DSTATE[rtb_Add1_m + 1];
    }

    /* Update for Delay: '<S17>/Delay' */
    StandTurn_Balance_DW.Delay_DSTATE_o[18] = StandTurn_Balance_B.encoder1;

    /* Update for Delay: '<S17>/Delay1' */
    StandTurn_Balance_DW.Delay1_DSTATE[18] = StandTurn_Balance_B.encoder2;
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/encoder to rpm' */

  /* Outputs for Enabled SubSystem: '<Root>/speedPID_motor' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<S9>/Output'
   */
  if (StandTurn_Balance_DW.Output_DSTATE_i == 1) {
    /* Sum: '<S44>/Add1' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read4'
     *  Sum: '<S44>/Add2'
     */
    rtb_Add1_o = StandTurn_Balance_DW.tar_speed - (StandTurn_Balance_B.Divide +
      StandTurn_Balance_B.Divide1);

    /* Gain: '<S46>/Gain1' incorporates:
     *  DataStoreRead: '<S46>/Data Store Read1'
     *  Delay: '<S46>/Delay'
     *  Gain: '<S46>/Gain'
     *  ManualSwitch: '<S46>/Manual Switch1'
     *  Product: '<S46>/Product3'
     *  Sum: '<S46>/Add2'
     */
    StandTurn_Balance_DW.Delay_DSTATE_i = ((real32_T)(0.001 *
      StandTurn_Balance_DW.Ki_speed * rtb_Add1_o) +
      StandTurn_Balance_DW.Delay_DSTATE_i) * 0.995;

    /* Saturate: '<S46>/Saturation2' */
    if (StandTurn_Balance_DW.Delay_DSTATE_i > 1500.0) {
      /* Gain: '<S46>/Gain1' */
      StandTurn_Balance_DW.Delay_DSTATE_i = 1500.0;
    } else if (StandTurn_Balance_DW.Delay_DSTATE_i < -1500.0) {
      /* Gain: '<S46>/Gain1' */
      StandTurn_Balance_DW.Delay_DSTATE_i = -1500.0;
    }

    /* End of Saturate: '<S46>/Saturation2' */

    /* Sum: '<S44>/Add' incorporates:
     *  DataStoreRead: '<S45>/Data Store Read2'
     *  DataStoreRead: '<S47>/Data Store Read'
     *  Delay: '<S46>/Delay'
     *  Gain: '<S45>/Gain'
     *  Gain: '<S47>/Gain'
     *  ManualSwitch: '<S45>/Manual Switch2'
     *  ManualSwitch: '<S47>/Manual Switch'
     *  Product: '<S45>/Product2'
     *  Product: '<S47>/Product'
     *  Sum: '<S48>/Diff'
     *  UnitDelay: '<S48>/UD'
     *
     * Block description for '<S48>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S48>/UD':
     *
     *  Store in Global RAM
     */
    StandTurn_Balance_B.Add = (0.001 * StandTurn_Balance_DW.Kp_speed *
      rtb_Add1_o + StandTurn_Balance_DW.Delay_DSTATE_i) + 0.001 *
      StandTurn_Balance_DW.Kd_speed * (rtb_Add1_o -
      StandTurn_Balance_DW.UD_DSTATE_o);

    /* Update for UnitDelay: '<S48>/UD'
     *
     * Block description for '<S48>/UD':
     *
     *  Store in Global RAM
     */
    StandTurn_Balance_DW.UD_DSTATE_o = rtb_Add1_o;
  }

  /* End of RelationalOperator: '<S3>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/speedPID_motor' */

  /* Sum: '<Root>/Add1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read13'
   *  DataStoreRead: '<Root>/Data Store Read8'
   */
  rtb_Add1_m = angle_yaw - StandTurn_Balance_DW.yaw_begin;

  /* Outputs for Enabled SubSystem: '<Root>/currentPID_motor1' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  UnitDelay: '<S10>/Output'
   */
  if (StandTurn_Balance_DW.Output_DSTATE_a == 1) {
    /* Sum: '<S16>/Add1' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read5'
     *  Sum: '<Root>/Add1'
     */
    rtb_Add1_o = StandTurn_Balance_DW.tar_yaw - (real32_T)rtb_Add1_m *
      3.81469727E-6F;

    /* Sum: '<S42>/Add2' incorporates:
     *  DataStoreRead: '<S42>/Data Store Read1'
     *  Delay: '<S42>/Delay'
     *  Gain: '<S42>/Gain'
     *  ManualSwitch: '<S42>/Manual Switch1'
     *  Product: '<S42>/Product3'
     */
    StandTurn_Balance_DW.Delay_DSTATE_n += (real32_T)(0.01 *
      StandTurn_Balance_DW.Ki_turn * rtb_Add1_o);

    /* Saturate: '<S42>/Saturation' */
    if (StandTurn_Balance_DW.Delay_DSTATE_n > 2000.0) {
      /* Sum: '<S42>/Add2' */
      StandTurn_Balance_DW.Delay_DSTATE_n = 2000.0;
    } else if (StandTurn_Balance_DW.Delay_DSTATE_n < -2000.0) {
      /* Sum: '<S42>/Add2' */
      StandTurn_Balance_DW.Delay_DSTATE_n = -2000.0;
    }

    /* End of Saturate: '<S42>/Saturation' */

    /* Sum: '<S16>/Add' incorporates:
     *  DataStoreRead: '<S41>/Data Store Read2'
     *  DataStoreRead: '<S43>/Data Store Read'
     *  Delay: '<S42>/Delay'
     *  Gain: '<Root>/Gain2'
     *  ManualSwitch: '<S41>/Manual Switch2'
     *  ManualSwitch: '<S43>/Manual Switch'
     *  Product: '<S41>/Product2'
     *  Product: '<S43>/Product'
     */
    StandTurn_Balance_B.Add_p = 26214.0 * (real_T)StandTurn_Balance_B.anglev[2] *
      3.814697265625E-6 * StandTurn_Balance_DW.Kd_turn + ((real_T)
      StandTurn_Balance_DW.Kp_turn * rtb_Add1_o +
      StandTurn_Balance_DW.Delay_DSTATE_n);
  }

  /* End of RelationalOperator: '<S4>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/currentPID_motor1' */

  /* Outputs for Enabled SubSystem: '<Root>/anglePID' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S7>/Output'
   */
  if (StandTurn_Balance_DW.Output_DSTATE_i5 == 1) {
    int16_T tmp;

    /* Abs: '<Root>/Abs' */
    if (StandTurn_Balance_B.angle[1] < 0) {
      tmp = (int16_T)-StandTurn_Balance_B.angle[1];
    } else {
      tmp = StandTurn_Balance_B.angle[1];
    }

    /* End of Abs: '<Root>/Abs' */

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain'
     */
    if (tmp > 3500) {
      rtb_Add_a = 0.0;
    } else {
      rtb_Add_a = 20972.0 * (real_T)StandTurn_Balance_B.angle[1] *
        4.76837158203125E-7;
    }

    /* End of Switch: '<Root>/Switch' */

    /* Sum: '<S12>/Add' incorporates:
     *  Constant: '<S29>/Constant2'
     *  Constant: '<S30>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read1'
     *  Gain: '<Root>/Gain1'
     *  Product: '<S29>/Product2'
     *  Product: '<S30>/Product'
     *  Sum: '<Root>/Add'
     *  Sum: '<S12>/Add1'
     */
    StandTurn_Balance_B.Add_o = ((StandTurn_Balance_B.Add +
      StandTurn_Balance_DW.machine_mid) - rtb_Add_a) * 70.0 + 26214.0 * (real_T)
      StandTurn_Balance_B.anglev[0] * 3.814697265625E-6 * 0.1;
  }

  /* End of RelationalOperator: '<S1>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/anglePID' */

  /* Switch: '<S22>/FixPt Switch' incorporates:
   *  Constant: '<S21>/FixPt Constant'
   *  Constant: '<S22>/Constant'
   *  Sum: '<S21>/FixPt Sum1'
   *  UnitDelay: '<S7>/Output'
   */
  if ((uint8_T)(StandTurn_Balance_DW.Output_DSTATE_i5 + 1) > 1) {
    StandTurn_Balance_DW.Output_DSTATE_i5 = 0U;
  } else {
    StandTurn_Balance_DW.Output_DSTATE_i5++;
  }

  /* End of Switch: '<S22>/FixPt Switch' */

  /* Switch: '<S24>/FixPt Switch' incorporates:
   *  Constant: '<S23>/FixPt Constant'
   *  Constant: '<S24>/Constant'
   *  Sum: '<S23>/FixPt Sum1'
   *  UnitDelay: '<S8>/Output'
   */
  if ((uint8_T)(StandTurn_Balance_DW.Output_DSTATE + 1) > 1) {
    StandTurn_Balance_DW.Output_DSTATE = 0U;
  } else {
    StandTurn_Balance_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S24>/FixPt Switch' */

  /* Switch: '<S26>/FixPt Switch' incorporates:
   *  Constant: '<S25>/FixPt Constant'
   *  Constant: '<S26>/Constant'
   *  Sum: '<S25>/FixPt Sum1'
   *  UnitDelay: '<S9>/Output'
   */
  if ((uint8_T)(StandTurn_Balance_DW.Output_DSTATE_i + 1) > 1) {
    StandTurn_Balance_DW.Output_DSTATE_i = 0U;
  } else {
    StandTurn_Balance_DW.Output_DSTATE_i++;
  }

  /* End of Switch: '<S26>/FixPt Switch' */

  /* Switch: '<S28>/FixPt Switch' incorporates:
   *  Constant: '<S27>/FixPt Constant'
   *  Constant: '<S28>/Constant'
   *  Sum: '<S27>/FixPt Sum1'
   *  UnitDelay: '<S10>/Output'
   */
  if ((uint8_T)(StandTurn_Balance_DW.Output_DSTATE_a + 1) > 1) {
    StandTurn_Balance_DW.Output_DSTATE_a = 0U;
  } else {
    StandTurn_Balance_DW.Output_DSTATE_a++;
  }

  /* End of Switch: '<S28>/FixPt Switch' */

  /* DataStoreRead: '<Root>/Data Store Read9' */
  StandTurn_Balance_B.DataStoreRead9 = StandTurn_Balance_DW.tar_yaw;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Sum: '<Root>/Add1'
   */
  StandTurn_Balance_B.DataTypeConversion1 = (real32_T)rtb_Add1_m *
    3.81469727E-6F;

  /* Sum: '<Root>/Add2' */
  rtb_Add_a = StandTurn_Balance_B.Add_p + StandTurn_Balance_B.Add_o;

  /* Saturate: '<Root>/Saturation3' */
  if (rtb_Add_a > 2048.0) {
    rtb_Add_a = 2048.0;
  } else if (rtb_Add_a < -2048.0) {
    rtb_Add_a = -2048.0;
  }

  rtb_Add_a = floor(rtb_Add_a);
  if (rtIsNaN(rtb_Add_a)) {
    rtb_Add_a = 0.0;
  } else {
    rtb_Add_a = fmod(rtb_Add_a, 65536.0);
  }

  /* Switch: '<S19>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation3'
   */
  StandTurn_Balance_B.Saturation = (int16_T)(rtb_Add_a < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Add_a : (int32_T)(int16_T)(uint16_T)rtb_Add_a);

  /* RateLimiter: '<Root>/Rate Limiter1' */
  if (StandTurn_Balance_B.Saturation - StandTurn_Balance_DW.PrevY > 5) {
    /* Switch: '<S19>/Switch1' */
    StandTurn_Balance_B.Saturation = (int16_T)(StandTurn_Balance_DW.PrevY + 5);
  } else if (StandTurn_Balance_B.Saturation - StandTurn_Balance_DW.PrevY < -5) {
    /* Switch: '<S19>/Switch1' */
    StandTurn_Balance_B.Saturation = (int16_T)(StandTurn_Balance_DW.PrevY + -5);
  }

  StandTurn_Balance_DW.PrevY = StandTurn_Balance_B.Saturation;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* Sum: '<Root>/Add3' */
  rtb_Add_a = StandTurn_Balance_B.Add_o - StandTurn_Balance_B.Add_p;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Add_a > 2048.0) {
    rtb_Add_a = 2048.0;
  } else if (rtb_Add_a < -2048.0) {
    rtb_Add_a = -2048.0;
  }

  rtb_Add_a = floor(rtb_Add_a);
  if (rtIsNaN(rtb_Add_a)) {
    rtb_Add_a = 0.0;
  } else {
    rtb_Add_a = fmod(rtb_Add_a, 65536.0);
  }

  /* Switch: '<S20>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation2'
   */
  StandTurn_Balance_B.Saturation1 = (int16_T)(rtb_Add_a < 0.0 ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-rtb_Add_a : (int32_T)(int16_T)(uint16_T)
    rtb_Add_a);

  /* RateLimiter: '<Root>/Rate Limiter2' */
  rtb_Add1_m = StandTurn_Balance_B.Saturation1 - StandTurn_Balance_DW.PrevY_n;
  if (rtb_Add1_m > 5) {
    /* Switch: '<S20>/Switch1' */
    StandTurn_Balance_B.Saturation1 = (int16_T)(StandTurn_Balance_DW.PrevY_n + 5);
  } else if (rtb_Add1_m < -5) {
    /* Switch: '<S20>/Switch1' */
    StandTurn_Balance_B.Saturation1 = (int16_T)(StandTurn_Balance_DW.PrevY_n +
      -5);
  }

  StandTurn_Balance_DW.PrevY_n = StandTurn_Balance_B.Saturation1;

  /* End of RateLimiter: '<Root>/Rate Limiter2' */

  /* Sum: '<S31>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S13>/Delay One Step'
   */
  rtb_Add1_o = (real32_T)StandTurn_Balance_B.Saturation -
    StandTurn_Balance_DW.DelayOneStep_DSTATE;

  /* Sum: '<S34>/Add2' incorporates:
   *  Constant: '<S34>/Constant1'
   *  Delay: '<S34>/Delay'
   *  Gain: '<S34>/Gain'
   *  Product: '<S34>/Product3'
   */
  StandTurn_Balance_DW.Delay_DSTATE += (real32_T)(0.03 * rtb_Add1_o);

  /* Saturate: '<S34>/Saturation' */
  if (StandTurn_Balance_DW.Delay_DSTATE > 2000.0) {
    /* Sum: '<S34>/Add2' */
    StandTurn_Balance_DW.Delay_DSTATE = 2000.0;
  } else if (StandTurn_Balance_DW.Delay_DSTATE < -2000.0) {
    /* Sum: '<S34>/Add2' */
    StandTurn_Balance_DW.Delay_DSTATE = -2000.0;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Sum: '<S31>/Add' incorporates:
   *  Constant: '<S33>/Constant2'
   *  Constant: '<S35>/Constant'
   *  Delay: '<S34>/Delay'
   *  Product: '<S33>/Product2'
   *  Product: '<S35>/Product'
   *  Sum: '<S36>/Diff'
   *  UnitDelay: '<S36>/UD'
   *
   * Block description for '<S36>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S36>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a = (7.0 * rtb_Add1_o + StandTurn_Balance_DW.Delay_DSTATE) +
    (rtb_Add1_o - StandTurn_Balance_DW.UD_DSTATE) * 5.0;

  /* Switch: '<S19>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S13>/Delay One Step'
   *  Switch: '<S19>/Switch3'
   */
  if (StandTurn_Balance_DW.DelayOneStep_DSTATE > -30.0F) {
    /* Switch: '<S19>/Switch' */
    if (StandTurn_Balance_DW.DelayOneStep_DSTATE > 30.0F) {
      /* Switch: '<S19>/Switch2' */
      if (rtb_Add_a > 0.0) {
        rtb_Add_a = floor(rtb_Add_a);
        if (rtIsInf(rtb_Add_a)) {
          /* Switch: '<S19>/Switch1' */
          StandTurn_Balance_B.Saturation = 0;
        } else {
          /* Switch: '<S19>/Switch1' */
          StandTurn_Balance_B.Saturation = (int16_T)(int32_T)fmod(rtb_Add_a,
            65536.0);
        }
      } else {
        /* Switch: '<S19>/Switch1' incorporates:
         *  Constant: '<S19>/Constant'
         */
        StandTurn_Balance_B.Saturation = 10;
      }

      /* End of Switch: '<S19>/Switch2' */
    } else {
      rtb_Add_a = floor(rtb_Add_a);
      if (rtIsNaN(rtb_Add_a) || rtIsInf(rtb_Add_a)) {
        rtb_Add_a = 0.0;
      } else {
        rtb_Add_a = fmod(rtb_Add_a, 65536.0);
      }

      /* Switch: '<S19>/Switch1' */
      StandTurn_Balance_B.Saturation = (int16_T)(rtb_Add_a < 0.0 ? (int32_T)
        (int16_T)-(int16_T)(uint16_T)-rtb_Add_a : (int32_T)(int16_T)(uint16_T)
        rtb_Add_a);
    }

    /* End of Switch: '<S19>/Switch' */
  } else if (rtb_Add_a > 0.0) {
    /* Switch: '<S19>/Switch1' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Switch: '<S19>/Switch3'
     */
    StandTurn_Balance_B.Saturation = -10;
  } else {
    /* Switch: '<S19>/Switch3' */
    rtb_Add_a = floor(rtb_Add_a);
    if (rtIsNaN(rtb_Add_a) || rtIsInf(rtb_Add_a)) {
      rtb_Add_a = 0.0;
    } else {
      rtb_Add_a = fmod(rtb_Add_a, 65536.0);
    }

    /* Switch: '<S19>/Switch1' incorporates:
     *  Switch: '<S19>/Switch3'
     */
    StandTurn_Balance_B.Saturation = (int16_T)(rtb_Add_a < 0.0 ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-rtb_Add_a : (int32_T)(int16_T)(uint16_T)
      rtb_Add_a);
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Saturate: '<Root>/Saturation' */
  if (StandTurn_Balance_B.Saturation > 4200) {
    /* Switch: '<S19>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    StandTurn_Balance_B.Saturation = 4200;
  } else if (StandTurn_Balance_B.Saturation < -4200) {
    /* Switch: '<S19>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    StandTurn_Balance_B.Saturation = -4200;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<S32>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S14>/Delay One Step'
   */
  rtb_Add1_js = (real32_T)StandTurn_Balance_B.Saturation1 -
    StandTurn_Balance_DW.DelayOneStep_DSTATE_d;

  /* Sum: '<S38>/Add2' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Delay: '<S38>/Delay'
   *  Gain: '<S38>/Gain'
   *  Product: '<S38>/Product3'
   */
  StandTurn_Balance_DW.Delay_DSTATE_g += (real32_T)(0.03 * rtb_Add1_js);

  /* Saturate: '<S38>/Saturation' */
  if (StandTurn_Balance_DW.Delay_DSTATE_g > 2000.0F) {
    /* Sum: '<S38>/Add2' */
    StandTurn_Balance_DW.Delay_DSTATE_g = 2000.0F;
  } else if (StandTurn_Balance_DW.Delay_DSTATE_g < -2000.0F) {
    /* Sum: '<S38>/Add2' */
    StandTurn_Balance_DW.Delay_DSTATE_g = -2000.0F;
  }

  /* End of Saturate: '<S38>/Saturation' */

  /* Sum: '<S32>/Add' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Constant: '<S39>/Constant'
   *  Delay: '<S38>/Delay'
   *  Product: '<S37>/Product2'
   *  Product: '<S39>/Product'
   *  Sum: '<S40>/Diff'
   *  UnitDelay: '<S40>/UD'
   *
   * Block description for '<S40>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S40>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_a = (7.0 * rtb_Add1_js + StandTurn_Balance_DW.Delay_DSTATE_g) +
    (rtb_Add1_js - StandTurn_Balance_DW.UD_DSTATE_k) * 4.0;

  /* Switch: '<S20>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S14>/Delay One Step'
   *  Switch: '<S20>/Switch3'
   */
  if (StandTurn_Balance_DW.DelayOneStep_DSTATE_d > -30.0F) {
    /* Switch: '<S20>/Switch' */
    if (StandTurn_Balance_DW.DelayOneStep_DSTATE_d > 30.0F) {
      /* Switch: '<S20>/Switch2' */
      if (rtb_Add_a > 0.0) {
        rtb_Add_a = floor(rtb_Add_a);
        if (rtIsInf(rtb_Add_a)) {
          /* Switch: '<S20>/Switch1' */
          StandTurn_Balance_B.Saturation1 = 0;
        } else {
          /* Switch: '<S20>/Switch1' */
          StandTurn_Balance_B.Saturation1 = (int16_T)(int32_T)fmod(rtb_Add_a,
            65536.0);
        }
      } else {
        /* Switch: '<S20>/Switch1' incorporates:
         *  Constant: '<S20>/Constant'
         */
        StandTurn_Balance_B.Saturation1 = 10;
      }

      /* End of Switch: '<S20>/Switch2' */
    } else {
      rtb_Add_a = floor(rtb_Add_a);
      if (rtIsNaN(rtb_Add_a) || rtIsInf(rtb_Add_a)) {
        rtb_Add_a = 0.0;
      } else {
        rtb_Add_a = fmod(rtb_Add_a, 65536.0);
      }

      /* Switch: '<S20>/Switch1' */
      StandTurn_Balance_B.Saturation1 = (int16_T)(rtb_Add_a < 0.0 ? (int32_T)
        (int16_T)-(int16_T)(uint16_T)-rtb_Add_a : (int32_T)(int16_T)(uint16_T)
        rtb_Add_a);
    }

    /* End of Switch: '<S20>/Switch' */
  } else if (rtb_Add_a > 0.0) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Constant: '<S20>/Constant1'
     *  Switch: '<S20>/Switch3'
     */
    StandTurn_Balance_B.Saturation1 = -10;
  } else {
    /* Switch: '<S20>/Switch3' */
    rtb_Add_a = floor(rtb_Add_a);
    if (rtIsNaN(rtb_Add_a) || rtIsInf(rtb_Add_a)) {
      rtb_Add_a = 0.0;
    } else {
      rtb_Add_a = fmod(rtb_Add_a, 65536.0);
    }

    /* Switch: '<S20>/Switch1' incorporates:
     *  Switch: '<S20>/Switch3'
     */
    StandTurn_Balance_B.Saturation1 = (int16_T)(rtb_Add_a < 0.0 ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-rtb_Add_a : (int32_T)(int16_T)(uint16_T)
      rtb_Add_a);
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Saturate: '<Root>/Saturation1' */
  if (StandTurn_Balance_B.Saturation1 > 4200) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    StandTurn_Balance_B.Saturation1 = 4200;
  } else if (StandTurn_Balance_B.Saturation1 < -4200) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    StandTurn_Balance_B.Saturation1 = -4200;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* S-Function (StackLiteDualDrive_DataLinkInput): '<Root>/DataLinkInput' */

  /*Input Data*/
  StandTurn_Balance_B.DataLinkInput_o1= DataLink_RevData[0].point;
  StandTurn_Balance_B.DataLinkInput_o2= DataLink_RevData[1].point;
  StandTurn_Balance_B.DataLinkInput_o3= DataLink_RevData[2].point;
  StandTurn_Balance_B.DataLinkInput_o4= DataLink_RevData[3].point;
  StandTurn_Balance_B.DataLinkInput_o5= DataLink_RevData[4].point;
  StandTurn_Balance_B.DataLinkInput_o6= DataLink_RevData[5].point;
  StandTurn_Balance_B.DataLinkInput_o7= DataLink_RevData[6].point;
  StandTurn_Balance_B.DataLinkInput_o8= DataLink_RevData[7].point;
  StandTurn_Balance_B.DataLinkInput_o9= DataLink_RevData[8].point;
  StandTurn_Balance_B.DataLinkInput_o10= DataLink_RevData[9].point;

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  StandTurn_Balance_DW.machine_mid = StandTurn_Balance_B.DataLinkInput_o1;

  /* DataStoreWrite: '<Root>/Data Store Write10' */
  StandTurn_Balance_DW.Ki_speed = StandTurn_Balance_B.DataLinkInput_o6;

  /* DataStoreWrite: '<Root>/Data Store Write11' */
  StandTurn_Balance_DW.Kd_speed = StandTurn_Balance_B.DataLinkInput_o7;

  /* DataStoreWrite: '<Root>/Data Store Write12' */
  StandTurn_Balance_DW.Kp_turn = StandTurn_Balance_B.DataLinkInput_o8;

  /* DataStoreWrite: '<Root>/Data Store Write13' */
  StandTurn_Balance_DW.Ki_turn = StandTurn_Balance_B.DataLinkInput_o9;

  /* DataStoreWrite: '<Root>/Data Store Write14' */
  StandTurn_Balance_DW.Kd_turn = StandTurn_Balance_B.DataLinkInput_o10;

  /* DataStoreWrite: '<Root>/Data Store Write2' */
  StandTurn_Balance_DW.tar_yaw = StandTurn_Balance_B.DataLinkInput_o2;

  /* DataStoreWrite: '<Root>/Data Store Write5' */
  StandTurn_Balance_DW.Kp_speed = StandTurn_Balance_B.DataLinkInput_o5;

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* Logic: '<Root>/AND' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read11'
   *  DataStoreRead: '<Root>/Data Store Read12'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   */
  if ((StandTurn_Balance_DW.flag == 0.0) && (angle_yaw != 0)) {
    /* DataStoreWrite: '<S11>/Data Store Write1' incorporates:
     *  Constant: '<S11>/Constant'
     */
    StandTurn_Balance_DW.flag = 1.0;

    /* DataStoreWrite: '<S11>/Data Store Write' incorporates:
     *  DataStoreRead: '<S11>/Data Store Read'
     */
    StandTurn_Balance_DW.yaw_begin = angle_yaw;
  }

  /* End of Logic: '<Root>/AND' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Update for UnitDelay: '<S36>/UD'
   *
   * Block description for '<S36>/UD':
   *
   *  Store in Global RAM
   */
  StandTurn_Balance_DW.UD_DSTATE = rtb_Add1_o;

  /* Update for UnitDelay: '<S40>/UD'
   *
   * Block description for '<S40>/UD':
   *
   *  Store in Global RAM
   */
  StandTurn_Balance_DW.UD_DSTATE_k = rtb_Add1_js;
}

/* Model initialize function */
void StandTurn_Balance_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void StandTurn_Balance_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
