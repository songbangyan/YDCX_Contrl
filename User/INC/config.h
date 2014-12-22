#ifndef CONFIG_H
#define CONFIG_H

//#include "stm32f10x_lib.h"
#include "stm32f10x.h"
#define	VERL 0x53			//�汾�ŵ�λ
#define	VERH 0x34			//�汾�Ÿ�λ

#define	ALRV 10			//�澯���


#define		MAXNUMOFHZ	101
#define		MAXNUMOFSZ	75
#define		MAXOFRXQ	0xFF
//#define	 	KEYDELAY 	0x01
#define	 	MAXBUFFER 		0xFF
#define 	CANCALALARMTIME 0x0a		//�������ʱ��
#define		KEYDELAY		0x04		//��������ʱ��
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

#define ALARMSTART 	7				//������ʼʱ��
#define ALARMEND	21				//��������ʱ��

#define LCD_ONTIME 30			 	//LCD����ʱ�� /��
#define TIMEING	   30			 	//�ȴ�����ʱ�� /��
#define DATA_TIMR  3			 	//������Ч�� /��
#define ALARM_TURE	5				//����ʱ�� 5S
#define	ALARM_FAUSE	10				//������ʱ�� 10S

#define	OFFSET	0x33			 	//���������ƫ����
#define ALAEM_CAC	0x55		 	//�������BY����
#define ALAEM_CACJ	0x88		 	//�������BY��ֵ

#define	HANZI	16
#define	ZIMU	8

#define	TIME_1S		1000
#define	TIME_250MS	250
#define	TIME_25MS	25
#define	TIME_10MS	20



/************����������*******************/
//#define	KADD	1				  //����ַ��ֵ
#define	KYUE	1				  //ʣ�����ֵ
#define	KYDL	2				  //ʣ�������ֵ
#define	KZQS	3				  //���ڵ�����ʼ��ֵ
#define	KZQE	7				  //���ڵ���������ֵ
#define	KDQS	8				  //��ǰʾ����ʼ��ֵ
#define	KDQE	12				  //��ǰʾ��������ֵ
#define	KDJS 	13				  //��ۿ�ʼ��ֵ
#define	KDJE	16				  //��۽�����ֵ
#define	KGDC	17				  //���������ֵ
#define	KLGD	18				  //�ۼƹ�������ֵ
#define	KLJJ	19				  //�ۼƹ������ֵ
#define	KGDT	20				  //���һ�ι���ʱ���ֵ 
#define	KGDJ	21				  //���һ�ι������ֵ
#define	KDQJ	22				  //��ǰ���ݵ�ۼ�ֵ
#define	KGXT	23				  //���һ�θ���ʱ���ֵ

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

/************Э��������*******************/
#define	HEAD	0xa8				//��ʼ��
#define	END		0x16				//������
#define CON0	0x00				//����0��ȷ��/����
#define CON1	0x01				//����1����λ
#define CON2	0x02				//����2��������Ϣ
#define	CON3	0x03				//����3����ȡ������Ϣ
#define CON4	0x04				//����4���������
#define CON5	0x05				//����5����·����
#define CON6	0x06				//����6����ȡ�¼���¼

#define D_FEILV		0x34			//���ʵ��
#define	D_ZHUANGTAI	0x35			//���״̬��
#define	D_DANGQBM	0x36			//��ǰ����
#define	D_SHENGYD	0x37			//��ǰʣ�����
#define	D_SHENGYJ	0x38			//��ǰʣ����
#define	D_ZONGGDC	0x39		    //�ܹ������
#define D_LASTGT	0x3a		    //���һ�ι���ʱ��
#define D_DANGQLJD	0x3b		    //��ǰ�����ۼ��õ���
#define	D_SHANGZQD  0x3c		    //��һ���ڽ����ۼ��õ���
#define	D_LEIJGD 	0x3d		    //�ۼƹ�����
#define	D_LASTGDJ	0x3e			//���һ�ι�����
#define	D_LEIJG		0x3f			//�ۼƹ�����
#define	D_JTDJ		0x40			//��ǰ���ݵ��

typedef struct typFNT_GB12      	// ������ģ���ݽṹ
	{
	u8 Index[2];              	 	// ������������
	u8 Msk[32];             		// ����������
	}HZ_TypeDef;

