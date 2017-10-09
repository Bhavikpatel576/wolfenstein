/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_last_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:46:47 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/25 16:46:54 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	put_char(char c)
{
	write(1, &c, 1);
}

static	int		is_word_char(char *str, int i)
{
	if ((i < 0) || (str[i] == '\0') || (9 <= str[i] && str[i] <= 13)
		|| (str[i] == 32))
		return (0);
	else
		return (1);
}

static	void	print_word(char *str, int start_i)
{
	int i;

	i = start_i;
	while (is_word_char(str, i))
	{
		put_char(str[i]);
		i++;
	}
}

void			ft_print_last_word(char *str)
{
	int			last_word_start_idx;
	int			i;

	i = 0;
	last_word_start_idx = -1;
	while (str[i] != '\0')
	{
		if (is_word_char(str, i) && !(is_word_char(str, i - 1)))
			last_word_start_idx = i;
		i++;
	}
	print_word(str, last_word_start_idx);
}
