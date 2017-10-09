/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:36:42 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/10 20:58:10 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_reverse(char *str, int length)
{
	int start;
	int end;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		ft_swap((str + start), (str + end));
		start++;
		end--;
	}
}
