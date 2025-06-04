/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/05/22 17:21:59 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	ft_isspace(char c)
{
	if (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
		return (true);
	else
		return (false);
}

bool	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

bool	check_dir_complete(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->dir_check[i] == false)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

void	check_texture(t_data *data, int i)
{
	int		x;

	x = 0;
	while (ft_isspace(data->line[i + x]) == false)
		x++;
	data->texture = malloc(x + 1);
	if (data->texture == NULL)
		exit_all(data, 8);
	x = 0;
	while (ft_isspace(data->line[i + x]) == false)
	{
		data->texture[x] = data->line[i + x];
		x++;
	}
	data->texture[x] = '\0';
	check_extension(data, data->texture, ".png", 9);
	open_fd(data, data->texture, &data->fd_check, 10);
	close_fd(data, data->fd_check, 11);
	free_null((void **)&data->texture);
}
