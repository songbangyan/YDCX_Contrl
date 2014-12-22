#include"config.h"


/*************����ͷβ��У��*****************/
void CheckHE(void)
	{
	u8 i;
	buffer_flag = 0;
	RxCounter3 = 0;
	d_start = 0;
	if((RxBuffer3[0] == HEAD)&&(RxBuffer3[7] == HEAD))
		{
		if(RxBuffer3[D_len-1] == END)
			{
			for(i=0;i<D_len;i++)
				{
				Data_tmp[i]=RxBuffer3[i];
				}
			data_t = 1;
			}
		else
			{
			data_t = 0;
			}
		}
	else
		{
		data_t = 0;
		}		
	}

/*************�������У��*****************/
void CheckSum(void)
	{
	u8 i,sum;
	CheckHE();
	if(1 == data_t)
		{
		sum = 0;
		for(i=0;i<D_len-2;i++)
			{
			sum += Data_tmp[i];
			}
		if(Data_tmp[D_len-2] == sum)
			{
			data_t = 1;
			}
		else
			{
			data_t = 0;
			}
		}
	}

/*************��ַУ��*****************/
void CheckADD(void)
	{
	u8 i;
	u8 tmp1=0,tmp2=0;
	CheckSum();	
	if(1 == data_t)
		{
		for(i=0;i<6;i++)
			{
			if(Data_tmp[i+1] == 0xff)			  		//�ж��Ƿ�㲥��ַ
				{
				tmp1++;
				}
		   	if(Data_tmp[i+1] == DX_Addr[5-i])			//�ж��Ƿ��Ǳ��������ַ
		   		{
				tmp2++;
				}
			}
		if(tmp2 == 0x06)
			{
			mac_t = 1;
			data_t = 1;
			}
		else if(tmp1 == 0x06)
			{
			mac_t = 0;
			data_t = 1;
			}
		else 
			{
			data_t = 0;
			}
		}
	}

/*************���ݰ�����*****************/
void BagPack(void)
	{
	u8 temp=0;
	u8 i;
	CheckADD();
	if(1 == data_t)
		{
		temp = (Data_tmp[8]&0x1f);
		switch(temp)
			{
			case(CON1):
				if(1 == mac_t)
					{
					Reset_fun();				
					}
				break;
			case(CON2):
				if(1 == mac_t)
					{
					reset = 0;
					set_time = 0;
					Set_fun();
					if(reset == 0)
						{
						Report_T();
						}
					}
				break;
			case(CON3):
				Check_fun();
				break;
			case(CON4):
				if((1 == mac_t)&&(1 == set_time))
					{
					DT_Counter = 0; 
					Dbdata_fun();
					Report_T();
					changedata = 1;
					}					
				break;
			case(CON5):
				Linktest_fun();
				break;
			case(CON6):
				if(mac_t)
					{
					CheckT_fun();
					}				
				break;
			default:
			    buffer_flag=0;
				break;
			}		
		for(i=0;i<MAXBUFFER;i++)
			{
			Data_tmp[i]=0x00;
			}
		}	
	}

/*************��λ����*****************/
void Reset_fun(void)
	{
	u8 Data_Len,Data_Lent;
	Data_Len = 0x0a;
	Data_Lent = Data_tmp[9];
	while(Data_Lent!=0)
		{
		if((Data_tmp[Data_Len] == 0x34))						 //Ӳ����ʼ��
			{
			Report_T();
			Delay(0x580000);			 						 //��ʱ��Լ1152mS
			NVIC_SystemReset();
//		NVIC_GenerateSystemReset();							 //ϵͳ��λ
			}
		if((Data_tmp[Data_Len] == 0x35))						 //������ʼ��
			{
			Report_T();
			Delay(0x580000);			 						 //��ʱ��Լ1152mS
			NVIC_SystemReset();
//			NVIC_GenerateSystemReset();							 //ϵͳ��λ
			}	
		if((Data_tmp[Data_Len] == 0x36))						 //��������ʼ��
			{
			Report_T();
			DataInit();
			Delay(0x580000);			 						 //��ʱ��Լ1152mS
			NVIC_SystemReset();
//			NVIC_GenerateSystemReset();							 //ϵͳ��λ
			}
		if((Data_tmp[Data_Len] == 0x37))					 	//�ָ���������
			{
			Report_T();
			DataInit();			
			Delay(0x580000);			 						 //��ʱ��Լ1152mS
			NVIC_SystemReset();
//			NVIC_GenerateSystemReset();							 //ϵͳ��λ
			}
		else
			{
			Data_Lent =	0;
			}
		}
	}

