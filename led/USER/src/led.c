#include "led.h"


/*
��������Led_Pin_Init
����������LED�ܽų�ʼ��
����ֵ����
�βΣ���
��ע��LED1 ------  PB11
	  LED2 ------  PB14
	  LED3 ------  PA11
	  ������Ϊ�������
*/
void Led_Pin_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);  			//��A��B��ʱ��
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	//����һ���ṹ�����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;	         	 	//�������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_14; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					//��������ٶ�Ϊ2Mhz
    GPIO_Init( GPIOB,  &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11 ; 
	GPIO_Init( GPIOA,  &GPIO_InitStruct);
	
	
	GPIO_SetBits( GPIOB,  GPIO_Pin_11|GPIO_Pin_14);                             //��PB11һ���ߵ�ƽ
	
	GPIO_SetBits( GPIOA,  GPIO_Pin_11);
}


//1.��ʱ��A��B��ʱ��
//2.GPIO��ʼ��
//3.��������ߵ�ƽ
void LED1_ON()
{
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	//����һ���ṹ�����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;	         	 	//�������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					//��������ٶ�Ϊ2Mhz
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  
	GPIO_Init( GPIOB,  &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB,  GPIO_Pin_11);
}
	
void LED2_ON()
{
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	//����һ���ṹ�����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;	         	 	//�������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					//��������ٶ�Ϊ2Mhz
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  
	GPIO_Init( GPIOB,  &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB,  GPIO_Pin_14);
}
		
void LED3_ON()
{	
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	//����һ���ṹ�����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;	         	 	//�������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					//��������ٶ�Ϊ2Mhz
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  
	GPIO_Init( GPIOA,  &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOA,  GPIO_Pin_11);
}

