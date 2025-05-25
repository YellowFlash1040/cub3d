/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:40:12 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 15:04:11 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_builder.h"

int	build_camera(t_camera *camera, int rays_amount)
{
	int	rays_arr_size;

	if (!camera)
		return (EMPTY_PTR_ERR);
	rays_arr_size = sizeof(t_ray) * (rays_amount + 1);
	camera->rays = NULL;
	camera->rays = (t_ray *)malloc(rays_arr_size);
	if (!camera->rays)
		return (MALLOC_FAIL_ERR);
	ft_bzero(camera->rays, rays_arr_size);
	return (SUCCESS);
}
