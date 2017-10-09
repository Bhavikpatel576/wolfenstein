/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:37:45 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/07 18:13:30 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	int				diff;
	unsigned char	*string_one;
	unsigned char	*string_two;

	string_one = (unsigned char *)s1;
	string_two = (unsigned char *)s2;
	i = 0;
	diff = 0;
	while (n--)
	{
		if (*string_one == *string_two)
		{
			string_one++;
			string_two++;
		}
		else
			diff = *string_one - *string_two;
	}
	return (diff);
}
