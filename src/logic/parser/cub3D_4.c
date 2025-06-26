/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 14:31:27 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_map_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] != '\n' && data->line[i] != '\0')
	{
		if (data->line[i] != ' ' && data->line[i] != 'X' && data->line[i] != '0'
			&& data->line[i] != '1' && data->line[i] != '2'
			&& data->line[i] != 'N' && data->line[i] != 'S'
			&& data->line[i] != 'W' && data->line[i] != 'E')
			exit_all(data, 16);
		else if (data->line[i] == 'N' || data->line[i] == 'S'
			|| data->line[i] == 'W' || data->line[i] == 'E')
		{
			if (data->spawn == false)
				data->spawn = true;
			else
				exit_all(data, 15);
		}
		i++;
		if (i > data->map_x)
			data->map_x = i;
	}
}

void	check_map(t_data *data)
{
	if (empty_line(data->line) == true)
	{
		if (data->map_y != 0)
			data->temp_y++;
		return ;
	}
	data->map_y += (data->temp_y + 1);
	data->temp_y = 0;
	check_map_line(data);
}

void	check_dir_map(t_data *data)
{
	reset_dir(data);
	data->map_x = 0;
	data->map_y = 0;
	data->temp_y = 0;
	data->spawn = false;
	open_fd(data, data->file, &data->fd);
	while (true)
	{
		data->line = get_next_line(data->fd);
		if (data->line == NULL)
			break ;
		else if (check_dir_complete(data) == false)
			check_dir(data);
		else if (check_dir_complete(data) == true)
			check_map(data);
		free_null((void **)&data->line);
	}
	if (data->spawn == false)
		exit_all(data, 17);
	close_fd(data, &data->fd);
}

void	init_temp_clean_map(t_data *data)
{
	int	y;

	data->temp_map = malloc(data->clean_map_size.y * sizeof(char *));
	data->clean_map = malloc(data->clean_map_size.y * sizeof(char *));
	if (data->temp_map == NULL || data->clean_map == NULL)
		exit_all(data, 8);
	y = 0;
	while (y < data->clean_map_size.y)
	{
		data->temp_map[y] = NULL;
		data->clean_map[y] = NULL;
		y++;
	}
	y = 0;
	while (y < data->clean_map_size.y)
	{
		data->temp_map[y] = malloc(data->clean_map_size.x + 1);
		data->clean_map[y] = malloc(data->clean_map_size.x + 1);
		if (data->temp_map[y] == NULL || data->clean_map[y] == NULL)
			exit_all(data, 8);
		y++;
	}
}

bool	scrape_wall(t_data *data, int d, int i)
{
	int	j;

	if (data->line[i] != data->dir[d][0] || data->line[i + 1] != data->dir[d][1]
		|| ft_isspace(data->line[i + 2]) == false)
		return (false);
	i += 3;
	while (ft_isspace(data->line[i]) == true)
		i++;
	j = 0;
	while (ft_isspace(data->line[i + j]) == false)
		j++;
	if (d == 4 || d == 5)
		free_null((void **)&data->clean_wall[d]);
	data->clean_wall[d] = malloc(j + 1);
	if (data->clean_wall[d] == NULL)
		exit_all(data, 8);
	j = 0;
	while (ft_isspace(data->line[i]) == false)
		data->clean_wall[d][j++] = data->line[i++];
	data->clean_wall[d][j] = '\0';
	data->dir_check[d] = true;
	return (true);
}
