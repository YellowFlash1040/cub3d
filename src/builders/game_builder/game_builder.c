/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:44:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/03 18:03:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_builder.h"

static void	destroy_temp(t_game *game);

int	build_game(t_game *game)
{
	if (!game)
		return (EMPTY_PTR_ERR);
	game->map = init_map();
	if (!game->map)
		return (destroy_temp(game), MALLOC_FAIL_ERR);
	game->player = init_player();
	if (!game->player)
		return (destroy_temp(game), MALLOC_FAIL_ERR);
	return (SUCCESS);
}

static void	destroy_temp(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		destroy_map(&game->map);
	if (game->player)
		destroy_player(&game->player);
}
