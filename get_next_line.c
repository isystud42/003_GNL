/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 04:47:44 by isy               #+#    #+#             */
/*   Updated: 2019/06/21 11:33:29 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**tant qu'on lit bien des choses et que dans ce qu'on a lu il n'y a pas de \n
**on ferme le buff
**on attribue l'ancienne partie lue à tmp
**et on l'asocie à la nouvelle
**puis on free ce qu'on venait de faire
**si le read a echoué -> erreur (if numero 1)
**si on a rien lu et qu'on a pas trouvé de \n (if numero 2)
**on attribue à line ce qu'on a lu jusqu'à present
*/

// static int	procession(int const fd, char *buff, char *s[fd])
// {
// 	char	*tmp;
// 	char	*pointeur;
// 	int		i;

// 	i = 0;
// 	while (!(pointeur = ft_strchr(s[fd], '\n')) &&
// 		(i = read(fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		buff[i] = '\0';
// 		tmp = s[fd];
// 		s[fd] = ft_strjoin(tmp, buff);
// 		ft_strdel(&tmp);
// 	}
// 	if (i == -1)
// 		return (-1);
// 	if (i == 0 && !pointeur)
// 	{
// 		if (!ft_strlen(s[fd]))
// 			return (0);
// 		return (2);
// 	}
// 	return (1);
// }

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
**on supprime tmp pour les leaks
*/

int			get_next_line(int const fd, char **line)
{
	static char	*s[666];
	char		*tmp;
	int			i;
	char		*buff;

	if (!(buff = ft_strnew(BUFF_SIZE)) || fd < 0 || !line)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	if ((i = procession(fd, buff, s)) == -1)
		return (-1);
	ft_strdel(&buff);
	if (i == 0 || i == 2)
	{
		*line = s[fd];
		s[fd] = NULL;
		if (i == 0)
			return (0);
		return (1);
	}
	*line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd]);
	tmp = s[fd];
	s[fd] = ft_strdup(ft_strchr(s[fd], '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}


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

static int	cut_and_store(t_fd *s_fd, char *buff, char **line, char *p)
{
	if (!s_fd || !buff || !line || !*line || !p)
		return (-1);
	//copy currentl line
	//free ex pointeur and resize to desired size
	//copy ex line in, put new content in + /0
	//cut string, store rest of it in s_fd->rest
	return (0);
}

static int	procession(int fd, char *buff, char **line, t_fd *s_fd)
{
	int		ret;
	char	*pointeur;

	while (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (pointeur = ft_strchr(buff, '\n'))
		{
			cut_and_store(s_fd, buff, line, pointeur);
			return (1);
		}
		//join buff to line
	}
	//join buff to line
	return (0);	
}

static int	treat_rest()
{
	if ()
	{
		
	}
	free(s_fd->next);
	return (0);
}

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
	if (s_fd->rest)
	{
		if (treat_rest(s_list, line))
			return (1);
	}
	state = procession(fd,buff,line,s_fd);
	return (state);
}


/*
** check le rest, si il n'est pas vide, on ne continue pas a lire
** si il n'est pas vide , on le prcours jusqu'au \n et on le coupe plus line
** Si pas de backslash n on l'ajoute a 100% et on passe a la suite
**	si il est fini on lis et on check pour un \n
**	  si on a un backslash n on cut et on stocke
*/
