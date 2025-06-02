/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:23:55 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 14:53:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotations.h"

void	rotate_player_left(t_player *player, double delta_time)
{
	double	angle;
	double	perpendicular_angle;

	angle = ROTATION_SPEED * delta_time;
	player->camera->angle += angle;
	normalize_angle(&player->camera->angle);
	player->vertical_direction = get_unit_vector(player->camera->angle);

	perpendicular_angle = get_perpendicular_angle(player->camera->angle);
	normalize_angle(&perpendicular_angle);
	player->horizontal_direction = get_unit_vector(perpendicular_angle);
}

void	rotate_player_right(t_player *player, double delta_time)
{
	double	angle;
	double	angle2;

	angle = ROTATION_SPEED * delta_time;
	player->camera->angle -= angle;
	normalize_angle(&player->camera->angle);
	player->vertical_direction = get_unit_vector(player->camera->angle);

	angle2 = player->camera->angle - 90 * M_PI / 180.0;
	normalize_angle(&player->camera->angle);
	player->horizontal_direction = get_unit_vector(angle2);
}
