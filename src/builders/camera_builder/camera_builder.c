/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:40:12 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 17:26:12 by akovtune         ###   ########.fr       */
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
	camera->rays_count = rays_amount;
	return (SUCCESS);
}

// static int	allocate_rays(t_ray **rays, int amount);
// static void	destroy_reys(t_ray **rays, int amount);

// int	build_camera(t_camera *camera, int rays_amount)
// {
// 	int	result;
// 	int	rays_arr_size;

// 	if (!camera)
// 		return (EMPTY_PTR_ERR);
// 	rays_arr_size = sizeof(t_ray *) * (rays_amount + 1);
// 	camera->rays = NULL;
// 	camera->rays = (t_ray **)malloc(rays_arr_size);
// 	if (!camera->rays)
// 		return (MALLOC_FAIL_ERR);
// 	ft_bzero(camera->rays, rays_arr_size);
// 	camera->rays_count = rays_amount;
// 	result = allocate_rays(camera->rays, rays_arr_size);
// 	if (result != SUCCESS)
// 	{
// 		free(camera->rays);
// 		camera->rays = NULL;
// 		return (result);
// 	}
// 	return (SUCCESS);
// }

// static int	allocate_rays(t_ray **rays, int amount)
// {
// 	int	i;

// 	i = 0;
// 	while (i < amount)
// 	{
// 		rays[i] = init_ray();
// 		if (!rays[i])
// 			return (destroy_reys(rays, i), MALLOC_FAIL_ERR);
// 		i++;
// 	}
// 	return (SUCCESS);
// }

// static void destroy_reys(t_ray **rays, int amount)
// {
// 	int	i;

// 	i = 0;
// 	while (i < amount)
// 	{
// 		free(rays[i]);
// 		rays[i] = NULL;
// 		i++;
// 	}
// }
