/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:39:23 by rbom              #+#    #+#             */
/*   Updated: 2025/06/04 19:29:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_error_message(t_data *data)
{
	data->error[0] = "Success\n";
	data->error[1] = "No argument provided\n";
	data->error[2] = "More than one argument provided\n";
	data->error[3] = "Ivalid file extension map\n";
	data->error[4] = "Open";
	data->error[5] = "Close";
	data->error[6] = "Multiple wall entries\n";
	data->error[7] = "No texture directory\n";
	data->error[8] = "Malloc";
	data->error[9] = "Ivalid file extension texture\n";
	data->error[10] = "Open";
	data->error[11] = "Close";
	data->error[12] = "Too many arguments texture directory\n";
	data->error[13] = "Multiple floor entries\n";
	data->error[14] = "No RGB data\n";
	data->error[15] = "Invalid RGB format\n";
	data->error[16] = "Invalid RGB value\n";
	data->error[17] = "Invalid map data\n";
	data->error[18] = "Multiple spawn points\n";
	data->error[19] = "Invalid map tokens\n";
	data->error[20] = "No spawn points\n";
	data->error[21] = "Map not fully enclosed\n";
}

void	init_map_data(t_data *data)
{
	init_error_message(data);
	data->line = NULL;
	reset_dir(data);
	data->dir[0] = "NO";
	data->dir[1] = "SO";
	data->dir[2] = "WE";
	data->dir[3] = "EA";
	data->dir[4] = "F";
	data->dir[5] = "C";
	data->map_x = 0;
	data->map_y = 0;
	data->temp_y = 0;
	data->spawn = false;
	data->texture = NULL;
	data->temp_map = NULL;
	data->clean_map = NULL;
	data->resize_map = NULL;
	data->clean_wall[0] = NULL;
	data->clean_wall[1] = NULL;
	data->clean_wall[2] = NULL;
	data->clean_wall[3] = NULL;
}

void	free_null(void	**ptr)
{
	if (ptr && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_all(t_data *data, uint8_t exit_status)
{
	int	i;

	free_null((void **)&data->line);
	free_null((void **)&data->texture);
	if (exit_status > 5 && exit_status < 21)
		close_fd(data, data->fd, 5);
	i = 0;
	while (data->temp_map != NULL && i < data->clean_map_size.y)
		free_null((void **)&data->temp_map[i++]);
	free_null((void **)&data->temp_map);
	i = 0;
	while (data->clean_map != NULL && i < data->clean_map_size.y)
		free_null((void **)&data->clean_map[i++]);
	free_null((void **)&data->clean_map);
	i = 0;
	while (data->resize_map != NULL && i < data->resize_map_size.y && exit_status != 0)
		free_null((void **)&data->resize_map[i++]);
	if (exit_status != 0)
		free_null((void **)&data->resize_map);
	i = 0;
	while (i < 4 && exit_status != 0)
		free_null((void **)&data->clean_wall[i++]);
}

void	exit_all(t_data *data, uint8_t exit_status)
{
	if (exit_status != 0)
		write(2, "Error\n", 6);
	write(2, data->error[exit_status], ft_strlen(data->error[exit_status]));
	if (exit_status == 4 || exit_status == 5 || exit_status == 8
		|| exit_status == 10 || exit_status == 11)
		perror("");
	free_all(data, exit_status);
	exit(exit_status);
}
