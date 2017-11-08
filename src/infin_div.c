/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include <bistro.h>

t_exprnb *infin_div_unit(int lv)
{
	t_exprnb *unit;

	unit = infin_create_exprnb(lv);
	unit->strlen = lv + 1;
	unit->expr[lv] = 1;
	return (unit);
}

void infin_div_calc2(t_exprnb **nb1, t_exprnb *tmp,
		     t_exprnb **result, t_calc *def)
{
	int e = 1;
	t_exprnb *prev;
	t_exprnb *r;
	t_exprnb *unit;

	unit = infin_div_unit(def->var->i);
	while (e) {
		infin_exprnb_updatelen((r = infin_sub(*nb1, tmp, def)));
		if (!r->is_neg) {
			prev = *result;
			*result = infin_add(*result, unit, def);
			infin_exprnb_free(prev);
			e = (infin_exprnb_cmp(r, tmp, def) <= 0);
			if (def->var->can_free)
				infin_exprnb_free(*nb1);
			*nb1 = r;
			def->var->can_free = 1;
		} else if (infin_exprnb_free(r))
			e = 0;
	}
	infin_exprnb_free(unit);
}

t_exprnb *infin_div_calc(t_exprnb *nb1, t_exprnb *tmp,
			 t_exprnb *result, t_calc *def)
{
	def->var->i = 0;
	def->var->can_free = 0;
	while (infin_exprnb_cmp(nb1, tmp, def) <= 0) {
		infin_exprnb_baseup(tmp);
		def->var->i = def->var->i + 1;
	}
	while ((def->var->i = def->var->i - 1) > -1) {
		infin_exprnb_basedown(tmp);
		infin_div_calc2(&nb1, tmp, &result, def);
	}
	if (def->var->can_free)
		infin_exprnb_free(nb1);
	return (result);
}

t_exprnb *infin_div(t_exprnb *nb1, t_exprnb *nb2, t_calc *def)
{
	t_exprnb *result;
	t_exprnb *tmp;
	char is_neg;

	if (infin_exprnb_is_zero(nb2))
		return (my_error(ERROR_MSG, RUNTIME_ERROR_DIVZERO));
	is_neg = (nb1->is_neg != nb2->is_neg);
	nb1->is_neg = 0;
	nb2->is_neg = 0;
	if (infin_exprnb_cmp(nb1, nb2, def) > 0) {
		if ((tmp = infin_create_exprnb(0)) == NULL)
			return (NULL);
		tmp->expr[0] = def->base[0];
		tmp->expr[1] = '\0';
		return (tmp);
	}
	result = infin_create_exprnb(nb1->strlen);
	tmp = infin_create_exprnb(nb1->strlen + 2);
	infin_exprnb_cpy(nb2, tmp);
	result = infin_div_calc(nb1, tmp, result, def);
	infin_exprnb_free(tmp);
	result->is_neg = is_neg;
	return (result);
}
