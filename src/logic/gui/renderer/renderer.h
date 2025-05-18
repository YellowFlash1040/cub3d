/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:40:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/18 15:45:05 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "app.h"
# include "minimap.h"
# include "ft_memory.h"

void	render(t_app *app);
void	render_frame(void *param);
void	clear_buffer(mlx_image_t *img);

#endif
