/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:01:39 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/07 17:37:27 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	c_find;
	unsigned char	*string;

	c_find = (unsigned char)c;
	string = (unsigned char*)s;
	index = 0;
	while (n--)
	{
		if (*string == c_find)
			return (string);
		if (n == 0)
			return (NULL);
		string++;
	}
	return (0);
}
