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
		ft_putnstr_fd.c ft_fndfile.c ft_exit.c ft_splitlen.c ft_sort.c \
		ft_revsort.c ft_fndpath.c ft_atoi_base.c ft_strbcpy.c ft_strswch.c \
		ft_dtoa.c ft_pow.c ft_ldtoa.c ft_dlen.c ft_ldlen.c
HDR = libft.h ft_colors.h
FPFSRC = ft_printf.c flags.c conv_init.c conv_chars.c conv_strs.c \
			conv_digits.c conv_trans.c conv_helpers.c conv_helpers2.c \
			conv_others.c conv_colors.c color_check.c conv_double.c
FPFDIR = ft_printf/
OBJDIR = build/
SDIR= src/
HDIR = include/
MK = Makefile
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:%.c=$(OBJDIR)%.o)
OBJ += $(FPFSRC:%.c=$(OBJDIR)%.o)
INC = -I $(HDIR)
EMACS = $(SRC:%=$(SDIR)%~)
EMACS += $(MK:%=%~)
EMACS += $(HDR:%=%$(HDIR)%~)
EMACS += $(FPFSRC:%=$(FPFDIR)%~)
EMACS += $(SRC:%=$(SDIR)\\\#%\\\#)
EMACS += $(MK:%=\\\#%\\\#)
EMACS += $(HDR:%=$(HDIR)\\\#%\\\#)
EMACS += $(FPFSRC:%=$(FPFDIR)\\\#%\\\#)

all: build $(NAME)

build:
	@mkdir -p build

$(OBJDIR)%.o: $(SDIR)%.c
	@echo "Making $@..."
	@gcc $(CFLAGS) $(INC) -c $< -o $@
	@ar rc $(NAME) $@
	
$(OBJDIR)%.o: $(FPFDIR)%.c
	@echo "Making $@..."
	@gcc $(CFLAGS) $(INC) -c $< -o $@
	@ar rc $(NAME) $@
	
$(NAME): $(OBJ)
	@echo "Making $(NAME)..."
	@ranlib $(NAME)

clean:
	@echo "Cleaning..."
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(EMACS)

fclean: clean
	@echo "...Deep"
	@/bin/rm -rf build
	@/bin/rm -f $(NAME)

re: fclean all
