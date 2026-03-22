/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:18:39 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/21 23:48:01 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdlib.h>

void	cleanup(t_game *game)
{
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
		printf("Error\n%s\n", msg);
	else
		printf("Error\n%s\n", mlx_strerror(mlx_get_errno()));
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
