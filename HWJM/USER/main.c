#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "remote.h"


 int main(void)
 {	 
	u8 key;
	u8 t=0;	
 	u8 *str=0;

	delay_init();	    	 //延时函数初始化	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			     //LED端口初始化
	LCD_Init();	
	KEY_Init();	 	
	Remote_Init();			//红外接收初始化		 	
 
 	POINT_COLOR=RED;		//设置字体为红色 
	LCD_ShowString(30,90,200,16,24,"REMOTE TEST");
   	LCD_ShowString(30,130,200,16,16,"KEYVAL:");		
   	LCD_ShowString(30,150,200,16,16,"SYMBOL:");	  		 	  		    							  
	while(1)
	{
		key=Remote_Scan();	
		if(key)
		{	 
			LCD_ShowNum(86,130,key,3,16);		//显示键值
			//LCD_ShowNum(86,20,RmtCnt,3,16);	//显示按键次数		  
			switch(key)
			{
				
				case 86:str="KEY9";break;				
				case 90:str="KEY8";break;		  
				case 94:str="KEY7";break;		   
				case 82:str="KEY6";break;		    
				case 99:str="KEY5";break;		  
				case 119:str="KEY4";break;	   
				case 66:str="KEY3";break;	    
				case 115:str="KEY2";break;		    
				case 103:str="KEY1";break;
						 
			}
			LCD_Fill(86,170,116+8*8,170+16,WHITE);	//清楚之前的显示
			LCD_ShowString(86,150,200,16,16,str);
			LCD_ShowString(30,185,200,16,24,"Successful!!");
			//显示SYMBOL
		}else delay_ms(10);	  
		t++;
		if(t==50)
		{
			t=0;
			LED0=!LED0;
		}
	}
}






