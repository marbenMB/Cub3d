/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:46:36 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/24 07:42:31 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	texture_storage(t_data *data, char *line)
{
	while (*line == ' ')
		line += 1;
	if (!ft_strncmp(line, "NO ", 3))
		texture_to_data(data, line, 3, NO);
	else if (!ft_strncmp(line, "SO ", 3))
		texture_to_data(data, line, 3, SO);
	else if (!ft_strncmp(line, "WE ", 3))
		texture_to_data(data, line, 3, WE);
	else if (!ft_strncmp(line, "EA ", 3))
		texture_to_data(data, line, 3, EA);
	else if (!ft_strncmp(line, "F ", 2))
		texture_to_data(data, line, 2, F);
	else if (!ft_strncmp(line, "C ", 2))
		texture_to_data(data, line, 2, C);
	else if (!ft_strncmp(line, "D1 ", 2))
		texture_to_data(data, line, 2, D1);
	else if (!ft_strncmp(line, "D2 ", 2))
		texture_to_data(data, line, 2, D2);
	else if (!ft_strncmp(line, "D3 ", 2))
		texture_to_data(data, line, 2, D3);
	else if (!data->error)
		data->error = ft_strdup("error: texture no complete");
}

void	close_map(t_data *data)
{
	t_index_int	index;
	char		**map;

	map = data->map;
	index.x = 0;
	while (!data->error && map[index.x])
	{
		index.y = 0;
		while (map[index.x][index.y] && !data->error)
			while_closed(data, map, index.x, &index.y);
		index.x++;
	}
	init_face(data);
	if (data->player.n_player == 0 && !data->error)
		data->error = ft_strdup("error : no player");
}

void	color_data(t_data *data, t_color *data_color, char *color, int type)
{
	char	**tab;
	int		index;

	index = 0;
	tab = ft_split(color, ',');
	while (tab[index])
		index++;
	if (index == 3)
	{
		if (type == F)
			(*data_color).t = FLOOR;
		else if (type == C)
			(*data_color).t = CEILLING;
		(*data_color).r = ft_atoi(tab[0]);
		(*data_color).g = ft_atoi(tab[1]);
		(*data_color).b = ft_atoi(tab[2]);
	}
	else if (!data->error)
		data->error = ft_strdup("error color no valid");
	if (((*data_color).r < 0 || (*data_color).g < 0
			|| (*data_color).b < 0 || (*data_color).r > 255
			|| (*data_color).g > 255 || (*data_color).b > 255) \
			&& !data->error)
		data->error = ft_strdup("error color no valid");
	ft_free_tab(tab);
}

void	storage_color(t_data *data, char *line, t_color *variable, int type)
{
	if ((*variable).r == -1)
		data->texture.check++;
	color_data(data, variable, line, type);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("\x1b[31m🚫 Error in arguments 🚫\033[0m\n");
		return (1);
	}
	else if (WIDTH > 2880 || HEIGHT > 1550)
	{
		printf("\x1b[31m🚫 Error in window size 🚫\033[0m\n");
		return (1);
	}
	else
		read_map(&data, av);
	if (data.error)
	{
		printf("\x1b[31m Error \033[0m\n");
		printf("\x1b[31m🚫 %s 🚫\033[0m\n", data.error);
	}
	else
	{
		draw_to_img(&data);
		ft_hook(&data);
	}
	return (0);
}
