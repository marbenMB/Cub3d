/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:52:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/17 08:23:35 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_background(t_data *data, int f_color, int c_color)
{
	int	x;
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			if (y < (HEIGHT / 2))
				ft_put_pixel(x, y, data, c_color);
			else
				ft_put_pixel(x, y, data, f_color);
			x++;
		}
		y++;
	}
}

t_index	player_possition(t_data *data, char zoom, char mouve)
{
	t_index	index;

	index.x = data->player.init_y_player + data->player.player_x;
	index.y = data->player.init_x_player + data->player.player_y;
	if (zoom == 'Y')
	{
		index.x *= data->texture.zoom;
		index.y *= data->texture.zoom;
	}
	if (mouve == 'Y')
	{
		index.x += data->player.mouve.x;
		index.y += data->player.mouve.y;
	}
	return (index);
}

void	draw_3d(t_data *data)
{
	t_index	player;
	t_index	ray;
	int		index;
	double	ray_distance;

	index = 0;
	player = player_possition(data, 'Y', 'Y');
	data->ray.angle_ray = data->player.alpha - (30 * (M_PI / 180));
	draw_background(data, color_converter(&data->texture.floor), \
	color_converter(&data->texture.ceilling));
	while (index < WIDTH)
	{
		facing_ray(data);
		horizontal_intersection(data);
		vertical_intersection(data);
		ray_distance = get_distance(data, &ray);
		draw_wall(data, ray_distance, index, ray);
		data->ray.angle_ray += ((60 * (M_PI / 180)) / WIDTH);
		index++;
	}
}

double	get_distance(t_data *data, t_index *ray)
{
	double	h_distance;
	double	v_distance;
	t_index	player;

	h_distance = 0;
	v_distance = 0;
	player = player_possition(data, 'Y', 'N');
	if (data->ray.found_h_wall)
		h_distance = distance_2_point(player, data->ray.horizontal_touch);
	if (data->ray.found_v_wall)
		v_distance = distance_2_point(player, data->ray.vertical_touch);
	if (h_distance > v_distance)
	{
		(*ray).x = data->ray.vertical_touch.x + data->player.mouve.x;
		(*ray).y = data->ray.vertical_touch.y + data->player.mouve.y;
		data->ray.horizontal_best = 0;
		return (v_distance);
	}
	else
	{
		(*ray).x = data->ray.horizontal_touch.x + data->player.mouve.x;
		(*ray).y = data->ray.horizontal_touch.y + data->player.mouve.y;
		data->ray.horizontal_best = 1;
		return (h_distance);
	}
}

void	ft_put_pixel(int x, int y, t_data *data, int color)
{
	char	*adr;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		adr = data->img->addr + (y * data->img->d_size) \
		+ (x * (data->img->bit_img / 8));
		*((unsigned int *)adr) = color;
	}
}
