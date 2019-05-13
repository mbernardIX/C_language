/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:14:00 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/05 14:39:24 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	int i;
	int count;

	i = 0;
	count = 1;
	argc = argc - 1;
	while (argc != 0)
	{
		while (argv[count][i] != '\0')
		{
			ft_putchar(argv[count][i]);
			i++;
		}
		i = 0;
		count++;
		argc--;
		ft_putchar('\n');
	}
	return (0);
}
