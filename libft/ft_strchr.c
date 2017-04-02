/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 00:00:27 by isy               #+#    #+#             */
/*   Updated: 2016/11/21 00:00:38 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*mdr;

	i = 0;
	mdr = (char *)s;
	while (i < (ft_strlen(mdr) + 1))
	{
		if (mdr[i] == (char)c)
			return (&mdr[i]);
		i++;
	}
	return (NULL);
}
