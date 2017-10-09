/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:25:04 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/08 17:22:03 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*string_one;
	char	*string_two;
	int		len;
	int		index;

	string_one = (char *)s1;
	string_two = (char *)s2;
	len = ft_strlen(string_one);
	index = 0;
	while (string_two[index] != '\0')
	{
		string_one[len + index] = string_two[index];
		index++;
	}
	string_one[len + index] = '\0';
	return (s1);
}
