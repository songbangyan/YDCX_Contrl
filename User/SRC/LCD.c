
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
//函 数 名:  Delay_ms() 
//功 能：	 软件延时
//入口参数： ch:数据
//出口参数： 无
//返 回 值： 无
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
//函 数 名: SendByte(u8 Byte) 
//功 能：	发送一个字节
//入口参数： Byte:发送字节
//出口参数： 无
//返 回 值： 无
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
			GPIO_LCDSDA_1();//SID_PORT = 1; /*发送数据由高位到低位传送*/
		
		GPIO_LCDSCL_0();//SCK_PORT = 0; /*置时钟线为高通知被控器开始接收数位*/
		Delay_ms(1);
		GPIO_LCDSCL_1();//SCK_PORT = 1; /*钳住总线准备下一个数据位*/
		
		Byte =Byte <<1; /*发送数据左移一位*/
		}
	}
//============================================================================= 
//函 数 名:  WriteCommand() 
//功 能：	写命令到LCD
//入口参数： CmdData:命令码
//出口参数： 无
//返 回 值： 无
//============================================================================= 
void WriteCommand(u8 CmdData)
	{
	GPIO_LCDCS_0();//CS0	= 0;
	GPIO_LCDA0_0();//CD	= 0;
	SendByte(CmdData);//DateBus	= cmdcode;
	GPIO_LCDCS_1();
	}
//============================================================================= 
//函 数 名:  WriteData() 
//功 能：	写数据到LCD
//入口参数： Data:写入的数据
//出口参数： 无
//返 回 值： 无
//============================================================================= 
void WriteData(u8 Data)
	{
	GPIO_LCDCS_0();//CS0	= 0;
	GPIO_LCDA0_1();//CD	= 0;
	SendByte(Data);//DateBus	= cmdcode;
	GPIO_LCDCS_1();
	}

//============================================================================= 
//函 数 名: InitLCD() 
//功 能：	初始化 LCD
//入口参数： 无
//出口参数： 无
//返 回 值： 无
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
//函 数 名: ClearScreen() 
//功 能: 	清屏
//入口参数: 无
//出口参数:  无
//返 回 值:  无
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
//函 数 名: WriteWord() 
//功 能: 	写一个点阵为16*16的汉字
//入口参数:  x y位置，index[2]汉字
//出口参数:  无
//返 回 值:  无
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
	for(j=0;j<2;j++)				// 整个字符分上下半部分字符
	{
		for(i=0;i<16;i++)
		{
			LCD_old[x+j][y+i] = p[16*j+i];
		}
	}	
}


//============================================================================= 
//函 数 名: WriteASCII() 
//功 能: 	写一个点阵为16*8的数字
//入口参数:  x y位置，index[1]为数字
//出口参数:  无
//返 回 值:  无
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
	for(j=0;j<2;j++)				// 整个字符分上下半部分字符
	{
		for(i=0;i<8;i++)
		{
			LCD_old[x+j][y+i] = p[8*j+i];
		}
	} 
}
//============================================================================= 
//函 数 名: WriteBCD() 
//功 能: 	写一个点阵为12*6的数字
//入口参数:  x y位置，index为BCD码
//出口参数:  无
//返 回 值:  无
//============================================================================= 
void WriteBCD(u8 x, u8 y, u8 index)
{
	u8 j,i;
	u8 *p;
	p=SZ1[index].Msk;
	for(j=0;j<2;j++)				// 整个字符分上下半部分字符
	{
		for(i=0;i<8;i++)
		{
			LCD_old[x+j][y+i] = p[8*j+i];
		}
	}
}
//============================================================================= 
//函 数 名: LCDrefur() 
//功 能: 	刷新LCD
//入口参数:  
//出口参数:  无
//返 回 值:  无
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
//函 数 名: Displaytog(unsigned char x,unsigned char y,unsigned char size)
//功 能: 	指定的地方进行闪烁
//入口参数: x:显示屏的横向位置
//					y:显示屏的竖直位置
//					size:大小，是一个汉字还是英文
//出口参数:  无
//返 回 值:  无
//============================================================================= 
void Displaytog(unsigned char x,unsigned char y,unsigned char size)
{
	u8 *p;
	u8 j, i;
	if(size == HANZI)
	{
		p = HZ1[101].Msk;
		for(j=0;j<2;j++)				// 整个字符分上下半部分字符
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
		for(j=0;j<2;j++)				// 整个字符分上下半部分字符
		{
			for(i=0;i<8;i++)
			{
				LCD_old[x+j][y+i] = p[8*j+i];
			}
		} 					
	}
}

//============================================================================= 
//函 数 名: LCD_shutup(); 
//功 能: 	关闭显示器
//入口参数:  无
//出口参数:  无
//返 回 值:  无
//============================================================================= 
void LCD_shutup(void)
	{									
	/*Display ON*/
	WriteCommand(0xAF);
	GPIO_LCDBL_ON();
	}

//============================================================================= 
//函 数 名: LCD_shutdown(); 
//功 能: 	关闭显示器
//入口参数:  无
//出口参数:  无
//返 回 值:  无
//============================================================================= 
void LCD_shutdown(void)
	{
	InitLCD();	
	/*Display OFF*/	
	WriteCommand(0xAE);
	GPIO_LCDBL_OFF();
	}
