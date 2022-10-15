# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 11:22:32 by mbenbajj          #+#    #+#              #
#    Updated: 2022/10/10 11:22:33 by mbenbajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

NAME_B = cub3d_bonus

CFLAGS = -Wall -Wextra -Werror -Ofast -fsanitize=address -Ofast

CC = cc

FRAM = /Users/marouanebenbajja/MiniLibX/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

########## PATH ########

LIBFT_DIR = libft
SRC_DIR = src
UTILS_DIR = utils/

SRC = $(UTILS_DIR)/get_next_line.c $(UTILS_DIR)/get_next_line_utils.c $(SRC_DIR)/cub3d.c $(SRC_DIR)/read_map.c $(SRC_DIR)/ft_error.c $(SRC_DIR)/draw_2d.c \
		$(SRC_DIR)/key_handling.c $(SRC_DIR)/player_data.c $(SRC_DIR)/utils.c $(SRC_DIR)/ft_check.c $(SRC_DIR)/ray_casting.c $(SRC_DIR)/rendering.c

OBJ = $(SRC:%.c=%.o)

.SILENT:	

all: $(NAME)

$(NAME) : _libft $(OBJ)
	@ $(CC) $(CFLAGS) $(SRC) $(FRAM) $(LIBFT_DIR)/libft.a -o $(NAME) -g
	@printf "\x1b[32m  ✅     Make successfully    💯 ✅\033[0m\n"

%.o : %.c $(SRC) cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

_libft :
	@ make bonus -C $(LIBFT_DIR)

_libft_clean :
	@ make clean -C $(LIBFT_DIR)

_libft_fclean :
	@ make fclean -C $(LIBFT_DIR)

clean : _libft_clean
	@rm -rf $(OBJ)

fclean : _libft_fclean clean
	@rm -rf $(NAME) cub3d.dSYM
	@printf "\x1b[36m  ✅ Make fclean successfully 💯 ✅\033[0m\n"

re : fclean all

.PHONY : re fclean clean all
