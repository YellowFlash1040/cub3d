/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_6.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 14:31:42 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	scrape_dir_map(t_data *data)
{
	reset_dir(data);
	data->clean_map_size.x = data->map_x;
	data->clean_map_size.y = data->map_y;
	data->map_y = 0;
	init_temp_clean_map(data);
	open_fd(data, data->file, &data->fd);
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
	close_fd(data, &data->fd);
}

bool	flood_fill(t_data *data, int x, int y, bool stop)
{
	if (x == 0 || x == data->clean_map_size.x - 1
		|| y == 0 || y == data->clean_map_size.y - 1
		|| data->temp_map[y][x - 1] == ' ' || data->temp_map[y][x + 1] == ' '
		|| data->temp_map[y - 1][x] == ' ' || data->temp_map[y + 1][x] == ' ')
		exit_all(data, 18);
	if (data->clean_map[y][x - 1] != ' ' && data->clean_map[y][x + 1] != ' '
		&& data->clean_map[y - 1][x] != ' ' && data->clean_map[y + 1][x] != ' ')
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

void	generate_clean_map(t_data *data)
{
	int		x;
	int		y;
	bool	stop;

	y = 0;
	stop = true;
	while (y < data->clean_map_size.y)
	{
		x = 0;
		while (x < data->clean_map_size.x)
		{
			if (data->clean_map[y][x] != ' ' && data->clean_map[y][x] != '1')
				stop = flood_fill(data, x, y, stop);
			x++;
		}
		y++;
		if (y == data->clean_map_size.y && stop == false)
		{
			y = 0;
			stop = true;
		}
	}
}

void	resize_map_y(t_data *data)
{
	int	y;

	y = 0;
	while (empty_line(data->clean_map[y]) == true && y < data->clean_map_size.y)
		y++;
	data->start.y = y;
	while (y < data->clean_map_size.y && !empty_line(data->clean_map[y]))
		y++;
	data->end.y = y;
	data->resize_map_size.y = data->end.y - data->start.y;
}

void	resize_map_x(t_data *data)
{
	int	x;
	int	y;

	data->start.x = data->clean_map_size.x;
	data->end.x = 0;
	y = data->start.y;
	while (y < data->end.y)
	{
		x = 0;
		while (x < data->clean_map_size.x)
		{
			if (ft_isspace(data->clean_map[y][x]) == false && x < data->start.x)
				data->start.x = x;
			if (ft_isspace(data->clean_map[y][x]) == false && x > data->end.x)
				data->end.x = x;
			x++;
		}
		y++;
	}
	data->end.x++;
	data->resize_map_size.x = data->end.x - data->start.x;
}
