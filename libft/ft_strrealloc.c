/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:05:20 by idsy              #+#    #+#             */
/*   Updated: 2019/05/06 11:19:06 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Gimme a string adress, i will resize it for you with fresh memory <3
*/

char	*ft_strrealloc(char **str, size_t new_size)
{
	char	*new_str;
	char	*tmp;
	char	*save;

	if (!(new_str = malloc(sizeof(char) * new_size + 1)))
		return (NULL);
	tmp = new_str;
	save = *str;
	while (tmp - new_str < (long)new_size)
	{
		if (*str)
			*tmp++ = *save++;
		else
			*tmp++ = '\0';
	}
	*tmp = '\0';
	free(*str);
	return (new_str);
}
