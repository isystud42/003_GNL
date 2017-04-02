/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:51:29 by isy               #+#    #+#             */
/*   Updated: 2016/12/04 15:18:52 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*lol;
	size_t	da_final_countdown;

	da_final_countdown = 0;
	if (s)
	{
		lol = (char *)malloc(sizeof(char) * (len + 1));
		if (lol == NULL)
			return (NULL);
		while (da_final_countdown < len)
		{
			lol[da_final_countdown] = s[start + da_final_countdown];
			da_final_countdown++;
		}
		lol[da_final_countdown] = '\0';
		return (lol);
	}
	else
		return (NULL);
}
