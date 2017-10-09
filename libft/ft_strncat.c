/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 01:39:34 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/23 01:39:55 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*string_one;
	char	*string_two;
	int		len;
	int		index;

	string_one = (char *)s1;
	string_two = (char *)s2;
	len = ft_strlen(string_one);
	index = 0;
	while (string_two[index] != '\0' && n)
	{
		string_one[len + index] = string_two[index];
		index++;
		n--;
	}
	string_one[len + index] = '\0';
	return (s1);
}
