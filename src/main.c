/*
** EPITECH PROJECT, 2017
** src
** File description:
**	__DESCRIPTION__
*/

#include "bistro.h"

char *stdin_expr(unsigned int maxsize)
{
	unsigned int size;
	char *expr;
	char buffer[STDIN_BUFSIZE];
	unsigned int i = 0;
	unsigned int p = 0;

	if ((expr = malloc(maxsize + 1)) == NULL)
		return (my_error(ERROR_MSG, RUNTIME_ERROR_MEMORY));
	while (p < maxsize && (size = read(0, buffer, STDIN_BUFSIZE)) > 0) {
		while (i < size && p < maxsize) {
			expr[p] = buffer[i];
			i++;
			p++;
		}
	}
	expr[p] = '\0';
	return (expr);
}

int initialize(char **av, t_calc *def)
{
	if ((def->size = my_atoi(av[3])) <= 0)
		return (my_error2(SYNTAX_ERROR_MSG, SYNTAX_ERROR_READSIZE));
	def->base = av[1];
	def->bstruct = av[2];
	def->lenofbase = my_strlen(def->base);
	if (check_params_syntax(def) != 0)
		return (1);
	if ((def->expr = stdin_expr(def->size)) == NULL)
		return (1);
	if (check_expr_syntax(def) != 0)
		return (1);
	return (0);
}

void print_usage()
{
	my_puterror("Usage: stdin > ./calc base operators size_read\n\n");
	my_puterror("Example:\n");
	my_puterror("echo \"17*(-2)\" | ./calc \"0123456789\" \"()+-*/%\" 7\n");
	exit(EXIT_SUCESS);
}

int main(int ac, char **av)
{
	char *expr;
	t_calc *def;

	if (ac != 4)
		print_usage();
	if ((def = malloc(sizeof(t_calc))) == NULL)
		return (my_error2(ERROR_MSG, RUNTIME_ERROR_MEMORY));
	if ((def->var = malloc(sizeof(t_var))) == NULL)
		return (my_error2(ERROR_MSG, RUNTIME_ERROR_MEMORY));
	if (initialize(av, def) != 0)
		return (42);
	expr = expr_to_btree_it(def, 0, def->size - 1);
	free(def->expr);
	free(def->var);
	free(def);
	my_putstr(expr);
	free(expr);
	return (0);
}
