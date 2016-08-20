#ifndef CONFIG_H
#define CONFIG_H

//#include "stm32f10x_lib.h"
#include "stm32f10x.h"
#define	VERL 0x53			//版本号低位
#define	VERH 0x34			//版本号高位


#define 	ON 1
#define 	OFF 0
#define		MAXNUMOFHZ	101
#define		MAXNUMOFSZ	75
#define		MAXOFRXQ	0xFF

#define		KEYDELAY		150		//按键消抖时间

#define		KEYPRE0		0   //松开
#define		KEYPRE1		1   //1次
#define		KEYPRE2		2   //连续


#define		KEYV_DE		  0  //默认状态
#define		KEYV_NH		  1  //现在时间的时
#define		KEYV_NM		  2  //现在时间的分
#define		KEYV_SH		  3  //起始时间的时
#define		KEYV_SM		  4  //起始时间的分
#define		KEYV_EH		  5  //结束时间的时
#define		KEYV_EM		  6  //结束时间的分


#define FLASH_PAGE_SIZE    ((u16)0x400)
#define StartAddr  ((u32)0x0800FC00)
#define EndAddr    ((u32)0x08010000)


#define	HANZI	16
#define	ZIMU	8

#define	TIME_1S		1000
#define	TIME_250MS	250
#define	TIME_25MS	25
#define	TIME_10MS	20




/* Define the LCD register command code */
#define Disp_On  0xaf	// Display Enable
#define Disp_Off 0xae	// Display Disable
#define Page_Add 0xb0	// Page Address Start
#define Row_AddL 0x04	// Scroll Line LSB
#define Row_AddH 0x10	// Scroll Line MSB
#define Row_Add  0x40   // Scroll Line Start



#define	GPIO_5V_ON()		GPIO_ResetBits(GPIOB, GPIO_Pin_9)
#define	GPIO_5V_OFF()		GPIO_SetBits(GPIOB, GPIO_Pin_9)
#define	GPIO_3V_ON()		GPIO_ResetBits(GPIOB, GPIO_Pin_8)
#define	GPIO_3V_OFF()		GPIO_SetBits(GPIOB, GPIO_Pin_8)

#define	GPIO_LCDBL_ON()		GPIO_ResetBits(GPIOA, GPIO_Pin_11)
#define	GPIO_LCDBL_OFF()	GPIO_SetBits(GPIOA, GPIO_Pin_11)

#define	GPIO_LCDRST_ON()	GPIO_ResetBits(GPIOB, GPIO_Pin_13)
#define	GPIO_LCDRST_OFF()	GPIO_SetBits(GPIOB, GPIO_Pin_13)

#define	GPIO_LCDSDA_1()		GPIO_SetBits(GPIOA, GPIO_Pin_8)
#define	GPIO_LCDSDA_0()		GPIO_ResetBits(GPIOA, GPIO_Pin_8)

#define	GPIO_LCDSCL_1()		GPIO_SetBits(GPIOB, GPIO_Pin_15)
#define	GPIO_LCDSCL_0()		GPIO_ResetBits(GPIOB, GPIO_Pin_15)

#define	GPIO_LCDA0_1()		GPIO_SetBits(GPIOB, GPIO_Pin_14)
#define	GPIO_LCDA0_0()		GPIO_ResetBits(GPIOB, GPIO_Pin_14)

#define	GPIO_LCDCS_1()		GPIO_SetBits(GPIOB, GPIO_Pin_12)
#define	GPIO_LCDCS_0()		GPIO_ResetBits(GPIOB, GPIO_Pin_12)

#define	GPIO_ZBRST_ON()		GPIO_ResetBits(GPIOB, GPIO_Pin_2)
#define	GPIO_ZBRST_OFF()	GPIO_SetBits(GPIOB, GPIO_Pin_2)

#define	GPIO_SCRST_ON()		GPIO_ResetBits(GPIOA, GPIO_Pin_3)
#define	GPIO_SCRST_OFF()	GPIO_SetBits(GPIOA, GPIO_Pin_3)

#define	GPIO_BEEP_ON()		GPIO_ResetBits(GPIOA, GPIO_Pin_12)
#define	GPIO_BEEP_OFF()		GPIO_SetBits(GPIOA, GPIO_Pin_12)
#define	GPIO_BEEP_0N_OFF()	GPIO_WriteBit(GPIOA, GPIO_Pin_12, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_12)))

#define	GPIO_ALED_ON()		GPIO_SetBits(GPIOA, GPIO_Pin_5)
#define	GPIO_ALED_OFF()		GPIO_ResetBits(GPIOA, GPIO_Pin_5)
#define	GPIO_ALED_0N_OFF()	GPIO_WriteBit(GPIOA, GPIO_Pin_5, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_5)))

