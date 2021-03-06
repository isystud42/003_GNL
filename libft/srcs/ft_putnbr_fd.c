/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:20:39 by isy               #+#    #+#             */
/*   Updated: 2016/11/24 19:20:42 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = n;
	if (i == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (i == 2147483647)
		ft_putstr_fd("2147483647", fd);
	if (i == -2147483648 || i == 2147483647)
		return ;
	if (i < 0)
	{
		write(fd, "-", 1);
		i = i * -1;
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	i = i % 10 + '0';
	write(fd, &i, 1);
}
