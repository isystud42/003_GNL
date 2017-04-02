/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:18:16 by isy               #+#    #+#             */
/*   Updated: 2016/11/24 15:18:18 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa(int n)
{
	int		tempo;
	int		final;
	int		inf_zero;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tempo = n;
	final = 2;
	inf_zero = 0;
	ft_negative(&n, &inf_zero);
	while (tempo /= 10)
		final++;
	final += inf_zero;
	if ((str = (char*)malloc(sizeof(char) * final)) == NULL)
		return (NULL);
	str[--final] = '\0';
	while (final--)
	{
		str[final] = n % 10 + '0';
		n = n / 10;
	}
	if (inf_zero)
		str[0] = '-';
	return (str);
}
