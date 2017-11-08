/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

int from_base(char c, t_calc *def)
{
	int i = 0;

	while (i < def->lenofbase) {
		if (def->base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char to_base(int i, t_calc *def)
{
	return (def->base[i]);
}

char *to_base_expr(int i, t_calc *def)
{
	char *dest;

	if ((dest = malloc(2)) == NULL)
		return (NULL);
	dest[0] = def->base[i];
	dest[1] = '\0';
	return (dest);
}
