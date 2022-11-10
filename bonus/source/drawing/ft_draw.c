/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:18:25 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/23 13:07:49 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_rectangle(t_data *data, t_index_int first, int color)
{
	t_index_int	last;
	int			tmp;

	first.x *= data->texture.zoom;
	first.y *= data->texture.zoom;
	first.x += data->player.mouve.y;
	first.y += data->player.mouve.x;
	last.x = first.x + data->texture.zoom;
	last.y = first.y + data->texture.zoom;
	while ((double)first.y <= last.y - 1)
	{
		tmp = first.x;
		while (tmp <= last.x - 1)
		{
			if (point_in_circle(data, first.y, tmp))
				ft_put_pixel(first.y, tmp, data, color);
			tmp++;
		}
		first.y++;
	}
}

void	draw_map_2d(t_data *data)
{
	t_index_int	index;
	t_index		player;
	t_index		line;

	index.x = 0;
	player = player_possition(data, 'Y', 'Y');
	line.x = player.x + (20 * cos(data->player.alpha));
	line.y = player.y + (20 * sin(data->player.alpha));
	while (data->map[index.x])
	{
		index.y = 0;
		while (data->map[index.x][index.y])
		{
			if (data->map[index.x][index.y] == '1')
				draw_rectangle(data, index, 0x555555);
			else if (char_in_str(PLAY_EMPT, data->map[index.x][index.y]))
				draw_rectangle(data, index, 0xffffff);
			else if (char_in_str(DOOR, data->map[index.x][index.y]))
				draw_rectangle(data, index, 0x800080);
			index.y++;
		}
		index.x++;
	}
	draw_line(data, player, line, FOV_COLOR);
}

void	draw_to_img(t_data *data)
{
	t_img	*img;
	t_check	check;

	img = data->img;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bit_img, \
	&img->d_size, &img->endian);
	get_player_possition(data);
	check.check = ISWALL;
	draw_3d(data, check);
	if (data->player.view_2d)
		draw_map_2d(data);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	draw_my_wall(t_data *data, double height, t_index ray, t_check check)
{
	t_index	last;
	t_index	first;
	int		color;

	first.x = (HEIGHT / 2) - (height / 2);
	if (first.x < 0)
		first.x = 0;
	last.x = first.x + height;
	if (last.x > HEIGHT)
		last.x = HEIGHT;
	while (first.x <= last.x)
	{
		color = rendering_texcolor(data, first.x, ray, check);
		if (check.check == ISDOOR && color == 0)
			;
		else
			ft_put_pixel(ray.id, first.x, data, color);
		first.x++;
	}
}

void	draw_wall(t_data *data, double ray_distance, t_index ray, t_check check)
{
	double	wall_hight;
	double	distance_pr_pl;

	distance_pr_pl = (WIDTH / 2) / tan(30 * (M_PI / 180));
	ray_distance = ray_distance * \
	(cos(data->ray.angle_ray - data->player.alpha));
	wall_hight = (data->texture.zoom / (ray_distance)) * distance_pr_pl;
	if (check.check == ISWALL)
		data->ray.wall_height = wall_hight;
	else
		data->ray.door_height = wall_hight;
	if (wall_hight > HEIGHT)
		wall_hight = HEIGHT;
	draw_my_wall(data, wall_hight, ray, check);
}
