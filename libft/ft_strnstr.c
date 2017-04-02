/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:34:42 by isy               #+#    #+#             */
/*   Updated: 2016/11/21 01:34:50 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!ft_strlen(lil) || lil[0] == 0)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] == lil[j] && lil[j])
			j++;
		if (!lil[j] && j != 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
