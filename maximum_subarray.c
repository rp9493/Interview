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
	int ans=INT_MIN;
	for(int sub_sz=1;sub_sz<=n;++sub_sz)
	{
		for(int start=0;start<n;++start)
		{
			if(start+sub_sz>n)
				break;
			int sum=0;
			for(int i=start;i<(start+sub_sz);i++)
			sum+=a[i];
			ans=ans>sum?ans:sum;
		}
	}
	return ans;
}
