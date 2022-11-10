/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:46:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:34 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	pre_while(t_data *data, char *line, int *index, int *i_map)
{
	if (!empty_line(line) || data->texture.read_in_map == 1)
	{
		if ((*index) < 6 && !data->error)
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
	data->img->win = mlx_new_window(data->img->mlx, WIDTH, HEIGHT, "Cub3D");
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || WIDTH > 2880 || HEIGHT > 1550)
	{
		printf("\x1b[31m🚫 Error initial 🚫\033[0m\n");
		return (1);
	}
	else
		read_map(&data, av);
	if (data.error)
	{
		printf("\x1b[31m Error \033[0m\n");
		printf("\x1b[31m🚫 %s 🚫\033[0m\n", data.error);
		return (1);
	}
	else
	{
		draw_to_img(&data);
		ft_hook(&data);
	}
	return (0);
}
