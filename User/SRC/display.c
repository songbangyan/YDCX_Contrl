#include "config.h"

//============================================================================= 
//函 数 名: Display()
//功 能: 	主屏显示
//入口参数:无
//出口参数:  无
//返 回 值:  无
//============================================================================= 
void Display(void)
{
	WriteASCII(0,ZIMU*0,'N');
	WriteASCII(0,ZIMU*1,'O');
	WriteASCII(0,ZIMU*2,'W');
	WriteASCII(0,ZIMU*3,' ');
	WriteASCII(0,ZIMU*4,' ');
	WriteBCD(0,ZIMU*5,(Now_Time.hour/10));
	WriteBCD(0,ZIMU*6,(Now_Time.hour%10));
	WriteASCII(0,ZIMU*7,':');
	WriteBCD(0,ZIMU*8,(Now_Time.min/10));
	WriteBCD(0,ZIMU*9,(Now_Time.min%10));
	WriteASCII(0,ZIMU*10,':');
	WriteBCD(0,ZIMU*11,(Now_Time.sec/10));
	WriteBCD(0,ZIMU*12,(Now_Time.sec%10));
	WriteASCII(0,ZIMU*13,' ');
	WriteASCII(0,ZIMU*14,' ');
	WriteASCII(0,ZIMU*15,' ');
	
	WriteASCII(2,ZIMU*0,'S');
	WriteASCII(2,ZIMU*1,' ');
	WriteBCD(2,ZIMU*2,(Start_T.hour/10));
	WriteBCD(2,ZIMU*3,(Start_T.hour%10));
	WriteASCII(2,ZIMU*4,':');
	WriteBCD(2,ZIMU*5,(Start_T.min/10));
	WriteBCD(2,ZIMU*6,(Start_T.min%10));
	WriteASCII(2,ZIMU*7,' ');
	WriteASCII(2,ZIMU*8,' ');
	WriteASCII(2,ZIMU*9,' ');
	WriteASCII(2,ZIMU*10,' ');
	WriteASCII(2,ZIMU*11,' ');
	WriteASCII(2,ZIMU*12,' ');
	WriteASCII(2,ZIMU*13,' ');
	WriteASCII(2,ZIMU*14,' ');
	WriteASCII(2,ZIMU*15,' ');
	
	WriteASCII(4,ZIMU*0,'E');
	WriteASCII(4,ZIMU*1,' ');
	WriteBCD(4,ZIMU*2,(End_T.hour/10));
	WriteBCD(4,ZIMU*3,(End_T.hour%10));
	WriteASCII(4,ZIMU*4,':');	
	WriteBCD(4,ZIMU*5,(End_T.min/10));
	WriteBCD(4,ZIMU*6,(End_T.min%10));
	WriteASCII(4,ZIMU*7,' ');		
	WriteASCII(4,ZIMU*8,' ');
	WriteASCII(4,ZIMU*9,' ');
	WriteASCII(4,ZIMU*10,' ');
	WriteASCII(4,ZIMU*11,' ');
	WriteASCII(4,ZIMU*12,' ');
	WriteASCII(4,ZIMU*13,' ');
	WriteASCII(4,ZIMU*14,' ');
	WriteASCII(4,ZIMU*15,' ');	
	

	WriteBCD(6,ZIMU*0,(temp_p/10));
	WriteBCD(6,ZIMU*1,(temp_p%10));
//  WriteASCII(6,ZIMU*0,' ');		
//  WriteASCII(6,ZIMU*1,' ');		
	WriteASCII(6,ZIMU*2,' ');
	WriteASCII(6,ZIMU*3,' ');
	WriteASCII(6,ZIMU*4,' ');
	WriteASCII(6,ZIMU*5,' ');
	WriteASCII(6,ZIMU*6,' ');
	WriteASCII(6,ZIMU*7,' ');		
	WriteASCII(6,ZIMU*8,' ');
	WriteASCII(6,ZIMU*9,' ');
	WriteASCII(6,ZIMU*10,' ');
	WriteASCII(6,ZIMU*11,' ');
	WriteASCII(6,ZIMU*12,' ');
	WriteASCII(6,ZIMU*13,' ');
	WriteASCII(6,ZIMU*14,' ');
	WriteASCII(6,ZIMU*15,' ');	
}

void Distog(void)
{
  switch(KeyValueFor)
  {
    case(KEYV_NH):
      Displaytog(0,ZIMU*5,HANZI);
      break;    
    case(KEYV_SH):
      Displaytog(2,ZIMU*2,HANZI);
      break;        
    case(KEYV_EH):
      Displaytog(4,ZIMU*2,HANZI);
      break; 
    case(KEYV_NM):
      Displaytog(0,ZIMU*8,HANZI);
      break;    
    case(KEYV_SM):
      Displaytog(2,ZIMU*5,HANZI);
      break;        
    case(KEYV_EM):
      Displaytog(4,ZIMU*5,HANZI);
      break; 
		default:
			break;
	}	
}

void Dismain(void)
{	
	if(sys_flag.Lcd_ON_OFF == ON)
	{
		LCD_shutup();
		RTC_Get(&Now_Time);
		if(sys_flag.Lcd_ref == ON)
		{
			Display();
			if(sys_flag.Lcd_togold == ON)
			{
				Distog();
//				sys_flag.Lcd_tog = OFF;
			}			
			LCDrefur();
			sys_flag.Lcd_ref = OFF;
		}
	}else
	{
    temp_p = 0;
		LCD_shutdown();		
	}
	if(sys_flag.Check_save == ON)
	{
		sys_flag.Check_save = OFF;
		SaveTime();
	}
}














