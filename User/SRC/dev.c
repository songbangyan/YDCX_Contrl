
#include "config.h"

/*******************************************************************************
* Function Name  : RCC_Configuration
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_Configuration(void)
	{
	ErrorStatus HSEStartUpStatus;
 
	/* RCC system reset(for debug purpose) */
	RCC_DeInit();
	
	/* Enable HSE */
	RCC_HSEConfig(RCC_HSE_ON);
	
	/* Wait till HSE is ready */
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStartUpStatus == SUCCESS)									//ʹ���ⲿHSE
		{
		/* Enable Prefetch Buffer */
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		/* Flash 2 wait state */
		FLASH_SetLatency(FLASH_Latency_2);
		
		/* HCLK = SYSCLK */
		RCC_HCLKConfig(RCC_SYSCLK_Div1); 
		
		/* PCLK2 = HCLK */
		RCC_PCLK2Config(RCC_HCLK_Div1); 
		
		/* PCLK1 = HCLK/2 */
		RCC_PCLK1Config(RCC_HCLK_Div2);
		
		/* PLLCLK = 8MHz * 3 = 24 MHz */
		RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_3);
		
		/* Enable PLL */ 
		RCC_PLLCmd(ENABLE);
		
		/* Wait till PLL is ready */
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
			{
			}
		
		/* Select PLL as system clock source */
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		/* Wait till PLL is used as system clock source */
		while(RCC_GetSYSCLKSource() != 0x08)
			{
			}
		}
//	else															 //ʹ���ڲ�HSI
//		{
//		/* Enable Prefetch Buffer */
//		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
//		
//		/* Flash 2 wait state */
//		FLASH_SetLatency(FLASH_Latency_2);
//		
//		/* HCLK = SYSCLK */
//		RCC_HCLKConfig(RCC_SYSCLK_Div1); 
//		
//		/* PCLK2 = HCLK */
//		RCC_PCLK2Config(RCC_HCLK_Div1); 
//		
//		/* PCLK1 = HCLK/2 */
//		RCC_PCLK1Config(RCC_HCLK_Div2);
//		
//		/* PLLCLK = 8MHz * 3 = 24 MHz */
//		RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_6);
//		
//		/* Enable PLL */ 
//		RCC_PLLCmd(ENABLE);
//		
//		/* Wait till PLL is ready */
//		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
//			{
//			}
//		
//		/* Select PLL as system clock source */
//		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
//		
//		/* Wait till PLL is used as system clock source */
//		while(RCC_GetSYSCLKSource() != 0x08)
//			{
//			}
//		
//		}

	/* Enable GPIOA clocks */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	/* Enable GPIOB clocks */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	/* Enable AFIO clocks */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	/* Enable USART1 clock */  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* Enable USART2 USART3 clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	/* TIM2 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	/* TIM3 clock enable */
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
	{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	#ifdef  VECT_TAB_RAM
	/* Set the Vector Table base location at 0x20000000 */
		NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
	#else  /* VECT_TAB_FLASH  */
	/* Set the Vector Table base location at 0x08000000 */
		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	#endif
	

	/* Configure the NVIC Preemption Priority Bits */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	


	/* Enable the TIM3 Interrupt */
//	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQChannel;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	
//	NVIC_Init(&NVIC_InitStructure);

	/* Clear the CardIN_EXTI IRQ Pending Bit */
	EXTI_ClearITPendingBit(EXTI1_IRQn);

	/* Enable the TIM2 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	/* Enable the USART3 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the USART2 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the RTC Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);


	/* Enable the USART1 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	}

/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configures the different GPIO ports.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration(void)
	{
	GPIO_InitTypeDef GPIO_InitStructure;
	/********Configure USARTx*****/
	
	/* Configure USART1 Rx (PA.10) as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Configure USART1 Tx (PA.09) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	 	
	
	/* Configure USART2 CK(PA.4) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure USART2 Rx (PA.3) as SmartCard Reset  */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure USART2 Tx (PA.2) as alternate function open-drain */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure USART3 Rx (PB.11) as input floating  */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* Configure USART3 Tx (PB.10) as alternate function open-drain */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure); 


	/* Configure IO  *********************/
	/*Configure PA11 as BEEP*/
	/*Configure PA12 as LCD_B*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*Configure PB2 as ZB_RESET*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
		  
	/*Configure PB8 as IC CARD 3V*/
	/*Configure PB9 as IC CARD 5V*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/*Configure PB12 as LCD CS*/
	/*Configure PB13 as LCD RST*/
	/*Configure PB14 as LCD A0*/
	/*Configure PB15 as LCD SCK*/
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/*Configure PA8 as LCD SDA*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	/*Configure PA5 as LED1*/
	/*Configure PA6 as LED2*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	/* Configure PA1 as Smartcard INS */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
		
	/* Configure PB0 as KEY1 */
	/* Configure PB1 as KEY2 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
		
	/* Configure PA7 as KEY3 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
		
	/* Configure PA0 as IO */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure I2C1 pins: SCL(PB.6) and SDA(PB.7) */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	I2C_SCL_1();
	I2C_SDA_1();

	}


