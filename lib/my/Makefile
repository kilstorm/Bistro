CC	= cc

RM	= rm -f
CP	= cp

LDFLAGS	=

NAME	= libmy.a

SRC	= my_strlen.c		\
          my_putchar.c		\
          my_putstr.c		\
	  my_puterror.c

OBJ	= $(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
