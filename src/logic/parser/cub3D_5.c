/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_5.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/05/30 21:53:57 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reset_dir(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->dir_check[i] = false;
		i++;
	}
}

void	init_map(t_data *data)
{
	int	y;

	data->temp_map = malloc(data->clean_map_size.y * sizeof(char *));
	if (data->temp_map == NULL)
		exit_all(data, 8);
	data->clean_map = malloc(data->clean_map_size.y * sizeof(char *));
	if (data->clean_map == NULL)
		exit_all(data, 8);
	y = 0;
	while (y < data->clean_map_size.y)
	{
		data->temp_map[y] = malloc(data->clean_map_size.x + 1);
		if (data->temp_map[y] == NULL)
			exit_all(data, 8);
		data->clean_map[y] = malloc(data->clean_map_size.x + 1);
		if (data->clean_map[y] == NULL)
			exit_all(data, 8);
		y++;
	}
}

void	scrape_texture(t_data *data, int w, int i)
{
	int		x;

	x = 0;
	while (ft_isspace(data->line[i + x]) == false)
		x++;
	data->clean_wall[w] = malloc(x + 1);
	if (data->clean_wall[w] == NULL)
		exit_all(data, 8);
	x = 0;
	while (ft_isspace(data->line[i + x]) == false)
	{
		data->clean_wall[w][x] = data->line[i + x];
		x++;
	}
	data->clean_wall[w][x] = '\0';
}

bool	scrape_dir_wall_loop(t_data *data, int w)
{
	int	i;

	i = 0;
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (data->line[i] == data->dir[w][0] && data->line[i + 1] == data->dir[w][1]
		&& ft_isspace(data->line[i + 2]))
	{
		i += 3;
		while (ft_isspace(data->line[i]) == true)
			i++;
		scrape_texture(data, w, i);
		data->dir_check[w] = true;
		return (true);
	}
	return (false);
}

bool	scrape_dir_wal(t_data *data)
{
	int	w;

	w = 0;
	while (w < 4)
	{
		if (scrape_dir_wall_loop(data, w) == true)
			return (true);
		w++;
	}
	return (false);
}
