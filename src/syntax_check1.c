/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

int check_number(t_calc *def, int i)
{
	int n = 0;

	while (def->base[n] != def->expr[i] && def->base[n] != '\0')
		n++;
	if (def->base[n] == '\0')
		return (0);
	if (def->expr[i + 1] == def->bstruct[OP_OPEN_PARENT_IDX])
		return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BRACKET5));
	return (0);
}

int check_twobase(t_calc *def)
{
	int first = 0;
	int second = 0;

	if (my_strlen(def->bstruct) != 7)
		return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_OPLEN));
	while (def->base[first] != '\0') {
		second = 0;
		while (def->bstruct[second] != '\0') {
			if (def->base[first] == def->bstruct[second])
				return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BASEOP_REP));
			second++;
		}
		first++;
	}
	return (0);
}

int check_char_rep(char *str, char type)
{
	int n = 0;
	int i = 0;

	while (str[i] != '\0') {
		n = 0;
		while (str[n] != '\0') {
			if (n != i && str[n] == str[i]) {
				if (type == 0)
					return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BASE_REP));
				else
					return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_OP_REP));
			}
			n ++;
		}
		i++;
	}
	return (0);
}

int next_check(t_calc *def, int i)
{
	if (is_valid_bstruct_or_base(def, i) != 0)
		return (1);
	if ((def->expr[i] == def->bstruct[OP_OPEN_PARENT_IDX] ||
	     def->expr[i] == def->bstruct[OP_CLOSE_PARENT_IDX]) &&
	    check_bracket(def, i) != 0)
		return (1);
	if (check_operator(def, i) != 0)
		return (1);
	if (check_number(def, i) != 0)
		return (1);
	return (0);
}

int check_params_syntax(t_calc *def)
{
	if (my_strlen(def->base) < 2)
		return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BASELEN));
	if (check_char_rep(def->base, 0) != 0)
		return (1);
	if ((check_char_rep(def->bstruct, 1)) != 0)
		return (1);
	if ((check_twobase(def)) != 0)
		return (1);
	return (0);
}
