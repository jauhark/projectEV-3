/*
 * w_code.h
 *
 *  Created on: Feb 5, 2022
 *      Author: SHARAFU
 */

#ifndef INC_W_CODE_H_
#define INC_W_CODE_H_


//-------------------------------------------------------------

#include "main.h"
#include "ssd1306.h"
#include "string.h"
#include "stdio.h"

#define Line1 0
#define Line2 12
#define Line3 24
#define Line4 36
#define Line5 52

#define Seg1 0
#define Seg2 60

#define w_FONT1 &(Font_7x10)
#define w_FONT2 &(Font_11x18)

#define w_OLED_MSG_NO 5
#define w_OLED_MSG_LEN 20
#define w_UART_DMA_BUFF_LEN 55
//-------------------------------------------------------------
//-----------------------------OLED_DATA-----------------------

struct {
	char stringData[w_OLED_MSG_LEN];
	FontDef *font;
}w_oledData[w_OLED_MSG_NO];


//-------------------------------------------------------------

char w_uartBuff[w_UART_DMA_BUFF_LEN];
char w_uartParsedData[w_OLED_MSG_LEN];

char w_adcString[10];
uint16_t w_adcVal;

uint32_t w_adcAvg;
uint16_t w_adcDataBuff[10];
char w_adcAvgdString[10];


void w_Initialize();
void w_oledCopyBuffer(char *, uint8_t, FontDef *);
uint8_t w_oledPosIncVal(uint8_t );
char* w_oledParseUartData(char *);
void w_oledPageWrite();
//-------------------------------------------------------------



#endif /* INC_W_CODE_H_ */
