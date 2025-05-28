/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:21:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/28 18:20:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "drawing.h"
# include "camera.h"
# include "settings.h"
# include "geometry.h"

void	draw_scene(t_canvas *canvas, t_camera *camera, t_settings *settings);
void	draw_surface(t_canvas *canvas, t_surface *surface);

#endif
