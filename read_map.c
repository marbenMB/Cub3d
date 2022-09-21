/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:13:15 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/19 20:03:41 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    get_parced_map(t_data *data, char *file_name)
{
    int fd;
	(void)data;
	
    fd = open(file_name, O_RDONLY, 0666);
    if (fd < 0)
		error_exit("+>	File cannot be openned <+", FAIL);
	map_height(fd, data);
	fd = open(file_name, O_RDONLY, 0666);
	read_map(fd, data);
}

void	map_height(int fd, t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_width(data, line);
		data->map_height += 1;
		free(line);
	}
	close(fd);
}

void	map_width(t_data *data, char *line)
{
	int	lenght;

	lenght = ft_strlen(line);
	if (lenght > data->map_width)
		data->map_width = lenght;
}

void	read_map(int fd, t_data *data)
{
	char	*line;
	int		idx;
	(void)line;

	idx = 0;
	data->map = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->map)
		error_exit("+>	Fatal Error	<+", FAIL);
	line = get_next_line(fd);
	while (line)
	{
		data->map[idx] = ft_strdup(line);
		free(line);
		idx++;
		line = get_next_line(fd);
	}
	close(fd);
}