#include<stdio.h>
#include<limits.h>
int msm(int *,int);
int main()
{
	int a[]={-2,-3,4,-1,-2,1,5,-3};
	int len=sizeof(a)/sizeof(a[0]);
	int i=msm(a,len);
	printf("%d\n",i);
	return 0;
}
int msm(int *a,int n)
{
	int ans=0,sum=0;
	for(int i=0;i<n;++i)
	{
		if(sum+a[i]>0)
		{
			sum+=a[i];
		}
		else
		sum=0;
		ans=ans>sum?ans:sum;
	}
	return ans;
}
