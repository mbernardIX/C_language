/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:53:31 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:53:34 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "printflibft/libftprintf.h"
# include "printflibft/libft.h"
# include "printflibft/split.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_stack
{
	long			num;
	long			oper_a;
	long			oper_b;
	struct s_stack	*start;

	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_link
{
	long			max;
	long			min;

	struct s_stack	*start_a;
	struct s_stack	*end_a;
	unsigned int	len_a;

	struct s_stack	*start_b;
	struct s_stack	*end_b;
	unsigned int	len_b;

	bool			mod_v;
	bool			mod_l;
}				t_link;

t_stack			*reading_for_check(int ac, char **av, t_stack *stack_a);
void			add_stack_checker(char *str, t_stack *a);

void			algorithm(t_link *link, t_stack *choose);
void			end(t_link *link, long i);
char			*result_of_prepare(t_link *link);

void			output_elem(t_link *link);
void			error(void);

void			recieve_commands(t_link *link);
void			find_command(t_link *link, char *p);
void			recognize_command(t_link *link, char *command);
void			result_of_check(t_link *link);

void			commands_sa(t_link *link);
void			commands_sb(t_link *link);
void			commands_ss(t_link *link);
void			commands_pa(t_link *link);
void			commands_pb(t_link *link);

void			commands_ra(t_link *link);
void			commands_rb(t_link *link);
void			commands_rr(t_link *link);

void			commands_rra(t_link *link);
void			commands_rrb(t_link *link);
void			commands_rrr(t_link *link);

t_stack			*reading_for_push_swap(int ac, char **av, t_stack *stack_a);
void			add_stack_push_swap(char *str, t_stack *stack_a);

void			first_work(t_link *link, t_stack *tmp);
void			choose_the_best(t_link *link);
void			length_in_a(t_link *link);
void			length_in_b(t_link *link);

void			test_error(t_link *link);
void			duplicate(t_link *link);
void			max_and_min_int(t_link *link);

char			**convert(int ac, char **av, int k, char **p);

#endif
