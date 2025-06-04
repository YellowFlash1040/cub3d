/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:40:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 15:03:11 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BUILDER_H
# define CAMERA_BUILDER_H

# include "camera.h"
# include "errors.h"
# include "ft_memory.h"

int	build_camera(t_camera *camera, int rays_amount);

#endif