/*******************************************************************************
* Function Name  : RTC_Configuration
* Description    : Configures the RTC.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTC_Configuration(void)
	{
	/* Enable PWR and BKP clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
	
	/* Allow access to BKP Domain */
	PWR_BackupAccessCmd(ENABLE);
	
	/* Reset Backup Domain */
	BKP_DeInit();
	
	/* Select the RTC Clock Source */
	RCC_RTCCLKConfig(RCC_RTCCLKSource_HSE_Div128);
	
	/* Enable RTC Clock */
	RCC_RTCCLKCmd(ENABLE);
	
	/* Wait for RTC registers synchronization */
	RTC_WaitForSynchro();
	
	/* Wait until last write operation on RTC registers has finished */
	RTC_WaitForLastTask();
	
	/* Enable the RTC Second */
	RTC_ITConfig(RTC_IT_SEC, ENABLE);
	
	/* Wait until last write operation on RTC registers has finished */
	RTC_WaitForLastTask();
	
	/* Set RTC prescaler: set RTC period to 1sec */
	RTC_SetPrescaler(62500);
	
	/* Wait until last write operation on RTC registers has finished */
	RTC_WaitForLastTask();
	
	/* To output second signal on Tamper pin, the tamper functionality
	   must be disabled (by default this functionality is disabled) */
	BKP_TamperPinCmd(DISABLE);
	
	/* Enable the RTC Second Output on Tamper Pin */
	BKP_RTCOutputConfig(BKP_RTCOutputSource_Second);
	}

/*******************************************************************************
* Function Name  : USART_Configuration
* Description    : Configures the USART.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART_Configuration(void)
	{
	USART_InitTypeDef USART_InitStructure;
	USART_ClockInitTypeDef USART_ClockInitStructure;	
	/* USART1 USART3 configuration ------------------------------------------------------*/
	/* USART1 USART3 configured as follow:
	    - BaudRate = 9600 baud  
	    - Word Length = 9 Bits
	    - One Stop Bit
	    - Even parity
	    - Hardware flow control disabled (RTS and CTS signals)
	    - Receive and transmit enabled
	*/
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_9b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_Even;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
	/* Configure USART1 USART3*/
	USART_Init(USART1, &USART_InitStructure);
	USART_Init(USART3, &USART_InitStructure);

	/* Enable the USART1 USART3*/
	USART_Cmd(USART1, ENABLE); 
	USART_Cmd(USART3, ENABLE); 

	/* Enable USART1 Receive and Transmit interrupts */
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
	
	/* Enable USART3 Receive and Transmit interrupts */
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
//	USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
	


	/* USART2  configuration -------------------------------------------------------*/
	/* USART2 configured as follow:
	    - Word Length = 9 Bits
	    - 0.5 Stop Bit
	    - Even parity
	    - BaudRate = 12096 baud
	    - Hardware flow control disabled (RTS and CTS signals)
	    - Tx and Rx enabled
	    - USART Clock enabled
	    - USART CPOL Low
	    - USART CPHA on first edge
	    - USART Last Bit Clock Enabled
	*/
	
	/* USART Clock set to 3MHz (PCLK1 = 12 MHZ / 4) */
	USART_SetPrescaler(USART2, 0x02);
	/* USART Guard Time set to 2 Bit */
	USART_SetGuardTime(USART2, 0x2);
	
	USART_ClockInitStructure.USART_Clock = USART_Clock_Enable;
	USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;
	USART_ClockInitStructure.USART_CPHA = USART_CPHA_1Edge;
	USART_ClockInitStructure.USART_LastBit = USART_LastBit_Enable;
	USART_ClockInit(USART2, &USART_ClockInitStructure);	
	
	USART_InitStructure.USART_BaudRate = 8064;//12096;
	USART_InitStructure.USART_WordLength = USART_WordLength_9b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1_5;
	USART_InitStructure.USART_Parity = USART_Parity_Even;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART2, &USART_InitStructure);  
	 
	
	/* Enable the USART Parity Error Interrupt */
	USART_ITConfig(USART2, USART_IT_PE, ENABLE);

	
	/* Enable USART2 Receive and Transmit interrupts */
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

	/* Enable USART2  */
	USART_Cmd(USART2, ENABLE);
	
	/* Enable the NACK Transmission */
	USART_SmartCardNACKCmd(USART2, ENABLE);	
	
	/* Enable the Smartcard Interface */
	USART_SmartCardCmd(USART2, ENABLE);	

	}

