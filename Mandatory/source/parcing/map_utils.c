/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:32:01 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/09/08 11:44:35 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	file_type(char *file, char *type)
{
	char	*text;

	text = ft_strrchr(file, '.');
	if (ft_strcmp(text, type))
		return (0);
	else
		return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_col(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	ft_check_map_size(t_data *data, t_index_int count)
{
	if (count.x == 0)
		data->error = ft_strdup("Empty file");
	else if (count.x < 6)
		data->error = ft_strdup("No map");
	else
	{
		data->texture.map_size.x = count.x - 6;
		data->texture.map_size.y = count.y;
	}
}

void	map_size(t_data *data, char *file)
{
	int			fd;
	char		*line;
	t_index_int	count;

	count.x = 0;
	count.y = 0;
	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			if (!empty_line(line))
			{
				count.x++;
				if (count.y < count_col(line))
					count.y = count_col(line);
			}
			free(line);
		}
		ft_check_map_size(data, count);
	}
	close (fd);
}
