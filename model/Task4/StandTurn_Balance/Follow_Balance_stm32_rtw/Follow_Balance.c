/*
 * File: Follow_Balance.c
 *
 * Code generated for Simulink model 'Follow_Balance'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Mar 25 12:19:30 2023
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
#include "Follow_Balance.h"
#include "Follow_Balance_private.h"

const uint8_T Follow_Balance_U8GND = 0U;/* uint8_T ground */

/* Block signals (default storage) */
B_Follow_Balance_T Follow_Balance_B;

/* Block states (default storage) */
DW_Follow_Balance_T Follow_Balance_DW;

/* Real-time model */
static RT_MODEL_Follow_Balance_T Follow_Balance_M_;
RT_MODEL_Follow_Balance_T *const Follow_Balance_M = &Follow_Balance_M_;
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
void Follow_Balance_step(void)
{
  real_T rtb_Add_op;
  int32_T angle_yaw;
  int32_T rtb_Add1_c;
  real32_T rtb_Add1_a;
  real32_T rtb_Add1_f;

  /* S-Function (StackLiteDualDrive_Input): '<Root>/Input' */
  /*Input Data*/
  memcpy(&Follow_Balance_B.angle[0],HI226_Angle,3*2);
  memcpy(&Follow_Balance_B.anglev[0],HI226_AngleV,3*2);
  Follow_Balance_B.encoder1= (int32_t)(__HAL_TIM_GetCounter(&htim5));
  Follow_Balance_B.encoder2= -(int32_t)(__HAL_TIM_GetCounter(&htim2));
  memcpy(&Follow_Balance_B.current1[0],adc_rawvalue[0],5*2);
  memcpy(&Follow_Balance_B.current2[0],adc_rawvalue[1],5*2);

  /* Sum: '<S12>/Add4' incorporates:
   *  Delay: '<S12>/Delay One Step'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S12>/Gain1'
   *  Gain: '<S12>/Gain2'
   *  Gain: '<S12>/Gain3'
   *  Gain: '<S12>/Gain4'
   *  Gain: '<S12>/Gain5'
   *  Gain: '<S12>/Gain6'
   *  Gain: '<S12>/Gain7'
   *  Gain: '<S12>/Gain8'
   *  Gain: '<S12>/Gain9'
   *  Sum: '<S12>/Add'
   *  Sum: '<S12>/Add1'
   *  Sum: '<S12>/Add2'
   *  Sum: '<S12>/Add3'
   */
  Follow_Balance_DW.DelayOneStep_DSTATE = ((((0.95F *
    Follow_Balance_DW.DelayOneStep_DSTATE + 0.0499992371F * (real32_T)
    Follow_Balance_B.current1[0]) * 0.95F + 0.0499992371F * (real32_T)
    Follow_Balance_B.current1[1]) * 0.95F + 0.0499992371F * (real32_T)
    Follow_Balance_B.current1[2]) * 0.95F + 0.0499992371F * (real32_T)
    Follow_Balance_B.current1[3]) * 0.95F + 0.0499992371F * (real32_T)
    Follow_Balance_B.current1[4];

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
  Follow_Balance_DW.DelayOneStep_DSTATE_l = ((((0.95F *
    Follow_Balance_DW.DelayOneStep_DSTATE_l + 0.0499992371F * (real32_T)
    Follow_Balance_B.current2[0]) * 0.95F + 0.0499992371F * (real32_T)
    Follow_Balance_B.current2[1]) * 0.95F + 0.0499992371F * (real32_T)
    Follow_Balance_B.current2[2]) * 0.95F + 0.0499992371F * (real32_T)
    Follow_Balance_B.current2[3]) * 0.95F + 0.0499992371F * (real32_T)
    Follow_Balance_B.current2[4];

  /* Gain: '<Root>/Gain3' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write8'
   */
  angle_yaw = 26214 * Follow_Balance_B.angle[2];

  /* S-Function (StackLiteDualDrive_DataLinkOutput): '<Root>/DataLinkOutput' */
  /*Output Data*/
  DataLink_UpFrameData.data[0].point= Follow_Balance_B.DataStoreRead9;
  DataLink_UpFrameData.data[1].point= Follow_Balance_B.DataTypeConversion1;
  DataLink_UpFrameData.data[2].point= 0.0F;
  DataLink_UpFrameData.data[3].point= 0.0F;
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
  motor1_PwmData= Follow_Balance_B.Saturation;
  motor2_PwmData= Follow_Balance_B.Saturation1;
  HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,(GPIO_PinState)((uint8_T)0U));
  memcpy(ws2812_data,((const uint8_T*) &Follow_Balance_U8GND),3);

  /* Outputs for Enabled SubSystem: '<Root>/encoder to rpm' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  UnitDelay: '<S8>/Output'
   */
  if (Follow_Balance_DW.Output_DSTATE == 1) {
    /* Product: '<S15>/Divide' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S15>/Constant2'
     *  Delay: '<S15>/Delay'
     *  Product: '<S15>/Product'
     *  Product: '<S15>/Product1'
     *  Sum: '<S15>/Add1'
     */
    Follow_Balance_B.Divide = (real32_T)(Follow_Balance_B.encoder1 -
      Follow_Balance_DW.Delay_DSTATE_b[0]) * 100.0F * 60.0F / 40000.0F;

    /* Product: '<S15>/Divide1' incorporates:
     *  Constant: '<S15>/Constant3'
     *  Constant: '<S15>/Constant4'
     *  Constant: '<S15>/Constant5'
     *  Delay: '<S15>/Delay1'
     *  Product: '<S15>/Product2'
     *  Product: '<S15>/Product3'
     *  Sum: '<S15>/Add2'
     */
    Follow_Balance_B.Divide1 = (real32_T)(Follow_Balance_B.encoder2 -
      Follow_Balance_DW.Delay1_DSTATE[0]) * 100.0F * 60.0F / 40000.0F;
    for (rtb_Add1_c = 0; rtb_Add1_c < 18; rtb_Add1_c++) {
      /* Update for Delay: '<S15>/Delay' */
      Follow_Balance_DW.Delay_DSTATE_b[rtb_Add1_c] =
        Follow_Balance_DW.Delay_DSTATE_b[rtb_Add1_c + 1];

      /* Update for Delay: '<S15>/Delay1' */
      Follow_Balance_DW.Delay1_DSTATE[rtb_Add1_c] =
        Follow_Balance_DW.Delay1_DSTATE[rtb_Add1_c + 1];
    }

    /* Update for Delay: '<S15>/Delay' */
    Follow_Balance_DW.Delay_DSTATE_b[18] = Follow_Balance_B.encoder1;

    /* Update for Delay: '<S15>/Delay1' */
    Follow_Balance_DW.Delay1_DSTATE[18] = Follow_Balance_B.encoder2;
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/encoder to rpm' */

  /* Outputs for Enabled SubSystem: '<Root>/speedPID_motor' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<S9>/Output'
   */
  if (Follow_Balance_DW.Output_DSTATE_k == 1) {
    /* Sum: '<S41>/Add1' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read4'
     *  Sum: '<S41>/Add2'
     */
    rtb_Add1_f = Follow_Balance_DW.tar_speed - (Follow_Balance_B.Divide +
      Follow_Balance_B.Divide1);

    /* Gain: '<S43>/Gain1' incorporates:
     *  DataStoreRead: '<S43>/Data Store Read1'
     *  Delay: '<S43>/Delay'
     *  Gain: '<S43>/Gain'
     *  Product: '<S43>/Product3'
     *  Sum: '<S43>/Add2'
     */
    Follow_Balance_DW.Delay_DSTATE_h = ((real32_T)(0.001 *
      Follow_Balance_DW.Ki_speed * rtb_Add1_f) +
      Follow_Balance_DW.Delay_DSTATE_h) * 0.995F;

    /* Saturate: '<S43>/Saturation2' */
    if (Follow_Balance_DW.Delay_DSTATE_h > 1500.0F) {
      /* Gain: '<S43>/Gain1' */
      Follow_Balance_DW.Delay_DSTATE_h = 1500.0F;
    } else if (Follow_Balance_DW.Delay_DSTATE_h < -1500.0F) {
      /* Gain: '<S43>/Gain1' */
      Follow_Balance_DW.Delay_DSTATE_h = -1500.0F;
    }

    /* End of Saturate: '<S43>/Saturation2' */

    /* Sum: '<S41>/Add' incorporates:
     *  DataStoreRead: '<S42>/Data Store Read2'
     *  DataStoreRead: '<S44>/Data Store Read'
     *  Delay: '<S43>/Delay'
     *  Gain: '<S42>/Gain'
     *  Gain: '<S44>/Gain'
     *  Product: '<S42>/Product2'
     *  Product: '<S44>/Product'
     *  Sum: '<S45>/Diff'
     *  UnitDelay: '<S45>/UD'
     *
     * Block description for '<S45>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S45>/UD':
     *
     *  Store in Global RAM
     */
    Follow_Balance_B.Add_p = (0.001 * Follow_Balance_DW.Kp_speed * rtb_Add1_f +
      Follow_Balance_DW.Delay_DSTATE_h) + 0.001 * Follow_Balance_DW.Kd_speed *
      (rtb_Add1_f - Follow_Balance_DW.UD_DSTATE_e);

    /* Update for UnitDelay: '<S45>/UD'
     *
     * Block description for '<S45>/UD':
     *
     *  Store in Global RAM
     */
    Follow_Balance_DW.UD_DSTATE_e = rtb_Add1_f;
  }

  /* End of RelationalOperator: '<S3>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/speedPID_motor' */

  /* Sum: '<Root>/Add1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read13'
   *  DataStoreRead: '<Root>/Data Store Read8'
   */
  rtb_Add1_c = angle_yaw - Follow_Balance_DW.yaw_begin;

  /* Outputs for Enabled SubSystem: '<Root>/turnPID' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  UnitDelay: '<S10>/Output'
   */
  if (Follow_Balance_DW.Output_DSTATE_kh == 1) {
    /* Sum: '<S17>/Add1' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read5'
     *  Sum: '<Root>/Add1'
     */
    rtb_Add1_f = Follow_Balance_DW.tar_yaw - (real32_T)rtb_Add1_c *
      3.81469727E-6F;

    /* Sum: '<S47>/Add2' incorporates:
     *  DataStoreRead: '<S47>/Data Store Read1'
     *  Delay: '<S47>/Delay'
     *  Gain: '<S47>/Gain'
     *  ManualSwitch: '<S47>/Manual Switch1'
     *  Product: '<S47>/Product3'
     */
    Follow_Balance_DW.Delay_DSTATE_i += (real32_T)(0.01 *
      Follow_Balance_DW.Ki_turn * rtb_Add1_f);

    /* Saturate: '<S47>/Saturation' */
    if (Follow_Balance_DW.Delay_DSTATE_i > 2000.0) {
      /* Sum: '<S47>/Add2' */
      Follow_Balance_DW.Delay_DSTATE_i = 2000.0;
    } else if (Follow_Balance_DW.Delay_DSTATE_i < -2000.0) {
      /* Sum: '<S47>/Add2' */
      Follow_Balance_DW.Delay_DSTATE_i = -2000.0;
    }

    /* End of Saturate: '<S47>/Saturation' */

    /* Sum: '<S17>/Add' incorporates:
     *  DataStoreRead: '<S46>/Data Store Read2'
     *  DataStoreRead: '<S48>/Data Store Read'
     *  Delay: '<S47>/Delay'
     *  Gain: '<Root>/Gain2'
     *  ManualSwitch: '<S46>/Manual Switch2'
     *  ManualSwitch: '<S48>/Manual Switch'
     *  Product: '<S46>/Product2'
     *  Product: '<S48>/Product'
     */
    Follow_Balance_B.Add = 26214.0 * (real_T)Follow_Balance_B.anglev[2] *
      3.814697265625E-6 * Follow_Balance_DW.Kd_turn + ((real_T)
      Follow_Balance_DW.Kp_turn * rtb_Add1_f + Follow_Balance_DW.Delay_DSTATE_i);
  }

  /* End of RelationalOperator: '<S4>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/turnPID' */

  /* Outputs for Enabled SubSystem: '<Root>/anglePID' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S7>/Output'
   */
  if (Follow_Balance_DW.Output_DSTATE_e == 1) {
    int16_T tmp;

    /* Abs: '<Root>/Abs' */
    if (Follow_Balance_B.angle[1] < 0) {
      tmp = (int16_T)-Follow_Balance_B.angle[1];
    } else {
      tmp = Follow_Balance_B.angle[1];
    }

    /* End of Abs: '<Root>/Abs' */

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain'
     */
    if (tmp > 3500) {
      rtb_Add_op = 0.0;
    } else {
      rtb_Add_op = 20972.0 * (real_T)Follow_Balance_B.angle[1] *
        4.76837158203125E-7;
    }

    /* End of Switch: '<Root>/Switch' */

    /* Sum: '<S11>/Add' incorporates:
     *  Constant: '<S29>/Constant2'
     *  Constant: '<S30>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read1'
     *  Gain: '<Root>/Gain1'
     *  Product: '<S29>/Product2'
     *  Product: '<S30>/Product'
     *  Sum: '<Root>/Add'
     *  Sum: '<S11>/Add1'
     */
    Follow_Balance_B.Add_h = ((Follow_Balance_B.Add_p +
      Follow_Balance_DW.machine_mid) - rtb_Add_op) * 70.0 + 26214.0 * (real_T)
      Follow_Balance_B.anglev[0] * 3.814697265625E-6 * 0.1;
  }

  /* End of RelationalOperator: '<S1>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/anglePID' */

  /* Switch: '<S22>/FixPt Switch' incorporates:
   *  Constant: '<S21>/FixPt Constant'
   *  Constant: '<S22>/Constant'
   *  Sum: '<S21>/FixPt Sum1'
   *  UnitDelay: '<S7>/Output'
   */
  if ((uint8_T)(Follow_Balance_DW.Output_DSTATE_e + 1) > 1) {
    Follow_Balance_DW.Output_DSTATE_e = 0U;
  } else {
    Follow_Balance_DW.Output_DSTATE_e++;
  }

  /* End of Switch: '<S22>/FixPt Switch' */

  /* Switch: '<S24>/FixPt Switch' incorporates:
   *  Constant: '<S23>/FixPt Constant'
   *  Constant: '<S24>/Constant'
   *  Sum: '<S23>/FixPt Sum1'
   *  UnitDelay: '<S8>/Output'
   */
  if ((uint8_T)(Follow_Balance_DW.Output_DSTATE + 1) > 1) {
    Follow_Balance_DW.Output_DSTATE = 0U;
  } else {
    Follow_Balance_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S24>/FixPt Switch' */

  /* Switch: '<S26>/FixPt Switch' incorporates:
   *  Constant: '<S25>/FixPt Constant'
   *  Constant: '<S26>/Constant'
   *  Sum: '<S25>/FixPt Sum1'
   *  UnitDelay: '<S9>/Output'
   */
  if ((uint8_T)(Follow_Balance_DW.Output_DSTATE_k + 1) > 1) {
    Follow_Balance_DW.Output_DSTATE_k = 0U;
  } else {
    Follow_Balance_DW.Output_DSTATE_k++;
  }

  /* End of Switch: '<S26>/FixPt Switch' */

  /* Switch: '<S28>/FixPt Switch' incorporates:
   *  Constant: '<S27>/FixPt Constant'
   *  Constant: '<S28>/Constant'
   *  Sum: '<S27>/FixPt Sum1'
   *  UnitDelay: '<S10>/Output'
   */
  if ((uint8_T)(Follow_Balance_DW.Output_DSTATE_kh + 1) > 1) {
    Follow_Balance_DW.Output_DSTATE_kh = 0U;
  } else {
    Follow_Balance_DW.Output_DSTATE_kh++;
  }

  /* End of Switch: '<S28>/FixPt Switch' */

  /* DataStoreRead: '<Root>/Data Store Read9' */
  Follow_Balance_B.DataStoreRead9 = Follow_Balance_DW.tar_yaw;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Sum: '<Root>/Add1'
   */
  Follow_Balance_B.DataTypeConversion1 = (real32_T)rtb_Add1_c * 3.81469727E-6F;

  /* Sum: '<Root>/Add2' */
  rtb_Add_op = Follow_Balance_B.Add + Follow_Balance_B.Add_h;

  /* Saturate: '<Root>/Saturation3' */
  if (rtb_Add_op > 2048.0) {
    rtb_Add_op = 2048.0;
  } else if (rtb_Add_op < -2048.0) {
    rtb_Add_op = -2048.0;
  }

  rtb_Add_op = floor(rtb_Add_op);
  if (rtIsNaN(rtb_Add_op)) {
    rtb_Add_op = 0.0;
  } else {
    rtb_Add_op = fmod(rtb_Add_op, 65536.0);
  }

  /* Switch: '<S19>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation3'
   */
  Follow_Balance_B.Saturation = (int16_T)(rtb_Add_op < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Add_op : (int32_T)(int16_T)(uint16_T)rtb_Add_op);

  /* RateLimiter: '<Root>/Rate Limiter1' */
  if (Follow_Balance_B.Saturation - Follow_Balance_DW.PrevY > 5) {
    /* Switch: '<S19>/Switch1' */
    Follow_Balance_B.Saturation = (int16_T)(Follow_Balance_DW.PrevY + 5);
  } else if (Follow_Balance_B.Saturation - Follow_Balance_DW.PrevY < -5) {
    /* Switch: '<S19>/Switch1' */
    Follow_Balance_B.Saturation = (int16_T)(Follow_Balance_DW.PrevY + -5);
  }

  Follow_Balance_DW.PrevY = Follow_Balance_B.Saturation;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* Sum: '<Root>/Add3' */
  rtb_Add_op = Follow_Balance_B.Add_h - Follow_Balance_B.Add;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Add_op > 2048.0) {
    rtb_Add_op = 2048.0;
  } else if (rtb_Add_op < -2048.0) {
    rtb_Add_op = -2048.0;
  }

  rtb_Add_op = floor(rtb_Add_op);
  if (rtIsNaN(rtb_Add_op)) {
    rtb_Add_op = 0.0;
  } else {
    rtb_Add_op = fmod(rtb_Add_op, 65536.0);
  }

  /* Switch: '<S20>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation2'
   */
  Follow_Balance_B.Saturation1 = (int16_T)(rtb_Add_op < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-rtb_Add_op : (int32_T)(int16_T)(uint16_T)rtb_Add_op);

  /* RateLimiter: '<Root>/Rate Limiter2' */
  rtb_Add1_c = Follow_Balance_B.Saturation1 - Follow_Balance_DW.PrevY_c;
  if (rtb_Add1_c > 5) {
    /* Switch: '<S20>/Switch1' */
    Follow_Balance_B.Saturation1 = (int16_T)(Follow_Balance_DW.PrevY_c + 5);
  } else if (rtb_Add1_c < -5) {
    /* Switch: '<S20>/Switch1' */
    Follow_Balance_B.Saturation1 = (int16_T)(Follow_Balance_DW.PrevY_c + -5);
  }

  Follow_Balance_DW.PrevY_c = Follow_Balance_B.Saturation1;

  /* End of RateLimiter: '<Root>/Rate Limiter2' */

  /* Sum: '<S31>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S12>/Delay One Step'
   */
  rtb_Add1_f = (real32_T)Follow_Balance_B.Saturation -
    Follow_Balance_DW.DelayOneStep_DSTATE;

  /* Sum: '<S34>/Add2' incorporates:
   *  Constant: '<S34>/Constant1'
   *  Delay: '<S34>/Delay'
   *  Gain: '<S34>/Gain'
   *  Product: '<S34>/Product3'
   */
  Follow_Balance_DW.Delay_DSTATE += (real32_T)(0.03 * rtb_Add1_f);

  /* Saturate: '<S34>/Saturation' */
  if (Follow_Balance_DW.Delay_DSTATE > 2000.0) {
    /* Sum: '<S34>/Add2' */
    Follow_Balance_DW.Delay_DSTATE = 2000.0;
  } else if (Follow_Balance_DW.Delay_DSTATE < -2000.0) {
    /* Sum: '<S34>/Add2' */
    Follow_Balance_DW.Delay_DSTATE = -2000.0;
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
  rtb_Add_op = (7.0 * rtb_Add1_f + Follow_Balance_DW.Delay_DSTATE) + (rtb_Add1_f
    - Follow_Balance_DW.UD_DSTATE) * 5.0;

  /* Switch: '<S19>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S12>/Delay One Step'
   *  Switch: '<S19>/Switch3'
   */
  if (Follow_Balance_DW.DelayOneStep_DSTATE > -30.0F) {
    /* Switch: '<S19>/Switch' */
    if (Follow_Balance_DW.DelayOneStep_DSTATE > 30.0F) {
      /* Switch: '<S19>/Switch2' */
      if (rtb_Add_op > 0.0) {
        rtb_Add_op = floor(rtb_Add_op);
        if (rtIsInf(rtb_Add_op)) {
          /* Switch: '<S19>/Switch1' */
          Follow_Balance_B.Saturation = 0;
        } else {
          /* Switch: '<S19>/Switch1' */
          Follow_Balance_B.Saturation = (int16_T)(int32_T)fmod(rtb_Add_op,
            65536.0);
        }
      } else {
        /* Switch: '<S19>/Switch1' incorporates:
         *  Constant: '<S19>/Constant'
         */
        Follow_Balance_B.Saturation = 10;
      }

      /* End of Switch: '<S19>/Switch2' */
    } else {
      rtb_Add_op = floor(rtb_Add_op);
      if (rtIsNaN(rtb_Add_op) || rtIsInf(rtb_Add_op)) {
        rtb_Add_op = 0.0;
      } else {
        rtb_Add_op = fmod(rtb_Add_op, 65536.0);
      }

      /* Switch: '<S19>/Switch1' */
      Follow_Balance_B.Saturation = (int16_T)(rtb_Add_op < 0.0 ? (int32_T)
        (int16_T)-(int16_T)(uint16_T)-rtb_Add_op : (int32_T)(int16_T)(uint16_T)
        rtb_Add_op);
    }

    /* End of Switch: '<S19>/Switch' */
  } else if (rtb_Add_op > 0.0) {
    /* Switch: '<S19>/Switch1' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Switch: '<S19>/Switch3'
     */
    Follow_Balance_B.Saturation = -10;
  } else {
    /* Switch: '<S19>/Switch3' */
    rtb_Add_op = floor(rtb_Add_op);
    if (rtIsNaN(rtb_Add_op) || rtIsInf(rtb_Add_op)) {
      rtb_Add_op = 0.0;
    } else {
      rtb_Add_op = fmod(rtb_Add_op, 65536.0);
    }

    /* Switch: '<S19>/Switch1' incorporates:
     *  Switch: '<S19>/Switch3'
     */
    Follow_Balance_B.Saturation = (int16_T)(rtb_Add_op < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Add_op : (int32_T)(int16_T)(uint16_T)rtb_Add_op);
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Saturate: '<Root>/Saturation' */
  if (Follow_Balance_B.Saturation > 4200) {
    /* Switch: '<S19>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    Follow_Balance_B.Saturation = 4200;
  } else if (Follow_Balance_B.Saturation < -4200) {
    /* Switch: '<S19>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    Follow_Balance_B.Saturation = -4200;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<S32>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S13>/Delay One Step'
   */
  rtb_Add1_a = (real32_T)Follow_Balance_B.Saturation1 -
    Follow_Balance_DW.DelayOneStep_DSTATE_l;

  /* Sum: '<S38>/Add2' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Delay: '<S38>/Delay'
   *  Gain: '<S38>/Gain'
   *  Product: '<S38>/Product3'
   */
  Follow_Balance_DW.Delay_DSTATE_j += (real32_T)(0.03 * rtb_Add1_a);

  /* Saturate: '<S38>/Saturation' */
  if (Follow_Balance_DW.Delay_DSTATE_j > 2000.0F) {
    /* Sum: '<S38>/Add2' */
    Follow_Balance_DW.Delay_DSTATE_j = 2000.0F;
  } else if (Follow_Balance_DW.Delay_DSTATE_j < -2000.0F) {
    /* Sum: '<S38>/Add2' */
    Follow_Balance_DW.Delay_DSTATE_j = -2000.0F;
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
  rtb_Add_op = (7.0 * rtb_Add1_a + Follow_Balance_DW.Delay_DSTATE_j) +
    (rtb_Add1_a - Follow_Balance_DW.UD_DSTATE_a) * 4.0;

  /* Switch: '<S20>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S13>/Delay One Step'
   *  Switch: '<S20>/Switch3'
   */
  if (Follow_Balance_DW.DelayOneStep_DSTATE_l > -30.0F) {
    /* Switch: '<S20>/Switch' */
    if (Follow_Balance_DW.DelayOneStep_DSTATE_l > 30.0F) {
      /* Switch: '<S20>/Switch2' */
      if (rtb_Add_op > 0.0) {
        rtb_Add_op = floor(rtb_Add_op);
        if (rtIsInf(rtb_Add_op)) {
          /* Switch: '<S20>/Switch1' */
          Follow_Balance_B.Saturation1 = 0;
        } else {
          /* Switch: '<S20>/Switch1' */
          Follow_Balance_B.Saturation1 = (int16_T)(int32_T)fmod(rtb_Add_op,
            65536.0);
        }
      } else {
        /* Switch: '<S20>/Switch1' incorporates:
         *  Constant: '<S20>/Constant'
         */
        Follow_Balance_B.Saturation1 = 10;
      }

      /* End of Switch: '<S20>/Switch2' */
    } else {
      rtb_Add_op = floor(rtb_Add_op);
      if (rtIsNaN(rtb_Add_op) || rtIsInf(rtb_Add_op)) {
        rtb_Add_op = 0.0;
      } else {
        rtb_Add_op = fmod(rtb_Add_op, 65536.0);
      }

      /* Switch: '<S20>/Switch1' */
      Follow_Balance_B.Saturation1 = (int16_T)(rtb_Add_op < 0.0 ? (int32_T)
        (int16_T)-(int16_T)(uint16_T)-rtb_Add_op : (int32_T)(int16_T)(uint16_T)
        rtb_Add_op);
    }

    /* End of Switch: '<S20>/Switch' */
  } else if (rtb_Add_op > 0.0) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Constant: '<S20>/Constant1'
     *  Switch: '<S20>/Switch3'
     */
    Follow_Balance_B.Saturation1 = -10;
  } else {
    /* Switch: '<S20>/Switch3' */
    rtb_Add_op = floor(rtb_Add_op);
    if (rtIsNaN(rtb_Add_op) || rtIsInf(rtb_Add_op)) {
      rtb_Add_op = 0.0;
    } else {
      rtb_Add_op = fmod(rtb_Add_op, 65536.0);
    }

    /* Switch: '<S20>/Switch1' incorporates:
     *  Switch: '<S20>/Switch3'
     */
    Follow_Balance_B.Saturation1 = (int16_T)(rtb_Add_op < 0.0 ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-rtb_Add_op : (int32_T)(int16_T)(uint16_T)
      rtb_Add_op);
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Saturate: '<Root>/Saturation1' */
  if (Follow_Balance_B.Saturation1 > 4200) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Follow_Balance_B.Saturation1 = 4200;
  } else if (Follow_Balance_B.Saturation1 < -4200) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Follow_Balance_B.Saturation1 = -4200;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* S-Function (StackLiteDualDrive_DataLinkInput): '<Root>/DataLinkInput' */

  /*Input Data*/
  Follow_Balance_B.DataLinkInput_o1= DataLink_RevData[0].point;
  Follow_Balance_B.DataLinkInput_o2= DataLink_RevData[1].point;
  Follow_Balance_B.DataLinkInput_o3= DataLink_RevData[2].point;
  Follow_Balance_B.DataLinkInput_o4= DataLink_RevData[3].point;
  Follow_Balance_B.DataLinkInput_o5= DataLink_RevData[4].point;
  Follow_Balance_B.DataLinkInput_o6= DataLink_RevData[5].point;
  Follow_Balance_B.DataLinkInput_o7= DataLink_RevData[6].point;
  Follow_Balance_B.DataLinkInput_o8= DataLink_RevData[7].point;
  Follow_Balance_B.DataLinkInput_o9= DataLink_RevData[8].point;
  Follow_Balance_B.DataLinkInput_o10= DataLink_RevData[9].point;

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  Follow_Balance_DW.Kp_turn = Follow_Balance_B.DataLinkInput_o1;

  /* DataStoreWrite: '<Root>/Data Store Write2' */
  Follow_Balance_DW.Ki_turn = Follow_Balance_B.DataLinkInput_o2;

  /* DataStoreWrite: '<Root>/Data Store Write3' */
  Follow_Balance_DW.Kd_turn = Follow_Balance_B.DataLinkInput_o3;

  /* DataStoreWrite: '<Root>/Data Store Write4' */
  Follow_Balance_DW.tar_yaw = Follow_Balance_B.DataLinkInput_o4;

  /* Outputs for Enabled SubSystem: '<Root>/yaw to zero' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  /* Logic: '<Root>/AND' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read11'
   *  DataStoreRead: '<Root>/Data Store Read12'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   */
  if ((Follow_Balance_DW.flag == 0.0) && (angle_yaw != 0)) {
    /* DataStoreWrite: '<S18>/Data Store Write1' incorporates:
     *  Constant: '<S18>/Constant'
     */
    Follow_Balance_DW.flag = 1.0;

    /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
     *  DataStoreRead: '<S18>/Data Store Read'
     */
    Follow_Balance_DW.yaw_begin = angle_yaw;
  }

  /* End of Logic: '<Root>/AND' */
  /* End of Outputs for SubSystem: '<Root>/yaw to zero' */

  /* Update for UnitDelay: '<S36>/UD'
   *
   * Block description for '<S36>/UD':
   *
   *  Store in Global RAM
   */
  Follow_Balance_DW.UD_DSTATE = rtb_Add1_f;

  /* Update for UnitDelay: '<S40>/UD'
   *
   * Block description for '<S40>/UD':
   *
   *  Store in Global RAM
   */
  Follow_Balance_DW.UD_DSTATE_a = rtb_Add1_a;
}

/* Model initialize function */
void Follow_Balance_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void Follow_Balance_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
