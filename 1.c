#include<stdio.h>
#include<limits.h>
#include<string.h>
int msm(char *,int);
int main()
{
	char s[]="ABC";
	int len=strlen(s);
	int i=msm(s,len);
	printf("%d\n",i);
	return 0;
}
int msm(char *s,int n)
{
	for(int sub_sz=1;sub_sz<=n;++sub_sz)
	{
		for(int start=0;start<n;++start)
		{
			if(start+sub_sz>n)
				break;
			for(int i=start;i<(start+sub_sz);i++)
				printf("%c",s[i]);
		printf("\n");
		}
	}
	return 1;
}
