
#include "C_FILE.h"

struct node{
	int data;
	struct node *next;
}*head;

struct DLLnode{
	int data;
	struct DLLnode *prev;
	struct DLLnode *next;
}*Doublehead;

void display(struct node *ptr);
void reverse();
void search(struct node *head, int iData);
void singlelistInsert(struct node* head,int iData,int iPosition);
void singlelistDelete(struct node* head,int iPosition);
void DoubleListInsert(struct DLLnode* head,int iData,int iPosition);
void DoubleListDelete(struct DLLnode* head,int iPosition);
int FindLoopinList(struct node* head);
struct node* FindStartNodeinCyclicList(struct node* head);
int FindLengthOfLoopinCyclicList(struct node* head);

int main(int argc, char* argv[])
{

	display(head);

	reverse();

	while(1);
	return 0;
}

void display(struct node *head)
{
	struct node *p = head;

	while(p != NULL)
	{
		printf("Data:%d  ",p->data);
		p = p->next;
	}
}

void search(struct node *head, int iData)
{
	struct node *p = head;
	int iPos = 1;

	while(p != NULL)
	{
		if(iData == p->data)
		{
			printf("Element found at position : %d",iPos);
		}
		p = p->next;
		iPos++;
	}
}

void reverse(void)
{
	struct node *prev,*current;

	if(head != NULL)
	{
		prev = head;
		prev->next = NULL;
		current =  head->next;
		head = head->next;

		while(head != NULL)
		{
			head = head->next;
			current->next = prev;
			prev = current;
			current = head;
		}
	}

	display(prev);
}

void singlelistInsert(struct node* head,int iData,int iPosition)
{
	struct node *p = head;
	struct node *newnode;
	int iPos = 1;

	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = iData;

	if(iPosition == 1)
	{
		newnode->next = head;
		head = newnode;
		return;
	}
	else
	{
		while((p!=NULL) && (iPos<iPosition))
		{
			p = p->next;
			iPos++;
		}

		newnode->next = p->next;
		p->next =newnode;
	}
}

void singlelistDelete(struct node* head,int iPosition)
{
	struct node *p = head;
	struct node *temp;
	int iPos = 1;

	if(iPosition == 1)
	{
		head = head->next;
		free(p);
		return;
	}
	else
	{
		while((p!=NULL) && (iPos<iPosition))
		{
			iPos++;
			temp = p;
			p = p->next;
		}
		
		temp->next = p->next;//assign P next pointer to temp
		free(p);
	}
}

void DoubleListInsert(struct DLLnode* Doublehead,int iData,int iPosition)
{
	struct DLLnode *p = Doublehead;
	struct DLLnode *newnode;
	int iPos = 1;

	newnode = (struct DLLnode*)malloc(sizeof(struct DLLnode));
	newnode->data = iData;

	if(iPosition == 1)
	{
		newnode->next = Doublehead;
		newnode->prev = NULL;

		if(Doublehead)
		{
			Doublehead->prev = newnode;
		}

		newnode = Doublehead;
		return;
	}
	else
	{
		while((p->next!=NULL) && (iPos<iPosition-1))
		{
			p = p->next;
			iPos++;
		}
		
		newnode->next = p->next;
		newnode->prev = p;

		if(p->next)
		{
			p->next->prev = newnode;
		}

		p->next = newnode;
	}
}

void DoubleListDelete(struct DLLnode* Doublehead,int iPosition)
{
	struct DLLnode *p = Doublehead;
	struct DLLnode *temp;
	int iPos = 1;

	if(iPosition == 1)
	{
		Doublehead =Doublehead->next;

		if(Doublehead!=NULL)
		{
			Doublehead->prev = NULL;
		}

		free(p);
		return;
	}
	else
	{
		while((p->next!=NULL) && (iPos<iPosition))
		{
			p = p->next;
			iPos++;
		}

		temp = p->prev;
		temp->next = p->next;

		if(p->next)
		{
			p->next->prev = temp;
		}

		free(p);
	}
}

int FindLoopinList(struct node* head)
{
	struct node* slowptr = head;
	struct node* fastptr= head;

	while(slowptr && fastptr && fastptr->next)
	{
		slowptr = slowptr->next;//move slow ptr one position
		fastptr = fastptr->next->next;//move fast pointer two positions

		if(slowptr == fastptr)//if fast and slow meets then the list has a loop
		{
			printf("Loop is present");
			return 1;
		}
	}

	printf("Loop is not present");
	return 0;
}

struct node* FindStartNodeinCyclicList(struct node* head)
{
	struct node* slowptr = head;
	struct node* fastptr= head;
	int iLoopExists = 0;

	while(slowptr && fastptr && fastptr->next)
	{
		slowptr = slowptr->next;//move slow ptr one position
		fastptr = fastptr->next->next;//move fast pointer two positions

		if(slowptr == fastptr)//if fast and slow meets then the list has a loop
		{
			iLoopExists = 1;
			break;
		}
	}

	if(iLoopExists)
	{
		slowptr = head;
		while(slowptr != fastptr)
		{
			slowptr = slowptr->next;
			fastptr = fastptr->next;
		}
		return slowptr;
	}

	return NULL;
}

int FindLengthOfLoopinCyclicList(struct node* head)
{
	struct node* slowptr = head;
	struct node* fastptr= head;
	int iLoopExists = 0;
	int iCounter = 0;

	while(slowptr && fastptr && fastptr->next)
	{
		slowptr = slowptr->next;//move slow ptr one position
		fastptr = fastptr->next->next;//move fast pointer two positions

		if(slowptr == fastptr)//if fast and slow meets then the list has a loop
		{
			iLoopExists = 1;
			break;
		}
	}

	if(iLoopExists)
	{
		fastptr = fastptr->next;
		while(slowptr != fastptr)
		{
			fastptr = fastptr->next;
			iCounter++;
		}
		return iCounter;
	}

	return 0;
}