/*************��������*****************/
void Set_fun(void)
	{
	volatile FLASH_Status FLASHStatus;
	u8 NbrOfPage;
	u8 Data_Len,Data_Lent;
	u8 i,temp;
	u16 tmp;
	FLASHStatus = FLASH_COMPLETE;
	Data_Len = 0x0a;
	Data_Lent = Data_tmp[9];
	for(i=0;i<Data_Lent;i++)
		{
		Data_tmp[Data_Len+i] -= OFFSET;
		if(((Data_tmp[Data_Len+i]>>4)<=0x09)&&((Data_tmp[Data_Len+i]&0x0f)<=0x09))
			{
			Data_tmp[Data_Len+i] += OFFSET;
			}
		else
			{
			Data_Lent = 0;
			reset = 1;
			}
		}
	while(Data_Lent!=0)
		{
		if((Data_tmp[Data_Len] == 0x34)&&(Data_Lent!=0))						   //����MAC��ַ
			{
			Data_tmp[Data_Len+1+i] -= OFFSET;
			/* Unlock the Flash Program Erase controller */
			FLASH_Unlock();			
			/* Define the number of page to be erased */
			NbrOfPage = (EndAddr - StartAddr) / FLASH_PAGE_SIZE; 
			/* Clear All pending flags */
			FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);			
			/* Erase the FLASH pages */
			for(i = 0; (i < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); i++)
				{
				FLASHStatus = FLASH_ErasePage(StartAddr + (FLASH_PAGE_SIZE * i));
				}
			for(i=0;((i<3)&& (FLASHStatus == FLASH_COMPLETE));i++)
				{
				DX_Addr[5-i*2] =Data_tmp[Data_Len+1+i*2]- OFFSET;
				DX_Addr[4-i*2] =Data_tmp[Data_Len+2+i*2] - OFFSET;
				tmp = Data_tmp[Data_Len+1+i*2]- OFFSET;
				tmp = (Data_tmp[Data_Len+2+i*2] - OFFSET) | tmp<<8;
				FLASH_ProgramHalfWord(StartAddr+(4-i*2), tmp);				   //��ŵ�ַ
				}
			/* lock the Flash Program Erase controller */
			FLASH_Lock();
			GPIO_ZBRST_ON();
			Delay(0xfff);
			GPIO_ZBRST_OFF();  
			Data_Len += 0x07;
			Data_Lent -=0x07;
			dbaddrtrue = 1;					
			}
		if((Data_tmp[Data_Len] == 0x35)&&(Data_Lent!=0))							  //����ַ
			{
			for(i=0;i<6;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				}
			Data_Len += 0x07;
			Data_Lent -=0x07;
			}
		if((Data_tmp[Data_Len] == 0x36)&&(Data_Lent!=0))
			{														  //������룬�˰���ʱ����
			Data_Len += 0x03;
			Data_Lent -=0x03;
			}
		if((Data_tmp[Data_Len] == 0x37)&&(Data_Lent!=0))							  //����ʱ��
			{
			if(mac_t)
				{
				temp = Bcd2Hex(Data_tmp[Data_Len+1] - OFFSET);
				if(temp >= 60)
					{
					reset = 1;
					}
				temp = Bcd2Hex(Data_tmp[Data_Len+2] - OFFSET);
				if(temp >= 60)
					{
					reset = 1;
					}
				temp = Bcd2Hex(Data_tmp[Data_Len+3] - OFFSET);
				if(temp >= 24)
					{
					reset = 1;
					}
				temp = Bcd2Hex(Data_tmp[Data_Len+4] - OFFSET);
				if(temp >= 32)
					{
					reset = 1;
					}
				temp = Bcd2Hex(Data_tmp[Data_Len+5] - OFFSET);
				if(temp >= 13)
					{
					reset = 1;
					}
				if(reset == 0)
					{
					Now_time.sec = Bcd2Hex(Data_tmp[Data_Len+1] - OFFSET);
					Now_time.min = Bcd2Hex(Data_tmp[Data_Len+2] - OFFSET);
					Now_time.hour = Bcd2Hex(Data_tmp[Data_Len+3] - OFFSET);
					Now_time.day = Bcd2Hex(Data_tmp[Data_Len+4] - OFFSET);
					Now_time.mon = Bcd2Hex(Data_tmp[Data_Len+5] - OFFSET);
  					Now_time.year = Bcd2Hex(Data_tmp[Data_Len+6] - OFFSET);
					/* RTC Configuration */
					RTC_Configuration();
					/* Wait until last write operation on RTC registers has finished */
					RTC_WaitForLastTask();
					/* Change the current time */
					RTC_SetCounter(Now_time.hour*3600+Now_time.min*60+Now_time.sec);
					/* Wait until last write operation on RTC registers has finished */
					RTC_WaitForLastTask();
					DT_Counter = 0;
					timed = 1;
					set_time = 1;						
					}
				else
					{
					set_time = 0;
					}
				}
			Data_Len += 0x07;
			Data_Lent -=0x07;
			} 
		if((Data_tmp[Data_Len] == 0x38)&&(Data_Lent!=0))
			{
			for(i=0;i<4;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
//				Byte_Program(LOCAL_DALARMVALUE+i,Data_tmp[Data_Len+1+i]);	   //���������澯ֵ
				}
			Data_Len += 0x05;
			Data_Lent -=0x05;
			}
		if((Data_tmp[Data_Len] == 0x39)&&(Data_Lent!=0))
			{
			for(i=0;i<4;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
//				Byte_Program(LOCAL_JALARMVALUE+i,Data_tmp[Data_Len+1+i]);	   //�������澯ֵ
				}
			Data_Len += 0x05;
			Data_Lent -=0x05;
			}
		else
			{
			if((Data_tmp[Data_Len] <= 0x33)||(Data_tmp[Data_Len] >= 0x3a))
				{
				Data_Lent =0;
				}
			}
		}
	}


