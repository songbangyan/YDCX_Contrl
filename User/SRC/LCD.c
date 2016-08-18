
#include "config.h"

/* Private typedef -----------------------------------------------------------*/
void LCD_IOinit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*Configure PB8 as IC CARD 3V*/
	/*Configure PB9 as IC CARD 5V*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/*Configure PA11 as BEEP*/
	/*Configure PA12 as LCD_B*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

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
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
		

}
//============================================================================= 
//�� �� ��:  Delay_ms() 
//�� �ܣ�	 �����ʱ
//��ڲ����� ch:����
//���ڲ����� ��
//�� �� ֵ�� ��
//============================================================================= 
void Delay_ms(u16 i)
	{
	u16 m;
	while(i--)
		{
		for(m=0;m<0xF;m++);
		}
	}

//============================================================================= 
//�� �� ��: SendByte(u8 Byte) 
//�� �ܣ�	����һ���ֽ�
//��ڲ����� Byte:�����ֽ�
//���ڲ����� ��
//�� �� ֵ�� ��
//=============================================================================  
void SendByte(u8 Byte)
	{
	u8 i;
	GPIO_LCDSCL_1();//SCK_PORT = 1;
	Delay_ms(1);
	for(i=0;i<8;i++)
		{
		if(( Byte & 0X80 ) == 0)
			GPIO_LCDSDA_0();//SID_PORT = 0;
		else
			GPIO_LCDSDA_1();//SID_PORT = 1; /*���������ɸ�λ����λ����*/
		
		GPIO_LCDSCL_0();//SCK_PORT = 0; /*��ʱ����Ϊ��֪ͨ��������ʼ������λ*/
		Delay_ms(1);
		GPIO_LCDSCL_1();//SCK_PORT = 1; /*ǯס����׼����һ������λ*/
		
		Byte =Byte <<1; /*������������һλ*/
		}
	}
//============================================================================= 
//�� �� ��:  WriteCommand() 
//�� �ܣ�	д���LCD
//��ڲ����� CmdData:������
//���ڲ����� ��
//�� �� ֵ�� ��
//============================================================================= 
void WriteCommand(u8 CmdData)
	{
	GPIO_LCDCS_0();//CS0	= 0;
	GPIO_LCDA0_0();//CD	= 0;
	SendByte(CmdData);//DateBus	= cmdcode;
	GPIO_LCDCS_1();
	}
//============================================================================= 
//�� �� ��:  WriteData() 
//�� �ܣ�	д���ݵ�LCD
//��ڲ����� Data:д�������
//���ڲ����� ��
//�� �� ֵ�� ��
//============================================================================= 
void WriteData(u8 Data)
	{
	GPIO_LCDCS_0();//CS0	= 0;
	GPIO_LCDA0_1();//CD	= 0;
	SendByte(Data);//DateBus	= cmdcode;
	GPIO_LCDCS_1();
	}

//============================================================================= 
//�� �� ��: InitLCD() 
//�� �ܣ�	��ʼ�� LCD
//��ڲ����� ��
//���ڲ����� ��
//�� �� ֵ�� ��
//============================================================================= 
void InitLCD(void)
{
	LCD_IOinit();		
	GPIO_LCDRST_ON();
	Delay_ms(250);
	GPIO_LCDRST_OFF();

	/*Internal Reset*/
	WriteCommand(0xE2);
	Delay_ms(250);
	
	/*Display OFF*/	
	WriteCommand(0xAE);
	
	/*Set The DDRAM Address SEG output Correspondence (ADC=0)SEG0--SEG127*/
	WriteCommand(0xA0);
	
	/*Set LCD Scroll Control*/
	WriteCommand(0x40);

	/*Set LCD Mapping Control*/
	WriteCommand(0xC2);

	/*Set RAM Address Control*/
	WriteCommand(0x88);
	
	/*Set The LCD Display(Normal)*/
	WriteCommand(0xA6);

	/*Sets Display all points 0: normal display*/
	WriteCommand(0xA4);
	
	/*Set Frame Rate 1=100fps*/
	WriteCommand(0xA1);
	
	/*Set Power Control : Internal VLCD,*/
	WriteCommand(0x2F);

	/*Set Temperature Compensation : 10b=-0.15%, 00b=0%*/
	WriteCommand(0x26);

	/*Set VBIAS Potentiometer*/
	WriteCommand(0x81);
	WriteCommand(0xC0);//24
									
	/*Display ON*/	
	WriteCommand(0xAF);
}


//============================================================================= 
//�� �� ��: ClearScreen() 
//�� ��: 	����
//��ڲ���: ��
//���ڲ���:  ��
//�� �� ֵ:  ��
//============================================================================= 
void ClearScreen(void)
{
	u8 j,k;
	for(k=0;k<8;k++)
	{
		WriteCommand(Page_Add+k);
		WriteCommand(0x10);
		WriteCommand(0x00);
		for(j=0;j<132;j++)
		WriteData(0x00);
	}
}

