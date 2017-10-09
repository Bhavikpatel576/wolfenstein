/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:06:28 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/09 22:14:18 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**description: Sets every character of the string to the value '\0'
*/

#include <libft.h>

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}
