/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:18:39 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/21 23:54:59 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdlib.h>

void	cleanup(t_game *game)
{
	if (game->textures.so)
		mlx_delete_texture(game->textures.so);
	if (game->textures.no)
		mlx_delete_texture(game->textures.no);
	if (game->textures.we)
		mlx_delete_texture(game->textures.we);
	if (game->textures.ea)
		mlx_delete_texture(game->textures.ea);
	if (game->map.map_fd != -1)
		close(game->map.map_fd);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.map)
		ft_free_arr(&game->map.map);
	if (game->map.copy)
		ft_free_arr(&game->map.copy);
}

void	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup(game);
	exit(EXIT_SUCCESS);
}

void	error_exit(t_game *game, char *msg)
{
	if (msg)
		printf("Error: %s\n", msg);
	else
		printf("Error: %s\n", mlx_strerror(mlx_get_errno()));
	cleanup(game);
	exit(EXIT_FAILURE);
}

void	clean_gnl(int fd)
{
	char	*aux;

	aux = get_next_line(fd);
	while (aux)
	{
		free(aux);
		aux = get_next_line(fd);
	}
}