/*************������ѯ*****************/
void Check_fun(void)
	{
	u8 Data_Len,Data_Lent;
	u8 i;
	u32 TimeVar;
	u8 tmp[34],len=0;
	Data_Len = 0x0a;
	Data_Lent = Data_tmp[9];
	while(Data_Lent!=0)
		{
		if((Data_tmp[Data_Len] == 0x34)&&(Data_Lent!=0))						  //��ѯ����ַ
			{
			tmp[len] = 0x34;
			len++;
			for(i=0;i<6;i++)
				{
				tmp[len] = DX_Addr[5-i];	   			  //��ŵ�ַ 
				tmp[len] += OFFSET;				
				len++;
				}
			Data_Len += 0x01;
			Data_Lent -=0x01;
			}
		if((Data_tmp[Data_Len] == 0x35)&&(Data_Lent!=0))						  //��ѯMAC��ַ
			{
			tmp[len] = 0x35;
			len++;
			for(i=0;i<6;i++)
				{
				tmp[len] = DX_Addr[5-i];	   			  //��ŵ�ַ 
				tmp[len] += OFFSET;				
				len++;
				}
			Data_Len += 0x01;
			Data_Lent -=0x01;
			}
		if((Data_tmp[Data_Len] == 0x36)&&(Data_Lent!=0))
			{														  //��ѯ���룬�˰���ʱ����
			tmp[len] = 0x36;
			len++;
			tmp[len] = VERL;										  //�汾�ŵ�λ
			len++;
			tmp[len] = VERH;										  //�汾�Ÿ�λ
			len++;
			Data_Len += 0x01;
			Data_Lent -=0x01;
			}
		if((Data_tmp[Data_Len] == 0x37)&&(Data_Lent!=0))							  //��ѯʱ��
			{
			TimeVar = RTC_GetCounter();
			Now_time.hour = TimeVar / 3600;
			Now_time.min = (TimeVar % 3600) / 60;
			Now_time.sec = (TimeVar % 3600) % 60;
			tmp[len] = 0x37;
			len++;
			tmp[len] = Hex2Bcd(Now_time.sec);
			tmp[len] += OFFSET;
			len++;
			tmp[len] = Hex2Bcd(Now_time.min);
			tmp[len] += OFFSET;
			len++;
			tmp[len] = Hex2Bcd(Now_time.hour);
			tmp[len] += OFFSET;
			len++;
			tmp[len] = Hex2Bcd(Now_time.day);
			tmp[len] += OFFSET;
			len++;
			tmp[len] = Hex2Bcd(Now_time.mon);
			tmp[len] += OFFSET;
			len++;
			tmp[len] = Hex2Bcd(Now_time.year);
			tmp[len] += OFFSET;
			len++;								
			Data_Len += 0x01;
			Data_Lent -=0x01;
			} 
		if((Data_tmp[Data_Len] == 0x38)&&(Data_Lent!=0))
			{
			tmp[len] = 0x38;
			len++;
			for(i=0;i<4;i++)
				{				
				tmp[len] = 0x00;	   //��ѯ���������澯ֵ	����δʹ��
				tmp[len] += OFFSET;
				len++;
				}
//			if(D_Feil[0] == BESET)
//				{
//				tmp[len-3] = 0xaa;
//				}
//			if(D_Biaoma[0] == BESET)
//				{
//				tmp[len-2] = 0xaa ;
//				}
//			if(D_Djleij[0] == BESET)
//				{
//				tmp[len-1] = 0xaa;
//				}

			Data_Len += 0x01;
			Data_Lent -=0x01;
			}
		if((Data_tmp[Data_Len] == 0x39)&&(Data_Lent!=0))
			{
			tmp[len] = 0x39;
			len++;
			tmp[len] = 0;
			tmp[len] += OFFSET;
			len++;
			tmp[len] = Hex2Bcd(ALRV);
			tmp[len] += OFFSET;
			len++;
			tmp[len] = 0;
			tmp[len] += OFFSET;
			len++;
			tmp[len] = 0;
			tmp[len] += OFFSET;
			len++;

//			for(i=0;i<4;i++)
//				{				
//				tmp[len] = 0xff;	  //��ѯ�������澯ֵ	����δʹ��
//				len++;
//				}
			Data_Len += 0x01;
			Data_Lent -=0x01;
			}
		else
			{
			if((Data_tmp[Data_Len] <= 0x33)||(Data_tmp[Data_Len] >= 0x3a))
				{
				Data_Lent =0;
				}
			}
		}
	Data_tmp[0]=HEAD;
	for(i=0;i<6;i++)
		{
		Data_tmp[1+i] = DX_Addr[5-i];
		}
	Data_tmp[7]=HEAD;
	Data_tmp[8]=0x83;
	Data_tmp[9]=len;
	for(i=0;i<len;i++)
		{
		Data_tmp[10+i] = tmp[i];
		}
	Data_tmp[10+len] = 0x00;
	for(i=0;i<(10+len);i++)
		{
		Data_tmp[10+len] += Data_tmp[i];
		}
	Data_tmp[11+len] = END;
	USART3send(Data_tmp,(12+len));  
//	USART1send(Data_tmp,(12+len));  
	}

