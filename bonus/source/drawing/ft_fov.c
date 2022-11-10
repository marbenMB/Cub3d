/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:52:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 05:26:43 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
				ft_put_pixel(x, y, data, f_color);
			else
				ft_put_pixel(x, y, data, c_color);
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

t_check	update_check(t_door *head)
{
	t_check	check;

	check.check = ISDOOR;
	check.last = 0;
	if (!head->next->next)
		check.last = LAST;
	return (check);
}

void	ft_draw_door(t_data *data, t_distance distance, int index)
{
	t_door	*head;
	t_check	check;

	head = data->actual_head;
	while (head->next)
	{
		check = update_check(head);
		if ((head->found_h || head->found_v) \
		&& (head->distance < distance.wall))
		{
			if (head->found_h)
			{
				head->horizontal_touch.id = index;
				draw_wall(data, head->distance, \
				head->horizontal_touch, check);
			}
			else
			{
				head->vertical_touch.id = index;
				draw_wall(data, head->distance, \
				head->vertical_touch, check);
			}
		}
		head = head->next;
	}
}

void	draw_3d(t_data *data, t_check check)
{
	t_index		player;
	t_index		wall;
	int			index;
	t_distance	ray_distance;

	index = 0;
	player = player_possition(data, 'Y', 'Y');
	data->ray.angle_ray = data->player.alpha - (30 * (M_PI / 180));
	draw_background(data, color_converter(&data->texture.floor), \
	color_converter(&data->texture.ceilling));
	while (index < WIDTH)
	{
		data->lst_door = (t_door *)ft_calloc(1, sizeof(t_door));
		facing_ray(data);
		horizontal_intersection(data);
		vertical_intersection(data);
		ray_distance = get_distance(data, &wall);
		data->actual_head = data->lst_door;
		wall.id = index;
		draw_wall(data, ray_distance.wall, wall, check);
		ft_draw_door(data, ray_distance, index);
		ft_free_list(data);
		data->ray.angle_ray += ((60 * (M_PI / 180)) / WIDTH);
		index++;
	}
}