/*******************************************************************************
* Function Name  : ISO7816_Disable
* Description    : Disable the ISO7816.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void ISO7816_Disable(void)
	{
//	USART_InitTypeDef USART_InitStructure;
	USART_ClockInitTypeDef USART_ClockInitStructure;	

	/* USART2  configuration -------------------------------------------------------*/
	/* USART2 configured as follow:
	    - Word Length = 9 Bits
	    - 0.5 Stop Bit
	    - Even parity
	    - BaudRate = 12096 baud
	    - Hardware flow control disabled (RTS and CTS signals)
	    - Tx and Rx enabled
	    - USART Clock enabled
	    - USART CPOL Low
	    - USART CPHA on first edge
	    - USART Last Bit Clock Enabled
	*/
	
	/* USART Clock set to 3MHz (PCLK1 = 12 MHZ / 4) */
	USART_SetPrescaler(USART2, 0x02);
	/* USART Guard Time set to 2 Bit */
	USART_SetGuardTime(USART2, 0x2);
	
	USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;
	USART_ClockInit(USART2, &USART_ClockInitStructure);	
	/* Disable the USART Parity Error Interrupt */
	USART_ITConfig(USART2, USART_IT_PE, DISABLE);

	
	/* Disable USART2 Receive and Transmit interrupts */
	USART_ITConfig(USART2, USART_IT_RXNE, DISABLE);

	/* Disable USART2  */
	USART_Cmd(USART2, DISABLE);
	
	/* Disable the NACK Transmission */
	USART_SmartCardNACKCmd(USART2, DISABLE);	
	
	/* Disable the Smartcard Interface */
	USART_SmartCardCmd(USART2, DISABLE);	
	}

/*******************************************************************************
* Function Name  : ISO7816_Enable
* Description    : Enable the ISO7816.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void ISO7816_Enable(void)
	{
	USART_InitTypeDef USART_InitStructure;
	USART_ClockInitTypeDef USART_ClockInitStructure;	

	/* USART2  configuration -------------------------------------------------------*/
	/* USART2 configured as follow:
	    - Word Length = 9 Bits
	    - 0.5 Stop Bit
	    - Even parity
	    - BaudRate = 12096 baud
	    - Hardware flow control disabled (RTS and CTS signals)
	    - Tx and Rx enabled
	    - USART Clock enabled
	    - USART CPOL Low
	    - USART CPHA on first edge
	    - USART Last Bit Clock Enabled
	*/
	
	/* USART Clock set to 3MHz (PCLK1 = 12 MHZ / 4) */
	USART_SetPrescaler(USART2, 0x02);
	/* USART Guard Time set to 2 Bit */
	USART_SetGuardTime(USART2, 0x2);
	
	USART_ClockInitStructure.USART_Clock = USART_Clock_Enable;
	USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;
	USART_ClockInitStructure.USART_CPHA = USART_CPHA_1Edge;
	USART_ClockInitStructure.USART_LastBit = USART_LastBit_Enable;
	USART_ClockInit(USART2, &USART_ClockInitStructure);	
	
	USART_InitStructure.USART_BaudRate = 8064;//12096;
	USART_InitStructure.USART_WordLength = USART_WordLength_9b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1_5;
	USART_InitStructure.USART_Parity = USART_Parity_Even;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART2, &USART_InitStructure);  
	 
	
	/* Enable the USART Parity Error Interrupt */
	USART_ITConfig(USART2, USART_IT_PE, ENABLE);

	
	/* Enable USART2 Receive and Transmit interrupts */
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

	/* Enable USART2  */
	USART_Cmd(USART2, ENABLE);
	
	/* Enable the NACK Transmission */
	USART_SmartCardNACKCmd(USART2, ENABLE);	
	
	/* Enable the Smartcard Interface */
	USART_SmartCardCmd(USART2, ENABLE);	
	
	}

/*******************************************************************************
* Function Name  : EXTI_Configuration
* Description    : Configures the External Interrupts controller.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI_Configuration(void)
	{
	EXTI_InitTypeDef EXTI_InitStructure; 

	/* Clear KEY1 Line Pending Bit */
	EXTI_ClearITPendingBit(EXTI_Line1);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);
	EXTI_StructInit(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_Line = EXTI_Line1;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
	}

