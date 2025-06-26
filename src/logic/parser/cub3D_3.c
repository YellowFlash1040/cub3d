/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:39:23 by rbom              #+#    #+#             */
/*   Updated: 2025/06/13 14:48:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_dir_wall_loop(t_data *data, int w, int i)
{
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (data->line[i] == data->dir[w][0] && data->line[i + 1] == data->dir[w][1]
		&& ft_isspace(data->line[i + 2]))
	{
		if (data->dir_check[w] == true)
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
			exit_all(data, 12);
		data->dir_check[w] = true;
		return (true);
	}
	return (false);
}

bool	check_dir_wal(t_data *data)
{
	int	w;
	int	i;

	w = 0;
	while (w < 4)
	{
		i = 0;
		if (check_dir_wall_loop(data, w, i) == true)
			return (true);
		w++;
	}
	return (false);
}

void	atouint8_check(t_data *data, int i)
{
	uint16_t	x;

	x = 0;
	while (ft_isdigit(data->line[i]) == true)
	{
		x = x * 10 + data->line[i] - 48;
		if (x > 255)
			exit_all(data, 16);
		i++;
	}
}

int	check_loop_skip(t_data *data, int i, bool last)
{
	if (ft_isdigit(data->line[i]) == false)
		exit_all(data, 15);
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
			exit_all(data, 15);
		while (ft_isspace(data->line[i]) == true)
			i++;
		if (data->line[i] == '\0')
			exit_all(data, 15);
	}
	else
		if (data->line[i] != '\0')
			exit_all(data, 15);
	return (i);
}

bool	check_dir_floor_loop(t_data *data, int f)
{
	int	i;

	i = 0;
	while (ft_isspace(data->line[i]) == true)
		i++;
	if (data->line[i] == data->dir[f][0] && ft_isspace(data->line[i + 1]))
	{
		if (data->dir_check[f] == true)
			exit_all(data, 13);
		i += 2;
		while (ft_isspace(data->line[i]) == true)
			i++;
		if (data->line[i] == '\0')
			exit_all(data, 14);
		i = check_loop_skip(data, i, false);
		i = check_loop_skip(data, i, false);
		i = check_loop_skip(data, i, true);
		data->dir_check[f] = true;
		return (true);
	}
	return (false);
}
