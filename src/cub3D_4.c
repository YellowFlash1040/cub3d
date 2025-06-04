/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/05/22 19:34:03 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_dir_floor(t_data *data)
{
	int	i;
	int	f;

	i = 0;
	f = 4;
	while (f < 6)
	{
		if (check_dir_floor_loop(data, f) == true)
			return (true);
		f++;
	}
	return (false);
}

void	check_dir(t_data *data)
{
	if (empty_line(data->line) == true)
		return ;
	else if (check_dir_wal(data) == true)
		return ;
	else if (check_dir_floor(data) == true)
		return ;
	exit_all(data, 17);
}

void	check_map_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] != '\n' && data->line[i] != '\0')
	{
		if (data->line[i] == ' ' || data->line[i] == '1'
			|| data->line[i] == '0')
			i++;
		else if (data->line[i] == 'N' || data->line[i] == 'S'
			|| data->line[i] == 'W' || data->line[i] == 'E')
		{
			if (data->spawn == false)
			{
				data->spawn = true;
				i++;
			}
			else
				exit_all(data, 18);
		}
		else
			exit_all(data, 19);
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
	open_fd(data, data->file, &data->fd, 4);
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
		exit_all(data, 20);
	close_fd(data, data->fd, 5);
}
