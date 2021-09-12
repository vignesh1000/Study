
#include <stdio.h>
#include <stdlib.h>

#define SIZE  100

int ArrQueue[SIZE];
int front = -1;
int rear = -1;

void insert(int data)
{
	if(rear == SIZE)
	{
		printf("Queue overflow");
	}
	else
	{
		if(front == -1)
		{
			front = front + 1;
		}
	
		rear = rear + 1;
		ArrQueue[rear] = data;
	}
}

void Delete(void)
{
	if((front == -1)||(front > rear))
	{
		printf("Queue Underflow");
	}
	else
	{
		printf("Element removed : %d\n",ArrQueue[front]);
		front = front + 1;
	}
}

void display(void)
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("Queue Elements are: %d\n",ArrQueue[i]);
	}
}

void main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);

	display();

	Delete();
	Delete();
	Delete();
	Delete();
	Delete();

	while(1);
}
