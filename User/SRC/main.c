/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V2.0.1
* Date               : 06/13/2008
* Description        : Main program body
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
//#include "stm32f10x_lib.h"
#define root
#include "config.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


SZ_TypeDef SZ1[]=
	{
																			   "0",
	0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,/*"0",0*/
																			   "1",
	0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,/*"1",1*/
																			   "2",
	0x00,0x70,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00,/*"2",2*/
																			   "3",
	0x00,0x30,0x08,0x88,0x88,0x48,0x30,0x00,0x00,0x18,0x20,0x20,0x20,0x11,0x0E,0x00,/*"3",3*/
																			   "4",
	0x00,0x00,0xC0,0x20,0x10,0xF8,0x00,0x00,0x00,0x07,0x04,0x24,0x24,0x3F,0x24,0x00,/*"4",4*/
																			   "5",
	0x00,0xF8,0x08,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x21,0x20,0x20,0x11,0x0E,0x00,/*"5",5*/
																			   "6",
	0x00,0xE0,0x10,0x88,0x88,0x18,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x11,0x0E,0x00,/*"6",6*/
																			   "7",
	0x00,0x38,0x08,0x08,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,/*"7",7*/
																			   "8",
	0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00,/*"8",8*/
																			   "9",
	0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x31,0x22,0x22,0x11,0x0F,0x00,/*"9",9*/
																			   " ",
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*" ",10*/
																			   "a",
	0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x19,0x24,0x22,0x22,0x22,0x3F,0x20,/*"a",11*/
																			   "b",
	0x08,0xF8,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00,/*"b",12*/
																			   "c",
	0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00,/*"c",13*/
																			   "d",
	0x00,0x00,0x00,0x80,0x80,0x88,0xF8,0x00,0x00,0x0E,0x11,0x20,0x20,0x10,0x3F,0x20,/*"d",14*/
																			   "e",
	0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x22,0x13,0x00,/*"e",15*/
																			   "f",
	0x00,0x80,0x80,0xF0,0x88,0x88,0x88,0x18,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,/*"f",16*/
																			   "g",
	0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00,/*"g",17*/
																			   "h",
	0x08,0xF8,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,/*"h",18*/
																			   "i",
	0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,/*"i",19*/
																			   "j",
	0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,/*"j",20*/
																			   "k",
	0x08,0xF8,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x02,0x2D,0x30,0x20,0x00,/*"k",21*/
																			   "l",
	0x00,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,/*"l",22*/
																			   "m",
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F,/*"m",23*/
																			   "n",
	0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,/*"n",24*/
																			   "o",
	0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,/*"o",25*/
																			   "p",
	0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0xA1,0x20,0x20,0x11,0x0E,0x00,/*"p",26*/
																			   "q",
	0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0xA0,0xFF,0x80,/*"q",27*/
																			   "r",
	0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00,/*"r",28*/
																			   "s",
	0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00,/*"s",29*/
																			   "t",
	0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x00,0x00,/*"t",30*/
																			   "u",
	0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20,/*"u",31*/
																			   "v",
	0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x01,0x0E,0x30,0x08,0x06,0x01,0x00,/*"v",32*/
																			   "w",
	0x80,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x0F,0x30,0x0C,0x03,0x0C,0x30,0x0F,0x00,/*"w",33*/
																			   "x",
	0x00,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x31,0x2E,0x0E,0x31,0x20,0x00,/*"x",34*/
																			   "y",
	0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x81,0x8E,0x70,0x18,0x06,0x01,0x00,/*"y",35*/
																			   "z",
	0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00,/*"z",36*/
																			   "A",
	0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20,/*"A",37*/
																			   "B",
	0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00,/*"B",38*/
																			   "C",
	0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00,/*"C",39*/
																			   "D",
	0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00,/*"D",40*/
																			   "E",
	0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00,/*"E",41*/
																			   "F",
	0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00,/*"F",42*/
																			   "G",
	0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00,/*"G",43*/
																			   "H",
	0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20,/*"H",44*/
																			   "I",
	0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,/*"I",45*/
																			   "J",
	0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00,/*"J",46*/
																			   "K",
	0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00,/*"K",47*/
																			   "L",
	0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00,/*"L",48*/
																			   "M",
	0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x00,0x3F,0x00,0x3F,0x20,0x00,/*"M",49*/
																			   "N",
	0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00,/*"N",50*/
																			   "O",
	0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00,/*"O",51*/
																			   "P",
	0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00,/*"P",52*/
																			   "Q",
	0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x18,0x24,0x24,0x38,0x50,0x4F,0x00,/*"Q",53*/
																			   "R",
	0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20,/*"R",54*/
																			   "S",
	0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00,/*"S",55*/
																			   "T",
	0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,/*"T",56*/
																			   "U",
	0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,/*"U",57*/
																			   "V",
	0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00,/*"V",58*/
																			   "W",
	0xF8,0x08,0x00,0xF8,0x00,0x08,0xF8,0x00,0x03,0x3C,0x07,0x00,0x07,0x3C,0x03,0x00,/*"W",59*/
																			   "X",
	0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20,/*"X",60*/
																			   "Y",
	0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,/*"Y",61*/
																			   "Z",
	0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00,/*"Z",62*/
																			   ":",
	0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,/*":",63*/
																			   "!",
	0x00,0x00,0x00,0xF8,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x33,0x00,0x00,0x00,/*"!",64*/
																			   "(",
	0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00,/*"(",65*/
																			   ")",
	0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00,/*")",66*/
																			   "*",
	0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00,/*"*",67*/
																			   "-",
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,/*"-",68*/
																			   "+",
	0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x1F,0x01,0x01,0x01,0x00,/*"+",69*/
																			   "=",
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00,/*"=",70*/
																			   "\\",
	0x00,0x0C,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00,/*"\",71*/
																		   	    "/",
	0x00,0x00,0x00,0x00,0x80,0x60,0x18,0x04,0x00,0x60,0x18,0x06,0x01,0x00,0x00,0x00,/*"/",72*/
																				".",
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,/*".",73*/
																				"%",
	0xF0,0x08,0xF0,0x00,0xE0,0x18,0x00,0x00,0x00,0x21,0x1C,0x03,0x1E,0x21,0x1E,0x00,/*"%",74*/
	};



