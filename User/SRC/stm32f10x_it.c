/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_it.c
* Author             : MCD Application Team
* Version            : V2.0.1
* Date               : 06/13/2008
* Description        : Main Interrupt Service Routines.
*                      This file provides template for all exceptions handler
*                      and peripherals interrupt service routine.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "config.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : NMIException
* Description    : This function handles NMI exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NMIException(void)
{
}

/*******************************************************************************
* Function Name  : HardFaultException
* Description    : This function handles Hard Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void HardFaultException(void)
	{
	/* Go to infinite loop when Hard Fault exception occurs */
//	while (1)
//		{
//		NVIC_GenerateSystemReset();
//		}
	}

/*******************************************************************************
* Function Name  : MemManageException
* Description    : This function handles Memory Manage exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
	void MemManageException(void)
	{
	/* Go to infinite loop when Memory Manage exception occurs */
//	while (1)
//		{
//		NVIC_GenerateSystemReset();
//		}
	}

/*******************************************************************************
* Function Name  : BusFaultException
* Description    : This function handles Bus Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void BusFaultException(void)
	{
	/* Go to infinite loop when Bus Fault exception occurs */
//	while (1)
//		{
//		NVIC_GenerateSystemReset();
//		}
	}

/*******************************************************************************
* Function Name  : UsageFaultException
* Description    : This function handles Usage Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UsageFaultException(void)
	{
	/* Go to infinite loop when Usage Fault exception occurs */
//	while (1)
//		{
//		NVIC_GenerateSystemReset();
//		}
	}

/*******************************************************************************
* Function Name  : DebugMonitor
* Description    : This function handles Debug Monitor exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DebugMonitor(void)
{
}

/*******************************************************************************
* Function Name  : SVCHandler
* Description    : This function handles SVCall exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SVCHandler(void)
{
}

/*******************************************************************************
* Function Name  : PendSVC
* Description    : This function handles PendSVC exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void PendSVC(void)
{
}

/*******************************************************************************
* Function Name  : SysTickHandler
* Description    : This function handles SysTick Handler.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SysTickHandler(void)
{
	
}

/*******************************************************************************
* Function Name  : WWDG_IRQHandler
* Description    : This function handles WWDG interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void WWDG_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : PVD_IRQHandler
* Description    : This function handles PVD interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void PVD_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TAMPER_IRQHandler
* Description    : This function handles Tamper interrupt request. 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TAMPER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : RTC_IRQHandler
* Description    : This function handles RTC global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTC_IRQHandler(void)
	{
	if (RTC_GetITStatus(RTC_IT_SEC) != RESET)
		{
		/* Clear the RTC Second interrupt */
		RTC_ClearITPendingBit(RTC_IT_SEC);
		
		
		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();
		if(timed != 1)
			{
//			Time_Adjust();
			}
		/* Reset RTC Counter when Time is 23:59:59 */
		if (RTC_GetCounter() == 0x00015180)
			{
			if(timed)
				{
				if(((Now_time.mon==1)||(Now_time.mon==3)||(Now_time.mon==5)||(Now_time.mon==7)||(Now_time.mon==8)||(Now_time.mon==10)||(Now_time.mon==12))&&(Now_time.day>=32))
					{
					Now_time.day=1;
					Now_time.mon++;
					}
				else if(((Now_time.mon==4)||(Now_time.mon==6)||(Now_time.mon==9)||(Now_time.mon==11))&&(Now_time.day>=31))
					{
					Now_time.day=1;
					Now_time.mon++;
					}
				else if((Now_time.mon==2)&&(Now_time.day>=29))
					{
					Now_time.day=1;
					Now_time.mon++;
					}				
				}
			/* Change the current time */
			RTC_SetCounter(0);
			/* Wait until last write operation on RTC registers has finished */
			RTC_WaitForLastTask();
			}
		}
	}

/*******************************************************************************
* Function Name  : FLASH_IRQHandler
* Description    : This function handles Flash interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void FLASH_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : RCC_IRQHandler
* Description    : This function handles RCC interrupt request. 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI0_IRQHandler
* Description    : This function handles External interrupt Line 0 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI0_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI1_IRQHandler
* Description    : This function handles External interrupt Line 1 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI1_IRQHandler(void)
	{
	/* Clear KEY3 EXTIT Line Pending Bit */
	EXTI_ClearITPendingBit(EXTI_Line1);
	CardInserted = 1;
	lcd_flag = 1;
	}

