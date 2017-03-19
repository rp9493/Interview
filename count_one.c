#include<stdio.h>
int main()
{
	int num,count=0,num1;
	printf("Enter Number\n");
	scanf("%d",&num);
	num1=num;
	while(num)
	{
		count++;
		num&=num-1;
	}
	printf("%d\n",count);
	return 0;
}
