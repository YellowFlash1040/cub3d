/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:04:10 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map.h"
# include "player.h"

# define GAME_INIT_ERR 1

typedef struct game
{
	t_player	*player;
	t_map		*map;
}	t_game;

t_game	*init_game(void);
int		build_game(t_game **game_ref);
void	destroy_game(t_game **game_ref);

#endif
