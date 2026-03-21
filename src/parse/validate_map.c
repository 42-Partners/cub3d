/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:37:19 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/21 01:02:48 by devrafaelly      ###   ########.fr       */
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
	int		x;

	spawn = 0;
	x = 0;
	while (game->map.map[x])
	{
		validate_row(game, &spawn, x);
		x++;
	}
	if (spawn != 1)
		error_exit(game, "Invalid map");
	copy_map(game);
	flood_fill(game, (int)game->player.pos_x, (int)game->player.pos_y);
}

static void	validate_row(t_game *game, int *spawn, int x)
{
	char	c;
	int		y;

	y = 0;
	while (game->map.map[x][y])
	{
		c = game->map.map[x][y];
		if (!validate_char(c))
			error_exit(game, "Invalid map");
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			game->player.pos_x = x;
			game->player.pos_y = y;
			game->player.orientation = game->map.map[x][y];
			(*spawn)++;
		}
		y++;
	}
}

static int	validate_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

static void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.rows)
		error_exit(game, "Invalid map");
	if (y < 0 || (size_t)y >= ft_strlen(game->map.copy[x]))
		error_exit(game, "Invalid map");
	if (game->map.copy[x][y] == ' ')
		error_exit(game, "Invalid map");
	else if (game->map.copy[x][y] == '1' || game->map.copy[x][y] == 'V')
		return ;
	game->map.copy[x][y] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
	flood_fill(game, x + 1, y + 1);
	flood_fill(game, x - 1, y - 1);
	flood_fill(game, x + 1, y - 1);
	flood_fill(game, x - 1, y + 1);
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
