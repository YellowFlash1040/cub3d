/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_0.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 17:33:17 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_error_message(t_data *data)
{
	data->error[0] = "Success\n";
	data->error[1] = "No argument provided\n";
	data->error[2] = "More than one argument provided\n";
	data->error[3] = "Ivalid file extension map\n";
	data->error[4] = "Open: ";
	data->error[5] = "Close: ";
	data->error[6] = "Multiple wall entries\n";
	data->error[7] = "No texture directory\n";
	data->error[8] = "Malloc: ";
	data->error[9] = "Too many arguments texture directory\n";
	data->error[10] = "Multiple floor entries\n";
	data->error[11] = "No RGB data\n";
	data->error[12] = "Invalid RGB format\n";
	data->error[13] = "Invalid RGB value\n";
	data->error[14] = "Invalid or incomplete data\n";
	data->error[15] = "Multiple spawn points\n";
	data->error[16] = "Invalid map tokens\n";
	data->error[17] = "No map or spawn points\n";
	data->error[18] = "Map not fully enclosed\n";
}

void	init_map_data(t_data *data)
{
	init_error_message(data);
	data->fd = -1;
	data->dir[0] = "NO";
	data->dir[1] = "SO";
	data->dir[2] = "WE";
	data->dir[3] = "EA";
	data->dir[4] = "DO";
	data->dir[5] = "SP";
	data->dir[6] = "F";
	data->dir[7] = "C";
	data->line = NULL;
	data->temp_map = NULL;
	data->clean_map = NULL;
	data->resize_map = NULL;
	data->clean_wall[0] = NULL;
	data->clean_wall[1] = NULL;
	data->clean_wall[2] = NULL;
	data->clean_wall[3] = NULL;
	data->clean_wall[4] = ft_strdup(DEFAULT_DOOR);
	if (data->clean_wall[4] == NULL)
		exit_all(data, 8);
	data->clean_wall[5] = ft_strdup(DEFAULT_SPRITE);
	if (data->clean_wall[5] == NULL)
		exit_all(data, 8);
	data->sprites = NULL;
}

void	free_null(void	**ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	open_fd(t_data *data, char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		exit_all(data, 4);
}

void	close_fd(t_data *data, int *fd)
{
	if (*fd != -1 && close(*fd) == -1)
		exit_all(data, 5);
	*fd = -1;
}
