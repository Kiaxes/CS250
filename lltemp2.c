#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;

node *insertFront(node *head, int d);
node *insertBack(node *head, int d);
void print(node *head);
int max(node *head);
int min(node *head);
int locInList(node *head, int x);
void printRev(node *head);
node *removeNode(node *head, int d);

int main()
{
	node *head = NULL;

	head = insertBack(head, 5);
	head = insertFront(head, 4);
	head = insertBack(head, 6);
	head = insertBack(head, 7);
	print(head);
	printRev(head);

	printf("Max: %d\n", max(head));
	printf("Min: %d\n", min(head));
	printf("locInList 5: %d\n", locInList(head, 5));
	printf("locInList 9: %d\n", locInList(head, 9));

	head = removeNode(head, 6);
	print(head);
	head = removeNode(head, 4);
	print(head);
	head = removeNode(head, 7);
	print(head);
	
	return 0;
}

node *insertFront(node *head, int d)
{
	node *tmp = NULL;
	tmp = malloc(sizeof(node));
	tmp->data = d;
	tmp->next = head;
	tmp->prev = NULL;
	head->prev = tmp;
	head = tmp;
	return head;
}

node *insertBack(node *head, int d)
{
	node *tmp = NULL;
	node *new = NULL;
	new = malloc(sizeof(node));
	new->data = d;
	new->next = NULL;

	if (head == NULL)
	{
		head = new;
	}
	else
	{
		tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = new;
		new->prev = tmp;
	}
	return head;
}

void print(node *head)
{
	node *tmp;
	tmp = head;

	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int max(node *head)
{
	node *tmp = head;
	int maximum = head->data;
	while (tmp != NULL)
	{
		if (maximum < tmp->data)
		{
			maximum = tmp->data;
		}
		tmp = tmp->next;
	}
	return maximum;
}
int min(node *head)
{
	node *tmp = head;
	int minimum = head->data;
	while (tmp != NULL)
	{
		if (minimum > tmp->data)
		{
			minimum = tmp->data;
		}
		tmp = tmp->next;
	}
	return minimum;
}

int locInList(node *head, int x)
{
	node *tmp = head;
	int i = 0;
	int loc = -1;
	while (tmp != NULL)
	{
		if (tmp->data == x)
		{
			loc = i;
		}
		tmp = tmp->next;
		i++;
	}
	return loc;
}
void printRev(node *head)
{
	if (head == NULL)
	{
		return;
	}
	node *tail = NULL;
	tail = head;

	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	while (tail != NULL)
	{
		printf("%d ", tail->data);
		tail = tail->prev;
	}
	printf("\n");
}

node *removeNode(node *head, int d)
{
	node *tmp = head;
	while (tmp != NULL)
	{
		if (tmp->data == d && tmp->next != NULL && tmp->prev != NULL)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);
			tmp = head;
			break;
		}
		if (tmp->data == d && tmp->next == NULL)
		{
			tmp->prev->next = NULL;
			head = tmp->prev;
			free(tmp);
			tmp = head;
			break;
		}
		if (tmp->data == d && tmp->prev == NULL)
		{
			tmp->next->prev = NULL;
			head = tmp->next;
			free(tmp);
			tmp = head;
			break;
		}
		tmp = tmp->next;
	}
}