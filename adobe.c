#include<stdio.h>
int main()
{
	int num,count,i,j,k,flag=1,flag1=1;
	printf("Entre NUmber\n");
	scanf("%d",&num);
	int num2=num*2-1;
	for(i=0;i<num2;i++)
	{
		k=i<num?i:num2-i;
		for(j=0;j<k;j++)
			printf("%d",num-j);
		for(j=0;j<2*(num-k)-1;j++)
			printf("%d",num-k);
		for(j=k-1;j>=0;j--)
			printf("%d",num-j);
		printf("\n");
	}
	return 0;
}
