/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:05:22 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 17:35:07 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_SETUP_H
# define CAMERA_SETUP_H

# include "camera.h"
# include "settings.h"
# include "errors.h"

void	setup_camera(t_camera *camera, t_settings *settings);

#endif
