#include "hash_tables.h"

/**
 * key_index - Computes the index where a key/value pair should be stored
 *             in the array of a hash table.
 * @key: The key for which the index is calculated.
 * @size: The size of the array in the hash table.
 *
 * Return: The index at which the key/value pair should be stored.
 *
 * Description: This function uses the djb2 algorithm to calculate the index
 *              where a key/value pair should be placed.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
