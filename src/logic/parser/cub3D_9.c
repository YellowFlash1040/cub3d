/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:39:23 by rbom              #+#    #+#             */
/*   Updated: 2025/06/13 14:48:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

	count_sprite(data);
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
	check_input(data, argc, argv);
	check_dir_map(data);
	scrape_dir_map(data);
	resize_map(data);
	scrape_sprite(data);
}
