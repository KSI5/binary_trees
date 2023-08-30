#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: the generated array
 *         NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	if (!heap || !size)
		return (NULL);

	size_t heap_size = binary_tree_size(heap);
	int *sorted_array = malloc(heap_size * sizeof(int));

	if (!sorted_array)
		return (NULL);

	for (size_t i = 0; i < heap_size; ++i)
	{
		sorted_array[i] = heap->n;
		heap_extract(&heap);
	}

	*size = heap_size;
	return (sorted_array);
}
