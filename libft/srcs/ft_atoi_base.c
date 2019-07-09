/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:00:13 by idsy              #+#    #+#             */
/*   Updated: 2019/05/06 11:05:17 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	See atoi over there? Well am him, but better. Cuz i have this special
**	customizable output. gimme a Base you want your answer in and you'll get it
**	tweaked in the good base. Yeah, i know... awesome.
*/

static void	handle_neg_base_ten(char *s, int base_size, int *is_neg, int *x)
{
	if (base_size == 10 && s[0] == '-')
	{
		*is_neg = 1;
		*x += 1;
	}
}

int			ft_atoi_base(char *s, int base_size)
{
	int		is_neg;
	int		x;
	long	ret;

	is_neg = 0;
	ret = 0;
	x = 0;
	handle_neg_base_ten(s, base_size, &is_neg, &x);
	while ((s[x] && s[x] >= '0' && s[x] <= '9') ||
			(s[x] && s[x] >= 'A' && s[x] <= 'Z'))
	{
		if (s[x] >= '0' && s[x] <= '9')
			ret = ret * base_size + (s[x] - '0');
		else
			ret = ret * base_size + (s[x] - 'A' + 10);
		x++;
	}
	if ((ret < -2147483648) || (ret > 2147483647 && is_neg == 0) ||
		ret > 2147483648)
		return (0);
	if (is_neg == 1 && ret > 0)
		return ((int)(ret *= -1));
	return (ret);
}
