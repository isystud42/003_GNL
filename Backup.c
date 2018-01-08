/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 04:47:44 by isy               #+#    #+#             */
/*   Updated: 2017/01/21 04:47:49 by isy              ###   ########.fr       */
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

static int	procession(int const fd, char *buff, char *s)
{
	char	*tmp;
	char	*pointeur;
	int		i;

	i = 0;
	while (!(pointeur = ft_strchr(s, '\n')) &&
		(i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = s;
		s = ft_strjoin(tmp, buff);
ft_putendl("strjoin");
		ft_strdel(&tmp);
	}
	if (i == -1)
		return (-1);
	if (i == 0 && !pointeur)
	{
		if (!ft_strlen(s))
			return (0);
		return (2);
	}
	return (1);
}

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
	static char	*s = NULL;
	char		*tmp;
	int			i;
	char		buff[BUFF_SIZE];

	if (fd < 0 || !line)
		return (-1);
	if (!s)
		s = ft_strnew(1);
	if ((i = procession(fd, buff, s)) == -1)
		return (-1);
	if (i == 0 || i == 2)
	{
		*line = s;
		s = NULL;
		return (i != 0);
	}
	*line = ft_strsub(s, 0, ft_strchr(s, '\n') - s);
ft_putendl("strsub");
	tmp = s;
ft_putendl("patate");
	char	*truc = ft_strchr(s, '\n');
ft_putendl(truc == NULL ? "NULL" : "pas NULL");
	s = ft_strdup(truc + 1);
ft_putendl("strdup");
	ft_strdel(&tmp);
	return (1);
}