/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 12:33:47 by akovtune      #+#    #+#                 */
/*   Updated: 2025/06/04 18:04:08 by rbom          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data		data;

	check_input(&data, argc, argv);
	check_dir_map(&data);
	scrape_dir_map(&data);
	resize_map(&data);

	exit_all(&data, 0);
}
