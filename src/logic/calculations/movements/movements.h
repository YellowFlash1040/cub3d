/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/18 18:32:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include <stdlib.h>
# include <math.h>
# include "player.h"
# include "status_codes.h"
# include "window.h"

# define STEP 10

int	move_player_forward(t_player *player);
int	move_player_back(t_player *player);
int	rotate_player_left(t_player *player);
int	rotate_player_right(t_player *player);

#endif
