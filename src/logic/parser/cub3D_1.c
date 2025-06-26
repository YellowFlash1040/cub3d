/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 17:41:03 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_all(t_data *data, uint8_t exit_status)
{
	int	i;

	free_null((void **)&data->line);
	close_fd(data, &data->fd);
	i = 0;
	while (data->temp_map != NULL && i < data->clean_map_size.y)
		free_null((void **)&data->temp_map[i++]);
	free_null((void **)&data->temp_map);
	i = 0;
	while (data->clean_map != NULL && i < data->clean_map_size.y)
		free_null((void **)&data->clean_map[i++]);
	free_null((void **)&data->clean_map);
	i = 0;
	while (exit_status != 0 && data->resize_map && i < data->resize_map_size.y)
		free_null((void **)&data->resize_map[i++]);
	if (exit_status != 0)
		free_null((void **)&data->resize_map);
	i = 0;
	while (exit_status != 0 && i < 6)
		free_null((void **)&data->clean_wall[i++]);
	free_null((void **)&data->sprites);
}

void	exit_all(t_data *data, uint8_t exit_status)
{
	if (exit_status != 0)
		write(2, "Error\n", 6);
	if (exit_status != 19)
	{
		write(2, data->error[exit_status], ft_strlen(data->error[exit_status]));
		if (exit_status == 4 || exit_status == 5 || exit_status == 8)
			perror("");
	}
	else if (exit_status == 19)
	{
		write(2, mlx_strerror(mlx_errno),
			ft_strlen((char *)mlx_strerror(mlx_errno)));
		write(2, "\n", 1);
	}
	free_all(data, exit_status);
	exit(exit_status);
}

void	check_number_args(t_data *data, int argc, char **argv)
{
	if (argc == 1)
		exit_all(data, 1);
	else if (argc > 2)
		exit_all(data, 2);
	else
		data->file = argv[1];
}

void	check_extension(t_data *data, char *file, char *ext)
{
	int	len_ext;
	int	len_name;

	len_ext = ft_strlen(ext);
	len_name = ft_strlen(file) - len_ext;
	len_ext--;
	if (len_name <= 0)
		exit_all(data, 3);
	while (len_ext > 0 && (ext[len_ext] == file[len_name + len_ext]
			|| ext[len_ext] == file[len_name + len_ext] + 32))
		len_ext--;
	if (len_ext != 0 || ext[len_ext] != '.' || file[len_name + len_ext] != '.')
		exit_all(data, 3);
}

void	reset_dir(t_data *data)
{
	int	i;

	i = 0;
	while (i < 9)
		data->dir_check[i++] = false;
}
