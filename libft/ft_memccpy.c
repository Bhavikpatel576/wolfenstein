/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:25:49 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/07 12:14:20 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** If c is not found, null will be returned (dst and src should not overlap)
*/

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;
	size_t			return_index;

	destination = dst;
	source = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		destination[i] = source[i];
		if (source[i] == (unsigned char)(c))
		{
			return_index = i + 1;
			return (dst + return_index);
		}
		i++;
	}
	return (NULL);
}
