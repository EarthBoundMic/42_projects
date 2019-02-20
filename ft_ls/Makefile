#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 14:42:58 by mkass             #+#    #+#              #
#    Updated: 2018/10/05 12:39:22 by mkass            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/
MK = Makefile
SDIR = src
HDIR = include
HDR = ft_ls.h

SRC = ft_ls.c lflag.c opendirs.c checkstat.c sort.c extras.c recursion.c checkparams.c flags.c lprintfile.c data_extract.c errors.c wrongname.c data_alloc.c delete.c ex_attr.c ls_color.c

HDRI = -I $(HDIR)/ -I $(LIBFT)
LFTA = -L $(LIBFT) -lft
SRCS = $(addprefix $(SDIR)/, $(SRC))
SRCO = $(SRC:.c=.o)
EMACSTIL = $(addsuffix ~, $(SRCS))
EMACSTIL += $(addsuffix ~, $(MK))
EMACSTIL += $(addprefix $(HDIR)/, $(addsuffix ~, $(HDR)))
EMACSHASH = $(addsuffix \#, $(addprefix $(SDIR)/\#, $(SRC)))
EMACSHASH += $(addsuffix	\#, $(addprefix	\#, $(MK)))
EMACSHASH += $(addsuffix \#, $(addprefix $(HDIR)/\#, $(HDR)))

all: lib $(NAME)

lib:
	@echo "Making libft..."
	@make -C $(LIBFT)

$(NAME):
	@echo "Making $(NAME)..."
	@gcc $(CFLAGS) -c $(SRCS) $(HDRI)
	@gcc $(SRCO) $(LFTA) -o $(NAME)

clean:
	@echo "Cleaning..."
	@/bin/rm -f $(EMACSTIL) $(EMACSHASH)
	@/bin/rm -f $(SRCO)

fclean: clean
	@echo "...deep"
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

sclean: clean
	@echo "...$(NAME)"
	@/bin/rm -f $(NAME)

sre: sclean $(NAME)
	@echo "Remaking $(NAME)"
	@make clean

.PHONY: all clean fclean re sclean sre
