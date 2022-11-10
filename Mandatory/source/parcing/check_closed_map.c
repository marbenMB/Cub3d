/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:57:52 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/18 09:11:36 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_v_wall(t_data *data, char **map, int x, int y)
{
	if (!data->error)
	{
		if (map[x - 1][y] == '1' && map[x][y - 1] == '1')
		{
			if (map[x][y] == '0')
				map[x][y] = '2';
			if (map[x - 1][y - 1] == '0' && map[x][y] == '2')
				map[x - 1][y - 1] = '3';
			if (map[x - 1][y - 1] == '0' && map[x][y] == '3')
				map[x - 1][y - 1] = '2';
		}
		if (map[x + 1][y] == '1' && map[x][y - 1] == '1')
		{
			if (map[x + 1][y - 1] == '0')
				map[x + 1][y - 1] = '3';
			if (map[x][y] == '0')
				map[x][y] = '2';
		}
	}
}

void	check_player(t_data *data, char **map, int x, int y)
{
	if (data->player.n_player > 1 && !data->error)
		data->error = ft_strdup("error : multiple players");
	else if (char_in_str(PLAY_EMPT, map[x][y]))
	{
		if (check_circle(map, x, y))
			data->error = ft_strdup("error : map no closed");
		if (char_in_str(PLAYER, map[x][y]))
		{
			data->player.face = map[x][y];
			data->player.n_player++;
		}
	}
	check_v_wall(data, map, x, y);
}

void	while_closed(t_data *data, char **map, int x, int *y)
{
	if (char_in_str(WHITE_SPACE, map[x][*y]))
		data->error = ft_strdup("error white-space in the map");
	else if (char_in_str(PLAY_EMPT, map[x][*y]))
		check_player(data, map, x, *y);
	else if (char_in_str(WALL_SPAC, map[x][*y]))
		;
	else if (!data->error)
		data->error = ft_strdup("invalid caracter in map");
	(*y)++;
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
