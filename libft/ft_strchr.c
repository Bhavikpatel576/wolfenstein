/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:49:06 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/23 02:03:10 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	locates FIRST occurance of character pointed to by s (also includes '\0')
**	returns a pointer to the located character
*/

#include <libft.h>

/*
** function does not work with unicode or \0
**	char		*ft_strchr(const char *s, int c)
**	{
**		unsigned char	*string;
**
**		string = (unsigned char*)s;
**		while (*string++ != '\0')
**		{
**			if (*string == c)
**				return ((char*)string);
**		}
**		if (*string == '\0')
**			return (0);
**		return ((char*)string);
**	}
*/

char		*ft_strchr(const char *s, int c)
{
	const char	*string;

	string = s;
	while (*string != '\0')
	{
		if ((char)*string == c)
			return ((char*)string);
		string++;
	}
	if (c == 0)
		return ((char*)string);
	return (0);
}
