/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:55:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 20:55:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <stdlib.h>
# include "texture.h"

# define SPRITE_INIT_ERR 1

typedef struct sprite
{
	t_texture		*texture;
}	t_sprite;

t_sprite	*init_sprite(void);
void		destroy_sprite(t_sprite **sprite_ref);

#endif
