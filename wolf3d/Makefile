#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 14:24:50 by mkass             #+#    #+#              #
#    Updated: 2018/08/25 17:00:05 by mkass            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror
MFLAG = make -C
MXFLAGS = -framework OpenGL -framework AppKit
MKF = Makefile
LFTP = libft/
MLXP = minilibx_simple/
W3DP = include/
W3DN = wolf3d.h

SRC = wolf3d.c hooks.c parse.c render.c texture.c extras.c floor.c minimap.c error.c

LFTA = -L $(LFTP) -lft
LFTH = -I $(LFTP)
MLXA = -L $(MLXP) -lmlx $(MXFLAGS)
MLXH = -I $(MLXP)
W3DH = -I $(W3DP)
HEADERS = $(LFTH) $(MLXH) $(W3DH)
LIBS = $(LFTA) $(MLXA)
SRCS = $(addprefix src/, $(SRC))
HDR = $(addprefix $(W3DP), $(W3DN))
OBJ = $(SRC:.c=.o)
TIL = $(addsuffix ~, $(SRCS))
TIL += $(addsuffix ~, $(HDR))
TIL += $(addsuffix ~, $(MKF))
CMPL1 = $(CFLAGS) -c $(SRCS) $(HEADERS)
CMPL2 = $(OBJ) $(LIBS) -o $(NAME)

all: libs $(NAME)

libs:
	@echo "Making Libraries"
	@echo "Making libft.a..."
	@$(MFLAG) $(LFTP)
	@echo "Making libmlx.a..."
	@$(MFLAG) $(MLXP)
	@echo "Use command 'sre' to prevent remaking libraries."

$(NAME):
	@echo "Compiling..."
	@gcc $(CMPL1)
	@echo "Creating wolf3d..."
	@gcc $(CMPL2)
	@echo "Finished"

clean:
	@echo "Cleaning junk..."
	@rm -f $(OBJ) $(TIL)
	@$(MFLAG) $(LFTP) clean

fclean: clean
	@echo "Cleaning programs..."
	@rm -f $(NAME)
	@$(MFLAG) $(LFTP) fclean
	@$(MFLAG) $(MLXP) fclean

re: fclean all

sclean: clean
	@echo "Removing wolf3d..."
	@rm -f $(NAME)

sre: sclean $(NAME)

.PHONY: all libs clean fclean re sclean sre