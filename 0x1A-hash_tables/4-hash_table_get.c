#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value  with a key
 * @ht: hash table to look into
 * @key: key to look for
 * Return: value  with the element, or NULL if key couldn't be found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx = 0;
	hash_node_t *tmp = NULL;

	if (!ht || !key)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
