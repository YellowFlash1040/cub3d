/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 15:16:07 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_setup.h"

void	setup_game(t_game *game, t_configuration *config)
{
	game->map = config->map;
	game->npcs = config->npcs;
	game->npc_count = config->npc_count;
	config->map = NULL;
	config->npcs = NULL;
}
