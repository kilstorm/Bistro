/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

void infin_mul_char(t_exprnb *nb1, t_exprnb *nb2, t_exprnb *result,
		    t_calc *def)
{
	int r = result->expr[def->var->i + def->var->j];

	r = r  + (int)nb1->expr[def->var->j] * (int)nb2->expr[def->var->i];
	if (r >= def->lenofbase) {
		result->expr[def->var->i + def->var->j + 1] = r / def->lenofbase;
		result->strlen = def->var->i + def->var->j + 2;
	}
	result->expr[def->var->i + def->var->j] = r % def->lenofbase;
	if (result->strlen < def->var->i + def->var->j + 1)
		result->strlen = def->var->i + def->var->j + 1;
}

char infin_mul_negcheck(t_exprnb *nb1, t_exprnb *nb2)
{
	char	neg;

	neg = (nb1->is_neg != nb2->is_neg);
	nb2->is_neg = 0;
	nb1->is_neg = 0;
	return (neg);
}

t_exprnb *infin_mul2(t_exprnb *result, t_exprnb *tmp, int len,
		     t_calc *def)
{
	t_exprnb *nresult;

	nresult = infin_add(result, tmp, def);
	infin_exprnb_free(result);
	infin_reset_exprnb(tmp, len);
	return (nresult);
}

t_exprnb *infin_mul(t_exprnb *nb1, t_exprnb *nb2, t_calc *def)
{
	t_exprnb *result;
	t_exprnb *tmp;
	char is_neg = is_neg = infin_mul_negcheck(nb1, nb2);
	int len;

	tmp = infin_create_exprnb((len = nb1->strlen + nb2->strlen + 1));
	if ((result = infin_create_exprnb(len)) == NULL || tmp == NULL)
		return (NULL);
	if (infin_exprnb_cmp(nb1, nb2, def) > 0)
		infin_swap(&nb1, &nb2);
	def->var->i = -1;
	while ((def->var->i = def->var->i + 1) < nb2->strlen) {
		def->var->j = -1;
		while ((def->var->j = def->var->j + 1) < nb1->strlen)
			infin_mul_char(nb1, nb2, tmp, def);
		result = infin_mul2(result, tmp, len, def);
	}
	result->is_neg = is_neg;
	infin_exprnb_free(tmp);
	return (result);
}
