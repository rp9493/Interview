#include<stdio.h>
int strcp(char *,int);
int main()
{
	char s[50];
	printf("Enter String\n");
	scanf("%[^\n]",s);
	strcp(s,0);
	printf("%s\n",s);
}
int strcp(char *s,int i)
{
	int j;
	if(*s)
	{
		j=strcp(s+1,i+1);
		if(j<i)
		{
	/*		char temp=*(s-i+j);
			*(s-i+j)=*s;
			*s=temp;*/
			*(s-i+j)=*(s-i+j)+*s;
			*s=*(s-i+j)-*s;
			*(s-i+j)=*(s-i+j)-*s;
			j=j+1;
			return j;
		}
	}
	else
		return 0;
}
