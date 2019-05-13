NAME = get_next_line

all: one

one:
	gcc -Wall -Wextra -Werror -L libft/ -lft -I libft/ -o $(NAME) get_next_line.c main.c
two:
	gcc -Wall -Wextra -Werror -L libft/ -lft -I libft/ -o $(NAME) get_next_line.c main2.c
oned:
	gcc -Wall -Wextra -Werror -L libft/ -lft -I libft/ -o $(NAME) get_next_line_DEBUG.c main.c
twod:
	gcc -Wall -Wextra -Werror -L libft/ -lft -I libft/ -o $(NAME) get_next_line_DEBUG.c main2.c
fclean:
	/bin/rm -f $(NAME)
re: fclean all
