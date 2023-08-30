#include <stdlib.h>
#include "binary_trees.h"

q_node *enqueue(binary_tree_t *node, q_node **head, q_node **tail);
void free_queue(q_node *head);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * Description: This function uses an inorder traversal
 * to store the nodes in a queue,
 * then checks if the queue is sorted in ascending order.
 * Inorder traversal of a
 * binary search tree should result in sorted values in ascending order.
 * The queue is implemented using a linked list.
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	q_node *head = NULL, *tail = NULL, *current = NULL;

	if (!tree)
		return (0);

	create_queue((binary_tree_t *)tree, &head, &tail, &enqueue);

	current = head;

	while (current->next)
	{
		if (current->b_tree_node->n >= current->next->b_tree_node->n)
		{
			free_queue(head);
			return (0);
		}
		current = current->next;
	}
	free_queue(head);
	return (1);
}

/**
 * create_queue - Creates a queue of nodes using inorder traversal
 * @tree: pointer to the root node of the tree to traverse
 * @head: pointer to the head of the queue
 * @tail: pointer to the tail of the queue
 * @func: pointer to a function to call for each node
 * Return: void
 */
void create_queue(binary_tree_t *tree, q_node **head, q_node **tail,
				  q_node *(*func)(binary_tree_t *, q_node **, q_node **))
{
	if (!tree || !func)
		return;
	create_queue(tree->left, head, tail, func);
	func(tree, head, tail);
	create_queue(tree->right, head, tail, func);
}
/**
 * enqueue - adds a node to the end of a queue
 * @node: pointer to the binary tree node
 * @head: pointer to the head of the queue
 * @tail: pointer to the tail of the queue
 * Return: pointer to the new node
 */
q_node *enqueue(binary_tree_t *node, q_node **head, q_node **tail)
{
	q_node *new_node = NULL;

	if (!node || !head || !tail)
		return (NULL);
	new_node = malloc(sizeof(q_node));

	if (!new_node)
		return (NULL);

	new_node->b_tree_node = node;
	new_node->next = NULL;

	if (!*head)
		*head = new_node;
	if (*tail)
		(*tail)->next = new_node;
	*tail = new_node;
	return (new_node);
}

/**
 * free_queue - frees a queue
 * @head: pointer to the head of the queue
 * Return: void
 */
void free_queue(q_node *head)
{
	q_node *temp = NULL;

	while (head)
	{

		temp = head;
		head = head->next;
		free(temp);
	}
}
