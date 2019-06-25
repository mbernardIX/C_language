/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:48:27 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>

static int		slesh(char *save)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!save)
		return (0);
	if (save[0] == '\n')
		return (i);
	while (save[j] == '\n')
		j++;
	i = j;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	return (i);
}

static int		nextslesh(char *save)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	while (save[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static int		afte(char **line, char **save,
		int fd, char *tmp)
{
	*line = ft_strsub(save[fd], 0, slesh(save[fd]));
	tmp = save[fd];
	save[fd] = ft_strsub(save[fd],
			slesh(save[fd]) + 1, nextslesh(save[fd]));
	free(tmp);
	if (save[fd] == NULL)
		ft_strdel(&save[fd]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*save[255];
	char			strbuf[BUFF_SIZE + 1];
	int				nb;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, strbuf, 0) < 0)
		return (-1);
	if (save[fd] == 0)
		save[fd] = ft_strnew(1);
	if (!save[fd])
		return (-1);
	while ((nb = read(fd, strbuf, BUFF_SIZE)) > 0)
	{
		tmp = save[fd];
		strbuf[nb] = '\0';
		save[fd] = ft_strjoin(save[fd], strbuf);
		free(tmp);
		if (nextslesh(save[fd]) > 0)
			return (afte(line, save, fd, tmp));
	}
	if (nb < 0)
		return (-1);
	if (nb == 0 && ft_strlen(save[fd]))
		return (afte(line, save, fd, tmp));
	return (0);
}
