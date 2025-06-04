/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 12:33:47 by akovtune      #+#    #+#                 */
/*   Updated: 2025/05/30 22:02:55 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_data *data)
{
	printf("NORTH:\t\tdir: %s\n", data->clean_wall[0]);
	printf("SOUTH:\t\tdir: %s\n", data->clean_wall[1]);
	printf("WEST:\t\tdir: %s\n", data->clean_wall[2]);
	printf("EAST:\t\tdir: %s\n", data->clean_wall[3]);
	printf("FLOOR:\t\tr: %i\tg: %i\tb: %i\n", data->clean_floor[0].r, data->clean_floor[0].g, data->clean_floor[0].b);
	printf("CEILING:\tr: %i\tg: %i\tb: %i\n", data->clean_floor[1].r, data->clean_floor[1].g, data->clean_floor[1].b);
	printf("\nORIGINAL MAP\n");
	int	i = 0;
	while (i < data->clean_map_size.y)
	{
		printf("%s\n", data->temp_map[i]);
		i++;
	}
	printf("\nREDUCED MAP\n");
	i = 0;
	while (i < data->resize_map_size.y)
	{
		printf("%s\n", data->resize_map[i]);
		i++;
	}
	printf("\nMAP SIZE\tX: %i\tY: %i\n", data->resize_map_size.x, data->resize_map_size.y);
	printf("SPAWN\t\t%c, x: %i, y: %i\n", data->resize_spawn_dir, data->resize_spawn.x, data->resize_spawn.y);
}

int	main(int argc, char **argv)
{
	t_data		data;

	check_input(&data, argc, argv);
	check_dir_map(&data);
	scrape_dir_map(&data);
	resize_map(&data);

	print_map(&data);

	exit_all(&data, 0);
}
