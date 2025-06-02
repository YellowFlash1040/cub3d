/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:56:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/02 21:02:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_setup.h"

void	setup_player(t_player *player, t_settings *settings)
{
	double	perpendicular_angle;

	perpendicular_angle = get_perpendicular_angle(settings->camera_angle);
	normalize_angle(&perpendicular_angle);
	player->position = settings->player_position;
	player->vertical_direction = get_unit_vector(settings->camera_angle);
	player->horizontal_direction = get_unit_vector(perpendicular_angle);
}
