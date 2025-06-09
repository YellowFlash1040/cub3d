/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:53:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/08 12:27:39 by akovtune         ###   ########.fr       */
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
