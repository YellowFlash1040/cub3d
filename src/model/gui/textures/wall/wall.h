/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:29:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 13:29:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include <stdlib.h>
# include "texture.h"

# define WALL_INIT_ERR 1

typedef struct wall
{
	t_texture		*texture;
}	t_wall;

t_wall	*init_wall(void);
void	destroy_wall(t_wall **wall_ref);

#endif
