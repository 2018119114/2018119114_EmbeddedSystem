#include "main.h"



int main(void)  //������һ������ֻ�ܳ���һ��main������Ҳ������һ��
{
	//����Ĵ���ֻ����һ��
	//Led_Pin_Init();
	
	while(1)
	{
		//һֱѭ������
		Key_Pin_Init();//����������ʼ��
		u8 x=Key_Scan();
		if (x==1)
		{
			LED1_ON();
		}
		else if(x==2)
		{
			LED2_ON();
		}
		else if(x==3)
		{
			LED3_ON();
		}
	}
	
	
}


