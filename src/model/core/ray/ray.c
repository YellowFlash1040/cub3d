/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:53:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/08 12:27:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->angle = 0;
	ray->length = 0;
	ray->position = (t_fpoint){0};
	ray->hit_type = NONE_HIT;
	return (ray);
}

void	destroy_ray(t_ray **ray_ref)
{
	t_ray	*ray;

	if (!ray_ref || !*ray_ref)
		return ;
	ray = *ray_ref;
	free(ray);
	*ray_ref = NULL;
}
