NAME = lem-in

FLAGS = -Wall -Werror -Wextra

SRC = main.c \
	  scan_param.c \
	  val_param.c \
	  ft_struct.c \
	  func_for_val.c \
	  func_for_val_p2.c \
	  step_2.c \
	  step_3.c \
	  sort_list.c \
	  alg_lem.c \
	  struct_for_queue.c \
	  ft_queue.c \
	  create_quick_way.c \
	  re_malloc.c \
	  add_queue.c \
	  del_dead_end.c \
	  check_double.c \
	  check_par_dead_end.c \
	  kill_cross.c \
	  check_start_end.c \
	  func_for_ants.c \
	  print_ants.c \

DIRSRC = ./src

DIRO = ./obj

DS = $(addprefix $(DIRSRC)/, $(SRC))

OBJ = $(addprefix $(DIRO)/, $(SRC:.c=.o))

INCLUDES = -I libft -I include

LIB_INC = -L libft -lft

all: $(NAME)

$(NAME): libmake creatdiro $(OBJ)
		gcc $(FLAGS) $(INCLUDES) $(LIB_INC) $(OBJ) -o $(NAME) 

$(addprefix $(DIRO)/, %.o): $(addprefix $(DIRSRC)/,%.c)
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

creatdiro:
		mkdir -p $(DIRO)

libmake:
		make -C libft

clean: 
		rm -rf $(DIRO)
		make clean -C libft

fclean: clean
		make fclean -C libft
		rm -f $(NAME)

re: fclean all
