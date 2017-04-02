/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:22:32 by isy               #+#    #+#             */
/*   Updated: 2016/11/21 01:22:40 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		k;
	char	*result;
	int		save;

	i = 0;
	result = 0;
	if (to_find[0] != '\0')
	{
		while (str[i] != '\0')
		{
			k = 0;
			save = i;
			while (str[i++] == to_find[k++])
				if (to_find[k] == '\0')
					return ((char *)str + save);
			if (to_find[k] != str[i])
				i = (i - k) + 1;
		}
	}
	else if (to_find[0] == '\0')
		result = (char *)str;
	return (result);
}
