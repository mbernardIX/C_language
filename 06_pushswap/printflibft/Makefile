# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dspider- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 18:40:41 by dspider-          #+#    #+#              #
#    Updated: 2019/03/01 15:14:02 by dspider-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c	ft_memdel.c	ft_striter.c	ft_bzero.c	ft_memmove.c	ft_striteri.c \
		ft_count_if.c	ft_memset.c	ft_strjoin.c	ft_fibonacci.c	ft_print_params.c \
		ft_strlcat.c	ft_is_prime.c	ft_putchar.c	ft_strlen.c	ft_isalnum.c \
		ft_putchar_fd.c	ft_strmap.c ft_isalpha.c	ft_putendl.c	ft_strmapi.c \
		ft_isascii.c	ft_putendl_fd.c	ft_strncat.c	ft_isdigit.c	ft_putnbr.c \
		ft_strncmp.c	ft_isprint.c	ft_putnbr_fd.c	ft_strncpy.c	ft_itoa.c \
		ft_putstr.c	ft_strnequ.c	ft_lstadd.c	ft_putstr_fd.c	ft_strnew.c \
		ft_lstdel.c	ft_sort_params.c	ft_strnstr.c	ft_lstdelone.c	ft_sqrt.c \
		ft_strrchr.c	ft_lstiter.c	ft_strcat.c	ft_lstmap.c \
		ft_strchr.c	ft_strstr.c	ft_lstnew.c	ft_strclr.c	ft_strsub.c	ft_memalloc.c \
		ft_strcmp.c	ft_strtrim.c	ft_memccpy.c	ft_strcpy.c	ft_tolower.c \
		ft_memchr.c	ft_strdel.c	ft_toupper.c	ft_memcmp.c	\
		ft_strdup.c	ft_memcpy.c	ft_strequ.c ft_swap_char.c \
		ft_itoa_base.c	ft_printf.c	output.c	reading.c	next.c \
		ft_putchar_n.c	basic.c	double.c	prep_list.c	ft_bit.c	\
		finish.c	check.c	\
		ft_calc_letters.c	ft_strsplit.c	ft_free_array.c	\
		ft_calc_words.c

OBJ  = $(SRC:.c=.o)

HEADER = libft.h libftprintf.h split.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -O3 -Wextra -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