/*************�������*****************/
void Dbdata_fun(void)
	{
	u8 Data_Len,Data_Lent;
	u8 i;
	u32 temp;
	Data_Len = 0x0a;
	Data_Lent = Data_tmp[9];
	while(Data_Lent!=0)
		{
		if((Data_tmp[Data_Len] == D_FEILV)&&(Data_Lent!=0))								  //������
			{
			for(i=0;i<16;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Feil[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}	   
				}
			if((i == 16))
				{
				D_Feil[0] = BESET;							 //�����õ��				
				}
			Data_Len += 0x11;
			Data_Lent -=0x11;
			}

		if((Data_tmp[Data_Len] == D_ZHUANGTAI)&&(Data_Lent!=0))								  //���״̬
			{
			for(i=0;i<14;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				}
			i = Data_tmp[Data_Len+5];
			if((i&0x80) == 0x80)
				{
				alarm_flg = 1;
				Alarm_count = 0;
				alarm_time0 = 1;
				}
			else
				{
				alarm_flg = 0;
				alarm_canc = 0;
				GPIO_BEEP_OFF();
				GPIO_ALED_OFF();
				Alarm_Abo(); 				
				}
			Data_Len += 15;
			Data_Lent -=15;
			}

		if((Data_tmp[Data_Len] == D_DANGQBM)&&(Data_Lent!=0))								  //��ǰ������
			{
			for(i=0;i<20;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Biaoma[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 20))
				{
				D_Biaoma[0] =BESET;							  //�����õ���					
				}
			Data_Len += 21;
			Data_Lent -=21;
			}

		if((Data_tmp[Data_Len] == D_SHENGYD)&&(Data_Lent!=0))								   //��ǰʣ�����
			{
			for(i=0;i<5;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Sdian[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 5))
				{
				D_Sdian[0] =BESET;							  //������ʣ����� 				
				}
			Data_Len += 6;
			Data_Lent -=6;
			}

		if((Data_tmp[Data_Len] == D_SHENGYJ)&&(Data_Lent!=0))								   //��ǰʣ����
			{
			for(i=0;i<5;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Smoney[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 5))
				{
				D_Smoney[0] =BESET;						   //������ʣ����
				temp=((D_Smoney[2]&0x0f))+((D_Smoney[2]>>4)*10)+((D_Smoney[3]&0x0f)*100)+((D_Smoney[3]>>4)*1000);
				if((D_Smoney[4]==0)&&(D_Smoney[5]==0))
					{
					if(temp < ALRV*100)
						{
						alarm_flg = 1;
						Alarm_count = 0;
						alarm_time0 = 1;						
						}
					else
						{
						if(temp > ((X_Smoney[2]&0x0f))+((X_Smoney[2]>>4)*10)+((X_Smoney[3]&0x0f)*100)+((X_Smoney[3]>>4)*1000))
							{
							alarm_flg = 0;
//							alarm_canc = 0;
							GPIO_BEEP_OFF();
							GPIO_ALED_OFF(); 						
							}
						}
					}
				else
					{
					alarm_flg = 0;
//					alarm_canc = 0;
					GPIO_BEEP_OFF();
					GPIO_ALED_OFF();					
					}
				}
			Data_Len += 6;
			Data_Lent -=6;															 
			}

		if((Data_tmp[Data_Len] == D_ZONGGDC)&&(Data_Lent!=0))								  //�ܹ������
			{
			for(i=0;i<2;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Goudc[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 2))
				{
				D_Goudc[0] = BESET;							//�������ܹ������					
				}
			Data_Len += 3;
			Data_Lent -=3;
			}
		if((Data_tmp[Data_Len] == D_LASTGT)&&(Data_Lent!=0))							  //���һ�ι���ʱ��
			{
			for(i=0;i<5;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Lgoudt[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 5)&&(Data_tmp[Data_Len+3]!=0)&&(Data_tmp[Data_Len+4]!=0))
				{
				D_Lgoudt[0] = BESET;							//���������һ�ι���ʱ��				
				}
			Data_Len += 6;
			Data_Lent -= 6;
			}

		if((Data_tmp[Data_Len] == D_DANGQLJD)&&(Data_Lent!=0))									//��ǰ�����ۼ�
			{
			for(i=0;i<20;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Djleij[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 20))
				{
				D_Djleij[0] = BESET;								//�����õ�ǰ�����ۼ�
				}
			Data_Len += 21;
			Data_Lent -=21;
			}

		if((Data_tmp[Data_Len] == D_SHANGZQD)&&(Data_Lent!=0))									//��һ�����ۼ�
			{
			for(i=0;i<4;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
//				��ȷ���Ƿ���Ҫ
				}
			Data_Len += 5;
			Data_Lent -=5;
			}
		if((Data_tmp[Data_Len] == D_LEIJGD)&&(Data_Lent!=0))								  //�ۼƹ�����
			{
			for(i=0;i<4;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Ljgoud[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 4))
				{
				D_Ljgoud[0] = BESET;							   //�������ۼƹ�����
				}
			Data_Len += 5;
			Data_Lent -=5;
			}

		if((Data_tmp[Data_Len] == D_LASTGDJ)&&(Data_Lent!=0))							  //���һ�ι�����
			{
			for(i=0;i<4;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Lgoudj[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 4))
				{
				D_Lgoudj[0] = BESET;							   //���������һ�ι�����
				}
			Data_Len += 5;
			Data_Lent -=5;
			}

		if((Data_tmp[Data_Len] == D_LEIJG)&&(Data_Lent!=0))							  //�ۼƹ�����
			{
			for(i=0;i<4;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Leigoudj[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 4))
				{
				D_Leigoudj[0] = BESET;							   //�������ۼƹ�����
				}
			Data_Len += 5;
			Data_Lent -=5;
			}	
				
		if((Data_tmp[Data_Len] == D_JTDJ)&&(Data_Lent!=0))							  //��ǰ���ݵ��
			{
			for(i=0;i<4;i++)
				{
				Data_tmp[Data_Len+1+i] -= OFFSET;
				if(((Data_tmp[Data_Len+1+i]>>4)<=0x09)&&((Data_tmp[Data_Len+1+i]&0x0f)<=0x09))
					{
					D_Jietdj[i+1] = Data_tmp[Data_Len+1+i];
					}
				else
					{
					break;
					}
				}
			if((i == 4))
				{
				D_Jietdj[0] = BESET;							   //�����ý��ݵ��
				}
			Data_Len += 5;
			Data_Lent -=5;
			}		
		else
			{
			if((Data_tmp[Data_Len] <= 0x33)||(Data_tmp[Data_Len] >= D_JTDJ+1))
				{
				Data_Lent =0;
				}
			}
		}
	}	


