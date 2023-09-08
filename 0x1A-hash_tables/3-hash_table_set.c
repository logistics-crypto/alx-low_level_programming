#include "hash_tables.h"

/**
 * hash_table_set - adds an element
 * @ht: hash table to add or update the key/value to
 * @key: key to add
 * @value: value associated with the key
 * Return: 1 if success, 0 if failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx = 0, size = 0;
	hash_node_t *new_n = NULL;

	if (!ht || !key || !value)
		return (0);

	size = ht->size;
	idx = key_index((const unsigned char *)key, size);

	if (ht->array[idx] && strcmp(ht->array[idx]->key, key) == 0)
	{
		free(ht->array[idx]->value);
		ht->array[idx]->value = strdup(value);
		return (1);
	}
	new_n = malloc(sizeof(hash_node_t));
	if (!new_n)
		return (0);

	new_n->key = strdup(key);
	new_n->value = strdup(value);
	new_n->next = ht->array[idx];
	ht->array[idx] = new_n;
	return (1);
}
