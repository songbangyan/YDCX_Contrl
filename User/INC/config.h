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
#define		KEYDELAY		0x04		//按键消抖时间
#define		KEYLONG			0x40		//2S

#define		QUESUC		0 
#define		QUEFULL		1
#define		QUEEMP		2
#define		QUENOEGH	3

#define		BESET	0xAA

#define FLASH_PAGE_SIZE    ((u16)0x400)
#define StartAddr  ((u32)0x0800FC00)
#define EndAddr    ((u32)0x08010000)

#define OFFSET_BH    0x00
#define OFFSET_KEY   0x20
#define OFFSET_JL	 0x30
#define OFFSET_JLL	 0x08



#define I2C_Speed         400000
#define EEPROM_ADDRESS    0xA8
#define EE_PageSize      256
#define I2C_SCL_0() GPIOB->BRR=GPIO_Pin_6
#define I2C_SCL_1() GPIOB->BSRR=GPIO_Pin_6
#define I2C_SDA_0() GPIOB->BRR=GPIO_Pin_7
#define I2C_SDA_1() GPIOB->BSRR=GPIO_Pin_7
#define I2C_SDA_STATE() (GPIOB->IDR&GPIO_Pin_7)


#define I2C_READY	0x00
#define	I2C_OK		0x00
#define	I2C_BUSY	0x01
#define	I2C_ERR		0x02
#define	I2C_NACK	0x03
#define	I2C_ACK		0x04

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



/************按键变量区*******************/
//#define	KADD	1				  //电表地址键值
#define	KYUE	1				  //剩余金额键值
#define	KYDL	2				  //剩余电量键值
#define	KZQS	3				  //周期电量开始键值
#define	KZQE	7				  //周期电量结束键值
#define	KDQS	8				  //当前示数开始键值
#define	KDQE	12				  //当前示数结束键值
#define	KDJS 	13				  //电价开始键值
#define	KDJE	16				  //电价结束键值
#define	KGDC	17				  //购电次数键值
#define	KLGD	18				  //累计购电量键值
#define	KLJJ	19				  //累计购电金额键值
#define	KGDT	20				  //最后一次购电时间键值 
#define	KGDJ	21				  //最后一次购电金额键值
#define	KDQJ	22				  //当前阶梯电价键值
#define	KGXT	23				  //最后一次更新时间键值

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

struct Time
	{
	u8 msec;
	u8 sec;
	u8 min;
	u8 hour;
	u8 day;
	u8 mon;
	u8 year;
	};
	
#ifdef  root
	#define EXT_ 
#else
	#define EXT_  extern
#endif

EXT_  HZ_TypeDef HZ1[];
EXT_  SZ_TypeDef SZ1[];

EXT_ struct Time Now_time;						//当前时间

EXT_ u8 *TxBuffer1;
EXT_ u8 RxBuffer1[10];
EXT_ u8 *TxBuffer2; 
EXT_ u8 RxBuffer2[100];
EXT_ u8 *TxBuffer3;
EXT_ u8 RxBuffer3[MAXBUFFER];
 
//EXT_ Quque RxQUE3;
EXT_ u8 Data_tmp[MAXBUFFER];

EXT_ u8	LCD_old[8][128];

EXT_ vu8 TxCounter1;
EXT_ vu8 RxCounter1;
EXT_ vu8 TxCounter2;
EXT_ vu8 RxCounter2; 
EXT_ vu8 TxCounter3;
EXT_ vu8 RxCounter3; 

EXT_ u8 MaxNbrofTx1;
EXT_ u8 MaxNbrofTx2;
EXT_ u8 MaxNbrofTx3;
EXT_ u16 capture;

EXT_ u8 D_len;				 	//需接收长度
EXT_ u8	Data_time;				//串口数据有效期
EXT_ u8	DT_Counter;				//串口数据时限 //用于判断串口的数据是否与当前时间标签相一致
EXT_ u8	Alarm_count;			//报警计数器

EXT_ u8 Lcd_counter;			//LCD关闭计数器 

EXT_ u8 Key_value;				//按键计数器
EXT_ u8 Key0_value;				//确认按键值
EXT_ u8 KeyU_count;				//按键上计数器
EXT_ u8 KeyD_count;				//按键下计数器
EXT_ u8 KeyQ_count;				//按键确认计数器
EXT_ u8 KeyQ1_count;			//按键确认1计数器

EXT_ u8 Key_upcount;			//按键释放计数器
EXT_ u8 Page_dis;				//显示的页面

EXT_ u8 Tempr_data;				//温度
EXT_ u8 RH_data;				//湿度 

//EXT_ u16 cont;

EXT_ u8 buffer_flag;		  	//串口数据已满
EXT_ u8 d_start;			 	//串口数据有效标志
EXT_ u8	set_time;				//时间已设置
EXT_ u8 timed;					//已校时标志
EXT_ u8	linktest;				//链路测试
EXT_ u8	lcd_flag;				//LCD状态
EXT_ u8 alarm_flg;				//报警标志
EXT_ u8 alarm_canc;				//报警取消
EXT_ u8 alarm_time;				//报警时间
EXT_ u8 alarm_time0;			//报警时段
EXT_ u8	lcd_refur;				//LCD刷新标志
EXT_ u8 CardInserted;			//卡插入标志

