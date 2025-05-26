/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:55:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/05/26 17:31:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <stdlib.h>
# include <stdbool.h>

# define SETTINGS_INIT_ERR 1

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define CAMERA_FIELD_OF_VIEW 60

# define CELL_SIZE 64

typedef struct settings
{
	bool	is_minimap_visible;
}	t_settings;

t_settings	*init_settings(void);
void		destroy_settings(t_settings **settings_ref);

#endif
