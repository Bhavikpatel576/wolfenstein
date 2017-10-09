/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:01:05 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/10 14:44:36 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	string = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!string)
		return (NULL);
	ft_strcpy(string, s1);
	ft_strcat(string, s2);
	return (string);
}
