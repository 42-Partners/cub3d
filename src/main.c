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
	validate_input(&game, argc, argv[1]);
	validate_map(&game);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
