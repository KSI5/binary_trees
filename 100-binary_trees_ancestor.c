#include "binary_trees.h"

/**
 * create_queue_node - Creates a new queue node for level-order traversal.
 * @node: The binary tree node to store in the queue node.
 *
 * Return: A pointer to the newly created queue node.
 */
levelorder_queue_t *create_queue_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees a queue used for level-order traversal.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * enqueue - Enqueues a binary tree node for level-order traversal.
 * @node: The binary tree node to enqueue.
 * @head: A pointer to the head of the queue.
 * @tail: A pointer to the tail of the queue.
 * @func: The function to apply to the node.
 */
void enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(node->n);
	if (node->left != NULL)
	{
		new_node = create_queue_node(node->left);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = create_queue_node(node->right);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * dequeue - Dequeues the front node from the queue.
 * @head: A pointer to the head of the queue.
 */
void dequeue(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder_traversal - Performs level-order
 * traversal on a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: The function to apply to each node.
 */
void binary_tree_levelorder_traversal(const binary_tree_t *tree,
void (*func)(int))
{
	levelorder_queue_t *queue_head, *queue_tail;

	if (tree == NULL || func == NULL)
		return;

	queue_head = queue_tail = create_queue_node((binary_tree_t *)tree);
	if (queue_head == NULL)
		return;

	while (queue_head != NULL)
	{
		enqueue(queue_head->node, queue_head, &queue_tail, func);
		dequeue(&queue_head);
	}

	free_queue(queue_head);
}
