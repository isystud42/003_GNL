/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:27:02 by idsy              #+#    #+#             */
/*   Updated: 2019/06/27 10:28:50 by idsy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Basically, une fonction qui fait le strjoin mais en renvoyant de la memoire
**	fraiche avec un free des anciens components.
*/

static void	free_str(char **s1, char **s2, int flag)
{
	if (flag == 1)
		free(*s1);
	if (flag == 2)
		free(*s2);
	if (flag == 3)
	{
		free(*s1);
		free(*s2);
	}
}

char		*ft_strjoin_free(char *s1, char *s2, int flag)
{
	char	*new;
	char	*s_s1;
	char	*s_s2;
	char	*s_new;

	s_s1 = s1;
	s_s2 = s2;
	if (!(s1 && s2 && *s1 && *s2 &&
		(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	s_new = new;
	while (*s_s1)
		*s_new++ = *s_s1++;
	while (*s_s2)
		*s_new++ = *s_s2++;
	*s_new = '\0';
	free_str(&s1,&s2,flag);
	return (new);
}


// ##PROJECT
// NAME = libft.a
// CC = gcc
// CFLAGS = -Wall -Wextra -Werror

// ##DIRECTORIES
// SRC_PATH = srcs/
// OBJ_PATH = objs/
// INC_PATH = includes/

// ##FILES
// SRC_NAME  = ft_set_lst.c ft_find_charset.c ft_strsplit_lst.c ft_putstr_fd.c\
// 			ft_strsplit_whitespaces_lst.c ft_strsplit_charset_lst.c ft_strclr.c\
// 			ft_print_words_table.c ft_strncmp.c ft_strsplit_charset.c ft_atoi.c\
// 			ft_strlen.c ft_strcmp.c ft_set_list.c ft_strcpy.c ft_putnbr_endl.c\
// 			ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_putchar_endl.c\
// 			ft_memmove.c ft_memchr.c ft_memcmp.c ft_putnbr_fd.c ft_lstdelone.c\
// 			ft_itoa.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
// 			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strdup.c ft_isalpha.c\
// 			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
// 			ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
// 			ft_putstr.c ft_lstnew.c ft_lstdel.c ft_lstadd.c ft_putchar_fd.c\
// 			ft_lstiter.c ft_strrealloc.c ft_array_realloc.c ft_del_array.c\
// 			ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strsplit.c\
// 			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
// 			ft_putendl_fd.c ft_memccpy.c ft_putendl.c ft_putchar.c ft_putnbr.c\
// 			ft_lstmap.c ft_strrealloc_more.c ft_strdup_c.c get_next_line.c\
// 			ft_debug.c ft_itoa_base.c ft_atoi_base.c
// OBJ_NAME = $(SRC_NAME:.c=.o)

// ##VARIABLES
// SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
// OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
// INC = $(addprefix -I,$(INC_PATH))


// ##RULES
// all: $(NAME)

// $(NAME): $(OBJ)
// 	@ar rc $(NAME) $(OBJ)
// 	@ranlib $(NAME)
// 	@echo "\n\033[1;34m [$(NAME)] %.o\t\t\033[1;32m[Created]\033[0m"
// 	@echo "\033[1;34m [$(NAME)] $(NAME)\t\033[1;32m[Created]\033[0m"


// $(OBJ_PATH)%.o: $(SRC_PATH)%.c
// 	@mkdir -p $(OBJ_PATH)
// 	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
// 	@echo "\033[31m█\033[0m\c"

// clean:
// 	@rm -f $(OBJ)
// 	@rmdir $(OBJ_PATH) 2> /dev/null || true
// 	@echo "\033[1;34m [$(NAME)] %.o\t\t\033[1;31m[Removed]\033[0m"

// fclean: clean
// 	@rm -rf $(NAME)
// 	@echo "\033[1;34m [$(NAME)] $(NAME)\t\033[1;31m[Removed]\033[0m"

// re: fclean all

// .PHONY: all, clean, fclean, re
