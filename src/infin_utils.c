/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

int infin_exprnb_is_zero(t_exprnb *nb)
{
	if (nb->strlen == 1 && nb->expr[0] == 0)
		return (1);
	return (0);
}

int infin_exprnb_cmp(t_exprnb *nb1, t_exprnb *nb2, t_calc *def)
{
	int i;
	int r;

	def->base = def->base;
	if (nb1->is_neg && !nb2->is_neg)
		return (1);
	if (nb1->strlen != nb2->strlen)
		return (nb2->strlen - nb1->strlen);
	i = nb1->strlen;
	while (i > 0) {
		i--;
		r = nb2->expr[i] - nb1->expr[i];
		if (r != 0)
			return (r);
	}
	return (0);
}

void infin_swap(t_exprnb **nb1, t_exprnb **nb2)
{
	t_exprnb *swap;

	swap = *nb1;
	*nb1 = *nb2;
	*nb2 = swap;
}

int infin_max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

void infin_exprnb_cpy(t_exprnb *src, t_exprnb *dst)
{
	int i = 0;

	while (i < src->strlen) {
		dst->expr[i] = src->expr[i];
		i++;
	}
	dst->strlen = src->strlen;
}
