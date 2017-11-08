//
// EPITECH PROJECT, 2017
// include
// File description:
//	__DESCRIPTION__
//

typedef struct	s_var
{
  int		i;
  int		j;
  int		k;
  char		can_free;
}		t_var;


typedef struct	s_calc
{
  char		*expr;
  char		*base;
  int		lenofbase;
  char		*bstruct;
  unsigned int	size;
  t_var		*var;
}		t_calc;

typedef struct	s_exprnb
{
  char		*expr;
  int		strlen;
  char		is_neg;
}		t_exprnb;

typedef struct		s_number
{
  char			*nbr;
  int			i;
  struct s_number       *next;
  struct s_number       *prev;
}			t_btree_number;

typedef struct		s_b_tree
{
  int			i;
  int			first;
  int			last;
  int			side;
  struct s_b_tree       	*next;
  struct s_b_tree       	*prev;
}			t_btree;
