/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:44:01 by mbernard          #+#    #+#             */
/*   Updated: 2019/05/08 15:30:01 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	static char	*s[20000];
	char		buff[BUFF_SIZE + 1];
	char		*t;
	ssize_t		z;
	int			end;

	if (fd < 0 || (!s[fd] && !(s[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(s[fd], '\n') && (z = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[z] = '\0';
		t = s[fd];
		s[fd] = ft_strjoin(s[fd], buff);
		ft_strdel(&t);
	}
	if (z == -1 || !*(t = s[fd]))
		return (z == -1 ? -1 : 0);
	if ((end = (ft_strchr(s[fd], '\n') > 0) ? 1 : 0))
		*line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd]);
	else
		*line = ft_strdup(s[fd]);
	s[fd] = ft_strsub(s[fd], (unsigned int)(ft_strlen(*line) + end),
			(size_t)(ft_strlen(s[fd]) - (ft_strlen(*line) + end)));
	ft_strdel(&t);
	return (!(!s[fd] && !ft_strlen(*line)));
}
