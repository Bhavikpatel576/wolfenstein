/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 14:03:31 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/29 13:42:56 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int i;
	int negative_test;
	int total;

	i = 0;
	total = 0;
	negative_test = 1;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '-')
		negative_test = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		total = (total * 10) + (str[i] - '0');
		i++;
	}
	return (negative_test * total);
}
