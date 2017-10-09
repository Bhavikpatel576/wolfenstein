/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:36:13 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/24 15:28:58 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	trim(char c)
{
	if (c == '\t' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	char	*start;
	char	*end;
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	start = (char *)s;
	end = (char *)s + len - 1;
	while (trim(*start))
		++start;
	while (trim(*end) && end > start)
		--end;
	return (ft_strsub(start, 0, 1 + end - start));
}
