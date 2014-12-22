#include"config.h"

/***************按键处理函数*******************/
void Key_deal(void)
	{
	if((key_plus != key_plusold)&&(sys_start != 1)/*&&(Key_value != KYUE)*/)
		{
		if(key_plus == 0)	
			{
			Key_value--;
			}
		else
			{
			Key_value++;
			}
		key_plusold = key_plus;
		}
	else 
		{
		sys_start = 0;
		key_plusold = key_plus;
		}
	if(key_plus)
		{
		if(Key_value == KYUE)
			{
			Key_value++;
			}
		if((Key_value == KYUE)&&(X_Smoney[0] != BESET))					 //剩余金额
			{
//			Key_value ++;
			Key_value = KYDL;
			}
		if((Key_value == KYDL)&&(X_Sdian[0] != BESET))					//剩余电量
			{
			Key_value = KZQS;
			}
		if((Key_value >= KZQS)&&(Key_value <= KZQE)&&(X_Djleij[0] != BESET))	     //周期电量
			{
			Key_value = KDQS;
			}
		if((Key_value >= KDQS)&&(Key_value <= KDQE)&&(X_Biaoma[0] != BESET))		 //当前示数
			{
			Key_value = KDJS;
			}
		if((Key_value >= KDJS)&&(Key_value <= KDJE)&&(X_Feil[0] != BESET))			//电价
			{
			Key_value = KGDC;
			}
		if((Key_value == KGDC)&&(X_Goudc[0] != BESET))						 	//总购电次数
			{
			Key_value = KLGD;
			}
		if((Key_value == KLGD)&&(X_Ljgoud[0] != BESET))						 	//累计购电量
			{
			Key_value = KLJJ;
			}
		if((Key_value == KLJJ)&&(X_Leigoudj[0] != BESET))						 	//累计购电金额
			{
			Key_value = KGDT;
			}
		if((Key_value == KGDT)&&(X_Lgoudt[0] != BESET))						 	//最后一次购电时间
			{
			Key_value = KGDJ;
			}
		if((Key_value == KGDJ)&&(X_Lgoudj[0] != BESET))						 	//最后一次购电金额
			{
			Key_value = KDQJ;
			}
		if((Key_value == KDQJ)&&(X_Jietdj[0] != BESET))						 	//当前阶梯电价
			{
			Key_value = KGXT;
			}
		if((Key_value == KGXT)&&(X_DTime[0] != BESET))						 	//最后更新时间
			{
			Key_value = 0;
			}
		if(Key_value >= KGXT+1)
			{
			Key_value =	0;
			}
		}
	else
		{
		if(Key_value >= KGXT)
			{
			Key_value =	KGXT;
			}
		if((Key_value == KGXT)&&(X_DTime[0] != BESET))					 		 //最后更新时间
			{
			Key_value = KDQJ;
			}
		if((Key_value == KDQJ)&&(X_Jietdj[0] != BESET))							//当前阶梯电价
			{
			Key_value = KGDJ;
			}
		if((Key_value == KGDJ)&&(X_Lgoudj[0] != BESET))						 	//最后一次购电金额
			{
			Key_value = KGDT;
			}
		if((Key_value == KGDT)&&(X_Lgoudt[0] != BESET))						 	//最后一次购电时间
			{													   
			Key_value = KLJJ;
			}							
		if((Key_value == KLJJ)&&(X_Leigoudj[0] != BESET))						 	//累计购电金额
			{
			Key_value = KLGD;
			}
		if((Key_value == KLGD)&&(X_Ljgoud[0] != BESET))						 	//累计购电量
			{
			Key_value = KGDC;
			}	
		if((Key_value == KGDC)&&(X_Goudc[0] != BESET))						 	//总购电次数
			{
			Key_value = KDJE;
			}
		if((Key_value >= KDJS)&&(Key_value <= KDJE)&&(X_Feil[0] != BESET))			//电价
			{
			Key_value = KDQE;
			}
		if((Key_value >= KDQS)&&(Key_value <= KDQE)&&(X_Biaoma[0] != BESET))		 //当前示数
			{
			Key_value = KZQE;
			}
		if((Key_value >= KZQS)&&(Key_value <= KZQE)&&(X_Djleij[0] != BESET))	  	 //周期电量
			{
			Key_value = KYDL;
			}
		if((Key_value == KYDL)&&(X_Sdian[0] != BESET))							//剩余电量
			{
			Key_value = KYUE;
			}
		if((Key_value == KYUE)&&(X_Smoney[0] != BESET))							 //剩余金额
			{
			Key_value = 0;
			}
		} 
	switch(Key_value)
		{
		case(KYUE):
			Dis_LeaJ();
			break;
		case(KYDL):
			Dis_LeaD();
			break;
		case(KZQS):
		case(KZQS+1):
		case(KZQS+2):
		case(KZQS+3):
		case(KZQE):
			Dis_Dqz();
			break;
		case(KDQS):
		case(KDQS+1):
		case(KDQS+2):
		case(KDQS+3):
		case(KDQE):
			Dis_Dqdls();
			break;
		case(KDJS):
		case(KDJS+1):
		case(KDJS+2):
		case(KDJE):	
			Dis_DJ();
			break;
		case(KGDC):
			Dis_GCount();
			break;
		case(KLGD):
			Dis_GTotal();
			break;
		case(KLJJ):
			Dis_Tbuyj();
			break;
		case(KGDT):
			Dis_Lastbuytime();
			break;
		case(KGDJ):
			Dis_Lastbuyj();
			break;
		case(KDQJ):
			Dis_Nowjtdj();
			break;
		case(KGXT):
			Dis_Lasttiming();
			break;
		default:
			Dis_dbadd();
			break;
			
		}
	}

