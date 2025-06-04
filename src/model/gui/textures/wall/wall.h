/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:29:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/30 18:48:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include <stdlib.h>
# include "direction.h"
# include "texture.h"

# define WALL_INIT_ERR 1

typedef struct wall
{
	t_direction		direction;
	t_texture		*texture;
}	t_wall;

t_wall	*init_wall(void);
void	destroy_wall(t_wall **wall_ref);

#endif
