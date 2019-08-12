/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 04:47:44 by isy               #+#    #+#             */
/*   Updated: 2019/08/12 21:48:48 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_fd	*check_fd_struct(int fd, t_fd **s_list)
{
	t_fd	*s_fd;

	if (!*s_list)
	{
		(*s_list) = (t_fd *)malloc(sizeof(t_fd));
		(*s_list)->fd = fd;
		(*s_list)->rest = NULL;
		(*s_list)->next = NULL;
		return (*s_list);
	}
	s_fd = *s_list;
	while (NEXT && (FD != fd))
		s_fd = NEXT;
	if (FD == fd)
		return (s_fd);
	else
	{
		if (!(NEXT = (t_fd *)malloc(sizeof(t_fd))))
			return (0);
		s_fd = NEXT;
		FD = fd;
		REST = NULL;
		NEXT = NULL;
		return (s_fd);
	}
}

static int	cut_and_store(t_fd *s_fd, char *buff, char **line, char *p)
{
	char	*string_holder;

	if (!s_fd || !buff || !line || !p)
		return (-1);
	if (!*line)
	{
		if (!(*line = malloc(sizeof(char))))
			return (-1);
	}
	if (!(string_holder = ft_strsub(buff, 0, p - buff)))
		return (-1);
	*line = ft_strjoin_free(*line, string_holder, 3);
	if (p[1] && !(REST = ft_strdup(p + 1)))
		return (-1);
	return (0);
}

/*
**	The process function is the one that treats buffer reading and
**	cuting + storing data into REST and line. Easy
*/

static int	procession(int fd, char *buff, char **line, t_fd *s_fd)
{
	int		ret;
	char	*ptr;
	int		line_len;

	line_len = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			if ((cut_and_store(s_fd, buff, line, ptr)))
				return (-1);
			return (1);
		}
		if (!(*line = ft_strjoin_free(*line, buff, 1)))
			return (-1);
	}
	return (0);
}

/*
**	treat_rest, well... it treats the rest of the buffer precedently not treated
**	verifying if there is a '\n' anywhere in it before cuting it and storing bac
**	the rest of the rest into rest. Yeah i'm very eloquent i know.
**	if no '\n' is found, you just paste the rest into the line and continue
**	process after freeing the rest pointer so you avoid leaks in the last run.
*/

static int	treat_rest(char **line, t_fd *s_fd)
{
	char	*ptr;
	char	*tmp;

	if (REST)
	{
		if ((ptr = ft_strchr(REST, '\n')))
		{
			tmp = REST;
			if (!(*line = ft_strsub(tmp, 0, ptr - tmp)))
				return (-1);
			if ((!(REST = ft_strsub(REST, ptr - tmp + 1,
			ft_strlen(REST) - (ptr - tmp + 1)))))
				return (-1);
			free(tmp);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(REST)))
				return (-1);
			free(REST);
		}
	}
	return (0);
}

/*
**	get_next_line is basically a function that reads a fd and gets
**	a line into a char*
*/

int			get_next_line(int fd, char **line)
{
	static t_fd	*s_list;
	t_fd		*s_fd;
	char		buff[BUFF_SIZE];

	if (fd < 0 || !line || !(s_fd = check_fd_struct(fd, &s_list)))
		return (-1);
	if (REST)
	{
		DEB
		if (treat_rest(line, s_fd))
			return (1);
	}
	return(procession(fd, buff, line, s_fd));
}
