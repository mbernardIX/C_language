/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:47:38 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:47:43 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	result_of_check(t_link *link)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;

	i = 0;
	if (link->start_b != NULL)
		ft_putstr("KO\n");
	else
	{
		stack_a = link->start_a;
		while (stack_a)
		{
			if (stack_a->next)
			{
				tmp = stack_a->next;
				if (tmp->num < stack_a->num)
					i++;
			}
			stack_a = stack_a->next;
		}
		if (i == 0)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
}

void	recognize_command(t_link *link, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		commands_sa(link);
	else if (ft_strcmp(command, "sb") == 0)
		commands_sb(link);
	else if (ft_strcmp(command, "ss") == 0)
		commands_ss(link);
	else if (ft_strcmp(command, "pa") == 0)
		commands_pa(link);
	else if (ft_strcmp(command, "pb") == 0)
		commands_pb(link);
	else if (ft_strcmp(command, "ra") == 0)
		commands_ra(link);
	else if (ft_strcmp(command, "rb") == 0)
		commands_rb(link);
	else if (ft_strcmp(command, "rr") == 0)
		commands_rr(link);
	else if (ft_strcmp(command, "rra") == 0)
		commands_rra(link);
	else if (ft_strcmp(command, "rrb") == 0)
		commands_rrb(link);
	else if (ft_strcmp(command, "rrr") == 0)
		commands_rrr(link);
	else
		error();
	output_elem(link);
}

void	find_command(t_link *link, char *p)
{
	int		len;
	char	*tmp;
	char	*command;

	tmp = NULL;
	command = NULL;
	while (ft_strchr(p, '\n'))
	{
		len = 0;
		if (!p)
			p = ft_strnew(0);
		while (p[len] != '\n' && p[len] != '\0')
			len++;
		if (ft_strlen(p))
			command = ft_strsub(p, 0, len);
		if (p[len] != '\0')
			tmp = ft_strdup(&p[len + 1]);
		else
			tmp = NULL;
		ft_strdel(p);
		p = tmp;
		recognize_command(link, command);
		ft_strdel(command);
	}
	ft_strdel(p);
}

void	recieve_commands(t_link *link)
{
	char	buff[5 + 1];
	int		i;
	char	*p;
	char	*tmp;

	p = NULL;
	while ((i = read(0, buff, 5)) > 0)
	{
		tmp = NULL;
		buff[i] = '\0';
		tmp = ft_strjoin(p, buff);
		ft_strdel(p);
		p = ft_strdup(tmp);
		ft_strdel(tmp);
	}
	if (p)
		find_command(link, p);
	result_of_check(link);
}
