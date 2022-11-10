/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:04:42 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/17 05:10:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_is_wall(t_data *data, double x, double y)
{
	double		zoom;
	int			line;

	zoom = data->texture.zoom;
	if (x > 0 && (x / zoom) < data->texture.map_size.x)
		line = ft_strlen(data->map[(int)(x / zoom)]);
	if (x < 0 || (x / zoom) > data->texture.map_size.x \
	|| y < 0 || (y / zoom) > line)
		return (1);
	if (data->map[(int)(x / zoom)] && \
	data->map[(int)(x / zoom)][(int)(y / zoom)] && \
	char_in_str(LIMIT, data->map[(int)(x / zoom)][(int)(y / zoom)]))
		return (1);
	return (0);
}

void	while_horizontal(t_data *data, t_index inter, t_index step)
{
	double		tmp;
	double		zoom;

	zoom = data->texture.zoom;
	while (1)
	{
		tmp = inter.y;
		if (data->ray.ray_face.up)
			tmp -= 1;
		if (ft_is_wall(data, tmp, inter.x))
		{
			data->ray.found_h_wall = 1;
			data->ray.horizontal_touch.x = inter.x;
			data->ray.horizontal_touch.y = inter.y;
			break ;
		}
		else
		{
			inter.x += step.x;
			inter.y += step.y;
		}
	}
}

void	while_vertical(t_data *data, t_index inter, t_index step)
{
	double		tmp;
	double		zoom;

	zoom = data->texture.zoom;
	while (1)
	{
		tmp = inter.x;
		if (data->ray.ray_face.left)
			tmp -= 1;
		if (ft_is_wall(data, inter.y, tmp))
		{
			data->ray.found_v_wall = 1;
			data->ray.vertical_touch.x = inter.x;
			data->ray.vertical_touch.y = inter.y;
			break ;
		}
		else
		{
			inter.x += step.x;
			inter.y += step.y;
		}
	}
}

void	horizontal_intersection(t_data *data)
{
	t_index	player;
	t_index	h_inter;
	t_index	step;

	player = player_possition(data, 'Y', 'N');
	h_inter.y = data->texture.zoom * ((int)(player.y / data->texture.zoom));
	if (data->ray.ray_face.down)
		h_inter.y += data->texture.zoom;
	h_inter.x = player.x + ((h_inter.y - player.y) / tan(data->ray.angle_ray));
	step.y = data->texture.zoom;
	if (data->ray.ray_face.up)
		step.y *= -1;
	step.x = data->texture.zoom / tan(data->ray.angle_ray);
	if (data->ray.ray_face.left && step.x > 0)
		step.x *= -1;
	if (data->ray.ray_face.right && step.x < 0)
		step.x *= -1;
	while_horizontal(data, h_inter, step);
}

void	vertical_intersection(t_data *data)
{
	t_index	player;
	t_index	step;
	t_index	v_inter;

	player = player_possition(data, 'Y', 'N');
	v_inter.x = data->texture.zoom * ((int)(player.x / data->texture.zoom));
	if (data->ray.ray_face.right)
		v_inter.x += data->texture.zoom;
	v_inter.y = player.y + ((v_inter.x - player.x) * tan(data->ray.angle_ray));
	step.x = data->texture.zoom;
	if (data->ray.ray_face.left)
		step.x *= -1;
	step.y = data->texture.zoom * tan(data->ray.angle_ray);
	if (data->ray.ray_face.up && step.y > 0)
		step.y *= -1;
	if (data->ray.ray_face.down && step.y < 0)
		step.y *= -1;
	while_vertical(data, v_inter, step);
}
