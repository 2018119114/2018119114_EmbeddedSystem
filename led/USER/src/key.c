#include "key.h"

/*
��������Key_Pin_Init
����������KEY�ܽų�ʼ��
����ֵ����
�βΣ���
��ע��KEY1 ------  PA0     ����ǰ�͵�ƽ  ���º�ߵ�ƽ
	  KEY2 ------  PA8
	  kEY3 ------  PB10    ����ǰ�ߵ�ƽ  ���º�͵�ƽ
	  ������Ϊ��������
*/
void Key_Pin_Init(void)
{
	//1.��A��ʱ�Ӻ�B��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);  			//��A��B��ʱ��
	
	//2.����GPIO��ʼ������
	GPIO_InitTypeDef  GPIO_InitStruct; 							 	    //����һ���ṹ�����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;	         	 	//��������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_8; 
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;					    //��������ٶ�Ϊ2Mhz
	
  GPIO_Init( GPIOA,  &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init( GPIOB,  &GPIO_InitStruct);
	
	
}

/*
��������Key_Scan
����������KEYɨ��
����ֵ�������ĸ��������¾ͷ���ʲôֵ   K1���� ����1
�βΣ���
��ע�������ĸ��������¾ͷ���ʲôֵ   K1���� ����1
*/
u8 Key_Scan(void)
{
	static u8 KEY_FLAG = 0;
	if((K1 == 1 || K2 == 0 || K3 == 0)&&KEY_FLAG == 0)
	{
		KEY_FLAG = 1;		//��ֹɨ��
		if(K1 == 1)			//��ʾ����1����
		{
			return 1;
		}
		else if(K2 == 0)	//��ʾ����2����
		{
			return 2;
		}
		else if(K3 == 0)	//��ʾ����3����
		{
			return 3;
		}
	}
	else if( K1 == 0 && K2 == 1 && K3 == 1 && KEY_FLAG == 1)
	{
		KEY_FLAG = 0; 	   //��������ɨ��
	}
	return 0;
}

