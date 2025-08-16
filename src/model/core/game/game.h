/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 16:15:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map.h"
# include "player.h"
# include "npc.h"

# define GAME_INIT_ERR 1

typedef struct game
{
	t_player	*player;
	t_map		*map;
	t_npc		*npcs;
	int			npc_count;
}	t_game;

t_game	*init_game(void);
int		build_game(t_game **game_ref);
void	destroy_game(t_game **game_ref);

#endif
