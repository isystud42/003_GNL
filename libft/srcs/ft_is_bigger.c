/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bigger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:46:35 by idsy              #+#    #+#             */
/*   Updated: 2019/05/06 11:10:40 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Size contest between 2 numbers... Yeah childish, but useful i swear.
** a has an advantage tho.
*/

size_t	ft_is_bigger(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
