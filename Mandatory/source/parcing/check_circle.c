/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_circle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:51:20 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/08 12:59:09 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_north(char **map, int x, int y)
{
	if ((x - 1) >= 0)
	{
		if (map[x - 1][y] && (map[x - 1][y] != ' '))
			return (1);
	}
	return (0);
}

int	check_south(char **map, int x, int y)
{
	if (map[x + 1] && map[x + 1][y] && (map[x + 1][y] != ' '))
		return (1);
	return (0);
}

int	check_west(char **map, int x, int y)
{
	if ((y - 1) >= 0)
	{
		if (map[x][y - 1] && map[x][y - 1] != ' ')
			return (1);
	}
	return (0);
}

int	check_east(char **map, int x, int y)
{
	if (map[x][y + 1] && map[x][y + 1] != ' ' && map[x][y + 1] != '\n')
		return (1);
	else
		return (0);
}

int	check_circle(char **map, int x, int y)
{
	if (!check_north(map, x, y) || !check_south(map, x, y) \
		|| !check_west(map, x, y) || !check_east(map, x, y))
		return (1);
	return (0);
}
