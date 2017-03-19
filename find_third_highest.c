#include<stdio.h>
#include<limits.h>
int main()
{
	int i,arr[] = {12, 13, 1, 10, 34, 16},first,second,third;
	first=arr[0];
	second=INT_MAX;
	third=INT_MAX;
	for(i=1;i<6;i++)
	{
		if(arr[i]>first)
		{
			third=second;
			second=first;
			first=arr[i];
		}
		else if(arr[i]>second)
		{
			third=second;
			second=arr[i];
		}
		else if(arr[i]>third)
			third=arr[i]; 
	}
	printf("%d\n",third);
}
