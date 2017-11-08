/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

void *free_all(t_btree_number *nbr, t_btree *node)
{
	t_btree_number *pnbr;
	t_btree *pnode;

	while (nbr != NULL) {
		pnbr = nbr->prev;
		if (nbr->nbr != NULL)
			free(nbr->nbr);
		free(nbr);
		nbr = pnbr;
	}
	while (node != NULL) {
		pnode = node->prev;
		free(node);
		node = pnode;
	}
	return (NULL);
}
