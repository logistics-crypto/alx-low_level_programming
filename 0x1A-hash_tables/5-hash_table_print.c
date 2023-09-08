#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table to print
 * Return: void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp = NULL;
	unsigned long int i = 0, flag = 0;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			flag = 1;
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
