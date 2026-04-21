#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer to pointer of the head
 * @idx: index where new node should be added
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp;
	unsigned int i = 0;

	/* إذا الإندكس 0 نضيف بالبداية */
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;

	/* نمشي لين نوصل للمكان قبل الإندكس */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* إذا ما وصلنا للمكان المطلوب */
	if (temp == NULL)
		return (NULL);

	/* إذا الإضافة في النهاية */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* إنشاء النود الجديد */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	/* ربط النود */
	new->next = temp->next;
	new->prev = temp;
	temp->next->prev = new;
	temp->next = new;

	return (new);
}
