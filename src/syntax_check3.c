/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

int check_expr_syntax(t_calc *def)
{
	int bracket = 0;
	unsigned int i = 0;

	while (i < def->size) {
		if ((next_check(def, i)) != 0)
			return (1);
		if ((bracket = countbracket(bracket, def, i)) < 0)
			return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BRACKET6));
		i++;
	}
	if (bracket != 0)
		return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_BRACKET7));
	return (0);
}

void	*my_error(char *type, char *msg)
{
	int i = my_strlen(msg);

	i++;
	my_puterror(type);
	return (NULL);
}

int	my_error2(char *type, char *msg)
{
	my_error(type, msg);
	return (1);
}
