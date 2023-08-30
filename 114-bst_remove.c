#include <stdlib.h>
#include "binary_trees.h"

bst_t *inorder_successor(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 *
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: Value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the desired
 * value, or NULL if value doesn't exist.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL, *successor = NULL;

	if (!root)
		return (NULL);
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		successor = inorder_successor(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}

/**
 * inorder_successor - Finds the inorder successor of a node.
 *
 * @node: Pointer to the node to find the successor of.
 *
 * Return: Pointer to the inorder successor node of the given node.
 */
bst_t *inorder_successor(bst_t *node)
{
	bst_t *current = node;

	while (current->left)
		current = current->left;
	return (current);
}
