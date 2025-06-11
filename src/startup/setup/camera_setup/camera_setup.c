/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:56:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 17:35:03 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_setup.h"

void	setup_camera(t_camera *camera, t_settings *settings)
{
	camera->fov = settings->camera_fov;
	camera->angle = settings->camera_angle;
	camera->position = settings->player_position;
}
