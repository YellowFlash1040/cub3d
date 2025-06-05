/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_handlers.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:16:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/05 16:18:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_EVENT_HANDLERS_H
# define MOUSE_EVENT_HANDLERS_H

# include <math.h>
# include "app.h"
# include "movement_handlers.h"

void	handle_mouse_move(double xpos, double ypos, void* param);

#endif
