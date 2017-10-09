/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 00:16:55 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/23 00:17:10 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	copies len bytes from src to dst. String may overlap and is done in a
**	"non-destructive manner". If src memory > dst memory copy value forward
**	if src < dst copy backwards at length len. Increase pointer by len.
*/

#include <libft.h>

static void		ft_back_memcpy(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	d += len;
	s += len;
	while (len--)
	{
		*--d = *--s;
	}
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		ft_back_memcpy(dst, src, len);
	return (dst);
}
