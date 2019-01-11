#include<stdio.h>
int main()
{
	int a = 0;
	printf("hello,world!\r\n");
#if 0	
	while(1)
	{
		a++;
		if(a==0xffff)
		{
			//printf("a = %d\r\n",a);
			a = 0;
		}
	}
#endif
    return 0;
}
