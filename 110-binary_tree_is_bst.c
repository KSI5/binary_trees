#include "binary_trees.h"

int is_bst_recursive(const binary_tree_t *node,
const binary_tree_t *min, const binary_tree_t *max);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid
 *                      Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_recursive(tree, NULL, NULL));
}

/**
 * is_bst_recursive - Recursively checks if a binary tree is a valid BST.
 * @node: Current node being checked.
 * @min: Minimum value allowed for nodes in the subtree.
 * @max: Maximum value allowed for nodes in the subtree.
 *
 * Return: 1 if subtree rooted at 'node' is a valid BST, 0 otherwise.
 */
int is_bst_recursive(const binary_tree_t *node,
const binary_tree_t *min, const binary_tree_t *max)
{
	if (node == NULL)
		return (1);

	if ((min != NULL && node->n <= min->n) || (max != NULL && node->n >= max->n))
		return (0);

	return (is_bst_recursive(node->left, min, node)
	 && is_bst_recursive(node->right, node, max));
}
