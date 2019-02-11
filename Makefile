# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 11:41:10 by ochaar            #+#    #+#              #
#    Updated: 2018/12/14 15:38:21 by ochaar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_NAME = ft_fdf.c ft_parsing.c ft_map.c ft_bresenham.c ft_putaclic.c \
			ft_error.c ft_map_parallele.c ft_color.c ft_putaclic_par.c

SRC = $(SRC_NAME)

OBJ = $(SRC_NAME:.c=.o)

CFLAGS = -Wall -Werror -Wextra

MLX = minilibx_macos/

FRAMEWORKS = -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc $(CFLAGS) -c $(SRC_NAME)
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -Llibft -lft -I libft -L $(MLX) -lmlx $(FRAMEWORKS)

clean:
	/bin/rm -rf $(OBJ)
	@make -C ./libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean all
