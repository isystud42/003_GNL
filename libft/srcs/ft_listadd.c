/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:49:08 by idsy              #+#    #+#             */
/*   Updated: 2019/05/06 10:32:22 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Basically ft_lstadd but in a structure more usable and usefull with a prev
*/

void	ft_listadd(t_lst **alst, t_lst *new)
{
	if (alst && new)
	{
		new->next = *alst;
		new->prev = NULL;
		*alst = new;
	}
}
