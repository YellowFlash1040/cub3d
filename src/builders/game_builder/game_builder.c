/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:44:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 15:05:08 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_builder.h"

int	build_game(t_game *game)
{
	if (!game)
		return (EMPTY_PTR_ERR);
	game->map = init_map();
	if (!game->map)
		return (MALLOC_FAIL_ERR);
	game->player = init_player();
	if (!game->player)
		return (destroy_map(&game->map), MALLOC_FAIL_ERR);
	return (SUCCESS);
}
