/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:01:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:02:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->position = (t_fpoint){0, 0};
	player->vertical_direction = (t_vector){0};
	player->horizontal_direction = (t_vector){0};
	player->camera = NULL;
	return (player);
}

void	destroy_player(t_player **player_ref)
{
	t_player	*player;

	if (!player_ref || !*player_ref)
		return ;
	player = *player_ref;
	if (player->camera)
		destroy_camera(&player->camera);
	free(player);
	*player_ref = NULL;
}

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