/***************显示欢迎、插卡等*******************/
void Dis_defalt(void)
	{
//	u32 TimeVar;
	u8 Page = 0;
	u8 i;
//	TimeVar = RTC_GetCounter();
//	Now_time.hour = TimeVar / 3600;
//	Now_time.min = (TimeVar % 3600) / 60;
//	Now_time.sec = (TimeVar % 3600) % 60;
//	if(Page_dis%2 == 0)
//		{
//		Page = 0;
//		}
//	else
//		{
//		Page = 4;
//		}
	for(i=0;i<16;i++)
		{
		WriteASCII(Page,ZIMU*i," ");
		}	

	WriteWord((Page+1),HANZI*0,"终");
	WriteWord((Page+1),HANZI*1,"端");
	WriteWord((Page+1),HANZI*2,"获");
	WriteWord((Page+1),HANZI*3,"取");
	WriteWord((Page+1),HANZI*4,"电");
	WriteWord((Page+1),HANZI*5,"表");
	WriteWord((Page+1),HANZI*6,"表");
	WriteWord((Page+1),HANZI*7,"号");
//	WriteASCII((Page+1),ZIMU*14," ");
//	WriteASCII((Page+1),ZIMU*15," ");

	for(i=0;i<16;i++)
		{
		WriteASCII(Page+3,ZIMU*i," ");
		}	

	if(1 == nocardid)
		{
		WriteWord((Page+3),HANZI*0,"读");
		WriteWord((Page+3),HANZI*1,"卡");
		WriteWord((Page+3),HANZI*2,"失");
		WriteWord((Page+3),HANZI*3,"败");
		WriteASCII((Page+3),HANZI*4,"!");
		WriteASCII((Page+3),ZIMU*9," ");
		WriteASCII((Page+3),ZIMU*10," ");
		WriteASCII((Page+3),ZIMU*11," ");
		WriteASCII((Page+3),ZIMU*12," ");
		WriteASCII((Page+3),ZIMU*13," ");
		WriteASCII((Page+3),ZIMU*14," ");
		WriteASCII((Page+3),ZIMU*15," ");
		
		}

	for(i=0;i<16;i++)
		{
		WriteASCII(Page+6,ZIMU*i," ");
		}	

	WriteWord((Page+5),HANZI*0,"请");
	WriteWord((Page+5),HANZI*1,"插");
	WriteWord((Page+5),HANZI*2,"入");
	WriteWord((Page+5),HANZI*3,"购");
	WriteWord((Page+5),HANZI*4,"电");
	WriteWord((Page+5),HANZI*5,"卡");
	WriteASCII((Page+5),ZIMU*12,":");
	WriteASCII((Page+5),ZIMU*13," ");
	WriteASCII((Page+5),ZIMU*14," ");
	WriteASCII((Page+5),ZIMU*15," ");

//	WriteASCII((Page+5),ZIMU*0," ");
//	WriteWord((Page+5),ZIMU*1,"谢");
//	WriteASCII((Page+5),ZIMU*3," ");
//	WriteASCII((Page+5),ZIMU*4," ");
//	WriteWord((Page+5),ZIMU*5,"谢");
//	WriteASCII((Page+5),ZIMU*7," ");
//	WriteASCII((Page+5),ZIMU*8," ");
//	WriteWord((Page+5),ZIMU*9,"合");
//	WriteASCII((Page+5),ZIMU*11," ");
//	WriteASCII((Page+5),ZIMU*12," ");
//	WriteWord((Page+5),ZIMU*13,"作");
//	WriteASCII((Page+5),ZIMU*15," ");
	
//	Dis_TRH(); 
	}
/***************显示温湿度*******************/
void Dis_TRH(void)
	{
	u8 Page,i;
	if(Page_dis%2 == 0)
		{
		Page = 4;
		}
	else
		{
		Page = 0;
		}
	DHT_com();
	if((Tempr_data == 0)&&(RH_data == 0))
		{
		if((1 == timed)&&(BESET == X_Smoney[0]))
			{
			Page_dis++;
			Dis_LeaJ();
			Page_dis--;
			}
		else
			{
			for(i=0;i<16;i++)
				{
				WriteASCII(Page,ZIMU*i," ");
				WriteASCII(Page+2,ZIMU*i," ");			
				}			
			}
		}
	else
		{
		WriteWord(Page,HANZI*0,"当");
		WriteWord(Page,HANZI*1,"前");
		WriteWord(Page,HANZI*2,"温");
		WriteWord(Page,HANZI*3,"度");
		WriteASCII(Page,ZIMU*8,":");
		WriteASCII(Page,ZIMU*9," ");
		WriteASCII(Page,ZIMU*10," ");
		WriteASCII(Page,ZIMU*11," ");
		WriteBCD(Page,ZIMU*12,(Tempr_data/10)%10); 
		WriteBCD(Page,ZIMU*13,Tempr_data%10);
		WriteWord(Page,HANZI*7,"℃");
	
		WriteWord((Page+2),HANZI*0,"相");
		WriteWord((Page+2),HANZI*1,"对");
		WriteWord((Page+2),HANZI*2,"湿");
		WriteWord((Page+2),HANZI*3,"度");
		WriteASCII((Page+2),ZIMU*8,":");
		WriteASCII((Page+2),ZIMU*9," ");
		WriteASCII((Page+2),ZIMU*10," ");
		WriteASCII((Page+2),ZIMU*11," ");
		WriteASCII((Page+2),ZIMU*12," ");
		WriteBCD((Page+2),ZIMU*13,(RH_data/10)%10); 
		WriteBCD((Page+2),ZIMU*14,RH_data%10);
		WriteASCII((Page+2),ZIMU*15,"%");		
		}	
	}
