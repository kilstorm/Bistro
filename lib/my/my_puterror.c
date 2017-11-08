/*
** EPITECH PROJECT, 2017
** __project__
** File description:
**	__DESCRIPTION__
*/

#include <stdlib.h>
#include <unistd.h>

int	my_puterror(char *str)
{
  int	i;

  if (str == NULL)
    return (1);
  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i = i + 1;
    }
  return (0);
}
