/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:02:41 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/15 15:12:23 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_countl(char const *s, char c, int countw)
{
	int		countl;
	int		word;
	int		index;

	word = 0;
	countl = 0;
	index = 0;
	while (word < countw)
	{
		if (s[0] == s[index] && s[0] != c)
		{
			word = 1;
			index++;
		}
		else
		{
			while (s[index] == c && s[index] != '\0')
				index++;
			if (s[index] != c && s[index] != '\0')
				word += 1;
		}
	}
	if (word == countw)
		countl = 0;
	return (countl);
}