/*******************************************************************************
* Function Name  : USART send_Configuration
* Description    : Configures the USART send.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART1send(u8 *buffer,u8 len)
	{
	TxCounter1 = 0;
	MaxNbrofTx1 = len;
	TxBuffer1 = buffer;
	USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
	while(TxCounter1 != MaxNbrofTx1);
	}
void USART2send(u8 *buffer,u8 len)
	{
	TxCounter2 = 0;
	MaxNbrofTx2 = len;
	TxBuffer2 = buffer;
	USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
	}
void USART3send(u8 *buffer,u8 len)
	{
	TxCounter3 = 0;
	MaxNbrofTx3 = len;
	TxBuffer3 = buffer;
	GPIO_COMLED_ON();
	USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
	while(TxCounter3 != MaxNbrofTx3);
	GPIO_COMLED_OFF();
	}
/*******************************************************************************
* Function Name  : TIM_Configuration
* Description    : Configures the TIM.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM_Configuration(void)
	{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	/* ---------------------------------------------------------------
	TIM2 Configuration: Output Compare Inactive Mode:
	TIM2CLK = 24 MHz, Prescaler = 23999, TIM2 counter clock = 1 KHz
	TIM2_CH1 delay = 1000/TIM2 counter clock  = 1 s
	TIM2_CH2 delay = 10/TIM2 counter clock  = 10 ms
	TIM2_CH3 delay = 25/TIM2 counter clock  = 25 ms
	--------------------------------------------------------------- */ 	
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 65535;
	TIM_TimeBaseStructure.TIM_Prescaler = 23999;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	/* Output Compare Active Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = TIME_1S;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);

	/* Output Compare Active Mode configuration: Channel2 */
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = TIME_250MS;
	
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);

	/* Output Compare Active Mode configuration: Channel3 */
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = TIME_25MS;
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Disable);

	/* Output Compare Active Mode configuration: Channel4 */
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = TIME_10MS;
	
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Disable);

	TIM_ARRPreloadConfig(TIM2, ENABLE);
		
	/* TIM IT enable */
	TIM_ITConfig(TIM2, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4, ENABLE);
	
	/* TIM2 enable counter */
	TIM_Cmd(TIM2, ENABLE);

//	/* ---------------------------------------------------------------
//	TIM3 Configuration: Output Compare Inactive Mode:
//	TIM2CLK = 24 MHz, Prescaler = 23999, TIM2 counter clock = 1 KHz
//	TIM3_CH1 delay = 1/TIM2 counter clock  = 1 ms
//	--------------------------------------------------------------- */ 	
//	/* Time base configuration */
//	TIM_TimeBaseStructure.TIM_Period = 65535;
//	TIM_TimeBaseStructure.TIM_Prescaler = 23999;
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
//
//	/* Output Compare Active Mode configuration: Channel1 */
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse = TIME_1MS;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	
//	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
//	
//	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Disable);
//
//	TIM_ARRPreloadConfig(TIM3, ENABLE);
//	
//	/* TIM IT enable */
//	TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
//	
//	/* TIM2 enable counter */
//	TIM_Cmd(TIM3, ENABLE);
	}
/*******************************************************************************
* Function Name  : IWDG_Configuration
* Description    : Configures the IWDG.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void IWDG_Configuration(void)
	{
	/* Enable the LSI OSC */
	RCC_LSICmd(ENABLE);
	/* Wait till LSI is ready */
	while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET)
	{}

	/* IWDG timeout equal to 280 ms (the timeout may varies due to LSI frequency
	 dispersion) */
	/* Enable write access to IWDG_PR and IWDG_RLR registers */
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	/* IWDG counter clock: 40KHz(LSI) / 32 = 1.25 KHz */
	IWDG_SetPrescaler(IWDG_Prescaler_32);
	
	/* Set counter reload value to 999 */
	IWDG_SetReload(999);
	
	/* Reload IWDG counter */
	IWDG_ReloadCounter();
	
	/* Enable IWDG (the LSI oscillator will be enabled by hardware) */
	IWDG_Enable();	
	}

/*******************************************************************************
* Function Name  : SysTick_Configuration
* Description    : Configures the SysTick.Configures the SysTick to generate an interrupt each 1 millisecond.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SysTick_Configuration(void)
{
  /* Setup SysTick Timer for 1 msec interrupts  */
  if (SysTick_Config(SystemCoreClock/100000))
  { 
    /* Capture error */ 
    while (1);
  }
  /* Set SysTick Priority to  */
  NVIC_SetPriority(SysTick_IRQn, 0x04);
}



