/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event_handlers.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:22:05 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 17:50:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_EVENT_HANDLERS_H
# define KEYBOARD_EVENT_HANDLERS_H

# include "app.h"
# include "movement.h"
# include "minimap_visibility.h"
# include "door_interaction.h"

void	handle_keyboard(t_app *app);
void	handle_key_pressed(mlx_key_data_t keydata, void *param);

#endif
