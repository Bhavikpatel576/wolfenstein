/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:30:31 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/24 15:27:21 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	locates first occurence of little in big. If !little return big. If lit
**	doesn't show up in big, return null, else pointer to first matching char s
**	char	*ft_strstr(const char *big, const char *little)
**	{
**		int i;
**		int j;
**		int k;
**
**		i = 0;
**		if (!little)
**			return ((char *)big);
**		while (big[i] != '\0')
**		{
**			j = 0;
**			k = i;
**			while (big[k] == little[j] && (big[k] != '\0' || little[j] !='\0'))
**			{
**				if (little[j + 1] == '\0')
**					return ((char*)(big+i));
**				k++;
**				j++;
**			}
**			i++;
**		}
**
**		return (0);
**	}
*/

char	*ft_strstr(const char *big, const char *little)
{
	const char *s;
	const char *f;

	if (!*little)
		return ((char*)big);
	while (*big)
	{
		s = big;
		f = little;
		while (*s && *f)
			if (*s++ != *f)
				break ;
			else
				f++;
		if (*f == 0)
			return ((char*)big);
		big++;
	}
	return (0);
}