HZ_TypeDef HZ1[]=
	{
																		       "成",	
	0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,
	0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,
//	0x00,0x00,0xF8,0x48,0x48,0x48,0xC8,0x08,0xFF,0x08,0x09,0x0A,0xC8,0x88,0x08,0x00,
//	0x40,0x30,0x0F,0x00,0x08,0x50,0x4F,0x20,0x10,0x0B,0x0C,0x12,0x21,0x40,0xF0,0x00,/*"成",0*/
																		   	   "都",
	0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,
	0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,

//	0x20,0x24,0x24,0xA4,0x7F,0x24,0x34,0x28,0x24,0x00,0xFE,0x22,0x52,0x8A,0x06,0x00,
//	0x04,0x02,0x7F,0x25,0x25,0x25,0x25,0x7F,0x00,0x00,0xFF,0x08,0x08,0x10,0x0F,0x00,/*"都",1*/
	   																	   	   "博",
	0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
	0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
//	0x20,0x20,0xFF,0x20,0x20,0x04,0xF4,0x54,0x54,0xFF,0x54,0x55,0xF6,0x04,0x00,0x00,
//	0x00,0x00,0xFF,0x00,0x04,0x04,0x0F,0x35,0x15,0x47,0x85,0x7F,0x07,0x04,0x04,0x00,/*"博",2*/
																			   "高",
	0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
	0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
//	0x04,0x04,0x04,0x04,0x74,0x54,0x55,0x56,0x54,0x54,0x74,0x04,0x04,0x04,0x04,0x00,
//	0x00,0xFF,0x01,0x01,0x3D,0x25,0x25,0x25,0x25,0x25,0x3D,0x41,0x81,0x7F,0x00,0x00,/*"高",3*/
																			   "科",
	0x10,0x12,0x92,0x72,0xFE,0x51,0x91,0x00,0x22,0xCC,0x00,0x00,0xFF,0x00,0x00,0x00,
	0x04,0x02,0x01,0x00,0xFF,0x00,0x04,0x04,0x04,0x02,0x02,0x02,0xFF,0x01,0x01,0x00,/*"科",4*/
																			   "技",
	0x08,0x08,0x88,0xFF,0x48,0x28,0x00,0xC8,0x48,0x48,0x7F,0x48,0xC8,0x48,0x08,0x00,
	0x01,0x41,0x80,0x7F,0x00,0x40,0x40,0x20,0x13,0x0C,0x0C,0x12,0x21,0x60,0x20,0x00,/*"技",5*/
																			   "本",
	0x08,0x08,0x08,0x08,0x08,0xC8,0x38,0xFF,0x18,0x68,0x88,0x08,0x08,0x08,0x08,0x00,
	0x08,0x08,0x04,0x02,0x05,0x04,0x04,0x7F,0x04,0x04,0x04,0x03,0x06,0x0C,0x04,0x00,/*"本",6*/
																			   "机",
	0x08,0x08,0xC8,0xFF,0x48,0x88,0x08,0x00,0xFE,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,
	0x04,0x03,0x00,0xFF,0x00,0x41,0x30,0x0C,0x03,0x00,0x00,0x00,0x3F,0x40,0x78,0x00,/*"机",7*/
																			   "透",
	0x40,0x42,0xCC,0x00,0x48,0x4A,0xEA,0x5A,0x7E,0xD9,0x59,0x29,0x49,0x48,0x00,0x00,
	0x40,0x20,0x1F,0x20,0x48,0x46,0x41,0x40,0x40,0x41,0x49,0x51,0x4F,0x40,0x00,0x00,/*"透",8*/
																			   "支",
	0x00,0x08,0x08,0x48,0xC8,0x48,0x48,0x7F,0x48,0x48,0x48,0xC8,0x48,0x08,0x08,0x00,
	0x00,0x40,0x40,0x40,0x20,0x23,0x14,0x08,0x08,0x14,0x23,0x20,0x40,0xC0,0x40,0x00,/*"支",9*/
																			   "阶",
	0x00,0xFF,0x11,0x29,0xC5,0x43,0x20,0xD0,0x0C,0x03,0x04,0xC8,0x10,0x20,0x20,0x00,
	0x00,0xFF,0x02,0x04,0x03,0x40,0x30,0x0F,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,/*"阶",10*/
																			   "梯",
	0x08,0x88,0x68,0xFF,0x28,0x40,0xC8,0x49,0x4E,0xF8,0x4C,0x4A,0x49,0x78,0x00,0x00,
	0x02,0x01,0x00,0xFF,0x00,0x20,0x13,0x0A,0x06,0xFF,0x02,0x02,0x12,0x22,0x1E,0x00,/*"梯",11*/
																			   "总",
	0x00,0x00,0x00,0xF8,0x89,0x8E,0x88,0x88,0x88,0x8C,0x8B,0xF8,0x00,0x00,0x00,0x00,
	0x00,0x20,0x38,0x00,0x3C,0x40,0x40,0x42,0x4C,0x40,0x40,0x70,0x04,0x18,0x30,0x00,/*"总",12*/
																			   "尖",
	0x40,0x20,0x10,0x0E,0x04,0x20,0x40,0xBF,0x00,0x02,0x04,0x08,0x18,0x30,0x00,0x00,
	0x02,0x82,0x82,0x42,0x22,0x12,0x0E,0x03,0x06,0x0A,0x12,0x22,0x62,0xC2,0x42,0x00,/*"尖",13*/
																			   "峰",
	0xF8,0x00,0xFF,0x00,0xF8,0x20,0x90,0x88,0x4F,0xD2,0x22,0x52,0xCE,0x42,0x00,0x00,
	0x1F,0x08,0x0F,0x04,0x0F,0x20,0x2A,0x2A,0x2A,0xFF,0x2A,0x2A,0x2A,0x2A,0x20,0x00,/*"峰",14*/
																			   "平",
	0x00,0x01,0x05,0x09,0x71,0x21,0x01,0xFF,0x01,0x41,0x21,0x1D,0x09,0x01,0x00,0x00,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,/*"平",15*/
																			   "谷",
	0x00,0x10,0x08,0x04,0x87,0x42,0x20,0x1C,0x20,0x41,0x82,0x04,0x0C,0x00,0x00,0x00,
	0x04,0x04,0x02,0x01,0x7E,0x22,0x22,0x22,0x22,0x22,0x22,0x7F,0x01,0x06,0x02,0x00,/*"谷",16*/
																			   "费",
	0x00,0x00,0x3A,0x2A,0xAA,0x6A,0x3F,0x2A,0x2A,0xFF,0x2A,0x2A,0xAE,0x20,0xE0,0x00,
	0x00,0x02,0x82,0x81,0x5F,0x41,0x21,0x1D,0x21,0x21,0x41,0xDF,0x40,0x01,0x00,0x00,/*"费",17*/
																			   "率",
	0x00,0x0C,0x14,0xA4,0x04,0x64,0x35,0xAE,0x64,0x24,0x14,0xA4,0x14,0x04,0x04,0x00,
	0x08,0x0A,0x09,0x08,0x08,0x0A,0x0B,0xFE,0x0A,0x0B,0x0C,0x08,0x09,0x0A,0x08,0x00,/*"率",18*/
																			   "电",
	0x00,0x00,0xF8,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xF8,0x00,0x00,0x00,
	0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0x3F,0x44,0x44,0x44,0x44,0x4F,0x40,0x70,0x00,/*"电",19*/
																			   "价",
	0x40,0x20,0xF0,0x1C,0x47,0x22,0x10,0xC8,0x04,0x03,0x04,0xD8,0x30,0x60,0x20,0x00,
	0x00,0x00,0xFF,0x00,0x80,0x60,0x18,0x07,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,/*"价",20*/
																			   "当",
	0x00,0x00,0x40,0x42,0x5C,0x48,0x40,0x40,0x7F,0x40,0x50,0x4E,0x44,0xC0,0x00,0x00,
	0x00,0x00,0x20,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x7F,0x00,0x00,/*"当",21*/
																			   "前",
	0x08,0x08,0xE8,0xA8,0xA9,0xAE,0xEA,0x08,0x08,0xC8,0x0C,0x0B,0xEA,0x08,0x08,0x00,
	0x00,0x00,0x7F,0x04,0x24,0x44,0x3F,0x00,0x00,0x1F,0x40,0x80,0x7F,0x00,0x00,0x00,/*"前",22*/
																			   "正",
	0x00,0x02,0x02,0xC2,0x02,0x02,0x02,0x02,0xFE,0x82,0x82,0x82,0x82,0x82,0x02,0x00,
	0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x20,0x20,0x00,/*"正",23*/
																			   "向",
	0x00,0x00,0xFC,0x04,0x04,0xE6,0x25,0x24,0x24,0x24,0xE4,0x04,0x04,0xFC,0x00,0x00,
	0x00,0x00,0x7F,0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0x0F,0x20,0x40,0x3F,0x00,0x00,/*"向",24*/
																			   "有",
	0x00,0x04,0x84,0x44,0xE4,0x34,0x2C,0x27,0x24,0x24,0x24,0xE4,0x04,0x04,0x04,0x00,
	0x02,0x01,0x00,0x00,0xFF,0x09,0x09,0x09,0x29,0x49,0xC9,0x7F,0x00,0x00,0x00,0x00,/*"有",25*/
																			   "功",
	0x00,0x04,0x04,0x04,0xFC,0x04,0x14,0x14,0x10,0x90,0x7F,0x10,0x10,0xF0,0x00,0x00,
	0x04,0x0C,0x04,0x04,0x03,0x42,0x22,0x11,0x0C,0x23,0x20,0x60,0x20,0x1F,0x00,0x00,/*"功",26*/
																			   "示",
	0x00,0x20,0x20,0x22,0x22,0x22,0x22,0xE2,0x22,0x22,0x22,0x22,0x22,0x20,0x20,0x00,
	0x10,0x08,0x04,0x03,0x00,0x40,0x80,0x7F,0x00,0x00,0x01,0x02,0x0C,0x18,0x00,0x00,/*"示",27*/
																			   "数",
	0x10,0x92,0x54,0x38,0xFF,0x38,0x54,0x52,0x80,0xF0,0x1F,0x12,0x10,0xF0,0x10,0x00,
	0x42,0x42,0x2A,0x2E,0x13,0x1A,0x26,0x02,0x40,0x20,0x13,0x0C,0x33,0x60,0x20,0x00,/*"数",28*/
																			   "剩",
	0x08,0x2A,0xAA,0xFA,0x0A,0xFE,0x09,0xF9,0x49,0xA8,0x00,0xF8,0x00,0x00,0xFF,0x00,
	0x21,0x11,0x08,0x05,0x02,0x7F,0x02,0x04,0x19,0x09,0x00,0x07,0x20,0x40,0x3F,0x00,/*"剩",29*/
																			   "余",
	0x40,0x40,0x20,0x20,0x30,0x28,0x24,0xE3,0x24,0x28,0x28,0x30,0x20,0x60,0x20,0x00,
	0x00,0x40,0x21,0x1D,0x09,0x41,0x81,0x7F,0x01,0x05,0x09,0x39,0x11,0x01,0x00,0x00,/*"余",30*/
																			   "量",
	0x40,0x40,0x40,0xDF,0x55,0x55,0x55,0xD5,0x55,0x55,0x55,0xDF,0x40,0x40,0x40,0x00,
	0x40,0x40,0x40,0x57,0x55,0x55,0x55,0x7F,0x55,0x55,0x55,0x57,0x50,0x40,0x40,0x00,/*"量",31*/
																			   "金",
	0x40,0x40,0x20,0x20,0x50,0x48,0x44,0xC3,0x44,0x48,0x50,0x50,0x20,0x60,0x20,0x00,
	0x40,0x40,0x42,0x42,0x4A,0x72,0x42,0x7F,0x42,0x62,0x5A,0x42,0x42,0x40,0x40,0x00,/*"金",32*/
																			   "额",
	0x00,0x4C,0x24,0x5D,0x96,0xD4,0x34,0x0C,0xF6,0x12,0x1A,0x96,0x12,0x12,0xF2,0x00,
	0x04,0x04,0x7E,0x23,0x22,0x22,0x3F,0x40,0x4F,0x20,0x18,0x07,0x08,0x10,0x6F,0x00,/*"额",33*/
																			   "购",
	0x00,0xFE,0x02,0xFA,0x02,0xFE,0x40,0x30,0x0F,0xCA,0x08,0x08,0x08,0x08,0xF8,0x00,
	0x40,0x23,0x18,0x07,0x08,0x33,0x00,0x06,0x05,0x04,0x05,0x4E,0x84,0x40,0x3F,0x00,/*"购",34*/
																			   "次",
	0x00,0x02,0x1C,0xC0,0x30,0x4C,0x30,0x0F,0x08,0xF8,0x08,0x08,0x28,0x18,0x08,0x00,
	0x02,0x5E,0x43,0x20,0x20,0x10,0x08,0x04,0x03,0x01,0x06,0x08,0x30,0x60,0x20,0x00,/*"次",35*/
																			   "累",
	0x00,0x00,0x00,0x1F,0x95,0xD5,0xB5,0x9F,0x95,0x95,0x55,0x15,0x1F,0x00,0x00,0x00,
	0x00,0x00,0x00,0x40,0x34,0x06,0x46,0x85,0x7C,0x04,0x15,0x26,0x6C,0x00,0x00,0x00,/*"累",36*/
																			   "计",
	0x20,0x21,0x2E,0xE4,0x00,0x00,0x20,0x20,0x20,0x20,0xFF,0x20,0x20,0x20,0x20,0x00,
	0x00,0x00,0x00,0x7F,0x20,0x10,0x08,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,/*"计",37*/
																			   "结",
	0x20,0x30,0xAC,0x63,0x10,0x00,0x08,0x48,0x48,0x48,0x7F,0x48,0x48,0x48,0x08,0x00,
	0x22,0x23,0x22,0x12,0x12,0x00,0x00,0x7E,0x22,0x22,0x22,0x22,0x22,0x7E,0x00,0x00,/*"结",38*/
																			   "算",
	0x08,0x07,0xFA,0xAA,0xAE,0xAA,0xAA,0xA8,0xAC,0xAB,0xAA,0xFE,0x0A,0x02,0x02,0x00,
	0x08,0x08,0x8B,0x6A,0x1E,0x0A,0x0A,0x0A,0x0A,0xFE,0x0A,0x0B,0x08,0x08,0x08,0x00,/*"算",39*/
																			   "周",
	0x00,0x00,0x00,0xFE,0x02,0x42,0x4A,0x4A,0x7E,0x4A,0x4A,0x42,0x02,0xFE,0x00,0x00,
	0x80,0x40,0x30,0x0F,0x00,0x00,0x1F,0x09,0x09,0x09,0x1F,0x40,0x80,0x7F,0x00,0x00,/*"周",40*/
																			   "期",
	0x00,0x04,0xFF,0x54,0x54,0x54,0xFF,0x04,0x00,0xFE,0x22,0x22,0x22,0xFE,0x00,0x00,
	0x42,0x22,0x1B,0x02,0x02,0x0A,0x33,0x62,0x18,0x07,0x02,0x22,0x42,0x3F,0x00,0x00,/*"期",41*/
																			   "用",
	0x00,0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0xFE,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,
	0x80,0x40,0x30,0x0F,0x02,0x02,0x02,0x02,0xFF,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,/*"用",42*/
																			   "表",
	0x00,0x40,0x44,0x54,0x54,0x54,0xD4,0xFF,0x54,0x54,0x54,0x54,0x54,0x44,0x40,0x00,
	0x08,0x08,0x04,0x04,0xFE,0x43,0x21,0x10,0x03,0x04,0x08,0x14,0x23,0x62,0x20,0x00,/*"表",43*/
																			   "地",
	0x10,0x10,0x10,0xFE,0x10,0x50,0x40,0xFE,0x20,0x20,0xFF,0x10,0x10,0xF8,0x10,0x00,
	0x20,0x20,0x10,0x1F,0x08,0x08,0x00,0x3F,0x40,0x40,0x4F,0x42,0x44,0x43,0x70,0x00,/*"地",44*/
																			   "址",
	0x20,0x20,0x20,0xFE,0x20,0x20,0x00,0xE0,0x00,0x00,0xFF,0x40,0x40,0x40,0x00,0x00,
	0x10,0x30,0x10,0x1F,0x08,0x28,0x20,0x3F,0x20,0x20,0x3F,0x20,0x20,0x30,0x20,0x00,/*"址",45*/
																			   "元",
	0x00,0x20,0x20,0x22,0x22,0xE2,0x22,0x22,0x22,0xE2,0x22,0x22,0x22,0x20,0x20,0x00,
	0x00,0x40,0x20,0x10,0x0C,0x03,0x00,0x00,0x00,0x3F,0x40,0x40,0x40,0x40,0x70,0x00,/*"元",46*/
																			   "未",
	0x40,0x40,0x48,0x48,0x48,0x48,0xC8,0xFF,0x48,0x48,0x48,0x48,0x48,0x40,0x40,0x00,
	0x20,0x20,0x10,0x10,0x08,0x06,0x01,0xFF,0x01,0x02,0x04,0x08,0x18,0x30,0x10,0x00,/*"未",47*/
																			   "校",
	0x08,0x88,0x68,0xFF,0x28,0x48,0x00,0x88,0x68,0x09,0x0E,0x08,0xA8,0x48,0x88,0x00,
	0x02,0x01,0x00,0xFF,0x00,0x40,0x42,0x21,0x26,0x18,0x18,0x26,0x61,0xC0,0x40,0x00,/*"校",48*/
																			   "时",
	0x00,0xFC,0x44,0x44,0x44,0xFC,0x10,0x90,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00,
	0x00,0x07,0x04,0x04,0x04,0x07,0x00,0x00,0x03,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,/*"时",49*/
																			   "据",
	0x08,0x08,0x08,0xFF,0x88,0x40,0xFE,0x92,0x92,0x92,0xF2,0x92,0x92,0x9E,0x80,0x00,
	0x02,0x42,0x81,0x7F,0x40,0x30,0x0F,0xFC,0x44,0x44,0x47,0x44,0x44,0xFC,0x00,0x00,/*"据",50*/
																			   "更",
	0x00,0x02,0x02,0xFA,0x2A,0x2A,0x2A,0xFE,0x2A,0x2A,0x2A,0x2A,0xFA,0x02,0x02,0x00,
	0x40,0x40,0x40,0x21,0x23,0x15,0x09,0x17,0x11,0x21,0x21,0x41,0xC1,0x40,0x40,0x00,/*"更",51*/
																			   "新",
	0x20,0x24,0x2C,0x35,0xE6,0x34,0x2C,0x24,0x00,0xFC,0x24,0x24,0xE2,0x22,0x22,0x00,
	0x21,0x11,0x4D,0x81,0x7F,0x05,0x59,0x21,0x18,0x07,0x00,0x00,0xFF,0x00,0x00,0x00,/*"新",52*/
																			   "间",
	0x00,0xF8,0x01,0x06,0x00,0xF0,0x92,0x92,0x92,0x92,0xF2,0x02,0x02,0xFE,0x00,0x00,
	0x00,0xFF,0x00,0x00,0x00,0x07,0x04,0x04,0x04,0x04,0x07,0x40,0x80,0x7F,0x00,0x00,/*"间",53*/
																			   "日",
	0x00,0x00,0x00,0xFE,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0xFE,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3F,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x3F,0x00,0x00,0x00,0x00,/*"日",54*/
																			   "月",
	0x00,0x00,0x00,0x00,0x00,0xFF,0x11,0x11,0x11,0x11,0x11,0xFF,0x00,0x00,0x00,0x00,
	0x00,0x40,0x20,0x10,0x0C,0x03,0x01,0x01,0x01,0x21,0x41,0x3F,0x00,0x00,0x00,0x00,/*"月",55*/
																			   "号",
	0x40,0x40,0x40,0x5F,0xD1,0x51,0x51,0x51,0x51,0x51,0x51,0x5F,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x02,0x07,0x02,0x02,0x22,0x42,0x82,0x42,0x3E,0x00,0x00,0x00,0x00,/*"号",56*/
																			   "最",
	0x40,0x40,0xC0,0x5F,0x55,0x55,0xD5,0x55,0x55,0x55,0x55,0x5F,0x40,0x40,0x40,0x00,
	0x20,0x20,0x3F,0x15,0x15,0x15,0xFF,0x48,0x23,0x15,0x09,0x15,0x23,0x61,0x20,0x00,/*"最",57*/
																			   "近",
	0x40,0x41,0xCE,0x04,0x00,0x00,0xFC,0x24,0x24,0x24,0xE2,0x22,0x22,0x22,0x20,0x00,
	0x40,0x20,0x1F,0x20,0x40,0x50,0x4F,0x40,0x40,0x40,0x5F,0x40,0x40,0x40,0x40,0x00,/*"近",58*/
																			   "查",
	0x80,0x88,0x48,0xC8,0xA8,0x98,0x88,0xFF,0x88,0x98,0xA8,0xA8,0x48,0xC8,0x48,0x00,
	0x00,0x40,0x40,0x5F,0x52,0x52,0x52,0x52,0x52,0x52,0x52,0x5F,0x40,0x40,0x40,0x00,/*"查",59*/
																			   "询",
	0x40,0x42,0xCC,0x04,0x00,0x10,0xE8,0x27,0x24,0x24,0xE4,0x04,0x04,0xFC,0x00,0x00,
	0x00,0x00,0x7F,0x20,0x10,0x00,0x1F,0x09,0x09,0x09,0x1F,0x40,0x80,0x7F,0x00,0x00,/*"询",60*/
																			   "终",
	0x20,0x30,0xAC,0x63,0x18,0x00,0x20,0x18,0x17,0xA4,0x44,0xA4,0x1C,0x04,0x00,0x00,
	0x22,0x23,0x22,0x12,0x12,0x00,0x02,0x02,0x01,0x12,0x24,0x6C,0xC1,0x02,0x02,0x00,/*"终",61*/
																			   "端",
	0x50,0x91,0x16,0x10,0xF0,0x10,0x40,0x5E,0x50,0x50,0xDF,0x50,0x50,0x5E,0x40,0x00,
	0x10,0x13,0x10,0x0F,0x08,0x08,0xFF,0x01,0x01,0x3F,0x01,0x3F,0x41,0x81,0x7F,0x00,/*"端",62*/
																			   "欢",
	0x14,0x24,0x44,0x84,0x64,0x1C,0x20,0x18,0x0F,0xE8,0x08,0x08,0x28,0x18,0x08,0x00,
	0x20,0x10,0x4C,0x43,0x43,0x2C,0x20,0x10,0x0C,0x03,0x06,0x18,0x30,0x60,0x20,0x00,/*"欢",63*/
																			   "迎",
	0x40,0x41,0xCE,0x04,0x00,0xFC,0x04,0x02,0x02,0xFC,0x04,0x04,0x04,0xFC,0x00,0x00,
	0x40,0x20,0x1F,0x20,0x40,0x47,0x42,0x41,0x40,0x5F,0x40,0x42,0x44,0x43,0x40,0x00,/*"迎",64*/
																			   "使",
	0x40,0x20,0xF0,0x1C,0x07,0xF2,0x94,0x94,0x94,0xFF,0x94,0x94,0x94,0xF4,0x04,0x00,
	0x00,0x00,0x7F,0x00,0x40,0x41,0x22,0x14,0x0C,0x13,0x10,0x30,0x20,0x61,0x20,0x00,/*"使",65*/
																			   "请",
	0x40,0x42,0x4C,0xC4,0x00,0x22,0xAA,0xAA,0xAA,0xBF,0xAA,0xAA,0xAA,0x22,0x20,0x00,
	0x00,0x00,0x00,0x7F,0x20,0x10,0xFF,0x0A,0x0A,0x0A,0x4A,0x8A,0x7F,0x00,0x00,0x00,/*"请",66*/	
																			   "插",
	0x08,0x08,0x08,0xFF,0x88,0x48,0x92,0x92,0x52,0x12,0xFE,0x11,0x91,0x91,0x90,0x00,
	0x02,0x42,0x81,0x7F,0x00,0x00,0x7F,0x24,0x24,0x20,0x3F,0x20,0x24,0x24,0x7F,0x00,/*"插",67*/
																			   "入",
	0x00,0x00,0x00,0x00,0x01,0x83,0x76,0x18,0x60,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x40,0x20,0x10,0x08,0x06,0x01,0x00,0x00,0x00,0x00,0x03,0x04,0x18,0x30,0x10,0x00,/*"入",68*/
																			   "卡",
	0x00,0x40,0x40,0x40,0x40,0x40,0x40,0xFF,0x44,0x44,0x44,0x44,0x44,0x44,0x40,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x02,0x04,0x0C,0x38,0x10,0x00,0x00,/*"卡",69*/
																			   "温",
	0x10,0x21,0x86,0x70,0x00,0x7E,0x4A,0x4A,0x4A,0x4A,0x4A,0x7E,0x00,0x00,0x00,0x00,
	0x02,0xFE,0x01,0x40,0x7F,0x41,0x41,0x7F,0x41,0x41,0x7F,0x41,0x41,0x7F,0x40,0x00,/*"温",70*/
																			   "湿",
	0x10,0x60,0x02,0xCC,0x00,0x00,0x3E,0x2A,0xAA,0x2A,0xAA,0x2A,0x3E,0x00,0x00,0x00,
	0x08,0x08,0xFE,0x01,0x40,0x42,0x4C,0x40,0x7F,0x40,0x7F,0x48,0x44,0x42,0x40,0x00,/*"湿",71*/
																			   "度",
	0x00,0x00,0xFC,0x04,0x24,0x24,0xFC,0xA5,0xA6,0xA4,0xFC,0x24,0x24,0x24,0x04,0x00,
	0x80,0x60,0x1F,0x80,0x80,0x42,0x46,0x2A,0x12,0x12,0x2A,0x26,0x42,0xC0,0x40,0x00,/*"度",72*/
																			   "相",
	0x10,0x10,0xD0,0xFF,0x30,0x50,0x90,0x00,0xFE,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,
	0x04,0x03,0x00,0xFF,0x00,0x00,0x01,0x00,0xFF,0x42,0x42,0x42,0x42,0xFF,0x00,0x00,/*"相",73*/
																			   "对",
	0x00,0x24,0x44,0x84,0x84,0x7C,0x00,0x90,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00,
	0x20,0x10,0x0C,0x02,0x01,0x06,0x18,0x00,0x07,0x42,0x80,0x7F,0x00,0x00,0x00,0x00,/*"对",74*/
																			   "读",
	0x40,0x42,0xCC,0x04,0x00,0x50,0x94,0x34,0xD4,0x1F,0xD4,0x14,0x54,0x34,0x10,0x00,
	0x00,0x00,0x7F,0x20,0x10,0x82,0x43,0x22,0x12,0x0A,0x07,0x0A,0x12,0xE2,0x42,0x00,/*"读",75*/
																			   "中",
	0x00,0x00,0xFC,0x08,0x08,0x08,0x08,0xFF,0x08,0x08,0x08,0x08,0xFC,0x08,0x00,0x00,
	0x00,0x00,0x07,0x02,0x02,0x02,0x02,0xFF,0x02,0x02,0x02,0x02,0x07,0x00,0x00,0x00,/*"中",76*/
																			   "在",
	0x00,0x04,0x04,0xC4,0x64,0x9C,0x87,0x84,0x84,0xE4,0x84,0x84,0x84,0x84,0x04,0x00,
	0x04,0x02,0x01,0x7F,0x00,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x20,0x00,/*"在",77*/
																			   "重",
	0x08,0x08,0x0A,0xEA,0xAA,0xAA,0xAA,0xFF,0xA9,0xA9,0xA9,0xE9,0x08,0x08,0x08,0x00,
	0x40,0x40,0x48,0x4B,0x4A,0x4A,0x4A,0x7F,0x4A,0x4A,0x4A,0x4B,0x48,0x40,0x40,0x00,/*"重",78*/
																			   "启",
	0x00,0x00,0x00,0xF8,0x48,0x48,0x48,0x49,0x4E,0x4A,0x48,0x48,0x48,0x78,0x00,0x00,
	0x40,0x20,0x18,0x07,0x00,0x7E,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x7E,0x00,0x00,/*"启",79*/	
																			   "获",
	0x02,0x12,0xA2,0x42,0xA2,0x9F,0x82,0x82,0x82,0xEF,0x82,0xA2,0xC2,0x82,0x82,0x00,
	0x12,0x09,0x44,0x82,0x7F,0x80,0x40,0x30,0x0C,0x03,0x04,0x18,0x30,0x60,0x20,0x00,/*"获",80*/
																			   "取",
	0x02,0x02,0xFE,0x92,0x92,0x92,0xFE,0x02,0x02,0x7C,0x84,0x04,0x84,0x7C,0x04,0x00,
	0x10,0x10,0x0F,0x08,0x08,0x04,0xFF,0x04,0x22,0x10,0x09,0x06,0x09,0x30,0x10,0x00,/*"取",81*/
																			   "以",
	0x00,0x00,0xFE,0x00,0x00,0x02,0x1C,0x88,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,
	0x00,0x08,0x1F,0x0C,0x06,0x42,0x41,0x20,0x10,0x18,0x0E,0x07,0x08,0x30,0x60,0x20,/*"以",82*/
																			   "便",
	0x40,0x20,0xF0,0x1C,0x07,0xFA,0x2A,0x2A,0x2A,0xFE,0x2A,0x2A,0x2A,0xFA,0x02,0x00,
	0x00,0x00,0xFF,0x00,0x80,0x83,0x45,0x29,0x19,0x17,0x21,0x21,0x41,0xC1,0x40,0x00,/*"便",83*/
																			   "同",
	0x00,0xFE,0x02,0x12,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x12,0x02,0xFE,0x00,0x00,
	0x00,0xFF,0x00,0x00,0x1F,0x08,0x08,0x08,0x08,0x08,0x1F,0x40,0x80,0x7F,0x00,0x00,/*"同",84*/
																			   "步",
	0x00,0x20,0x20,0x20,0xBC,0x20,0x20,0x20,0xFF,0x24,0x24,0x24,0x24,0x20,0x20,0x00,
	0x00,0x44,0x44,0x42,0x41,0x20,0x20,0x20,0x17,0x10,0x08,0x04,0x03,0x02,0x00,0x00,/*"步",85*/
																			   "谢",
	0x40,0x42,0xCC,0x04,0x00,0xFC,0x56,0x55,0xFC,0x50,0x90,0x10,0xFF,0x10,0x10,0x00,
	0x00,0x00,0x3F,0x50,0x29,0x11,0x4D,0x83,0x7F,0x00,0x41,0x80,0x7F,0x00,0x00,0x00,/*"谢",86*/
																			   "合",
	0x40,0x40,0x20,0x50,0x48,0x44,0x42,0x41,0x42,0x44,0x68,0x50,0x30,0x60,0x20,0x00,
	0x00,0x00,0x00,0x7E,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x7E,0x00,0x00,0x00,0x00,/*"合",87*/
																			   "作",
	0x80,0x40,0x20,0xF8,0x07,0x22,0x18,0x0C,0xFB,0x48,0x48,0x48,0x68,0x48,0x08,0x00,
	0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x04,0x04,0x04,0x04,0x06,0x04,0x00,/*"作",88*/
																			   "等",
	0x90,0x88,0xA7,0xA2,0xA6,0xBA,0xA2,0xF8,0xA7,0xA2,0xA6,0xBA,0xA2,0x82,0x80,0x00,
	0x00,0x04,0x04,0x04,0x04,0x0C,0x34,0x04,0x44,0x84,0x7F,0x04,0x04,0x04,0x00,0x00,/*"等",89*/
																			   "待",
	0x20,0x10,0x08,0xC7,0x3A,0x50,0x44,0x44,0x44,0x7F,0x44,0xC4,0x44,0x44,0x40,0x00,
	0x00,0x02,0x01,0xFF,0x00,0x02,0x02,0x1A,0x02,0x42,0x82,0x7F,0x02,0x02,0x02,0x00,/*"待",90*/
																			   "后",
	0x00,0x00,0x00,0xFE,0x12,0x12,0x12,0x12,0x12,0x11,0x11,0x11,0x11,0x11,0x00,0x00,
	0x40,0x30,0x0E,0x01,0x00,0x7F,0x11,0x11,0x11,0x11,0x11,0x11,0x7F,0x00,0x00,0x00,/*"后",91*/
																			   "方",
	0x08,0x08,0x08,0x08,0x08,0x08,0xF9,0x4A,0x4C,0x48,0x48,0xC8,0x08,0x08,0x08,0x00,
	0x40,0x40,0x20,0x10,0x0C,0x03,0x00,0x00,0x20,0x40,0x40,0x3F,0x00,0x00,0x00,0x00,/*"方",92*/
																			   "可",
	0x00,0x02,0x02,0xF2,0x12,0x12,0x12,0x12,0xF2,0x02,0x02,0x02,0xFE,0x02,0x02,0x00,
	0x00,0x00,0x00,0x07,0x02,0x02,0x02,0x02,0x07,0x10,0x20,0x40,0x3F,0x00,0x00,0x00,/*"可",93*/
																			   "拔",
	0x08,0x08,0x08,0xFF,0x88,0x48,0x10,0x10,0xFF,0x50,0x50,0x52,0xD4,0x50,0x10,0x00,
	0x02,0x42,0x81,0x7F,0x40,0x20,0x58,0x47,0x20,0x13,0x0C,0x16,0x21,0x60,0x20,0x00,/*"拔",94*/
																			   "出",
	0x00,0x00,0xFC,0x40,0x40,0x40,0x40,0xFF,0x40,0x40,0x40,0x40,0x40,0xFC,0x00,0x00,
	0x00,0x00,0x7E,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x20,0x7E,0x00,0x00,/*"出",95*/
																			   "片",
	0x00,0x00,0x00,0xFE,0x10,0x10,0x10,0x10,0x10,0x1F,0x10,0x10,0x10,0x18,0x10,0x00,
	0x80,0x40,0x30,0x0F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0x00,0x00,0x00,0x00,/*"片",96*/
																			   "失",
	0x00,0x40,0x20,0x18,0x16,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x00,
	0x00,0x01,0x81,0x41,0x21,0x11,0x0D,0x03,0x05,0x09,0x31,0x61,0xC1,0x41,0x01,0x00,/*"失",97*/
																			   "败",
	0x00,0x00,0xFE,0x02,0xF2,0x02,0xFE,0x20,0xF8,0x17,0x12,0x10,0xF0,0x10,0x10,0x00,
	0x00,0x40,0x31,0x0C,0x03,0x04,0xB9,0x50,0x20,0x13,0x0C,0x13,0x60,0xC0,0x40,0x00,/*"败",98*/
																				"…",
	0x00,0xC0,0xC0,0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"…",*99*/
																			   "℃",
	0x00,0x02,0x05,0xE2,0x18,0x04,0x02,0x02,0x02,0x02,0x02,0x02,0x04,0x1E,0x00,0x00,
	0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x40,0x40,0x40,0x40,0x40,0x20,0x18,0x00,0x00,/*"℃",100*/
	};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void Delay(vu32 nCount)
	{
	for(; nCount != 0; nCount--);
	IWDG_ReloadCounter();
	}


