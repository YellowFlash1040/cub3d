/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:21:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 13:19:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_H
# define ANIMATIONS_H

# include <stdlib.h>
# include "errors.h"
# include "animation.h"

# define ANIMATIONS_INIT_ERR 1

typedef enum e_animation_name
{
	ANIMATION_NORTH_WALL,
	ANIMATION_SOUTH_WALL,
	ANIMATION_WEST_WALL,
	ANIMATION_EAST_WALL,
	ANIMATION_SPRITE,
	ANIMATION_NAMES_COUNT
}	t_animation_name;
// ANIMATION_NAMES_COUNT is a nice trick, with which you 
// can always tell how many items there are

typedef struct animations
{
	t_animation	*north_wall;
	t_animation	*south_wall;
	t_animation	*west_wall;
	t_animation	*east_wall;
	t_animation	*sprite;
}	t_animations;

t_animations	*init_animations(void);
int				build_animations(t_animations **animations_ref);
void			destroy_animations(t_animations **animations_ref);

#endif
