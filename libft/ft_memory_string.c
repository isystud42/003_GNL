/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 02:47:21 by isy               #+#    #+#             */
/*   Updated: 2016/11/28 13:04:04 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memory_string(char *lol, size_t mdr)
{
	char	*ptdr;

	ptdr = ft_strdup(lol);
	free(lol);
	lol = (char *)malloc(sizeof(char) * (mdr + 1));
	ft_strncpy(lol, ptdr, mdr);
	free(ptdr);
	return (lol);
}
