/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:45:42 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:04:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdlib.h>
# include "fpoint.h"
# include "vector.h"
# include "camera.h"

# define PLAYER_INIT_ERR 1

typedef struct player
{
	t_fpoint	position;
	t_vector	vertical_direction;
	t_vector	horizontal_direction;
	t_camera	*camera;
}	t_player;

t_player	*init_player(void);
int			build_player(t_player **player_ref);
void		destroy_player(t_player **player_ref);

#endif
