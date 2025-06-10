/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:44:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 16:52:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_builder.h"

int	build_game(t_game **game_ref)
{
	t_game	*game;

	if (!game_ref || !*game_ref)
		return (EMPTY_PTR_ERR);
	game = *game_ref;
	game->map = init_map();
	if (!game->map)
		return (destroy_game(game_ref), MALLOC_FAIL_ERR);
	game->player = init_player();
	if (!game->player)
		return (destroy_game(game_ref), MALLOC_FAIL_ERR);
	return (SUCCESS);
}