/*******************************************************************************
* Function Name  : EXTI2_IRQHandler
* Description    : This function handles External interrupt Line 2 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI3_IRQHandler
* Description    : This function handles External interrupt Line 3 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI4_IRQHandler
* Description    : This function handles External interrupt Line 4 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel1_IRQHandler
* Description    : This function handles DMA1 Channel 1 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel2_IRQHandler
* Description    : This function handles DMA1 Channel 2 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel3_IRQHandler
* Description    : This function handles DMA1 Channel 3 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel4_IRQHandler
* Description    : This function handles DMA1 Channel 4 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel5_IRQHandler
* Description    : This function handles DMA1 Channel 5 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel5_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel6_IRQHandler
* Description    : This function handles DMA1 Channel 6 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel6_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA1_Channel7_IRQHandler
* Description    : This function handles DMA1 Channel 7 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA1_Channel7_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : ADC1_2_IRQHandler
* Description    : This function handles ADC1 and ADC2 global interrupts requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void ADC1_2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USB_HP_CAN_TX_IRQHandler
* Description    : This function handles USB High Priority or CAN TX interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USB_HP_CAN_TX_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USB_LP_CAN_RX0_IRQHandler
* Description    : This function handles USB Low Priority or CAN RX0 interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USB_LP_CAN_RX0_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : CAN_RX1_IRQHandler
* Description    : This function handles CAN RX1 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAN_RX1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : CAN_SCE_IRQHandler
* Description    : This function handles CAN SCE interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAN_SCE_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI9_5_IRQHandler
* Description    : This function handles External lines 9 to 5 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI9_5_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_BRK_IRQHandler
* Description    : This function handles TIM1 Break interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_BRK_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_UP_IRQHandler
* Description    : This function handles TIM1 overflow and update interrupt 
*                  request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_UP_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_TRG_COM_IRQHandler
* Description    : This function handles TIM1 Trigger and commutation interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_TRG_COM_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_CC_IRQHandler
* Description    : This function handles TIM1 capture compare interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_CC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM2_IRQHandler
* Description    : This function handles TIM2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM2_IRQHandler(void)
	{
	if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)
		{
		/* Clear TIM2 Capture Compare1 interrupt pending bit*/
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);
//		GPIO_WriteBit(GPIOA, GPIO_Pin_5, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_5)));
		capture = TIM_GetCapture1(TIM2);
		TIM_SetCompare1(TIM2, capture + TIME_1S);
		Lcd_counter++;
		Data_time++;
		Alarm_count++;
		DT_Counter++;
		if((DT_Counter >= TIMEING)&&(set_time))				//超过TIMEING关闭电表数据接收
			{
			set_time = 0;
			cleardata = 1;
			}
		if(Lcd_counter >= LCD_ONTIME)
			{
			Lcd_counter = 0;
			lcd_flag = 0;
			linktest = 0;
			}
		if(Data_time >= DATA_TIMR)
			{
			d_start = 0;
			buffer_flag = 0;
			RxCounter3 = 0;
			}
		if((Alarm_count > ALARM_TURE)&&(alarm_time0))
			{
			alarm_time0 = 0;
			Alarm_count	= 0;
			}
		if((Alarm_count > ALARM_FAUSE)&&(!alarm_time0))
			{
			alarm_time0 = 1;
			Alarm_count	= 0;
			}
		}
	else if (TIM_GetITStatus(TIM2, TIM_IT_CC2) != RESET)
		{
		/* Clear TIM2 Capture Compare2 interrupt pending bit*/
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
		capture = TIM_GetCapture2(TIM2);
		TIM_SetCompare2(TIM2, capture + TIME_250MS);
		if(alarm_time)											//警报处理
			{
			if(alarm_flg!=0)
				{
				if((alarm_canc)||(!alarm_time0))
					{
					GPIO_BEEP_OFF();
					GPIO_ALED_0N_OFF();
					}
				else
					{
					GPIO_BEEP_0N_OFF();
					GPIO_ALED_0N_OFF();
					}
				}
			}
		else if(alarm_flg!=0)
			{
			GPIO_ALED_0N_OFF();
			}		
		}
	else if (TIM_GetITStatus(TIM2, TIM_IT_CC3) != RESET)
		{
		/* Clear TIM2 Capture Compare3 interrupt pending bit*/
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC3);
		capture = TIM_GetCapture3(TIM2);
		TIM_SetCompare3(TIM2, capture + TIME_25MS);		
		lcd_refur = 1;
		}
	if (TIM_GetITStatus(TIM2, TIM_IT_CC4) != RESET)
		{
		/* Clear TIM2 Capture Compare4 interrupt pending bit*/
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC4);
		capture = TIM_GetCapture4(TIM2);
		TIM_SetCompare4(TIM2, capture + TIME_10MS); 
