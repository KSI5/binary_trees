#include "binary_trees.h"

/**
 * is_heap - Recursive helper function to check if a binary tree is a valid
 *           Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 * @parent_value: Value of the parent node.
 * Return: 1 if the subtree is a valid Max Binary Heap, 0 otherwise.
 */
int is_heap(const binary_tree_t *tree, int parent_value)
{
	if (tree == NULL)
		return (1);

	if (tree->n > parent_value)
		return (0);

	return (is_heap(tree->left, tree->n) && is_heap(tree->right, tree->n));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_heap(tree, tree->n));
}
