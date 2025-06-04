/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:39:23 by rbom              #+#    #+#             */
/*   Updated: 2025/06/04 18:46:27 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	scrape_map_loop(t_data *data, int i)
{
	if (ft_isspace(data->line[i]) == true)
		data->temp_map[data->map_y][i] = ' ';
	else
		data->temp_map[data->map_y][i] = data->line[i];
	if (data->line[i] == 'N'
		|| data->line[i] == 'S'
		|| data->line[i] == 'W'
		|| data->line[i] == 'E')
		data->clean_map[data->map_y][i] = data->line[i];
	else
		data->clean_map[data->map_y][i] = ' ';
}

void	scrape_map(t_data *data)
{
	int	i;

	if (empty_line(data->line) == true && data->map_y == 0)
		return ;
	i = 0;
	while (data->line[i] != '\n' && data->line[i] != '\0')
	{
		scrape_map_loop(data, i);
		i++;
	}
	while (i < data->clean_map_size.x)
	{
		data->temp_map[data->map_y][i] = ' ';
		data->clean_map[data->map_y][i] = ' ';
		i++;
	}
	data->temp_map[data->map_y][i] = '\0';
	data->clean_map[data->map_y][i] = '\0';
	data->map_y += 1;
}

void	scrape_dir_map(t_data *data)
{
	reset_dir(data);
	data->clean_map_size.x = data->map_x;
	data->clean_map_size.y = data->map_y;
	data->map_y = 0;
	initialize_map(data);
	open_fd(data, data->file, &data->fd, 4);
	while (true)
	{
		data->line = get_next_line(data->fd);
		if (data->line == NULL)
			break ;
		else if (check_dir_complete(data) == false)
			scrape_dir(data);
		else if (check_dir_complete(data) == true)
			scrape_map(data);
		free_null((void **)&data->line);
	}
	close_fd(data, data->fd, 5);
}

void	check_enclosure(t_data *data, int x, int y)
{
	if (x == 0 || x == data->clean_map_size.x - 1
		|| y == 0 || y == data->clean_map_size.y - 1
		|| data->temp_map[y][x - 1] == ' '
		|| data->temp_map[y][x + 1] == ' '
		|| data->temp_map[y - 1][x] == ' '
		|| data->temp_map[y + 1][x] == ' ')
		exit_all(data, 21);
}

bool	flood_fill(t_data *data, int x, int y, bool stop)
{
	if (data->clean_map[y][x - 1] != ' '
		&& data->clean_map[y][x + 1] != ' '
		&& data->clean_map[y - 1][x] != ' '
		&& data->clean_map[y + 1][x] != ' ')
		return (stop);
	if (data->clean_map[y][x - 1] == ' ')
		data->clean_map[y][x - 1] = data->temp_map[y][x - 1];
	if (data->clean_map[y][x + 1] == ' ')
		data->clean_map[y][x + 1] = data->temp_map[y][x + 1];
	if (data->clean_map[y - 1][x] == ' ')
		data->clean_map[y - 1][x] = data->temp_map[y - 1][x];
	if (data->clean_map[y + 1][x] == ' ')
		data->clean_map[y + 1][x] = data->temp_map[y + 1][x];
	return (false);
}
