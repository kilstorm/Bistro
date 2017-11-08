/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

int skip_parent(t_calc *def, int i)
{
	int nbparent = 1;

	i--;
	while (nbparent != 0) {
		if (def->expr[i] == def->bstruct[OP_CLOSE_PARENT_IDX])
			nbparent = nbparent + 1;
		if (def->expr[i] == def->bstruct[OP_OPEN_PARENT_IDX])
			nbparent = nbparent - 1;
		i--;
	}
	return (i);
}

int find_the_operator(t_calc *def, int first, int last)
{
	int firstop = -1;
	int i = last + 1;

	while ((i = i - 1) >= first) {
		if (def->expr[i] == def->bstruct[OP_CLOSE_PARENT_IDX])
			i = skip_parent(def, i);
		if (i < first)
			return (firstop);
		if ((def->expr[i] == def->bstruct[OP_SUB_IDX] ||
		     def->expr[i] == def->bstruct[OP_PLUS_IDX]) &&
		    (i - 1 < first || ((def->expr[i - 1] != def->bstruct[OP_PLUS_IDX] &&
					def->expr[i - 1] != def->bstruct[OP_SUB_IDX] &&
					def->expr[i - 1] != def->bstruct[OP_MULT_IDX] &&
					def->expr[i - 1] != def->bstruct[OP_DIV_IDX] &&
					def->expr[i - 1] != def->bstruct[OP_MOD_IDX]))))
			return (i);
		if (firstop == -1 && (def->expr[i] == def->bstruct[OP_MULT_IDX] ||
				      def->expr[i] == def->bstruct[OP_DIV_IDX] ||
				      def->expr[i] == def->bstruct[OP_MOD_IDX]))
			firstop = i;
	}
	return (firstop);
}

char *cpy_in_btree_number(t_calc *def, int first, int last)
{
	char *number;
	int nb = 0;

	while (def->expr[first] == def->bstruct[0]) {
		first++;
		last--;
	}
	while (def->expr[first] == def->base[0] && first < last)
		first = first + 1;
	if ((number = malloc(last - first + 2)) == NULL)
		return (NULL);
	while (first + nb < last + 1) {
		number[nb] = def->expr[first + nb];
		nb++;
	}
	number[nb] = '\0';
	return (number);
}

void find_first_last(int *f, int *l, t_calc *def, t_btree *node)
{
	int first;
	int last;

	first = node->first;
	last = node->last;
	while (def->expr[last] == def->bstruct[OP_CLOSE_PARENT_IDX] &&
	       skip_parent(def, last) == first - 1) {
		first = first + 1;
		last = last - 1;
	}
	node->first = first;
	node->last = last;
	*f = first;
	*l = last;
}

char *expr_to_btree_it(t_calc *def, int first, int last)
{
	t_btree *node;
	t_btree_number *nbr;
	char *number;
	int i;

	if ((node = new_stack(NULL, 0, first, 0)) == NULL)
		return (NULL);
	node->last = last;
	if ((nbr = new_number(NULL, NULL)) == NULL)
		return (NULL);
	while (node != NULL) {
		find_first_last(&first, &last, def, node);
		if ((i = find_the_operator(def, first, last)) == -1)
			nbr = calc_in_bt(&node, &nbr, def);
		else
			number = stack_me_that(def, &node, &nbr, i);
		if (nbr == NULL || number == NULL)
			return (NULL);
	}
	number = nbr->nbr;
	free(nbr->prev);
	free(nbr);
	return (number);
}
