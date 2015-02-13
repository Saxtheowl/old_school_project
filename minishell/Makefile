CC	=	cc -w

RM	=	rm -f

NAME	=	42sh


SRC=	main.c \
	sources/run_shell.c \
	sources/read_entry.c \
	sources/print_not_found.c \
	sources/exec_bin.c \
	sources/my_exit.c \
	sources/test_empty_cmds.c \
	env_func/trans_list_to_dbtab.c \
	env_func/make_env.c \
	env_func/my_setenv.c \
	env_func/my_unsetenv.c \
	env_func/exec_env_func.c \
	builtin_func/my_cd.c \
	builtin_func/my_echo.c \
	old_func/xfunc.c \
	old_func/str_to_wordtab.c \
	old_func/list_func.c \
	old_func/my_putstr.c 


OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) 

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re