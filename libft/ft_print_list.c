/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:05:59 by isy               #+#    #+#             */
/*   Updated: 2016/11/28 13:06:02 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr((char *)tmp->content);
		ft_putchar('(');
		ft_putnbr(tmp->content_size);
		ft_putchar(')');
		if (tmp->next)
			ft_putstr(" --> ");
		tmp = tmp->next;
	}
}
