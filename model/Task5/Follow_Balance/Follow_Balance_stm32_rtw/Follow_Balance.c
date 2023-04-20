/*
 * File: Follow_Balance.c
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
extern int32_t RPi_Revdata[4];         //data rev from RPi

/* Model step function */
void Follow_Balance_step(void)
{
  real_T rtb_Add1;
  real_T tmp;
  int32_T angle_yaw;
  int32_T rtb_Add1_m;
  real32_T rtb_Add1_e;
  real32_T rtb_Product3_p;

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
  Follow_Balance_DW.DelayOneStep_DSTATE_d = ((((0.95F *
    Follow_Balance_DW.DelayOneStep_DSTATE_d + 0.0499992371F * (real32_T)
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
  DataLink_UpFrameData.data[0].point= Follow_Balance_B.DataStoreRead10;
  DataLink_UpFrameData.data[1].point= Follow_Balance_B.DataTypeConversion3;
  DataLink_UpFrameData.data[2].point= Follow_Balance_B.DataTypeConversion8;
  DataLink_UpFrameData.data[3].point= 0.0F;
  DataLink_UpFrameData.data[4].point= 0.0F;
  DataLink_UpFrameData.data[5].point= 0.0F;
  DataLink_UpFrameData.data[6].point= 0.0F;
  DataLink_UpFrameData.data[7].point= 0.0F;
  DataLink_UpFrameData.data[8].point= 0.0F;
  DataLink_UpFrameData.data[9].point= 0.0F;
  DataLink_UpFrameData.data[10].point= Follow_Balance_B.Divide;
  DataLink_UpFrameData.data[11].point= Follow_Balance_B.Divide1;
  DataLink_UpFrameData.data[12].point= 0.0F;
  DataLink_UpFrameData.data[13].point= 0.0F;
  DataLink_UpFrameData.data[14].point= 0.0F;
  DataLink_UpFrameData.data[15].point= 0.0F;
  DataLink_UpFrameData.data[16].point= Follow_Balance_B.DataStoreRead14;
  DataLink_UpFrameData.data[17].point= Follow_Balance_B.DataTypeConversion11;
  DataLink_UpFrameData.data[18].point= Follow_Balance_B.DataStoreRead19;
  DataLink_UpFrameData.data[19].point= Follow_Balance_B.DataStoreRead20;

  /* S-Function (StackLiteDualDrive_Output): '<Root>/Output' */
  /*Output Data*/
  motor1_PwmData= Follow_Balance_B.Saturation_d;
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
      Follow_Balance_DW.Delay_DSTATE_o[0]) * 100.0F * 60.0F / 40000.0F;

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
    for (rtb_Add1_m = 0; rtb_Add1_m < 18; rtb_Add1_m++) {
      /* Update for Delay: '<S15>/Delay' */
      Follow_Balance_DW.Delay_DSTATE_o[rtb_Add1_m] =
        Follow_Balance_DW.Delay_DSTATE_o[rtb_Add1_m + 1];

      /* Update for Delay: '<S15>/Delay1' */
      Follow_Balance_DW.Delay1_DSTATE[rtb_Add1_m] =
        Follow_Balance_DW.Delay1_DSTATE[rtb_Add1_m + 1];
    }

    /* Update for Delay: '<S15>/Delay' */
    Follow_Balance_DW.Delay_DSTATE_o[18] = Follow_Balance_B.encoder1;

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
  if (Follow_Balance_DW.Output_DSTATE_i == 1) {
    /* Sum: '<S42>/Add1' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read4'
     *  Sum: '<S42>/Add2'
     */
    rtb_Add1 = Follow_Balance_DW.tar_speed - (Follow_Balance_B.Divide +
      Follow_Balance_B.Divide1);

    /* Gain: '<S44>/Gain1' incorporates:
     *  DataStoreRead: '<S44>/Data Store Read1'
     *  Delay: '<S44>/Delay'
     *  Gain: '<S44>/Gain'
     *  Product: '<S44>/Product3'
     *  Sum: '<S44>/Add2'
     */
    Follow_Balance_DW.Delay_DSTATE_i = ((real32_T)(0.001 *
      Follow_Balance_DW.Ki_speed * rtb_Add1) + Follow_Balance_DW.Delay_DSTATE_i)
      * 0.995F;

    /* Saturate: '<S44>/Saturation2' */
    if (Follow_Balance_DW.Delay_DSTATE_i > 1500.0F) {
      /* Gain: '<S44>/Gain1' */
      Follow_Balance_DW.Delay_DSTATE_i = 1500.0F;
    } else if (Follow_Balance_DW.Delay_DSTATE_i < -1500.0F) {
      /* Gain: '<S44>/Gain1' */
      Follow_Balance_DW.Delay_DSTATE_i = -1500.0F;
    }

    /* End of Saturate: '<S44>/Saturation2' */

    /* Sum: '<S42>/Add' incorporates:
     *  Constant: '<S45>/Constant'
     *  DataStoreRead: '<S43>/Data Store Read2'
     *  Delay: '<S44>/Delay'
     *  Gain: '<S43>/Gain'
     *  Gain: '<S45>/Gain'
     *  Product: '<S43>/Product2'
     *  Product: '<S45>/Product'
     *  Sum: '<S46>/Diff'
     *  UnitDelay: '<S46>/UD'
     *
     * Block description for '<S46>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S46>/UD':
     *
     *  Store in Global RAM
     */
    Follow_Balance_B.Add = (0.021 * rtb_Add1 + Follow_Balance_DW.Delay_DSTATE_i)
      + 0.001 * Follow_Balance_DW.Kd_speed * (rtb_Add1 -
      Follow_Balance_DW.UD_DSTATE_o);

    /* Update for UnitDelay: '<S46>/UD'
     *
     * Block description for '<S46>/UD':
     *
     *  Store in Global RAM
     */
    Follow_Balance_DW.UD_DSTATE_o = rtb_Add1;
  }

  /* End of RelationalOperator: '<S3>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/speedPID_motor' */

  /* Sum: '<Root>/Add' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   */
  rtb_Add1 = Follow_Balance_B.Add + Follow_Balance_DW.machine_mid;

  /* Sum: '<Root>/Add1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read13'
   *  DataStoreRead: '<Root>/Data Store Read8'
   */
  rtb_Add1_m = angle_yaw - Follow_Balance_DW.yaw_begin;

  /* Outputs for Enabled SubSystem: '<Root>/turnPID' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  UnitDelay: '<S10>/Output'
   */
  if (Follow_Balance_DW.Output_DSTATE_a == 1) {
    /* Sum: '<S17>/Add1' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read5'
     *  Sum: '<Root>/Add1'
     */
    rtb_Product3_p = Follow_Balance_DW.tar_yaw - (real32_T)rtb_Add1_m *
      3.81469727E-6F;

    /* Sum: '<S48>/Add2' incorporates:
     *  Constant: '<S48>/Constant1'
     *  Delay: '<S48>/Delay'
     *  Gain: '<S48>/Gain'
     *  Product: '<S48>/Product3'
     */
    Follow_Balance_DW.Delay_DSTATE_n += (real32_T)(-0.02 * rtb_Product3_p);

    /* Saturate: '<S48>/Saturation' */
    if (Follow_Balance_DW.Delay_DSTATE_n > 2000.0F) {
      /* Sum: '<S48>/Add2' */
      Follow_Balance_DW.Delay_DSTATE_n = 2000.0F;
    } else if (Follow_Balance_DW.Delay_DSTATE_n < -2000.0F) {
      /* Sum: '<S48>/Add2' */
      Follow_Balance_DW.Delay_DSTATE_n = -2000.0F;
    }

    /* End of Saturate: '<S48>/Saturation' */

    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S47>/Constant2'
     *  Constant: '<S49>/Constant'
     *  Delay: '<S48>/Delay'
     *  Gain: '<Root>/Gain2'
     *  Product: '<S47>/Product2'
     *  Product: '<S49>/Product'
     */
    Follow_Balance_B.Saturation = 26214.0 * (real_T)Follow_Balance_B.anglev[2] *
      3.814697265625E-6 * 3.0 + (-27.0 * rtb_Product3_p +
      Follow_Balance_DW.Delay_DSTATE_n);

    /* Saturate: '<S17>/Saturation' */
    if (Follow_Balance_B.Saturation > 1000.0) {
      /* Sum: '<S17>/Add' incorporates:
       *  Saturate: '<S17>/Saturation'
       */
      Follow_Balance_B.Saturation = 1000.0;
    } else if (Follow_Balance_B.Saturation < -1000.0) {
      /* Sum: '<S17>/Add' incorporates:
       *  Saturate: '<S17>/Saturation'
       */
      Follow_Balance_B.Saturation = -1000.0;
    }

    /* End of Saturate: '<S17>/Saturation' */
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
  if (Follow_Balance_DW.Output_DSTATE_i5 == 1) {
    int16_T tmp_0;

    /* Abs: '<Root>/Abs' */
    if (Follow_Balance_B.angle[1] < 0) {
      tmp_0 = (int16_T)-Follow_Balance_B.angle[1];
    } else {
      tmp_0 = Follow_Balance_B.angle[1];
    }

    /* End of Abs: '<Root>/Abs' */

    /* Switch: '<Root>/Switch' incorporates:
     *  Gain: '<Root>/Gain'
     */
    if (tmp_0 > 3500) {
      tmp = rtb_Add1;
    } else {
      tmp = 20972.0 * (real_T)Follow_Balance_B.angle[1] * 4.76837158203125E-7;
    }

    /* End of Switch: '<Root>/Switch' */

    /* Sum: '<S11>/Add' incorporates:
     *  Constant: '<S30>/Constant2'
     *  Constant: '<S31>/Constant'
     *  Gain: '<Root>/Gain1'
     *  Product: '<S30>/Product2'
     *  Product: '<S31>/Product'
     *  Sum: '<S11>/Add1'
     */
    Follow_Balance_B.Add_o = 26214.0 * (real_T)Follow_Balance_B.anglev[0] *
      3.814697265625E-6 * -6.0 + (rtb_Add1 - tmp) * 54.0;
  }

  /* End of RelationalOperator: '<S1>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/anglePID' */

  /* Switch: '<S23>/FixPt Switch' incorporates:
   *  Constant: '<S22>/FixPt Constant'
   *  Constant: '<S23>/Constant'
   *  Sum: '<S22>/FixPt Sum1'
   *  UnitDelay: '<S7>/Output'
   */
  if ((uint8_T)(Follow_Balance_DW.Output_DSTATE_i5 + 1) > 1) {
    Follow_Balance_DW.Output_DSTATE_i5 = 0U;
  } else {
    Follow_Balance_DW.Output_DSTATE_i5++;
  }

  /* End of Switch: '<S23>/FixPt Switch' */

  /* Switch: '<S25>/FixPt Switch' incorporates:
   *  Constant: '<S24>/FixPt Constant'
   *  Constant: '<S25>/Constant'
   *  Sum: '<S24>/FixPt Sum1'
   *  UnitDelay: '<S8>/Output'
   */
  if ((uint8_T)(Follow_Balance_DW.Output_DSTATE + 1) > 1) {
    Follow_Balance_DW.Output_DSTATE = 0U;
  } else {
    Follow_Balance_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S25>/FixPt Switch' */

  /* Switch: '<S27>/FixPt Switch' incorporates:
   *  Constant: '<S26>/FixPt Constant'
   *  Constant: '<S27>/Constant'
   *  Sum: '<S26>/FixPt Sum1'
   *  UnitDelay: '<S9>/Output'
   */
  if ((uint8_T)(Follow_Balance_DW.Output_DSTATE_i + 1) > 1) {
    Follow_Balance_DW.Output_DSTATE_i = 0U;
  } else {
    Follow_Balance_DW.Output_DSTATE_i++;
  }

  /* End of Switch: '<S27>/FixPt Switch' */

  /* Switch: '<S29>/FixPt Switch' incorporates:
   *  Constant: '<S28>/FixPt Constant'
   *  Constant: '<S29>/Constant'
   *  Sum: '<S28>/FixPt Sum1'
   *  UnitDelay: '<S10>/Output'
   */
  if ((uint8_T)(Follow_Balance_DW.Output_DSTATE_a + 1) > 1) {
    Follow_Balance_DW.Output_DSTATE_a = 0U;
  } else {
    Follow_Balance_DW.Output_DSTATE_a++;
  }

  /* End of Switch: '<S29>/FixPt Switch' */

  /* DataStoreRead: '<Root>/Data Store Read10' */
  Follow_Balance_B.DataStoreRead10 = Follow_Balance_DW.tar_yaw;

  /* DataStoreRead: '<Root>/Data Store Read14' */
  Follow_Balance_B.DataStoreRead14 = Follow_Balance_DW.tar_yaw;

  /* DataStoreRead: '<Root>/Data Store Read19' */
  Follow_Balance_B.DataStoreRead19 = Follow_Balance_DW.usart_input3;

  /* DataStoreRead: '<Root>/Data Store Read20' */
  Follow_Balance_B.DataStoreRead20 = Follow_Balance_DW.usart_input4;

  /* DataTypeConversion: '<Root>/Data Type Conversion11' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read9'
   */
  Follow_Balance_B.DataTypeConversion11 = (real32_T)angle_yaw * 3.81469727E-6F;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Sum: '<Root>/Add1'
   */
  Follow_Balance_B.DataTypeConversion3 = (real32_T)rtb_Add1_m * 3.81469727E-6F;

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read4'
   */
  Follow_Balance_B.DataTypeConversion8 = (real32_T)Follow_Balance_DW.tar_speed;

  /* Sum: '<Root>/Add2' */
  rtb_Add1 = Follow_Balance_B.Saturation + Follow_Balance_B.Add_o;

  /* Saturate: '<Root>/Saturation3' */
  if (rtb_Add1 > 2048.0) {
    rtb_Add1 = 2048.0;
  } else if (rtb_Add1 < -2048.0) {
    rtb_Add1 = -2048.0;
  }

  tmp = floor(rtb_Add1);
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Switch: '<S20>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation3'
   */
  Follow_Balance_B.Saturation_d = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* RateLimiter: '<Root>/Rate Limiter1' */
  if (Follow_Balance_B.Saturation_d - Follow_Balance_DW.PrevY > 5) {
    /* Switch: '<S20>/Switch1' */
    Follow_Balance_B.Saturation_d = (int16_T)(Follow_Balance_DW.PrevY + 5);
  } else if (Follow_Balance_B.Saturation_d - Follow_Balance_DW.PrevY < -5) {
    /* Switch: '<S20>/Switch1' */
    Follow_Balance_B.Saturation_d = (int16_T)(Follow_Balance_DW.PrevY + -5);
  }

  Follow_Balance_DW.PrevY = Follow_Balance_B.Saturation_d;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* Sum: '<Root>/Add3' */
  rtb_Add1 = Follow_Balance_B.Add_o - Follow_Balance_B.Saturation;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Add1 > 2048.0) {
    rtb_Add1 = 2048.0;
  } else if (rtb_Add1 < -2048.0) {
    rtb_Add1 = -2048.0;
  }

  tmp = floor(rtb_Add1);
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Switch: '<S21>/Switch1' incorporates:
   *  Saturate: '<Root>/Saturation2'
   */
  Follow_Balance_B.Saturation1 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* RateLimiter: '<Root>/Rate Limiter2' */
  rtb_Add1_m = Follow_Balance_B.Saturation1 - Follow_Balance_DW.PrevY_n;
  if (rtb_Add1_m > 5) {
    /* Switch: '<S21>/Switch1' */
    Follow_Balance_B.Saturation1 = (int16_T)(Follow_Balance_DW.PrevY_n + 5);
  } else if (rtb_Add1_m < -5) {
    /* Switch: '<S21>/Switch1' */
    Follow_Balance_B.Saturation1 = (int16_T)(Follow_Balance_DW.PrevY_n + -5);
  }

  Follow_Balance_DW.PrevY_n = Follow_Balance_B.Saturation1;

  /* End of RateLimiter: '<Root>/Rate Limiter2' */

  /* Sum: '<S32>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S12>/Delay One Step'
   */
  rtb_Product3_p = (real32_T)Follow_Balance_B.Saturation_d -
    Follow_Balance_DW.DelayOneStep_DSTATE;

  /* Sum: '<S35>/Add2' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Delay: '<S35>/Delay'
   *  Gain: '<S35>/Gain'
   *  Product: '<S35>/Product3'
   */
  Follow_Balance_DW.Delay_DSTATE += (real32_T)(0.03 * rtb_Product3_p);

  /* Saturate: '<S35>/Saturation' */
  if (Follow_Balance_DW.Delay_DSTATE > 2000.0) {
    /* Sum: '<S35>/Add2' */
    Follow_Balance_DW.Delay_DSTATE = 2000.0;
  } else if (Follow_Balance_DW.Delay_DSTATE < -2000.0) {
    /* Sum: '<S35>/Add2' */
    Follow_Balance_DW.Delay_DSTATE = -2000.0;
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Sum: '<S32>/Add' incorporates:
   *  Constant: '<S34>/Constant2'
   *  Constant: '<S36>/Constant'
   *  Delay: '<S35>/Delay'
   *  Product: '<S34>/Product2'
   *  Product: '<S36>/Product'
   *  Sum: '<S37>/Diff'
   *  UnitDelay: '<S37>/UD'
   *
   * Block description for '<S37>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S37>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add1 = (7.0 * rtb_Product3_p + Follow_Balance_DW.Delay_DSTATE) +
    (rtb_Product3_p - Follow_Balance_DW.UD_DSTATE_f) * 5.0;

  /* Switch: '<S20>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write6'
   *  Delay: '<S12>/Delay One Step'
   *  Switch: '<S20>/Switch3'
   */
  if (Follow_Balance_DW.DelayOneStep_DSTATE > -30.0F) {
    /* Switch: '<S20>/Switch' */
    if (Follow_Balance_DW.DelayOneStep_DSTATE > 30.0F) {
      /* Switch: '<S20>/Switch2' */
      if (rtb_Add1 > 0.0) {
        tmp = floor(rtb_Add1);
        if (rtIsInf(tmp)) {
          /* Switch: '<S20>/Switch1' */
          Follow_Balance_B.Saturation_d = 0;
        } else {
          /* Switch: '<S20>/Switch1' */
          Follow_Balance_B.Saturation_d = (int16_T)(int32_T)fmod(tmp, 65536.0);
        }
      } else {
        /* Switch: '<S20>/Switch1' incorporates:
         *  Constant: '<S20>/Constant'
         */
        Follow_Balance_B.Saturation_d = 10;
      }

      /* End of Switch: '<S20>/Switch2' */
    } else {
      tmp = floor(rtb_Add1);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 65536.0);
      }

      /* Switch: '<S20>/Switch1' */
      Follow_Balance_B.Saturation_d = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
        -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
    }

    /* End of Switch: '<S20>/Switch' */
  } else if (rtb_Add1 > 0.0) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Constant: '<S20>/Constant1'
     *  Switch: '<S20>/Switch3'
     */
    Follow_Balance_B.Saturation_d = -10;
  } else {
    /* Switch: '<S20>/Switch3' */
    tmp = floor(rtb_Add1);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    /* Switch: '<S20>/Switch1' incorporates:
     *  Switch: '<S20>/Switch3'
     */
    Follow_Balance_B.Saturation_d = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Saturate: '<Root>/Saturation' */
  if (Follow_Balance_B.Saturation_d > 4200) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    Follow_Balance_B.Saturation_d = 4200;
  } else if (Follow_Balance_B.Saturation_d < -4200) {
    /* Switch: '<S20>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    Follow_Balance_B.Saturation_d = -4200;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<S33>/Add1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S13>/Delay One Step'
   */
  rtb_Add1_e = (real32_T)Follow_Balance_B.Saturation1 -
    Follow_Balance_DW.DelayOneStep_DSTATE_d;

  /* Sum: '<S39>/Add2' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Delay: '<S39>/Delay'
   *  Gain: '<S39>/Gain'
   *  Product: '<S39>/Product3'
   */
  Follow_Balance_DW.Delay_DSTATE_g += (real32_T)(0.03 * rtb_Add1_e);

  /* Saturate: '<S39>/Saturation' */
  if (Follow_Balance_DW.Delay_DSTATE_g > 2000.0F) {
    /* Sum: '<S39>/Add2' */
    Follow_Balance_DW.Delay_DSTATE_g = 2000.0F;
  } else if (Follow_Balance_DW.Delay_DSTATE_g < -2000.0F) {
    /* Sum: '<S39>/Add2' */
    Follow_Balance_DW.Delay_DSTATE_g = -2000.0F;
  }

  /* End of Saturate: '<S39>/Saturation' */

  /* Sum: '<S33>/Add' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Constant: '<S40>/Constant'
   *  Delay: '<S39>/Delay'
   *  Product: '<S38>/Product2'
   *  Product: '<S40>/Product'
   *  Sum: '<S41>/Diff'
   *  UnitDelay: '<S41>/UD'
   *
   * Block description for '<S41>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add1 = (7.0 * rtb_Add1_e + Follow_Balance_DW.Delay_DSTATE_g) + (rtb_Add1_e
    - Follow_Balance_DW.UD_DSTATE_k) * 4.0;

  /* Switch: '<S21>/Switch1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write7'
   *  Delay: '<S13>/Delay One Step'
   *  Switch: '<S21>/Switch3'
   */
  if (Follow_Balance_DW.DelayOneStep_DSTATE_d > -30.0F) {
    /* Switch: '<S21>/Switch' */
    if (Follow_Balance_DW.DelayOneStep_DSTATE_d > 30.0F) {
      /* Switch: '<S21>/Switch2' */
      if (rtb_Add1 > 0.0) {
        tmp = floor(rtb_Add1);
        if (rtIsInf(tmp)) {
          /* Switch: '<S21>/Switch1' */
          Follow_Balance_B.Saturation1 = 0;
        } else {
          /* Switch: '<S21>/Switch1' */
          Follow_Balance_B.Saturation1 = (int16_T)(int32_T)fmod(tmp, 65536.0);
        }
      } else {
        /* Switch: '<S21>/Switch1' incorporates:
         *  Constant: '<S21>/Constant'
         */
        Follow_Balance_B.Saturation1 = 10;
      }

      /* End of Switch: '<S21>/Switch2' */
    } else {
      tmp = floor(rtb_Add1);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 65536.0);
      }

      /* Switch: '<S21>/Switch1' */
      Follow_Balance_B.Saturation1 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
        -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
    }

    /* End of Switch: '<S21>/Switch' */
  } else if (rtb_Add1 > 0.0) {
    /* Switch: '<S21>/Switch1' incorporates:
     *  Constant: '<S21>/Constant1'
     *  Switch: '<S21>/Switch3'
     */
    Follow_Balance_B.Saturation1 = -10;
  } else {
    /* Switch: '<S21>/Switch3' */
    tmp = floor(rtb_Add1);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    /* Switch: '<S21>/Switch1' incorporates:
     *  Switch: '<S21>/Switch3'
     */
    Follow_Balance_B.Saturation1 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Saturate: '<Root>/Saturation1' */
  if (Follow_Balance_B.Saturation1 > 4200) {
    /* Switch: '<S21>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Follow_Balance_B.Saturation1 = 4200;
  } else if (Follow_Balance_B.Saturation1 < -4200) {
    /* Switch: '<S21>/Switch1' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Follow_Balance_B.Saturation1 = -4200;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* DataStoreWrite: '<Root>/Data Store Write15' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Follow_Balance_DW.machine_mid = 2.0;

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

  /* S-Function (StackLiteDualDrive_RPiDataInput): '<Root>/RPiDataInput' */

  /*RPi Input Data*/
  Follow_Balance_B.RPiDataInput_o1= RPi_Revdata[0];
  Follow_Balance_B.RPiDataInput_o2= RPi_Revdata[1];
  Follow_Balance_B.RPiDataInput_o3= RPi_Revdata[2];
  Follow_Balance_B.RPiDataInput_o4= RPi_Revdata[3];

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write13'
   */
  Follow_Balance_DW.usart_input4 = (real32_T)Follow_Balance_B.RPiDataInput_o4;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write4'
   */
  Follow_Balance_DW.usart_input3 = (real32_T)Follow_Balance_B.RPiDataInput_o3;

  /* DataStoreRead: '<S18>/Data Store Read17' */
  rtb_Add1 = Follow_Balance_DW.tar_lenth;

  /* Gain: '<S53>/Gain1' incorporates:
   *  Constant: '<S53>/Constant1'
   *  DataStoreRead: '<S18>/Data Store Read17'
   *  Delay: '<S53>/Delay'
   *  Product: '<S53>/Product3'
   *  Sum: '<S53>/Add2'
   */
  Follow_Balance_DW.Delay_DSTATE_a = ((real32_T)(-0.1 *
    Follow_Balance_DW.tar_lenth) + Follow_Balance_DW.Delay_DSTATE_a) * 0.995;

  /* Sum: '<S18>/Add4' incorporates:
   *  Constant: '<S50>/Constant2'
   *  Constant: '<S54>/Constant'
   *  DataStoreRead: '<S18>/Data Store Read17'
   *  DataStoreWrite: '<S18>/Data Store Write14'
   *  Delay: '<S53>/Delay'
   *  Product: '<S50>/Product2'
   *  Product: '<S54>/Product'
   *  Sum: '<S57>/Diff'
   *  UnitDelay: '<S57>/UD'
   *
   * Block description for '<S57>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S57>/UD':
   *
   *  Store in Global RAM
   */
  Follow_Balance_DW.tar_speed = (-10.0 * Follow_Balance_DW.tar_lenth +
    Follow_Balance_DW.Delay_DSTATE_a) + (Follow_Balance_DW.tar_lenth -
    Follow_Balance_DW.UD_DSTATE) * 0.0;

  /* Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  /* Switch: '<S18>/Switch3' incorporates:
   *  DataStoreRead: '<S18>/Data Store Read16'
   *  Logic: '<S55>/AND1'
   *  Logic: '<S55>/AND2'
   *  Logic: '<S55>/NOT'
   *  Logic: '<S55>/NOT1'
   *  Logic: '<S55>/NOT2'
   *  Logic: '<S55>/OR'
   */
  if (!(Follow_Balance_DW.usart_input4 != 0.0F)) {
    /* DataStoreWrite: '<S51>/Data Store Write' incorporates:
     *  Constant: '<S51>/Constant'
     */
    Follow_Balance_DW.tar_lenth = 0.0;
  } else {
    int32_T rtb_Switch1_l;

    /* Outputs for Enabled SubSystem: '<S18>/Subsystem' incorporates:
     *  EnablePort: '<S55>/Enable'
     */
    /* Switch: '<S55>/Switch2' */
    rtb_Add1_m = (Follow_Balance_DW.usart_input4 > 37.0F);

    /* Switch: '<S55>/Switch1' */
    rtb_Switch1_l = !(Follow_Balance_DW.usart_input4 > 32.0F);

    /* Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S58>/Enable'
     */
    if ((rtb_Add1_m == 0) && (rtb_Switch1_l == 0)) {
      /* DataStoreWrite: '<S58>/Data Store Write' incorporates:
       *  Constant: '<S58>/Constant'
       */
      Follow_Balance_DW.tar_lenth = 0.0;
    }

    /* End of Outputs for SubSystem: '<S55>/Enabled Subsystem' */

    /* Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S59>/Enable'
     */
    if ((rtb_Add1_m != 0) && (rtb_Switch1_l == 0)) {
      /* Sum: '<S59>/Add' incorporates:
       *  Constant: '<S59>/Constant'
       *  DataStoreWrite: '<S59>/Data Store Write'
       */
      Follow_Balance_DW.tar_lenth = 37.0 - Follow_Balance_DW.usart_input4;
    }

    /* End of Outputs for SubSystem: '<S55>/Enabled Subsystem1' */

    /* Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem2' incorporates:
     *  EnablePort: '<S60>/Enable'
     */
    if ((rtb_Add1_m == 0) && (rtb_Switch1_l != 0)) {
      /* Sum: '<S60>/Add' incorporates:
       *  Constant: '<S60>/Constant'
       *  DataStoreWrite: '<S60>/Data Store Write'
       */
      Follow_Balance_DW.tar_lenth = 32.0 - Follow_Balance_DW.usart_input4;
    }

    /* End of Outputs for SubSystem: '<S55>/Enabled Subsystem2' */
    /* End of Outputs for SubSystem: '<S18>/Subsystem' */
  }

  /* End of Switch: '<S18>/Switch3' */
  /* End of Outputs for SubSystem: '<S18>/Enabled Subsystem' */

  /* Outputs for Enabled SubSystem: '<S18>/Subsystem1' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  /* Switch: '<S18>/Switch1' incorporates:
   *  DataStoreRead: '<S18>/Data Store Read18'
   */
  if ((boolean_T)(Follow_Balance_DW.usart_input3 != 0.0F)) {
    /* Gain: '<S56>/Gain5' incorporates:
     *  DataStoreWrite: '<S56>/Data Store Write11'
     */
    Follow_Balance_DW.tar_yaw = -Follow_Balance_DW.usart_input3;

    /* Delay: '<S56>/Delay' */
    Follow_Balance_B.Delay = Follow_Balance_DW.Delay_DSTATE_p;

    /* Update for Delay: '<S56>/Delay' incorporates:
     *  DataStoreWrite: '<S56>/Data Store Write11'
     */
    Follow_Balance_DW.Delay_DSTATE_p = Follow_Balance_DW.tar_yaw;
  } else {
    /* Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S52>/Enable'
     */
    /* DataStoreWrite: '<S52>/Data Store Write' */
    Follow_Balance_DW.tar_yaw = Follow_Balance_B.Delay;

    /* End of Outputs for SubSystem: '<S18>/Enabled Subsystem1' */
  }

  /* End of Switch: '<S18>/Switch1' */
  /* End of Outputs for SubSystem: '<S18>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<Root>/yaw to zero' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  /* Logic: '<Root>/AND' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read11'
   *  DataStoreRead: '<Root>/Data Store Read12'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   */
  if ((Follow_Balance_DW.flag == 0.0) && (angle_yaw != 0)) {
    /* DataStoreWrite: '<S19>/Data Store Write1' incorporates:
     *  Constant: '<S19>/Constant'
     */
    Follow_Balance_DW.flag = 1.0;

    /* DataStoreWrite: '<S19>/Data Store Write' incorporates:
     *  DataStoreRead: '<S19>/Data Store Read'
     */
    Follow_Balance_DW.yaw_begin = angle_yaw;
  }

  /* End of Logic: '<Root>/AND' */
  /* End of Outputs for SubSystem: '<Root>/yaw to zero' */

  /* Update for UnitDelay: '<S37>/UD'
   *
   * Block description for '<S37>/UD':
   *
   *  Store in Global RAM
   */
  Follow_Balance_DW.UD_DSTATE_f = rtb_Product3_p;

  /* Update for UnitDelay: '<S41>/UD'
   *
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  Follow_Balance_DW.UD_DSTATE_k = rtb_Add1_e;

  /* Update for UnitDelay: '<S57>/UD'
   *
   * Block description for '<S57>/UD':
   *
   *  Store in Global RAM
   */
  Follow_Balance_DW.UD_DSTATE = rtb_Add1;
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
