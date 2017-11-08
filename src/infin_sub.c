/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include <bistro.h>

void infin_sub_char(t_exprnb *nb1, t_exprnb *nb2,
		    t_exprnb *result, t_calc *def)
{
	int n1 = 0;
	int n2 = 0;

	if (def->var->k < nb1->strlen)
		n1 = nb1->expr[def->var->k];
	if (def->var->k < nb2->strlen)
		n2 = nb2->expr[def->var->k];
	n1 = n1 - n2 - result->expr[def->var->k];
	if (n1 < 0) {
		result->expr[def->var->k + 1] = 1;
		n1 = def->lenofbase + n1;
	}
	result->expr[def->var->k] = n1 % def->lenofbase;
	result->strlen = def->var->k + 1;
}

t_exprnb *infin_sub(t_exprnb *nb1, t_exprnb *nb2, t_calc *def)
{
	t_exprnb *result;
	int len;

	if (!nb1->is_neg && nb2->is_neg && (nb2->is_neg = 0) == 0)
		return (infin_add(nb1, nb2, def));
	if (nb1->is_neg && !nb2->is_neg && (nb2->is_neg = 1) == 1)
		return (infin_add(nb1, nb2, def));
	len = infin_max(nb1->strlen, nb2->strlen);
	if ((result = infin_create_exprnb(len)) == NULL)
		return (NULL);
	if (infin_exprnb_cmp(nb1, nb2, def) > 0) {
		infin_swap(&nb1, &nb2);
		result->is_neg = 1;
	}
	def->var->k = -1;
	while ((def->var->k = def->var->k + 1) < nb1->strlen ||
	       def->var->k < nb2->strlen)
		infin_sub_char(nb1, nb2, result, def);
	if (nb1->is_neg && nb2->is_neg)
		result->is_neg = (!result->is_neg);
	return (result);
}
