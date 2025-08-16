/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:53:05 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 17:05:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stdlib.h>
# include "errors.h"
# include "ft_memory.h"
# include "ray.h"

# define CAMERA_INIT_ERR 1

typedef struct camera
{
	double		fov;
	t_ray		*rays;
	int			rays_count;
	t_fpoint	position;
	double		angle;
}	t_camera;

t_camera	*init_camera(void);
int			build_camera(t_camera **camera_ref, int rays_amount);
void		destroy_camera(t_camera **camera_ref);

#endif
