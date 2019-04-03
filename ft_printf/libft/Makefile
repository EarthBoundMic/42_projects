#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 18:35:31 by mkass             #+#    #+#              #
#    Updated: 2018/07/05 16:01:43 by mkass            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_strdup.c ft_atoi.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_strcmp.c ft_strncmp.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_memalloc.c ft_memdel.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
		ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstdel.c \
		ft_lstiter.c ft_lstmap.c ft_word_count.c ft_word_len.c ft_word_cpy.c \
		ft_nlen.c ft_strrev.c ft_realstrcmp.c ft_realstrncmp.c ft_putnbrendl.c \
		ft_putnbrendl_fd.c ft_strlen_diff.c get_next_line.c ft_putnstr.c \
		ft_putnstr_fd.c ft_fndfile.c ft_exit.c ft_splitlen.c ft_dtoa.c \
		ft_ldtoa.c ft_dlen.c ft_ldlen.c ft_pow.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
EMACS = $(SRC:%=%~)
EMACS += $(SRC:%=\\\#%\\\#)
INC = -I .

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) $(INC) -c $<
	ar rc $(NAME) $@
	
$(NAME): $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(TIL)
	/bin/rm -f $(HASH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
