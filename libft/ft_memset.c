/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:57:18 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/06 11:57:43 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** writes len bytes of unsigned c to string b
*/

#include <libft.h>

void				*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*b;

	b = s;
	i = 0;
	while (n--)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
