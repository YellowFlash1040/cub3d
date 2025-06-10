/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:14:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/10 16:52:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_BUILDER_H
# define CANVAS_BUILDER_H

# include "canvas.h"
# include "errors.h"

int	build_canvas(t_canvas **canvas_ref, mlx_t *mlx);

#endif
