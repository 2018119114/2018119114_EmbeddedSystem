#include "led.h"


/*
函数名：Led_Pin_Init
函数描述：LED管脚初始化
返回值：无
形参：无
备注：LED1 ------  PB11
	  LED2 ------  PB14
	  LED3 ------  PA11
	  都配置为推挽输出
*/
void Led_Pin_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);  			//打开A，B组时钟
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	//定义一个结构体变量
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;	         	 	//推挽输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_14; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					//配置输出速度为2Mhz
    GPIO_Init( GPIOB,  &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11 ; 
	GPIO_Init( GPIOA,  &GPIO_InitStruct);
	
	
	GPIO_SetBits( GPIOB,  GPIO_Pin_11|GPIO_Pin_14);                             //给PB11一个高电平
	
	GPIO_SetBits( GPIOA,  GPIO_Pin_11);
}


//1.打开时钟A或B组时钟
//2.GPIO初始化
//3.设置输出高电平
void LED1_ON()
{
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	//定义一个结构体变量
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;	         	 	//推挽输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					//配置输出速度为2Mhz
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  
	GPIO_Init( GPIOB,  &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB,  GPIO_Pin_11);
}
	
void LED2_ON()
{
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	//定义一个结构体变量
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;	         	 	//推挽输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					//配置输出速度为2Mhz
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  
	GPIO_Init( GPIOB,  &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB,  GPIO_Pin_14);
}
		
void LED3_ON()
{	
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	//定义一个结构体变量
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;	         	 	//推挽输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					//配置输出速度为2Mhz
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  
	GPIO_Init( GPIOA,  &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOA,  GPIO_Pin_11);
}

