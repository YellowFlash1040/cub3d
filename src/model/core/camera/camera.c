/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:53:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:00:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->angle = 0;
	camera->fov = 0;
	camera->rays = NULL;
	camera->rays_count = 0;
	return (camera);
}

void	destroy_camera(t_camera **camera_ref)
{
	t_camera	*camera;

	if (!camera_ref || !*camera_ref)
		return ;
	camera = *camera_ref;
	if (camera->rays)
		free(camera->rays);
	free(camera);
	*camera_ref = NULL;
}

int	build_camera(t_camera **camera_ref, int rays_amount)
{
	t_camera	*camera;
	int			rays_arr_size;

	if (!camera_ref || !*camera_ref)
		return (EMPTY_PTR_ERR);
	camera = *camera_ref;
	rays_arr_size = sizeof(t_ray) * (rays_amount + 1);
	camera->rays = NULL;
	camera->rays = (t_ray *)malloc(rays_arr_size);
	if (!camera->rays)
		return (destroy_camera(camera_ref), MALLOC_FAIL_ERR);
	ft_bzero(camera->rays, rays_arr_size);
	camera->rays_count = rays_amount;
	return (SUCCESS);
}
