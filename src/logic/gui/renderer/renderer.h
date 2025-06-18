/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:40:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/15 12:28:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "ft_memory.h"
# include "app.h"
# include "minimap.h"
# include "scene.h"
# include "animations_manager.h"

int		render(t_app *app);
void	render_frame(void *param);
void	clear_buffer(mlx_image_t *img);

#endif