/***************显示读卡状态*******************/
void Dis_readcard(void)
	{
	u8 Page = 0;
	u8 i;
//	if(Page_dis%2 == 0)
//		{
//		Page = 0;
//		}
//	else
//		{
//		Page = 4;
//		}

	for(i=0;i<16;i++)
		{
		WriteASCII(Page,ZIMU*i," ");
		}

	WriteASCII((Page+2),ZIMU*0," ");
	WriteWord((Page+2),ZIMU*1,"请");
	WriteASCII((Page+2),ZIMU*3," ");
	WriteASCII((Page+2),ZIMU*4," ");
	WriteWord((Page+2),ZIMU*5,"等");
	WriteASCII((Page+2),ZIMU*7," ");
	WriteASCII((Page+2),ZIMU*8," ");
	WriteWord((Page+2),ZIMU*9,"待");
	WriteASCII((Page+2),ZIMU*11," ");
	WriteASCII((Page+2),ZIMU*12," ");
	WriteASCII((Page+2),ZIMU*13," ");
	WriteASCII((Page+2),ZIMU*14," ");
	WriteASCII((Page+2),ZIMU*15," ");


	for(i=0;i<16;i++)
		{
		WriteASCII(Page+4,ZIMU*i," ");
		}

	WriteWord((Page+5),HANZI*0,"正");
	WriteWord((Page+5),HANZI*1,"在");
	WriteWord((Page+5),HANZI*2,"读");
	WriteWord((Page+5),HANZI*3,"卡");
	WriteWord((Page+5),HANZI*4,"…");
	WriteWord((Page+5),HANZI*5,"…");
	WriteASCII((Page+5),ZIMU*12,":");
	WriteASCII((Page+5),ZIMU*13," ");
	WriteASCII((Page+5),ZIMU*14," ");
	WriteASCII((Page+5),ZIMU*15," ");

	for(i=0;i<16;i++)
		{
		WriteASCII(Page+7,ZIMU*i," ");
		}

//	WriteWord((Page+4),HANZI*0,"终");
//	WriteWord((Page+4),HANZI*1,"端");
//	WriteWord((Page+4),HANZI*2,"重");
//	WriteWord((Page+4),HANZI*3,"启");
//	WriteWord((Page+4),HANZI*4,"后");
//	WriteASCII((Page+4),ZIMU*10," ");
//	WriteASCII((Page+4),ZIMU*11," ");
//	WriteASCII((Page+4),ZIMU*12," ");
//	WriteASCII((Page+4),ZIMU*13," ");
//	WriteASCII((Page+4),ZIMU*14," ");
//	WriteASCII((Page+4),ZIMU*15," ");
//
//	WriteWord((Page+6),HANZI*0,"方");
//	WriteWord((Page+6),HANZI*1,"可");
//	WriteWord((Page+6),HANZI*2,"拔");	
//	WriteWord((Page+6),HANZI*3,"出");	
//	WriteWord((Page+6),HANZI*4,"卡");	
//	WriteWord((Page+6),HANZI*5,"片");
//	WriteASCII((Page+6),ZIMU*12," ");
//	WriteASCII((Page+6),ZIMU*13," ");
//	WriteASCII((Page+6),ZIMU*14," ");
//	WriteASCII((Page+6),ZIMU*15," ");
		
//	Dis_TRH(); 
	}
