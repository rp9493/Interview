#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
int top=-1;
int isempty();
void push(long int);
long int pop();
int priority(char);
void infix_post();
int eval_prefix();
int white_space(char);
long int stack[MAX];
char infix[MAX],postfix[MAX];
int main()
{
	long int value;
	printf("Enter Expression\n");
	scanf("%s",infix);
	infix_post();
	printf("%s\n",postfix);
	return 0;
}
void infix_post()
{
	char symbol,next;
	unsigned int i,p=0;
	for(i=0;infix[i];i++)
	{
		symbol=infix[i];
		if(!(white_space(symbol)))
		{
			switch(symbol)
			{
				case '(':
					push(symbol);
					break;
				case ')':
					while((next=pop())!='(')
						postfix[p++]=next;break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '^':
					while(!isempty()&&priority(stack[top])>=priority(symbol))
					postfix[p++]=pop();
					push(symbol);
					break;
				default:postfix[p++]=symbol;
			}
		}
	}
	while(!isempty())
		postfix[p++]=pop();
		postfix[p]='\0';
}
int priority(char symbol)
{
	switch(symbol)
	{
		case 'c':
			return 0;
		case '+':
		case '-':	
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
		default: return 0;
	}
}
void push(long int symbol)
{
	if(top>MAX)
	{
		printf("Stack is Overflow\n");
		return;
	}
	stack[++top]=symbol;
}
long int pop()
{
	if(isempty())
	{
		printf("Stack is Underflow\n");
		exit(1);
	}
	return (stack[top--]);
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int white_space(char symbol)
{
	if(symbol==BLANK||symbol==TAB)
		return 1;
	else
		return 0;
}
