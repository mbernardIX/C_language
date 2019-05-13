/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:46:15 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/04 16:47:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define NBYTE 4096

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_error(int ac)
{
	if (ac == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		f;
	int		ret;
	char	buf[NBYTE + 1];

	if (ft_error(ac))
		return (0);
	f = open(av[1], O_RDONLY);
	while ((ret = read(f, buf, NBYTE)))
	{
		buf[ret] = '\0';
		write(1, buf, ret);
	}
	close(f);
	return (0);
}
