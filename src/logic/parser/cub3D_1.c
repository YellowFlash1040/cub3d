/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:39:23 by rbom              #+#    #+#             */
/*   Updated: 2025/06/13 14:48:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_number_args(t_data *data, int argc, char **argv)
{
	if (argc == 1)
		exit_all(data, 1);
	else if (argc > 2)
		exit_all(data, 2);
	else
		data->file = argv[1];
}

void	check_extension(t_data *data, char *str, char *ext, int exit_status)
{
	int	s_i;
	int	e_i;

	s_i = ft_strlen(str);
	e_i = ft_strlen(ext);
	if (s_i <= e_i)
		exit_all(data, exit_status);
	while (e_i >= 0 && str[s_i] == ext[e_i])
	{
		s_i--;
		e_i--;
	}
	if (e_i == -1)
		return ;
	s_i = ft_strlen(str);
	e_i = ft_strlen(ext);
	while (e_i >= 0 && str[s_i] == ext[e_i] - 32)
	{
		s_i--;
		e_i--;
	}
	if (e_i != -1)
		exit_all(data, exit_status);
}

void	check_input(t_data *data, int argc, char **argv)
{
	init_map_data(data);
	check_number_args(data, argc, argv);
	check_extension(data, data->file, ".cub", 3);
}

void	open_fd(t_data *data, char *file, int *fd, int exit_status)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		exit_all(data, exit_status);
}

void	close_fd(t_data *data, int fd, int exit_status)
{
	if (close(fd) == -1)
		exit_all(data, exit_status);
}
