
#include "config.h"


unsigned char RTC_Set(unsigned char hour,unsigned char min,unsigned char sec)
{

	unsigned int seccount = 0;
	seccount+=(u32)hour*3600;//Сʱ������
	seccount+=(u32)min*60; //����������
//	seccount+=sec;//�������Ӽ���ȥ
	//����ʱ��
	systick = seccount*1000;
	return 1;
}
//�õ���ǰ��ʱ��
//����ֵ:1���ɹ�;����:�������.
unsigned char RTC_Get(Time_t *rtc_real)
{
	unsigned int seccount=0;
	seccount = systick/1000;//��ȡ���������ֵ
	rtc_real->hour=seccount/3600; //Сʱ
	rtc_real->min=(seccount%3600)/60; //����
	rtc_real->sec=(seccount%60); //����
	return 1;	
}

unsigned char Tick2time(unsigned int tick, Time_t *rtc_real)
{
	rtc_real->hour=tick/3600; //Сʱ
	rtc_real->min=(tick%3600)/60; //����
	return 1;	
}

unsigned int Time2tick(Time_t *rtc_real)
{
	unsigned int tick;
	tick = rtc_real->hour*3600 + rtc_real->min*60;
	return tick;	
}