/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:45:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 15:08:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings_setup.h"

static double	get_camera_angle(t_direction direction);

int	setup_settings(t_settings *settings)
{
	t_point		player_pos;
	t_direction	player_direction;
	int			x;
	int			y;

	player_pos = (t_point){3, 6};
	player_direction = NORTH;
	x = player_pos.x * CELL_SIZE + CELL_SIZE / 2;
	y = player_pos.y * CELL_SIZE + CELL_SIZE / 2;
	settings->player_position = (t_fpoint){x, y};
	settings->camera_angle = get_camera_angle(player_direction);
	settings->camera_fov = CAMERA_FIELD_OF_VIEW * DEGREE;
	settings->ceiling_color = 0xffaaaaff;
	settings->floor_color = 0xaaaaffff;
	settings->north_wall_filepath = ft_strdup("./assets/wall1.png");
	settings->south_wall_filepath = ft_strdup("./assets/wall2.png");
	settings->west_wall_filepath = ft_strdup("./assets/wall3.png");
	settings->east_wall_filepath = ft_strdup("./assets/wall4.png");
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
