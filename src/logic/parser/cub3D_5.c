/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_5.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 14:31:35 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

uint8_t	atouint8(t_data *data, int i)
{
	uint8_t	x;

	x = 0;
	while (ft_isdigit(data->line[i]) == true)
		x = x * 10 + data->line[i++] - 48;
	return (x);
}

int	scrape_floor_loop(t_data *data, int f, int i, char c)
{
	if (c == 'r')
		data->clean_floor[f - 6].r = atouint8(data, i);
	else if (c == 'g')
		data->clean_floor[f - 6].g = atouint8(data, i);
	else if (c == 'b')
		data->clean_floor[f - 6].b = atouint8(data, i);
	while (ft_isdigit(data->line[i]) == true)
		i++;
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (data->line[i] == ',')
		i++;
	while (ft_isspace(data->line[i]) == true)
		i++;
	return (i);
}

bool	scrape_floor(t_data *data, int d, int i)
{
	if (data->line[i] != data->dir[d][0]
		|| ft_isspace(data->line[i + 1]) == false)
		return (false);
	i += 2;
	while (ft_isspace(data->line[i]) == true)
		i++;
	i = scrape_floor_loop(data, d, i, 'r');
	i = scrape_floor_loop(data, d, i, 'g');
	i = scrape_floor_loop(data, d, i, 'b');
	data->dir_check[d] = true;
	return (true);
}

void	scrape_dir(t_data *data)
{
	int	d;
	int	i;

	if (empty_line(data->line) == true)
		return ;
	d = 0;
	while (d < 8)
	{
		i = 0;
		while (ft_isspace(data->line[i]) == true)
			i++;
		if (d < 6 && scrape_wall(data, d, i) == true)
			return ;
		else if (d >= 6 && scrape_floor(data, d, i) == true)
			return ;
		d++;
	}
}

void	scrape_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] != '\n' && data->line[i] != '\0')
	{
		if (ft_isspace(data->line[i]) == true)
			data->temp_map[data->map_y][i] = ' ';
		else
			data->temp_map[data->map_y][i] = data->line[i];
		if (data->line[i] == 'N' || data->line[i] == 'S' || data->line[i] == 'W'
			|| data->line[i] == 'E')
			data->clean_map[data->map_y][i] = data->line[i];
		else
			data->clean_map[data->map_y][i] = ' ';
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
