##
## EPITECH PROJECT, 2017
## __project__
## File description:
##	__DESCRIPTION__
##

SRCS	= main.c			\
	  expr_to_btree.c	\
	  expr_to_btree2.c	\
    syntax_check1.c   \
    syntax_check2.c	\
	  syntax_check3.c   \
	  free_all.c		\
	  infin_add.c		\
	  infin.c		\
	  infin_utils.c	\
	  infin_utils2.c	\
	  infin_sub.c		\
	  infin_mul.c		\
	  infin_div.c		\
	  infin_mod.c		\
	  infin_base.c	\
	  my_atoi.c

OBJS	= $(addprefix src/, $(SRCS:.c=.o))

LIBS	= -Llib/my -lmy

PROJECT = Bistromathique

NAME	= calc

RM	= rm -f

CC	= gcc

MAKELIB	= make -C lib/my/

LIB	= lib/my/libmy.a

CFLAGS	= -W -Wall -Wextra
CFLAGS	+= -Iinclude/		\
	   -Ilib/my/include/
CFLAGS	+= $(LIBS)

LDFLAGS	=  $(LIBS)

$(PROJECT):	$(LIB) $(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIB):
	$(MAKELIB)

all:	$(PROJECT)

clean:
	$(RM) $(OBJS)
	$(MAKELIB) clean

fclean:		clean
	$(MAKELIB) fclean
	$(RM) $(NAME)

re:	fclean all
