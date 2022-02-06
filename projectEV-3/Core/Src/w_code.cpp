/*
 * w_code.cpp
 *
 *  Created on: Feb 5, 2022
 *      Author: SHARAFU
 */

#include "w_code.h"

uint8_t w_oledYPos[w_OLED_MSG_NO] = { Line1, Line2, Line3, Line4, Line5 };
char w_CLEARBUFF[] = "            ";
//-------------------------------------------------------------
/*
 * function initialising oled buffer struct. this value will be displayed unless
 * changed in program
 */
void w_Initialize() {

	w_oledData[0].font = w_FONT1;
	w_oledData[1].font = w_FONT1;
	w_oledData[2].font = w_FONT1;
	w_oledData[3].font = w_FONT2;
	w_oledData[4].font = w_FONT2;

	strcpy(w_oledData[0].stringData, "Hell-0");
	strcpy(w_oledData[1].stringData, "Hell-1");
	strcpy(w_oledData[2].stringData, "Hell-2");
	strcpy(w_oledData[3].stringData, "Hell-3");
	strcpy(w_oledData[4].stringData, "Hell-4");
	ssd1306_Init();
}

//-------------------------------------------------------------
/*
 * copying the character data to oled buffer struct
 */
void w_oledCopyBuffer(char *data, uint8_t line, FontDef *font) {
	memset(w_oledData[line].stringData, 0, w_OLED_MSG_LEN);
	strcpy(w_oledData[line].stringData, data);
//	sprintf(w_oledData[line].stringData, data);
	w_oledData[line].font = font;
}

char* w_oledParseUartData(char *data) {
	uint8_t uartMsgBegFound = 0;
	uint8_t uartMsgEndFound = 0;
	char tempVar;
	char *dataptr = w_uartParsedData;
	memset(w_uartParsedData, 0, w_OLED_MSG_LEN);
	for (int i = 0; i < w_UART_DMA_BUFF_LEN; i++) {
		if (i != 0)
			data++;
		tempVar = *data;
		if (tempVar == '<' && uartMsgEndFound == 0) {
			uartMsgBegFound = 1;
			continue;
		}
		if (uartMsgBegFound) {
			if (tempVar == '>') {
				uartMsgEndFound = 1;
				return w_uartParsedData;
			}
			*dataptr = tempVar;
			dataptr++;
		}
	}
	return " ERROR ";
}
//-------------------------------------------------------------
/*
 * Writes the data in w_oledData to lines according to its size. Extra data not fitting
 * will be discarded.
 */

void w_oledPageWrite() {
	static uint8_t LineVal = 0;
	ssd1306_SetCursor(0, w_oledYPos[0]);
	ssd1306_WriteString(w_oledData[0].stringData, *(w_oledData[0].font), White);

	for (int i = 1; i < w_OLED_MSG_NO; i++) {
		LineVal += w_oledPosIncVal(i);
		if (LineVal >= w_OLED_MSG_NO)
			break;
		ssd1306_SetCursor(0, w_oledYPos[LineVal]);
		ssd1306_WriteString(w_oledData[i].stringData, *(w_oledData[i].font),
				White);
	}

	ssd1306_UpdateScreen();

	LineVal = 0;

	ssd1306_SetCursor(0, w_oledYPos[0]);
	ssd1306_WriteString(w_CLEARBUFF, *(w_oledData[0].font), White);

	for (int i = 1; i < w_OLED_MSG_NO; i++) {
		LineVal += w_oledPosIncVal(i);
		if (LineVal >= w_OLED_MSG_NO)
			break;
		ssd1306_SetCursor(0, w_oledYPos[LineVal]);
		ssd1306_WriteString(w_CLEARBUFF, *(w_oledData[i].font), White);
	}

	LineVal = 0;
}

//-------------------------------------------------------------
/*
 * function returning the value to be incremented in Line position according
 * to size taken by previous line in oled.
 */
uint8_t w_oledPosIncVal(uint8_t i) {
	if (w_oledData[i - 1].font == w_FONT1)
		return 1;
	else if (w_oledData[i - 1].font == w_FONT2)
		return 2;
	return 2;
}

//-------------------------------------------------------------
