/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

void infin_exprnb_baseup(t_exprnb *nb)
{
	int i = nb->strlen;;

	while (i > 0) {
		i--;
		nb->expr[i + 1] = nb->expr[i];
	}
	nb->expr[0] = 0;
	nb->strlen = nb->strlen + 1;
}

void infin_exprnb_basedown(t_exprnb *nb)
{
	int i = 0;

	nb->strlen = nb->strlen - 1;
	while (i < nb->strlen) {
		nb->expr[i] = nb->expr[i + 1];
		i++;
	}
	nb->expr[i] = 0;
}

void infin_exprnb_updatelen(t_exprnb *nb)
{
	while (nb->strlen > 1 && nb->expr[nb->strlen - 1] == 0) {
		nb->strlen = nb->strlen - 1;
	}
}

int infin_exprnb_is_zero2(t_exprnb *nb)
{
	int i = nb->strlen;

	while (i > 0) {
		i--;
		if (nb->expr[i] != 0)
			return (0);
	}
	return (1);
}

int infin_exprnb_free(t_exprnb *nb)
{
	if (nb != NULL) {
		if (nb->expr != NULL)
			free(nb->expr);
		free(nb);
	}
	return (1);
}
