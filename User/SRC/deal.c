#include "config.h"

void HourPlus(unsigned char hour)
{
  hour++;
  if(hour > 23)
  {
    hour = 0;
  }
}
void MinPlus(unsigned char min)
{
  min++;
  if(min > 59)
  {
    min = 0;
  }
}

void DealKeyup(void)
{
  switch(KeyValueFor)
  {
    case(KEYV_NH):
      HourPlus(Now_Time[0]);
      break;    
    case(KEYV_SH):
      HourPlus(Start_T[0]);
      break;        
    case(KEYV_EH):
      HourPlus(End_T[0]);
      break; 
    case(KEYV_NM):
      MinPlus(Now_Time[1]);
      break;    
    case(KEYV_SM):
      MinPlus(Start_T[1]);
      break;        
    case(KEYV_EM):
      MinPlus(End_T[1]);
      break; 
		default:
			break;

  }
}
void HourDec(unsigned char hour)
{
  hour--;
  if(hour > 23)
  {
    hour = 23;
  }
}
void MinDec(unsigned char min)
{
  min++;
  if(min > 59)
  {
    min = 59;
  }
}

void DealKeydown(void)
{
  switch(KeyValueFor)
  {
    case(KEYV_NH):
      HourDec(Now_Time[0]);
      break;    
    case(KEYV_SH):
      HourDec(Start_T[0]);
      break;        
    case(KEYV_EH):
      HourDec(End_T[0]);
      break; 
    case(KEYV_NM):
      MinDec(Now_Time[1]);
      break;    
    case(KEYV_SM):
      MinDec(Start_T[1]);
      break;        
    case(KEYV_EM):
      MinDec(End_T[1]);
      break; 
		default:
			break;

  }
}

void DealKeyent(void)
{
  KeyValueFor++;
  if(KeyValueFor > 6)
  {
    KeyValueFor = 0;
  }
}
  
void Check_Key(void)
{
	if(GPIO_KEYU_F())
  {
    Key_Up.Start_t = systick;
    if(Key_Up.En == 1)
    {
      if((systick - Key_Up.Start_t) > KEYDELAY)
      {
        DealKeyup();        
      }        
    }else
    {
      Key_Up.En = 1;
    }
  }else
  {
    Key_Up.En = 0;
  }
  
  if(GPIO_KEYD_F())
  {
    Key_Down.Start_t = systick;
    if(Key_Down.En == 1)
    {
      if((systick - Key_Down.Start_t) > KEYDELAY)
      {
        DealKeyup();
      }        
    }else
    {
      Key_Down.En = 1;
    }
  }else
  {
    Key_Down.En = 0;
  }
  
  if(GPIO_KEYQ_F())
  {
    Key_Ent.Start_t = systick;
    if(Key_Ent.En == 1)
    {
      if((systick - Key_Ent.Start_t) > KEYDELAY)
      {
        DealKeyent();
      }        
    }else
    {
      Key_Ent.En = 1;
    }
  }else
  {
    Key_Ent.En = 0;
  }
      
}

