# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 16:47:58 by mbernard          #+#    #+#              #
#    Updated: 2019/04/04 16:48:33 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC_DIR = srcs/
INCLUDES_DIR = includes/

FLAGS=-Wall -Wextra -Werror

FUNCTIONS=main.c
SRCS = $(patsubst %,$(SRC_DIR)%,$(FUNCTIONS))
OBJ = $(patsubst %.c,%.o,$(FUNCTIONS))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ):
		gcc -I$(INCLUDES_DIR) $(FLAGS) -c $(SRCS)

$(NAME): $(OBJ)
		gcc -I$(INCLUDES_DIR) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
