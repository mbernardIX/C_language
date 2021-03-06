/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:32:36 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:34:19 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	char	*s;

	if ((tmp = malloc(sizeof(t_list))) == 0)
		return (0);
	tmp->content_size = content_size;
	tmp->next = NULL;
	if (content_size != 0 && content != 0)
	{
		if (!(s = ft_memalloc(content_size)))
		{
			free(tmp);
			return (0);
		}
		tmp->content = ft_memcpy(s, content, content_size);
	}
	else
	{
		tmp->content = 0;
		tmp->content_size = 0;
	}
	return (tmp);
}
