/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node 
{
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	int index = 1;
	struct node *start = head;
	while (head != NULL)
	{
		while (head->next != NULL && index<K)
		{
			index++;
			head = head->next;
		}
		if (head != NULL&&index == K)
		{
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->next = head->next;
			head->next = newNode;
			newNode->num = K;
			head = newNode;
			index = 1;
		}
		head = head->next;
	}
	return start;
}
