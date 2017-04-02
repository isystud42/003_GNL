/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 21:43:31 by isy               #+#    #+#             */
/*   Updated: 2016/11/20 21:43:33 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int nb_carac;
	int j;

	nb_carac = 0;
	j = 0;
	while (dest[nb_carac] != '\0')
		nb_carac++;
	while (src[j])
	{
		dest[nb_carac] = src[j];
		nb_carac++;
		j++;
	}
	dest[nb_carac] = '\0';
	return (dest);
}
