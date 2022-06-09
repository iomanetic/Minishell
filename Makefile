NAME		=	minishell

SRC			=	minishell.c \
				src/parser/lexer/lexer.c \
				src/parser/lexer/lexer_func.c \
				src/parser/lexer/utils.c \
				src/builtins/ft_pwd.c \
				src/builtins/ft_env.c \
				src/builtins/ft_echo.c \
				src/builtins/ft_export.c \
				src/builtins/ft_unset.c \
				src/builtins/ft_cd.c \
				src/builtins/ft_exit.c\
				src/builtins/redirects.c \
				src/builtins/heredoc.c \
				src/builtins/ft_search_builtins.c \
				src/signals/signals.c \
				src/init/envp_init.c \
				src/init/minishell_init.c \
				src/utils/cleaner.c \
				src/utils/ft_isspace.c \
				src/utils/ft_error.c \
				src/utils/ft_lstnew.c \
				src/utils/ft_istoken.c \
				src/utils/ft_lstadd_back.c \
				src/utils/ft_backtohead.c \
				src/utils/ft_realloc.c \
				src/utils/ft_freex2arr.c \
				src/utils/ft_split_shell.c \
				src/parser/preparser/preparser.c \
				src/parser/preparser/preparser_func.c \
				src/parser/preparser/utils.c \
				src/parser/preparser/utils_2.c \
				src/parser/parser.c \
				src/parser/parser_utils.c \
				src/executor/executor.c \
				src/executor/executor_utils.c \
				src/executor/find_path.c \
				libs/get_next_line/get_next_line.c \

OBJ			=	$(patsubst %.c,%.o,$(SRC))

HEADERS		=	includes/minishell.h \
				includes/defines.h \
				includes/structs.h \

CC			= 	gcc

CFLAGS		=  -Wall -Wextra -Werror -O2

F_READLINE	=	-lreadline -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include

LIB_PATH = libs/libft/

all: lib $(NAME)

lib		:
	make -C $(LIB_PATH) all

$(NAME): $(OBJ) libs/libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) -Llibs/libft -lft -o $@ $(F_READLINE)

%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJ)
	make -C libs/libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libs/libft fclean
