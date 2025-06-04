/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:00:16 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 15:06:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_builder.h"

int	build_player(t_player *player)
{
	if (!player)
		return (EMPTY_PTR_ERR);
	player->camera = init_camera();
	if (!player->camera)
		return (MALLOC_FAIL_ERR);
	return (SUCCESS);
}
