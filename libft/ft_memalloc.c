/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:19:43 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/23 04:20:01 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	char	*fill;
	size_t	i;

	ret = (void*)malloc(size);
	if (!ret)
		return (0);
	fill = ret;
	i = 0;
	while (i < size)
	{
		*fill++ = 0;
		i++;
	}
	return (ret);
}
