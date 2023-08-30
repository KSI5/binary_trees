#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	/* Store the path from root to the first node */
	binary_tree_t *path1[1024] = {NULL};
	size_t depth1 = 0;
	binary_tree_t *curr1 = (binary_tree_t *)first;
		while (curr1 != NULL)
	{
		path1[depth1++] = curr1;
		curr1 = curr1->parent;
	}

	/* Find the common ancestor with the second node */
	binary_tree_t *curr2 = (binary_tree_t *)second;
		while (curr2 != NULL)
	{
		for (size_t i = 0; i < depth1; ++i)
		{
			if (curr2 == path1[i])
				return (curr2);
		}
		curr2 = curr2->parent;
	}

	return (NULL); /* No common ancestor found */
}
