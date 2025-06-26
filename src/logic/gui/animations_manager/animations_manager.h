/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_manager.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:08:32 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 20:42:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_MANAGER_H
# define ANIMATIONS_MANAGER_H

# include "animations.h"
# include "textures.h"

void	update_animations(t_animations *animations);
void	update_textures(t_textures *textures, t_animations *animations);

#endif
