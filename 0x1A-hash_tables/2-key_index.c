#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @key: key to find
 * @size: size of the array of the hash table
 * Return: index of the key
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash = 0;

	if (!key || !size)
		return (0);

	hash = hash_djb2(key);
	return (hash % size);
}
