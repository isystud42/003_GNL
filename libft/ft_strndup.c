/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:22:09 by isy               #+#    #+#             */
/*   Updated: 2016/11/28 12:22:11 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int j)
{
	char	*cpy;
	int		i;

	i = 0;
	while (i != j && src[i])
		i++;
	if (!(cpy = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (i != j && src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
