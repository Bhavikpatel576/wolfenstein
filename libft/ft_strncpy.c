/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:12:24 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/03 22:29:58 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** same as strcpy, but if src < len -> rem values filled with '\0'
*/

#include <libft.h>

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (src[i] != '\0' && len > n)
	{
		dst[i] = src[i];
		i++;
		n++;
	}
	while (len > n)
	{
		dst[i] = '\0';
		i++;
		n++;
	}
	return (dst);
}
