NAME = cub3d

NAME_B = cub3d_bonus

CFLAGS = -Wall -Wextra -Werror -Ofast -fsanitize=address

CC = cc

FRAM = -lmlx -framework OpenGL -framework AppKit

########## PATH ########

LIBFT_DIR = libft
UTILS_DIR = utils/

SRC = $(UTILS_DIR)/get_next_line.c $(UTILS_DIR)/get_next_line_utils.c cub3d.c read_map.c ft_error.c #draw_2d.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : _libft $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(FRAM) $(LIBFT_DIR)/libft.a -o $(NAME) -g
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
	@rm -rf $(NAME)
	@printf "\x1b[36m  ✅ Make fclean successfully 💯 ✅\033[0m\n"

re : fclean all

.PHONY : re fclean clean all
