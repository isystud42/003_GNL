/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clgirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 02:23:54 by clgirard          #+#    #+#             */
/*   Updated: 2016/08/14 20:15:22 by clgirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		ft_negative(char str)
{
	int sign;

	if (str == '-')
		sign = -1;
	else
		sign = 1;
	return (sign);
}

int				ft_atoi(const char *str)
{
	int integer;
	int i;
	int sign;

	sign = 1;
	i = 0;
	integer = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
	|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = ft_negative(str[i]);
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		integer = integer * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (integer);
}
