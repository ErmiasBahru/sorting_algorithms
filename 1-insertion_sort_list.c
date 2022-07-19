#include "sort.h"

/**
 * swap_at_head - swaps node at head with another, sort of
 * inserting at head
 * @head: head of listint_t doubly linked list
 * @start_node: starting node in listint_t list
 * @swap_node: node to swap or insert at head
 * Return: nothing
 */
void swap_at_head(listint_t **head, listint_t *start_node,
listint_t *swap_node)
{
	if (head)
	{
		swap_node->next = start_node;
		swap_node->prev = NULL;
		start_node->prev = swap_node;
		*head = swap_node;
	}
}

/**
 * swap - swaps two node greater than value of current pointer of head
 * @list: listint_t doubly linked list
 * @head: current position of pointer of head in listint_t list
 * Return: nothing
 */
void swap(listint_t **list, listint_t *head)
{
	listint_t *next, *prev;
	listint_t *swap_node = head;
	listint_t *start_node = head->prev;

	while (start_node)
	{
		if (start_node->n > head->n)
		{
			/* fix initialposition of node */
			if (swap_node->next)
				swap_node->next->prev = swap_node->prev;
			if (swap_node->prev)
				swap_node->prev->next = swap_node->next;
			if (!start_node->prev)
			{
				/* insertion to head */
				swap_at_head(list, start_node, swap_node);
			}
			else
			{
				/* fix swap node to new position */
				next = start_node;
				prev = start_node->prev;
				if (next)
					next->prev = swap_node;
				prev->next = swap_node;
				swap_node->prev = prev;
				swap_node->next = next;
			}
			print_list(*list);
		}
		start_node = start_node->prev;
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list using
 * insertion sort algorithm
 * @list: listint_t doubly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head;

	if (!list || !*list)
		return;

	head = *list;
	head = head->next;
	while (head)
	{
		if (head->n < head->prev->n)
			swap(list, head);
		head = head->next;
	}
}
