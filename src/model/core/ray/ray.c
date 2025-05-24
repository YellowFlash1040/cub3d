/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:53:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/24 19:53:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray/ray.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
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