/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int main(void)
	{
	u8 temp,i;
//	u8 No[100]={0};
//	InitQue(&RxQUE3);
	#ifdef DEBUG
		debug();
	#endif
	/*IWDG configuration*/
//	IWDG_Configuration();

	/* System Clocks Configuration */
	RCC_Configuration();

	/* Configure the GPIO ports */
	GPIO_Configuration();

	/* Configure the EXTI Controller */
	EXTI_Configuration();

	/*USART and UART configuration*/
	USART_Configuration();

	/*TIM configuration*/
	TIM_Configuration();

	/* NVIC configuration */
	NVIC_Configuration();

	GPIO_ZBRST_ON();
	GPIO_BEEP_OFF();
	/* Shutdown Smart Card Port */  
	GPIO_5V_OFF();
	GPIO_3V_OFF();
	ISO7816_Disable(); 

	GPIO_COMLED_OFF();
	GPIO_ALED_OFF();
	GPIO_ZBRST_OFF();
	GPIO_LCDBL_ON();
//	timing_flag = 0;
	lcd_flag = 1;
	temp = (*(vu32*) (StartAddr+OFFSET_JL));							//警报按键解除判断
	if(0x55 == temp)
		{
		alarm_canc = 1;
		}
	else
		{
		alarm_canc = 0;
		}
	for(i=0;i<6;i++)
		{
		DX_Addr[i]=(*(vu32*) (StartAddr+i));							 //读取已存电表号码
		}
	if((((DX_Addr[0]>>4)<=0x09)&&((DX_Addr[0]&0x0f)<=0x09)))
		{
		dbaddrtrue = 1;
		}
	else
		{
		dbaddrtrue = 0;
		}
	lcd_refur = 1;
	sys_start = 1;
//	feeddog = 1;
	InitLCD();
	ClearScreen();
	/* Infinite loop */	
	while(1)
		{
		Delay(0x1fffff);
		lcd_flag = 1;
		lcd_refur = 1;
		Dis_test1();
		LCDrefur();	
		Delay(0x1fffff);
		lcd_flag = 1;
		lcd_refur = 1;
		Dis_test2();
		LCDrefur();		
		Delay(0x1fffff);
		lcd_flag = 1;
		lcd_refur = 1;
		Dis_test3();
		LCDrefur();		
		Delay(0x1fffff);
		lcd_flag = 1;
		lcd_refur = 1;
		Dis_test4();
		LCDrefur();		
		}
//		Delay(0xfffff);		
//		while(1);
//		lcd_flag = 1;
//		if(lcd_refur&&lcd_flag)
//			{
//			lcd_refur = 0;
//			if(1 == CardInserted)
//				{
//				CardInserted = 0;
//				if(GPIO_CARDIN())
//					{
//					Dis_readcard();
//					LCDrefur();	
//					ReadSC();
////					ReadSC1();
//					Key_value = 0;
//					}
//				else
//					{
//					ISO7816_Disable();
//					GPIO_5V_OFF();
//					GPIO_3V_OFF();
//					}
//				}
//			if(linktest)
//				{
////				LCD_shutup();
//				Dis_Link();
//				}
//			else
//				{
//				if(0x55 == Key0_value)
//					{
////					LCD_shutup();
//					Dis_NowTime();
//					}
//				else
//					{
//					if((X_DTime[0] != BESET)||(0 == dbaddrtrue))
//						{
//						Page_dis = 0;
//						}
//					Key_deal();
//					}								
//				}
//			LCDrefur();
//			}
//		if(buffer_flag)
//			{
//			BagPack();
//			}
//		if(changedata == 1)
//			{
//			changedata = 0;
//			Change_Dis();
//			}
//		if(cleardata == 1)
//			{
//			ClearData();
//			cleardata = 0;
//			}
//		if(lcd_flag == 0)
//			{
//			LCD_shutdown();
//			Key_value = 0;
//			Key0_value = 0;
//			Page_dis = 0;
//			sys_start = 1;
//			}
//		if((0xff == Key0_value)&&(alarm_flg!=0)&&(alarm_canc == 0))
//			{
//			Alarm_reg();
//			Key0_value = 0x00;
//			}
//		if((Now_time.hour <= ALARMEND)&&(Now_time.hour >= ALARMSTART))
//			{
//			alarm_time = 1;
//			}
//		else
//			{
//			alarm_time = 0;
//			GPIO_BEEP_OFF();
//			}
//		}
	}




#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
	{ 
	/* User can add his own implementation to report the file name and line number,
	ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	
//	/* Infinite loop */
//	while (1)
//		{
//		NVIC_GenerateSystemReset();
//		}
	}
#endif

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
