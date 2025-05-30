/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:29:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/29 16:40:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include "direction.h"

# define WALL_INIT_ERR 1

typedef struct wall
{
	t_direction		direction;
	mlx_texture_t	*texture;
}	t_wall;

t_wall	*init_wall(void);
void	destroy_wall(t_wall **wall_ref);

#endif
