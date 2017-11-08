//
// EPITECH PROJECT, 2017
// include
// File description:
//	__DESCRIPTION__
//

#ifndef BISTRO_H_
# define BISTRO_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "bistruct.h"

#define STDIN_BUFSIZE 8192
#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6
#define EXIT_SUCESS 0

void my_putchar(char c);
int my_puterror(char *expr);
int my_putstr(char *expr);
int my_strlen(char *expr);
void		*free_all(t_btree_number *, t_btree*);
char		*stack_me_that(t_calc *, t_btree **, t_btree_number **, int);
int		skip_parent(t_calc *, int);
void		find_first_last(int *, int *, t_calc *, t_btree *);
char		*cpy_in_btree_number(t_calc *def, int, int);
t_btree_number       	*calc_in_bt(t_btree **, t_btree_number **, t_calc *);
t_btree		*new_stack(t_btree *, int , int, int);
t_btree_number	*new_number(t_btree_number *, char *);
char		*expr_to_btree_it(t_calc *, int, int);
int		is_valid_bstruct_or_base(t_calc *def, int i);
int		countbracket(int bracket, t_calc *def, int i);
int		check_bracket(t_calc *def, int i);
int		check_operator(t_calc *def, int i);
int		check_number(t_calc *def, int i);
int		check_twobase(t_calc *def);
int		check_char_rep(char *expr, char type);
int		next_check(t_calc *def, int i);
int		check_params_syntax(t_calc *def);
int		check_expr_syntax(t_calc *def);
char		*infin(char *n1, char *n2, char op, t_calc *def);
char		*epur_expr(char *expr, int, char *);


t_exprnb	*infin_create_exprnb(int expr_len);
void    infin_reset_exprnb(t_exprnb *exprnb, int len);
t_exprnb	*infin_expr_to_exprnb(char *expr, t_calc *def);
char	*infin_exprnb_to_expr(t_exprnb *exprnb, t_calc *def);

int     infin_exprnb_is_zero(t_exprnb *nb);
int     infin_exprnb_cmp(t_exprnb *nb1, t_exprnb *nb2, t_calc *def);
void	infin_swap(t_exprnb **nb1, t_exprnb **nb2);
int     infin_max(int a, int b);
void    infin_exprnb_cpy(t_exprnb *src, t_exprnb *dst);

void    infin_exprnb_baseup(t_exprnb *nb);
void    infin_exprnb_basedown(t_exprnb *nb);
void	infin_exprnb_updatelen(t_exprnb *nb);
int     infin_exprnb_is_zero2(t_exprnb *nb);

char *infin(char *n1, char *n2, char op, t_calc *def);
t_exprnb	*infin_add(t_exprnb *nb1, t_exprnb *nb2, t_calc *def);
t_exprnb	*infin_sub(t_exprnb *nb1, t_exprnb *nb2, t_calc *def);
t_exprnb *infin_mul(t_exprnb *nb1, t_exprnb *nb2, t_calc *def);
t_exprnb *infin_div(t_exprnb *nb1, t_exprnb *nb2, t_calc *def);
t_exprnb *infin_mod(t_exprnb *nb1, t_exprnb *nb2, t_calc *def);

int from_base(char c, t_calc *def);
char to_base(int i, t_calc *def);
char *to_base_expr(int i, t_calc *def);
int infin_exprnb_free(t_exprnb *nb);


#define SYNTAX_ERROR_MSG		"syntax error"
#define SYNTAX_ERROR_READSIZE		"size_read must be a exprictly positive integer"
# define SYNTAX_ERROR_READSIZE_LONG	"Invalid size_read (too long) or new\
 line in expression"
# define SYNTAX_ERROR_BASELEN		"The base must contain at least 2\
 characters"
# define SYNTAX_ERROR_OPLEN		"The operators must contain 7\
 characters"
# define SYNTAX_ERROR_BASE_REP		"Same character is present twice in\
 the base"
# define SYNTAX_ERROR_OP_REP		"Same character is present twice in\
 the operators"
# define SYNTAX_ERROR_BASEOP_REP	"Same character is present in base\
 and operators"
# define SYNTAX_ERROR_INVALID_CHAR	"Unknown character in expression"
# define SYNTAX_ERROR_BRACKET1		"Close bracket after an open bracket"
# define SYNTAX_ERROR_BRACKET2		"Operator after an open bracket"
# define SYNTAX_ERROR_BRACKET3		"No operator after a close bracket"
# define SYNTAX_ERROR_BRACKET4		"Open bracket after a close bracket"
# define SYNTAX_ERROR_BRACKET5		"Open bracket after a number"
# define SYNTAX_ERROR_BRACKET6		"Invalid close bracket"
# define SYNTAX_ERROR_BRACKET7		"Bad number of bracket"
# define SYNTAX_ERROR_OP1		"Bad operators order"
# define SYNTAX_ERROR_OP2		"Close bracket after an operator"
# define SYNTAX_ERROR_OP3		"Operator at end of expression"
# define SYNTAX_ERROR_OP4		"Bad operator just after another\
 operator"
# define SYNTAX_ERROR_OP5		"Bad operator at start or end"

# define ERROR_MSG		"error"
#define RUNTIME_ERROR_MEMORY		"Out of memory"
#define RUNTIME_ERROR_DIVZERO		"Division by zero"
#define RUNTIME_ERROR_MODZERO		"Modulo by zero"

void	*my_error(char *type, char *msg);
int	my_error2(char *type, char *msg);

unsigned int my_atoi(char *expr);


#endif /* !BISTRO_H_ */
