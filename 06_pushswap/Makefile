# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 15:53:20 by mbernard          #+#    #+#              #
#    Updated: 2019/06/19 15:53:35 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker

PUSH = push_swap

SRC_CHECK = folder_checker/main_for_checker.c \
	  		folder_checker/read_and_save_checker.c \
	  		folder_checker/checker.c

SRC_PUSH =	folder_push_swap/main_for_push_swap.c \
	  		folder_push_swap/read_and_save_push_swap.c	\
			folder_push_swap/preparation.c	\
			folder_push_swap/algorithm.c

SRC = folder_general/output.c	\
	  folder_general/first_part_commands.c    \
	  folder_general/second_part_commands.c \
	  folder_general/third_part_commands.c	\
	  folder_general/test_error.c	\
	  folder_general/convert.c

INC = push_swap.h

LIB = printflibft/libftprintf.a

all: $(PUSH) $(CHECK)

$(PUSH): $(SRC_PUSH)
	@$(MAKE) -C ./printflibft
	gcc -Wall -Wextra -Werror $(SRC_PUSH) $(SRC) $(LIB) -I $(INC) -o $(PUSH)

$(CHECK): $(SRC_CHECK)
	@$(MAKE) -C ./printflibft
	gcc -Wall -Wextra -Werror $(SRC_CHECK) $(SRC) $(LIB) -I $(INC) -o $(CHECK)

clean:
	@$(MAKE) -C ./printflibft clean

fclean: clean
	@$(MAKE) -C ./printflibft fclean
	/bin/rm -f $(PUSH) $(CHECK)

re: fclean all
