#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current_node;
	unsigned long int k;
	unsigned char comma_flag = 0;

	if (ht == NULL)
	{
		return;
	}

	printf("{");
	k = 0;
	while (k < ht->size)
	{
		if (ht->array[k] != NULL)
		{
			if (comma_flag == 1)
				printf(",");
	
			current_node = ht->array[k];
			while (current_node != NULL)
			{
				printf("'%s': '%s'", current_node->key, current_node->value);
				current_node = current_node->next;
				if (current_node != NULL)
					printf(",");
			}
			comma_flag = 1;
		}
		k++;
	}
	printf("}\n");
}
