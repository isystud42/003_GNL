/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:41:47 by isy               #+#    #+#             */
/*   Updated: 2016/11/20 16:42:00 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	comp;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	comp = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == comp)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
