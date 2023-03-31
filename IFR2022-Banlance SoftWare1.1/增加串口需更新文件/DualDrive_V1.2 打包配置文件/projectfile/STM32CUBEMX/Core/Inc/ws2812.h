#ifndef __WS2812_H__
#define __WS2812_H__

#include "stm32f4xx.h"

#define WS2812_NUMS 30
#define WS2812_SIZE 24*WS2812_NUMS+1	//The last bit is the reset level;	//Another idea is to enable the DMA transfer completion interrupt and set the CCR register to 0 in this interrupt

#define WS2812_GREEN 0
#define WS2812_RED 1
#define WS2812_BLUE 2

#define WS2812BIT_HIGH 14	//The first light will flash if the 1 code high level is set to 13
#define WS2812BIT_LOW 6
extern const uint8_t WS2812BitDef[2];


uint8_t UpdateOneColorToAllBit(uint8_t colors[3],uint16_t dmabuffer[],uint16_t led_nums);
uint8_t UpdateOneColorsToDesignatedBit(uint8_t colors[3],uint8_t designated[], uint16_t dmabuffer[],uint16_t led_nums);
uint8_t UpdateColorsToBit(uint8_t colors[][3],uint16_t dmabuffer[],uint16_t led_nums);
void pwmdma_testinit(uint16_t dma1buffer[],uint16_t dma2buffer[]);

void shift_by_byte(uint8_t bytes[],uint16_t nums,int16_t movestep);
void ColorsRamp(uint8_t tarcolors[][3],uint8_t realcolors[][3],uint8_t rampstep,uint16_t led_nums);

void normal_LightingEffects(void);
void connecting_LightingEffects(void);
void connected_LightingEffects(void);
#endif
