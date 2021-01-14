#include "key.h"

/*
函数名：Key_Pin_Init
函数描述：KEY管脚初始化
返回值：无
形参：无
备注：KEY1 ------  PA0     按下前低电平  按下后高电平
	  KEY2 ------  PA8
	  kEY3 ------  PB10    按下前高电平  按下后低电平
	  都配置为浮空输入
*/
void Key_Pin_Init(void)
{
	//1.开A组时钟和B组时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);  			//打开A，B组时钟
	
	//2.配置GPIO初始化函数
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	    //定义一个结构体变量
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;	         	 	//浮空输入
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_8; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					    //配置输出速度为2Mhz
	
  GPIO_Init( GPIOA,  &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init( GPIOB,  &GPIO_InitStruct);
	
	
}

/*
函数名：Key_Scan
函数描述：KEY扫描
返回值：具体哪个按键按下就返回什么值   K1按下 返回1
形参：无
备注：具体哪个按键按下就返回什么值   K1按下 返回1
*/
u8 Key_Scan(void)
{
	static u8 KEY_FLAG = 0;
	if((K1 == 1 || K2 == 0 || K3 == 0)&&KEY_FLAG == 0)
	{
		KEY_FLAG = 1;		//禁止扫描
		if(K1 == 1)			//表示按键1按下
		{
			return 1;
		}
		else if(K2 == 0)	//表示按键2按下
		{
			return 2;
		}
		else if(K3 == 0)	//表示按键3按下
		{
			return 3;
		}
	}
	else if( K1 == 0 && K2 == 1 && K3 == 1 && KEY_FLAG == 1)
	{
		KEY_FLAG = 0; 	   //从新允许扫描
	}
	return 0;
}

