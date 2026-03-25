/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:37:19 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/25 17:19:14 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_row(t_game *game, int *spawn, int x);
static int	validate_char(char c);
static void	flood_fill(t_game *game, int x, int y);
static void	copy_map(t_game *game);

void	validate_map(t_game *game)
{
	int		spawn;
	int		y;

	spawn = 0;
	y = 0;
	while (game->map.map[y])
	{
		validate_row(game, &spawn, y);
		y++;
	}
	if (spawn != 1)
		error_exit(game, "Invalid map");
	copy_map(game);
	flood_fill(game, (int)game->player.pos_x, (int)game->player.pos_y);
}

static void	validate_row(t_game *game, int *spawn, int y)
{
	char	c;
	int		x;

	x = 0;
	while (game->map.map[y][x])
	{
		c = game->map.map[y][x];
		if (!validate_char(c))
			error_exit(game, "Invalid map");
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			game->player.pos_x = x + 0.5;
			game->player.pos_y = y + 0.5;
			game->player.orientation = game->map.map[y][x];
			game->map.map[y][x] = '0';
			(*spawn)++;
		}
		x++;
	}
}

static int	validate_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

static void	flood_fill(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map.rows)
		error_exit(game, "Invalid map");
	if (x < 0 || (size_t)x >= ft_strlen(game->map.copy[y]))
		error_exit(game, "Invalid map");
	if (game->map.copy[y][x] == ' ')
		error_exit(game, "Invalid map");
	if (game->map.copy[y][x] == '1' || game->map.copy[y][x] == 'V')
		return ;
	game->map.copy[y][x] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

static void	copy_map(t_game *game)
{
	int		i;

	game->map.copy = ft_calloc(game->map.rows + 1, sizeof(char *));
	if (!game->map.copy)
		error_exit(game, "Malloc error");
	i = 0;
	while (i < game->map.rows)
	{
		game->map.copy[i] = ft_strdup(game->map.map[i]);
		if (!game->map.copy[i])
			error_exit(game, "Malloc error");
		i++;
	}
	game->map.copy[i] = NULL;
}
