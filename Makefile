NAME = cub3d

NAME_B = cub3d_bonus

CFLAGS = -Wall -Wextra -Werror -Ofast #-fsanitize=address

CC = cc

########## PATH ########

PARC_DIR = ./Mandatory/source/parcing

DRAW_DIR = ./Mandatory/source/drawing

UTIL_DIR = ./Mandatory/source/utils

LIBFT_DIR = ./libft

PARC_DIR_B = ./bonus/source/parcing

DRAW_DIR_B = ./bonus/source/drawing

UTIL_DIR_B = ./bonus/source/utils

########################

SRCS = ${PARC_DIR}/cub3d.c ${PARC_DIR}/map_storage.c ${PARC_DIR}/texture_utils.c ${PARC_DIR}/map_utils.c ${PARC_DIR}/check_closed_map.c ${PARC_DIR}/check_circle.c ${PARC_DIR}/ft_init_var.c\
		${DRAW_DIR}/ft_fov.c ${DRAW_DIR}/ft_key.c ${DRAW_DIR}/handling_key_data.c ${DRAW_DIR}/ft_calcul_ray.c ${DRAW_DIR}/draw_circle.c ${DRAW_DIR}/render_wall.c\
		${UTIL_DIR}/get_next_line.c ${UTIL_DIR}/get_next_line_utils.c

SRCS_BONUS = ${PARC_DIR_B}/cub3d.c ${PARC_DIR_B}/map_storage.c ${PARC_DIR_B}/texture_utils.c ${PARC_DIR_B}/map_utils.c ${PARC_DIR_B}/check_closed_map.c ${PARC_DIR_B}/check_circle.c ${PARC_DIR_B}/ft_init_var.c\
		${DRAW_DIR_B}/ft_window.c ${DRAW_DIR_B}/ft_draw.c ${DRAW_DIR_B}/ft_fov.c ${DRAW_DIR_B}/ft_key.c ${DRAW_DIR_B}/handling_key_data.c ${DRAW_DIR_B}/ft_calcul_ray.c ${DRAW_DIR_B}/draw_circle.c ${DRAW_DIR_B}/render_wall.c ${DRAW_DIR_B}/utils_file.c\
		${UTIL_DIR_B}/get_next_line.c ${UTIL_DIR_B}/get_next_line_utils.c ${DRAW_DIR_B}/casting_utils.c

OBJS = $(SRCS:%.c=%.o)
OBJS_B = $(SRCS_BONUS:%.c=%.o)

all: $(NAME)

_libft :
	@make -C $(LIBFT_DIR)

$(NAME) : $(OBJS) _libft
	@rm -rf $(OBJS_B) $(NAME_B)
	@make bonus -C $(LIBFT_DIR)
	@$(CC)  $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "\x1b[32m  ✅     Make successfully    💯 ✅\033[0m\n"

%.o:%.c $(SRCS)
	@$(CC) $(CFLAGS) -c $<  -o  $@

bonus: $(OBJS_B)
	@rm -rf $(OBJS) $(NAME)
	@ make bonus -C $(LIBFT_DIR)
	@$(CC)  $(CFLAGS) $(OBJS_B) $(LIBFT_DIR)/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
	@printf "\x1b[32m  ✅     Make Bonus successfully    💯 ✅\033[0m\n"

%.o:%.c $(SRCS_BONUS)
	@$(CC) $(CFLAGS) -c $<  -o  $@

clean : 
	@rm -rf $(OBJS) $(OBJS_B)
	@make fclean -C $(LIBFT_DIR)

fclean : clean
	@rm -rf $(NAME) $(NAME_B)
	@printf "\x1b[36m  ✅ Make fclean successfully 💯 ✅\033[0m\n"

re : fclean all

.PHONY : all clean fclean re
