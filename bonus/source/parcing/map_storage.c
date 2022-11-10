/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:50:06 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 15:26:21 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	check_texture_done(t_data *data)
{
	t_texture	value;

	value = data->texture;
	if ((!value.east.path || !value.north.path || !value.south.path \
	|| !value.west.path || !value.door[0].path || !value.door[1].path \
	|| !value.door[2].path || value.ceilling.r == -1 \
	|| value.floor.r == -1) \
	&& !data->error)
	{
		data->error = ft_strdup("error: texture no complete");
		return (0);
	}
	else
		return (1);
}

void	pre_while(t_data *data, char *line, int *index, int *i_map)
{
	if (!empty_line(line) || data->texture.read_in_map == 1)
	{
		if ((*index) < TEXTURE_LINE && !data->error)
		{
			texture_storage(data, line);
			(*index)++;
		}
		else if (check_texture_done(data) && !data->error)
		{
			if (empty_line(line) && !data->error)
				data->texture.is_empty_line = 1;
			else if (data->texture.is_empty_line == 1)
				data->error = ft_strdup("empty line in map");
			else
			{
				data->texture.read_in_map = 1;
				data->map[(*i_map)] = ft_strdup(line);
				(*i_map)++;
			}
		}
	}
	data->map[(*i_map)] = NULL;
	free(line);
	line = NULL;
}

void	while_loop(t_data *data, int fd)
{
	char	*line;
	int		index;
	int		i_map;

	index = 0;
	i_map = 0;
	data->map = (char **)malloc(sizeof(char **) \
	* (data->texture.map_size.x + 1));
	while (!data->error)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		pre_while(data, line, &index, &i_map);
	}
}

void	update_v_wall(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '2' && data->map[x][y + 1] == '3')
				data->map[x][y] = '3';
			else if (data->map[x][y] == '3' && data->map[x][y + 1] == '2')
				data->map[x + 1][y] = '2';
			y++;
		}
		x++;
	}
}

void	read_map(t_data *data, char **av)
{
	int		fd;
	int		index;

	init_struct(data);
	if (data->texture.zoom < 1)
		data->error = ft_strdup("error in zoom value");
	data->img->mlx = mlx_init();
	data->img->win = mlx_new_window(data->img->mlx, WIDTH, HEIGHT, "B_CUB3D");
	map_size(data, av[1]);
	fd = open(av[1], O_RDONLY);
	index = 0;
	if (fd > 0 && file_type(av[1], ".cub") && !data->error)
	{
		while_loop(data, fd);
		close_map(data);
		update_v_wall(data);
	}
	else if (!data->error)
		data->error = ft_strdup("file not valid");
	close(fd);
}
