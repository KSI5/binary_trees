#include "binary_trees.h"

/**
 * bal - Measures balance factor of an AVL tree and rebalances if needed.
 * @tree: Pointer to the root of the tree.
 * Return: Nothing.
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	bal(&(*tree)->left);
	bal(&(*tree)->right);

	bval = binary_tree_balance((const binary_tree_t *)*tree);

	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Get the minimum value in the right subtree.
 * @node: Node to start from.
 * Return: The minimum value in the subtree.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);

	left = successor(node->left);
	if (left == 0)
		return (node->n);

	return (left);
}

/**
 * remove_type - Removes a node depending on its children.
 * @root: Node to remove.
 * Return: 0 if it has no children, otherwise a value.
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}

	new_value = successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 * bst_remove - Remove a node from a BST tree.
 * @root: Root of the tree.
 * @value: Value of the node to remove.
 * Return: The new root of the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}

	return (root);
}

/**
 * avl_remove - Remove a node from an AVL tree.
 * @root: Root of the tree.
 * @value: Value of the node to remove.
 * Return: The new root of the tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);

	bal(&root_a);
	return (root_a);
}
