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

/* Print helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0
 * @true: Equals 1
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/* Sorting Algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

/* selection sort algorithms */
void ints_swapper(int *first_int, int *second_int);

/* quick_sort.c algorithms */
void ints_swapper(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

#endif /* SORT_H Prepared by Adioz Daniel & Happy Felix Chukwuma */
