#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to pointer of the head
 * @n: integer to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	/* إذا القائمة فاضية */
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	/* نروح لآخر نود */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}