//============================================================================= 
//�� �� ��: WriteWord() 
//�� ��: 	дһ������Ϊ16*16�ĺ���
//��ڲ���:  x yλ�ã�index[2]����
//���ڲ���:  ��
//�� �� ֵ:  ��
//============================================================================= 
void WriteWord(u8 x, u8 y, u8 index[2])
{
	u8 *p;
	u8 j, i;
	j=0;
	for(i=0;i<MAXNUMOFHZ;i++)
	{
		if((HZ1[i].Index[1] == index[1])&&(HZ1[i].Index[0] == index[0]))
		{
			p=HZ1[i].Msk;
			break;
		}
	}
	if(i == MAXNUMOFHZ)
	{
		p=HZ1[0].Msk;
	}
	for(j=0;j<2;j++)				// �����ַ������°벿���ַ�
	{
		for(i=0;i<16;i++)
		{
			LCD_old[x+j][y+i] = p[16*j+i];
		}
	}	
}


//============================================================================= 
//�� �� ��: WriteASCII() 
//�� ��: 	дһ������Ϊ16*8������
//��ڲ���:  x yλ�ã�index[1]Ϊ����
//���ڲ���:  ��
//�� �� ֵ:  ��
//============================================================================= 
void WriteASCII(u8 x, u8 y, u8 index)
{
	u8 j,i;
	u8 *p;
	j=0;
	i=0;
	for(i=0;i<MAXNUMOFSZ;i++)
	{
		if(SZ1[i].Index == index)
		{
			p=SZ1[i].Msk;
			break;
		}
	}
	if(i == MAXNUMOFSZ)
	{
		p=SZ1[0].Msk;
	}
	for(j=0;j<2;j++)				// �����ַ������°벿���ַ�
	{
		for(i=0;i<8;i++)
		{
			LCD_old[x+j][y+i] = p[8*j+i];
		}
	} 
}
//============================================================================= 
//�� �� ��: WriteBCD() 
//�� ��: 	дһ������Ϊ12*6������
//��ڲ���:  x yλ�ã�indexΪBCD��
//���ڲ���:  ��
//�� �� ֵ:  ��
//============================================================================= 
void WriteBCD(u8 x, u8 y, u8 index)
{
	u8 j,i;
	u8 *p;
	p=SZ1[index].Msk;
	for(j=0;j<2;j++)				// �����ַ������°벿���ַ�
	{
		for(i=0;i<8;i++)
		{
			LCD_old[x+j][y+i] = p[8*j+i];
		}
	}
}
//============================================================================= 
//�� �� ��: LCDrefur() 
//�� ��: 	ˢ��LCD
//��ڲ���:  
//���ڲ���:  ��
//�� �� ֵ:  ��
//============================================================================= 
void LCDrefur(void)	
{
	u8 i,j;
	LCD_shutup();
	for(i=0;i<8;i++)
	{
		WriteCommand(Page_Add+i);
		WriteCommand(Row_AddH);
		WriteCommand(Row_AddL); 
		for(j=0;j<128;j++)
		{
			WriteData(LCD_old[i][j]);
		}
	}
}

//============================================================================= 
//�� �� ��: Displaytog(unsigned char x,unsigned char y,unsigned char size)
//�� ��: 	ָ���ĵط�������˸
//��ڲ���: x:��ʾ���ĺ���λ��
//					y:��ʾ������ֱλ��
//					size:��С����һ�����ֻ���Ӣ��
//���ڲ���:  ��
//�� �� ֵ:  ��
//============================================================================= 
void Displaytog(unsigned char x,unsigned char y,unsigned char size)
{
	u8 *p;
	u8 j, i;
	if(size == HANZI)
	{
		p = HZ1[101].Msk;
		for(j=0;j<2;j++)				// �����ַ������°벿���ַ�
		{
			for(i=0;i<16;i++)
			{
				LCD_old[x+j][y+i] = p[16*j+i];
			}
		}				
	}
	else
	{
		p = SZ1[10].Msk;
		for(j=0;j<2;j++)				// �����ַ������°벿���ַ�
		{
			for(i=0;i<8;i++)
			{
				LCD_old[x+j][y+i] = p[8*j+i];
			}
		} 					
	}
}

//============================================================================= 
//�� �� ��: LCD_shutup(); 
//�� ��: 	�ر���ʾ��
//��ڲ���:  ��
//���ڲ���:  ��
//�� �� ֵ:  ��
//============================================================================= 
void LCD_shutup(void)
	{									
	/*Display ON*/
	WriteCommand(0xAF);
	GPIO_LCDBL_ON();
	}

//============================================================================= 
//�� �� ��: LCD_shutdown(); 
//�� ��: 	�ر���ʾ��
//��ڲ���:  ��
//���ڲ���:  ��
//�� �� ֵ:  ��
//============================================================================= 
void LCD_shutdown(void)
	{
	InitLCD();	
	/*Display OFF*/	
	WriteCommand(0xAE);
	GPIO_LCDBL_OFF();
	}
