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
	if(n==1)
	{
		return a[0];
	}
	int m=n/2;
	int left_MSS=msm(a,m);
	int right_MSS=msm(a+m,n-m);
	int leftsum=INT_MIN,rightsum=INT_MIN,sum=0;
	for(int i=m;i<n;i++)
	{
		sum+=a[i];
		rightsum=rightsum>sum?rightsum:sum;
	}
	for(int i=(m-1);i>=0;i--)
	{
		sum+=a[i];
		leftsum=leftsum>sum?leftsum:sum;
	}
	int ans=left_MSS>right_MSS?left_MSS:right_MSS;
	return ans>(leftsum+rightsum)?ans:(leftsum+rightsum);
}
