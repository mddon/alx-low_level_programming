#include "hash_tables.h"

/**
 * hash_table_set - Function that adds or updates an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add (cannot be an empty string).
 * @value: The value associated with the key.
 *
 * Return: 0 when fails.
 *         Otherwise - 1.
 *
 * Description: This function adds/updates an element in the given hash table.
 *              If a matching key is found, the associated value is updated.
 *              If not, a new key-value pair is added to the hash table.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *value_copy;
	unsigned long int index, k;

	if (!ht || !key || !*key || !value)
	{
		return (0);
	}
	value_copy = strdup(value);
	if (!value_copy)
	{
		return (0);
	}
	index = key_index((const unsigned char *)key, ht->size);
	k = index;
	do {
		if (ht->array[k] && strcmp(ht->array[k]->key, key) == 0)
		{
			free(ht->array[k]->value);
			ht->array[k]->value = value_copy;
			return (1);
		}
		k = (k + 1) % ht->size;
	} while (k != index);
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(value_copy);
		return (0);
	}
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (0);
	}
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
