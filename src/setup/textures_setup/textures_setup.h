/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:47:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/31 17:51:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_SETUP_H
# define TEXTURES_SETUP_H

# include "textures.h"
# include "settings.h"
# include "errors.h"

int		setup_textures(t_textures *textures, t_settings *settings);
void	setup_surfaces(t_textures *textures, t_settings *settings);
int		setup_walls(t_textures *textures, t_settings *settings);

#endif
