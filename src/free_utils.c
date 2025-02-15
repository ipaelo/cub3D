/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:04:06 by crigonza          #+#    #+#             */
/*   Updated: 2023/11/14 14:01:23 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	game_over(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.map_h)
	{
		free(game->map.map_array[i]);
		i++;
	}
	free(game->map.map_array);
	mlx_delete_texture(game->textures.north);
	mlx_delete_texture(game->textures.south);
	mlx_delete_texture(game->textures.west);
	mlx_delete_texture(game->textures.east);
}

void	free_data(t_data *data)
{
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
}