/*************��·����*****************/
void Linktest_fun(void)
	{
	linktest = 1;
	lcd_flag = 1;
	}

/*************�¼���ѯ*****************/
void CheckT_fun(void)
	{
	u8 i; 
	u8 tmp;
	tmp = Data_tmp[10]-OFFSET;
	Data_tmp[0]=HEAD;
	for(i=0;i<6;i++)
		{
		Data_tmp[1+i]=DX_Addr[5-i];
		}
	Data_tmp[7]=HEAD;
	Data_tmp[8]=0x86;
	Data_tmp[9]=0x08;
	Data_tmp[10]=0x34;
	for(i=0;i<7;i++)
		{
		Data_tmp[11+i] = (*(vu32*) (StartAddr+OFFSET_JL+tmp*OFFSET_JLL+i))+0x33;
		}
	Data_tmp[18] = 0x00;
	for(i=0;i<(18);i++)
		{
		Data_tmp[18] += Data_tmp[i];
		}
	Data_tmp[19] = END;
	USART3send(Data_tmp,20);
	}

/*************��ʼ��������������*****************/
void DataInit(void)
	{
	volatile FLASH_Status FLASHStatus;
	u8 NbrOfPage;
	u8 i;
	FLASHStatus = FLASH_COMPLETE;
	/* Unlock the Flash Program Erase controller */
	FLASH_Unlock();	
	/* Define the number of page to be erased */
	NbrOfPage = (EndAddr - StartAddr) / FLASH_PAGE_SIZE;
	/* Clear All pending flags */
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);			
	/* Erase the FLASH pages */
	for(i = 0; (i < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); i++)
		{
		FLASHStatus = FLASH_ErasePage(StartAddr + (FLASH_PAGE_SIZE * i));
		}
	/* lock the Flash Program Erase controller */
	FLASH_Lock();	
	}

