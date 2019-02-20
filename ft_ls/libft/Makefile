#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 18:35:31 by mkass             #+#    #+#              #
#    Updated: 2018/08/31 16:20:55 by mkass            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_strdup.c ft_atoi.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strnew.c ft_strdel.c ft_strclr.c ft_memalloc.c ft_memdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_word_count.c ft_word_len.c ft_word_cpy.c ft_nlen.c ft_strrev.c ft_realstrcmp.c ft_realstrncmp.c ft_putnbrendl.c ft_putnbrendl_fd.c ft_strlen_diff.c get_next_line.c ft_putnstr.c ft_putnstr_fd.c ft_fndfile.c ft_exit.c ft_splitlen.c ft_sort.c ft_revsort.c ft_fndpath.c ft_atoi_base.c ft_strbcpy.c ft_strswch.c
HDR = libft.h
FPFSRC = ft_printf.c flags.c conv_init.c conv_chars.c conv_strs.c conv_digits.c conv_trans.c conv_helpers.c conv_others.c
FPFDIR = ft_printf
FPFHDR = ft_printf.h
MK = Makefile
FPFSDIR = $(FPFDIR)/src
FPFSRCS = $(addprefix $(FPFSDIR)/, $(FPFSRC))
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
OBJ += $(FPFSRC:.c=.o)
INC = -I .
FPFINC = -I $(FPFDIR)/includes
EMACSTIL = $(addsuffix ~, $(SRC))
EMACSTIL += $(addsuffix ~, $(FPFSRCS))
EMACSTIL += $(addsuffix ~, $(MK))
EMACSTIL += $(addsuffix ~, $(HDR))
EMACSTIL += $(addprefix $(FPFDIR)/includes/, $(addsuffix ~, $(FPFHDR)))
EMACSHASH = $(addsuffix \#, $(addprefix $(FPFSDIR)/\#, $(FPFSRC)))
EMACSHASH += $(addsuffix \#, $(addprefix \#, $(SRC)))
EMACSHASH += $(addsuffix \#, $(addprefix \#, $(MK)))
EMACSHASH += $(addsuffix \#, $(addprefix \#, $(HDR)))
EMACSHASH += $(addsuffix \#, $(addprefix $(FPFDIR)/includes/\#, $(FPFHDR)))

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(INC) -c $(SRC)
	@gcc $(CFLAGS) $(FPFINC) -c $(FPFSRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@make clean

clean:
	@/bin/rm -f $(OBJ) $(EMACSTIL) $(EMACSHASH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
