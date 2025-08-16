/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:46:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 13:48:39 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include "configuration.h"
# include "parser.h"
# include "direction.h"
# include "geometry.h"
# include "point.h"
# include "fpoint.h"
# include "world_settings.h"
# include "string_array.h"
# include "textures.h"
# include "animations.h"

t_configuration	*convert_data_to_configuration(t_data *data);
t_string		*get_animations(t_data *data);
t_npc			*get_npcs(t_data *data);

#endif
