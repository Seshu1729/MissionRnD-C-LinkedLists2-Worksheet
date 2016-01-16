/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node 
{
	int num;
	struct node *next;
};

//METHOD 1:: (Using Recursion)

struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else if (head1->num < head2->num)
	{
		head1->next = merge2LinkedLists(head1->next, head2);
		return head1;
	}
	else
	{
		head2->next = merge2LinkedLists(head1, head2->next);
		return head2;
	}
}

/*

METHOD 2:: (Using Iteration)

struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	struct node *head, *returnHead;
	if (head1 == NULL&&head2 == NULL)
		return NULL;
	else if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else if (head1->num > head2->num)
	{
		head = head2;
		returnHead = head2;
		head2 = head2->next;
	}
	else
	{
		head = head1;
		returnHead = head;
		head1 = head1->next;
	}
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->num > head2->num)
		{
			head->next = head2;
			head = head->next;
			head2 = head2->next;
		}
		else
		{
			head->next = head1;
			head = head->next;
			head1 = head1->next;
		}
	}
	if (head1 != NULL)
		head->next = head1;
	if (head2 != NULL)
		head->next = head2;
	return returnHead;
}

*/
