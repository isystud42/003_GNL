/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:12:56 by isy               #+#    #+#             */
/*   Updated: 2016/12/21 12:03:52 by isy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 666

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_fd
{
	int			fd;
	int			start;
	t_list		*lst;
	struct s_fd	*next;
}					t_fd;

int					get_next_line(int const fd, char **line);

#endif
