/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:54:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 19:22:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

# include <bits/types.h>
# include "color.h"

typedef __uint8_t	t_pixel;

t_color	get_pixel_color(t_pixel	*pixel);

#endif
