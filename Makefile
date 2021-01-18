# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 14:27:32 by ael-bagh          #+#    #+#              #
#    Updated: 2021/01/17 15:59:06 by ael-bagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c additional_check.c bmp.c cub2d_utils.c cub2d.c get_next_line_utils.c get_next_line.c map_manager.c map_utils.c raycasting.c raycasting_utils.c readfile.c readmap.c routingu.c routing_utils.c routing1.c routing2.c sprite_utils.c sprite.c texture_errors.c utils.c walls.c ft_strcmp.c
BONUS = ($SRC)
NAME = cub3D

all: $(NAME)

$(NAME): 
	gcc -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit -o cub3D $(SRC)

bonus:
	gcc -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit -o cub3D $(SRC)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
