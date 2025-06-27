/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:17:24 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/27 18:33:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_event_handlers.h"

static void	prevent_cursor_edge_escape(t_app *app, int xpos, int ypos);
static void	rotate(mlx_t *mlx, t_direction direction, t_player *player);

void	handle_mouse(t_app *app)
{
	int			difference;
	t_direction	direction;
	int			xpos;
	int			ypos;

	mlx_get_mouse_pos(app->mlx, &xpos, &ypos);
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
	prevent_cursor_edge_escape(app, xpos, ypos);
}

static void	rotate(mlx_t *mlx, t_direction direction, t_player *player)
{
	if (direction == LEFT)
		rotate_player_left(player, mlx->delta_time);
	else if (direction == RIGHT)
		rotate_player_right(player, mlx->delta_time);
}

static void	prevent_cursor_edge_escape(t_app *app, int xpos, int ypos)
{
	int	quarter_height;
	int	quarter_width;
	int	new_x;
	int	new_y;

	quarter_height = app->mlx->height / 4;
	quarter_width = app->mlx->width / 4;
	if (xpos < quarter_width || xpos > app->mlx->width - quarter_width
		|| ypos < quarter_height || ypos > app->mlx->height - quarter_height)
	{
		new_x = app->mlx->width / 2;
		new_y = app->mlx->height / 2;
		app->cursor_position.x = new_x;
		app->cursor_position.y = new_y;
		mlx_set_mouse_pos(app->mlx, new_x, new_y);
	}
}
