#include<stdio.h>
int main()
{
	int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int b[2][2]={6,7,10,11};
	int i,j,k,flag=1,l;
	printf("4 * 4 Matrix\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\n2 * 2 Matrix\n\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(l=0;l<4;l++)
		{
			if(a[i][l]==b[0][0])
			{
				for(j=0;j<2;j++)
				{
					for(k=0;k<2;k++)
					{
						if(a[i+j][l+k]==b[j][k])
							flag=1;
						else
						{
							flag=0;
							break;
						}
					}
				}
			}
		}
	}
	if(flag)
		printf("\nGiven 2*2 Matrix is Submatrix of 4*4\n");
	else
		printf("\nGiven 2*2 is Not Submatrix of 4*4\n");
	return 0;
}
