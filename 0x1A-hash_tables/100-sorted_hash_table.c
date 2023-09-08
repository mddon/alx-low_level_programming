#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the new sorted hash table.
 *
 * Return: If an error occurs - NULL.
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
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *tmp_node;
	char *value_copy;
	unsigned long int index;

	if (!ht || !key || !*key || !value)
		return (0);

	value_copy = strdup(value);
	if (!value_copy)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp_node = ht->shead;

	while (tmp_node)
	{
		if (strcmp(tmp_node->key, key) == 0)
		{
			free(tmp_node->value);
			tmp_node->value = value_copy;
			return (1);
		}
		tmp_node = tmp_node->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
	{
		free(value_copy);
		return (0);
	}

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(value_copy);
		free(new_node);
		return (0);
	}

	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (!ht->shead)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		tmp_node = ht->shead;
		while (tmp_node->snext != NULL && strcmp(tmp_node->snext->key, key) < 0)
			tmp_node = tmp_node->snext;

		new_node->sprev = tmp_node;
		new_node->snext = tmp_node->snext;
		if (tmp_node->snext == NULL)
			ht->stail = new_node;
		else
			tmp_node->snext->sprev = new_node;
		tmp_node->snext = new_node;
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
