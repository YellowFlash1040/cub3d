/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:23:55 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 21:01:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotations.h"

static void	update_data(t_player *player);

void	rotate_player_left(t_player *player, double delta_time)
{
	double	angle;

	angle = ROTATION_SPEED * delta_time;
	player->camera->angle += angle;
	normalize_angle(&player->camera->angle);
	update_data(player);
}

void	rotate_player_right(t_player *player, double delta_time)
{
	double	angle;

	angle = ROTATION_SPEED * delta_time;
	player->camera->angle -= angle;
	normalize_angle(&player->camera->angle);
	update_data(player);
}

static void	update_data(t_player *player)
{
	double	perpendicular_angle;

	perpendicular_angle = get_perpendicular_angle(player->camera->angle);
	normalize_angle(&perpendicular_angle);
	player->vertical_direction = get_unit_vector(player->camera->angle);
	player->horizontal_direction = get_unit_vector(perpendicular_angle);
}
