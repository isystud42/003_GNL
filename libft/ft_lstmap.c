/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:55:13 by isy               #+#    #+#             */
/*   Updated: 2016/11/26 21:55:34 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*finish;

	new = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (new == NULL)
		{
			new = ft_lstnew(tmp->content, tmp->content_size);
			finish = new;
		}
		else
		{
			new->next = ft_lstnew(tmp->content, tmp->content_size);
			new = new->next;
		}
		lst = lst->next;
	}
	return (finish);
}
