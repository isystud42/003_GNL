/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:34:09 by isy               #+#    #+#             */
/*   Updated: 2016/11/24 15:17:41 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sc;

	sc = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
		while (n--)
			(dst[n] = sc[n]);
	return (dest);
}
