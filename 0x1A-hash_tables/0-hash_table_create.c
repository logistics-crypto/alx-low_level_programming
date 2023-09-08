#include "hash_tables.h"

/**
 * hash_table_create - creates a new hash table
 * @size: size of the final array
 * Return: pointer to the created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table = NULL;

	if (!size)
		return (NULL);

	new_table = calloc(1, sizeof(hash_table_t));
	if (!new_table)
		return (NULL);

	new_table->size = size;
	new_table->array = calloc(size, sizeof(hash_node_t *));
	if (!new_table->array)
	{
		free(new_table);
		return (NULL);
	}
	return (new_table);
}