/***************显示电表地址*******************/
void Dis_dbadd(void)
	{
	u8 temp[12];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<6;i++)
		{
		temp[2*i]=DX_Addr[5-i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	if((0x0a <= temp[0])||((0==DX_Addr[0])&&(0==DX_Addr[1])&&(0==DX_Addr[2])&&(0==DX_Addr[3])&&(0==DX_Addr[4])&&(0==DX_Addr[5])))
		{
		Dis_defalt();
		}
	else
		{
		WriteWord(Page,HANZI*0,"电");	   	
		WriteWord(Page,HANZI*1,"表");	   	
		WriteWord(Page,HANZI*2,"表");	   	
		WriteWord(Page,HANZI*3,"号");	   	
		WriteASCII(Page,HANZI*4,":");
		WriteASCII(Page,ZIMU*9," ");
		WriteASCII(Page,ZIMU*10," ");
		WriteASCII(Page,ZIMU*11," ");
		WriteASCII(Page,ZIMU*12," ");
		WriteASCII(Page,ZIMU*13," ");
		WriteASCII(Page,ZIMU*14," ");
		WriteASCII(Page,ZIMU*15," ");
		WriteBCD((Page+2),ZIMU*15,temp[0]);
		WriteBCD((Page+2),ZIMU*14,temp[1]);
		WriteBCD((Page+2),ZIMU*13,temp[2]);
		WriteBCD((Page+2),ZIMU*12,temp[3]);
		WriteBCD((Page+2),ZIMU*11,temp[4]);
		WriteBCD((Page+2),ZIMU*10,temp[5]);
		WriteBCD((Page+2),ZIMU*9,temp[6]);
		WriteBCD((Page+2),ZIMU*8,temp[7]);
		WriteBCD((Page+2),ZIMU*7,temp[8]);
		WriteBCD((Page+2),ZIMU*6,temp[9]);
		WriteBCD((Page+2),ZIMU*5,temp[10]);
		WriteBCD((Page+2),ZIMU*4,temp[11]);
		WriteASCII((Page+2),ZIMU*3," ");
		WriteASCII((Page+2),ZIMU*2," ");
		WriteASCII((Page+2),ZIMU*1," ");
		WriteASCII((Page+2),ZIMU*0," ");
		Dis_TRH(); 
		}
	if((Key_value>=(KGXT+1))&&(key_plus))
		{
		Key_value = 0;
		}
	if((Key_value>=(KGXT+1))&&(!key_plus))
		{
		Key_value = KGXT;
		}
	}

/***************显示费率电价*******************/
void Dis_DJ(void)
	{
	u8 temp[8];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	WriteASCII(Page,ZIMU*0," ");
	if(Key_value == KDJS)
		{
		WriteWord(Page,ZIMU*1,"尖");
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Feil[1+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KDJS+1))
		{
		WriteWord(Page,ZIMU*1,"峰");
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Feil[1+4+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KDJS+2))
		{
		WriteWord(Page,ZIMU*1,"平");
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Feil[1+8+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KDJS+3))
		{
		WriteWord(Page,ZIMU*1,"谷");
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Feil[1+12+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	WriteASCII(Page,ZIMU*3," ");
	WriteWord(Page,HANZI*2,"费");
	WriteWord(Page,HANZI*3,"率");
	WriteWord(Page,HANZI*4,"电");
	WriteWord(Page,HANZI*5,"价");
	WriteASCII(Page,ZIMU*12,":");
	WriteASCII(Page,ZIMU*13," ");
	WriteASCII(Page,ZIMU*14," ");
	WriteASCII(Page,ZIMU*15," ");
	WriteASCII((Page+2),ZIMU*0," ");
	for(i=7;i>=5;i--)
		{
		if(temp[i] == 0)
			{
			temp[i] = 10;
			}
		else
			{
			break;
			}
		}
	WriteBCD((Page+2),ZIMU*1,temp[7]);
	WriteBCD((Page+2),ZIMU*2,temp[6]);
	WriteBCD((Page+2),ZIMU*3,temp[5]);
	WriteBCD((Page+2),ZIMU*4,temp[4]);
	WriteASCII((Page+2),ZIMU*5,".");		  
	WriteBCD((Page+2),ZIMU*6,temp[3]);
	WriteBCD((Page+2),ZIMU*7,temp[2]);
	WriteBCD((Page+2),ZIMU*8,temp[1]);
	WriteBCD((Page+2),ZIMU*9,temp[0]);
	WriteWord((Page+2),HANZI*5,"元");		 
	WriteASCII((Page+2),ZIMU*12,"/");		 	
	WriteASCII((Page+2),ZIMU*13,"k");		 
	WriteASCII((Page+2),ZIMU*14,"W");	 
	WriteASCII((Page+2),ZIMU*15,"h");	 
	}



/***************当前电量示数*******************/
void Dis_Dqdls(void)
	{
	u8 temp[8];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	WriteWord(Page,HANZI*0,"当");
	WriteWord(Page,HANZI*1,"前");
	if(Key_value == KDQS)
		{
		WriteWord(Page,HANZI*2,"总");
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Biaoma[1+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KDQS+1))
		{
		WriteWord(Page,HANZI*2,"尖");		//
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Biaoma[1+4+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KDQS+2))
		{
		WriteWord(Page,HANZI*2,"峰");		//
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Biaoma[1+8+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KDQS+3))
		{
		WriteWord(Page,HANZI*2,"平");		//
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Biaoma[1+12+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KDQS+4))
		{
		WriteWord(Page,HANZI*2,"谷");		//
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Biaoma[1+16+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	WriteWord(Page,HANZI*3,"电");
	WriteWord(Page,HANZI*4,"量");
	WriteWord(Page,HANZI*5,"示");
	WriteWord(Page,HANZI*6,"数");
	WriteASCII(Page,HANZI*7,":");
	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
 	WriteASCII((Page+2),ZIMU*1," ");
 	WriteASCII((Page+2),ZIMU*2," ");
 	WriteASCII((Page+2),ZIMU*3," ");
	for(i=7;i>=3;i--)
		{
		if(temp[i] == 0)
			{
			temp[i] = 10;
			}
		else
			{
			break;
			}
		}
	WriteBCD((Page+2),ZIMU*4,temp[7]);
	WriteBCD((Page+2),ZIMU*5,temp[6]);
	WriteBCD((Page+2),ZIMU*6,temp[5]);
	WriteBCD((Page+2),ZIMU*7,temp[4]);
	WriteBCD((Page+2),ZIMU*8,temp[3]);		  
	WriteBCD((Page+2),ZIMU*9,temp[2]);
	WriteASCII((Page+2),ZIMU*10,".");
	WriteBCD((Page+2),ZIMU*11,temp[1]);
	WriteBCD((Page+2),ZIMU*12,temp[0]);
	WriteASCII((Page+2),ZIMU*13,"k");		
	WriteASCII((Page+2),ZIMU*14,"W");	 
	WriteASCII((Page+2),ZIMU*15,"h");
	}


	
/***************本周期用电量*******************/
void Dis_Dqz(void)
	{
	u8 temp[8];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	WriteWord(Page,HANZI*0,"本");
	WriteWord(Page,HANZI*1,"周");
	WriteWord(Page,HANZI*2,"期");
	if(Key_value == KZQS)
		{
		WriteWord(Page,HANZI*3,"总");	
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Djleij[1+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KZQS+1))
		{
		WriteWord(Page,HANZI*3,"尖");	
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Djleij[1+4+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KZQS+2))
		{
		WriteWord(Page,HANZI*3,"峰");		
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Djleij[1+8+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KZQS+3))
		{
		WriteWord(Page,HANZI*3,"平");		
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Djleij[1+12+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	else if(Key_value == (KZQS+4))
		{
		WriteWord(Page,HANZI*3,"谷");		
		for(i=0;i<4;i++)
			{
			temp[2*i]=X_Djleij[1+16+i];
			temp[2*i+1]=(temp[2*i])>>4;
			temp[2*i]=temp[2*i]&0x0f;
			}
		}
	WriteWord(Page,HANZI*4,"用");
	WriteWord(Page,HANZI*5,"电");
	WriteWord(Page,HANZI*6,"量");
	WriteASCII(Page,HANZI*7,":");
	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
 	WriteASCII((Page+2),ZIMU*1," ");
 	WriteASCII((Page+2),ZIMU*2," ");
 	WriteASCII((Page+2),ZIMU*3," ");
	for(i=7;i>=3;i--)
		{
		if(temp[i] == 0)
			{
			temp[i] = 10;
			}
		else
			{
			break;
			}
		}
	WriteBCD((Page+2),ZIMU*4,temp[7]);
	WriteBCD((Page+2),ZIMU*5,temp[6]);
	WriteBCD((Page+2),ZIMU*6,temp[5]);
	WriteBCD((Page+2),ZIMU*7,temp[4]);
	WriteBCD((Page+2),ZIMU*8,temp[3]);		  
	WriteBCD((Page+2),ZIMU*9,temp[2]);
	WriteASCII((Page+2),ZIMU*10,".");
	WriteBCD((Page+2),ZIMU*11,temp[1]);
	WriteBCD((Page+2),ZIMU*12,temp[0]);
	WriteASCII((Page+2),ZIMU*13,"k");		
	WriteASCII((Page+2),ZIMU*14,"W");	 
	WriteASCII((Page+2),ZIMU*15,"h");
	}


/***************当前剩余电量*******************/
void Dis_LeaD(void)
	{
	u8 temp[10];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<5;i++)
		{
		temp[2*i]=X_Sdian[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	WriteWord(Page,HANZI*0,"当");		
	WriteWord(Page,HANZI*1,"前");	  
	if(temp[0] == 0)
		{
		WriteWord(Page,HANZI*2,"剩");		
		WriteWord(Page,HANZI*3,"余");		
		}
	else
		{
		WriteWord(Page,HANZI*2,"透");		
		WriteWord(Page,HANZI*3,"支");		
		}
	WriteWord(Page,HANZI*4,"电");		
	WriteWord(Page,HANZI*5,"量");	  
	WriteASCII(Page,HANZI*6,":");
	WriteASCII(Page,ZIMU*13," ");
	WriteASCII(Page,ZIMU*14," ");
	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
 	WriteASCII((Page+2),ZIMU*1," ");
 	WriteASCII((Page+2),ZIMU*2," ");
 	WriteASCII((Page+2),ZIMU*3," ");
	for(i=9;i>=5;i--)
		{
		if(temp[i] == 0)
			{
			temp[i] = 10;
			}
		else
			{
			break;
			}
		}
	WriteBCD((Page+2),ZIMU*4,temp[9]);
	WriteBCD((Page+2),ZIMU*5,temp[8]);
	WriteBCD((Page+2),ZIMU*6,temp[7]);
	WriteBCD((Page+2),ZIMU*7,temp[6]);
	WriteBCD((Page+2),ZIMU*8,temp[5]);		  
	WriteBCD((Page+2),ZIMU*9,temp[4]);
	WriteASCII((Page+2),ZIMU*10,".");
	WriteBCD((Page+2),ZIMU*11,temp[3]);
	WriteBCD((Page+2),ZIMU*12,temp[2]);
	WriteASCII((Page+2),ZIMU*13,"k");		
	WriteASCII((Page+2),ZIMU*14,"W");	 
	WriteASCII((Page+2),ZIMU*15,"h");
	}


/***************当前剩余金额*******************/
void Dis_LeaJ(void)
	{
	u8 temp[10];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<5;i++)
		{
		temp[2*i]=X_Smoney[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	WriteWord(Page,HANZI*0,"当");		
	WriteWord(Page,HANZI*1,"前");
	if(temp[0] == 0)
		{
		WriteWord(Page,HANZI*2,"剩");		
		WriteWord(Page,HANZI*3,"余");		
		}
	else
		{
		WriteWord(Page,HANZI*2,"透");		
		WriteWord(Page,HANZI*3,"支");		
		}
	WriteWord(Page,HANZI*4,"金");		
	WriteWord(Page,HANZI*5,"额");
	WriteASCII(Page,HANZI*6,":");
	WriteASCII(Page,ZIMU*13," ");
	WriteASCII(Page,ZIMU*14," ");
	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
 	WriteASCII((Page+2),ZIMU*1," ");
 	WriteASCII((Page+2),ZIMU*2," ");
 	WriteASCII((Page+2),ZIMU*3," ");
 	WriteASCII((Page+2),ZIMU*4," "); 			  
	for(i=9;i>=5;i--)
		{
		if(temp[i] == 0)
			{
			temp[i] = 10;
			}
		else
			{
			break;
			}
		}
	WriteBCD((Page+2),ZIMU*5,temp[9]);
	WriteBCD((Page+2),ZIMU*6,temp[8]);
	WriteBCD((Page+2),ZIMU*7,temp[7]);
	WriteBCD((Page+2),ZIMU*8,temp[6]);
	WriteBCD((Page+2),ZIMU*9,temp[5]);		  
	WriteBCD((Page+2),ZIMU*10,temp[4]);
	WriteASCII((Page+2),ZIMU*11,".");
	WriteBCD((Page+2),ZIMU*12,temp[3]);
	WriteBCD((Page+2),ZIMU*13,temp[2]);
	WriteWord((Page+2),HANZI*7,"元");

	}

/***************总购电次数*******************/
void Dis_GCount(void)
	{
	u8 temp[4];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<2;i++)
		{
		temp[2*i]=X_Goudc[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	if(temp[3] == 0x0f)
		{
		;
		}
	else
		{
		WriteWord(Page,HANZI*0,"总");
		WriteWord(Page,HANZI*1,"购");
		WriteWord(Page,HANZI*2,"电");
		WriteWord(Page,HANZI*3,"次");
		WriteWord(Page,HANZI*4,"数");
		WriteASCII(Page,HANZI*5,":");
		WriteASCII(Page,ZIMU*11," ");
		WriteASCII(Page,ZIMU*12," ");
		WriteASCII(Page,ZIMU*13," ");
		WriteASCII(Page,ZIMU*14," ");
		WriteASCII(Page,ZIMU*15," ");
	 	WriteASCII((Page+2),ZIMU*0," ");
	 	WriteASCII((Page+2),ZIMU*1," ");
	 	WriteASCII((Page+2),ZIMU*2," ");
	 	WriteASCII((Page+2),ZIMU*3," ");
	 	WriteASCII((Page+2),ZIMU*4," ");
	 	WriteASCII((Page+2),ZIMU*5," ");
	 	WriteASCII((Page+2),ZIMU*6," ");
	 	WriteASCII((Page+2),ZIMU*7," ");
	 	WriteASCII((Page+2),ZIMU*8," ");
	 	WriteASCII((Page+2),ZIMU*9," ");
		for(i=3;i>=1;i--)
			{
			if(temp[i] == 0)
				{
				temp[i] = 10;
				}
			else
				{
				break;
				}
			}
		WriteBCD((Page+2),ZIMU*10,temp[3]);		  
		WriteBCD((Page+2),ZIMU*11,temp[2]);
		WriteBCD((Page+2),ZIMU*12,temp[1]);
		WriteBCD((Page+2),ZIMU*13,temp[0]);
		WriteWord((Page+2),HANZI*7,"次");
		}
	}


/***************最后一次购电时间*******************/
void Dis_Lastbuytime(void)
	{
	u8 temp[10];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<5;i++)
		{
		temp[2*i]=X_Lgoudt[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	WriteWord(Page,HANZI*0,"最");
	WriteWord(Page,HANZI*1,"近");
	WriteWord(Page,HANZI*2,"购");
	WriteWord(Page,HANZI*3,"电");
	WriteWord(Page,HANZI*4,"时");
	WriteWord(Page,HANZI*5,"间");
	WriteASCII(Page,HANZI*6,":");
	WriteASCII(Page,ZIMU*13," ");
 	WriteASCII(Page,ZIMU*14," ");
 	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
 	WriteASCII((Page+2),ZIMU*1," ");
 	WriteASCII((Page+2),ZIMU*2," ");
 	WriteASCII((Page+2),ZIMU*3," ");
	WriteBCD((Page+2),ZIMU*4,temp[7]);
	WriteBCD((Page+2),ZIMU*5,temp[6]);						
	WriteWord((Page+2),HANZI*3,"月");
	WriteBCD((Page+2),ZIMU*8,temp[5]);
	WriteBCD((Page+2),ZIMU*9,temp[4]);						
	WriteWord((Page+2),HANZI*5,"日");
	WriteBCD((Page+2),ZIMU*12,temp[3]);
	WriteBCD((Page+2),ZIMU*13,temp[2]);						
	WriteWord((Page+2),HANZI*7,"时");						
	}


/***************累计购电量*******************/
void Dis_GTotal(void)
	{
	u8 temp[8];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<4;i++)
		{
		temp[2*i]=X_Ljgoud[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	if(temp[3] == 0x0f)
		{
		;
		}
	else
		{
		WriteWord(Page,HANZI*0,"累");
		WriteWord(Page,HANZI*1,"计");
		WriteWord(Page,HANZI*2,"购");
		WriteWord(Page,HANZI*3,"电");
		WriteWord(Page,HANZI*4,"量");
		WriteASCII(Page,HANZI*5,":");
		WriteASCII(Page,ZIMU*11," ");
		WriteASCII(Page,ZIMU*12," ");
		WriteASCII(Page,ZIMU*13," ");
		WriteASCII(Page,ZIMU*14," ");
		WriteASCII(Page,ZIMU*15," ");
	 	WriteASCII((Page+2),ZIMU*0," ");
	 	WriteASCII((Page+2),ZIMU*1," ");
	 	WriteASCII((Page+2),ZIMU*2," ");
	 	WriteASCII((Page+2),ZIMU*3," ");  
		for(i=7;i>=3;i--)
			{
			if(temp[i] == 0)
				{
				temp[i] = 10;
				}
			else
				{
				break;
				}
			}
		WriteBCD((Page+2),ZIMU*4,temp[7]);		  
		WriteBCD((Page+2),ZIMU*5,temp[6]);
		WriteBCD((Page+2),ZIMU*6,temp[5]);		  
		WriteBCD((Page+2),ZIMU*7,temp[4]);
		WriteBCD((Page+2),ZIMU*8,temp[3]);		  
		WriteBCD((Page+2),ZIMU*9,temp[2]);
		WriteASCII((Page+2),ZIMU*10,".");
		WriteBCD((Page+2),ZIMU*11,temp[1]);
		WriteBCD((Page+2),ZIMU*12,temp[0]);
		WriteASCII((Page+2),ZIMU*13,"k");		
		WriteASCII((Page+2),ZIMU*14,"W");	 
		WriteASCII((Page+2),ZIMU*15,"h");
		}
	}



/****************累计购电金额***********************/
void Dis_Tbuyj(void)
	{
	u8 temp[8];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<4;i++)
		{
		temp[2*i]=X_Leigoudj[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	WriteWord(Page,HANZI*0,"累");
	WriteWord(Page,HANZI*1,"计");
	WriteWord(Page,HANZI*2,"购");
	WriteWord(Page,HANZI*3,"电");
	WriteWord(Page,HANZI*4,"金");
	WriteWord(Page,HANZI*5,"额");
	WriteASCII(Page,HANZI*6,":");
	WriteASCII(Page,ZIMU*13," ");
	WriteASCII(Page,ZIMU*14," ");
	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
 	WriteASCII((Page+2),ZIMU*1," ");
 	WriteASCII((Page+2),ZIMU*2," ");
 	WriteASCII((Page+2),ZIMU*3," "); 
 	WriteASCII((Page+2),ZIMU*4," "); 
	for(i=7;i>=3;i--)
		{
		if(temp[i] == 0)
			{
			temp[i] = 10;
			}
		else
			{
			break;
			}
		}
	WriteBCD((Page+2),ZIMU*5,temp[7]);
	WriteBCD((Page+2),ZIMU*6,temp[6]);	
	WriteBCD((Page+2),ZIMU*7,temp[5]);
	WriteBCD((Page+2),ZIMU*8,temp[4]);	
	WriteBCD((Page+2),ZIMU*9,temp[3]);
	WriteBCD((Page+2),ZIMU*10,temp[2]);	
	WriteASCII((Page+2),ZIMU*11,".");
	WriteBCD((Page+2),ZIMU*12,temp[1]);
	WriteBCD((Page+2),ZIMU*13,temp[0]);
	WriteWord((Page+2),HANZI*7,"元");
	}


/****************最后一次购电金额***********************/
void Dis_Lastbuyj(void)
	{
	u8 temp[8];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<4;i++)
		{
		temp[2*i]=D_Lgoudj[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	WriteWord(Page,HANZI*0,"最");
	WriteWord(Page,HANZI*1,"近");
	WriteWord(Page,HANZI*2,"购");
	WriteWord(Page,HANZI*3,"电");
	WriteWord(Page,HANZI*4,"金");
	WriteWord(Page,HANZI*5,"额");
	WriteASCII(Page,HANZI*6,":");
	WriteASCII(Page,ZIMU*13," ");
	WriteASCII(Page,ZIMU*14," ");
	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
 	WriteASCII((Page+2),ZIMU*1," ");
 	WriteASCII((Page+2),ZIMU*2," ");
 	WriteASCII((Page+2),ZIMU*3," "); 
 	WriteASCII((Page+2),ZIMU*4," "); 
	for(i=7;i>=3;i--)
		{
		if(temp[i] == 0)
			{
			temp[i] = 10;
			}
		else
			{
			break;
			}
		}
	WriteBCD((Page+2),ZIMU*5,temp[7]);
	WriteBCD((Page+2),ZIMU*6,temp[6]);	
	WriteBCD((Page+2),ZIMU*7,temp[5]);
	WriteBCD((Page+2),ZIMU*8,temp[4]);	
	WriteBCD((Page+2),ZIMU*9,temp[3]);
	WriteBCD((Page+2),ZIMU*10,temp[2]);	
	WriteASCII((Page+2),ZIMU*11,".");
	WriteBCD((Page+2),ZIMU*12,temp[1]);
	WriteBCD((Page+2),ZIMU*13,temp[0]);
	WriteWord((Page+2),HANZI*7,"元");
	}
/****************当前阶梯电价***********************/
void Dis_Nowjtdj(void)
	{
	u8 temp[8];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<4;i++)
		{
		temp[2*i]=X_Jietdj[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	WriteWord(Page,HANZI*0,"当");
	WriteWord(Page,HANZI*1,"前");
	WriteWord(Page,HANZI*2,"阶");
	WriteWord(Page,HANZI*3,"梯");
	WriteWord(Page,HANZI*4,"电");
	WriteWord(Page,HANZI*5,"价");
	WriteASCII(Page,HANZI*6,":");
	WriteASCII(Page,ZIMU*13," ");
	WriteASCII(Page,ZIMU*14," ");
	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
	for(i=7;i>=5;i--)
		{
		if(temp[i] == 0)
			{
			temp[i] = 10;
			}
		else
			{
			break;
			}
		}
	WriteBCD((Page+2),ZIMU*1,temp[7]);
	WriteBCD((Page+2),ZIMU*2,temp[6]);
	WriteBCD((Page+2),ZIMU*3,temp[5]);
	WriteBCD((Page+2),ZIMU*4,temp[4]);
	WriteASCII((Page+2),ZIMU*5,".");		  
	WriteBCD((Page+2),ZIMU*6,temp[3]);
	WriteBCD((Page+2),ZIMU*7,temp[2]);
	WriteBCD((Page+2),ZIMU*8,temp[1]);
	WriteBCD((Page+2),ZIMU*9,temp[0]);
	WriteWord((Page+2),HANZI*5,"元");		 
	WriteASCII((Page+2),ZIMU*12,"/");		 	
	WriteASCII((Page+2),ZIMU*13,"k");		 
	WriteASCII((Page+2),ZIMU*14,"W");	 
	WriteASCII((Page+2),ZIMU*15,"h");
	}
/****************上一次校时时间***********************/
void Dis_Lasttiming(void)
	{
	u8 temp[12];
	u8 i;
	u8 Page;
	if(Page_dis%2 == 0)
		{
		Page = 0;
		}
	else
		{
		Page = 4;
		}
	for(i=0;i<4;i++)
		{
		temp[2*i]=X_DTime[1+i];
		temp[2*i+1]=(temp[2*i])>>4;
		temp[2*i]=temp[2*i]&0x0f;
		}
	WriteWord(Page,HANZI*0,"数");
	WriteWord(Page,HANZI*1,"据");
	WriteWord(Page,HANZI*2,"更");
	WriteWord(Page,HANZI*3,"新");
	WriteWord(Page,HANZI*4,"时");
	WriteWord(Page,HANZI*5,"间");
	WriteASCII(Page,HANZI*6,":");
	WriteASCII(Page,ZIMU*13," ");
	WriteASCII(Page,ZIMU*14," ");
	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
	WriteASCII(Page,ZIMU*13," ");
 	WriteASCII(Page,ZIMU*14," ");
 	WriteASCII(Page,ZIMU*15," ");
 	WriteASCII((Page+2),ZIMU*0," ");
 	WriteASCII((Page+2),ZIMU*1," ");
 	WriteASCII((Page+2),ZIMU*2," ");
 	WriteASCII((Page+2),ZIMU*3," ");
	WriteBCD((Page+2),ZIMU*4,temp[5]);
	WriteBCD((Page+2),ZIMU*5,temp[4]);						
	WriteWord((Page+2),HANZI*3,"月");
	WriteBCD((Page+2),ZIMU*8,temp[3]);
	WriteBCD((Page+2),ZIMU*9,temp[2]);						
	WriteWord((Page+2),HANZI*5,"日");
	WriteBCD((Page+2),ZIMU*12,temp[1]);
	WriteBCD((Page+2),ZIMU*13,temp[0]);						
	WriteWord((Page+2),HANZI*7,"时");
	}

/****************链路测试***********************/
void Dis_Link(void)
	{
	Page_dis = 0;
	WriteASCII(0,ZIMU*0," ");
	WriteASCII(0,ZIMU*1," ");						
	WriteWord(0,ZIMU*2,"用");
	WriteWord(0,ZIMU*4,"电");					
	WriteWord(0,ZIMU*6,"查");					
	WriteWord(0,ZIMU*8,"询");					
	WriteWord(0,ZIMU*10,"终");					
	WriteWord(0,ZIMU*12,"端");					
	WriteASCII(0,ZIMU*14," ");						
	WriteASCII(0,ZIMU*15," ");
 	WriteASCII(2,ZIMU*0," ");
 	WriteASCII(2,ZIMU*1," ");
 	WriteASCII(2,ZIMU*2," ");							
 	WriteASCII(2,ZIMU*3," ");
 	WriteASCII(2,ZIMU*4,"L");
 	WriteASCII(2,ZIMU*5,"i");
 	WriteASCII(2,ZIMU*6,"n");
 	WriteASCII(2,ZIMU*7,"k");
 	WriteASCII(2,ZIMU*8," ");
 	WriteASCII(2,ZIMU*9,"T");
 	WriteASCII(2,ZIMU*10,"e");
 	WriteASCII(2,ZIMU*11,"s");
 	WriteASCII(2,ZIMU*12,"t");
 	WriteASCII(2,ZIMU*13,":");
 	WriteASCII(2,ZIMU*14,"O");
 	WriteASCII(2,ZIMU*15,"K");
	Dis_TRH();
	}
/****************显示当前时间***********************/
void Dis_NowTime(void)
	{
	u32 TimeVar;
	TimeVar = RTC_GetCounter();
	Now_time.hour = TimeVar / 3600;
	Now_time.min = (TimeVar % 3600) / 60;
	Now_time.sec = (TimeVar % 3600) % 60;
	Page_dis = 0;
	WriteWord(0,ZIMU*0,"当");
	WriteWord(0,ZIMU*2,"前");
	WriteASCII(0,ZIMU*4," ");
	WriteASCII(0,ZIMU*5," ");
	WriteASCII(0,ZIMU*6," ");
	WriteASCII(0,ZIMU*7," ");

//	WriteWord(0,ZIMU*4,"时");					
//	WriteWord(0,ZIMU*6,"间");					
	WriteASCII(0,ZIMU*8," ");
	WriteASCII(0,ZIMU*9," ");
	WriteASCII(0,ZIMU*10," ");					
	WriteASCII(0,ZIMU*11," ");					
	WriteASCII(0,ZIMU*12," ");					
	WriteASCII(0,ZIMU*13," ");					
	WriteASCII(0,ZIMU*14," ");						
	WriteASCII(0,ZIMU*15," ");
//	WriteBCD(0,ZIMU*13,(Lcd_counter/100)%10);
//	WriteBCD(0,ZIMU*14,(Lcd_counter/10)%10);
//	WriteBCD(0,ZIMU*15,Lcd_counter%10); 

	WriteASCII(2,ZIMU*0," ");
	WriteASCII(2,ZIMU*1," ");
	WriteASCII(2,ZIMU*2," ");
	WriteASCII(2,ZIMU*3," ");
	WriteASCII(2,ZIMU*4," ");
	WriteASCII(2,ZIMU*5," ");
	WriteASCII(2,ZIMU*6," ");
	WriteASCII(2,ZIMU*7," ");
	WriteBCD(2,ZIMU*8,Now_time.hour/10);
	WriteBCD(2,ZIMU*9,Now_time.hour%10);
	WriteASCII(2,ZIMU*10,":");
	WriteBCD(2,ZIMU*11,Now_time.min/10);
	WriteBCD(2,ZIMU*12,Now_time.min%10);
	WriteASCII(2,ZIMU*13,":");
	WriteBCD(2,ZIMU*14,Now_time.sec/10);
	WriteBCD(2,ZIMU*15,Now_time.sec%10); 
	Dis_TRH();
	}

	
void Dis_test1(void)
{
	u8 Page = 0;
	u8 i;
	for(i=0;i<8;i++)
		{
			WriteWord((Page),HANZI*i,"成");
			WriteWord((Page+2),HANZI*i,"成");
			WriteWord((Page+4),HANZI*i,"成");
			WriteWord((Page+6),HANZI*i,"成");
		}	

}
void Dis_test2(void)
{
	u8 Page = 0;
	u8 i;

	for(i=0;i<8;i++)
		{
			WriteWord((Page),HANZI*i,"都");
			WriteWord((Page+2),HANZI*i,"都");
			WriteWord((Page+4),HANZI*i,"都");
			WriteWord((Page+6),HANZI*i,"都");
		}	
}
void Dis_test3(void)
{
	u8 Page = 0;
	u8 i;

	for(i=0;i<8;i++)
		{
			WriteWord((Page),HANZI*i,"博");
			WriteWord((Page+2),HANZI*i,"博");
			WriteWord((Page+4),HANZI*i,"博");
			WriteWord((Page+6),HANZI*i,"博");
		}	
}
void Dis_test4(void)
{
	u8 Page = 0;
	u8 i;

	for(i=0;i<8;i++)
		{
			WriteWord((Page),HANZI*i,"高");
			WriteWord((Page+2),HANZI*i,"高");
			WriteWord((Page+4),HANZI*i,"高");
			WriteWord((Page+6),HANZI*i,"高");
		}	
}

