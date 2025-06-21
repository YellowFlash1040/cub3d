/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:02:27 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 12:57:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

static double	get_camera_angle(t_data *data);
static t_color	get_color_from_data(t_rgb value);
static t_fpoint	get_player_position(t_data *data);

t_configuration	*convert_data_to_configuration(t_data *data)
{
	t_configuration	*configuration;

	configuration = init_configuration();
	if (!configuration)
		return (NULL);
	configuration->textures = get_textures(data);
	if (!configuration->textures)
		return (destroy_configuration(&configuration, true), NULL);
	configuration->animations = get_animations();
	if (!configuration->animations)
		return (destroy_configuration(&configuration, true), NULL);
	configuration->floor_color = get_color_from_data(data->clean_floor[0]);
	configuration->ceiling_color = get_color_from_data(data->clean_floor[1]);
	configuration->map = get_map(data);
	if (!configuration->map)
		return (destroy_configuration(&configuration, true), NULL);
	configuration->player_position = get_player_position(data);
	configuration->camera_angle = get_camera_angle(data);
	configuration->npcs = get_npcs(data);
	configuration->npc_count = data->sprites_count;
	return (configuration);
}

t_map	*get_map(t_data *data)
{
	t_map	*map;

	map = init_map();
	if (!map)
		return (NULL);
	map->width = data->resize_map_size.x;
	map->height = data->resize_map_size.y;
	map->cells = data->resize_map;
	return (map);
}

static double	get_camera_angle(t_data *data)
{
	double	angle;

	if (data->resize_spawn_dir == 'N')
		angle = 91 * M_PI / 180.0;
	else if (data->resize_spawn_dir == 'S')
		angle = 271 * M_PI / 180.0;
	else if (data->resize_spawn_dir == 'W')
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

static t_fpoint	get_player_position(t_data *data)
{
	t_point		map_position;
	t_fpoint	world_position;

	map_position = (t_point){data->resize_spawn.x, data->resize_spawn.y};
	world_position.x = map_position.x * CELL_SIZE + CELL_SIZE / 2;
	world_position.y = map_position.y * CELL_SIZE + CELL_SIZE / 2;
	return (world_position);
}
