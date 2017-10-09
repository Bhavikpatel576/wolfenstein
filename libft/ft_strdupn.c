/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:06 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/12 17:32:47 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strdupn(const char *s1, size_t size_of_char)
{
	size_t		i;
	char		*test;

	i = 0;
	test = (char*)malloc((size_of_char + 1) * sizeof(char));
	if (!test)
		return (NULL);
	while (i < size_of_char + 1)
	{
		test[i] = s1[i];
		i++;
	}
	test[i] = '\0';
	return (test);
}
