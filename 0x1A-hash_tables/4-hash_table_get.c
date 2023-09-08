#include "hash_tables.h"

/**
 * hash_table_get - This function retrieves the value associated with
 * a key in a hash table.
 *
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched, NULL is returned.
 *         Otherwise - the value associated with the key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current_node;
	unsigned long int k;

	if (!ht || !key || !*key)
	{
		return (NULL);
	}

	k = key_index((const unsigned char *)key, ht->size);
	if (k >= ht->size)
	{
		return (NULL);
	}

	current_node = ht->array[k];
	while (current_node && strcmp(current_node->key, key) != 0)
	{
		current_node = current_node->next;
	}

	return ((current_node == NULL) ? NULL : current_node->value);
}
