/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:20:41 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/24 15:22:06 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static	int	sign(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static	int	num_len(int n)
{
	int count;
	int num;

	num = ft_abs(n);
	count = 0;
	if (num == 0)
		return (count = 1);
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	int		s;
	int		i;
	char	*string;

	s = sign(n);
	i = num_len(n);
	string = (char *)malloc(sizeof(char) * (s + i + 1));
	if (!string)
		return (NULL);
	string = string + s + i;
	*string = '\0';
	if (n == 0)
		*--string = 0 + '0';
	while (n != 0)
	{
		*--string = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	if (s == 1)
		*--string = '-';
	return (string);
}
