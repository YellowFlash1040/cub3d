/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:56:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 13:08:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_H
# define CONFIGURATION_H

# include <stdlib.h>
# include "fpoint.h"
# include "map.h"
# include "color.h"
# include "npc.h"
# include "string_array.h"

# define CONFIGURATION_INIT_ERR 1

typedef struct configuration
{
	t_string	*textures;
	t_string	*animations;
	t_color		ceiling_color;
	t_color		floor_color;
	t_map		*map;
	t_npc		*npcs;
	int			npc_count;
	t_fpoint	player_position;
	double		camera_angle;
}	t_configuration;

t_configuration	*init_configuration(void);
void			destroy_configuration(t_configuration **configuration_ref,
					bool full_destruction);

#endif
