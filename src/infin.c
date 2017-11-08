/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

t_exprnb *infin_create_exprnb(int expr_len)
{
	t_exprnb *exprnb;

	if ((exprnb = malloc(sizeof(t_exprnb))) == NULL)
		return (my_error(ERROR_MSG, RUNTIME_ERROR_MEMORY));
	if ((exprnb->expr = malloc(expr_len + 2)) == NULL)
		return (my_error(ERROR_MSG, RUNTIME_ERROR_MEMORY));
	infin_reset_exprnb(exprnb, expr_len);
	return (exprnb);
}

void infin_reset_exprnb(t_exprnb *exprnb, int len)
{
	int i = 0;

	while (i < len + 1) {
		exprnb->expr[i] = 0;
		i++;
	}
	exprnb->strlen = 0;
	exprnb->is_neg = 0;
}

t_exprnb *infin_expr_to_exprnb(char *expr, t_calc *def)
{
	t_exprnb *exprnb;
	int len;
	int i;
	int p = 0;

	len = my_strlen(expr);
	i = len;
	if ((exprnb = infin_create_exprnb(len)) == NULL)
		return (NULL);
	while (i > 0) {
		i = i - 1;
		if (expr[i] == def->bstruct[OP_SUB_IDX])
			exprnb->is_neg = 1;
		else {
			exprnb->expr[p] = from_base(expr[i], def);
			p++;
		}
	}
	exprnb->expr[p] = '\0';
	exprnb->strlen = p;
	return (exprnb);
}

char *infin_exprnb_to_expr(t_exprnb *exprnb, t_calc *def)
{
	char *expr;
	int i;
	int p;

	if (exprnb == NULL)
		return (NULL);
	if (exprnb->is_neg && infin_exprnb_is_zero2(exprnb))
		exprnb->is_neg = 0;
	if ((expr = malloc(exprnb->strlen + exprnb->is_neg + 2)) == NULL)
		return (my_error(ERROR_MSG, RUNTIME_ERROR_MEMORY));
	if (exprnb->is_neg)
		expr[0] = def->bstruct[OP_SUB_IDX];
	i = exprnb->strlen;
	p = 0;
	while ((i = i - 1) >= 0) {
		if (p || exprnb->expr[i] != 0)
			expr[((p = p + 1) - 1) + exprnb->is_neg] = to_base(exprnb->expr[i], def);
	}
	if (p == 0 && (expr[p + exprnb->is_neg] = def->base[0]) == def->base[0])
		p = p + 1;
	expr[p + exprnb->is_neg] = '\0';
	return (expr);
}

char *infin(char *n1, char *n2, char op, t_calc *def)
{
	char		*expr;
	t_exprnb	*res;
	t_exprnb       *nb1;
	t_exprnb       *nb2;

	if ((nb1 = infin_expr_to_exprnb(n1, def)) == NULL ||
	    (nb2 = infin_expr_to_exprnb(n2, def)) == NULL)
		return (NULL);
	res = NULL;
	if (op == def->bstruct[OP_PLUS_IDX])
		res = infin_add(nb1, nb2, def);
	else if (op == def->bstruct[OP_SUB_IDX])
		res = infin_sub(nb1, nb2, def);
	else if (op == def->bstruct[OP_MULT_IDX])
		res = infin_mul(nb1, nb2, def);
	else if (op == def->bstruct[OP_DIV_IDX])
		res = infin_div(nb1, nb2, def);
	else if (op == def->bstruct[OP_MOD_IDX])
		res = infin_mod(nb1, nb2, def);
	expr = infin_exprnb_to_expr(res, def);
	if (res != NULL && res != nb1)
		infin_exprnb_free(res);
	infin_exprnb_free(nb1);
	infin_exprnb_free(nb2);
	return (expr);
}
