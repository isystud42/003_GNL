/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_smaller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:54:58 by idsy              #+#    #+#             */
/*   Updated: 2019/05/06 11:11:04 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Size contest between 2 numbers... Yeah childish, but useful i swear.
** b has an advantage tho.
*/

size_t	ft_is_smaller(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
