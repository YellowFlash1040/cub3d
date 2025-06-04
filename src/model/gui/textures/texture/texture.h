/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:46:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/30 18:50:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <MLX42/MLX42.h>
# include "color.h"

typedef mlx_texture_t	t_texture;

t_color	get_texture_pixel(t_texture *texture, int x, int y);

#endif
