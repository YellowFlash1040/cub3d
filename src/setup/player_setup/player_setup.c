/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:56:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 17:35:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_setup.h"

void	setup_player(t_player *player, t_settings *settings)
{
	player->position = settings->player_position;
	player->direction = get_unit_vector(settings->camera_angle);
}
