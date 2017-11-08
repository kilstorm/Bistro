/*
** EPITECH PROJECT, 2017
** __project__
** File description:
**	__DESCRIPTION__
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
