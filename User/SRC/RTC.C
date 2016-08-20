
#include "config.h"


unsigned char RTC_Set(unsigned char hour,unsigned char min,unsigned char sec)
{

	unsigned int seccount = 0;
	seccount+=(u32)hour*3600;//小时秒钟数
	seccount+=(u32)min*60; //分钟秒钟数
//	seccount+=sec;//最后的秒钟加上去
	//设置时钟
	systick_time = seccount*1000;
	return 1;
}
//得到当前的时间
//返回值:1，成功;其他:错误代码.
unsigned char RTC_Get(Time_t *rtc_real)
{
	unsigned int seccount=0;
	seccount = systick_time/1000;//获取秒计数器的值
	rtc_real->hour=seccount/3600; //小时
	rtc_real->min=(seccount%3600)/60; //分钟
	rtc_real->sec=(seccount%60); //秒钟
	return 1;	
}

unsigned char Tick2time(unsigned int tick, Time_t *rtc_real)
{
	rtc_real->hour=tick/3600; //小时
	rtc_real->min=(tick%3600)/60; //分钟
	return 1;	
}

unsigned int Time2tick(Time_t *rtc_real)
{
	unsigned int tick;
	tick = rtc_real->hour*3600 + rtc_real->min*60;
	return tick;	
}
