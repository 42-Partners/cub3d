/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:39:39 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/10 19:39:39 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	validate_file(&game, argc, argv[1]);
	ft_printf("[DEBUG]: FILE VALIDATED\n");
	validate_map(&game);
	ft_printf("[DEBUG]: MAP VALIDATED\n");
	init_player_vectors(&game);
	ft_printf("[DEBUG]: PLAYER VECTOR INITIATED\n");
	init_game(&game);
	ft_printf("[DEBUG]: GAME ON\n");
	mlx_loop(game.mlx);
	return (0);
}
