/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:41:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 15:57:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SURFACE_H
# define SURFACE_H

# include <stdlib.h>
# include "surface_type.h"
# include "color.h"

# define SURFACE_INIT_ERR 1

typedef struct surface
{
	t_surface_type	type;
	t_color			color;
}	t_surface;

t_surface	*init_surface(void);
void		destroy_surface(t_surface **surface_ref);

#endif
