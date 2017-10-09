/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:55:44 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/10 02:04:09 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strdup(const char *s1)
{
	int		size_of_char;
	int		i;
	char	*test;

	i = 0;
	size_of_char = ft_strlen(s1);
	test = (char*)malloc((size_of_char + 1) * sizeof(char));
	if (!test)
		return (NULL);
	while (i < size_of_char + 1)
	{
		test[i] = s1[i];
		i++;
	}
	return (test);
}
