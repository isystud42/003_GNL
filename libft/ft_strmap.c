/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:17:37 by isy               #+#    #+#             */
/*   Updated: 2016/11/24 10:17:40 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*shit;

	if (s != NULL || f != NULL)
	{
		if (s)
		{
			shit = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
			if (shit == NULL)
				return (NULL);
			i = -1;
			while (s[++i])
				shit[i] = f(s[i]);
			shit[i] = '\0';
			return (shit);
		}
	}
	return (NULL);
}
