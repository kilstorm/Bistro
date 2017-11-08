/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

t_exprnb *infin_mod(t_exprnb *nb1, t_exprnb *nb2, t_calc *def)
{
	t_exprnb *res1;
	t_exprnb *res2;
	char is_neg;

	if (infin_exprnb_is_zero(nb2))
		return (my_error(ERROR_MSG, RUNTIME_ERROR_MODZERO));
	if (nb1->is_neg == 1)
		is_neg = 1;
	else
		is_neg = 0;
	nb1->is_neg = 0;
	nb2->is_neg = 0;
	if (infin_exprnb_cmp(nb1, nb2, def) > 0) {
		nb1->is_neg = is_neg;
		return (nb1);
	}
	res1 = infin_div(nb1, nb2, def);
	res2 = infin_mul(nb2, res1, def);
	infin_exprnb_free(res1);
	res1 = infin_sub(nb1, res2, def);
	infin_exprnb_free(res2);
	res1->is_neg = is_neg;
	return (res1);
}
