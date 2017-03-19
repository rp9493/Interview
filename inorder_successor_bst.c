#include<stdio.h>
#include<stdlib.h>
typedef struct s
{
	struct s *left;
	int data;
	struct s *right;
}S;
void add(S **,int);
void print(S *);
S* inorder_succ(S *,int);
S* FindRoot(S*,int);
int main()
{
	S *hp=NULL;
	int i,a[]={5,6,3,4,1,2,10,8,7,9};
	int len=sizeof(a)/sizeof(a[0]);
	for(i=0;i<len;i++)
		add(&hp,a[i]);
	print(hp);
	printf("\n");
	S *temp=inorder_succ(hp,4);
	printf("%d\n",temp->data);
	return 0;
}
void add(S **p,int dat)
{
	if(*p==NULL)
	{
		S *temp=(S *)malloc(sizeof(S));
		temp->data=dat;
		*p=temp;
	}
	if((*p)->data>dat)
	{
		add(&(*p)->left,dat);
	}
	else if((*p)->data<dat)
	{
		add(&(*p)->right,dat);
	}
}
void print(S *p)
{
	if(p)
	{
		print(p->left);
		printf("%d ",p->data);
		print(p->right);
	}
}
S * inorder_succ(S *p,int dat)
{
	S *cur=FindRoot(p,dat);
	if(cur->right!=NULL)
	{
		S *temp=cur->right;
		while(temp->left)
			temp=temp->left;
		return temp;
	}
	else
	{
		S *succ=NULL;
		S *anc=p;
		while(anc!=cur)
		{
			if(cur->data<anc->data)
			{
				succ=anc;
				anc=anc->left;
			}
			else
			{
				anc=anc->right;
			}
		}
		return succ;
	}
}
S* FindRoot(S *p,int dat)
{
	if(p==NULL)
		return NULL;
	else if(p->data>dat)
	{
		return FindRoot(p->left,dat);
	}
	else if(p->data<dat)
	{
		return FindRoot(p->right,dat);
	}
	else
		return p;
}
