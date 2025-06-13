/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:46:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/13 10:25:41 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include "configuration.h"
# include "cub3D.h"
# include "direction.h"
# include "geometry.h"
# include "point.h"
# include "fpoint.h"
# include "world_settings.h"
# include "string_array.h"
# include "textures.h"
# include "animations.h"

t_configuration	*convert_data_to_configuration(t_data *data);
t_map			*get_map(t_data *data);
t_string		*get_textures(t_data *data);
t_string		*get_animations(void);
t_npc			*get_npcs(t_data *data);

#endif
