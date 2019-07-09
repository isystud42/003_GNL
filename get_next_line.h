/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:12:56 by isy               #+#    #+#             */
/*   Updated: 2019/07/09 10:44:31 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 666
# define REST	s_fd->rest
# define FD		s_fd->fd
# define NEXT 	s_fd->next

# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct		s_fd
{
	int			fd;
	char		*rest;
	struct s_fd	*next;
}					t_fd;

int					get_next_line(int const fd, char **line);

#endif