#define	GPIO_COMLED_ON()	GPIO_SetBits(GPIOA, GPIO_Pin_6)
#define	GPIO_COMLED_OFF()	GPIO_ResetBits(GPIOA, GPIO_Pin_6)
#define	GPIO_COMLED_0N_OFF()	GPIO_WriteBit(GPIOA, GPIO_Pin_6, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_6)))

#define	GPIO_INS_ON()		GPIO_SetBits(GPIOA, GPIO_Pin_1)
#define	GPIO_INS_OFF()	GPIO_ResetBits(GPIOA, GPIO_Pin_1)


#define	GPIO_IO_1()			GPIO_SetBits(GPIOA, GPIO_Pin_0)
#define	GPIO_IO_0()			GPIO_ResetBits(GPIOA, GPIO_Pin_0)
 
#define	GPIO_IO_T()			1==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)
#define	GPIO_IO_F()			0==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

#define	GPIO_KEYU_T()		1==GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)
#define	GPIO_KEYU_F()		0==GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)

#define	GPIO_KEYD_T()		1==GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)
#define	GPIO_KEYD_F()		0==GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)

#define	GPIO_KEYQ_T()		1==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)
#define	GPIO_KEYQ_F()		0==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)

//#define	GPIO_CARDIN()		0==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)			
//#define	GPIO_CARDOUT()		1==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)



typedef struct typFNT_GB12      	// 汉字字模数据结构
{
	u8 Index[2];              	 	// 汉字内码索引
	u8 Msk[32];             		// 点阵码数据
}HZ_TypeDef;

typedef struct typFNT_GB6           //字母字模数据结构
{
	u8 Index;               	 	//字母内码索引
	u8 Msk[16];              	 	// 点阵码数据
}SZ_TypeDef;

typedef struct
{
	unsigned int Start_t;
  unsigned char Value;
	unsigned char En;
}Key_Value;

typedef struct
{
	unsigned char Lcd_ON_OFF:1;  //LCD是否显示的开关
	unsigned char Lcd_ref:1;		//LCD刷新开关
	unsigned char Lcd_tog:1;		//LCD存在需要消隐
	unsigned char Lcd_togold:1;		//LCD存在消隐上次状态
	unsigned char Check_save:1;
	unsigned char Reserved:3;
}Sys_flag;

typedef struct
{
	unsigned char hour;
	unsigned char min;
	unsigned char sec;
}Time_t;
#ifdef  root
	#define EXT_ 
#else
	#define EXT_  extern
#endif

EXT_  HZ_TypeDef HZ1[];
EXT_  SZ_TypeDef SZ1[];

EXT_ volatile unsigned int systick;	
EXT_ volatile unsigned int systick_time;	
EXT_ Sys_flag sys_flag;
EXT_ Time_t Now_Time;
EXT_ Time_t Start_T;
EXT_ Time_t End_T;
	

EXT_ u8	LCD_old[8][128];

EXT_ volatile Key_Value Key_Up;
EXT_ volatile Key_Value Key_Down;
EXT_ volatile Key_Value Key_Ent;
EXT_ u8 KeyValueFor;

EXT_ u16 Lcd_offcounter;			//LCD关闭计数器 
EXT_ u8 Lcd_togcount;
EXT_ u8 Lcd_refcount;


/*******Init功能函数区*************/ 
void RCC_Configuration(void);
void IWDG_Configuration(void);
void SysTick_Configuration(void);




unsigned char RTC_Set(unsigned char hour,unsigned char min,unsigned char sec);
unsigned char RTC_Get(Time_t *rtc_real);
unsigned char Tick2time(unsigned int tick, Time_t *rtc_real);
unsigned int Time2tick(Time_t *rtc_real);
/*******LCD功能函数区*************/
void InitLCD(void);
void ClearScreen(void);
void WriteWord(u8 x, u8 y, u8 index[2]);
void WriteASCII(u8 x, u8 y, u8 index);
void WriteBCD(u8 x, u8 y, u8 index);
void LCD_shutdown(void);
void LCD_shutup(void);
void WriteLine(u8 x, u8 y, u8 index);
void Displaytog(unsigned char x,unsigned char y,unsigned char size);

void SysTickDeal(void);
void SaveTime(void);
void SysPowerOn(void);
void CheckTime(void);
/********数据处理功能函数***********************/
void Delay(vu32 nCount);
u8 Hex2Bcd(u8 b);
u8 Bcd2Hex(u8 b);
/********按键及显示处理功能函数*******************/
void KEY_Init(void);
void Check_Key(void);
	
void LCDrefur(void);
void Dismain(void);
#endif