/*************ȷ��Ӧ��*****************/
void Report_T(void)
	{
	u8 i;
	Data_tmp[0]=0xa8;
		for(i=0;i<6;i++)
		{
		Data_tmp[1+i] = DX_Addr[5-i];
		}
	Data_tmp[7]=0xa8;
	Data_tmp[8]=0x80;
	Data_tmp[9]=0x01;
	Data_tmp[10]=0x34;				   //ȷ��
	Data_tmp[11]=0x00;
	for(i=0;i<11;i++)
		{
		Data_tmp[11] += Data_tmp[i];
		}
	Data_tmp[12]=0x16;
	USART3send(Data_tmp,13);
	}

/****************��ʾ���ݵĸ���***********************/
void Change_Dis(void)
	{
	u8 i;
	u32	TimeVar;
	TimeVar = RTC_GetCounter();
	Now_time.hour = TimeVar / 3600;
	X_DTime[0] = BESET;
	X_DTime[1] = Hex2Bcd(Now_time.hour);
	X_DTime[2] = Hex2Bcd(Now_time.day);
	X_DTime[3] = Hex2Bcd(Now_time.mon);
	for(i=0;i<17;i++)
		{
		X_Feil[i] = D_Feil[i];				//�����ʼĴ���
		}
	for(i=0;i<21;i++)
		{
		X_Biaoma[i] = D_Biaoma[i];			//��ǰ����Ĵ���
		}
	for(i=0;i<6;i++)
		{
		X_Sdian[i] = D_Sdian[i];				//ʣ�����
		}
	for(i=0;i<6;i++)
		{
		X_Smoney[i] = D_Smoney[i];			//ʣ����
		}
	for(i=0;i<3;i++)
		{
		X_Goudc[i] = D_Goudc[i];				//�ܹ������
		}
	for(i=0;i<6;i++)
		{
		X_Lgoudt[i] = D_Lgoudt[i];			//���һ�ι���ʱ��
		}
	for(i=0;i<21;i++)
		{
		X_Djleij[i] = D_Djleij[i];			//��ǰ�����ۻ�
		}
	for(i=0;i<5;i++)
		{
		X_Ljgoud[i] = D_Ljgoud[i];			//�ۼƹ�����
		}
	for(i=0;i<5;i++)
		{
		X_Lgoudj[i] = D_Lgoudj[i];			//���һ�ι�����
		}
	for(i=0;i<5;i++)
		{
		X_Leigoudj[i] = D_Leigoudj[i];			//�ۼƹ�����
		}
	for(i=0;i<5;i++)
		{
		X_Jietdj[i] = D_Jietdj[i];			//��ǰ���ݵ��
		}
	}
/****************����ѽ��յ�����***********************/
void ClearData(void)
	{
	D_Feil[0] = 0;  		
	D_Biaoma[0]	= 0;	
	D_Sdian[0] = 0;
	D_Smoney[0] = 0;
	D_Goudc[0]  = 0;
	D_Lgoudt[0] = 0;
	D_Djleij[0]	 = 0;
	D_Ljgoud[0] = 0;
	D_Lgoudj[0]	= 0;
	D_Leigoudj[0] = 0;
	D_Jietdj[0]	= 0;	
	}
/****************�澯���by�����¼���¼***********************/
void Alarm_reg(void)
	{
	u8 i,NbrOfPage;
	u16 tmp;
	u8 temp[7];
	u32 TimeVar;
	volatile FLASH_Status FLASHStatus;
	FLASHStatus = FLASH_COMPLETE;
	alarm_canc = 1;
 	for(i=0;i<6;i++)
		{
		temp[i] = (*(vu32*) (StartAddr+i));
		}
	temp[6] = (*(vu32*) (StartAddr+OFFSET_JL+1));
 	for(i=0;i<MAXBUFFER;i++)
		{
		RxBuffer1[i] = (*(vu32*) (StartAddr+OFFSET_JL+i));
		} 
	/* Unlock the Flash Program Erase controller */
	FLASH_Unlock();	
	/* Define the number of page to be erased */
	NbrOfPage = (EndAddr - StartAddr) / FLASH_PAGE_SIZE;
	/* Clear All pending flags */
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);			
	/* Erase the FLASH pages */
	for(i = 0; (i < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); i++)
		{
		FLASHStatus = FLASH_ErasePage(StartAddr + (FLASH_PAGE_SIZE * i));
		}
	for(i =0;((i<3)/*&& (FLASHStatus == FLASH_COMPLETE)*/);i++)
		{
		tmp = temp[i*2+1];
		tmp = temp[i*2]|tmp<<8;
		FLASHStatus = FLASH_ProgramHalfWord(StartAddr+i*2, tmp);	
		}

	temp[0] = ALAEM_CAC;
	temp[1] = temp[6];
	if(temp[1]>=0x10)
		{
		temp[1] = 0;
		}
	temp[1]++;
	TimeVar = RTC_GetCounter();
	Now_time.hour = TimeVar / 3600;
	Now_time.min = (TimeVar % 3600) / 60;
	temp[2] = Hex2Bcd(Now_time.min);
	temp[3] = Hex2Bcd(Now_time.hour);
	temp[4] = Hex2Bcd(Now_time.day);
	temp[5] = Hex2Bcd(Now_time.mon);
	temp[6] = Hex2Bcd(Now_time.year);
	for(i =0;((i<7)/*&& (FLASHStatus == FLASH_COMPLETE)*/);i++)
		{
		RxBuffer1[i] = temp[i];
		RxBuffer1[temp[1]*OFFSET_JLL+i] = temp[i];
		}
	for(i =0;((i<(MAXBUFFER/2))/*&& (FLASHStatus == FLASH_COMPLETE)*/);i++)
		{
		tmp = RxBuffer1[i*2+1];
		tmp = RxBuffer1[i*2]|tmp<<8;
		FLASHStatus = FLASH_ProgramHalfWord(StartAddr+OFFSET_JL+i*2, tmp);		
		}
	/* lock the Flash Program Erase controller */
	FLASH_Lock();	
	}

