#ifndef CONFIG_H
#define CONFIG_H

#include "stm32f10x.h"

#define	VERL 0x00			//版本号低位
#define	VERH 0x00			//版本号高位

#define		QUESUC		0 
#define		QUEFULL		1
#define		QUEEMP		2
#define		QUENOEGH	3
#define		MAXOFRXQ	100

#define		COMNFIR	0
#define		COMFIR	1
#define		COMTXON	2

#define		TRUE	1
#define		FALSE	0


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

#define	GPIO_ESAMRST_ON()		GPIO_ResetBits(GPIOA, GPIO_Pin_10)
#define	GPIO_ESAMRST_OFF()	GPIO_SetBits(GPIOA, GPIO_Pin_10)
#define	GPIO_BLRST_ON()			GPIO_ResetBits(GPIOB, GPIO_Pin_12)
#define	GPIO_BLRST_OFF()		GPIO_SetBits(GPIOB, GPIO_Pin_12)

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
typedef struct	
	{   
	u8 elem[MAXOFRXQ];   
	u8 head,tail;   
	}Quque;
	
#ifdef  root
	#define EXT_ 
#else
	#define EXT_  extern
#endif

EXT_ struct Time Now_time;	
EXT_ u8 RxData1;
EXT_ u8 RxData2;
EXT_ Quque RxQUE3;
EXT_ u8 Com1first;
EXT_ u8 Com2first;
EXT_ u8 Com3first;
EXT_ u8 Com1Endtx;
EXT_ u8 Com2Endtx;
EXT_ u8 Com3Endtx;


EXT_ u8 timed;

EXT_ __IO uint32_t TimingDelay ;

/** @defgroup config_Exported_Functions
  * @{
  */
/*******队列操作函数区*************/
void InitQue(Quque *q); //初始化
u8 IsFull(Quque *q);
u8 InsertQue(Quque *q,u8 elem);
u8 IsEmpty(Quque *q);
u8 OutQue(Quque *q,u8 *pelem,u8 len);
u8 AllOutQue(Quque *q,u8 *pelem);
u8 NumOfQue(Quque *q);

/*******串口功能函数区*************/
void RCC_Configuration(void);
void SYSCLKConfig_STOP(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void RTC_Configuration(void);
void USART_Configuration(void);
void ISO7816_Disable(USART_TypeDef* USARTx);
void ISO7816_Enable(USART_TypeDef* USARTx);
void TIM_Configuration(void);
void IWDG_Configuration(void);
void WWDG_Configuration(void);
void SysTick_Configuration(void);
void Delay(__IO uint32_t nTime);
/*******UART功能函数区*************/
void USART1send(Quque *q);
void USART2send(Quque *q);
void USART3send(u8 ch);



#endif

