#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node *insertFront(node *head, int d);
node *insertBack(node *head, int d);
void print(node *head);
int max(node *head);
int min(node *head);
int locInList(node *head, int x);

int main()
{
	node *head = NULL;

	head = insertBack(head, 5);
	head = insertFront(head, 4);
	head = insertFront(head, 3);
	head = insertBack(head, 6);
	head = insertBack(head, 7);
	print(head);

	printf("Max: %d\n", max(head));
	printf("Min: %d\n", min(head));
	printf("locInList 5: %d\n", locInList(head, 5));
	printf("locInList 9: %d\n", locInList(head, 9));
	return 0;
}

node *insertFront(node *head, int d)
{
	node *tmp = NULL;
	tmp = malloc(sizeof(node));
	tmp->data = d;
	tmp->next = head;
	head = tmp;
	return head;
}

node *insertBack(node *head, int d)
{
	node *tmp = NULL;
	node *new = NULL;
	tmp = head;

	if (head == NULL)
	{
		insertFront(head, d);
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		new = malloc(sizeof(node));
		new->data = d;
		tmp->next = new;
		new->next = NULL;
		return head;
	}
}

void print(node *head)
{
	node *tmp = NULL;
	tmp = head;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
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
	int location = 0;
	int found = -1;
	while (tmp != NULL)
	{
		if (tmp->data == x)
		{
			found++;
			break;
		}
		location++;
		tmp = tmp->next;
	}
	if (found == -1)
	{
		location = -1;
	}
	return location;
}
