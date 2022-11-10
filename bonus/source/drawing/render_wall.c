/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:02:05 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 05:20:07 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	*get_texture_side(t_data *data, t_check check)
{
	t_door	*last;

	if (check.check == ISDOOR)
	{
		last = lst_last(&data->lst_door);
		if (last)
		{
			if ((last->distance / data->texture.zoom) <= 1.5 \
			&& check.last == LAST)
				return (data->texture.door[0].xpm_array);
			else if ((last->distance / data->texture.zoom) <= 2 \
			&& check.last == LAST)
				return (data->texture.door[1].xpm_array);
			else
				return (data->texture.door[2].xpm_array);
		}
	}
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.up)
		return (data->texture.north.xpm_array);
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.down)
		return (data->texture.south.xpm_array);
	if (data->ray.horizontal_best == 0 && data->ray.ray_face.right)
		return (data->texture.east.xpm_array);
	else
		return (data->texture.west.xpm_array);
}

t_index_int	get_texture_size(t_data *data, t_check check)
{
	t_door	*last;

	if (check.check == ISDOOR)
	{
		last = lst_last(&data->lst_door);
		if (last)
		{
			if ((last->distance / data->texture.zoom) <= 1.5 \
			&& check.last == LAST)
				return (data->texture.door[0].tex_size);
			else if ((last->distance / data->texture.zoom) <= 2 \
			&& check.last == LAST)
				return (data->texture.door[1].tex_size);
			else
				return (data->texture.door[2].tex_size);
		}
	}
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.up)
		return (data->texture.north.tex_size);
	if (data->ray.horizontal_best == 1 && data->ray.ray_face.down)
		return (data->texture.south.tex_size);
	if (data->ray.horizontal_best == 0 && data->ray.ray_face.right)
		return (data->texture.east.tex_size);
	else
		return (data->texture.west.tex_size);
}

int	get_best_inter(t_data *data, t_check check)
{
	int	check_best;

	if (check.check == ISDOOR)
		check_best = data->actual_head->horizontal_best;
	else
		check_best = data->ray.horizontal_best;
	return (check_best);
}

double	get_height(t_data *data, t_check check)
{
	if (check.check == ISDOOR)
		return (data->ray.door_height);
	else
		return (data->ray.wall_height);
}

int	rendering_texcolor(t_data *data, int tex_x, t_index ray, t_check check)
{
	t_index		tex;
	t_index_int	texture_size;
	int			*side;
	double		height;
	int			check_best;

	check_best = get_best_inter(data, check);
	side = get_texture_side(data, check);
	texture_size = get_texture_size(data, check);
	height = get_height(data, check);
	tex.x = tex_x + ((height / 2) - (HEIGHT / 2));
	if (tex.x < 0)
		tex.x = 0;
	tex.x *= (double)texture_size.y / height;
	tex.x = floor(tex.x);
	tex.x *= texture_size.x;
	tex.y = ray.x;
	if (check_best == 0)
		tex.y = ray.y;
	tex.y /= data->texture.zoom;
	tex.y -= floor(tex.y);
	tex.y *= texture_size.x;
	return (side[(int)tex.x + (int)tex.y]);
}
