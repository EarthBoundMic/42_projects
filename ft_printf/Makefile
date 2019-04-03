#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 10:23:46 by mkass             #+#    #+#              #
#    Updated: 2018/10/18 13:31:27 by mkass            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEADER = ft_printf.h ft_colors.h
PRFHEADER = -I includes
SDIR = src/
INC = includes/
MK = Makefile
SRC = ft_printf.c flags.c conv_init.c conv_chars.c conv_strs.c conv_digits.c \
		conv_trans.c conv_helpers.c conv_others.c conv_helpers2.c colors.c \
		color_check.c conv_double.c

SRCO = $(SRC:.c=.o)
EMACS = $(SRC:%=$(SDIR)%~)
EMACS += $(MK:%=%~)
EMACS += $(HEADER:%=$(HDR)%~)
EMACS += $(SRC:%=$(SDIR)\\\#%\\\#)
EMACS += $(MK:%=\\\#%\\\#)
EMACS += $(HEADER:%=$(INC)\\\#%\\\#)

all: $(NAME)

%.o: $(SDIR)%.c
	gcc $(CFLAGS) $(PRFHEADER) -c $<

$(NAME): $(SRCO)
	make -C libft/
	libtool -static -o $(NAME) $(LIBFT) $(SRCO)
	ranlib $(NAME)

clean:
	/bin/rm -f $(SRCO)
	/bin/rm -f $(EMACS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
