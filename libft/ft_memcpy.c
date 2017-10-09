/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:27:56 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/06 14:35:37 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	i = 0;
	while (n-- > 0)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
