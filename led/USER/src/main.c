#include "main.h"



int main(void)  //主函数一个工程只能出现一个main，但是也必须有一个
{
	//这里的代码只运行一次
	//Led_Pin_Init();
	
	while(1)
	{
		//一直循环运行
		Key_Pin_Init();//三个按键初始化
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


