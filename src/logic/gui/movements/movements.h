/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:33:59 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include <stdlib.h>
# include "game.h"
# include "status_codes.h"

# define STEP 10

int move_player_up(t_game *game);
int move_player_down(t_game *game);
int move_player_left(t_game *game);
int move_player_right(t_game *game);

#endif
