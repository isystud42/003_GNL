/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:51:29 by isy               #+#    #+#             */
/*   Updated: 2019/07/12 12:01:30 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	countdown;

	countdown = 0;
	if (!s || !(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (countdown < len)
	{
		*(new_str + countdown) = *(s + start + countdown);
		countdown++;
	}
	*(new_str + countdown) = '\0';
	return (new_str);
}
