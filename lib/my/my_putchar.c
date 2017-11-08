/*
** EPITECH PROJECT, 2017
** __project__
** File description:
**	__DESCRIPTION__
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
