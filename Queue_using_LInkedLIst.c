
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *front;
struct node *rear;

void insert(int item)
{
	struct node *temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = item;

	if(front == NULL)
	{
		rear = temp;
		front = temp;
		rear->next = NULL;
		front->next = NULL;
	}
	else
	{
		rear->next = temp;
		rear = temp;
		rear->next = NULL;
	}
}

void Delete(void)
{
	struct node *temp;

	if(front != NULL)
	{
		temp = front;
		front = front->next;
		printf("Element deleted is: %d\n",temp->data);
		free(temp);
	}
}

void display(void)
{
	struct node *temp = front;

	while(temp != NULL)
	{
		printf("Element: %d\n",temp->data);
		temp = temp->next;
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
