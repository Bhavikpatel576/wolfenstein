/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:50:24 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/24 15:21:24 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*node;

	node = ft_memalloc(sizeof(t_list));
	if (node)
	{
		if (content)
		{
			node->content_size = content_size;
			node->content = ft_memalloc(content_size);
			if (node->content)
				ft_memmove(node->content, content, content_size);
		}
		else
		{
			node->content_size = 0;
			node->content = NULL;
		}
		node->next = NULL;
	}
	return (node);
}
