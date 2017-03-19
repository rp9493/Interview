#include<stdio.h>
#include<stdlib.h>
int flag=1;
typedef struct s
{
	int data;
	struct s*next;
}S;
void add(S **);
void print(S *);
S* palindrome(S *,S *);
int main()
{
	int op;
	S *hp=NULL;
	while(1)
	{
		printf("Enter Option\n1.Add\n2.Display\n3.Check if palindrome or Not\n4.Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: add(&hp);break;
			case 2: print(hp);break;
			case 3:	flag=1; palindrome(hp,hp);
				if(flag)printf("Palindrome\n");
				else printf("Not Palindrome\n");break;
			case 4 : exit(0);
			default : printf("Wrong Option\n");
		}
	}
}
void add(S **p)
{
	S *temp=(S*)malloc(sizeof(S));
	printf("Enter Data\n");
	scanf("%d",&temp->data);
	if(*p==NULL)
	{
		temp->next=*p;
		*p=temp;
	}
	else
	{
		S *temp1=*p;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp->next=temp1->next;
		temp1->next=temp;
	}
	return;
}
void print(S *p)
{
	if(p==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	else
	{
		while(p)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
S* palindrome(S *start,S* tail)
{
	if(tail->next!=NULL)
	{
		start=palindrome(start,tail->next);
	}
	if(start->data!=tail->data)
	{
		flag=0;
	}
	return start->next;
}
