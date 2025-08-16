/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_visibility.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:29:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 18:09:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_VISIBILITY_H
# define MINIMAP_VISIBILITY_H

# include "settings.h"

void	toggle_minimap(t_settings *settings);
void	toggle_clipped_minimap(t_settings *settings);

#endif
