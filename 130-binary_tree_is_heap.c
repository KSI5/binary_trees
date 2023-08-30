#include "binary_trees.h"

/**
 * is_valid_max_heap - Helper function to check if a binary tree is a valid
 *                     Max Binary Heap.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @index: Index of the current node.
 * @max_index: Max index of the tree.
 * @max_value: Max value of the tree.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int is_valid_max_heap(const binary_tree_t *tree, int index,
int max_index, int max_value)
{
	if (!tree)
		return (1);

	if (index > max_index || tree->n > max_value)
		return (0);

	return (is_valid_max_heap(tree->left, 2 * index + 1, max_index, tree->n) &&
			is_valid_max_heap(tree->right, 2 * index + 2, max_index, tree->n));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int nodes;

	if (!tree)
		return (0);

	nodes = binary_tree_total_nodes(tree);
	return (is_valid_max_heap(tree, 0, nodes - 1, tree->n));
}

/**
 * binary_tree_total_nodes - Counts the total number of nodes in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count nodes.
 *
 * Return: The total number of nodes in the tree.
 */
int binary_tree_total_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_total_nodes(tree->left) +
			binary_tree_total_nodes(tree->right));
}