typedef struct typFNT_GB6           //��ĸ��ģ���ݽṹ
	{
	u8 Index[1];               	 	//��ĸ��������
	u8 Msk[16];              	 	// ����������
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

EXT_ struct Time Now_time;						//��ǰʱ��

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

EXT_ u8 D_len;				 	//����ճ���
EXT_ u8	Data_time;				//����������Ч��
EXT_ u8	DT_Counter;				//��������ʱ�� //�����жϴ��ڵ������Ƿ��뵱ǰʱ���ǩ��һ��
EXT_ u8	Alarm_count;			//����������

EXT_ u8 Lcd_counter;			//LCD�رռ����� 

EXT_ u8 Key_value;				//����������
EXT_ u8 Key0_value;				//ȷ�ϰ���ֵ
EXT_ u8 KeyU_count;				//�����ϼ�����
EXT_ u8 KeyD_count;				//�����¼�����
EXT_ u8 KeyQ_count;				//����ȷ�ϼ�����
EXT_ u8 KeyQ1_count;			//����ȷ��1������

EXT_ u8 Key_upcount;			//�����ͷż�����
EXT_ u8 Page_dis;				//��ʾ��ҳ��

EXT_ u8 Tempr_data;				//�¶�
EXT_ u8 RH_data;				//ʪ�� 

//EXT_ u16 cont;

EXT_ u8 buffer_flag;		  	//������������
EXT_ u8 d_start;			 	//����������Ч��־
EXT_ u8	set_time;				//ʱ��������
EXT_ u8 timed;					//��Уʱ��־
EXT_ u8	linktest;				//��·����
EXT_ u8	lcd_flag;				//LCD״̬
EXT_ u8 alarm_flg;				//������־
EXT_ u8 alarm_canc;				//����ȡ��
EXT_ u8 alarm_time;				//����ʱ��
EXT_ u8 alarm_time0;			//����ʱ��
EXT_ u8	lcd_refur;				//LCDˢ�±�־
EXT_ u8 CardInserted;			//�������־

//EXT_ u8 timing_flag;			//Уʱ��־

EXT_ u8 data_t;					//������Ч��־
EXT_ u8 mac_t;					//�����ַ��־

EXT_ u8 reset;					//������־

EXT_ u8 key_plus;				//�����ӱ�־
EXT_ u8 key_plusold;			//�����ӵ���һ�α�־
EXT_ u8 key_up;					//�����ͷ� 
EXT_ u8 sys_start;				//ϵͳ��ʼ������ָʾ 

EXT_ u8 changedata;				//��ʾ���ݸ���
EXT_ u8 cleardata;				//����ѽ�������

//EXT_ u8 feeddog;					//ι����ʶ
EXT_ u8 dbaddrtrue;					//������־
EXT_ u8 nocardid;					//������־

EXT_ u8 X_DTime[4];				//���ݸ���ʱ��
EXT_ u8 X_Feil[17];				//�����ʼĴ���
EXT_ u8 X_Biaoma[21];			//��ǰ����Ĵ���
EXT_ u8 X_Sdian[6];				//ʣ�����
EXT_ u8 X_Smoney[6];			//ʣ����
EXT_ u8 X_Goudc[3];				//�ܹ������
EXT_ u8 X_Lgoudt[6];			//���һ�ι���ʱ��
EXT_ u8 X_Djleij[21];			//��ǰ�����ۻ�
EXT_ u8 X_Ljgoud[5];			//�ۼƹ�����
EXT_ u8 X_Lgoudj[5];			//���һ�ι�����
EXT_ u8 X_Leigoudj[5];			//�ۼƹ�����
EXT_ u8 X_Jietdj[5];			//��ǰ���ݵ��

EXT_ u8 D_Feil[17];				//�����ʼĴ���
EXT_ u8 D_Biaoma[21];			//��ǰ����Ĵ���
EXT_ u8 D_Sdian[6];				//ʣ�����
EXT_ u8 D_Smoney[6];			//ʣ����
EXT_ u8 D_Goudc[3];				//�ܹ������
EXT_ u8 D_Lgoudt[6];			//���һ�ι���ʱ��
EXT_ u8 D_Djleij[21];			//��ǰ�����ۻ�
EXT_ u8 D_Ljgoud[5];			//�ۼƹ�����
EXT_ u8 D_Lgoudj[5];			//���һ�ι�����
EXT_ u8 D_Leigoudj[5];			//�ۼƹ�����
EXT_ u8 D_Jietdj[5];			//��ǰ���ݵ��

EXT_ u8 DX_Addr[6];				//������



/*******Init���ܺ�����*************/ 
void RCC_Configuration(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void RTC_Configuration(void);
void USART_Configuration(void);
void EXTI_Configuration(void);
void TIM_Configuration(void);
void IWDG_Configuration(void);
void WWDG_Configuration(void);


/*******DHT11���ܺ�����*************/
void DHT_com(void);


/*******UART���ܺ�����*************/
void ISO7816_Disable(void);
void ISO7816_Enable(void);
void USART1send(u8 *buffer,u8 len);
void USART2send(u8 *buffer,u8 len);
void USART3send(u8 *buffer,u8 len);

/*******I2C���ܺ�����*************/
u8 eeprom_write_byte(u32 addr,u8 data);
u8 eeprom_read_byte(u32 addr,u8 *data);
u8 eeprom_write_page(u16 page_num,u8 offset,u16 num,u8 *data);
void eeprom_write(u32 addr,u32 num,u8 *p_data);


/*******LCD���ܺ�����*************/
void InitLCD(void);
void ClearScreen(void);
void WriteWord(u8 x, u8 y, u8 index[2]);
void WriteASCII(u8 x, u8 y, u8 index[1]);
void WriteBCD(u8 x, u8 y, u8 index);
void LCD_shutdown(void);
void LCD_shutup(void);
void WriteLine(u8 x, u8 y, u8 index);
//void WriteLine(u8 y);

/********���ݴ����ܺ���***********************/
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
/********��������ʾ�����ܺ���*******************/
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

