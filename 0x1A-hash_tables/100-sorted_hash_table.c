#include "hash_tables.h"

/**
 * shash_table_create - Function that creates a sorted hash table.
 * @size: The size of the new sorted hash table.
 *
 * Return: If an error occurs return NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int k;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!ht->array)
		return (NULL);

	k = 0;
	while (k < size)
	{
		ht->array[k] = NULL;
		k++;
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Function that adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: Value associated with key.
 *
 * Return: If failure return 0.
 *         Otherwise return 1.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	/* Variables */
	shash_node_t *new, *node;
	char *value_copy;
	unsigned long int index;

	/* Check for NULL parameters and empty key */
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	/* Copy the value */
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	/* Calculate the index for the key */
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->shead;

	/* Check if the key already exists */
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = value_copy;
			free(value_copy);
			return (1);
		}
		node = node->snext;
	}

	/* Allocate memory for the new node */
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}

	/* Copy the key and assign values */
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	/* Insert the new node into the sorted linked list */
	if (ht->shead == NULL || strcmp(ht->shead->key, key) >= 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		node = ht->shead;
		while (node->snext != NULL && strcmp(node->snext->key, key) < 0)
			node = node->snext;
		new->sprev = node;
		new->snext = node->snext;
		if (node->snext == NULL)
			ht->stail = new;
		else
			node->snext->sprev = new;
		node->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current_node;
	unsigned long int index;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	current_node = ht->shead;
	while (current_node && strcmp(current_node->key, key) != 0)
		current_node = current_node->snext;

	return ((current_node == NULL) ? NULL : current_node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (!ht)
		return;

	current_node = ht->shead;
	printf("{");
	while (current_node)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->snext;
		if (current_node)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (!ht)
		return;

	current_node = ht->stail;
	printf("{");
	while (current_node)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->sprev;
		if (current_node)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *current_node, *temp_node;

	if (ht == NULL)
		return;

	current_node = ht->shead;
	while (current_node)
	{
		temp_node = current_node->snext;
		free(current_node->key);
		free(current_node->value);
		free(current_node);
		current_node = temp_node;
	}

	free(head->array);
	free(head);
}
