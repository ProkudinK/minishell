# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 19:48:06 by wtalea            #+#    #+#              #
#    Updated: 2019/07/20 17:02:11 by wtalea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

FLAGS = -Wextra -Wall -Werror

OBJECTS  = ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o \
	ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
	ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o \
	ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
	ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
	ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o \
	ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
	ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o \
	ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
	ft_lstmap.o ft_memccpy.o ft_istab.o ft_isspace.o ft_abs.o ft_ftlstdel.o \
	ft_nullmemdel.o ft_lstpadd.o ft_lstlen.o ft_isnumber.o ft_lstsort.o \
	ft_lstswap.o ft_power.o ft_dlstnew.o ft_strcut.o ft_memtostr.o \
	ft_strswitch.o ft_strndup.o ft_memcut.o ft_lstcut.o ft_dback.o \
	ft_lstaddend.o get_next_line.o ft_intlen.o ft_itoa_nm.o ft_clmemcpy.o \
	ft_strrejoin.o ft_strdel2.o ft_memdup.o ft_memjoin.o

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
