NAME = libft.a

FILEC =	ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memcmp.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strsplit.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_countword.c \
		ft_freearr.c \
		ft_intsize.c \
		ft_swappoint.c \
		ft_sqrt.c \
		ft_countc.c \
		ft_l_itoa.c \
		ft_ltoa_base.c \
		ft_utoa_base.c \
		ft_utoa_base_little.c \
		ft_join_free.c \
		ft_swap.c \
		ft_latoi.c \
		ft_free_two_arr.c \
		ft_atoi_for_swap.c \
		ft_error_ps.c \
		get_next_line.c \
		ft_check_str_numb.c \
		chek_num_al_l.c \
		ft_check_sim.c \

FT_PRINTF =  	ft_printf.c \
		ft_struct.c \
		ft_parse_format.c \
		ft_print_str_char_pr.c \
		ft_print_int.c \
		ft_help_norm_for_d.c \
		ft_mod_lenght.c \
		ft_mod_lenght_2.c \
		ft_print_u.c \
		ft_print_o_p.c \
		ft_space_for_x.c \
		ft_print_x.c \
		ft_print_float.c \
		ft_float_accuracy.c \
		ft_float_roun.c \

FILEO = $(FILEC:.c=.o)

OBJPRINT = $(FT_PRINTF:.c=.o)

DIRPRINT = ft_printf

FP = $(addprefix $(DIRPRINT)/, $(FT_PRINTF))

LIB = libft.h

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILEO)
	@gcc -c $(FILEC) $(FP) -I $(LIB)
	@ar -rc $(NAME) $(FILEO) $(OBJPRINT)
	@ranlib $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all 
