#ifndef HASH_TABLES_H
#define HASH_TABLES_H

/**
 * struct hash_node_s - node of a hash table
 * @key: key, string
 * @value: value associated with the key
 * @next: pointer to the next node
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - hash table data structure
 * @size: size of the array
 * @array: array of size @size
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);

#endif /* HASH_TABLES_H */
