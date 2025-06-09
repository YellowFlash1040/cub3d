/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_9.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/09 18:18:20 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	count_sprite(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->resize_map_size.y)
	{
		x = 0;
		while (x < data->resize_map_size.x)
		{
			if (data->resize_map[y][x] == 'X')
				data->sprite_no++;
			x++;
		}
		y++;
	}
	data->sprite = malloc((data->sprite_no) * sizeof(t_xy));
	if (data->sprite == NULL)
		exit_all(data, 8);
}

void	scrape_sprite(t_data *data)
{
	int	x;
	int	y;
	int	i;

	count_sprite(data);
	y = 0;
	i = 0;
	while (y < data->resize_map_size.y && i < data->sprite_no)
	{
		x = 0;
		while (x < data->resize_map_size.x && i < data->sprite_no)
		{
			if (data->resize_map[y][x] == 'X')
			{
				data->sprite[i].x = x;
				data->sprite[i].y = y;
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
	check_input(data, argc, argv);
	check_dir_map(data);
	scrape_dir_map(data);
	resize_map(data);
	scrape_sprite(data);
}
