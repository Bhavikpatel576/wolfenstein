/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:34:21 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/24 15:18:42 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**apply a function to each element of the string s.
*/

#include <libft.h>

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
	{
		f(s++);
	}
}
