/*
** EPITECH PROJECT, 2017
** __project__
** File description:
**	__DESCRIPTION__
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

int	my_putstr(char *str)
{
  int	i;

  if (str == NULL)
    return (1);
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
