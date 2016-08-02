#ifndef CONFIG_H
#define CONFIG_H

//#include "stm32f10x_lib.h"
#include "stm32f10x.h"
#define	VERL 0x53			//版本号低位
#define	VERH 0x34			//版本号高位

#define	ALRV 10			//告警金额


#define		MAXNUMOFHZ	101
#define		MAXNUMOFSZ	75
#define		MAXOFRXQ	0xFF
//#define	 	KEYDELAY 	0x01
#define	 	MAXBUFFER 		0xFF
#define 	CANCALALARMTIME 0x0a		//警报解除时间
#define		KEYDELAY		20		//按键消抖时间
#define		KEYPRE		  50
#define		KEYLONG			0x40		//2S

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


#define		BESET	0xAA

#define FLASH_PAGE_SIZE    ((u16)0x400)
#define StartAddr  ((u32)0x0800FC00)
#define EndAddr    ((u32)0x08010000)

#define OFFSET_BH    0x00
#define OFFSET_KEY   0x20
#define OFFSET_JL	 0x30
#define OFFSET_JLL	 0x08

#define ALARMSTART 	7				//报警开始时间
#define ALARMEND	21				//报警结束时间

#define LCD_ONTIME 30			 	//LCD点亮时间 /秒
#define TIMEING	   30			 	//等待数据时间 /秒
#define DATA_TIMR  3			 	//数据有效期 /秒
#define ALARM_TURE	5				//闹铃时长 5S
#define	ALARM_FAUSE	10				//闹铃间隔时间 10S

#define	OFFSET	0x33			 	//数据自身的偏移量
#define ALAEM_CAC	0x55		 	//警报解除BY按键
#define ALAEM_CACJ	0x88		 	//警报解除BY充值

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



#define	GPIO_IO_1()			GPIO_SetBits(GPIOA, GPIO_Pin_0)
#define	GPIO_IO_0()			GPIO_ResetBits(GPIOA, GPIO_Pin_0)
 
#define	GPIO_IO_T()			1==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)
#define	GPIO_IO_F()			0==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

#define	GPIO_KEYU_T()		1==GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)
#define	GPIO_KEYU_F()		0==GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)

#define	GPIO_KEYD_T()		1==GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)
#define	GPIO_KEYD_F()		0==GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)

#define	GPIO_KEYQ_T()		1==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)
#define	GPIO_KEYQ_F()		0==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)

#define	GPIO_CARDIN()		0==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)			
#define	GPIO_CARDOUT()		1==GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)

/************协议命令字*******************/
#define	HEAD	0xa8				//起始字
#define	END		0x16				//结束符
#define CON0	0x00				//功能0：确认/否认
#define CON1	0x01				//功能1：复位
#define CON2	0x02				//功能2：设置信息
#define	CON3	0x03				//功能3：读取设置信息
#define CON4	0x04				//功能4：电表数据
#define CON5	0x05				//功能5：连路测试
#define CON6	0x06				//功能6：读取事件记录

#define D_FEILV		0x34			//费率电价
#define	D_ZHUANGTAI	0x35			//电表状态字
#define	D_DANGQBM	0x36			//当前表码
#define	D_SHENGYD	0x37			//当前剩余电量
#define	D_SHENGYJ	0x38			//当前剩余金额
#define	D_ZONGGDC	0x39		    //总购电次数
#define D_LASTGT	0x3a		    //最后一次购电时间
#define D_DANGQLJD	0x3b		    //当前结算累计用电量
#define	D_SHANGZQD  0x3c		    //上一周期结算累计用电量
#define	D_LEIJGD 	0x3d		    //累计购电量
#define	D_LASTGDJ	0x3e			//最后一次购电金额
#define	D_LEIJG		0x3f			//累计购电金额
#define	D_JTDJ		0x40			//当前阶梯电价

typedef struct typFNT_GB12      	// 汉字字模数据结构
	{
	u8 Index[2];              	 	// 汉字内码索引
	u8 Msk[32];             		// 点阵码数据
	}HZ_TypeDef;

typedef struct typFNT_GB6           //字母字模数据结构
	{
	u8 Index[1];               	 	//字母内码索引
	u8 Msk[16];              	 	// 点阵码数据
	}SZ_TypeDef;

typedef struct
{
	unsigned int Start_t;
  unsigned char Value;
	unsigned char En;
}Key_Value;

	
#ifdef  root
	#define EXT_ 
#else
	#define EXT_  extern
#endif

EXT_  HZ_TypeDef HZ1[];
EXT_  SZ_TypeDef SZ1[];

EXT_ unsigned int systick;	

EXT_ u8 Now_Time[3];
EXT_ u8 Start_T[2];
EXT_ u8 End_T[2];
	

EXT_ u8	LCD_old[8][128];

EXT_ Key_Value Key_Up;
EXT_ Key_Value Key_Down;
EXT_ Key_Value Key_Ent;
EXT_ u8 KeyValueFor;
	

EXT_ u8 Lcd_counter;			//LCD关闭计数器 




/*******Init功能函数区*************/ 
void RCC_Configuration(void);
void GPIO_Configuration(void);
void IWDG_Configuration(void);
void SysTick_Configuration(void);



/*******UART功能函数区*************/
void ISO7816_Disable(void);
void ISO7816_Enable(void);
void USART1send(u8 *buffer,u8 len);
void USART2send(u8 *buffer,u8 len);
void USART3send(u8 *buffer,u8 len);



/*******LCD功能函数区*************/
void InitLCD(void);
void ClearScreen(void);
void WriteWord(u8 x, u8 y, u8 index[2]);
void WriteASCII(u8 x, u8 y, u8 index[1]);
void WriteBCD(u8 x, u8 y, u8 index);
void LCD_shutdown(void);
void LCD_shutup(void);
void WriteLine(u8 x, u8 y, u8 index);


/********数据处理功能函数***********************/


void Delay(vu32 nCount);
u8 Hex2Bcd(u8 b);
u8 Bcd2Hex(u8 b);
/********按键及显示处理功能函数*******************/

void LCDrefur(void);

#endif

