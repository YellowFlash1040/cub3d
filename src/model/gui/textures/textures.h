/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:28:42 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 16:29:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include <stdlib.h>
# include "wall.h"
# include "surface.h"

# define TEXTURES_INIT_ERR 1

typedef struct textures
{
	t_surface	*ceiling;
	t_surface	*floor;
	t_wall		*north_wall;
	t_wall		*south_wall;
	t_wall		*west_wall;
	t_wall		*east_wall;
}	t_textures;

t_textures	*init_textures(void);
void		destroy_textures(t_textures **textures_ref);

#endif
