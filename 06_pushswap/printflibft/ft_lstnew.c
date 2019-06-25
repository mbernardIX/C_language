/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 07:59:01 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/07 08:29:33 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *y;

	y = (t_list*)malloc(sizeof(*y));
	if (!y)
		return (NULL);
	if (!content)
	{
		y->content = NULL;
		y->content_size = 0;
	}
	else
	{
		if (!(y->content = malloc(content_size)))
			return (NULL);
		y->content_size = content_size;
		ft_memcpy(y->content, content, content_size);
	}
	y->next = NULL;
	return (y);
}
