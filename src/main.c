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

void	debug_heartbeat(void *param)
{
	static int	frame = 0;

	frame++;
	if (frame % 60 == 0)
		printf("[DEBGU] MLX_LOOP!  frame: %d\n", frame);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	validate_file(&game, argc, argv[1]);
	validate_map(&game);
	init_player_vectors(&game);
	init_game(&game);
	printf("[WEB] Tudo inicializado. Entrando no mlx_loop...\n");
	mlx_loop_hook(game.mlx, debug_heartbeat, &game);
	mlx_loop(game.mlx);
	return (0);
}
