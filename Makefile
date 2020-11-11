# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 18:51:43 by ljerrica          #+#    #+#              #
#    Updated: 2020/11/04 19:34:43 by ljerrica         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = clang

CFLAGS =  -Wall -Wextra -Werror

MLX = mlxOpenGL/

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER =	cub3d.h \

SRC =		cub3d \
			keycodes \
			pixaddr \
			sprite_1 \
			sprite_2 \
			walls \
			beginning \
			get_next_line \
			split \
			val_int \
			words_count \
			parser_01 \
			parser_02 \
			parser_03 \
			player_pos \
			pars_all \
			fill_map \
			save \

FIL = $(addsuffix .c, $(addprefix files/, $(SRC)))

OBJ = $(FIL:.c=.o)

BIN = $(addsuffix .o, $(SRC))


.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -f screen.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(FIL) files/$(HEADER)
