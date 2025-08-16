/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:56:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 16:29:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_setup.h"

void	setup_camera(t_camera *camera, t_settings *settings,
	t_configuration *config)
{
	camera->fov = settings->camera_fov;
	camera->angle = config->camera_angle;
	camera->position = config->player_position;
}