/****************�澯���by��ֵ***********************/
void Alarm_Abo(void)
	{
	u8 i,NbrOfPage;
	u16 tmp;
	u8 temp[7];
	u32 TimeVar;
	volatile FLASH_Status FLASHStatus;
	FLASHStatus = FLASH_COMPLETE;
	for(i=0;i<6;i++)
		{
		temp[i] = (*(vu32*) (StartAddr+i));
		}
	temp[6]	= (*(vu32*) (StartAddr+OFFSET_JL));
	if(ALAEM_CACJ != temp[6])
		{
		temp[6] = (*(vu32*) (StartAddr+OFFSET_JL+1));
	 	for(i=0;i<MAXBUFFER;i++)
			{
			RxBuffer1[i] = (*(vu32*) (StartAddr+OFFSET_JL+i));
			} 
		/* Unlock the Flash Program Erase controller */
		FLASH_Unlock();	
		/* Define the number of page to be erased */
		NbrOfPage = (EndAddr - StartAddr) / FLASH_PAGE_SIZE;
		/* Clear All pending flags */
		FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);			
		/* Erase the FLASH pages */
		for(i = 0; (i < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); i++)
			{
			FLASHStatus = FLASH_ErasePage(StartAddr + (FLASH_PAGE_SIZE * i));
			}
		for(i =0;((i<3)/*&& (FLASHStatus == FLASH_COMPLETE)*/);i++)
			{
			tmp = temp[i*2+1];
			tmp = temp[i*2]|tmp<<8;
			FLASHStatus = FLASH_ProgramHalfWord(StartAddr+i*2, tmp);	
			}
		temp[0] = ALAEM_CACJ;
		temp[1] = temp[6];
		TimeVar = RTC_GetCounter();
		Now_time.hour = TimeVar / 3600;
		Now_time.min = (TimeVar % 3600) / 60;
		temp[2] = Hex2Bcd(Now_time.min);
		temp[3] = Hex2Bcd(Now_time.hour);
		temp[4] = Hex2Bcd(Now_time.day);
		temp[5] = Hex2Bcd(Now_time.mon);
		temp[6] = Hex2Bcd(Now_time.year);
		for(i =0;((i<7)/*&& (FLASHStatus == FLASH_COMPLETE)*/);i++)
			{
			RxBuffer1[i] = temp[i];
			}
		for(i =0;((i<(MAXBUFFER/2))/*&& (FLASHStatus == FLASH_COMPLETE)*/);i++)
			{
			tmp = RxBuffer1[i*2+1];
			tmp = RxBuffer1[i*2]|tmp<<8;
			FLASHStatus = FLASH_ProgramHalfWord(StartAddr+OFFSET_JL+i*2, tmp);		
			}
		/* lock the Flash Program Erase controller */
		FLASH_Lock(); 		
		}
	}

