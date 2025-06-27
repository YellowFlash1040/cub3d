/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:15:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 17:22:59 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLERS_H
# define EVENT_HANDLERS_H

# include "keyboard_event_handlers.h"
# include "mouse_event_handlers.h"

void	subscribe_to_keyboard_events(t_app *app);
void	subscribe_to_mouse_events(t_app *app);
void	handle_key_pressed(mlx_key_data_t keydata, void *param);

#endif
