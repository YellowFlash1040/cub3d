/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:45:42 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:02:11 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdlib.h>
# include "point.h"

# define PLAYER_INIT_ERR 1

typedef struct player
{
	t_point	position;
	float	angle;
}	t_player;

t_player	*init_player(void);
void		destroy_player(t_player **player_ref);

#endif
