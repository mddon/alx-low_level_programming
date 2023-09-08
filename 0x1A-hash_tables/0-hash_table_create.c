#include "hash_tables.h"

/**
 * hash_table_create - Funcation that creates a hash table.
 * @size: Size of the array.
 *
 * Return: If an error occurs, return NULL.
 *         Otherwise - a pointer to the new hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int index;

	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
	{
		return (NULL);
	}

	new_table->size = size;
	new_table->array = malloc(sizeof(hash_node_t *) * size);

	if (new_table->array == NULL)
	{
		free(new_table); /* Clean up allocated memory on failure*/
		return (NULL);
	}

	for (index = 0; index < size; index++)
	{
		new_table->array[index] = NULL;
	}

	return (new_table);
}
