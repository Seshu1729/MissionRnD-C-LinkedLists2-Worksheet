/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node 
{
	int num;
	struct node *next;
};

//METHOD 1:: (Using Iteration)

struct node * reverseLinkedList(struct node *head)
{
	struct node  *node1 = NULL, *node2 = NULL;
	while (head != NULL)
	{
		node2 = head->next;
		head->next = node1;
		node1 = head;
		head = node2;
	}
	return node1;
}

/*

METHOD 2:: (Using Recursion)

void makeLinkedListReversed(struct node *head, struct node **newHead, struct node *pre)
{
	if (head->next != NULL)
	{
		*newHead = head->next;
		makeLinkedListReversed(head->next, newHead, head);
	}
	head->next = pre;
}

struct node * reverseLinkedList(struct node *head)
{
	struct node *newHead;
	if (head == NULL || head->next == NULL)
		return head;
	makeLinkedListReversed(head, &newHead, NULL);
	return newHead;
}

*/
