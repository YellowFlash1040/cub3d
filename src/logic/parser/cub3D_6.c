/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:39:23 by rbom              #+#    #+#             */
/*   Updated: 2025/06/13 14:48:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	atouint8(t_data *data, int f, int i, char c)
{
	if (c == 'r')
	{
		data->clean_floor[f - 4].r = 0;
		while (ft_isdigit(data->line[i]) == true)
			data->clean_floor[f - 4].r
				= data->clean_floor[f - 4].r * 10 + data->line[i++] - 48;
	}
	else if (c == 'g')
	{
		data->clean_floor[f - 4].g = 0;
		while (ft_isdigit(data->line[i]) == true)
			data->clean_floor[f - 4].g
				= data->clean_floor[f - 4].g * 10 + data->line[i++] - 48;
	}
	else if (c == 'b')
	{
		data->clean_floor[f - 4].b = 0;
		while (ft_isdigit(data->line[i]) == true)
			data->clean_floor[f - 4].b
				= data->clean_floor[f - 4].b * 10 + data->line[i++] - 48;
	}
}

int	scrape_loop_skip(t_data *data, int f, int i, char c)
{
	atouint8(data, f, i, c);
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

bool	scrape_dir_floor_loop(t_data *data, int f)
{
	int	i;

	i = 0;
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (data->line[i] == data->dir[f][0] && ft_isspace(data->line[i + 1]))
	{
		i += 2;
		while (ft_isspace(data->line[i]) == true)
			i++;
		i = scrape_loop_skip(data, f, i, 'r');
		i = scrape_loop_skip(data, f, i, 'g');
		i = scrape_loop_skip(data, f, i, 'b');
		data->dir_check[f] = true;
		return (true);
	}
	return (false);
}

bool	scrape_dir_floor(t_data *data)
{
	int	f;

	f = 4;
	while (f < 6)
	{
		if (scrape_dir_floor_loop(data, f) == true)
			return (true);
		f++;
	}
	return (false);
}

void	scrape_dir(t_data *data)
{
	if (empty_line(data->line) == true)
		return ;
	else if (scrape_dir_wal(data) == true)
		return ;
	else if (scrape_dir_floor(data) == true)
		return ;
}
