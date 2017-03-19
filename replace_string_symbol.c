#include<stdio.h>
int main()
{
	char s[20];
	printf("Enter String\n");
	scanf("%s",s);
	int i,count=0,count1=0;;
	for(i=0;s[i];i++)
	{
		count=0,count1=0;
		if(s[i]=='b')
		{
			count++;
			i++;
			while(s[i]=='b')
			{
				count++;
				i++;
			}
			if(s[i]=='c'&&count==2)
			{
				i++;
				count1++;
			}
			switch(count)
			{

				case 2:
					if(count1)
					{			
						s[i-3]='$';
						for(int j=i-2;s[j];j++)
						{
							s[j]=s[j+2];
						}
						i=i-3;
					}
					else
					{
						s[i-2]='*';
						for(int j=i-1;s[j];j++)
						{
							s[j]=s[j+1];
						}
						i=i-2;
					}
					break;
				case 3:
					s[i-3]='&';
					for(int j=i-2;s[j];j++)
					{
						s[j]=s[j+2];
					}
					i=i-3;break;
			}
		}
	}
	printf("%s\n",s);
	return 0;
}
