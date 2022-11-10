/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:32:35 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 09:14:53 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define STEP 0.3
# define ALPHA 0.1
# define RAY 150
# define FOV_ANGLE 60
# define TEXTURE_LINE 9

# define FOV_COLOR 0x977950

// FOV_ANGLE 60 * M_PI / 180
/////////////// PARCING ///////////////////////

void		read_map(t_data *data, char **av);
void		color_data(t_data *data, \
t_color *data_color, char *color, int type);
void		texture_to_data(t_data *data, char *line, int size, int type);
void		texture_storage(t_data *data, char *line);
int			file_type(char *file, char *type);
void		ft_free_tab(char **tab);
void		map_size(t_data *data, char *file);
void		init_struct(t_data *data);
int			empty_line(char *line);
void		close_map(t_data *data);
int			check_circle(char **map, int x, int y);
void		init_face(t_data *data);
int			char_in_str(char *str, char c);
int			ft_close_x(t_data *data);
void		while_closed(t_data *data, char **map, int x, int *y);
void		texture_storage(t_data *data, char *line);

/////////////  DRAWING ///////////////////////

void		ft_hook(t_data *data);
int			ft_movekey(t_data *data);
void		drawing(t_data *data);
void		draw_to_img(t_data *data);
void		ft_put_pixel(int x, int y, t_data *data, int color);
void		draw_circle(t_data *data);
void		check_key(t_data *data);
void		draw_3d(t_data *data, t_check check);
void		horizontal_intersection(t_data *data);
void		vertical_intersection(t_data *data);
void		draw_line(t_data *data, t_index first, t_index last, int color);
double		distance_2_point(t_index first, t_index last);
t_distance	get_distance(t_data *data, t_index *ray);
double		normalizeangle(double angle);
void		facing_ray(t_data *data);
t_index		player_possition(t_data *data, char zoom, char mouve);
int			is_v_wall(t_data *data, double x, double y, t_index step);
int			ft_is_wall(t_data *data, double x, double y);
void		draw_circle(t_data *data);
int			point_in_circle(t_data *data, double y, double x);
void		get_player_possition(t_data *data);
double		ft_diff(double x, double y);
void		storage_color(t_data *data, char *line, \
t_color *variable, int type);

////// wall////
void		draw_wall(t_data *data, double ray_distance, \
t_index ray, t_check check);
int			color_converter(t_color *color);

//	*******	Casting Utils : 
t_door		*lst_new(int found, t_index inter);
void		add_front(t_door **lst, t_door *new);
t_door		*lst_last(t_door **lst);
void		ft_free_list(t_data *data);
int			rendering_texcolor(t_data *data, int tex_x, \
t_index ray, t_check check);
t_index		add_step(t_index inter, t_index step);
int			ft_mouse_release(int mouse, int x, int y, t_data *data);
int			mouvment_mouse(int x, int y, t_data *data);
double		best_wall_distance(t_data *data, t_index *ray, t_index player);
void		door_distance(t_data *data, t_index player);
int			ft_check_wall(t_data *data, double x_plus, double y_plus);
void		movement_key(t_data *data, t_index step);

#endif