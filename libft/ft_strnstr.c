/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:05:08 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/23 04:05:41 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	"ozarabozaraboze123"; ->"ozaraboze" -> len = 15
**	won't compare more than len.
**	char			*ft_strnstr(const char *big, const char *little, size_t len)
**	{
**		const char *s;
**		const char *f;
**		size_t orig_len;
**
**		orig_len = len;
**		if (!*little)
**			return ((char*)big);
**		while (*big++)
**		{
**			s = big;
**			f = little;
**			while (*s && *f && len)
**				if (*s++ != *f)
**				{
**					orig_len -= 1;
**					len = orig_len;
**					break ;
**				}
**				else
**				{
**					f++;
**					--len
**				}
**			if (*f == 0)
**				return ((char*)big);
**		}
**		return (0);
**	}
*/

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*s;
	const char	*f;
	const char	*end_string;

	end_string = big + len;
	if (!*little)
		return ((char*)big);
	while (*big)
	{
		s = big;
		f = little;
		while (*s && *f && len && s < end_string)
			if (*s++ != *f)
				break ;
			else
			{
				f++;
			}
		if (*f == 0)
			return ((char*)big);
		big++;
	}
	return (0);
}
