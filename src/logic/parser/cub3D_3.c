/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 14:31:06 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_wall(t_data *data, int d, int i)
{
	if (data->line[i] != data->dir[d][0] || data->line[i + 1] != data->dir[d][1]
		|| ft_isspace(data->line[i + 2] == false))
		return (false);
	if (data->dir_check[d] == true)
		exit_all(data, 6);
	i += 3;
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (data->line[i] == '\0')
		exit_all(data, 7);
	check_texture(data, i);
	while (ft_isspace(data->line[i]) == false)
		i++;
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (data->line[i] != '\0')
		exit_all(data, 9);
	data->dir_check[d] = true;
	return (true);
}

void	atouint8_check(t_data *data, int i)
{
	uint16_t	x;

	x = 0;
	while (ft_isdigit(data->line[i]) == true)
	{
		x = x * 10 + data->line[i] - 48;
		if (x > 255)
			exit_all(data, 13);
		i++;
	}
}

int	check_rgb(t_data *data, int i, bool last)
{
	if (ft_isdigit(data->line[i]) == false)
		exit_all(data, 12);
	atouint8_check(data, i);
	while (ft_isdigit(data->line[i]) == true)
		i++;
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (last == false)
	{
		if (data->line[i] == ',')
			i++;
		else
			exit_all(data, 12);
		while (ft_isspace(data->line[i]) == true)
			i++;
		if (data->line[i] == '\0')
			exit_all(data, 12);
	}
	else
		if (data->line[i] != '\0')
			exit_all(data, 12);
	return (i);
}

bool	check_floor(t_data *data, int d, int i)
{
	if (data->line[i] != data->dir[d][0]
		|| ft_isspace(data->line[i + 1]) == false)
		return (false);
	if (data->dir_check[d] == true)
		exit_all(data, 10);
	i += 2;
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (data->line[i] == '\0')
		exit_all(data, 11);
	i = check_rgb(data, i, false);
	i = check_rgb(data, i, false);
	i = check_rgb(data, i, true);
	data->dir_check[d] = true;
	return (true);
}

void	check_dir(t_data *data)
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
		if (d < 6 && check_wall(data, d, i) == true)
			return ;
		else if (d >= 6 && check_floor(data, d, i) == true)
			return ;
		d++;
	}
	exit_all(data, 14);
}
