/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_event_handlers.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 16:17:24 by akovtune      #+#    #+#                 */
/*   Updated: 2025/06/26 18:01:46 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_event_handlers.h"

static void	rotate(mlx_t *mlx, t_direction direction, t_player *player);

void	handle_mouse_move(double xpos, double ypos, void *param)
{
	t_app		*app;
	int			difference;
	t_direction	direction;

	app = (t_app *)param;
	if (app->cursor_position.x == 0 && app->cursor_position.y == 0)
		app->cursor_position = (t_point){xpos, ypos};
	difference = ft_abs(app->cursor_position.x - (int)xpos);
	if (difference > MOUSE_SENSITIVITY)
	{
		if (app->cursor_position.x < xpos)
			direction = RIGHT;
		else
			direction = LEFT;
		rotate(app->mlx, direction, app->game->player);
		app->cursor_position = (t_point){xpos, ypos};
	}
}

static void	rotate(mlx_t *mlx, t_direction direction, t_player *player)
{
	if (direction == LEFT)
		rotate_player_left(player, mlx->delta_time);
	else if (direction == RIGHT)
		rotate_player_right(player, mlx->delta_time);
}
