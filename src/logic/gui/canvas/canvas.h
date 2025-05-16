/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:37:58 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/16 17:28:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "app.h"
# include "status_codes.h"
# include "minimap.h"

void	render(t_app *app);
int		create_canvas(t_app *app, int width, int height);
void	refresh_canvas(void* param);

#endif
