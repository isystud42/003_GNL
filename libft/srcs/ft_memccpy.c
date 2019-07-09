/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:25:58 by isy               #+#    #+#             */
/*   Updated: 2016/11/20 14:26:01 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			cmpt;
	unsigned char	charizard;

	charizard = (unsigned char)c;
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	cmpt = 0;
	while (cmpt < n)
	{
		destination[cmpt] = source[cmpt];
		if (source[cmpt] == charizard)
			return (&destination[cmpt + 1]);
		cmpt++;
	}
	return (NULL);
}
