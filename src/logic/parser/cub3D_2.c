/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbom <rbom@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:39:23 by rbom          #+#    #+#                 */
/*   Updated: 2025/06/26 14:30:51 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_dir_complete(t_data *data)
{
	int	d;
	int	i;

	if (data->dir_check[8] == true)
		return (true);
	d = -1;
	while (++d < 8)
		if ((d != 4 && d != 5) && data->dir_check[d] == false)
			return (false);
	if (empty_line(data->line) == true)
		return (false);
	i = 0;
	while (data->line[i] != '\n' && data->line[i] != '\0')
	{
		if (data->line[i] != ' ' && data->line[i] != 'X' && data->line[i] != '0'
			&& data->line[i] != '1' && data->line[i] != '2'
			&& data->line[i] != 'N' && data->line[i] != 'S'
			&& data->line[i] != 'W' && data->line[i] != 'E')
			return (false);
		i++;
	}
	data->dir_check[8] = true;
	return (true);
}

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

void	check_texture(t_data *data, int i)
{
	int				x;
	char			*picture;
	mlx_texture_t	*texture;

	x = 0;
	while (ft_isspace(data->line[i + x]) == false)
		x++;
	picture = malloc(x + 1);
	if (picture == NULL)
		exit_all(data, 8);
	x = -1;
	while (ft_isspace(data->line[i + ++x]) == false)
		picture[x] = data->line[i + x];
	picture[x] = '\0';
	texture = mlx_load_png(picture);
	free(picture);
	if (texture == NULL)
		exit_all(data, 19);
	mlx_delete_texture(texture);
}

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}
