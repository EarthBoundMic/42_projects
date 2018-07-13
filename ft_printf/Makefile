#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 10:23:46 by mkass             #+#    #+#              #
#    Updated: 2018/07/13 14:00:31 by mkass            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEADER = ft_printf.h
PRFHEADER = -I includes
SDIR = src
MK = Makefile
SRC = ft_printf.c flags.c conv_init.c conv_chars.c conv_strs.c conv_digits.c conv_trans.c conv_helpers.c conv_others.c
SRCS = $(addprefix $(SDIR)/, $(SRC))
SRCO = $(SRC:.c=.o)
EMACSTIL = $(addsuffix ~, $(SRCS))
EMACSTIL += $(addsuffix ~, $(MK))
EMACSTIL += $(addprefix includes/, $(addsuffix ~, $(HEADER)))
EMACSHASH = $(addsuffix \#, $(addprefix $(SDIR)/\#, $(SRC)))
EMACSHASH += $(addsuffix	\#, $(addprefix	\#, $(MK)))
EMACSHASH += $(addsuffix \#, $(addprefix includes/\#, $(HEADER)))

all: $(NAME)

$(NAME):
	@make -C libft/
	@cp $(LIBFT) $(NAME)
	@gcc $(CFLAGS) $(PRFHEADER) -c $(SRCS)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)

clean:
	@rm -f $(SRCO) $(EMACSTIL)
	@rm -f $(EMACSHASH)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re