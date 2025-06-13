/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:47:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/11 16:32:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_SETUP_H
# define TEXTURES_SETUP_H

# include "textures.h"
# include "settings.h"
# include "configuration.h"
# include "errors.h"

int		setup_textures(t_textures *textures, t_configuration *config);
void	setup_surfaces(t_textures *textures, t_configuration *config);
int		setup_walls(t_textures *textures, t_configuration *config);
int		setup_door(t_textures *textures, t_configuration *config);

#endif
