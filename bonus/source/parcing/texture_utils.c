/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:33 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 05:57:50 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	pre_storage_texture(t_data *data, char *line, char **variable)
{
	if (!*variable)
		data->texture.check++;
	(*variable) = ft_strdup(line);
}

int	*opening_texture(t_data *data, char *file, t_index_int *size)
{
	int	*face;

	face = NULL;
	data->img->img = mlx_xpm_file_to_image(data->img->mlx, \
	file, &size->x, &size->y);
	if (data->img->img == NULL)
		data->error = ft_strdup("error in xpm file");
	else
		face = (int *)mlx_get_data_addr(data->img->img, \
		&data->img->bit_img, &data->img->d_size, &data->img->endian);
	return (face);
}

void	if_else2(t_data *data, char *line, int fd, int type)
{
	if (type == D2 && fd > 0)
	{
		pre_storage_texture(data, line, &data->texture.door[1].path);
		data->texture.door[1].xpm_array = opening_texture(data, line, \
		&data->texture.door[1].tex_size);
	}
	else if (type == D3 && fd > 0)
	{
		pre_storage_texture(data, line, &data->texture.door[2].path);
		data->texture.door[2].xpm_array = opening_texture(data, line, \
		&data->texture.door[2].tex_size);
	}
	else if (type == F)
		storage_color(data, line, &data->texture.floor, F);
	else if (type == C)
		storage_color(data, line, &data->texture.ceilling, C);
	else if (!data->error)
		data->error = ft_strdup("error texture not valid");
}

void	else_if(t_data *data, char *line, int fd, int type)
{
	if (type == WE && fd > 0)
	{
		pre_storage_texture(data, line, &data->texture.west.path);
		data->texture.west.xpm_array = opening_texture(data, \
		line, &data->texture.west.tex_size);
	}
	else if (type == EA && fd > 0)
	{
		pre_storage_texture(data, line, &data->texture.east.path);
		data->texture.east.xpm_array = opening_texture(data, line, \
		&data->texture.east.tex_size);
	}
	else if (type == D1 && fd > 0)
	{
		pre_storage_texture(data, line, &data->texture.door[0].path);
		data->texture.door[0].xpm_array = opening_texture(data, line, \
		&data->texture.door[0].tex_size);
	}
	else
		if_else2(data, line, fd, type);
}

void	texture_to_data(t_data *data, char *line, int size, int type)
{
	int	fd;

	line += size;
	while (*line == ' ')
		line += 1;
	line = ft_strtrim(line, "\n");
	fd = open(line, O_RDONLY);
	if (type == NO && fd > 0)
	{
		pre_storage_texture(data, line, &data->texture.north.path);
		data->texture.north.xpm_array = opening_texture(data, \
		line, &data->texture.north.tex_size);
	}
	else if (type == SO && fd > 0)
	{
		pre_storage_texture(data, line, &data->texture.south.path);
		data->texture.south.xpm_array = opening_texture(data, line, \
		&data->texture.south.tex_size);
	}
	else
		else_if(data, line, fd, type);
	free(line);
	close(fd);
}
