/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

void infin_add_char(t_exprnb *nb1, t_exprnb *nb2, t_exprnb *result,
		    t_calc *def)
{
	int n1 = 0;
	int n2 = 0;

	if (def->var->k < nb1->strlen)
		n1 = nb1->expr[def->var->k];
	if (def->var->k < nb2->strlen)
		n2 = nb2->expr[def->var->k];
	n1 = result->expr[def->var->k] + n1 + n2;
	if (n1 >= def->lenofbase) {
		result->expr[def->var->k + 1] = n1 / def->lenofbase;
		result->strlen = def->var->k + 2;
	}
	result->expr[def->var->k] = n1 % def->lenofbase;
	if (result->strlen < def->var->k + 1)
		result->strlen = def->var->k + 1;
}

t_exprnb *infin_add(t_exprnb *nb1, t_exprnb *nb2, t_calc *def)
{
	t_exprnb *result;
	int len;

	if (nb1->is_neg && !nb2->is_neg && !(nb1->is_neg = 0))
		return (infin_sub(nb2, nb1, def));
	else if (nb2->is_neg && !nb1->is_neg && !(nb2->is_neg = 0))
		return (infin_sub(nb1, nb2, def));
	len = infin_max(nb1->strlen, nb2->strlen);
	result = infin_create_exprnb(len);
	if (result == NULL)
		return (NULL);
	def->var->k = 0;
	while (def->var->k < nb1->strlen || def->var->k < nb2->strlen)
	{
		infin_add_char(nb1, nb2, result, def);
		def->var->k = def->var->k + 1;
	}
	if (nb1->is_neg && nb2->is_neg)
		result->is_neg = 1;
	return (result);
}
