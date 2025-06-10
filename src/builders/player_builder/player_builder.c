/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:00:16 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 16:40:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_builder.h"

int	build_player(t_player **player_ref)
{
	t_player	*player;

	if (!player_ref || !*player_ref)
		return (EMPTY_PTR_ERR);
	player = *player_ref;
	player->camera = init_camera();
	if (!player->camera)
		return (destroy_player(player_ref), MALLOC_FAIL_ERR);
	return (SUCCESS);
}
