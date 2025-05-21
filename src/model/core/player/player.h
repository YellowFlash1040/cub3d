/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:45:42 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/20 15:25:56 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdlib.h>
# include "fpoint.h"

# define PLAYER_INIT_ERR 1

typedef struct player
{
	t_fpoint	position;
	double		angle;
	double		delta_x;
	double		delta_y;
}	t_player;

t_player	*init_player(void);
void		destroy_player(t_player **player_ref);

#endif
