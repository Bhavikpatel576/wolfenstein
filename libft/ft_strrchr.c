/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:24:42 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/10 00:52:10 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	exact same as strchr except it searches for last 'c'. Search in reverse
*/

char			*ft_strrchr(const char *s, int c)
{
	const char	*string;
	int			string_len;

	string = s;
	string_len = ft_strlen(string);
	string = string + string_len;
	if (c == 0)
		return ((char*)string);
	while (string_len >= 0)
	{
		if ((char)*string == c)
		{
			return ((char*)string);
		}
		string--;
		string_len--;
	}
	return (0);
}
