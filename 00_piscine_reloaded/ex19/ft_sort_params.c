/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:54:17 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/05 14:54:23 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		main(int ac, char **av)
{
	int		check;
	int		i;
	char	*uk;

	check = 1;
	while (check)
	{
		i = 0;
		check = 0;
		while (++i < ac - 1)
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				uk = av[i];
				av[i] = av[i + 1];
				av[i + 1] = uk;
				check++;
			}
		}
	}
	i = 0;
	while (++i < ac)
		ft_putstr(av[i]);
	return (0);
}
