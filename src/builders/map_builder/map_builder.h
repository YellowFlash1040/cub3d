/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:50:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/25 14:42:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BUILDER_H
# define MAP_BUILDER_H

# include "map.h"
# include "ft_memory.h"
# include "errors.h"

int	build_map(t_map *map, int width, int height);

#endif