//		cont++;
//		if(cont == 20)
//			{
//			cont = 0;
//			GPIO_COMLED_0N_OFF();
//			}
		if((GPIO_KEYU_F())&&(key_up == 1))										    //向上键处理
			{
			linktest = 0;
			KeyU_count++;
			Lcd_counter = 0;
			}  
		if(KeyU_count >= KEYDELAY)
			{
			if(lcd_flag == 1)
				{			
				KeyU_count = 0;
				Key_value++;
				key_plus = 1;
				Key0_value = 0;
				key_up = 0;
				Page_dis++;
				}
			else
				{
				lcd_flag = 1;
				KeyU_count = 0;
				key_plus = 1;
				Key0_value = 0;
				Key_value = 0;
				key_up = 0;
				}
			}
		if((GPIO_KEYD_F())&&(key_up == 1))										 //向下键处理
			{
			linktest = 0;
			KeyD_count++;
			Lcd_counter = 0;
			}
		if(KeyD_count >= KEYDELAY)
			{
			if(lcd_flag == 1)
				{
				KeyD_count = 0;
				Key_value--;
				key_plus = 0;
				Key0_value = 0;
				key_up = 0;
				Page_dis--;			
				}
			else
				{
				lcd_flag = 1;
				KeyD_count = 0;
				key_plus = 0;
				Key0_value = 0;
				Key_value = 0;
				key_up = 0;
				}
			} 
		if((GPIO_KEYQ_F())&&(key_up == 1))										   //确认键处理
			{
			lcd_flag = 1;
			linktest = 0;
			KeyQ_count++;
			KeyQ1_count++;
			}
		if(KeyQ_count == CANCALALARMTIME)					   
			{
			Key0_value = 0xff;	
			}
		if(KeyQ1_count >= KEYLONG)
			{
			Key0_value = 0x55;
			KeyQ1_count = 0;
			Lcd_counter = 0;
			key_up = 0;
			}
		if((GPIO_KEYU_T())&&(GPIO_KEYD_T())&&(GPIO_KEYQ_T())) 					//按键释放处理
			{
			Key_upcount++;
			}
		if(Key_upcount >= 0x03)
			{
			key_up = 1;
			KeyU_count = 0;
			KeyD_count = 0;
			KeyQ_count = 0;
			KeyQ1_count = 0;
			Key_upcount = 0; 
			}
		}
	}

/*******************************************************************************
* Function Name  : TIM3_IRQHandler
* Description    : This function handles TIM3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM3_IRQHandler(void)
{	
}

/*******************************************************************************
* Function Name  : TIM4_IRQHandler
* Description    : This function handles TIM4 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C1_EV_IRQHandler
* Description    : This function handles I2C1 Event interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C1_EV_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C1_ER_IRQHandler
* Description    : This function handles I2C1 Error interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C1_ER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C2_EV_IRQHandler
* Description    : This function handles I2C2 Event interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C2_EV_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C2_ER_IRQHandler
* Description    : This function handles I2C2 Error interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C2_ER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SPI1_IRQHandler
* Description    : This function handles SPI1 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SPI2_IRQHandler
* Description    : This function handles SPI2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USART1_IRQHandler
* Description    : This function handles USART1 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART1_IRQHandler(void)
	{ 
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
		{
		/* Read one byte from the receive data register */
		RxBuffer1[RxCounter1++] = USART_ReceiveData(USART1);	      
		}
  
	if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET)
		{   
		/* Write one byte to the transmit data register */
		USART_SendData(USART1, TxBuffer1[TxCounter1++]); 
		if(TxCounter1 >= MaxNbrofTx1)
		    {				
		    /* Disable the USART1 Transmit interrupt */
			USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
		    }    
		}
	}

