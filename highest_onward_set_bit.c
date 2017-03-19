#include<stdio.h>
int main()
{
	int num,i,j;
	printf("Enter NUmber\n");
	scanf("%d",&num);
	for(i=31;i>=0;i--)
		printf("%d",num>>i&1);
	printf("\n");
	for(i=31;i>=0;i--)
	{
		if(num>>i&1)
		{
			for(j=i;j>=0;j--)
				num|=1<<j;
			break;
		}
	}
	for(i=31;i>=0;i--)
		printf("%d",num>>i&1);
	printf("\n");
	return 0;
}
