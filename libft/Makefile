# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idsy <idsy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/20 10:48:13 by isy               #+#    #+#              #
#    Updated: 2019/07/08 18:29:29 by idsy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##FINAL PRODUCT
NAME = libft.a

##FILE INFOS
SRCS_PATH = srcs/
SRCS_FILES = ft_atoi.c ft_atoi_base.c ft_bzero.c ft_deltab.c ft_is_bigger.c\
			ft_is_smaller.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
			ft_isprint.c ft_itoa.c ft_listadd.c ft_lstadd.c ft_lstaddend.c ft_lstdel.c\
			ft_lstdelone.c ft_lstiter.c ft_lstln.c ft_lstmap.c ft_lstnew.c ft_lstshift.c\
			ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
			ft_memmove.c ft_memory_string.c ft_memset.c ft_print_list.c\
			ft_print_words_tables.c ft_putchar.c ft_putchar_fd.c ft_putendl.c\
			ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putnerror.c ft_putstr.c\
			ft_putstr_fd.c ft_strcat.c ft_strcdup.c ft_strchr.c ft_strclr.c ft_strcmp.c\
			ft_strcpy.c ft_strcspn.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
			ft_striteri.c ft_strjoin.c ft_strjoin_free.c ft_strlcat.c ft_strlen.c\
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c\
			ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrealloc.c\
			ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c\
			ft_toupper.c

OBJS_PATH = objs/
OBJS_FILES = $(SRCS_FILES:.c=.o)

INCLUDES_PATH = includes/                     

##VARS
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))
INCLUDES = $(addprefix -I,$(INCLUDES_PATH))

##CC INFOS
CC = gcc
FLAG = -Werror -Wall -Wextra -O2

##RULES
all : $(NAME)
	
$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(FLAG) $(INCLUDES) -o $@ -c $<

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
