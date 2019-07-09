/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:01:56 by isy               #+#    #+#             */
/*   Updated: 2016/12/08 21:01:57 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **lst, t_list *new)
{
	t_list *view;

	view = *lst;
	if (view != NULL)
	{
		while (view->next != NULL)
			view = view->next;
		view->next = new;
	}
	else
		*lst = new;
}
