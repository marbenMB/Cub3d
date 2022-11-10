/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:32:35 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 16:37:25 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "structs.h"
# include "../../libft/libft.h"
# include "utils.h"
# include "macros.h"
# include <mlx.h>
# include <math.h>

# define FLOOR  0
# define CEILLING 0
# define WIDTH 1600
# define HEIGHT 1200
# define STEP 0.2
# define ALPHA 0.1
# define RAY 150
# define FOV_ANGLE 60

// # define FOV_COLOR 0x977950

/////////////// PARCING ///////////////////////

void	read_map(t_data *data, char **av);
int		check_texture_done(t_data *data);
void	pre_storage_texture(t_data *data, char *line, char **variable);
void	storage_color(t_data *data, char *line, t_color *variable, int type);
void	color_data(t_data *data, t_color *data_color, char *color, int type);
void	texture_to_data(t_data *data, char *line, int size, int type);
void	texture_storage(t_data *data, char *line);
int		file_type(char *file, char *type);
void	ft_free_tab(char **tab);
void	map_size(t_data *data, char *file);
void	init_struct(t_data *data);
int		empty_line(char *line);
void	close_map(t_data *data);
int		check_circle(char **map, int x, int y);
void	init_face(t_data *data);
int		char_in_str(char *str, char c);
int		ft_close_x(t_data *data);

/////////////  DRAWING ///////////////////////

void	ft_hook(t_data *data);
void	draw_to_img(t_data *data);
void	ft_put_pixel(int x, int y, t_data *data, int color);
void	check_key(t_data *data);
void	draw_3d(t_data *data);
void	horizontal_intersection(t_data *data);
void	vertical_intersection(t_data *data);
double	distance_2_point(t_index first, t_index last);
double	get_distance(t_data *data, t_index *ray);
double	normalizeangle(double angle);
void	facing_ray(t_data *data);
t_index	player_possition(t_data *data, char zoom, char mouve);
void	draw_wall(t_data *data, double ray_distance, int ray_id, t_index ray);
int		color_converter(t_color *color);

#endif