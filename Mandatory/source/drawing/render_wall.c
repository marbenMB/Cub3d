/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:02:05 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/18 07:21:45 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	*get_texture_side(t_data *data)
{
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.up)
		return (data->texture.north.xpm_array);
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.down)
		return (data->texture.south.xpm_array);
	if (data->ray.horizontal_best == 0 && data->ray.ray_face.right)
		return (data->texture.east.xpm_array);
	else
		return (data->texture.west.xpm_array);
}

t_index_int	get_texture_size(t_data *data)
{
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.up)
		return (data->texture.north.tex_size);
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.down)
		return (data->texture.south.tex_size);
	if (data->ray.horizontal_best == 0 && data->ray.ray_face.right)
		return (data->texture.east.tex_size);
	else
		return (data->texture.west.tex_size);
}

int	rendering_texcolor(t_data *data, int tex_x, t_index ray)
{
	t_index		tex;
	t_index_int	i_tex;
	t_index_int	texture_size;
	double		zoom_factor;
	int			*side;

	side = get_texture_side(data);
	texture_size = get_texture_size(data);
	zoom_factor = (double)texture_size.y / data->ray.wall_height;
	tex.x = tex_x + ((data->ray.wall_height / 2) - (HEIGHT / 2));
	if (tex.x < 0)
		tex.x = 0;
	tex.x *= zoom_factor;
	tex.x = floor(tex.x);
	tex.x *= texture_size.x;
	tex.y = ray.x - data->player.mouve.x;
	if (data->ray.horizontal_best == 0)
		tex.y = ray.y - data->player.mouve.y;
	tex.y /= data->texture.zoom;
	tex.y -= floor(tex.y);
	tex.y *= texture_size.x;
	i_tex.x = (int)tex.x;
	i_tex.y = (int)tex.y;
	return (side[i_tex.x + i_tex.y]);
}

void	draw_my_wall(t_data *data, double wall_height, int ray_id, t_index ray)
{
	t_index	last;
	t_index	first;
	int		color;

	first.x = (HEIGHT / 2) - (wall_height / 2);
	if (first.x < 0)
		first.x = 0;
	first.y = ray_id * 1;
	last.x = first.x + wall_height;
	if (last.x > HEIGHT)
		last.x = HEIGHT;
	last.y = first.y + 1;
	while (first.x <= last.x)
	{
		color = rendering_texcolor(data, first.x, ray);
		ft_put_pixel(ray_id, first.x, data, color);
		first.x++;
	}
}

void	draw_wall(t_data *data, double ray_distance, int ray_id, t_index ray)
{
	double	wall_hight;
	double	distance_pr_pl;

	distance_pr_pl = (WIDTH / 2) / tan(30 * (M_PI / 180));
	ray_distance = ray_distance * \
	(cos(data->ray.angle_ray - data->player.alpha));
	wall_hight = (data->texture.zoom / (ray_distance)) * distance_pr_pl;
	data->ray.wall_height = wall_hight;
	if (wall_hight > HEIGHT)
		wall_hight = HEIGHT;
	draw_my_wall(data, wall_hight, ray_id, ray);
}
