/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:28:42 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 12:34:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include <stdlib.h>
# include "errors.h"
# include "wall.h"
# include "surface.h"
# include "door.h"

# define TEXTURES_INIT_ERR 1

typedef enum e_texture_name
{
	TEXTURE_NORTH_WALL,
	TEXTURE_SOUTH_WALL,
	TEXTURE_WEST_WALL,
	TEXTURE_EAST_WALL,
	TEXTURE_DOOR,
	TEXTURE_NAMES_COUNT
}	t_texture_name;
// TEXTURE_NAMES_COUNT is a nice trick, with which you 
// can always tell how many items there are

typedef struct textures
{
	t_surface	*ceiling;
	t_surface	*floor;
	t_wall		*north_wall;
	t_wall		*south_wall;
	t_wall		*west_wall;
	t_wall		*east_wall;
	t_door		*door;
}	t_textures;

t_textures	*init_textures(void);
int			build_textures(t_textures **textures_ref);
void		destroy_textures(t_textures **textures_ref);

#endif
