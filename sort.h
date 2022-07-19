#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/*Bubble sort*/
void bubble_sort(int *array, size_t size);

/* Insertion algorithm methods */
void insertion_sort_list(listint_t **list);
void swap(listint_t **list, listint_t *head);
void swap_at_head(listint_t **head, listint_t *start_node,
listint_t *swap_node);

/* Selection sort*/
void selection_sort(int *array, size_t size);

/* Quicksort algorithm methods */
void quick_sort(int *array, size_t size);
void quicksort(int *array, int low, int high, size_t size);
int partition_array(int *array, int low, int high, size_t size);

#endif
