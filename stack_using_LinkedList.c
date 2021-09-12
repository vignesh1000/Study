
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head;


void push(int iData)
{
	struct node *temp;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = iData;

	temp->next = head;
	head = temp;
}

struct node* pop(void)
{
	struct node *temp = head;
	
	head = head->next;

	return temp;
}

void display(void)
{
	struct node *temp = head;

	while(temp != NULL)
	{
		printf("Element: %d\n",temp->data);
		temp = temp->next;
	}
}

void main()
{
	struct node* tmp;
	head = (struct node*)malloc(sizeof(struct node));

	push(2);
	push(3);
	push(4);
	push(5);
	push(6);

	tmp = pop();
	printf("elements : %d\n",tmp->data);
	tmp = pop();
	printf("elements : %d\n",tmp->data);
	tmp = pop();
	printf("elements : %d\n",tmp->data);
	tmp = pop();
	printf("elements : %d\n",tmp->data);
		tmp = pop();
	printf("elements : %d\n",tmp->data);

	while(1);
}
