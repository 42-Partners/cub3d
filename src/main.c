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
	validate_map(&game);
	ft_printf("[DEBUG]: Parsing OK!\n");
	init_player_vectors(&game);
	ft_printf("[DEBUG]: player vectors OK!\n");
	init_game(&game);
	ft_printf("[DEBUG]: game init!\n");
	mlx_loop(game.mlx);
	return (0);
}
