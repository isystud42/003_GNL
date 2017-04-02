/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 00:46:55 by isy               #+#    #+#             */
/*   Updated: 2016/11/21 00:46:59 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*mdr;
	int		max;

	mdr = (char *)s;
	max = ft_strlen(mdr);
	while (max >= 0)
	{
		if (mdr[max] == (char)c)
			return (&mdr[max]);
		max--;
	}
	return (NULL);
}
