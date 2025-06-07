/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:45:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/07 21:45:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings_setup.h"

static t_color		get_color_from_data(t_rgb value);
static t_direction	get_direction_from_data(char d);
static double		get_camera_angle(t_direction direction);

int	setup_settings(t_settings *settings, t_data *data)
{
	t_point		player_pos;
	t_direction	player_direction;
	int			x;
	int			y;

	player_pos = (t_point){data->resize_spawn.x, data->resize_spawn.y};
	player_direction = get_direction_from_data(data->resize_spawn_dir);
	x = player_pos.x * CELL_SIZE + CELL_SIZE / 2;
	y = player_pos.y * CELL_SIZE + CELL_SIZE / 2;
	settings->player_position = (t_fpoint){x, y};
	settings->camera_angle = get_camera_angle(player_direction);
	settings->camera_fov = CAMERA_FIELD_OF_VIEW * DEGREE;
	settings->floor_color = get_color_from_data(data->clean_floor[0]);
	settings->ceiling_color = get_color_from_data(data->clean_floor[1]);
	settings->north_wall_filepath = data->clean_wall[0];
	settings->south_wall_filepath = data->clean_wall[1];
	settings->west_wall_filepath = data->clean_wall[2];
	settings->east_wall_filepath = data->clean_wall[3];
	settings->door_filepath = ft_strdup("./assets/textures/door.png");
	return (SUCCESS);
}

static double	get_camera_angle(t_direction direction)
{
	double	angle;

	if (direction == NORTH)
		angle = 91 * M_PI / 180.0;
	else if (direction == SOUTH)
		angle = 271 * M_PI / 180.0;
	else if (direction == WEST)
		angle = 181 * M_PI / 180.0;
	else
		angle = 1 * M_PI / 180.0;
	return (angle);
}

static t_color	get_color_from_data(t_rgb value)
{
	t_color	color;

	color = get_color(value.r, value.g, value.b, 255);
	return (color);
}

static t_direction	get_direction_from_data(char d)
{
	if (d == 'N')
		return (NORTH);
	if (d == 'S')
		return (SOUTH);
	if (d == 'E')
		return (EAST);
	return (WEST);
}
