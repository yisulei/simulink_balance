/*
 * File: StackLiteDualDrive.c
 *
 * Code generated for Simulink model 'StackLiteDualDrive'.
 *
 * Model version                  : 1.60
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Nov  1 22:41:41 2022
 *
 * Target selection: stacklite_dualdrive.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ifr-scope_device.h"
#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "stdio.h"
#include <string.h>
#include "StackLiteDualDrive.h"
#include "StackLiteDualDrive_private.h"

/* Block signals (default storage) */
B_StackLiteDualDrive_T StackLiteDualDrive_B;

/* Block states (default storage) */
DW_StackLiteDualDrive_T StackLiteDualDrive_DW;

/* Real-time model */
static RT_MODEL_StackLiteDualDrive_T StackLiteDualDrive_M_;
RT_MODEL_StackLiteDualDrive_T *const StackLiteDualDrive_M =
  &StackLiteDualDrive_M_;
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
void StackLiteDualDrive_step(void)
{
  /* local block i/o variables */
  real32_T rtb_M1_Current_PID;
  real32_T rtb_M2_Current_PID;
  real32_T rtb_Speed_PID;
  real32_T rtb_RateLimiter1;
  boolean_T rtb_Compare_m;

  /* S-Function (StackLiteDualDrive_Input): '<Root>/Input' */
  /*Input Data*/
  memcpy(&StackLiteDualDrive_B.angle[0],HI226_Angle,3*2);
  memcpy(&StackLiteDualDrive_B.anglev[0],HI226_AngleV,3*2);
  StackLiteDualDrive_B.encoder1= (int32_t)(__HAL_TIM_GetCounter(&htim2));
  StackLiteDualDrive_B.encoder2= -(int32_t)(__HAL_TIM_GetCounter(&htim5));
  memcpy(&StackLiteDualDrive_B.current1[0],adc_rawvalue[0],5*2);
  memcpy(&StackLiteDualDrive_B.current2[0],adc_rawvalue[1],5*2);

  /* Outputs for Enabled SubSystem: '<Root>/main control' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  UnitDelay: '<S4>/Output'
   */
  if (StackLiteDualDrive_DW.Output_DSTATE_l == 1) {
    real32_T rtb_Sum;

    /* Sum: '<S16>/Sum' incorporates:
     *  DataStoreRead: '<S8>/Data Store Read4'
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     */
    rtb_Sum = StackLiteDualDrive_DW.UpRight_Set - (real32_T)
      StackLiteDualDrive_B.angle[1];

    /* Switch: '<S18>/Switch' incorporates:
     *  DataStoreRead: '<S8>/Data Store Read2'
     *  Delay: '<S16>/Delay2'
     *  Gain: '<S18>/Gain'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  RelationalOperator: '<S18>/Relational Operator1'
     *  Switch: '<S18>/Switch1'
     */
    if (StackLiteDualDrive_DW.Delay2_DSTATE >
        StackLiteDualDrive_DW.UpRight_iLimit) {
      rtb_RateLimiter1 = StackLiteDualDrive_DW.UpRight_iLimit;
    } else if (StackLiteDualDrive_DW.Delay2_DSTATE <
               -StackLiteDualDrive_DW.UpRight_iLimit) {
      /* Switch: '<S18>/Switch1' incorporates:
       *  Gain: '<S18>/Gain'
       */
      rtb_RateLimiter1 = -StackLiteDualDrive_DW.UpRight_iLimit;
    } else {
      rtb_RateLimiter1 = StackLiteDualDrive_DW.Delay2_DSTATE;
    }

    /* End of Switch: '<S18>/Switch' */

    /* Sum: '<S16>/Add' incorporates:
     *  DataStoreRead: '<S8>/Data Store Read1'
     *  Delay: '<S16>/Delay2'
     *  Product: '<S16>/Ki Product'
     */
    StackLiteDualDrive_DW.Delay2_DSTATE = StackLiteDualDrive_DW.UpRight_Ki *
      rtb_Sum + rtb_RateLimiter1;

    /* Sum: '<S17>/Add4' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion1'
     *  Delay: '<S17>/Delay One Step'
     *  Gain: '<S17>/Gain8'
     *  Gain: '<S17>/Gain9'
     */
    StackLiteDualDrive_DW.DelayOneStep_DSTATE_i = 0.5F *
      StackLiteDualDrive_DW.DelayOneStep_DSTATE_i + 0.5F * (real32_T)
      StackLiteDualDrive_B.anglev[0];

    /* Gain: '<S8>/Gain' incorporates:
     *  Delay: '<S8>/Delay'
     *  Delay: '<S8>/Delay1'
     *  Sum: '<S8>/Subtract'
     *  Sum: '<S8>/Subtract1'
     */
    rtb_RateLimiter1 = (real32_T)(((StackLiteDualDrive_B.encoder1 -
      StackLiteDualDrive_DW.Delay_DSTATE[StackLiteDualDrive_DW.CircBufIdx]) +
      StackLiteDualDrive_B.encoder2) -
      StackLiteDualDrive_DW.Delay1_DSTATE[StackLiteDualDrive_DW.CircBufIdx_h]) *
      0.5F;

    /* ModelReference: '<S8>/Speed_PID' incorporates:
     *  DataStoreRead: '<S8>/Data Store Read5'
     *  DataStoreRead: '<S8>/Data Store Read6'
     *  DataStoreRead: '<S8>/Data Store Read7'
     *  DataStoreRead: '<S8>/Data Store Read8'
     *  DataStoreRead: '<S8>/Data Store Read9'
     */
    variParaPID(&StackLiteDualDrive_DW.Speed_Kp, &StackLiteDualDrive_DW.Speed_Ki,
                &StackLiteDualDrive_DW.Speed_iLimit,
                &StackLiteDualDrive_DW.Speed_Kd,
                &StackLiteDualDrive_DW.Speed_Set, &rtb_RateLimiter1,
                &rtb_Speed_PID,
                &(StackLiteDualDrive_DW.Speed_PID_InstanceData.rtdw));

    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S8>/Constant'
     *  DataStoreRead: '<S8>/Data Store Read'
     *  DataStoreRead: '<S8>/Data Store Read3'
     *  Delay: '<S16>/Delay2'
     *  Delay: '<S17>/Delay One Step'
     *  Logic: '<S15>/Logical Operator'
     *  Product: '<S16>/Kd Product'
     *  Product: '<S16>/Kp Product'
     *  Saturate: '<S8>/Saturation'
     *  Sum: '<S16>/Sum1'
     *  Sum: '<S8>/Add1'
     *  Switch: '<S15>/Switch'
     *  Switch: '<S15>/Switch1'
     */
    if ((StackLiteDualDrive_B.angle[1] > 4000) || (StackLiteDualDrive_B.angle[1]
         <= -4000)) {
      rtb_RateLimiter1 = 0.0F;
    } else {
      if (rtb_Speed_PID > 300.0F) {
        /* Saturate: '<S8>/Saturation' */
        rtb_RateLimiter1 = 300.0F;
      } else if (rtb_Speed_PID < -300.0F) {
        /* Saturate: '<S8>/Saturation' */
        rtb_RateLimiter1 = -300.0F;
      } else {
        /* Saturate: '<S8>/Saturation' */
        rtb_RateLimiter1 = rtb_Speed_PID;
      }

      rtb_RateLimiter1 += (StackLiteDualDrive_DW.UpRight_Kp * rtb_Sum +
                           StackLiteDualDrive_DW.Delay2_DSTATE) +
        StackLiteDualDrive_DW.DelayOneStep_DSTATE_i *
        StackLiteDualDrive_DW.UpRight_Kd;
    }

    /* End of Switch: '<S8>/Switch' */

    /* Saturate: '<S8>/Saturation1' */
    if (rtb_RateLimiter1 > 1000.0F) {
      /* Saturate: '<S8>/Saturation1' */
      StackLiteDualDrive_B.Saturation1 = 1000.0F;
    } else if (rtb_RateLimiter1 < -1000.0F) {
      /* Saturate: '<S8>/Saturation1' */
      StackLiteDualDrive_B.Saturation1 = -1000.0F;
    } else {
      /* Saturate: '<S8>/Saturation1' */
      StackLiteDualDrive_B.Saturation1 = rtb_RateLimiter1;
    }

    /* End of Saturate: '<S8>/Saturation1' */

    /* SignalConversion generated from: '<S8>/m2' */
    StackLiteDualDrive_B.OutportBufferForm2 = StackLiteDualDrive_B.Saturation1;

    /* Update for Delay: '<S8>/Delay' */
    StackLiteDualDrive_DW.Delay_DSTATE[StackLiteDualDrive_DW.CircBufIdx] =
      StackLiteDualDrive_B.encoder1;
    if (StackLiteDualDrive_DW.CircBufIdx < 4U) {
      StackLiteDualDrive_DW.CircBufIdx++;
    } else {
      StackLiteDualDrive_DW.CircBufIdx = 0U;
    }

    /* End of Update for Delay: '<S8>/Delay' */

    /* Update for Delay: '<S8>/Delay1' */
    StackLiteDualDrive_DW.Delay1_DSTATE[StackLiteDualDrive_DW.CircBufIdx_h] =
      StackLiteDualDrive_B.encoder2;
    if (StackLiteDualDrive_DW.CircBufIdx_h < 4U) {
      StackLiteDualDrive_DW.CircBufIdx_h++;
    } else {
      StackLiteDualDrive_DW.CircBufIdx_h = 0U;
    }

    /* End of Update for Delay: '<S8>/Delay1' */
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/main control' */

  /* S-Function (StackLiteDualDrive_DataLinkOutput): '<Root>/DataLinkOutput' */
  /*Output Data*/
  DataLink_UpFrameData.data[0].point= StackLiteDualDrive_B.DataTypeConversion2;
  DataLink_UpFrameData.data[1].point= StackLiteDualDrive_B.Add4;
  DataLink_UpFrameData.data[2].point= StackLiteDualDrive_B.Add4_e;
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
  DataLink_UpFrameData.data[14].point= StackLiteDualDrive_B.DataLinkInput_o1;
  DataLink_UpFrameData.data[15].point= StackLiteDualDrive_B.DataLinkInput_o2;
  DataLink_UpFrameData.data[16].point= StackLiteDualDrive_B.DataLinkInput_o3;
  DataLink_UpFrameData.data[17].point= StackLiteDualDrive_B.DataLinkInput_o4;
  DataLink_UpFrameData.data[18].point= StackLiteDualDrive_B.DataLinkInput_o5;
  DataLink_UpFrameData.data[19].point= StackLiteDualDrive_B.DataLinkInput_o6;

  /* S-Function (StackLiteDualDrive_Output): '<Root>/Output' */
  /*Output Data*/
  motor1_PwmData= StackLiteDualDrive_B.Switch1_e;
  motor2_PwmData= StackLiteDualDrive_B.Switch1;
  HAL_GPIO_WritePin(USER_LED_GPIO_Port,USER_LED_Pin,(GPIO_PinState)
                    StackLiteDualDrive_B.LogicalOperator);
  memcpy(ws2812_data,&StackLiteDualDrive_B.ws2812[0],3);

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S3>/Output'
   */
  rtb_Compare_m = (StackLiteDualDrive_DW.Output_DSTATE == 100);

  /* Switch: '<S12>/FixPt Switch' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  Constant: '<S12>/Constant'
   *  Sum: '<S11>/FixPt Sum1'
   *  UnitDelay: '<S3>/Output'
   */
  if ((uint16_T)(StackLiteDualDrive_DW.Output_DSTATE + 1U) > 1000) {
    StackLiteDualDrive_DW.Output_DSTATE = 0U;
  } else {
    StackLiteDualDrive_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S12>/FixPt Switch' */

  /* Switch: '<S14>/FixPt Switch' incorporates:
   *  Constant: '<S13>/FixPt Constant'
   *  Constant: '<S14>/Constant'
   *  Sum: '<S13>/FixPt Sum1'
   *  UnitDelay: '<S4>/Output'
   */
  if ((uint8_T)(StackLiteDualDrive_DW.Output_DSTATE_l + 1U) > 1) {
    StackLiteDualDrive_DW.Output_DSTATE_l = 0U;
  } else {
    StackLiteDualDrive_DW.Output_DSTATE_l++;
  }

  /* End of Switch: '<S14>/FixPt Switch' */

  /* RateLimiter: '<Root>/Rate Limiter' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write'
   */
  rtb_RateLimiter1 = StackLiteDualDrive_B.Saturation1 -
    StackLiteDualDrive_DW.PrevY;
  if (rtb_RateLimiter1 > 5.0F) {
    rtb_RateLimiter1 = StackLiteDualDrive_DW.PrevY + 5.0F;
  } else if (rtb_RateLimiter1 < -5.0F) {
    rtb_RateLimiter1 = StackLiteDualDrive_DW.PrevY + -5.0F;
  } else {
    rtb_RateLimiter1 = StackLiteDualDrive_B.Saturation1;
  }

  StackLiteDualDrive_DW.PrevY = rtb_RateLimiter1;

  /* End of RateLimiter: '<Root>/Rate Limiter' */

  /* Sum: '<S6>/Add4' incorporates:
   *  Delay: '<S6>/Delay One Step'
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S6>/Gain2'
   *  Gain: '<S6>/Gain3'
   *  Gain: '<S6>/Gain4'
   *  Gain: '<S6>/Gain5'
   *  Gain: '<S6>/Gain6'
   *  Gain: '<S6>/Gain7'
   *  Gain: '<S6>/Gain8'
   *  Gain: '<S6>/Gain9'
   *  Sum: '<S6>/Add'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S6>/Add2'
   *  Sum: '<S6>/Add3'
   */
  StackLiteDualDrive_B.Add4 = ((((0.95F *
    StackLiteDualDrive_DW.DelayOneStep_DSTATE + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current1[0]) * 0.95F + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current1[1]) * 0.95F + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current1[2]) * 0.95F + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current1[3]) * 0.95F + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current1[4];

  /* ModelReference: '<Root>/M1_Current_PID' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   *  DataStoreRead: '<Root>/Data Store Read1'
   *  DataStoreRead: '<Root>/Data Store Read2'
   *  DataStoreRead: '<Root>/Data Store Read7'
   */
  variParaPID(&StackLiteDualDrive_DW.M1_Current_Kp,
              &StackLiteDualDrive_DW.M1_Current_Ki,
              &StackLiteDualDrive_DW.M1_Current_iLimit,
              &StackLiteDualDrive_DW.M1_Current_Kd, &rtb_RateLimiter1,
              &StackLiteDualDrive_B.Add4, &rtb_M1_Current_PID,
              &(StackLiteDualDrive_DW.M1_Current_PID_InstanceData.rtdw));

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_RateLimiter1 = floorf(rtb_M1_Current_PID);
  if (rtIsNaNF(rtb_RateLimiter1) || rtIsInfF(rtb_RateLimiter1)) {
    rtb_RateLimiter1 = 0.0F;
  } else {
    rtb_RateLimiter1 = fmodf(rtb_RateLimiter1, 65536.0F);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  StackLiteDualDrive_B.Switch1_e = (int16_T)(rtb_RateLimiter1 < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-rtb_RateLimiter1 : (int32_T)(int16_T)(uint16_T)
    rtb_RateLimiter1);

  /* RateLimiter: '<Root>/Rate Limiter1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write1'
   */
  rtb_RateLimiter1 = StackLiteDualDrive_B.OutportBufferForm2 -
    StackLiteDualDrive_DW.PrevY_d;
  if (rtb_RateLimiter1 > 5.0F) {
    rtb_RateLimiter1 = StackLiteDualDrive_DW.PrevY_d + 5.0F;
  } else if (rtb_RateLimiter1 < -5.0F) {
    rtb_RateLimiter1 = StackLiteDualDrive_DW.PrevY_d + -5.0F;
  } else {
    rtb_RateLimiter1 = StackLiteDualDrive_B.OutportBufferForm2;
  }

  StackLiteDualDrive_DW.PrevY_d = rtb_RateLimiter1;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

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
  StackLiteDualDrive_B.Add4_e = ((((0.95F *
    StackLiteDualDrive_DW.DelayOneStep_DSTATE_a + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current2[0]) * 0.95F + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current2[1]) * 0.95F + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current2[2]) * 0.95F + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current2[3]) * 0.95F + 0.0499992371F * (real32_T)
    StackLiteDualDrive_B.current2[4];

  /* ModelReference: '<Root>/M2_Current_PID' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read3'
   *  DataStoreRead: '<Root>/Data Store Read4'
   *  DataStoreRead: '<Root>/Data Store Read5'
   *  DataStoreRead: '<Root>/Data Store Read8'
   */
  variParaPID(&StackLiteDualDrive_DW.M2_Current_Kp,
              &StackLiteDualDrive_DW.M2_Current_Ki,
              &StackLiteDualDrive_DW.M2_Current_iLimit,
              &StackLiteDualDrive_DW.M2_Current_Kd, &rtb_RateLimiter1,
              &StackLiteDualDrive_B.Add4_e, &rtb_M2_Current_PID,
              &(StackLiteDualDrive_DW.M2_Current_PID_InstanceData.rtdw));

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_RateLimiter1 = floorf(rtb_M2_Current_PID);
  if (rtIsNaNF(rtb_RateLimiter1) || rtIsInfF(rtb_RateLimiter1)) {
    rtb_RateLimiter1 = 0.0F;
  } else {
    rtb_RateLimiter1 = fmodf(rtb_RateLimiter1, 65536.0F);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  StackLiteDualDrive_B.Switch1 = (int16_T)(rtb_RateLimiter1 < 0.0F ? (int32_T)
    (int16_T)-(int16_T)(uint16_T)-rtb_RateLimiter1 : (int32_T)(int16_T)(uint16_T)
    rtb_RateLimiter1);

  /* Switch: '<S10>/Switch1' incorporates:
   *  Switch: '<S10>/Switch3'
   */
  if (StackLiteDualDrive_B.Add4_e > -30.0F) {
    /* Switch: '<S10>/Switch' */
    if (StackLiteDualDrive_B.Add4_e > 30.0F) {
      /* Switch: '<S10>/Switch2' */
      if (StackLiteDualDrive_B.Switch1 <= 0) {
        /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
         *  Constant: '<S10>/Constant'
         *  Switch: '<S10>/Switch1'
         */
        StackLiteDualDrive_B.Switch1 = 10;
      }

      /* End of Switch: '<S10>/Switch2' */
    }

    /* End of Switch: '<S10>/Switch' */
  } else if (StackLiteDualDrive_B.Switch1 > 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Switch: '<S10>/Switch1'
     *  Switch: '<S10>/Switch3'
     */
    StackLiteDualDrive_B.Switch1 = -10;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  StackLiteDualDrive_B.DataTypeConversion2 = StackLiteDualDrive_B.Switch1;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Gain: '<Root>/Gain'
   */
  StackLiteDualDrive_B.ws2812[0] = (uint8_T)((20972 *
    StackLiteDualDrive_B.angle[0]) >> 21);
  StackLiteDualDrive_B.ws2812[1] = (uint8_T)((20972 *
    StackLiteDualDrive_B.angle[1]) >> 21);
  StackLiteDualDrive_B.ws2812[2] = (uint8_T)((20972 *
    StackLiteDualDrive_B.angle[2]) >> 21);

  /* S-Function (StackLiteDualDrive_DataLinkInput): '<Root>/DataLinkInput' */

  /*Input Data*/
  StackLiteDualDrive_B.DataLinkInput_o1= DataLink_RevData[0].point;
  StackLiteDualDrive_B.DataLinkInput_o2= DataLink_RevData[1].point;
  StackLiteDualDrive_B.DataLinkInput_o3= DataLink_RevData[2].point;
  StackLiteDualDrive_B.DataLinkInput_o4= DataLink_RevData[3].point;
  StackLiteDualDrive_B.DataLinkInput_o5= DataLink_RevData[4].point;
  StackLiteDualDrive_B.DataLinkInput_o6= DataLink_RevData[5].point;
  StackLiteDualDrive_B.DataLinkInput_o7= DataLink_RevData[6].point;
  StackLiteDualDrive_B.DataLinkInput_o8= DataLink_RevData[7].point;
  StackLiteDualDrive_B.DataLinkInput_o9= DataLink_RevData[8].point;
  StackLiteDualDrive_B.DataLinkInput_o10= DataLink_RevData[9].point;

  /* Outputs for Enabled SubSystem: '<Root>/LED Blink' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (rtb_Compare_m) {
    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Delay: '<S5>/Delay1'
     */
    StackLiteDualDrive_B.LogicalOperator = (uint8_T)
      (StackLiteDualDrive_DW.Delay1_DSTATE_j == 0);

    /* Update for Delay: '<S5>/Delay1' */
    StackLiteDualDrive_DW.Delay1_DSTATE_j = StackLiteDualDrive_B.LogicalOperator;
  }

  /* End of Outputs for SubSystem: '<Root>/LED Blink' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Switch: '<S9>/Switch3'
   */
  if (StackLiteDualDrive_B.Add4 > -30.0F) {
    /* Switch: '<S9>/Switch' */
    if (StackLiteDualDrive_B.Add4 > 30.0F) {
      /* Switch: '<S9>/Switch2' */
      if (StackLiteDualDrive_B.Switch1_e <= 0) {
        /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
         *  Constant: '<S9>/Constant'
         *  Switch: '<S9>/Switch1'
         */
        StackLiteDualDrive_B.Switch1_e = 10;
      }

      /* End of Switch: '<S9>/Switch2' */
    }

    /* End of Switch: '<S9>/Switch' */
  } else if (StackLiteDualDrive_B.Switch1_e > 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<S9>/Constant1'
     *  Switch: '<S9>/Switch1'
     *  Switch: '<S9>/Switch3'
     */
    StackLiteDualDrive_B.Switch1_e = -10;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Update for Delay: '<S6>/Delay One Step' */
  StackLiteDualDrive_DW.DelayOneStep_DSTATE = StackLiteDualDrive_B.Add4;

  /* Update for Delay: '<S7>/Delay One Step' */
  StackLiteDualDrive_DW.DelayOneStep_DSTATE_a = StackLiteDualDrive_B.Add4_e;
}

/* Model initialize function */
void StackLiteDualDrive_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Model Initialize function for ModelReference Block: '<Root>/M1_Current_PID' */
  variParaPID_initialize(rtmGetErrorStatusPointer(StackLiteDualDrive_M),
    &(StackLiteDualDrive_DW.M1_Current_PID_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/M2_Current_PID' */
  variParaPID_initialize(rtmGetErrorStatusPointer(StackLiteDualDrive_M),
    &(StackLiteDualDrive_DW.M2_Current_PID_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S8>/Speed_PID' */
  variParaPID_initialize(rtmGetErrorStatusPointer(StackLiteDualDrive_M),
    &(StackLiteDualDrive_DW.Speed_PID_InstanceData.rtm));

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  StackLiteDualDrive_DW.M1_Current_Kp = 5.419F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  StackLiteDualDrive_DW.M1_Current_Ki = 0.1F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  StackLiteDualDrive_DW.M2_Current_Kp = 5.419F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  StackLiteDualDrive_DW.M2_Current_Ki = 0.1F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  StackLiteDualDrive_DW.M1_Current_iLimit = 200.0F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  StackLiteDualDrive_DW.M2_Current_iLimit = 200.0F;

  /* SystemInitialize for Enabled SubSystem: '<Root>/main control' */
  /* Start for DataStoreMemory: '<S8>/Data Store Memory' */
  StackLiteDualDrive_DW.UpRight_Kp = 0.7F;

  /* Start for DataStoreMemory: '<S8>/Data Store Memory2' */
  StackLiteDualDrive_DW.UpRight_Kd = -0.3F;

  /* Start for DataStoreMemory: '<S8>/Data Store Memory3' */
  StackLiteDualDrive_DW.Speed_Kp = -0.045F;

  /* Start for DataStoreMemory: '<S8>/Data Store Memory4' */
  StackLiteDualDrive_DW.Speed_Ki = -0.015F;

  /* Start for DataStoreMemory: '<S8>/Data Store Memory6' */
  StackLiteDualDrive_DW.UpRight_Set = -50.0F;

  /* Start for DataStoreMemory: '<S8>/Data Store Memory9' */
  StackLiteDualDrive_DW.Speed_iLimit = 120.0F;

  /* End of SystemInitialize for SubSystem: '<Root>/main control' */
}

/* Model terminate function */
void StackLiteDualDrive_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
