/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:46:03 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/10 20:46:03 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

int			validate_config(int map_fd, t_game *game);
static bool	add_row(t_game *game, char *row);
static void	get_map(int map_fd, t_game *game);
static void	set_map_size(t_game *game);

void	validate_input(t_game *game, int argc, char *filename)
{
	char	*dot;
	int		map_fd;

	if (argc != 2)
		error_exit(game, "Usage: ./cub3d <map.cub>");
	dot = ft_strrchr(filename, '.');
	if (!dot || ft_strncmp(dot, ".cub", 5) != 0)
		error_exit(game, "Invalid file format.");
	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		error_exit(game, "Could not open the file.");
	if (!validate_config(map_fd, game))
		error_exit(game, ".cub file configuration is not correctly definined.");
	get_map(map_fd, game);
	set_map_size(game);
	close (map_fd);
}

static void	get_map(int map_fd, t_game *game)
{
	char	*line;

	line = get_next_line(map_fd);
	game->map = ft_calloc(1, sizeof (char *));
	while (ft_strcmp("\n", line) == 0)
	{
		free(line);
		line = get_next_line(map_fd);
	}
	while (line)
	{
		if (ft_strcmp("\n", line) != 0 && !add_row(game, line))
			error_exit(game, "Malloc error.");
		else if (ft_strcmp("\n", line) == 0)
			free(line);
		line = get_next_line(map_fd);
	}
	get_next_line(-1);
}

static bool	add_row(t_game *game, char *row)
{
	int		i;
	char	**new_map;

	i = 0;
	while (game->map[i])
		i++;
	new_map = ft_realloc(
			game->map, sizeof(char *) * i, sizeof(char *) * (i + 2));
	if (!new_map)
	{
		ft_free_arr(&game->map);
		return (false);
	}
	game->map = new_map;
	game->map[i] = row;
	game->map[i + 1] = NULL;
	return (true);
}

static void	set_map_size(t_game *game)
{
	int	max_x;
	int	x;
	int	y;

	y = 0;
	max_x = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if (x == INT_MAX - 10)
				error_exit(game, "Map too big");
			if (x > max_x)
				max_x = x;
			x++;
		}
		if (y == INT_MAX - 10)
			error_exit(game, "Map too big");
		y++;
	}
	game->map_size_x = max_x;
	game->map_size_y = y;
}
