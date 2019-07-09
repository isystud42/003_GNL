/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 04:47:44 by isy               #+#    #+#             */
/*   Updated: 2019/07/09 11:19:36 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**la string du fd
**gestion d'erreurs basiques
**Multi fd faux
**errueur dans procession = errueur
**gestion d'un '\n' intempestif: on donne a line
**la partie de memoire conteenue entre fd et le \n
**on redirige cette partie vers tmp
**on recrée s[fd] à partir de lui même en enlevant sa partie defectueuse
**\n conpris
**-on supprime tmp pour les leaks
*/

/**
 * check if special stuct exists for fd, if not, create, if failed to create, error
 * read in fd for buff_size chars
 * check if any \n or EOF are in it
 * Display until we get to \n or EOF
 * 		if \n cut string and store the rest after \n
 * return value
 * 
 * next call
 * check stored data if any exists.
 * check for \n or EOF
 * Display and cut + value if necessary 
 * 		continue reading until eof or \n
 * display and cut if necessary + store + retrun value
 * */

static t_fd	*check_fd_struct(int fd, t_fd *s_list)
{
	t_fd	*s_fd;
	
	while (s_list->next && s_list->fd != fd)
		s_list = s_list->next;
	if (s_list->fd == fd)
		return (s_list);
	s_fd = (t_fd *)malloc(sizeof(t_fd));
	FD = fd;
	REST = NULL;
	NEXT = NULL;
	s_list->next = s_fd;
	return(s_fd);	
}

/*
** cut and store... come on, it's in the title dum'ass
*/

static int	cut_and_store(t_fd *s_fd, char **buff, char **line, char *p)
{
	if (!s_fd || !buff || !line || !*line || !p)
		return (-1);
	*line = ft_strrealloc(line,(ft_strlen(*line)+(p-*buff)));
	*line = ft_strjoin_free(*line,ft_strsub(*buff,0,p-*buff),2);
	if (!REST)
		REST = ft_strsub(*buff,p-*buff,ft_strlen(p));
	else
		REST = ft_strjoin_free(REST,ft_strsub(*buff,p-*buff,ft_strlen(p)),2);
	return (0);
}

/*
**	The process function is the one that treats buffer reading and cuting + storing
**	data into REST and line. Easy
*/

static int	procession(int fd, char *buff, char **line, t_fd *s_fd)
{
	int		ret;
	char	*pointeur;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if ((pointeur = ft_strchr(buff, '\n')))
		{
			cut_and_store(s_fd, &buff, line, pointeur);
			return (1);
		}
		*line = ft_strjoin_free(*line,buff,1);
	}
	return (0);	
}

/*
**	treat_rest, well... it treats the rest of the buffer precedently not treated
**	verifying if there is a '\n' anywhere in it before cuting it and storing bac
**	the rest of the rest into rest. Yeah i'm very eloquent i know.
**	if no '\n' is found, you just paste the rest into the line and continue process
**	after freeing the rest pointer so you avoid leaks in the last run.
*/

static int	treat_rest(char **line, t_fd *s_fd)
{
	char	*pointeur;
	char	*tmp;

	if (!line || !s_fd)
		return (-1);
	if (REST)
	{
		if ((pointeur = ft_strchr(*line,'\n')))
		{
			*line = ft_strrealloc(line,(ft_strlen(*line)+(pointeur-REST)+1));
			ft_strjoin_free(*line,ft_strsub(REST,0,pointeur-REST),2);
			tmp = REST;
			REST = ft_strsub(REST,(pointeur-*line)+1,ft_strlen(pointeur+1));
			free(tmp);
			return (1);
		}
		else
		{
			*line = ft_strrealloc(line,(ft_strlen(*line)+ft_strlen(REST)+1));
			ft_strjoin_free(*line,s_fd->rest,2);
		}
	}
	return (0);
}

/*
**	get_next_line is basically a function that reads a fd and gets a line into a char*
**	
*/

int			get_next_line(int fd, char **line)
{
	static t_fd	*s_list;
	t_fd		*s_fd;
	int			state;
	char		*buff;
	
	if (!(buff = ft_strnew(BUFF_SIZE)) || fd < 0 || !line 
		|| !(s_fd = check_fd_struct(fd, s_list)))
		return (-1);
	*line = (char *)malloc(sizeof(char));
	if (REST)
	{
		if (treat_rest(line, s_list))
			return (1);
	}
	state = procession(fd,buff,line,s_fd);
	if (state == 0)
		free(buff);
	return (state);
}
