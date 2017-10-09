/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:22:18 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/10 00:53:32 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	appends src to dst at most size - strlen(dst) - 1 bytes
*/

#include <libft.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*string;
	size_t		len_src;
	size_t		len_dst;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst < size)
	{
		string = dst + len_dst;
		ft_bzero(string, size - len_dst);
		ft_memcpy(string, src, size - len_dst - 1);
		return (len_dst + len_src);
	}
	return (len_src + size);
}
