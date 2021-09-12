
#include <stdio.h>
#include <stdlib.h>

#define SIZE	10
int stack[SIZE];
int top = -1;

int isEmpty(void)
{
	if(top == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int isFull(void)
{
	if(top == SIZE)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int peek(void)
{
	return stack[top];
}

void push(int iData)
{
	if(isFull())
	{
		top = top + 1;
		stack[top] = iData;
	}
	else
	{
		printf("size is full");
	}
}

void pop(int *iData)
{
	if(isEmpty())
	{
		*iData = stack[top];
		top = top - 1;
	}
	else
	{
		printf("Stack empty");
	}
}


void main()
{
	int iData= 0;
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);

	pop(&iData);
	printf("elements : %d\n",iData);
	pop(&iData);
	printf("elements : %d\n",iData);
	pop(&iData);
	printf("elements : %d\n",iData);
	pop(&iData);
	printf("elements : %d\n",iData);
	pop(&iData);
	printf("elements : %d\n",iData);
	pop(&iData);
	printf("elements : %d\n",iData);

	while(1);
}
