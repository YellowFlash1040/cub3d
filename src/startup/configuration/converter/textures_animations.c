/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_animations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:45:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/06/21 13:47:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

t_string	*get_animations(t_data *data)
{
	t_string	*animations;

	animations = init_string_array(ANIMATION_NAMES_COUNT);
	if (!animations)
		return (NULL);
	animations[ANIMATION_NORTH_WALL] = data->clean_wall[0];
	animations[ANIMATION_SOUTH_WALL] = data->clean_wall[1];
	animations[ANIMATION_WEST_WALL] = data->clean_wall[2];
	animations[ANIMATION_EAST_WALL] = data->clean_wall[3];
	animations[ANIMATION_DOOR] = ft_strdup("./assets/textures/static/door.png");
	animations[ANIMATION_SPRITE] = ft_strdup("./assets/textures/animated/darth_vader.png");
	return (animations);
}

// t_string	*get_textures(t_data *data)
// {
// 	t_string	*textures;

// 	textures = init_string_array(TEXTURE_NAMES_COUNT);
// 	if (!textures)
// 		return (NULL);
// 	textures[TEXTURE_NORTH_WALL] = data->clean_wall[0];
// 	textures[TEXTURE_SOUTH_WALL] = data->clean_wall[1];
// 	textures[TEXTURE_WEST_WALL] = data->clean_wall[2];
// 	textures[TEXTURE_EAST_WALL] = data->clean_wall[3];
// 	textures[TEXTURE_DOOR] = ft_strdup("./assets/textures/static/door.png");
// 	if (!textures[TEXTURE_DOOR])
// 		return (destroy_string_array(&textures), NULL);
// 	return (textures);
// }

// t_string	*get_animations(void)
// {
// 	t_string	*animations;
// 	int			result;

// 	animations = init_string_array(ANIMATION_NAMES_COUNT);
// 	if (!animations)
// 		return (NULL);
// 	result = copy_animations_file_paths(animations);
// 	if (result != SUCCESS)
// 		return (destroy_string_array(&animations), NULL);
// 	return (animations);
// }

// static int	copy_animations_file_paths(t_string *animations)
// {
// 	t_string	file_path;

// 	file_path = ft_strdup("./assets/textures/animated/darth_vader.png");
// 	if (!file_path)
// 		return (MALLOC_FAIL_ERR);
// 	animations[ANIMATION_SPRITE] = file_path;
// 	file_path = ft_strdup("./assets/textures/animated/00_white.png");
// 	if (!file_path)
// 		return (destroy_string_array(&animations), MALLOC_FAIL_ERR);
// 	animations[ANIMATION_NORTH_WALL] = file_path;
// 	file_path = ft_strdup("./assets/textures/animated/01_red.png");
// 	if (!file_path)
// 		return (destroy_string_array(&animations), MALLOC_FAIL_ERR);
// 	animations[ANIMATION_SOUTH_WALL] = file_path;
// 	file_path = ft_strdup("./assets/textures/animated/02_orange.png");
// 	if (!file_path)
// 		return (destroy_string_array(&animations), MALLOC_FAIL_ERR);
// 	animations[ANIMATION_WEST_WALL] = file_path;
// 	file_path = ft_strdup("./assets/textures/animated/03_yellow.png");
// 	if (!file_path)
// 		return (destroy_string_array(&animations), MALLOC_FAIL_ERR);
// 	animations[ANIMATION_EAST_WALL] = file_path;
// 	return (SUCCESS);
// }
