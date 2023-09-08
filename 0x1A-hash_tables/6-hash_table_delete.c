#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to delete
 * Return: void
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp = NULL, *tmp2 = NULL;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			tmp2 = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = tmp2;
		}
	}
	free(ht->array);
	free(ht);
}