/*******************************************************************************
* Function Name  : USART2_IRQHandler
* Description    : This function handles USART2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART2_IRQHandler(void)
	{
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
		{
		/* Read one byte from the receive data register */
		RxBuffer2[RxCounter2++] = USART_ReceiveData(USART2);
		}
	if(USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
		{   
		/* Write one byte to the transmit data register */
		USART_SendData(USART2, TxBuffer2[TxCounter2++]); 
		if(TxCounter2 >= MaxNbrofTx2)
		    {				
		    /* Disable the USART1 Transmit interrupt */
			USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
		    }    
		}
	/* If the USART2 detects a parity error */
	if(USART_GetITStatus(USART2, USART_IT_PE) != RESET)
		{
		while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET)
			{
			}
		/* Clear the USART2 Parity error pending bit */
		USART_ClearITPendingBit(USART2, USART_IT_PE);
		USART_ReceiveData(USART2);
		}
	}

/*******************************************************************************
* Function Name  : USART3_IRQHandler
* Description    : This function handles USART3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART3_IRQHandler(void)
	{
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
		{
		GPIO_COMLED_ON();
		/* Read one byte from the receive data register */
		RxBuffer3[RxCounter3++] = USART_ReceiveData(USART3);
		if((RxBuffer3[RxCounter3-1] == HEAD)||(1 == d_start))
			{
			d_start = 1;
			}
		else if((RxBuffer3[RxCounter3] != HEAD)&&(0 == d_start))
			{
			RxCounter3 = 0;
			}
		if(RxCounter3 == 0x0a)
			{
			D_len = RxBuffer3[9]+12;
			}
		if(RxCounter3 == D_len)
			{
			buffer_flag = 1;
			}	      
		Data_time = 0;
		GPIO_COMLED_OFF();
		}
  
	if(USART_GetITStatus(USART3, USART_IT_TXE) != RESET)
		{   
		/* Write one byte to the transmit data register */
		USART_SendData(USART3, TxBuffer3[TxCounter3++]); 
		if(TxCounter3 >= MaxNbrofTx3)
		    {				
		    /* Disable the USART1 Transmit interrupt */
			USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
		    }    
		}
	}


/*******************************************************************************
* Function Name  : EXTI15_10_IRQHandler
* Description    : This function handles External lines 15 to 10 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI15_10_IRQHandler(void)
{}

/*******************************************************************************
* Function Name  : RTCAlarm_IRQHandler
* Description    : This function handles RTC Alarm interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTCAlarm_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USBWakeUp_IRQHandler
* Description    : This function handles USB WakeUp interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USBWakeUp_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM8_BRK_IRQHandler
* Description    : This function handles TIM8 Break interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_BRK_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM8_UP_IRQHandler
* Description    : This function handles TIM8 overflow and update interrupt 
*                  request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_UP_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM8_TRG_COM_IRQHandler
* Description    : This function handles TIM8 Trigger and commutation interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_TRG_COM_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM8_CC_IRQHandler
* Description    : This function handles TIM8 capture compare interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_CC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : ADC3_IRQHandler
* Description    : This function handles ADC3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void ADC3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : FSMC_IRQHandler
* Description    : This function handles FSMC global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void FSMC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SDIO_IRQHandler
* Description    : This function handles SDIO global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SDIO_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM5_IRQHandler
* Description    : This function handles TIM5 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM5_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SPI3_IRQHandler
* Description    : This function handles SPI3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : UART4_IRQHandler
* Description    : This function handles UART4 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UART4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : UART5_IRQHandler
* Description    : This function handles UART5 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UART5_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM6_IRQHandler
* Description    : This function handles TIM6 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM6_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM7_IRQHandler
* Description    : This function handles TIM7 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM7_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA2_Channel1_IRQHandler
* Description    : This function handles DMA2 Channel 1 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA2_Channel1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA2_Channel2_IRQHandler
* Description    : This function handles DMA2 Channel 2 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA2_Channel2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA2_Channel3_IRQHandler
* Description    : This function handles DMA2 Channel 3 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA2_Channel3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMA2_Channel4_5_IRQHandler
* Description    : This function handles DMA2 Channel 4 and DMA2 Channel 5
*                  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA2_Channel4_5_IRQHandler(void)
{
}

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
