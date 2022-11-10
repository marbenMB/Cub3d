/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:50:06 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/10/18 07:23:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_texture_done(t_data *data)
{
	t_texture	value;

	value = data->texture;
	if ((!value.east.path || !value.north.path || !value.south.path \
	|| !value.west.path || value.ceilling.r == -1 || value.floor.r == -1) \
	&& !data->error)
	{
		data->error = ft_strdup("error: texture no complete");
		return (0);
	}
	else
		return (1);
}

void	storage_color(t_data *data, char *line, t_color *variable, int type)
{
	if ((*variable).r == -1)
		data->texture.check++;
	color_data(data, variable, line, type);
}

void	pre_storage_texture(t_data *data, char *line, char **variable)
{
	if (!*variable)
		data->texture.check++;
	(*variable) = ft_strdup(line);
}
