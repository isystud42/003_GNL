/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:45:14 by isy               #+#    #+#             */
/*   Updated: 2016/11/24 20:27:24 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	nb_carac;
	size_t	lgnt_s1;

	if (size == 0)
		return (ft_strlen(src));
	nb_carac = 0;
	while (dest[nb_carac] && nb_carac < size)
		nb_carac++;
	lgnt_s1 = nb_carac;
	while (src[nb_carac - lgnt_s1] && nb_carac < size - 1)
	{
		dest[nb_carac] = src[nb_carac - lgnt_s1];
		nb_carac++;
	}
	if (lgnt_s1 < size)
		dest[nb_carac] = '\0';
	return (lgnt_s1 + ft_strlen(src));
}
