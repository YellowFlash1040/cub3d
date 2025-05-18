/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:27 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/18 15:40:27 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->player = NULL;
	return (game);
}

void	destroy_game(t_game **game_ref)
{
	t_game	*game;

	if (!game_ref || !*game_ref)
		return ;
	game = *game_ref;
	if (game->map)
		destroy_map(&game->map);
	free(game);
	*game_ref = NULL;
}
