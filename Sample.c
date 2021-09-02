#include<stdio.h> 
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head;


void Display(struct node *ptr);

void InsertAtEnd(struct node *ptr, int iData);

void InsertAtMiddle(struct node *ptr, int iData, int iPos);

void InsertAtBeginning(struct node *ptr, int iData);

void DeleteHead(struct node *ptr);

void Search(struct node* ptr, int iKey);

void DeleteAtPos(struct node *head, int iPos);

void DeleteAtEnd(struct node *head);

void reverse();

int main()
{
	
	head = (struct node*)malloc(sizeof(struct node));
	head->data = 1;
	head->next = NULL;

	InsertAtEnd(head,2);
	InsertAtEnd(head,3);
	InsertAtEnd(head,4);
	InsertAtEnd(head,5);
	InsertAtEnd(head,6);
	
	Display(head);
	reverse();

	while(1);

	return 0;
}

void InsertAtBeginning(struct node *head, int iData)
{
	struct node *temp;
	struct node *p = head;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = iData;

	temp->next = p;
	p->next = NULL;

	Display(head);
}

void InsertAtEnd(struct node *ptr, int iData)
{
	struct node *temp;
	struct node *p = ptr;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = iData;

	while(p->next != NULL)
	{
		p = p->next;
	}
	
	temp->next = p->next;
	p->next = temp;

	//Display(ptr);
}

void InsertAtMiddle(struct node *ptr, int iData, int iPos)
{
	struct node *temp;
	struct node *p = ptr;
	int pos = 1;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = iData;

	while(p->next != NULL)
	{
		pos++;
		if(pos == iPos)
		{
			temp->next = p->next;
			p->next = temp;
			break;
		}		
		p = p->next;
	}

	Display(ptr);
}

void Display(struct node *ptr)
{
	struct node *temp = ptr;

	while(temp != NULL)
	{
		printf("Elements : %d\n",temp->data);
		temp = temp->next;
	}
}

void Search(struct node* ptr, int iKey)
{
	struct node *temp = ptr;
	int pos = 1;

	while(temp != NULL)
	{
		if(iKey == temp->data)
		{
			printf("Elements found at Position : %d\n",pos);
		}

		pos++;
		temp = temp->next;
	}
}

void DeleteHead(struct node *head)
{
	struct node *temp = head;

	temp = temp->next;

	//Display(temp);
}

void DeleteAtPos(struct node *head, int iPos)
{
	struct node *temp = head;
	int pos = 1;

	while(temp->next != NULL)
	{
		pos++;
		if(iPos == pos)
		{
			temp->next = temp->next->next;
			break;
		}

		temp = temp->next;
	}

	Display(head);
}

void DeleteAtEnd(struct node *head)
{
	struct node *temp = head;

	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = temp->next->next;
}

void reverse()
{
	struct node *curr,*prev;

	printf("reverse\n");

	prev = head;
	curr = head->next;
	head = head->next;
	prev->next = NULL;

	while(head != NULL)
	{
		head = head->next;
		curr->next = prev;
		prev = curr;
		curr = head;
	}

	Display(prev);
}