/*******************************************************************************
* Function Name  : ReadSC()
* Description    : Read Smartcard.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/* Read Smartcard  response */ 
void ReadSC(void)
	{
	u8 Select[7]={0x00,0xA4,0x00,0x00,0x02,0xDF,0x01};		 //�ı䵱ǰĿ¼��ǰ��{0x00,0xA4,0x01,0x00,0x02,0xDF,0x01}
	u8 Read[5]={0x00,0xB0,0x81,0x00,0x2D};					 //��ȡ�ļ�����
	u8 i,NbrOfPage;
	u8 Re;
	u16 tmp = 0;
	volatile FLASH_Status FLASHStatus;
	FLASHStatus = FLASH_COMPLETE;
	/* Select Smart Card CMDVCC-3.3 */  
	GPIO_3V_ON();	 	
	/* Enable the ISO7816 port */
	ISO7816_Enable();
	/* Set RSTIN LOW */  
	GPIO_SCRST_ON();
	RxCounter2 = 0;
	Delay(0xfff);	
	/* Set RSTIN HIGH */  
	GPIO_SCRST_OFF();
	Delay(0x1fffff);
	if(0x3B == RxBuffer2[0])
		{
		USART2send(Select,5);
		Delay(0xfffff);
		Re = 9+(RxBuffer2[1]&0x0F);	 //��λ�����м�Ӧ��
		if(0xA4 == RxBuffer2[Re])
			{
			USART2send(Select+5,2);
			Delay(0xfffff);
			Re = 12+(RxBuffer2[1]&0x0F);   //��λ��ΪӦ��Ӧ��
			if(0x61 == RxBuffer2[Re])
				{
				USART2send(Read,5);
				Delay(0xfffff);
				Re = 19+(RxBuffer2[1]&0x0F);	  //��λ��Ϊ��ȡ����Ӧ��
				if(0xB0 == RxBuffer2[Re])
					{
					if((0x68 == RxBuffer2[Re+1])&&(0x01 == RxBuffer2[Re+2]))
						{
						for(i=0;i<6;i++)
							{
							if(DX_Addr[i] != RxBuffer2[Re+31+i])
								{
								DX_Addr[i] = RxBuffer2[Re+31+i];
								tmp++;
								}
							}
						if(0 != tmp)
							{
							/* Unlock the Flash Program Erase controller */
							FLASH_Unlock();	
							/* Define the number of page to be erased */
							NbrOfPage = (EndAddr - StartAddr) / FLASH_PAGE_SIZE;
							/* Clear All pending flags */
							FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);			
							/* Erase the FLASH pages */
							for(i = 0; (i < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); i++)
								{
								FLASHStatus = FLASH_ErasePage(StartAddr + (FLASH_PAGE_SIZE * i));
								}
							for(i =0;((i<3)/*&& (FLASHStatus == FLASH_COMPLETE)*/);i++)
								{
								tmp = DX_Addr[i*2+1];
								tmp = DX_Addr[i*2]|tmp<<8;
								FLASHStatus = FLASH_ProgramHalfWord(StartAddr+i*2, tmp);	
								}
							/* lock the Flash Program Erase controller */
							FLASH_Lock();
							/* Disable the ISO7816 port */
							ISO7816_Disable(); 
							/* Shutdown Smart Card CMDVCC-3.3 */  
							GPIO_3V_OFF();	
							NVIC_SystemReset();
//							NVIC_GenerateSystemReset();							 //ϵͳ��λ	  																	
							}
//						else	
//							{
//							NVIC_GenerateSystemReset();
//							}
						}
					else
						{
						nocardid = 1;
						}
					}
				else
					{
					nocardid = 1;
					}						
				}
			else
				{
				nocardid = 1;
				} 						
			}
		else
			{
			nocardid = 1;
			}
		}
	else
		{
		nocardid = 1;
		/* Disable the ISO7816 port */
		ISO7816_Disable(); 
		/* Shutdown Smart Card CMDVCC-3.3 */  
		GPIO_3V_OFF();
		}	
	}

 void ReadSC1(void)
	{
	u8 Select[7]={0x00,0xA4,0x00,0x00,0x02,0xDF,0x01};		 //�ı䵱ǰĿ¼
	u8 Read[5]={0x00,0xB0,0x81,0x00,0x2D};					 //��ȡ�ļ�����
//	u8 i;
//	u8 Re,NbrOfPage;
//	u16 tmp = 0;
	volatile FLASH_Status FLASHStatus;
	FLASHStatus = FLASH_COMPLETE;
	/* Select Smart Card CMDVCC-3.3 */  
	GPIO_3V_ON();	 	
	/* Enable the ISO7816 port */
	ISO7816_Enable();
	/* Set RSTIN LOW */  
	GPIO_SCRST_ON();
	RxCounter2 = 0;
	Delay(0xfff);	
	/* Set RSTIN HIGH */  
	GPIO_SCRST_OFF();
	Delay(0x1fffff);
//	RxCounter2 = 0;
	USART2send(Select,5);
	Delay(0xfffff);
	USART2send(Select+5,2);
	Delay(0xfffff);
//	RxCounter2 = 0;
	USART2send(Read,5);
	Delay(0xfffff);
	}
/*************HEXתBCD*****************/
u8 Hex2Bcd(u8 b)
	{
	u8 bcd ;
	
	bcd = ((b/10)<<4) | (b%10) ;
	
	return bcd ;
	}

/*************BCDתHEX*****************/
u8 Bcd2Hex(u8 b)
	{
	u8 hex ;
	
	hex = (((b&0xf0)>>4)*10) + (b&0x0f) ;
	
	return hex ;
	}



