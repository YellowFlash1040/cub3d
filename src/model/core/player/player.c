/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:01:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/23 16:11:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->position = (t_fpoint){-1, -1};
	player->angle = 0;
	player->direction.x = 0;
	player->direction.y = 0;
	return (player);
}

void	destroy_player(t_player **player_ref)
{
	t_player	*player;

	if (!player_ref || !*player_ref)
		return ;
	player = *player_ref;
	free(player);
	*player_ref = NULL;
}
