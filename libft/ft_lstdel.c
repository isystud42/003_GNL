/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:43:01 by isy               #+#    #+#             */
/*   Updated: 2016/11/26 19:43:13 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lol;
	t_list	*mdr;

	lol = *alst;
	while (lol)
	{
		mdr = lol->next;
		del(lol->content, lol->content_size);
		free(mdr);
		lol = mdr;
	}
	*alst = NULL;
}
