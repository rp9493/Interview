#include<stdio.h>
#include<stdlib.h>
void SpiralPrint(int a[][4],int ,int);
int main()
{
	int a[4][4]={1,2,3,4,12,13,14,5,11,16,15,6,10,9,8,7};
	SpiralPrint(a,4,4);
	return 0;
}
void SpiralPrint(int a[][4],int m,int n)
{
	int t=0,b=m-1,l=0,r=n-1;
	int dir=0;
	while(t<=b&&l<=r)
	{
		if(dir==0)
		{
			for(int i=t;i<=r;i++)
				printf("%d ",a[t][i]);
			t++;
			dir=1;
		}
		else if(dir==1)
		{
			for(int i=t;i<=b;i++)
				printf("%d ",a[i][r]);
			r--;
			dir=2;
		}
		else if(dir==2)
		{
			for(int i=r;i>=l;i--)
				printf("%d ",a[b][i]);
			dir=3;
			b--;
		}
		else if(dir==3)
		{
			for(int i=b;i>=t;i--)
				printf("%d ",a[i][l]);
			l++;
			dir=0;
		}
	}
	printf("\n");
}
