/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_7.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 14:38:32 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	scrape_spawn(t_data *data, int x, int y)
{
	if (data->resize_map[y][x] == 'N' || data->resize_map[y][x] == 'S'
		|| data->resize_map[y][x] == 'W' || data->resize_map[y][x] == 'E')
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

	data->resize_map = malloc(data->resize_map_size.y * sizeof(char *));
	if (data->resize_map == NULL)
		exit_all(data, 8);
	y = 0;
	while (y < data->resize_map_size.y)
		data->resize_map[y++] = NULL;
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
			scrape_spawn(data, x++, y);
		}
		data->resize_map[y++][x] = '\0';
	}
}

void	count_sprite(t_data *data)
{
	int	x;
	int	y;

	data->sprites_count = 0;
	y = 0;
	while (y < data->resize_map_size.y)
	{
		x = 0;
		while (x < data->resize_map_size.x)
		{
			if (data->resize_map[y][x] == 'X')
				data->sprites_count++;
			x++;
		}
		y++;
	}
	data->sprites = malloc((data->sprites_count) * sizeof(t_xy));
	if (data->sprites == NULL)
		exit_all(data, 8);
}

void	scrape_sprite(t_data *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < data->resize_map_size.y && i < data->sprites_count)
	{
		x = 0;
		while (x < data->resize_map_size.x && i < data->sprites_count)
		{
			if (data->resize_map[y][x] == 'X')
			{
				data->sprites[i].x = x;
				data->sprites[i].y = y;
				data->resize_map[y][x] = '0';
				i++;
			}
			x++;
		}
		y++;
	}
}

void	parse_all(t_data *data, int argc, char **argv)
{
	init_map_data(data);
	check_number_args(data, argc, argv);
	check_extension(data, data->file, ".cub");
	check_dir_map(data);
	scrape_dir_map(data);
	generate_clean_map(data);
	resize_map_y(data);
	resize_map_x(data);
	resize_map(data);
	count_sprite(data);
	scrape_sprite(data);
}
