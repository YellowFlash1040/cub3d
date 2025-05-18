/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/18 15:30:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include <stdlib.h>
# include <math.h>
# include "player.h"
# include "status_codes.h"

# define STEP 10

int	move_player_up(t_player *player);
int	move_player_down(t_player *player);
int	move_player_left(t_player *player);
int	move_player_right(t_player *player);

#endif
