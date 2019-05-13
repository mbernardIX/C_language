# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 17:31:51 by mbernard          #+#    #+#              #
#    Updated: 2019/04/12 17:42:29 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = ft_lstdel.o ft_memdel.o ft_putstr_fd.o ft_striteri.o ft_strnew.o\
ft_atoi.o ft_lstdelone.o ft_memmove.o ft_strcat.o ft_strjoin.o ft_strnstr.o\
ft_bzero.o ft_lstiter.o ft_memset.o ft_strchr.o ft_strlcat.o ft_strrchr.o\
ft_isalnum.o ft_lstmap.o ft_putchar.o ft_strclr.o ft_strlen.o ft_strsplit.o\
ft_isalpha.o ft_lstnew.o ft_putchar_fd.o ft_strcmp.o ft_strmap.o ft_strstr.o\
ft_isascii.o ft_memalloc.o ft_putendl.o ft_strcpy.o ft_strmapi.o ft_strsub.o\
ft_isdigit.o ft_memccpy.o ft_putendl_fd.o ft_strdel.o ft_strncat.o ft_strtrim.o\
ft_isprint.o ft_memchr.o ft_putnbr.o ft_strdup.o ft_strncmp.o ft_tolower.o\
ft_itoa.o ft_memcmp.o ft_putnbr_fd.o ft_strequ.o ft_strncpy.o ft_toupper.o\
ft_lstadd.o ft_memcpy.o ft_putstr.o ft_striter.o ft_strnequ.o ft_is_whitespace.o\
ft_get_word_number.o ft_get_word_len.o\

INCLUDES=./

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $< -I$(INCLUDES)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
