/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

t_btree *new_stack(t_btree *node, int i, int f, int side)
{
	t_btree *new;

	if ((new = malloc(sizeof(t_btree))) == NULL)
		return (NULL);
	if (side == 1) {
		new->first = i + 1;
		new->last = f;
	} else {
		new->first = f;
		new->last = i - 1;
	}
	new->next = NULL;
	new->side = side;
	new->i = i;
	if (node != NULL)
		node->next = new;
	new->prev = node;
	return (new);
}

t_btree_number *new_number(t_btree_number *node, char *nbr)
{
	t_btree_number *new;

	if ((new = malloc(sizeof(t_btree_number))) == NULL)
		return (NULL);
	new->nbr = nbr;
	if (node != NULL)
		node->next = new;
	new->prev = node;
	return (new);
}

char *stack_me_that(t_calc *def, t_btree **n, t_btree_number **nb, int i)
{
	t_btree *node;
	char *number;
	t_btree_number *nbr;

	node = *n;
	nbr = *nb;
	if ((node = new_stack(node, i, node->last, 1)) == NULL)
		return (NULL);
	if (i == node->prev->first) {
		if ((number = malloc(2)) == NULL)
			return (NULL);
		number[0] = def->base[0];
		number[1] = '\0';
		nbr = new_number(nbr, number);
	} else {
		if ((node = new_stack(node, i, node->prev->first, 0)) == NULL)
			return (NULL);
	}
	*n = node;
	*nb = nbr;
	return ("OK");
}

t_btree_number *let_it_go(t_btree_number *nbr)
{
	nbr = nbr->prev->prev;
	free(nbr->next->next->nbr);
	free(nbr->next->next);
	free(nbr->next->nbr);
	free(nbr->next);
	return (nbr);
}

t_btree_number	*calc_in_bt(t_btree **stk, t_btree_number **nb, t_calc *def)
{
	t_btree *node;
	t_btree *pnode;
	char *number;
	t_btree_number *nbr;

	node = *stk;
	if ((number = cpy_in_btree_number(def, node->first, node->last)) == NULL)
		return (NULL);
	if ((nbr = new_number((nbr = *nb), number)) == NULL)
		return (NULL);
	while (node->side == 1)
	{
		number = infin(nbr->prev->nbr, nbr->nbr, def->expr[node->i], def);
		if (number == NULL)
			return (free_all(nbr, node));
		if ((nbr = new_number((nbr = let_it_go(nbr)), number)) == NULL)
			return (NULL);
		if ((pnode = node->prev)->next != NULL)
			free(node);
		node = pnode;
	}
	*stk = node->prev;
	if (node != NULL)
		free(node);
	return (nbr);
}
