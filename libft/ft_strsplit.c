/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:22:14 by isy               #+#    #+#             */
/*   Updated: 2016/11/24 14:22:17 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_mots(const char *s, char c)
{
	int		i;
	int		separations;

	separations = 0;
	i = 0;
	while (*s != '\0')
	{
		if (separations == 1 && *s == c)
			separations = 0;
		if (separations == 0 && *s != c)
		{
			separations = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int		ft_long(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_mots;
	int		ind;

	if (!s)
		return (NULL);
	ind = 0;
	nb_mots = ft_mots((const char *)s, c);
	tab = (char **)malloc(sizeof(*tab) * (nb_mots + 1));
	if (tab == NULL)
		return (NULL);
	while (nb_mots--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[ind] = ft_strsub((const char *)s, 0, ft_long((const char *)s, c));
		if (tab[ind] == NULL)
			return (NULL);
		s = s + ft_long(s, c);
		ind++;
	}
	tab[ind] = NULL;
	return (tab);
}
