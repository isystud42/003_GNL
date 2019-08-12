/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:27:02 by idsy              #+#    #+#             */
/*   Updated: 2019/08/12 18:56:40 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Basically, une fonction qui fait le strjoin mais en renvoyant de la memoire
**	fraiche avec un free des anciens components.
*/

static int	give_len(char *s1, char *s2)
{
	if (!s1 && s2)
		return (ft_strlen(s2));
	else if (s1 && !s2)
		return (ft_strlen(s1));
	else
		return (ft_strlen(s1) + ft_strlen(s2));
}

static void	free_str(char **s1, char **s2, int flag)
{
	if (flag == 1)
		free(*s1);
	if (flag == 2)
		free(*s2);
	if (flag == 3)
	{
		free(*s1);
		free(*s2);
	}
}

char		*ft_strjoin_free(char *s1, char *s2, int flag)
{
	char	*new;
	char	*s_s1;
	char	*s_s2;
	char	*s_new;

	if ((!s1 && !s2) ||
		!(new = malloc(sizeof(char) * (give_len(s1, s2) + 1))))
		return (NULL);
	s_s1 = s1;
	s_s2 = s2;
	s_new = new;
	while (s1 && *s_s1)
		*s_new++ = *s_s1++;
	while (s2 && *s_s2)
		*s_new++ = *s_s2++;
	*s_new = '\0';
	free_str(&s1, &s2, flag);
	return (new);
}
