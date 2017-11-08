/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

int is_valid_bstruct_or_base(t_calc *def, int i)
{
	char a = def->expr[i];

	i = 0;
	while (def->base[i] != '\0') {
		if (def->base[i] == a)
			return (0);
		i++;
	}
	i = 0;
	while (def->bstruct[i] != '\0') {
		if (def->bstruct[i] == a)
			return (0);
		i++;
	}
	if (a == '\n')
		return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_READSIZE_LONG));
	return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_INVALID_CHAR));
}

int countbracket(int bracket, t_calc *def, int i)
{
	if (def->expr[i] == def->bstruct[OP_OPEN_PARENT_IDX])
		bracket = bracket + 1;
	if (def->expr[i] == def->bstruct[OP_CLOSE_PARENT_IDX])
		bracket = bracket - 1;
	return (bracket);
}

int check_bracket(t_calc *def, int i)
{
	if (def->expr[i] == def->bstruct[OP_OPEN_PARENT_IDX]) {
		if (def->expr[i + 1] == def->bstruct[OP_CLOSE_PARENT_IDX])
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BRACKET1));
		if (def->expr[i + 1] == def->bstruct[OP_MULT_IDX] ||
		    def->expr[i + 1] == def->bstruct[OP_DIV_IDX] ||
		    def->expr[i + 1] == def->bstruct[OP_MOD_IDX])
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BRACKET2));
	}
	if (def->expr[i] == def->bstruct[OP_CLOSE_PARENT_IDX]) {
		if (def->expr[i + 1] != def->bstruct[OP_PLUS_IDX] &&
		    def->expr[i + 1] != def->bstruct[OP_SUB_IDX] &&
		    def->expr[i + 1] != def->bstruct[OP_MULT_IDX] &&
		    def->expr[i + 1] != def->bstruct[OP_DIV_IDX] &&
		    def->expr[i + 1] != def->bstruct[OP_MOD_IDX] &&
		    def->expr[i + 1] != def->bstruct[OP_CLOSE_PARENT_IDX] &&
		    def->expr[i + 1] != '\0')
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BRACKET3));
		if (def->expr[i + 1] == def->bstruct[OP_OPEN_PARENT_IDX])
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BRACKET4));
	}
	return (0);
}

int extend_check_op(t_calc *def, int i)
{
	if (def->expr[i] == def->bstruct[OP_PLUS_IDX] ||
	    def->expr[i] == def->bstruct[OP_SUB_IDX]) {
		if (def->expr[i + 1] == def->bstruct[OP_MULT_IDX] ||
		    def->expr[i + 1] == def->bstruct[OP_DIV_IDX] ||
		    def->expr[i + 1] == def->bstruct[OP_MOD_IDX])
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_OP1));
		if (def->expr[i + 1] == def->bstruct[OP_CLOSE_PARENT_IDX])
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_OP2));
		if (def->expr[i + 1] == '\0')
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_OP3));
	}
	return (0);
}

int check_operator(t_calc *def, int i)
{
	if (extend_check_op(def, i) != 0)
		return (1);
	if (def->expr[i] == def->bstruct[OP_MULT_IDX] ||
	    def->expr[i] == def->bstruct[OP_DIV_IDX] ||
	    def->expr[i] == def->bstruct[OP_MOD_IDX]) {
		if (def->expr[i + 1] == def->bstruct[OP_CLOSE_PARENT_IDX])
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_OP1));
		if (def->expr[i + 1] == def->bstruct[OP_MULT_IDX] ||
		    def->expr[i + 1] == def->bstruct[OP_DIV_IDX] ||
		    def->expr[i + 1] == def->bstruct[OP_MOD_IDX])
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_OP4));
		if (def->expr[i + 1] == '\0' || i == 0)
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_OP5));
	}
	return (0);
}
