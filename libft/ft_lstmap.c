/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:07:18 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/23 20:07:20 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*original;
	t_list	*new;

	if (!lst)
		return (0);
	new_list = f(lst);
	if (new_list)
	{
		original = lst->next;
		new = new_list;
		while (original)
		{
			new->next = f(original);
			original = original->next;
			new = new->next;
		}
	}
	return (new_list);
}
