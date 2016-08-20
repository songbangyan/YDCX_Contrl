#include "config.h"


void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Configure PB0 as KEY1 */
	/* Configure PB1 as KEY2 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
		
	/* Configure PA7 as KEY3 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);		
}

void Keypress(void)
{
	if(sys_flag.Lcd_ON_OFF == OFF)
	{
		KeyValueFor = KEYV_DE;
		sys_flag.Lcd_ON_OFF = ON;
		sys_flag.Lcd_tog = OFF;	
		sys_flag.Lcd_togold = OFF;		
	}else if(KeyValueFor != KEYV_DE)
	{
	}
	Lcd_offcounter = 0;
}

unsigned char HourPlus(unsigned char hour)
{
  hour++;
  if(hour > 23)
  {
    hour = 0;
  }
  return hour;
}
unsigned char MinPlus(unsigned char min)
{
  min++;
  if(min > 59)
  {
    min = 0;
  }
  return min;
}

void DealKeyup(void)
{
  switch(KeyValueFor)
  {
    case(KEYV_NH):
      Now_Time.hour = HourPlus(Now_Time.hour);
      RTC_Set(Now_Time.hour,Now_Time.min,Now_Time.sec);  
      break;    
    case(KEYV_SH):
      Start_T.hour = HourPlus(Start_T.hour);
      break;        
    case(KEYV_EH):
      End_T.hour = HourPlus(End_T.hour);
      break; 
    case(KEYV_NM):
      Now_Time.min = MinPlus(Now_Time.min);
      RTC_Set(Now_Time.hour,Now_Time.min,Now_Time.sec);  
      break;    
    case(KEYV_SM):
      Start_T.min = MinPlus(Start_T.min);
      break;        
    case(KEYV_EM):
      End_T.min = MinPlus(End_T.min);
      break; 
		default:
			break;

  }
}
unsigned char HourDec(unsigned char hour)
{
  hour--;
  if(hour > 23)
  {
    hour = 23;
  }
  return hour;
}
unsigned char MinDec(unsigned char min)
{
  min--;
  if(min > 59)
  {
    min = 59;
  }
  return min;
}

void DealKeydown(void)
{
  switch(KeyValueFor)
  {
    case(KEYV_NH):
      Now_Time.hour = HourDec(Now_Time.hour);
      RTC_Set(Now_Time.hour,Now_Time.min,Now_Time.sec);  
      break;    
    case(KEYV_SH):
      Start_T.hour = HourDec(Start_T.hour);
      break;        
    case(KEYV_EH):
      End_T.hour = HourDec(End_T.hour);
      break; 
    case(KEYV_NM):
      Now_Time.min = MinDec(Now_Time.min);
      RTC_Set(Now_Time.hour,Now_Time.min,Now_Time.sec);  
      break;    
    case(KEYV_SM):
      Start_T.min = MinDec(Start_T.min);
      break;        
    case(KEYV_EM):
      End_T.min = MinDec(End_T.min);
      break; 
		default:
			break;

  }
}

void DealKeyent(void)
{
  KeyValueFor++;
  if(KeyValueFor != 0)
  {
    sys_flag.Lcd_tog = ON;
		sys_flag.Lcd_togold = ON;
  }
  if(KeyValueFor > 6)
  {
    sys_flag.Lcd_tog = OFF;
		sys_flag.Lcd_togold = OFF;
    KeyValueFor = 0;
  }
}
  
void Check_KeyUP(void)
{
	if(GPIO_KEYU_F())
  {		
		Keypress();
    if(Key_Up.En == 1)
    {
      if((systick - Key_Up.Start_t) > KEYDELAY)
      {
				Key_Up.Start_t = systick;
        DealKeyup();        
      }        
    }else
    {
      Key_Up.Start_t = systick;
      Key_Up.En = 1;
    }
  }else
  {
    Key_Up.En = 0;
  }
}

void Check_KeyDOWN(void)  
{
  if(GPIO_KEYD_F())
  {
		Keypress();
    if(Key_Down.En == 1)
    {
      if((systick - Key_Down.Start_t) > KEYDELAY)
      {
				Key_Down.Start_t = systick;
        DealKeydown();
      }        
    }else
    {
      Key_Down.Start_t = systick;
      Key_Down.En = 1;
    }
  }else
  {
    Key_Down.En = 0;
  }
}
void Check_KeyENT(void)  
{
  if(GPIO_KEYQ_F())
  {
		Keypress();    
    if(Key_Ent.En == 1)
    {
      if((systick - Key_Ent.Start_t) > KEYDELAY)
      {
				Key_Ent.Start_t = systick;
        DealKeyent();
      }        
    }else
    {
      Key_Ent.Start_t = systick;
      Key_Ent.En = 1;
    }
  }else
  {
    Key_Ent.En = 0;
  }     
}  
void Check_Key(void)
{
  Check_KeyUP();
  Check_KeyDOWN();
  Check_KeyENT();
}
void SaveTime(void)
{
	u8 i,NbrOfPage;
	u32 tick1,tick2;
	u32 tick_rec1,tick_rec2;
//	u16 tmp = 0;
	volatile FLASH_Status FLASHStatus;
	FLASHStatus = FLASH_COMPLETE;
	tick1 = Time2tick(&Start_T);
	tick2 = Time2tick(&End_T);
	tick_rec1 = (*(vu32*) StartAddr);
	tick_rec2 = (*(vu32*) (StartAddr+4));
	if((tick1 != tick_rec1)||(tick2 != tick_rec2))
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
		FLASH_ProgramWord(StartAddr,tick1);
		FLASH_ProgramWord(StartAddr+4,tick2);
	/* lock the Flash Program Erase controller */
		FLASH_Lock();				
	}
}

void SysTickDeal(void)
{
	systick++;
	systick_time++;
	if(sys_flag.Lcd_ON_OFF == ON)
	{
		Lcd_offcounter ++;		
		Lcd_refcount ++;
		if(Lcd_refcount >= 200)
		{
			Lcd_refcount = 0;
			sys_flag.Lcd_ref = ON;
		}
		if(Lcd_offcounter >= 20000)
		{
			Lcd_offcounter = 0;			
			KeyValueFor = KEYV_DE;
			sys_flag.Lcd_ON_OFF = OFF;
			sys_flag.Check_save = ON;
		}
	}
	if(sys_flag.Lcd_tog == ON)
	{
		Lcd_togcount ++;
		if(Lcd_togcount >= 200)
		{
			Lcd_togcount = 0;
			if(sys_flag.Lcd_togold == ON)
			{
				sys_flag.Lcd_togold = OFF;
			}else
			{
				sys_flag.Lcd_togold = ON;
			}
		}
	}
	if(systick_time >= 24*3600*1000)
	{
		systick_time = 0;
	}
}

void SysPowerOn(void)
{
	u32 tick_rec1,tick_rec2;
	sys_flag.Lcd_ON_OFF = ON;
  KeyValueFor = KEYV_DE;
	tick_rec1 = (*(vu32*) StartAddr);
	tick_rec2 = (*(vu32*) (StartAddr+4));
	Tick2time(tick_rec1,&Start_T);
	Tick2time(tick_rec2,&End_T);
	systick_time = 20*3600*1000;
}

void CheckTime(void)
{
	u32 tick1,tick2;
	tick1 = Time2tick(&Start_T);
	tick2 = Time2tick(&End_T);
	if((tick1 < (systick_time/1000))||(tick2 > (systick_time/1000)))
	{
		GPIO_5V_ON();
	}
	else
	{
		GPIO_5V_OFF();
	}
}


