/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_loader.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:03:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 21:05:08 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_LOADER_H
# define ANIMATIONS_LOADER_H

# include "texture.h"
# include "ft_string.h"
# include "animation.h"

typedef mlx_texture_t	t_sprite_sheet;

int	load_animation(t_string file_path, t_animation **animation_ref);

#endif
