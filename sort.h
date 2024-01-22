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

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

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
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

/* selection sort algorithms */
void ints_swapper(int *first_int, int *second_int);
void selection_sort(int *array, size_t size);

/* quick_sort.c algorithms */
void ints_swapper(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/* shell_sort */
void shell_sort(int *array, size_t size);

/* cocktail */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void cocktail_sort_list(listint_t **list);

/* merge_sort */
void new_merge_partition(size_t low, size_t top, int *array, int *temp);
void new_merge(size_t low, size_t mid, size_t top, int *dest, int *src);
void merge_sort(int *array, size_t size);

/*radix_sort*/
int get_max_value(int *arr, int n);
void count_sort(int *arr, size_t n, int exp, int *output);
void radix_sort(int *array, size_t size);

/* quick_sort_hoare */
void quick_sort_hoare(int *array, size_t size);
void swap_elements(int *array, ssize_t item1, ssize_t item2);
int hoare_partitioner(int *array, int first, int last, int size);
void quick_sort_recursive(int *array, ssize_t first, ssize_t last, int size);

#endif /* SORT_H Prepared by Adioz Daniel & Happy Felix Chukwuma */
