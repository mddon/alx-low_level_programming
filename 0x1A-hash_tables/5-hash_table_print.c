#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 * they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int k;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (k = 0; k < ht->size; k++)
	{
		node = ht->array[k];
		while (node != NULL)
		{
			if (comma_flag == 1)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			node = node->next;
			comma_flag = 1;
		}
	}
	printf("}\n");
}
