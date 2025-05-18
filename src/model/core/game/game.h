/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/18 12:58:20 by akovtune         ###   ########.fr       */
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
void	destroy_game(t_game **game_ref);

#endif
