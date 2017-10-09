/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:24:47 by bpatel            #+#    #+#             */
/*   Updated: 2017/01/12 17:45:26 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>

static char	*re_alloc(char *str, size_t size)
{
	char	*p;
	size_t	i;

	p = NULL;
	i = 0;
	if (str)
	{
		p = (char *)malloc(sizeof(char) * (size));
		if (!p)
			return (NULL);
		ft_bzero(p, size);
		ft_strcpy(p, str);
		free(str);
		str = NULL;
	}
	return (p);
}

static int	null_test(char *str)
{
	if (str[0] != '\0')
		return (1);
	return (0);
}

static char	*ft_ssub(char *s, size_t len)
{
	char			*p;
	size_t			i;
	size_t			start;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	start = ft_strlen(s) - len;
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	ft_strclr(s);
	free(s);
	s = NULL;
	return (p);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char *ls;
	int			ret;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (!ls)
		ls = ft_strnew(BUFF_SIZE + 1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while (!ft_strchr(buf, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		ls = re_alloc(ls, ft_strlen(ls) + ret + 1);
		ls = ft_strncat(ls, buf, ret);
	}
	if ((tmp = ft_strchr(ls, '\n')))
	{
		*line = ft_strsub(ls, 0, ft_strlen(ls) - ft_strlen(tmp));
		ls = ft_ssub(ls, ft_strlen(&tmp[1]));
		return (1);
	}
	*line = ft_strdup(ls);
	ret = null_test(ls);
	ft_strclr(ls);
	return (ret == 0 ? 0 : 1);
}

