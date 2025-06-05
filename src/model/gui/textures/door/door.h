/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:30:21 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/05 14:30:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

# include <stdlib.h>
# include "texture.h"

# define DOOR_INIT_ERR 1

typedef struct door
{
	t_texture	*texture;
}	t_door;

t_door	*init_door(void);
void	destroy_door(t_door **door_ref);

#endif