//EXT_ u8 timing_flag;			//校时标志

EXT_ u8 data_t;					//数据有效标志
EXT_ u8 mac_t;					//物理地址标志

EXT_ u8 reset;					//重启标志

EXT_ u8 key_plus;				//按键加标志
EXT_ u8 key_plusold;			//按键加的上一次标志
EXT_ u8 key_up;					//按键释放 
EXT_ u8 sys_start;				//系统初始化运行指示 

EXT_ u8 changedata;				//显示数据更新
EXT_ u8 cleardata;				//清空已接收数据

//EXT_ u8 feeddog;					//喂狗标识
EXT_ u8 dbaddrtrue;					//重启标志
EXT_ u8 nocardid;					//重启标志

EXT_ u8 X_DTime[4];				//数据更新时间
EXT_ u8 X_Feil[17];				//电表费率寄存器
EXT_ u8 X_Biaoma[21];			//当前表码寄存器
EXT_ u8 X_Sdian[6];				//剩余电量
EXT_ u8 X_Smoney[6];			//剩余金额
EXT_ u8 X_Goudc[3];				//总购电次数
EXT_ u8 X_Lgoudt[6];			//最后一次购电时间
EXT_ u8 X_Djleij[21];			//当前结算累积
EXT_ u8 X_Ljgoud[5];			//累计购电量
EXT_ u8 X_Lgoudj[5];			//最后一次购电金额
EXT_ u8 X_Leigoudj[5];			//累计购电金额
EXT_ u8 X_Jietdj[5];			//当前阶梯电价

EXT_ u8 D_Feil[17];				//电表费率寄存器
EXT_ u8 D_Biaoma[21];			//当前表码寄存器
EXT_ u8 D_Sdian[6];				//剩余电量
EXT_ u8 D_Smoney[6];			//剩余金额
EXT_ u8 D_Goudc[3];				//总购电次数
EXT_ u8 D_Lgoudt[6];			//最后一次购电时间
EXT_ u8 D_Djleij[21];			//当前结算累积
EXT_ u8 D_Ljgoud[5];			//累计购电量
EXT_ u8 D_Lgoudj[5];			//最后一次购电金额
EXT_ u8 D_Leigoudj[5];			//累计购电金额
EXT_ u8 D_Jietdj[5];			//当前阶梯电价

EXT_ u8 DX_Addr[6];				//电表号码



/*******Init功能函数区*************/ 
void RCC_Configuration(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void RTC_Configuration(void);
void USART_Configuration(void);
void EXTI_Configuration(void);
void TIM_Configuration(void);
void IWDG_Configuration(void);
void WWDG_Configuration(void);


/*******DHT11功能函数区*************/
void DHT_com(void);


/*******UART功能函数区*************/
void ISO7816_Disable(void);
void ISO7816_Enable(void);
void USART1send(u8 *buffer,u8 len);
void USART2send(u8 *buffer,u8 len);
void USART3send(u8 *buffer,u8 len);

/*******I2C功能函数区*************/
u8 eeprom_write_byte(u32 addr,u8 data);
u8 eeprom_read_byte(u32 addr,u8 *data);
u8 eeprom_write_page(u16 page_num,u8 offset,u16 num,u8 *data);
void eeprom_write(u32 addr,u32 num,u8 *p_data);


/*******LCD功能函数区*************/
void InitLCD(void);
void ClearScreen(void);
void WriteWord(u8 x, u8 y, u8 index[2]);
void WriteASCII(u8 x, u8 y, u8 index[1]);
void WriteBCD(u8 x, u8 y, u8 index);
void LCD_shutdown(void);
void LCD_shutup(void);
void WriteLine(u8 x, u8 y, u8 index);
//void WriteLine(u8 y);

/********数据处理功能函数***********************/
void BagPack(void);
void Reset_fun(void);
void DataInit(void);
void Set_fun(void);
void Check_fun(void);
void Dbdata_fun(void);
void Linktest_fun(void);
void CheckT_fun(void);
void Change_Dis(void);
void ClearData(void);
void Report_T(void);
void Alarm_reg(void);
void Alarm_Abo(void);

void ReadSC(void);
 void ReadSC1(void);

void Delay(vu32 nCount);
u8 Hex2Bcd(u8 b);
u8 Bcd2Hex(u8 b);
/********按键及显示处理功能函数*******************/
void Key_deal(void);
void Dis_defalt(void);
void Dis_readcard(void);
void Dis_TRH(void);
void Dis_dbadd(void);
void Dis_DJ(void);
void Dis_Dqdls(void);
void Dis_Dqz(void);
void Dis_LeaD(void);
void Dis_LeaJ(void);
void Dis_GCount(void);
void Dis_Lastbuytime(void);
void Dis_GTotal(void);
void Dis_Tbuyj(void);
void Dis_Lastbuyj(void);
void Dis_Nowjtdj(void);
void Dis_Lasttiming(void);
void Dis_Link(void);
void Dis_NowTime(void);
void Dis_test1(void);
void Dis_test2(void);
void Dis_test3(void);
void Dis_test4(void);
void LCDrefur(void);

#endif

