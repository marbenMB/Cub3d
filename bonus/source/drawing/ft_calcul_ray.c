/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:04:42 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/23 06:17:47 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_is_wall_door(t_data *data, double x, double y)
{
	double		zoom;
	int			line;

	zoom = data->texture.zoom;
	if (x > 0 && (x / zoom) < data->texture.map_size.x)
		line = ft_strlen(data->map[(int)(x / zoom)]);
	if (x < 0 || (x / zoom) > data->texture.map_size.x \
	|| y < 0 || (y / zoom) > line)
		return (1);
	if (data->map[(int)(x / zoom)] \
	&& data->map[(int)(x / zoom)][(int)(y / zoom)] \
	&& char_in_str(LIMIT, data->map[(int)(x / zoom)][(int)(y / zoom)]))
		return (1);
	if (char_in_str(DOOR, data->map[(int)(x / zoom)][(int)(y / zoom)]))
		return (2);
	return (0);
}

void	while_horizontal(t_data *data, t_index inter, t_index step)
{
	double		tmp;

	while (1)
	{
		tmp = inter.y;
		if (data->ray.ray_face.up)
			tmp -= 1;
		if (ft_is_wall_door(data, tmp, inter.x) == 2)
		{
			data->ray.door.found_h = 1;
			data->ray.door.horizontal_touch.x = inter.x;
			data->ray.door.horizontal_touch.y = inter.y;
			add_front(&data->lst_door, lst_new(1, inter));
		}
		if (ft_is_wall_door(data, tmp, inter.x) == 1)
		{
			data->ray.found_h_wall = 1;
			data->ray.horizontal_touch.x = inter.x;
			data->ray.horizontal_touch.y = inter.y;
			break ;
		}
		else
			inter = add_step(inter, step);
	}
}

void	while_vertical(t_data *data, t_index inter, t_index step)
{
	double		tmp;

	while (1)
	{
		tmp = inter.x;
		if (data->ray.ray_face.left)
			tmp -= 1;
		if (ft_is_wall_door(data, inter.y, tmp) == 2)
		{
			data->ray.door.found_v = 1;
			data->ray.door.vertical_touch.x = inter.x;
			data->ray.door.vertical_touch.y = inter.y;
			add_front(&data->lst_door, lst_new(2, inter));
		}
		if (ft_is_wall_door(data, inter.y, tmp) == 1)
		{
			data->ray.found_v_wall = 1;
			data->ray.vertical_touch.x = inter.x;
			data->ray.vertical_touch.y = inter.y;
			break ;
		}
		else
			inter = add_step(inter, step);
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
