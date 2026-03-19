/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:37:19 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/03/19 20:57:46 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_row(t_game *game, int *spawn, int i);
static int	validate_char(char c);
static void	flood_fill(t_game *game, char **map, int x, int y);
static char	**copy_map(t_game *game);

void	validate_map(t_game *game)
{
	char	**map;
	int		spawn;
	int		i;

	map = copy_map(game);
	spawn = 0;
	i = 0;
	while (game->map.map[i])
	{
		validate_row(game, &spawn, i);
		i++;
	}
	if (spawn != 1)
		error_exit(game, "Invalid map");
	flood_fill(game, map, (int)game->player.pos_x, (int)game->player.pos_y);
	ft_free_arr(&map);
}

static void	validate_row(t_game *game, int *spawn, int i)
{
	char	c;
	int		j;

	j = 0;
	while (game->map.map[i][j])
	{
		c = game->map.map[i][j];
		if (!validate_char(c))
			error_exit(game, "Invalid map");
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			game->player.pos_x = i;
			game->player.pos_y = j;
			game->player.orientation = game->map.map[i][j];
			(*spawn)++;
		}
		j++;
	}
}

static int	validate_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

static void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (x < 0 || x >= game->map.rows)
		error_exit(game, "Invalid map");
	if (y < 0 || (size_t)y >= ft_strlen(map[x]))
		error_exit(game, "Invalid map");
	if (map[x][y] == ' ')
		error_exit(game, "Invalid map");
	else if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
	flood_fill(game, map, x + 1, y + 1);
	flood_fill(game, map, x - 1, y - 1);
	flood_fill(game, map, x + 1, y - 1);
	flood_fill(game, map, x - 1, y + 1);
}

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = ft_calloc(game->map.rows + 1, sizeof(char *));
	if (!copy)
		error_exit(game, "Malloc error");
	i = 0;
	while (i < game->map.rows)
	{
		copy[i] = ft_strdup(game->map.map[i]);
		if (!copy[i])
		{
			ft_free_arr(&copy);
			error_exit(game, "Malloc error");
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
