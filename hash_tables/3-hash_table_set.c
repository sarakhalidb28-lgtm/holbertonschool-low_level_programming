#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * update_value - updates value if key exists
 * @node: current node
 * @key: key to search
 * @value: new value
 *
 * Return: 1 if updated, 0 if not found, -1 if failed
 */
int update_value(hash_node_t *node, const char *key, const char *value)
{
	char *value_copy;

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (-1);
			free(node->value);
			node->value = value_copy;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;
	int updated;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	updated = update_value(ht->array[index], key, value);
	if (updated == 1)
		return (1);
	if (updated == -1)
		return (0);

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
