#include "hash_tables.h"

/**
 * hash_djb2 - hash function for the djb2 algorithm
 * @str: string to hash
 * Return: hash value
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int i;

	if (!str)
		return (0);

	while ((i = *str++))
		hash = ((hash << 5) + hash) + i; /* hash * 33 + c */

	return (hash);
}
