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
#define		KEYDELAY		20		//��������ʱ��
#define		KEYPRE		  50
#define		KEYLONG			0x40		//2S

#define		KEYPRE0		0   //�ɿ�
#define		KEYPRE1		1   //1��
#define		KEYPRE2		2   //����


#define		KEYV_DE		  0  //Ĭ��״̬
#define		KEYV_NH		  1  //����ʱ���ʱ
#define		KEYV_NM		  2  //����ʱ��ķ�
#define		KEYV_SH		  3  //��ʼʱ���ʱ
#define		KEYV_SM		  4  //��ʼʱ��ķ�
#define		KEYV_EH		  5  //����ʱ���ʱ
#define		KEYV_EM		  6  //����ʱ��ķ�


#define		BESET	0xAA

#define FLASH_PAGE_SIZE    ((u16)0x400)
#define StartAddr  ((u32)0x0800FC00)
#define EndAddr    ((u32)0x08010000)

#define OFFSET_BH    0x00
#define OFFSET_KEY   0x20
#define OFFSET_JL	 0x30
#define OFFSET_JLL	 0x08

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
	

EXT_ u8 Lcd_counter;			//LCD�رռ����� 




/*******Init���ܺ�����*************/ 
void RCC_Configuration(void);
void GPIO_Configuration(void);
void IWDG_Configuration(void);
void SysTick_Configuration(void);



/*******UART���ܺ�����*************/
void ISO7816_Disable(void);
void ISO7816_Enable(void);
void USART1send(u8 *buffer,u8 len);
void USART2send(u8 *buffer,u8 len);
void USART3send(u8 *buffer,u8 len);



/*******LCD���ܺ�����*************/
void InitLCD(void);
void ClearScreen(void);
void WriteWord(u8 x, u8 y, u8 index[2]);
void WriteASCII(u8 x, u8 y, u8 index[1]);
void WriteBCD(u8 x, u8 y, u8 index);
void LCD_shutdown(void);
void LCD_shutup(void);
void WriteLine(u8 x, u8 y, u8 index);


/********���ݴ����ܺ���***********************/


void Delay(vu32 nCount);
u8 Hex2Bcd(u8 b);
u8 Bcd2Hex(u8 b);
/********��������ʾ�����ܺ���*******************/

void LCDrefur(void);

#endif

