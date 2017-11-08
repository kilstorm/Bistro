/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

unsigned int my_atoi(char *expr)
{
	int i = my_strlen(expr);
	int pow = 1;
	unsigned int pnb;
	unsigned int nb = 0;
  
	if (i > 10)
		return (0);
	while (i > 0) {
		i--;
		if (expr[i] < '0' || expr[i] > '9')
			return (0);
		pnb = nb;
		nb = nb + (expr[i] - '0') * pow;
		pow = pow * 10;
		if (nb < pnb)
			return (0);
	}
	return (nb);
}
