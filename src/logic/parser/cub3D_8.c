/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_8.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/05/30 22:02:36 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_map(t_data *data)
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
			{
				check_enclosure(data, x, y);
				stop = flood_fill(data, x, y, stop);
			}
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

void	resize_map_size_loop(t_data *data)
{
	int	x;
	int	y;

	y = data->start.y;
	while (y < data->end.y)
	{
		x = 0;
		while (x < data->clean_map_size.x)
		{
			if (ft_isspace(data->clean_map[y][x]) == false
				&& x < data->start.x)
				data->start.x = x;
			if (ft_isspace(data->clean_map[y][x]) == false
				&& x > data->end.x)
				data->end.x = x;
			x++;
		}
		y++;
	}
}

void	resize_map_size(t_data *data)
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
	data->start.x = data->clean_map_size.x;
	data->end.x = 0;
	resize_map_size_loop(data);
	data->end.x++;
	data->resize_map_size.x = data->end.x - data->start.x;
}

void	scrape_spawn(t_data *data, int x, int y)
{
	if (data->resize_map[y][x] == 'N'
		|| data->resize_map[y][x] == 'S'
		|| data->resize_map[y][x] == 'W'
		|| data->resize_map[y][x] == 'E')
	{
		data->resize_spawn.x = x;
		data->resize_spawn.y = y;
		data->resize_spawn_dir = data->resize_map[y][x];
		data->resize_map[y][x] = '0';
	}
}

void	resize_map(t_data *data)
{
	int	x;
	int	y;

	clean_map(data);
	resize_map_size(data);
	data->resize_map = malloc(data->resize_map_size.y * sizeof(char *));
	if (data->resize_map == NULL)
		exit_all(data, 8);
	y = 0;
	while (y < data->resize_map_size.y)
	{
		data->resize_map[y] = malloc(data->resize_map_size.x + 1);
		if (data->resize_map[y] == NULL)
			exit_all(data, 8);
		x = 0;
		while (x < data->resize_map_size.x)
		{
			data->resize_map[y][x]
				= data->clean_map[y + data->start.y][x + data->start.x];
			scrape_spawn(data, x, y);
			x++;
		}
		data->resize_map[y][x] = '\0';
		y++;
	}
}
