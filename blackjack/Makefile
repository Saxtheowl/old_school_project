CC	=	cc

RM	=	rm -f

NAME	=	blackjack 

SRC	=	main.c \
		old_func/my_getnbr.c \
		old_func/my_putchar.c \
		old_func/my_putnbr.c \
		old_func/my_putstr.c \
		old_func/my_strlen.c \
		old_func/my_strdup.c \
		old_func/my_strcpy.c \
		old_func/my_strcmp.c \
		old_func/my_strcat.c \
		old_func/is_even.c \
		old_func/put_zero.c \
		old_func/xfunc.c \
		sources/read_entry.c \
		sources/random.c \
		sources/print.c \
		sources/print2.c \
		sources/result.c \
		sources/mk_cards.c \
		sources/init.c \
		sources/special.c \
		sources/split.c \
		sources/moar_card.c \
		sources/dealer.c \
		sources/blackjack.c \
		sources/calc_card.c \
		sources/ask.c \
		sources/state.c \
		sources/core.c

OBJ	=	$(SRC:.c=.o)

#CFLAGS  =	-Wall -Wextra

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re