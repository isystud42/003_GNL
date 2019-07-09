/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:51:29 by isy               #+#    #+#             */
/*   Updated: 2019/06/24 10:54:21 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*lol;
	size_t	countdown;

	countdown = 0;
	if (s)
	{
		lol = (char *)malloc(sizeof(char) * (len + 1));
		if (lol == NULL)
			return (NULL);
		while (countdown < len)
		{
			lol[countdown] = s[start + countdown];
			countdown++;
		}
		lol[countdown] = '\0';
		return (lol);
	}
	else
		return (NULL);
}
