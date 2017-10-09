/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:32:11 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/29 13:43:33 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	count the number of words in the string. Allocate space for the num of words
**	count the num of letters in each word -> allocate space
*/

static int	ft_countw(char const *string, char c)
{
	size_t	num_words;
	int		pointer;

	pointer = 1;
	num_words = 0;
	while (*string)
	{
		if (pointer != (*string == c))
			if (pointer)
				num_words++;
		pointer = (*string == c);
		string++;
	}
	return (num_words);
}

char		**ft_strsplit(const char *s, char c)
{
	size_t	word;
	size_t	num_words;
	char	**words;
	char	*iter;

	if (!s)
		return (0);
	num_words = ft_countw(s, c);
	words = (char **)ft_memalloc(sizeof(char*) * (num_words + 1));
	if (!words)
		return (NULL);
	word = 0;
	while (word < num_words)
	{
		while (*s == c)
			++s;
		iter = ft_strchr(s, c);
		if (iter)
			words[word] = ft_strsub(s, 0, iter - s);
		else
			words[word] = ft_strdup(s);
		s = iter;
		++word;
	}
	return (words);
}
