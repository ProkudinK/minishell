# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 19:48:06 by wtalea            #+#    #+#              #
#    Updated: 2019/07/25 14:51:03 by wtalea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean re all


SRCS=$(addprefix $(SRCS_DIR), $(SOURCES))
OBJS=$(addprefix $(OBJS_DIR), $(SOURCES:.c=.o))
FLAGS=-Wextra -Wall -Werror
COMP=gcc
NAME=minishell
SRCS_DIR=./srcs/
OBJS_DIR=./obj/
LIBFT_DIR=libft
LIBS=libft/libft.a
HEADER=includes/minishell.h
SANIT=#-fsanitize=address
FLAGG=#-g
INCLUDES=-Iincludes -I libft
SOURCES=lexer_lib.c minishell.c nonint.c replace_dol.c sh_arrows.c sh_ch.c \
		sh_lib.c sh_parse.c sh_search_env.c sh_search_programm.c \
		start_lexer.c start_programm.c tilda_repl.c env_add.c env_del.c \
		start_cd.c start_echo.c start_env.c start_exit.c start_unsetenv.c \
		start_setenv.c signal.c quotes.c init_env.c dellib.c sh_lib_input.c \
		sh_print_escape.c getch_sh.c readline_write.c readline_lr.c auto.c \
		add_dot.c

all: $(NAME)

$(NAME): $(LIBS) $(OBJS_DIR) $(OBJS)
	$(COMP) $(LIBS) $(FLSGS) $(FLAGG) $(OBJS) -o $(NAME) $(INCLUDES) $(SANIT)

$(OBJS_DIR):
	mkdir obj

$(LIBS):
	make -C $(LIBFT_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	$(COMP) $(FLAGS) $(FLAGG) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -rf ./obj

fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)

re: fclean all
