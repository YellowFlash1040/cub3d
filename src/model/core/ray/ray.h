/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:53:22 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 16:41:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdlib.h>
# include "fpoint.h"

# define RAY_INIT_ERR 1

typedef enum e_hit_type
{
	NONE_HIT,
	VERTICAL_HIT,
	HORIZONTAL_HIT
}	t_hit_type;

typedef struct ray
{
	t_fpoint	position;
	double		angle;
	double		length;
	t_hit_type	hit_type;
}	t_ray;

t_ray	*init_ray(void);
void	destroy_ray(t_ray **ray_ref);

#endif
