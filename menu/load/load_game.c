/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:56:20 by gustaoli          #+#    #+#             */
/*   Updated: 2026/04/28 15:00:52 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	run_cub3d(t_game *game, char *map)
{
	int		pid;
	int		status;
	char	*args[3];

	args[0] = "./build/cub3d";
	args[1] = map;
	args[2] = NULL;
	pid = fork();
	if (pid == 1)
		error_exit(game, "Fork");
	if (pid == 0)
		execv("./build/cub3d", args);
	else
	{
		waitpid(pid, &status, 0);
		while (wait(NULL) > 0)
			;
		if ((status & 0x7f) != 0)
			error_exit(game, "Cub3d");
	}
}

void	close_window_mlx(void *param)
{
	int		i;
	t_game	*game;

	game = param;
	i = 0;
	if (i++ > 300)
	{
		mlx_close_window(game->mlx);
	}
}

void	load_game(t_game *game, int map)
{
	(void)map;
	mlx_loop_hook(game->mlx, close_window_mlx, game);
	cleanup(game);
	if (map == 0)
		run_cub3d(game, "maps/iron_maiden.cub");
	else if (map == 1)
		run_cub3d(game, "maps/retr0_dungeon.cub");
	else if (map == 2)
		run_cub3d(game, "maps/donut.cub");
	else if (map == 3)
		run_cub3d(game, "maps/death_wall.cub");
	else if (map == 4)
		run_cub3d(game, "maps/whale.cub");
	else if (map == 5)
		run_cub3d(game, "maps/vine_maze.cub");
	init_window(game);
	game->start = true;
	game->start_timestamp = get_time() - 5500;
	mlx_loop(game->mlx);
}
